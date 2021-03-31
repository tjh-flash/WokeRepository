#pragma once

#include <halconcpp/HalconCpp.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include <array>
#include <iostream>
#include <dbg.h>

using namespace HalconCpp;
using namespace cv;
using namespace std;


class ImageProcess
{
public:

    /*
        *@ brief: 构造函数
        */
    ImageProcess();

    /*
        *@ brief: 析构函数
        */
    ~ImageProcess();

    /*
        *@ brief: 获取所测量高度值
        */
    void getDistance(HImage & image);

// private:

    /*
        *@ brief: 图片格式转换，Mat转HImage
        */
    void Mat2HObject(const Mat &image, HObject &outObj);


    /*
        *@ brief: 图片格式转换，HImage转Mat
        */
    void HObject2Mat(const HObject &_Hobj, cv::Mat &outMat);

    /*
        *@ brief: 检测效果图片展示
        */
    void showImage(const HImage himage);


     /*
        *@ brief: 加载相机标定得到的参数
        */
    void initParam();

    //Halcon显示窗口句柄
    HTuple hv_WindowHandle;

    //最小边缘幅度
    HTuple AmplitudeThreshold = 0;

    //Sigma(平滑)
    HTuple SigmaValue = 0.40;

    //ROI宽(二分之一)
    HTuple RoiWidthLen2 = 24;

    //模糊测量阈值系数
    HTuple FuzzyThreshold = 0.6;

    //测量线段坐标
    HTuple LineRowStart_Measure = 728.968;
    HTuple LineColumnStart_Measure = 96.5696;
    HTuple LineRowEnd_Measure = 728.968;
    HTuple LineColumnEnd_Measure = 197.371;

    //相机内参 & 相机标定姿态
    array<double, 8> CameraParametersArray {{0.0163224, -77.09, 2.3991e-06, 2.4e-06, 1559.24, 1035.51, 3072,2048}};
    array<double, 7> CameraPoseArray = {{0.118393, 0.0587179, -0.934196, 356.467, 0.842866, 180.237, 0}};
    HTuple CameraParameters;
    HTuple CameraPose;

    //相机分辨率
    const int IMAGE_WIDTH = 3072;
    const int IMAGE_HEIGHT = 2048;

};