#include <ros/ros.h>
#include <iostream>
#include <halconcpp/HalconCpp.h>
#include <halcon_test/Camera.h>
#include <halcon_test/ImageProcess.h>
#include <signal.h>

using namespace std;
using namespace HalconCpp;

bool isSimulationRuning;

void my_handler(int s)
{
	ROS_INFO("halcon_test: ctrl-c catched! Exiting test...");
    isSimulationRuning = false;
	ros::shutdown();
}

int main(int argc, char const *argv[])
{   

    // Catch ctrl-c to end the program
    struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = my_handler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);

    isSimulationRuning = true;

    /*----------------Camera对象测试部分----------------*/
    // Camera cam;
    // cam.openCamera();

    // cv::namedWindow("Camera", cv::WINDOW_FREERATIO);

    // while(isSimulationRuning)
    // {
    //     cv::Mat image;
    //     cam.grabImage(image);
    //     cv::imshow("Camera", image);
    //     cv::waitKey(1);
    // }

    /*----------------ImageProcess对象测试部分----------------*/
    HImage Image("/home/fshs/Documents/test.bmp");
    ImageProcess imp;
    imp.getDistance(Image);
    sleep(10);


    /*---------------综合测试部分----------------*/
    // Camera cam;
    // cam.openCamera();
    // ImageProcess imp;

    // HImage show;
    // cv::Mat image;

    // while(isSimulationRuning)
    // {
    //     try
    //     {
    //         cam.grabImage(image);
    //         imp.Mat2HObject(image, show);
    //         imp.showImage(show);
    //     }
    //     catch(const HOperatorException & e)
    //     {
    //         std::cerr << e.ErrorMessage() << std::endl;
    //     }
        
    // }

    return 0;
}
