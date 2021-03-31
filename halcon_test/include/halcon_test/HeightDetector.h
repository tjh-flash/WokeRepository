#pragma once

#include <halcon_test/Camera.h>
#include <halcon_test/ImageProcess.h>
#include <thread>
#include <atomic>

class HeightDetector
{
public:

    /*
        *@ brief: 构造函数
        */
    HeightDetector();

    /*
        *@ brief: 析构函数
        */
    ~HeightDetector();

    /*
        *@ brief: 检测初始化检查
        */
    void init();

      /*
        *@ brief: 进行一次高度检测
        */
    void heightCheck();

    /*
        *@ brief: 高度检测状态反馈获取函数接口
        */
    bool getDetectionStatue()
    {
        return isDetecting;
    }

private:

    //相机对象指针
    std::shared_ptr<Camera> cam;

    //图像处理对象指针
    std::shared_ptr<ImageProcess> imp;

    //状态反馈变量
    std::atomic<bool> isDetecting;

    //全局图像变量
    cv::Mat Image;
    HImage Himage;

};