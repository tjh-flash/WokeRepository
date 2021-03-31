#include <ControlManeger.h>

// #define GRIPPER
#define ForceFeedback

//------------------------------------------------------------------------------

HapticDisplay* ControlManeger::hdp = nullptr;
HapticDriver* ControlManeger::hdd = nullptr;
GripperControl* ControlManeger::gpc = nullptr;
vector<int> ControlManeger::asixFilter = {1, 1, 1, 0, 0, 0};
vector<double> ControlManeger::currentForce = {0, 0, 0, 0, 0, 0};

//------------------------------------------------------------------------------

ControlManeger::ControlManeger(int argc, char* argv[], ros::NodeHandle & nh)
{
    _nh = nh;
    rosInit();

#ifdef GRIPPER
    gpc = new GripperControl();
#endif

    hdd = new HapticDriver();
    hdp = new HapticDisplay(argc, argv, hdd->info);
    hapticsThread = new cThread();
    asixFilter.resize(6);
}

//------------------------------------------------------------------------------

ControlManeger::~ControlManeger()
{

#ifdef GRIPPER
        delete gpc;
#endif

    delete hdd;
    delete hdp;
    delete hapticsThread;
}


//------------------------------------------------------------------------------

void ControlManeger::rosInit()
{
    openDeviceServer = _nh.advertiseService("/haptic_bridge/openDevice", &ControlManeger::openDeviceServerCallback, this);
    closeDeviceServer = _nh.advertiseService("/haptic_bridge/closeDevice", &ControlManeger::closeDeviceServerCallback, this);
    startControlServer = _nh.advertiseService("/haptic_bridge/startControl", &ControlManeger::startControlServerCallback, this);
    switchAxisServer = _nh.advertiseService("/haptic_bridge/switchAxis", &ControlManeger::switchAxisServerCallback, this);

#ifdef ForceFeedback
    forceDataSub = _nh.subscribe("/daq_data", 1, &ControlManeger::forceDataFeedback, this);
    currentForce.resize(6);
    fill(currentForce.begin(), currentForce.begin() + 6 ,0);
#endif
}


//------------------------------------------------------------------------------

void ControlManeger::open()
{
    hdd->openDevice();
    startControlSimulation();
}

//------------------------------------------------------------------------------

void ControlManeger::close()
{
    hdd->closeDevice();
}


//------------------------------------------------------------------------------

void ControlManeger::startControlSimulation()
{
    hapticsThread->start(updateHaptics, CTHREAD_PRIORITY_HAPTICS);
}


//------------------------------------------------------------------------------

void ControlManeger::updateHaptics(void)
{
    // initialize frequency counter
    hdd->frequencyCounter.reset();

    // simulation in now running
    hdp->simulationRunning  = true;
    hdp->simulationFinished = false;

    // main haptic simulation loop
    while (hdp->simulationRunning)
    {
        /////////////////////////////////////////////////////////////////////
        // READ HAPTIC DEVICE
        /////////////////////////////////////////////////////////////////////

        // read position 
        cVector3d position;
        hdd->hapticDevice->getPosition(position);

        // read orientation 
        cMatrix3d rotation;
        hdd->hapticDevice->getRotation(rotation);

        // read gripper position
        double gripperAngle;
        hdd->hapticDevice->getGripperAngleRad(gripperAngle);
        // cout << "gripperAngle: " << gripperAngle << endl;

        // read linear velocity 
        cVector3d linearVelocity;
        hdd->hapticDevice->getLinearVelocity(linearVelocity);

        // read angular velocity
        cVector3d angularVelocity;
        hdd->hapticDevice->getAngularVelocity(angularVelocity);

        // read gripper angular velocity
        double gripperAngularVelocity;
        hdd->hapticDevice->getGripperAngularVelocity(gripperAngularVelocity);

        // read user-switch status (button 0)
        bool button0 = false;
        hdd->hapticDevice->getUserSwitch(0, button0);

        /////////////////////////////////////////////////////////////////////
        // UPDATE 3D CURSOR MODEL
        /////////////////////////////////////////////////////////////////////

        // update arrow
        hdp->velocity->m_pointA = position;
        hdp->velocity->m_pointB = cAdd(position, linearVelocity);

        // update position and orientation of cursor
        hdp->cursor->setLocalPos(position);
        hdp->cursor->setLocalRot(rotation);

        // adjust the  color of the cursor according to the status of
        // the user-switch (ON = TRUE / OFF = FALSE)
        if (button0)
        {
            hdp->cursor->m_material->setGreenMediumAquamarine();
        }
        else
        {
            hdp->cursor->m_material->setBlueRoyal();
        }

        // update global variable for graphic display update
        hdp->hapticDevicePosition = position;

        /////////////////////////////////////////////////////////////////////
        // COMPUTE AND APPLY FORCES
        /////////////////////////////////////////////////////////////////////

        // desired position
        cVector3d desiredPosition;
        desiredPosition.set(0.0, 0.0, 0.0);

        // desired orientation
        cMatrix3d desiredRotation;
        desiredRotation.identity();
        
        // variables for forces    
        cVector3d force (0,0,0);
        cVector3d torque (0,0,0);
        double gripperForce = 0.0;

        // apply force field
        if (hdp->useForceField)
        {
            // compute linear force
            double Kp = 25; // [N/m]
            cVector3d forceField = Kp * (desiredPosition - position);
            force.add(forceField);

            // compute angular torque
            double Kr = 0.05; // [N/m.rad]
            cVector3d axis;
            double angle;
            cMatrix3d deltaRotation = cTranspose(rotation) * desiredRotation;
            deltaRotation.toAxisAngle(axis, angle);
            torque = rotation * ((Kr * angle) * axis);     
        }

#ifdef GRIPPER
        //control the gripper
        gpc->angle = gripperAngle;

        //gripper force feedback
        if(gpc->forceval < 4000)
            gripperForce = 5;
        else 
            gripperForce = 0;
#endif

#ifdef ForceFeedback
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<X: " << currentForce[0] << endl;
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<Y: " << currentForce[1] << endl; 
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<Z: " << currentForce[2] << endl;
        if (hdp->useForceFeedback)
        {
            force.x(currentForce[1]);
            force.y(currentForce[0]);
            force.z(-currentForce[2]);
        }
#endif


        // send computed force, torque, and gripper force to haptic device
        hdd->hapticDevice->setForceAndTorqueAndGripperForce(force, torque, gripperForce);


        // update frequency counte
        hdd->frequencyCounter.signal(1);
        hdp->hapticDeviceFrequence = hdd->frequencyCounter.getFrequency();

        
        // switch to control the robot
        while (hdp->isStartControl && hdp->simulationRunning)
        {
            updateControl();
        }
        
        // this_thread::sleep_for(chrono::milliseconds(10));
    }

    // close haptic device
    hdd->hapticDevice->close();

    // exit haptics thread
    hdp->simulationFinished = true;

}


