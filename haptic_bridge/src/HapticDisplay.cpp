
#include "HapticDisplay.h"

//------------------------------------------------------------------------------
int HapticDisplay::windowH = 0;
int HapticDisplay::windowW = 0;
bool HapticDisplay::useForceField = true;
bool HapticDisplay::useForceFeedback = false;
bool HapticDisplay::isStartControl = false;
bool HapticDisplay::simulationRunning = false;
bool HapticDisplay::simulationFinished = true;
HapticDisplay* HapticDisplay::currentInstance = nullptr;
cShapeSphere* HapticDisplay::cursor = nullptr;
cShapeLine* HapticDisplay::velocity = nullptr;
double HapticDisplay::hapticDeviceFrequence = 0.0;
cVector3d HapticDisplay::hapticDevicePosition(0.0, 0.0, 0.0);

HapticDisplay::HapticDisplay(int argc, char* argv[], cHapticDeviceInfo info)
{
    // get the device information
    _info = info;

    // create a new world.
    world = new cWorld();

    //create a camera and insert it into the virtual world
    camera = new cCamera(world);

    // create a directional light source
    light = new cDirectionalLight(world);

    // create a sphere (cursor) to represent the haptic device
    cursor = new cShapeSphere(0.01);

    // create small line to illustrate the velocity of the haptic device
    velocity = new cShapeLine(cVector3d(0,0,0), 
                              cVector3d(0,0,0));

    fullscreen = false;
    mirroredDisplay = false;

    // initialize the display
    initDisplay(argc, argv);

}

//------------------------------------------------------------------------------

HapticDisplay::~HapticDisplay()
{
    delete world;
    delete camera;
    delete cursor;
}


//------------------------------------------------------------------------------s
void HapticDisplay::initDisplay(int argc, char* argv[])
{
    //--------------------------------------------------------------------------
    // INITIALIZATION
    //--------------------------------------------------------------------------

    cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "Force Dimension Remote Control" << endl;
    cout << "Demo: fuck" << endl;
    cout << "-----------------------------------" << endl << endl << endl;
    cout << "Keyboard Options:" << endl << endl;
    cout << "[1] - Enable/Disable potential field" << endl;
    // cout << "[f] - Enable/Disable full screen mode" << endl;
    // cout << "[m] - Enable/Disable vertical mirroring" << endl;
    cout << "[x] - Exit application" << endl;
    cout << "-----------------------------------" << endl;
    cout << endl << endl;

    // initialize GLUT
    glutInit(&argc, argv);

    // retrieve  resolution of computer display and position window accordingly
    screenW = glutGet(GLUT_SCREEN_WIDTH);
    screenH = glutGet(GLUT_SCREEN_HEIGHT);
    windowW = (int)(0.8 * screenH);
    windowH = (int)(0.5 * screenH);
    windowPosY = (screenH - windowH) / 2;
    windowPosX = windowPosY;

    // initialize the OpenGL GLUT window
    glutInitWindowPosition(windowPosX, windowPosY);
    glutInitWindowSize(windowW, windowH);

    if (stereoMode == C_STEREO_ACTIVE)
        glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE | GLUT_STEREO);
    else
        glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    // create display context and initialize GLEW library
    glutCreateWindow(argv[0]);

#ifdef GLEW_VERSION
    // initialize GLEW
    glewInit();
