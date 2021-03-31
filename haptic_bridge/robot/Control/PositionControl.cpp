#include "PositionControl.h"
#include <assert.h>
#include <string>
#include <iostream>
#include <log.h>
#include <math.h>
PositionControl::PositionControl()
{
}

PositionControl::~PositionControl()
{
}

void PositionControl::setInitPos(std::vector<double>& RobotPos, std::vector<double>& RemotePos)
{
	assert(RobotPos.size() == 6);
	InitRobotPos.clear();
	InitRobotPos = RobotPos;
	InitRemotePos.clear();
	InitRemotePos = RemotePos;
}

void PositionControl::setCurrentPos(std::vector<double>& pos, std::vector<double>& RemotePos)
{
	assert(pos.size() == 6);
	CurRobotPos.clear();
	CurRobotPos = pos;

	CurRemotePos.clear();
	CurRemotePos = RemotePos;
}

/// XYZ �Ǿ���ƫ��� ABC����Ե�ƫ��
std::vector<double> PositionControl::compute()
{
	const double coeff_2_robot = 1;
	const double coeff = 1000.;//ͨ��ϵ������������˵�λ���ٶ�ӳ��

	std::vector<double> RemoteBias(6), target(6);
	for (int i = 0; i < 6; i++)
	{
		RemoteBias[i] = (CurRemotePos[i] - InitRemotePos[i]);
	}

	for (int i = 3; i < 6; i++)
	{
		if (fabs(RemoteBias[i])> 30)
		{
			if (RemoteBias[i] > 0)
				RemoteBias[i] = 30;
			else
				RemoteBias[i] = -30;
		}

	}
	RemoteBias[3] = -RemoteBias[3];
	RemoteBias[4] = -RemoteBias[4];
	RemoteBias[5] = -RemoteBias[5];

	//Disable EularAngle
	// RemoteBias[3] = 0;
	// RemoteBias[4] = 0;
	// RemoteBias[5] = 0;

	Log::debug("RemoteBias: ", RemoteBias);
	string msg = std::to_string(RemoteBias[0]) + ',' + std::to_string(RemoteBias[1])+  ',' +
		std::to_string(RemoteBias[2] );
	std::cout << "msg: " << msg << std::endl;
	//' + std::to_string(tr2robot[0]) + ', ' + std::to_string(tr2robot[1]) + ', ' + std::to_string(tr2robot[2]) + '\n';

	//target[0] = (InitRobotPos[0]/1000 + RemoteBias[0]* coeff_2_robot) * coeff;
	//target[1] = (InitRobotPos[1]/1000 + RemoteBias[1]* coeff_2_robot) * coeff;
	//target[2] = (InitRobotPos[2]/1000 + RemoteBias[2]* coeff_2_robot) * coeff;
	target[0] = ( RemoteBias[0] * coeff_2_robot ) * coeff;
	target[1] = ( RemoteBias[1] * coeff_2_robot ) * coeff;
	target[2] = ( RemoteBias[2] * coeff_2_robot ) * coeff;
	target[3] =  RemoteBias[3];
	target[4] =  RemoteBias[4];
	target[5] =  RemoteBias[5];

	//for (int i = 3; i < 6; i++)
	//{
	//	if (target[i] > 180)
	//	{
	//		target[i] = -360 + target[i];
	//	}
	//	else if (target[i] < -180) {
	//		target[i] = 360 + target[i];
	//	}
	//}

	//for (int i = 0; i < 6; i++)
	//	InitRobotPos[i] = CurRobotPos[i];

	return target;
}

