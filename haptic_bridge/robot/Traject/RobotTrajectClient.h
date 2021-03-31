#pragma once

#include <memory>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <MidRosInterface/midRosInterfaces.h>
using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
enum MotionType{
	Joint = 0,
	Cart = 1,
};
class RobotTrajectClient
{
public:
	RobotTrajectClient();
	~RobotTrajectClient();
	//点位下发控制	
	void setTrajStartPoint(vector<double> Tpoint, double time, MotionType type);
	void setTrajRunPoint(vector<double> Tpoint);
	void setTrajEnd();
	void setTrajTest();

private:
	 boost::shared_ptr<TSocket> socket1;
	 boost::shared_ptr<TTransport> transport;
	 boost::shared_ptr<TProtocol> protocol;
	 boost::shared_ptr<midRosInterfacesClient> client;
	 MotionType type;
	 double time;
};

