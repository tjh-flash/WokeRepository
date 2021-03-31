#pragma once
#include <cmath>
#include <math.h>
#include <math/CVector3d.h>
#include <chrono>
#include <iostream>

using namespace std;
using namespace chai3d;
class HelperTool
{
public:
	HelperTool();
	~HelperTool();
public:
	double static force_2_coeff(cVector3d forceField1)
	{
		double coeff_2_robot = 1;
		if (abs(forceField1(0)) > 0.5 || fabs(forceField1(1)) > 0.5 || abs(forceField1(2)) > 0.5)
		{
			coeff_2_robot = 0.5 / (cMax(cMax(abs(forceField1(0)), abs(forceField1(1))), abs(forceField1(2))));
		}
		return coeff_2_robot;
	}

	double avr_filter(double a[10], double coeff_2_robot)
	{
		double coeff_2_robot_sum = 0;
		for (int num_a = 0; num_a < 9; num_a++)
		{
			a[num_a] = a[num_a + 1];
		}
		a[9] = coeff_2_robot;

		for (int num_a = 0; num_a < 10; num_a++)
		{
			coeff_2_robot_sum += a[num_a];
		}
		coeff_2_robot = coeff_2_robot_sum / 10;
		return coeff_2_robot;
	}
};

class TimeUtilty {

public:
	static std::time_t getTimeStamp()
	{
		std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
		auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
		std::time_t timestamp = tmp.count();
		//std::time_t timestamp = std::chrono::system_clock::to_time_t(tp);
		return timestamp;
	}

	static void PrintNow()
	{
		std::cout << getTimeStamp() << std::endl;;
	}

};
