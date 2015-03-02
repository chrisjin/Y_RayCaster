#include"yTransform.h"
#include"yMath.h"

namespace yewbow
{
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
}