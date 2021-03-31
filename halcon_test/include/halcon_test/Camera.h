#pragma once

#include <HkCameraHandler.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <dbg.h>

using namespace std;

class Camera
{   
public:

    /*
        *@ brief: 构造函数
        */
    Camera();

    /*
        *@ brief: 析构函数
        */
    ~Camera();

    /*
        *@ brief: 打开相机
        */
    int openCamera();

    /*
        *@ brief: 关闭相机
        */
    void closeCamera();

    /*
        *@ brief: 获取相机图像流
        */
    int grabImage(cv::Mat & image);

private:

    //海康相机控制句柄
    HkCameraHandler hkcam; 
    
};