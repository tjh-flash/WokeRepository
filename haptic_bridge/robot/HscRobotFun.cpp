#include "HscRobotFun.h"
#include <iostream>
#include <assert.h>
#define GROUP_NUM 0
HscRobotFun::HscRobotFun()
{
	ComApi = std::make_shared<CommApi>();
	ComApi->setAutoConn(false);

	ProxyMotionPtr = std::make_shared<ProxyMotion>(ComApi.get());
}


HscRobotFun::~HscRobotFun()
{
}

bool HscRobotFun::connect()
{
	HMCErrCode code = ComApi->connect("10.10.56.214",23234);
	return code == 0? true:false;
}

bool HscRobotFun::isConnect()
{
	return ComApi->isConnected();	
}

bool HscRobotFun::getEnable()
{
	bool enable = false;
	HMCErrCode code = ProxyMotionPtr->getGpEn(0, enable);
	assert(code == 0);
	return enable;
}

// �����˵���̬��XYZ ABC ZYX����
vector<double> HscRobotFun::getCurrentPose()
{
	ReConnect();
	LocData POS;
	ProxyMotionPtr->getLocData(GROUP_NUM, POS);
	POS.erase(POS.end()-3, POS.end());
	return POS;
}

void HscRobotFun::ReConnect()
{
	if (!isConnect()) {
		ComApi->connect("10.10.56.214", 23234);
		std::cout << " ReConnect " << std::endl;
	}
}

bool HscRobotFun::setEnable(bool en)
{
	int ret = ProxyMotionPtr->setGpEn(GROUP_NUM, en);
	return ret == 0 ? true : false;
}