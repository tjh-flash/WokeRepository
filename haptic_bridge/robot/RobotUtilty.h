#pragma once
#include <math.h>
#include <stdio.h>

#define pi 3.14159265
/**
	�����˿��ƹ�����
**/
class RobotUtilty {
	/*//????????rpy(??????????????????????x,y,z?????)
	*R       ??????
	*rpy     ?????????????????(????)??????
	*flag    order 0:XYZ order 1:ZYX order 2:XYZ 
	*solve 0:��һ���᣻1:�ڶ����᣻
	*/
public:

	void  static tr2rpy(double R[3][3], double* rpy, int flag, int solve)
	{
		double eps = 0.000001;
		double s = 0.0;
		double c = 0.0;
		double cp = 0.0;
		double Q = 0.0;
		double m = 0.0;
		int symbol = 1;

		//matlab ��Ԫ��
		double qs = 0;
		double kx = 0;
		double ky = 0;
		double kz = 0;
		double kx1 = 0;
		double ky1 = 0;
		double kz1 = 0;
		int add = 0;
		double nm = 0;
		switch (flag)
		{
		case 0://XYZ order
			if (fabs(R[2][2])<eps&&fabs(R[1][2])<eps)
			{
				//singularity
				rpy[0] = 0;//roll is zero
				rpy[1] = atan2(R[0][2], R[2][2]);//pitch
				rpy[2] = atan2(R[1][0], R[1][1]);//yaw is sum of roll+yaw
			}
			else
			{
				rpy[0] = atan2(-R[1][2], R[2][2]);//roll
				s = sin(rpy[0]);
				c = cos(rpy[0]);
				rpy[1] = atan2(R[0][2], c*R[2][2] - s*R[1][2]);//pitch
				rpy[2] = atan2(-R[0][1], R[0][0]);//yaw

			}
			break;
		case 1://ZYX order
			if (fabs(R[0][0])<eps&&fabs(R[1][0])<eps)
			{
				//singularity
				rpy[0] = 0;//roll is zero
				rpy[1] = atan2(-R[2][0], R[0][0]);//pitch
				rpy[2] = atan2(-R[1][2], R[1][1]);//yaw is sum of roll+yaw
			}
			else
			{
				rpy[0] = atan2(R[1][0], R[0][0]);//roll
				s = sin(rpy[0]);
				c = cos(rpy[0]);
				rpy[1] = atan2(-R[2][0], c*R[0][0] + s*R[1][0]);//pitch
				rpy[2] = atan2(s*R[0][2] - c*R[1][2], c*R[1][1] - s*R[0][1]);//yaw

			}
			break;
		case 2://XYZ HLHN J.CRAIG method
			if (1 == solve)
			{
				symbol = -1;
			}
			rpy[1] = atan2(-R[2][0], symbol*sqrt(R[0][0] * R[0][0] + R[1][0] * R[1][0])); //pitch
			if (fabs(fabs(rpy[1]) - pi / 2.0) < eps)
			{
				if (rpy[1] > 0) //pi/2
				{
					rpy[1] = pi / 2.0;
					rpy[2] = 0.0;
					rpy[0] = atan2(R[0][1], R[1][1]);
				}
				else//-pi/2
				{
					rpy[1] = -pi / 2.0;
					rpy[2] = 0.0;
					rpy[0] = -atan2(R[0][1], R[1][1]);
				}
			}
			else
			{
				cp = cos(rpy[1]);
				rpy[2] = atan2(R[1][0] / cp, R[0][0] / cp);
				rpy[0] = atan2(R[2][1] / cp, R[2][2] / cp);
			}
			break;
		case 3://??��???  //orocos
			cp = (R[0][0] + R[1][1] + R[2][2] - 1) / 2.0;
			if (cp>1 - (eps*(1e-6)))
			{
				rpy[0] = 0;
				rpy[1] = 0;
				rpy[2] = 0;
			}
			else if (cp<-1 + (eps*(1e-6)))
			{
				rpy[0] = sqrt((R[0][0] + 1.0) / 2);
				rpy[1] = sqrt((R[1][1] + 1.0) / 2);
				rpy[2] = sqrt((R[2][2] + 1.0) / 2);
				if (R[0][2]< 0) rpy[0] = -rpy[0];
				if (R[2][1]< 0) rpy[1] = -rpy[1];
				if (rpy[0] * rpy[1] * R[0][1] < 0) rpy[0] = -rpy[0];  // this last line can be necessary when z is 0
																	  // z always >= 0
																	  // if z equal to zero
				rpy[0] = rpy[0] * pi;
				rpy[1] = rpy[1] * pi;
				rpy[2] = rpy[2] * pi;
			}
			else
			{
				Q = acos(cp);

				rpy[0] = Q*0.5*(R[2][1] - R[1][2]) / sin(Q);
				rpy[1] = Q*0.5*(R[0][2] - R[2][0]) / sin(Q);
				rpy[2] = Q*0.5*(R[1][0] - R[0][1]) / sin(Q);
			}


			break;
		case 4://��λ��Ԫ��
			m = 0.5*sqrt(1 + R[0][0] + R[1][1] + R[2][2]);
			if (fabs(m)<eps)
			{
				printf("quaternion no solution!\n");
				break;
			}
			rpy[3] = m;
			rpy[0] = (R[2][1] - R[1][2]) / (4 * rpy[3]);
			rpy[1] = (R[0][2] - R[2][0]) / (4 * rpy[3]);
			rpy[2] = (R[1][0] - R[0][1]) / (4 * rpy[3]);
			break;
		case 5: //matlab �����˹�����
			qs = sqrt((R[0][0] + R[1][1] + R[2][2]) + 1) / 2.0;
			kx = R[2][1] - R[1][2];   // Oz - Ay
			ky = R[0][2] - R[2][0];   //Ax - Nz
			kz = R[1][0] - R[0][1];   // Ny - Ox

			if ((R[0][0] >= R[1][1]) && (R[0][0] >= R[2][2]))
			{
				kx1 = R[0][0] - R[1][1] - R[2][2] + 1; // Nx - Oy - Az + 1
				ky1 = R[1][0] + R[0][1];          // Ny + Ox
				kz1 = R[2][0] + R[0][2];          // Nz + Ax
				if (kx >= 0)
				{
					add = 1;
				}
				else
				{
					add = 0;
				}
			}
			else if (R[1][1] >= R[2][2])
			{
				kx1 = R[1][0] + R[0][1];          //Ny + Ox
				ky1 = R[1][1] - R[0][0] - R[2][2] + 1; // Oy - Nx - Az + 1
				kz1 = R[2][1] + R[1][2];          // Oz + Ay
				if (ky >= 0)
				{
					add = 1;
				}
				else
				{
					add = 0;
				}
			}
			else
			{
				kx1 = R[2][0] + R[0][2];          // Nz + Ax
				ky1 = R[2][1] + R[1][2];          //Oz + Ay
				kz1 = R[2][2] - R[0][0] - R[1][1] + 1; // Az - Nx - Oy + 1
				if (kz >= 0)
				{
					add = 1;
				}
				else
				{
					add = 0;
				}
			}
			if (add)
			{
				kx = kx + kx1;
				ky = ky + ky1;
				kz = kz + kz1;
			}
			else
			{
				kx = kx - kx1;
				ky = ky - ky1;
				kz = kz - kz1;
			}
			nm = sqrt(kx*kx + ky*ky + kz*kz);
			if (nm<0.000001)
			{
				rpy[3] = 1; rpy[0] = 0; rpy[1] = 0; rpy[2] = 0;

			}
			else
			{
				s = sqrt(1 - qs*qs) / nm;
				rpy[3] = qs; rpy[0] = s*kx; rpy[1] = s*ky; rpy[2] = s*kz;

			}
			break;
		default:
			break;
		}

	}

