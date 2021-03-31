#include <HapticDriver.h>

HapticDriver::HapticDriver(int deviceID)
{
    handler = new cHapticDeviceHandler();

    // get a handle to the first haptic device
    handler->getDevice(hapticDevice, deviceID);

    // retrieve information about the current haptic device
    info = hapticDevice->getSpecifications();
}

HapticDriver::~HapticDriver()
{
    delete handler;
}

bool HapticDriver::openDevice(bool isCalibrate)
{
    // open a connection to haptic device
    if(hapticDevice->open())
        cout << "open the device successfully!" << endl;
    else
    {
        cout << "failed to open the device!" << endl;
        return false;
    }

    // calibrate device (if necessary)
    if (isCalibrate)
    {
        hapticDevice->calibrate();
        cout << "calibrate the device successfully!" << endl;
    }
    
    // if the device has a gripper, enable the gripper to simulate a user switch
    hapticDevice->setEnableGripperUserSwitch(true);
}

void HapticDriver::closeDevice()
{
    // close haptic device
    hapticDevice->close();
}