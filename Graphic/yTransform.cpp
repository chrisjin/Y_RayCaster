#include"yTransform.h"
#include"yMath.h"
#include<amp_math.h>

namespace yewbow
{
	//cameraTarget - cameraPosition)
	//	xaxis = normal(cross(cameraUpVector, zaxis))
	//	yaxis = cross(zaxis, xaxis)

	//	xaxis.x           yaxis.x           zaxis.x          0
	//	xaxis.y           yaxis.y           zaxis.y          0
	//	xaxis.z           yaxis.z           zaxis.z          0
	//	- dot(xaxis, cameraPosition) - dot(yaxis, cameraPosition) - dot(zaxis, cameraPosition)  1

	MatR4x4 LookAt(const Point3D& pos, const VecR3D& target, const VecR3D& upvector)
	{
		VecR3D zaxis = Normalize(target - pos);
		VecR3D xaxis = Normalize(CrossProduct(upvector, zaxis));
		VecR3D yaxis = CrossProduct(zaxis, xaxis);
		MatR4x4 ret = { xaxis.x, yaxis.x, zaxis.x, 0,
						xaxis.y, yaxis.y, zaxis.y, 0,
						xaxis.z, yaxis.z, zaxis.z, 0,
						-DotProduct(xaxis, pos),
						-DotProduct(yaxis, pos), -DotProduct(zaxis, pos), 1 };

		return ret;

	}

	MatR4x4 Translate(const VecR3D& dir)
	{
		MatR4x4 ret = { 1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			dir.x, dir.y, dir.z, 1 };
		return ret;
	}

	MatR4x4 RotateX(tReal angle)
	{
		tReal s = sin(angle);
		tReal c = cos(angle);
		MatR4x4 ret = { 1, 0,  0, 0,
						0, c,  s, 0,
						0, -s, c, 0,
						0, 0,  0, 1 };
		return ret;
	}
	MatR4x4 RotateY(tReal angle)
	{
		tReal s = sin(angle);
		tReal c = cos(angle);
		MatR4x4 ret = { c, 0, -s, 0,
						0, 1, 0, 0,
						s, 0, c, 0,
						0, 0, 0, 1 };
		return ret;
	}
	MatR4x4 RotateZ(tReal angle)
	{
		tReal s = sin(angle);
		tReal c = cos(angle);
		MatR4x4 ret = { c,  s, 0, 0,
						-s, c, 0, 0,
						0,  0, 1, 0,
						0,  0, 0, 1 };
		return ret;
	}
}