#endif

    // setup GLUT options
    // glutDisplayFunc(updateGraphics);
    setupUpdateGraphicsCallback();
    glutKeyboardFunc(keySelect);
    glutReshapeFunc(resizeWindow);
    glutSetWindowTitle("CHAI3D");

    // set fullscreen mode
    if (fullscreen)
    {
        glutFullScreen();
    }

    //--------------------------------------------------------------------------
    // WORLD - CAMERA - LIGHTING
    //--------------------------------------------------------------------------

    // // create a new world.
    // world = new cWorld();

    // set the background color of the environment
    world->m_backgroundColor.setBlack();

    // create a camera and insert it into the virtual world
    // camera = new cCamera(world);
    world->addChild(camera);

    // position and orient the camera
    camera->set( cVector3d (0.5, 0.0, 0.0),    // camera position (eye)
                 cVector3d (0.0, 0.0, 0.0),    // look at position (target)
                 cVector3d (0.0, 0.0, 1.0));   // direction of the (up) vector

    // set the near and far clipping planes of the camera
    camera->setClippingPlanes(0.01, 10.0);

    // set stereo mode
    camera->setStereoMode(stereoMode);

    // set stereo eye separation and focal length (applies only if stereo is enabled)
    camera->setStereoEyeSeparation(0.01);
    camera->setStereoFocalLength(0.5);

    // set vertical mirrored display mode
    camera->setMirrorVertical(mirroredDisplay);

    // create a directional light source
    // light = new cDirectionalLight(world);

    // insert light source inside world
    world->addChild(light);

    // enable light source
    light->setEnabled(true);

    // define direction of light beam
    light->setDir(-1.0, 0.0, 0.0);

    // create a sphere (cursor) to represent the haptic device
    // cursor = new cShapeSphere(0.01);

    // insert cursor inside world
    world->addChild(cursor);

    // create small line to illustrate the velocity of the haptic device
    // velocity = new cShapeLine(cVector3d(0,0,0), 
    //                           cVector3d(0,0,0));

    // insert line inside world
    world->addChild(velocity);

    // display a reference frame if haptic device supports orientations
    if (_info.m_sensedRotation == true)
    {
        // display reference frame
        cursor->setShowFrame(true);

        // set the size of the reference frame
        cursor->setFrameSize(0.05);
    }

    //--------------------------------------------------------------------------
    // WIDGETS
    //--------------------------------------------------------------------------

    // create a font
    cFont *font = NEW_CFONTCALIBRI20();

    // create a label to display the haptic device model
    labelHapticDeviceModel = new cLabel(font);
    camera->m_frontLayer->addChild(labelHapticDeviceModel);
    labelHapticDeviceModel->setText(_info.m_modelName);

    // create a label to display the position of haptic device
    labelHapticDevicePosition = new cLabel(font);
    camera->m_frontLayer->addChild(labelHapticDevicePosition);
    
    // create a label to display the haptic rate of the simulation
    labelHapticRate = new cLabel(font);
    camera->m_frontLayer->addChild(labelHapticRate);

    //--------------------------------------------------------------------------
    // START SIMULATION
    //--------------------------------------------------------------------------

    // start the main graphics rendering loop
    glutTimerFunc(50, graphicsTimer, 0);
    glutMainLoop();

}

//------------------------------------------------------------------------------

void HapticDisplay::resizeWindow(int w, int h)
{
    windowW = w;
    windowH = h;
}

//------------------------------------------------------------------------------

void HapticDisplay::graphicsTimer(int data)
{
    if (simulationRunning)
    {
        glutPostRedisplay();
    }

    glutTimerFunc(50, graphicsTimer, 0);
}

//------------------------------------------------------------------------------

void HapticDisplay::updateGraphics(void)
{
    /////////////////////////////////////////////////////////////////////
    // UPDATE WIDGETS
    /////////////////////////////////////////////////////////////////////

    // update position of label
    labelHapticDeviceModel->setLocalPos(20, windowH - 40, 0);

    // display new position data
    labelHapticDevicePosition->setText(hapticDevicePosition.str(3));

    // update position of label
    labelHapticDevicePosition->setLocalPos(20, windowH - 60, 0);

    // display haptic rate data
    // labelHapticRate->setText(cStr(frequencyCounter.getFrequency(), 0) + " Hz");
    labelHapticRate->setText(cStr(hapticDeviceFrequence, 0) + "Hz");

    // update position of label
    labelHapticRate->setLocalPos((int)(0.5 * (windowW - labelHapticRate->getWidth())), 15);


    /////////////////////////////////////////////////////////////////////
    // RENDER SCENE
    /////////////////////////////////////////////////////////////////////

    // update shadow maps (if any)
    world->updateShadowMaps(false, mirroredDisplay);

    // render world
    camera->renderView(windowW, windowH);

    // swap buffers
    glutSwapBuffers();

    // wait until all GL commands are completed
    glFinish();

    // check for any OpenGL errors
    GLenum err;
    err = glGetError();
    if (err != GL_NO_ERROR) cout << "Error:  %s\n" << gluErrorString(err);
}

//------------------------------------------------------------------------------

void HapticDisplay::keySelect(unsigned char key, int x, int y)
{
    //option ESC: exit
    if ((key == 27) || (key == 'x'))
    {
          // stop the simulation
        simulationRunning = false;

        // wait for graphics and haptics loops to terminate
        while (!simulationFinished) { cSleepMs(100); }

        exit(0);
    }

    // option 1: enable/disable force field
    if (key == '1')
    {
        useForceField = !useForceField;
        if (useForceField)
            cout << "> Enable force field     \r";
        else
            cout << "> Disable force field    \r";
    }

    // option s: start to control the robot
    if (key == 's')
    {
        isStartControl = !isStartControl;
    }

    if (key == '2')
    {
        useForceFeedback = !useForceFeedback;
         if (useForceFeedback)
            cout << "> Enable force feedback     \r";
        else
            cout << "> Disable force feedback    \r";
    }
}