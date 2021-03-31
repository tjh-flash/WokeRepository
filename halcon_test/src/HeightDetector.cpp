#include <halcon_test/HeightDetector.h>

HeightDetector::HeightDetector()
{
    cam = std::make_shared<Camera>();
    imp = std::make_shared<ImageProcess>();
    
    isDetecting = false;
}

HeightDetector::~HeightDetector()
{

}

void HeightDetector::init()
{
    int ret = -1;

    //开启摄像头,并进行状态反馈
    ret = cam->openCamera();

    if (ret == -1)
    {
        isDetecting = false;
        dbg("##相机开启失败");
        return;
    }
    else 
        isDetecting = true;

    //先进行两次相机数据流捕获来测试相机是否正常工作
    for (int i = 0; i < 2; i++)
    {
        Image.release();
        ret = cam->grabImage(Image);
    }

    if ( ret == -1)
    {
        //先重启相机尝试进行修复
        dbg("##获取图像数据流失败，尝试重启相机中...");
        cam->closeCamera();
        cam->openCamera();
        if(cam->grabImage(Image) == -1)
        {
            isDetecting = false;
            dbg("##相机重启失败，请检查");
            return;
        }
        else
        {
            dbg("##相机重启成功，已正常运行");
            isDetecting = true;
        }
    }
    else 
    {
        isDetecting = true;
    }

}


void HeightDetector::heightCheck()
{
    //先清空上一次的图像缓存
    Image.release();
    Himage.Clear();

    //捕获图片
    if(cam->grabImage(Image) == -1)
    {
        isDetecting = false;
        return;
    }
    isDetecting = true;

    //进行图像格式转换
    imp->Mat2HObject(Image, Himage);

    //进行高度距离检测
    imp->getDistance(Himage);
}