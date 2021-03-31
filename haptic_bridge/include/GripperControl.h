#pragma once

#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
#define ARRAY_SET_OPEN_SIZE_GRIPPER {0xEB, 0x90, 0x01, 0x03, 0x54, 0xF4, 0x01, 0x4D}
#define ARRAY_GET_CURRENT_OPEN_SIZE_GRIPPER {0xEB, 0x90, 0x01, 0x01, 0xD9, 0xDB}
#define ARRAY_GET_CURRENT_FORCE_VALUE_GRIPPER {0xEB, 0x90, 0x01, 0x01, 0x14, 0x16}
#define ARRAY_SET_FORCE_CONTINOUS_GRIPPER {0xEB, 0x90, 0x01, 0x05, 0x10, 0xF4, 0x01, 0x64, 0x00, 0x6F}
#define ARRAT_OPEN_GRIPPER {0xEB, 0x90, 0x01, 0x03, 0x11, 0xF4, 0x01, 0x0A}

//遥感设备夹爪自由度角度最值
const double MAX_REMOTE_AXIS_ANGLE = 0.520;
const double MIN_REMOTE_AXIS_ANGLE = 0.160;

//夹爪开口度最值
const int MAX_GRIPPER_OPENSIZE = 1000;
const int MIN_GRIPPER_OPENSIZE = 1;

#include <iostream>
#include <serial/serial.h>
#include <idebug.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <vector>
#include <boost/thread.hpp>

using namespace std;
using namespace serial;




class GripperControl
{
public:

    /*
        * @brief: 构造函数
        */
    GripperControl();

    /*
        * @brief: 析构函数
        */
    ~GripperControl();

    /*
        * @brief: 计算夹爪的遥感反馈力
        */
    void gripperForceCompute(double & force);

    /*
        * @brief: 遥感控制夹爪实时开闭
        */
    // inline void gripperRemoteControl(double angle)
    // {
    //     if (angle > MAX_REMOTE_AXIS_ANGLE)
    //         angle = MAX_REMOTE_AXIS_ANGLE;
    //     else if (angle < MIN_REMOTE_AXIS_ANGLE)
    //         angle = MIN_REMOTE_AXIS_ANGLE;

    //     //根据遥感当前角度量计算夹爪开口度
    //     int currentOpensize = (angle - MIN_REMOTE_AXIS_ANGLE) * (( MAX_GRIPPER_OPENSIZE - MIN_GRIPPER_OPENSIZE) / (MAX_REMOTE_AXIS_ANGLE - MIN_REMOTE_AXIS_ANGLE)) + 1;
    //     // int currentOpensize = (angle - MIN_REMOTE_AXIS_ANGLE) / (MAX_REMOTE_AXIS_ANGLE - MIN_REMOTE_AXIS_ANGLE) * 30 * 33.3 + 1;
    //     cout << "currentOpensize: " << currentOpensize << endl;

    //     //下发指令指定夹爪开口度
    //     setGripperOpenval(currentOpensize);
    // }

    inline void gripperRemoteControl()
    {
        while(true)
        {
            if (angle > MAX_REMOTE_AXIS_ANGLE)
                angle = MAX_REMOTE_AXIS_ANGLE;
            else if (angle < MIN_REMOTE_AXIS_ANGLE)
                angle = MIN_REMOTE_AXIS_ANGLE;

            //根据遥感当前角度量计算夹爪开口度
            int currentOpensize = (angle - MIN_REMOTE_AXIS_ANGLE) * (( MAX_GRIPPER_OPENSIZE - MIN_GRIPPER_OPENSIZE) / (MAX_REMOTE_AXIS_ANGLE - MIN_REMOTE_AXIS_ANGLE)) + 1;
            // int currentOpensize = (angle - MIN_REMOTE_AXIS_ANGLE) / (MAX_REMOTE_AXIS_ANGLE - MIN_REMOTE_AXIS_ANGLE) * 30 * 33.3 + 1;
            cout << "currentOpensize: " << currentOpensize << endl;

            //下发指令指定夹爪开口度
            setGripperOpenval(currentOpensize);

            this_thread::sleep_for(chrono::milliseconds(500));
        }
        
    }

// private:

    /*
        * @brief: 连接夹爪
        */
    int connectGripper();
    
    /*
        * @brief: 断连夹爪
        */
    int disconnectGripper();

