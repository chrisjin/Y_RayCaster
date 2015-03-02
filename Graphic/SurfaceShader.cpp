#include"SurfaceShader.h"
#include"yMath.h"
#include<math.h>
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
	_p1p2Xp1p3 = CrossProduct(p2.pos - p1.pos, p3.pos - p1.pos);
	_p2p1Xp2p3 = CrossProduct(p1.pos - p2.pos, p3.pos - p2.pos);

	_above = DotProduct(ori - p1.pos, _p1p2Xp1p3);
}

bool TriangleShader::ComputeTexcoor(const VecR3D& dir, Vertex& output)
{
	tReal below = DotProduct(dir, _p1p2Xp1p3);
	if (fabs(below) < 0.00001)
		return 0;
	tReal t = -_above / below;

	Point3D intersection = _ori + dir*t;
	VecR3D _p1p = intersection - _p1.pos;
	VecR3D _p2p = intersection - _p2.pos;
	VecR3D _p1pXp1p2 = CrossProduct(_p1p, _p1p2);
	VecR3D _p1pXp1p3 = CrossProduct(_p1p, _p1p3);
	VecR3D _p2pXp2p3 = CrossProduct(_p2p, _p2p3);

	tReal p3sameside = DotProduct(_p1pXp1p2,_p1p2Xp1p3);
	if (p3sameside >= 0)
		return 0;
	tReal p2sameside = DotProduct(_p1pXp1p3, _p1p2Xp1p3);
	if (p2sameside <= 0)
		return 0;
	tReal p1sameside = DotProduct(_p2pXp2p3, _p2p1Xp2p3);
	if (p1sameside <= 0)
		return 0;
	
	tReal alpha;
	tReal beta;
	bool validflag = 0;
	tReal factor;
	for (int i = 0; i < 3; i++)
	{
		factor = _p1p2Xp1p3.c[i];
		if (factor != 0)
		{
			beta = -_p1pXp1p2.c[i] / factor;
			alpha = _p1pXp1p3.c[i] / factor;
			validflag = 1;
		}
	}
	if (validflag == 0)
		return 0;

	//output = (_p2.texcoor - _p1.texcoor)*alpha
	//	+ (_p3.texcoor - _p1.texcoor)*beta;
	output.texcoor = (_p2.texcoor - _p1.texcoor)*alpha
		+ (_p3.texcoor - _p1.texcoor)*beta + _p1.texcoor;
	output.color = (_p2.color - _p1.color)*alpha
		+ (_p3.color - _p1.color)*beta + _p1.color;
	output.pos = intersection;
	return 1;
}