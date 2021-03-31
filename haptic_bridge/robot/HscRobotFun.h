#pragma once
#include <CommApi.h>
#include <memory>
#include <vector>
#include <proxy/ProxyMotion.h>
using namespace Hsc3::Comm;
using namespace Hsc3::Proxy;

using namespace std;

class HscRobotFun
{
public:
	HscRobotFun();
	~HscRobotFun();

	bool connect();
	bool isConnect();
	bool getEnable();
	vector<double> getCurrentPose();
	bool setEnable(bool en);
private:
	void ReConnect();
private:
	std::shared_ptr<CommApi> ComApi;
	std::shared_ptr<ProxyMotion> ProxyMotionPtr;
};

