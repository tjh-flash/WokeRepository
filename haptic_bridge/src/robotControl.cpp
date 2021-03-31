#include <robotControl.h>

void RemoteForceControl(const cVector3d & position, const bool & isApplyForce)
{
    // // initialize desired position and rotation
    // cVector3d desiredPosition;
    // cMatrix3d desiredRotation;
    // desiredPosition.set(0.0, 0.0, 0.0);
    // desiredRotation.identity();

    // // variables for forces control
    // cVector3d force(0.0, 0.0, 0.0);
    // cVector3d torque(20.0, 20.0, 0.0);

    // // apply force filed
    // if (isApplyForce)
    // {
    //     // compute linear force [N/m]
    //     double Kp = 20;
    //     cVector3d forceFiled = (0, 0, 0);
    //     forceFiled = Kp * (desiredPosition - position);
    //     force.add(forceFiled);  
    // }

    cout << "DEMO, DO NOTHING!" << endl;
}