	void static rpy2tr(double* rpy, double R[3][3], int flag)
	{
		double sx = 0;
		double cx = 0;
		double sy = 0;
		double cy = 0;
		double sz = 0;
		double cz = 0;

		double Q = 0;
		double k[3];
		double v = 0;

		/*
		Rx = [
		1   0    0
		0   cx  -sx
		0   sx   cx
		];
		Ry = [
		cy  0   sy
		0   1   0
		-sy  0   cy
		];
		Rz = [
		cz  -sz  0
		sz   cz  0
		0    0   1
		];
		*/
		switch (flag)
		{
		case 0://XYZ order
			sx = sin(rpy[0]);
			cx = cos(rpy[0]);
			sy = sin(rpy[1]);
			cy = cos(rpy[1]);
			sz = sin(rpy[2]);
			cz = cos(rpy[2]);
			//R=Rx*Ry*Rz
			R[0][0] = cy*cz; R[0][1] = -cy*sz; R[0][2] = sy;
			R[1][0] = cx*sz + cz*sx*sy; R[1][1] = cx*cz - sx*sy*sz; R[1][2] = -cy*sx;
			R[2][0] = sx*sz - cx*cz*sy; R[2][1] = cz*sx + cx*sy*sz; R[2][2] = cx*cy;
			break;
		case 1://ZYX order
			sx = sin(rpy[2]);
			cx = cos(rpy[2]);
			sy = sin(rpy[1]);
			cy = cos(rpy[1]);
			sz = sin(rpy[0]);
			cz = cos(rpy[0]);
			//R=Rz*Ry*Rx
			R[0][0] = cy*cz; R[0][1] = cz*sx*sy - cx*sz; R[0][2] = sx*sz + cx*cz*sy;
			R[1][0] = cy*sz; R[1][1] = cx*cz + sx*sy*sz; R[1][2] = cx*sy*sz - cz*sx;
			R[2][0] = -sy; R[2][1] = cy*sx; R[2][2] = cx*cy;
			break;
		case 2://XYZ HLHN J.CRAIG method
			sx = sin(rpy[0]);
			cx = cos(rpy[0]);
			sy = sin(rpy[1]);
			cy = cos(rpy[1]);
			sz = sin(rpy[2]);
			cz = cos(rpy[2]);
			//R=Rz*Ry*Rx
			R[0][0] = cy*cz; R[0][1] = cz*sx*sy - cx*sz; R[0][2] = sx*sz + cx*cz*sy;
			R[1][0] = cy*sz; R[1][1] = cx*cz + sx*sy*sz; R[1][2] = cx*sy*sz - cz*sx;
			R[2][0] = -sy; R[2][1] = cy*sx; R[2][2] = cx*cy;
			break;
		case 3://??��???
			Q = sqrt(rpy[0] * rpy[0] + rpy[1] * rpy[1] + rpy[2] * rpy[2]);
			if (Q<0.000001)
			{
				R[0][0] = 1;	R[0][1] = 0;	R[0][2] = 0;
				R[1][0] = 0;	R[1][1] = 1;	R[1][2] = 0;
				R[2][0] = 0;	R[2][1] = 0;    R[2][2] = 1;
				break;
			}
			k[0] = rpy[0] / Q;
			k[1] = rpy[1] / Q;
			k[2] = rpy[2] / Q;
			sx = sin(Q); cx = cos(Q); v = 1 - cx;
			R[0][0] = k[0] * k[0] * v + cx;			R[0][1] = k[0] * k[1] * v - k[2] * sx;	R[0][2] = k[0] * k[2] * v + k[1] * sx;
			R[1][0] = k[0] * k[1] * v + k[2] * sx;	R[1][1] = k[1] * k[1] * v + cx;			R[1][2] = k[1] * k[2] * v - k[0] * sx;
			R[2][0] = k[0] * k[2] * v - k[1] * sx;	R[2][1] = k[1] * k[2] * v + k[0] * sx;	R[2][2] = k[2] * k[2] * v + cx;
			break;
		case 4://��λ��Ԫ��
			R[0][0] = 1 - 2 * rpy[1] * rpy[1] - 2 * rpy[2] * rpy[2]; R[0][1] = 2 * (rpy[0] * rpy[1] - rpy[2] * rpy[3]); R[0][2] = 2 * (rpy[0] * rpy[2] + rpy[1] * rpy[3]);
			R[1][0] = 2 * (rpy[0] * rpy[1] + rpy[2] * rpy[3]); R[1][1] = 1 - 2 * rpy[0] * rpy[0] - 2 * rpy[2] * rpy[2]; R[1][2] = 2 * (rpy[1] * rpy[2] - rpy[0] * rpy[3]);
			R[2][0] = 2 * (rpy[0] * rpy[2] - rpy[1] * rpy[3]); R[2][1] = 2 * (rpy[1] * rpy[2] + rpy[0] * rpy[3]); R[2][2] = 1 - 2 * rpy[0] * rpy[0] - 2 * rpy[1] * rpy[1];
			break;
		case 5: //matlab �����˹�����
			R[0][0] = 1 - 2 * rpy[1] * rpy[1] - 2 * rpy[2] * rpy[2]; R[0][1] = 2 * (rpy[0] * rpy[1] - rpy[2] * rpy[3]); R[0][2] = 2 * (rpy[0] * rpy[2] + rpy[1] * rpy[3]);
			R[1][0] = 2 * (rpy[0] * rpy[1] + rpy[2] * rpy[3]); R[1][1] = 1 - 2 * rpy[0] * rpy[0] - 2 * rpy[2] * rpy[2]; R[1][2] = 2 * (rpy[1] * rpy[2] - rpy[0] * rpy[3]);
			R[2][0] = 2 * (rpy[0] * rpy[2] - rpy[1] * rpy[3]); R[2][1] = 2 * (rpy[1] * rpy[2] + rpy[0] * rpy[3]); R[2][2] = 1 - 2 * rpy[0] * rpy[0] - 2 * rpy[1] * rpy[1];
			break;
		default:
			break;
		}
	}

	void static Rad2Angle(double data[],int size)
	{
		for (int i = 0; i < size; i++)
			data[i] = data[i] * 180 / (pi);
	}

};
