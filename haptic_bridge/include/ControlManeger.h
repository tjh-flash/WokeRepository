#pragma once

#include <HapticDriver.h>
#include <HapticDisplay.h>
#include <robotControl.h>
#include <GripperControl.h>
#include <chai3d.h>

#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int8MultiArray.h>
#include <geometry_msgs/WrenchStamped.h>
#include <haptic_bridge/OpenDevice.h>
#include <haptic_bridge/CloseDevice.h>
#include <haptic_bridge/StartControl.h>
#include <haptic_bridge/SwitchAxis.h>
#include <atomic>
#include <thread>

//force sensor data range(N, Nm)
#define ForceSensorFxyz 200.0f
#define ForceSensorTxy 10.0f
#define ForseSensorTz  6.5f
#define HapticDeviceFxyz 12.0f
#define HapticDeviceTxy 10.0f
#define HapticDeviceTz  6.5f


using namespace std;
using namespace chai3d;

class ControlManeger
{
public:

    //! Constructor of ControlManeger.
    ControlManeger(int argc, char* argv[], ros::NodeHandle & nh);

    //! Destructor of ControlManeger.
    ~ControlManeger();

private:

    //----------------------------------------------------------------------------
    // DECLARED VARIABLES
    //----------------------------------------------------------------------------

    // declare a HapticDislay object
    static HapticDisplay *hdp;

    // declare a HapticDriver object
    static HapticDriver *hdd;

    //declare a GripperControl object
    static GripperControl *gpc;

    // declare a cthread
    cThread* hapticsThread;

    // declare a ros node
    ros::NodeHandle _nh;

    // declare ros server 
    ros::ServiceServer openDeviceServer;
    ros::ServiceServer closeDeviceServer;
    ros::ServiceServer startControlServer;
    ros::ServiceServer switchAxisServer;

    // declare ros subscriber
    ros::Subscriber forceDataSub;

    // force data
    static vector<double> currentForce;

    // filter the axis of the robot 
    static vector<int> asixFilter;

    //----------------------------------------------------------------------------
    // DECLARED FUNCTIONS
    //----------------------------------------------------------------------------

    /*
        * @brief: the thread's function1
        */ 
    static void updateHaptics(void);

    /*
        * @brief: initialize the ros
        */
    void rosInit();

    /*
        * @brief: start  the control simulation loop
        */ 
    void startControlSimulation();

    /*
        * @brief: the thread's function2
        */ 
    static void updateControl(void);

    /*
        * @brief: remote control function
        */
    static void RemoteForceControlDemo(const cVector3d & position);

    /*
        * @brief: open/close the device()
        */
    void open();
    void close();

    /*
        * @brief: ros service & topic callback function
        */ 
    bool openDeviceServerCallback(haptic_bridge::OpenDevice::Request & req, haptic_bridge::OpenDevice::Response & res);
    bool closeDeviceServerCallback(haptic_bridge::CloseDevice::Request & req, haptic_bridge::CloseDevice::Response & res);
    bool startControlServerCallback(haptic_bridge::StartControl::Request & req, haptic_bridge::StartControl::Response & res);
    bool switchAxisServerCallback(haptic_bridge::SwitchAxis::Request & req, haptic_bridge::SwitchAxis::Response & res);
    void forceDataFeedback(const geometry_msgs::Wrench::ConstPtr & msg);

    /*
        * @brief: multiply vec_a and vec_b, and then return vec_a
        */ 
    inline static void vectorMultiply(vector<double> & vec_a , vector<int> & vec_b)
    {
        for (int i = 0; i < 6; i++)
        {
            vec_a[i] = vec_a[i] * vec_b[i]; 
        }
    }


    /*
        * @brief: calculate the force apply to haptic device
        * @param: force data from force sensor
        */
    inline void getForceAndTorque(vector<double>& data)
    {
        for (int i = 0; i < 3; i++)
        {
            data[i] = data[i] * (HapticDeviceFxyz / ForceSensorFxyz);
        }
    }

};
