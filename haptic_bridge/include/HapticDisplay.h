#pragma once

#include <chai3d.h>
#include <iostream>

#ifndef MACOSX 
#include "GL/glut.h"
#else
#include "GLUT/glut.h"
#endif

// #ifndef HAPTIC 
// #define HAPTIC

using namespace chai3d;
using namespace std;


class HapticDisplay
{
public:

    //! Constructor of HapticDisplay.
    HapticDisplay(int argc, char* argv[], cHapticDeviceInfo info);

    //! Destructor of HapticDisplay.
    ~HapticDisplay();

    //----------------------------------------------------------------------------
    // DECLARED VARIABLES
    //----------------------------------------------------------------------------
    // information about the current haptic device
    cHapticDeviceInfo _info;

    //----------------------------------------------------------------------------
    // DECLARED VARIABLES
    //----------------------------------------------------------------------------

    // a public global variable to store the position [m] of the haptic device
    static cVector3d hapticDevicePosition;

    // a public global variable to store the frequence [Hz] of the haptic device
    static double hapticDeviceFrequence;

    // a small sphere (cursor) representing the haptic device 
    static cShapeSphere* cursor;

    // a line representing the velocity vector of the haptic device
    static cShapeLine* velocity;

    // flag for using force field (ON/OFF)
    static bool useForceField;

    // flag for using force feedback (ON/OFF)
    static bool useForceFeedback;


    // flag to indicate if the haptic shoule ba changed to control the robot
    static bool isStartControl;

    // flag to indicate if the haptic simulation currently running
    static bool simulationRunning;

    // flag to indicate if the haptic simulation has terminated
    static bool simulationFinished;

private:
    
    static HapticDisplay* currentInstance;

    static void updateGraphicsCallback()
    {
        currentInstance->updateGraphics();
    }

    void setupUpdateGraphicsCallback()
    {
        currentInstance = this;
        ::glutDisplayFunc(updateGraphicsCallback);
    }

    //----------------------------------------------------------------------------
    // GENERAL SETTINGS
    //----------------------------------------------------------------------------

    // stereo Mode
    /*
        C_STEREO_DISABLED:            Stereo is disabled 
        C_STEREO_ACTIVE:              Active stereo for OpenGL NVDIA QUADRO cards
        C_STEREO_PASSIVE_LEFT_RIGHT:  Passive stereo where L/R images are rendered next to each other
        C_STEREO_PASSIVE_TOP_BOTTOM:  Passive stereo where L/R images are rendered above each other
    */
    cStereoMode stereoMode = C_STEREO_DISABLED;

    // fullscreen mode
    bool fullscreen;

    // mirrored display
    bool mirroredDisplay;

    //----------------------------------------------------------------------------
    // DECLARED VARIABLES
    //----------------------------------------------------------------------------

    // a world that contains all objects of the virtual environment
    cWorld* world;

    // a camera to render the world in the window display
    cCamera* camera;

    // a light source to illuminate the objects in the world
    cDirectionalLight *light;

    // a label to display the haptic device model
    cLabel* labelHapticDeviceModel;

    // a label to display the position [m] of the haptic device
    cLabel* labelHapticDevicePosition;

    // a label to display the rate [Hz] at which the simulation is running
    cLabel* labelHapticRate;

    // information about computer screen and GLUT display window
    int screenW;
    int screenH;
    static int windowW;
    static int windowH;
    int windowPosX;
    int windowPosY;

    //----------------------------------------------------------------------------
    // DECLARED FUNCTIONS
    //----------------------------------------------------------------------------

    /*
        *@brief: initialize OPENGL - WINDOW DISPLAY
        */
    void initDisplay(int argc, char* argv[]);

    /*
    *@brief: callback when the window display is resized
    */ 
    static void resizeWindow(int w, int h);

    /*
    *@brief: callback to render graphic scene
    */
    void updateGraphics(void);

    /*
    *@brief: callback when a key is pressed
    */
    static void keySelect(unsigned char key, int x, int y);

    /*
        *@brief: callback of GLUT timer
        */
    static void graphicsTimer(int data);

};



// #endif