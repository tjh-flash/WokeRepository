#pragma once

#include <Control/PositionControl.h>
#include <HelperTool.h>
#include <log.h>
#include <Traject/RobotTrajectClient.h>
#include <HscRobotFun.h>
#include <RobotUtilty.h>

#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>

#include <chai3d.h>

using namespace std;
using namespace chai3d;

/*
    *@brief: 力控控制遥感操作
    */
void RemoteForceControl(const cVector3d & position);

