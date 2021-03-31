#pragma once
#include <vector>
using namespace std;
/**/
class PositionControl
{
public:
	PositionControl();
	~PositionControl();

	void setCurrentPos(std::vector<double>& pos, std::vector<double>& RemotePos);
	std::vector<double> compute();
	void setInitPos(std::vector<double>& RobotPos, std::vector<double>& RemotePos);

private:
	vector<double> InitRobotPos,InitRemotePos;
	vector<double> CurRobotPos, CurRemotePos;
};

