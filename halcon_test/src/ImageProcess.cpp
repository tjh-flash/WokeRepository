#include <halcon_test/ImageProcess.h>

ImageProcess::ImageProcess()
{
    OpenWindow(0, 0, 920, 840, "root", "visible", "", &hv_WindowHandle);
    SetColored(hv_WindowHandle, 12);
    initParam();
}

ImageProcess::~ImageProcess()
{
    
}

void ImageProcess::initParam()
{
    //变量清空
    CameraParameters.Clear();
    CameraPose.Clear();

    //读取相机标定参数
    ReadCamPar("/home/fshs/Documents/demo/param1.cal", &CameraParameters);

    //读取相机标定姿态
    ReadPose("/home/fshs/Documents/demo/pose1.dat", &CameraPose);

    //加载相机外参参数
    // for (size_t i = 0; i < CameraPoseArray.size(); i++)
    // {
    //     CameraPose[i] = CameraPoseArray[i];
    //     // cout << CameraPose[i].D() << endl;
    // }
}


void ImageProcess::getDistance(HImage & image)
{
    //径向畸变校正
    HTuple CameraOut;
    ChangeRadialDistortionCamPar("adaptive", CameraParameters, 0, &CameraOut);

    //设置HALCON系统参数
    SetSystem("int_zooming", "false");

    //计算测量矩形区域坐标转换量
    HTuple TmpCtrl_Row = 0.5 * (LineRowStart_Measure + LineRowEnd_Measure);
    HTuple TmpCtrl_Column = 0.5 * (LineColumnStart_Measure + LineColumnEnd_Measure);
    HTuple TmpCtrl_Dr = LineRowStart_Measure - LineRowEnd_Measure;
    HTuple TmpCtrl_Dc = LineColumnEnd_Measure - LineColumnStart_Measure;
    HTuple TmpCtrl_Phi = atan2(TmpCtrl_Dr.D(), TmpCtrl_Dc.D());
    HTuple TmpCtrl_Len1 = 0.5 * sqrt(TmpCtrl_Dr.D() * TmpCtrl_Dr.D() + TmpCtrl_Dc.D() * TmpCtrl_Dc.D());
    HTuple TmpCtrl_Len2 = RoiWidthLen2;

    //创建测量句柄
    HTuple Handle_Measure;

    //Create measure for line Measure. This assumes all images have the same size!
    GenMeasureRectangle2(TmpCtrl_Row, TmpCtrl_Column, TmpCtrl_Phi, TmpCtrl_Len1, TmpCtrl_Len2, IMAGE_WIDTH, IMAGE_HEIGHT, "nearest_neighbor", &Handle_Measure);
    
    //清楚上一次的窗口缓存
    ClearWindow(hv_WindowHandle);
    
    //对发生径向畸变的图像生成投影映射，图像的映射数据存在第一个参数中
    HObject Map;
    GenRadialDistortionMap(&Map, CameraParameters, CameraOut, "bilinear");

    //对图像进行畸变校正,得到新的校正图像
    HImage imageMapped;
    MapImage(image, Map, &imageMapped);
    // WriteImage(imageMapped, "png" ,0, "/home/fshs/Documents/hhhh");

    //声明各输出变量
    HTuple Row_Measure, Column_Measure, Amplitude_Measure, Score_Measure, Distance_Measure, Row_World_Measure, Column_World_Measure;

    //对距离进行模糊测量
    FuzzyMeasurePos(imageMapped, Handle_Measure, SigmaValue, AmplitudeThreshold, FuzzyThreshold, "positive", 
                        &Row_Measure, &Column_Measure, &Amplitude_Measure, &Score_Measure, &Distance_Measure);

    //将像素尺寸转换成实际尺寸
    ImagePointsToWorldPlane(CameraParameters, CameraPose, Row_Measure, Column_Measure, 0.001, &Row_World_Measure, &Column_World_Measure);
    
    //进行测量效果展示
    HTuple width, height;
    GetImageSize(image, &width, &height);
    SetPart(hv_WindowHandle, 0, 0, height, width);
    DispObj(imageMapped, hv_WindowHandle);

    //画出检侧效果分割线段
    for (size_t j = 0; j < Row_Measure.Length(); j++)
    {
        SetColor(hv_WindowHandle, "yellow");
        SetLineWidth(hv_WindowHandle, 1);
        DispLine(hv_WindowHandle, Row_Measure[j] - 200, Column_Measure[j], Row_Measure[j] + 200, Column_Measure[j]);
    }

    std::cout << "像素测量结果： " << std::endl;
    for (size_t i = 0; i < Distance_Measure.Length(); i++)
        std::cout << Distance_Measure[i].D() << ", ";
    std::cout << std::endl;

    std::cout << "真实测量结果： " << std::endl;
    for (size_t i = 0; i < Row_World_Measure.Length() - 1; i++)
        std::cout << Row_World_Measure[i].D() -  Row_World_Measure[i + 1].D() << ", ";
    std::cout << std::endl;

        
    // string distance_result = "测量结果为: " + to_string(Distance_Measure[0].D());
    // const char *cstr = distance_result.c_str();
    // SetColor(hv_WindowHandle, "blue");
    // SetTposition(hv_WindowHandle, 100, 100);
    // WriteString(hv_WindowHandle, HTuple(cstr));
    
    // 更新图片内容
    DumpWindowImage(&imageMapped, hv_WindowHandle);

    //关闭测量句柄
    CloseMeasure(Handle_Measure);
    
}

