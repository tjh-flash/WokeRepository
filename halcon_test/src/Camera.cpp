#include <halcon_test/Camera.h>

Camera::Camera()
{

}

Camera::~Camera()
{
    closeCamera();
    cout << "关闭相机..." << endl;
}

int Camera::openCamera()
{
    int rtn = -1;
    dbg("opening camera ...");

    //打开相机并设置曝光率
    rtn = hkcam.start();
    rtn = hkcam.setExpouse(10000);
    this_thread::sleep_for(chrono::seconds(1));
    
    return rtn;
}

void Camera::closeCamera()
{
    //关闭相机
    hkcam.close();
    this_thread::sleep_for(chrono::seconds(1));
}

int Camera::grabImage(cv::Mat & image)
{
    //设置相机图像触发模式，MONO为黑白照片模式,要注意查看相机是否支持彩色模式
    hkcam.TrrigerOnce(MONO);

    //获取相机图像流
    int rtn = hkcam.getImageData(image);
    
    return rtn;
}