    /*
        * @brief: 获取夹爪压力传感器数据值
        */
    // int getGripperForceval();
    inline int getGripperForceval()
    {
        while(true)
        {
            //发送给夹爪的读取压力传感器当前数值
            unsigned char send_buffer[] = ARRAY_GET_CURRENT_FORCE_VALUE_GRIPPER;

            //读取数据
            unsigned char read_buffer[12];

            // int val = 0;
            size_t result = 0;
            while(result == 0)
            {
                //清空串口缓存
                gripper_serial.flush();
                memset(read_buffer, 0, sizeof(read_buffer)/sizeof(char));

                try
                {
                    //发送指令读取数据，反馈的数据依次为夹爪当前开口大小，压力传感器当前值，设置的阈值
                    gripper_serial.write(send_buffer, ARRAY_SIZE(send_buffer));
                    result = gripper_serial.read(read_buffer, 12);

                #ifdef PRINT
                    cout << "数据查询应答帧: ";
                    for (int i = 0; i < ARRAY_SIZE(read_buffer); i++)
                    {
                        cout << hex << int(read_buffer[i]) << " " ;
                    }
                    cout << endl;
                #endif
                    
                    //从应答帧中抽离出压力传感器值
                    GripperControl::forceval = bytes2int2(read_buffer);
                    cout << "live value: " << forceval << endl;  
                }
                catch(const PortNotOpenedException& e)
                {
                    IErrorPrint("read gripper force value failed!");
                    return -1;
                }
            }

            this_thread::sleep_for(chrono::milliseconds(1500));
        }
        
        return 0;
    }
    

    /*
        * @brief: 设置夹爪当前开口度
        */
    // int setGripperOpenval(int openval);
    inline int setGripperOpenval(int openval)
    {
        if (openval <= 0 || openval > 1000)
        {
            IDebug("the openval is outsized!");
            return -1;
        }

        try
        {
            //发送给夹爪的指定当前开口度指令
            unsigned char send_buffer[] = ARRAY_SET_OPEN_SIZE_GRIPPER;
            int buffer_size = ARRAY_SIZE(send_buffer);

            //将低8位存入send_buffer[8]
            send_buffer[5] = (unsigned char)(openval & 0xFF);

            //将高8位存入send_buffer[6]
            send_buffer[6] = (unsigned char)((openval >> 8) & 0XFF);

            //send_buffer[7]为校验和位
            send_buffer[buffer_size - 1] = (unsigned)((send_buffer[2] + send_buffer[3] + send_buffer[4] + \
                                                            send_buffer[5] + send_buffer[6]) & 0xFF);

            //发送指令给夹爪
            gripper_serial.write(send_buffer, buffer_size);
            IDebug("THE COMMAND FO SETTING CURRENT OPEN SIZE HAS BEEN LOADED!");

            unsigned char read_buffer[7];
            gripper_serial.read(read_buffer, 7);

        #ifdef PRINT
            cout << "开闭应答帧: ";
            for (int i = 0; i < ARRAY_SIZE(read_buffer); i++)
            {
                cout << hex << int(read_buffer[i]) << " " ;
            }
            cout << endl;
        #endif
        
            gripper_serial.flush();
        }
        catch(const IOException& e)
        {
            IErrorPrint("set current open size failed!");
            return -1;
        }
        return 0;   
    }

    /*
        * @brief: 让夹爪持续抓取
        */
    int setGripperContinGrasp(int speed = 800, int force = 500);

    /*
        * @brief: 松开夹爪
        */
    int setGripperOpen(int speed = 800);



    /**
        * @brief: bytes2int
        * @param: bytes
        * @return: int
        */
    int bytes2int2(unsigned char* bytes) 
    {
        int iRetVal  = 0;
    
        if(bytes[7] == 0xff && bytes[8] == 0xff)
        {
            iRetVal = -1;
        }
        else
        {
            iRetVal = bytes[7] + ((bytes[8])<<8);
        }
    
        return iRetVal;
    }

    //夹爪USB端口名
    string serialNum = "/dev/ttyUSB0";

    //夹爪控制线程
    boost::thread* gripperGraspThread_;

    //夹爪监听线程
    boost::thread* gripperSuperviseThread_;

    //夹爪串口
    Serial gripper_serial;

    //遥感的角度更新值
    double angle = 0;

    //夹爪压力传感器的值
    double forceval = 0;

};