//------------------------------------------------------------------------------

void ControlManeger::updateControl(void)
{
    // initialize robot control params
    cVector3d positionInit;
    cVector3d positionDelta;
    cVector3d axis;
    double angle;

    // the variables read from the device
    cVector3d position;
    cMatrix3d rotation;
    cVector3d linearVelocity;
    cVector3d angularVelocity;

    // initialize control objects and control variables
    HscRobotFun robot;
    RobotTrajectClient rtClient;
    PositionControl pControl;
    bool isInit = false;
    int sendFlag = 100;


    assert(robot.connect() == true);

    // robot.setEnable(true);
    // ros::Duration(0.5).sleep();

    assert(robot.getEnable() == true);

    while (hdp->simulationRunning && hdp->isStartControl)
    {
        // read position 
        hdd->hapticDevice->getPosition(position);
        
        // read orientation 
        hdd->hapticDevice->getRotation(rotation);

        // print out the position and orientation
        cout << "device position: " << position << std::endl;
        cout << "device orientation: " << rotation(0, 0) << " " << rotation(0, 1) << " " << rotation(0, 2) << endl;
        rotation.toAxisAngle(axis, angle);

        // read linear velocity 
        hdd->hapticDevice->getLinearVelocity(linearVelocity);

        // read angular velocity
        hdd->hapticDevice->getAngularVelocity(angularVelocity);

        // update arrow
        hdp->velocity->m_pointA = position;
        hdp->velocity->m_pointB = cAdd(position, linearVelocity);

        // update position and orientation of cursor
        hdp->cursor->setLocalPos(position);
        hdp->cursor->setLocalRot(rotation);

        // update global variable for graphic display update
        hdp->hapticDevicePosition = position;

        /////////////////////////////////////////////////////////////////////
        // EULARANGLE
        /////////////////////////////////////////////////////////////////////
        double sensorEularAngle[3];
        double RMatrix[3][3];
        int ii = 0; 
        int jj = 0;
        for (ii = 0; ii < 3; ii++)
        {
            for (jj = 0; jj < 3; jj++)
            {
                RMatrix[ii][jj] = rotation(ii, jj);
            }
        }
        RobotUtilty::tr2rpy(RMatrix, sensorEularAngle, 3, 0);

        // RPY, which refer to HsRobot CBA
        RobotUtilty::Rad2Angle(sensorEularAngle, 3);

        /////////////////////////////////////////////////////////////////////
        // ROBOT FEEDBACK CONTROL
        ///////////////////////////////////////////////////////////////////// 
        if (sendFlag > 100)
        {
            // get current robot pose
            vector<double> curPos = robot.getCurrentPose();
            Log::debug("current robot pose: ", curPos);

            // compute the offset value
            if (!isInit)
            {
                vector<double> initRemotePos{position.x(), position.y(), position.z(), sensorEularAngle[2], sensorEularAngle[1], sensorEularAngle[0]};
                pControl.setInitPos(curPos, initRemotePos);
                rtClient.setTrajStartPoint(curPos, 20, Cart);
                isInit = true;
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }

            vector<double> remotePose{position.x(), position.y(), position.z(), sensorEularAngle[2], sensorEularAngle[1], sensorEularAngle[0]};
            pControl.setCurrentPos(curPos, remotePose);
            vector<double> target = pControl.compute(); 
            
            //set the control axis
            vectorMultiply(target, asixFilter);
            Log::debug("target", target);

            //render to the robot
            rtClient.setTrajRunPoint(target);
        }
        else
        {
            sendFlag++;
        }
        
        RemoteForceControlDemo(position);

        this_thread::sleep_for(chrono::milliseconds(10));
        auto nowTime = chrono::system_clock::now();
        auto duration_in_ms  = chrono::duration_cast<chrono::milliseconds>(nowTime.time_since_epoch());
        std::cout << "<--------- " << duration_in_ms.count() << " --------->" << std::endl;

    }

    // // exit haptics thread
    // hdp->simulationFinished = true;

    // stop robot move
    rtClient.setTrajEnd();
    robot.setEnable(false);
}

