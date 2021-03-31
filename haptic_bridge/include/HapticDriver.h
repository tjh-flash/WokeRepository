#pragma once

#include <chai3d.h>
#include <iostream>

using namespace chai3d;
using namespace std;




class HapticDriver
{
public:

    //! Constructor of HapticDriver.
    HapticDriver(int deviceID = 0);

    //! Destructor of HapticDriver.
    ~HapticDriver();

    //----------------------------------------------------------------------------
    // DECLARED VARIABLES
    //----------------------------------------------------------------------------

    // a pointer to the current haptic device
    cGenericHapticDevicePtr hapticDevice;

    // retrieve information about the current haptic device
    
    cHapticDeviceInfo info;

    // frequency counter to measure the simulation haptic rate
    cFrequencyCounter frequencyCounter;

    //----------------------------------------------------------------------------
    // DECLARED FUNCTIONS
    //----------------------------------------------------------------------------

    /*
        *@brief: open a connection to the haptic device.
        */
    bool openDevice(bool isCalibrate = true);

    /*
        *@brief: close the connection to the haptic device.
        */
    void closeDevice();



private:

    //----------------------------------------------------------------------------
    // DECLARED VARIABLES
    //----------------------------------------------------------------------------

    // a haptic device handler
    cHapticDeviceHandler* handler;
    
};

