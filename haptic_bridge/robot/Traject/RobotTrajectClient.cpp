#include "RobotTrajectClient.h"
#include <boost/make_shared.hpp>
RobotTrajectClient::RobotTrajectClient()
{
	socket1 = boost::make_shared<TSocket>("10.10.56.214", 9095);
	transport = boost::make_shared<TBufferedTransport>(socket1);
	protocol = boost::make_shared<TBinaryProtocol>(transport);
	client = boost::make_shared<midRosInterfacesClient>(protocol);
	transport->open();
	assert(transport->isOpen());
}


RobotTrajectClient::~RobotTrajectClient()
{
	transport->close();
}

void RobotTrajectClient::setTrajStartPoint(vector<double> Tpoint, double time, MotionType type)
{
	assert(Tpoint.size() == 6);
	assert(time > 16 && time < 100);
	this->time = time;
	this->type = type;

	JointPt point;
	point.pos = Tpoint;
	point.time = time;
	point.sequence = -1;
	point.isCart = (int)type;
	client->setJntTrajSinglePt(point);
}

void RobotTrajectClient::setTrajRunPoint(vector<double> Tpoint)
{
	JointPt point;
	point.pos = Tpoint;
	point.time = time;
	point.sequence = 1;
	point.isCart = (int)type;

	client->setJntTrajSinglePt(point);
}

void RobotTrajectClient::setTrajEnd()
{
	JointPt point;
	point.time = time;
	point.sequence = -3;
	client->setJntTrajSinglePt(point);
}

void RobotTrajectClient::setTrajTest()
{
	JointPt point;
	//point.time = time;
	point.sequence = -2;
	client->setJntTrajSinglePt(point);
}
 
