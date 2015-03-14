#include"SurfaceShader.h"
#include"yMath.h"
#include<math.h>
#include<stdlib.h>
#define ABS(num) ((num)>0.0?(num):-(num))
using namespace yewbow;
void TriangleShader::SetTriangle(const Point3D& ori,
	const Vertex& p1, const Vertex& p2, const Vertex& p3)
{
	_p1 = p1;
	_p2 = p2;
	_p3 = p3;
	_ori = ori;
	_p1p2 = p2.pos - p1.pos;
	_p1p3 = p3.pos - p1.pos;
	_p2p3 = p3.pos - p2.pos;
	_p1p2Xp1p3 = CrossProduct(_p1p2, _p1p3);
	//_p2p1Xp2p3 = CrossProduct(p1.pos - p2.pos, p3.pos - p2.pos);

	_above = DotProduct(ori - p1.pos, _p1p2Xp1p3);

	for (int i = 0; i < 3; i++)
	{
		tReal factor = _p1p2Xp1p3.c[i];
		if (factor != 0)
		{
			_factor = 1.0/factor;
			_factor_index = i;
			break;
		}
	}
}

bool TriangleShader::ComputeTexcoor(const VecR3D& dir, Vertex& output)
{
	if (!_factor)
		return 0;
	//VecR3D noise(UniformRandomDistribution::GetValue(),
	//	UniformRandomDistribution::GetValue(), UniformRandomDistribution::GetValue());
	//VecR3D dir = _dir +noise ;
	tReal below = DotProduct(dir, _p1p2Xp1p3);
	if (*(int*)(&below) == 0x7f800000)
	{
		return 0;
	}
	//if (ABS(below) < 0.00001)
	//	return 0;
	tReal t = -_above / below;

	Point3D intersection = _ori + dir*t;
	VecR3D _p1p = intersection - _p1.pos;
	//VecR3D _p2p = intersection - _p2.pos;
	VecR3D _p1pXp1p2 = CrossProduct(_p1p, _p1p2);
	VecR3D _p1pXp1p3 = CrossProduct(_p1p, _p1p3);
	//VecR3D _p2pXp2p3 = CrossProduct(_p2p, _p2p3);

	//tReal p3sameside = DotProduct(_p1pXp1p2,_p1p2Xp1p3);
	//if (p3sameside >= 0)
	//	return 0;
	//tReal p2sameside = DotProduct(_p1pXp1p3, _p1p2Xp1p3);
	//if (p2sameside <= 0)
	//	return 0;
	//tReal p1sameside = DotProduct(_p2pXp2p3, _p2p1Xp2p3);
	//if (p1sameside <= 0)
	//	return 0;
	
	tReal alpha;
	tReal beta;
	//bool validflag = 0;
	//tReal factor;
	//for (int i = 0; i < 3; i++)
	//{
	//	factor = _p1p2Xp1p3.c[i];
	//	if (factor != 0)
	//	{
	//		beta = -_p1pXp1p2.c[i] / _factor;
	//		alpha = _p1pXp1p3.c[i] / _factor;
	//		validflag = true;
	//		break;
	//	}
	//}
	beta = -_p1pXp1p2.c[_factor_index] * _factor;
	alpha = _p1pXp1p3.c[_factor_index] * _factor;
	//TriangleIntersection(_p1.pos,_p2.pos,_p3.pos,dir,alpha,beta);
	if (beta < 0 || alpha < 0 || (beta + alpha)>1)
		return 0;
	//if (validflag == 0)
	//	return 0;

	//output = (_p2.texcoor - _p1.texcoor)*alpha
	//	+ (_p3.texcoor - _p1.texcoor)*beta;
	output.texcoor = (_p2.texcoor - _p1.texcoor)*alpha
		+ (_p3.texcoor - _p1.texcoor)*beta + _p1.texcoor;
	output.color = (_p2.color - _p1.color)*alpha
		+ (_p3.color - _p1.color)*beta + _p1.color;
	output.pos = intersection;
	output.normal = (_p2.normal - _p1.normal)*alpha
		+ (_p3.normal - _p1.normal)*beta + _p1.normal;
	return 1;
}