#include <GripperControl.h>

//遥感设备夹爪自由度角度最值
// const double MAX_REMOTE_AXIS_ANGLE = 0.520;
// const double MIN_REMOTE_AXIS_ANGLE = 0.160;

// //夹爪开口度最值
// const int MAX_GRIPPER_OPENSIZE = 1000;
// const int MIN_GRIPPER_OPENSIZE = 1;

//串口端口
// Serial gripper_serial;

GripperControl::GripperControl()
{
    connectGripper();

    //创建夹爪线程
    gripperGraspThread_ = new boost::thread(boost::bind(&GripperControl::gripperRemoteControl, this));
    gripperSuperviseThread_ = new boost::thread(boost::bind(&GripperControl::getGripperForceval, this));
}

GripperControl::~GripperControl()
{
    disconnectGripper();

    if (gripperGraspThread_)
    {
        gripperGraspThread_->join();
        delete gripperGraspThread_;
    }

     if (gripperSuperviseThread_)
    {
        gripperSuperviseThread_->join();
        delete gripperSuperviseThread_;
    }
}

void GripperControl::gripperForceCompute(double & force)
{
    if ( getGripperForceval() == -1)
    {
        force = 0;
        IErrorPrint("夹爪压力传感器数据读取失败，请检查！！");
        return;
    }
    if (getGripperForceval() == 0)
    {
        force = 0;
        IDebug("当前夹爪传感器数据为零，未碰测抓取到物体");
    }
    else
    {
        force = getGripperForceval();
    }
    
}


// void GripperControl::gripperRemoteControl(double angle)
// {
//     if (angle > MAX_REMOTE_AXIS_ANGLE)
//         angle = MAX_REMOTE_AXIS_ANGLE;
//     else if (angle < MIN_REMOTE_AXIS_ANGLE)
//         angle = MIN_REMOTE_AXIS_ANGLE;

//     //根据遥感当前角度量计算夹爪开口度
//     int currentOpensize = (angle - MIN_REMOTE_AXIS_ANGLE) * (( MAX_GRIPPER_OPENSIZE - MIN_GRIPPER_OPENSIZE) / (MAX_REMOTE_AXIS_ANGLE - MIN_REMOTE_AXIS_ANGLE)) + 1;
//     // int currentOpensize = (angle - MIN_REMOTE_AXIS_ANGLE) / (MAX_REMOTE_AXIS_ANGLE - MIN_REMOTE_AXIS_ANGLE) * 30 * 33.3 + 1;
//     cout << "currentOpensize: " << currentOpensize << endl;

//     // //下发指令指定夹爪开口度
//     setGripperOpenval(currentOpensize);
// }


int GripperControl::connectGripper()
{
    try
    {   
        //设置usb串口名称
        gripper_serial.setPort(serialNum);

        //设置串口波特率
        gripper_serial.setBaudrate(115200);

        //配置读写超时时间
        serial::Timeout to = Timeout::simpleTimeout(1000);
        gripper_serial.setTimeout(to);

        //打开串口
        gripper_serial.open();
    }
    catch(const serial::IOException& e)
    {
        IErrorPrint("Unable to open port!!!");
        return -1;
    }

    IErrorPrint("Serial Port open ok ");
    return 0;
}

int GripperControl::disconnectGripper()
{
    try 
    {
        gripper_serial.close();
    } 
    catch (const serial::IOException& e) 
    {
        IErrorPrint("Unable to close port!!!");
        return -1;
    }
    IDebug("Serial Port closed");
    return 0;
}


// int GripperControl::getGripperForceval()
// {
//     //发送给夹爪的读取压力传感器当前数值
//     unsigned char send_buffer[] = ARRAY_GET_CURRENT_FORCE_VALUE_GRIPPER;

//     //读取数据
//     unsigned char read_buffer[12];

//     int val = 0;
//     size_t result = 0;
//     while(result == 0)
//     {
//         //清空串口缓存
//         gripper_serial.flush();
//         memset(read_buffer, 0, sizeof(read_buffer)/sizeof(char));

//         try
//         {
//             //发送指令读取数据，反馈的数据依次为夹爪当前开口大小，压力传感器当前值，设置的阈值
//             gripper_serial.write(send_buffer, ARRAY_SIZE(send_buffer));
//             result = gripper_serial.read(read_buffer, 12);
//             // cout << "数据查询应答帧: ";
//             // for (int i = 0; i < ARRAY_SIZE(read_buffer); i++)
//             // {
//             //     cout << hex << int(read_buffer[i]) << " " ;
//             // }
//             // cout << endl;
            
//             //从应答帧中抽离出压力传感器值s
//             val = bytes2int2(read_buffer);
           
//         }
//         catch(const PortNotOpenedException& e)
//         {
//             IErrorPrint("read gripper force value failed!");
//             return -1;
//         }
//     }