void ImageProcess::Mat2HObject(const Mat &image, HObject &outObj)
{
    int hgt = image.rows;
    int wid = image.cols;
    int i;

    try
    {
         //	CV_8UC3
        if (image.type() == CV_8UC3)
        {
            vector<Mat> imgchannel;
            split(image, imgchannel);
            Mat imgB = imgchannel[0];
            Mat imgG = imgchannel[1];
            Mat imgR = imgchannel[2];
            uchar *dataR = new uchar[hgt * wid];
            uchar *dataG = new uchar[hgt * wid];
            uchar *dataB = new uchar[hgt * wid];

            for (i = 0; i < hgt; i++)
            {
                memcpy(dataR + wid * i, imgR.data + imgR.step * i, wid);
                memcpy(dataG + wid * i, imgG.data + imgG.step * i, wid);
                memcpy(dataB + wid * i, imgB.data + imgB.step * i, wid);
            }

            GenImage3(&outObj, "byte", wid, hgt, (Hlong)dataR, (Hlong)dataG, (Hlong)dataB);
            delete[]dataR;
            delete[]dataG;
            delete[]dataB;
            dataR = nullptr;
            dataG = nullptr;
            dataB = nullptr;
        }

        //	CV_8UCU1
        else if (image.type() == CV_8UC1)
        {
            uchar *data = new uchar[hgt * wid];
            for (i = 0; i < hgt; i++)
                memcpy(data + wid * i, image.data + image.step * i, wid);
            GenImage1(&outObj, "byte", wid, hgt, (Hlong)data);
            delete[] data;
            data = nullptr;
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "Mat转HObject出现问题，请检查" << std::endl;
        std::cerr << e.what() << '\n';
    }
    
}

void ImageProcess::HObject2Mat(const HObject &_Hobj, cv::Mat &outMat)
{
    try
    {
        HTuple htCh = HTuple();
        HString cType;
        cv::Mat Image;
        HObject Hobj;
        ConvertImageType(_Hobj, &Hobj, "byte");
        CountChannels(Hobj, &htCh);
        Hlong w;
        Hlong h;
        if (htCh[0].I() == 1)
        {
            void* ptr = ((HImage)Hobj).GetImagePointer1(&cType, &w, &h);
            Image.create(h, w, CV_8UC1);
            uchar *pdata = static_cast<unsigned char *>(ptr);
            memcpy(Image.data, pdata, w * h);
        }
        else if (htCh[0].I() == 3)
        {
            void** pr = nullptr;
            void** pg = nullptr;
            void** pb = nullptr;
            ((HImage)Hobj).GetImagePointer3(pr, pg, pb, &cType,&w, &h);
            Image.create(h, w, CV_8UC3);
            std::vector<cv::Mat> vecM(3);
            vecM[2].create(h, w, CV_8UC1);
            vecM[1].create(h, w, CV_8UC1);
            vecM[0].create(h, w, CV_8UC1);
            memcpy(vecM[2].data, pr, w * h);
            memcpy(vecM[1].data, pg, w * h);
            memcpy(vecM[0].data, pb, w * h);
            merge(vecM, Image);
        }
        outMat = Image;
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "HObject转Mat出现问题，请检查" << std::endl;
    }
       
}

void ImageProcess::showImage(const HImage himage)
{
    try
    {
        ClearWindow(hv_WindowHandle);
        HTuple width, height;
        GetImageSize(himage, &width, &height);
        SetPart(hv_WindowHandle, 0, 0, height, width);
        DispObj(himage, hv_WindowHandle);
    }
    catch(const HOperatorException& e)
    {
        dbg(e.ErrorMessage());
    }
    
}