//------------------------------------------------------------------------------

void ControlManeger::RemoteForceControlDemo(const cVector3d & position)
{
    // initialize desired position and rotation
    cVector3d desiredPosition;
    cMatrix3d desiredRotation;
    desiredPosition.set(0.0, 0.0, 0.0);
    desiredRotation.identity();

    // variables for forces control
    cVector3d force(0.0, 0.0, 0.0);
    cVector3d torque(20.0, 20.0, 0.0);

    // calculate and apply force filed
    if (hdp->useForceField)
    {
        // compute linear force [N/m]
        double Kp = 20;
        cVector3d forceFiled(0, 0, 0);
        forceFiled = Kp * (desiredPosition - position);
        force.add(forceFiled);  
    }

    // send computed force to haptic device
    hdd->hapticDevice->setForce(force);

    // update frequency counter
    hdd->frequencyCounter.signal(1);
    hdp->hapticDeviceFrequence = hdd->frequencyCounter.getFrequency();

}


//------------------------------------------------------------------------------

bool ControlManeger::openDeviceServerCallback(haptic_bridge::OpenDevice::Request & req, haptic_bridge::OpenDevice::Response & res)
{
    cout << "emmm...open device!" << endl;
    open();
    return true;
}


//------------------------------------------------------------------------------

bool ControlManeger::closeDeviceServerCallback(haptic_bridge::CloseDevice::Request & req, haptic_bridge::CloseDevice::Response & res)
{
    cout << "emmm... shutdown device!" << endl;
    hdp->simulationRunning = false;
    return true;
}

bool ControlManeger::startControlServerCallback(haptic_bridge::StartControl::Request & req, haptic_bridge::StartControl::Response & res)
{
    if (req.isControl == false)
    {
        hdp->isStartControl = false;
        cout << "emmm... stop controling the robot!" << endl;
    }

    if (req.isControl == true)
    {
        hdp->isStartControl = true;
        cout << "emmm... start controling the robot!" << endl;   
    }
    return true;
}

bool ControlManeger::switchAxisServerCallback(haptic_bridge::SwitchAxis::Request & req, haptic_bridge::SwitchAxis::Response & res)
{
    asixFilter.clear();
    cout << "更新轴控制参数成功！" << endl;
    asixFilter.push_back(req.Axis_X);
    asixFilter.push_back(req.Axis_Y);
    asixFilter.push_back(req.Axis_Z);
    asixFilter.push_back(req.Axis_A);
    asixFilter.push_back(req.Axis_B);
    asixFilter.push_back(req.Axis_C);

    for (int i = 0; i < asixFilter.size(); i++)
    {
        cout << "asixFilter[" << i << "]: " << asixFilter[i] << endl;
    }

    return true;
}

// void ControlManeger::vectorMultiply(vector<double> & vec_a, vector<int> & vec_b)
// {
//     for (int i = 0; i < 6; i++)
//     {
//         vec_a[i] = vec_a[i] * vec_b[i]; 
//     }
// }

void ControlManeger::forceDataFeedback(const geometry_msgs::Wrench::ConstPtr & msg)
{
    currentForce[0] = msg->force.x;
    currentForce[1] = msg->force.y;
    currentForce[2] = msg->force.z;
    currentForce[3] = msg->torque.x;
    currentForce[4] = msg->torque.y;
    currentForce[5] = msg->torque.z;

    // for (int i = 0; i < 3; i++)
    // {
    //     currentForce[i] = currentForce[i] * (HapticDeviceFxyz / ForceSensorFxyz);
    // }
    getForceAndTorque(currentForce);

    // cout << "force: " << endl;
    // cout << "force_x: " << currentForce[0] << endl;
    // cout << "force_y: " << currentForce[1] << endl;
    // cout << "force_z: " << currentForce[2] << endl;
    // cout << "torque: " << endl;
    // cout << "torque_x: " << currentForce[3] << endl;
    // cout << "torque_y: " << currentForce[4] << endl;
    // cout << "torque_z: " << currentForce[5] << endl;
}