//     //返回最终值
//     return val;
// }


// int GripperControl::setGripperOpenval(int openval)
// {
//     if (openval <= 0 || openval > 1000)
//     {
//         IDebug("the openval is outsized!");
//         return -1;
//     }

//     try
//     {
//         //发送给夹爪的指定当前开口度指令
//         unsigned char send_buffer[] = ARRAY_SET_OPEN_SIZE_GRIPPER;
//         int buffer_size = ARRAY_SIZE(send_buffer);

//         //将低8位存入send_buffer[8]
//         send_buffer[5] = (unsigned char)(openval & 0xFF);

//         //将高8位存入send_buffer[6]
//         send_buffer[6] = (unsigned char)((openval >> 8) & 0XFF);

//         //send_buffer[7]为校验和位
//         send_buffer[buffer_size - 1] = (unsigned)((send_buffer[2] + send_buffer[3] + send_buffer[4] + \
//                                                         send_buffer[5] + send_buffer[6]) & 0xFF);

//         //发送指令给夹爪
//         gripper_serial.write(send_buffer, buffer_size);
//         IDebug("THE COMMAND FO SETTING CURRENT OPEN SIZE HAS BEEN LOADED!");

//         unsigned char read_buffer[7];
//         gripper_serial.read(read_buffer, 7);
//         // cout << "开闭应答帧: ";
//         // for (int i = 0; i < ARRAY_SIZE(read_buffer); i++)
//         // {
//         //     cout << hex << int(read_buffer[i]) << " " ;
//         // }
//         // cout << endl;
//         gripper_serial.flush();
        

//     }
//     catch(const IOException& e)
//     {
//         IErrorPrint("set current open size failed!");
//         return -1;
//     }
//     return 0;   
// }

int GripperControl::setGripperContinGrasp(int speed, int force)
{
    unsigned char close_buffer[] = ARRAY_SET_FORCE_CONTINOUS_GRIPPER;
    int size_close_buffer = ARRAY_SIZE(close_buffer);

    try 
    {
        //将输入值req.speed保存为临时变量，以备后面数值处理
        int temp = speed;
        //将低8位存入close_buffer[5]
        close_buffer[5]= (unsigned char)(temp&0xFF);
        //将高8位存入close_buffer[6]
        close_buffer[6]= (unsigned char)((temp&0xFF00)>>8);

        //将输入值req.force保存为临时变量，以备后面数值处理
        temp = force;
        //将低8位存入close_buffer[7]
        close_buffer[7]= (unsigned char)(temp&0xFF);
        //将高8位存入close_buffer[8]
        close_buffer[8]= (unsigned char)((temp&0xFF00)>>8);
        //close_buffer[9]为校验和位 （（B2+B3+…+B8）&0xFF）
        close_buffer[size_close_buffer-1]= (unsigned char)((close_buffer[2] + close_buffer[3] + \
                                                        close_buffer[4] + close_buffer[5] + \
                                                        close_buffer[6] + close_buffer[7] + close_buffer[8])&0xFF);
        
        //串口读写
        gripper_serial.write(close_buffer,size_close_buffer);
        unsigned char read_buffer[7];
        gripper_serial.read(read_buffer, 7);
        IDebug("THE COMMAND OF --CLOSE-- HAS BEEN LOADED!!!");
    } 
    catch (IOException& e) 
    {
        IErrorPrint("gripper close failed!!!");
        return -1;
    }
}

int GripperControl::setGripperOpen(int speed)
{
    unsigned char open_buffer[] = ARRAT_OPEN_GRIPPER;
    int size_open_buffer = ARRAY_SIZE(open_buffer);

    try 
    {
        //将输入值req.speed保存为临时变量，以备后面数值处理
        int temp = speed;
        //将低8位存入open_buffer[5]
        open_buffer[5]= (unsigned char)(temp&0xFF);
        //将高8位存入open_buffer[6]
        open_buffer[6]= (unsigned char)((temp&0xFF00)>>8);
        //close_buffer[7]为校验和位 （（B2+B3+…+B8）&0xFF）
        open_buffer[size_open_buffer-1]= (unsigned char)((open_buffer[2] + open_buffer[3] + \
                                                        open_buffer[4] + open_buffer[5] + \
                                                        open_buffer[6])&0xFF);
        gripper_serial.write(open_buffer,size_open_buffer);
        IDebug("THE COMMAND OF --OPEN-- HAS BEEN LOADED!!!");


        unsigned char read_buffer[7];
        gripper_serial.read(read_buffer, 7);
    } 
    catch (serial::IOException& e) 
    {
        IErrorPrint("gripper open failed!!!");
        return -1;
    }

    IDebug("gripper open!");
    return 0;
}