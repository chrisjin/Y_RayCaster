#include"yMath.h"
#include<math.h>
#include<stdio.h>
#include<random>
using namespace std;
VecR4D operator*(VecR4D& v, MatR4x4& m)
{
	VecR4D ret;
	ret.x = v.x*m.x11 + v.y*m.x21 + v.z*m.x31 + v.t*m.x41;
	ret.y = v.x*m.x12 + v.y*m.x22 + v.z*m.x32 + v.t*m.x42;
	ret.z = v.x*m.x13 + v.y*m.x23 + v.z*m.x33 + v.t*m.x43;
	ret.t = v.x*m.x14 + v.y*m.x24 + v.z*m.x34 + v.t*m.x44;
	return ret;
}
VecR3D operator*(VecR3D& v, MatR4x4& m)
{
	VecR3D ret;
	ret.x = v.x*m.x11 + v.y*m.x21 + v.z*m.x31 + 1*m.x41;
	ret.y = v.x*m.x12 + v.y*m.x22 + v.z*m.x32 + 1*m.x42;
	ret.z = v.x*m.x13 + v.y*m.x23 + v.z*m.x33 + 1*m.x43;
	tReal t = v.x*m.x14 + v.y*m.x24 + v.z*m.x34 + 1*m.x44;
	if (fabs(t) >= 0.000001)
	{
		ret.x /= t;
		ret.y /= t;
		ret.z /= t;
	}
	return ret;
}


VecR3D operator+(const VecR3D& v1, const VecR3D& v2)
{
	VecR3D ret = { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
	return ret;
}
VecR3D operator-(const VecR3D& v1, const VecR3D& v2)
{
	VecR3D ret = { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
	return ret;
}
VecR3D operator-(const VecR3D& v1)
{
	VecR3D ret = { -v1.x, -v1.y, -v1.z };
	return ret;
}
VecR3D operator*(const VecR3D& v1, tReal a)
{
	VecR3D ret = { a*v1.x, a*v1.y, a*v1.z };
	return ret;
}


VecR2D operator+(const VecR2D& v1, const VecR2D& v2)
{
	VecR2D ret = { v1.x + v2.x, v1.y + v2.y};
	return ret;
}
VecR2D operator-(const VecR2D& v1, const VecR2D& v2)
{
	VecR2D ret = { v1.x - v2.x, v1.y - v2.y};
	return ret;
}
VecR2D operator-(const VecR2D& v1)
{
	VecR2D ret = { -v1.x, -v1.y};
	return ret;
}
VecR2D operator*(const VecR2D& v1, tReal a)
{
	VecR2D ret = { a*v1.x, a*v1.y};
	return ret;
}


ColorRGBA operator+(const ColorRGBA& v1, const ColorRGBA& v2)
{
	ColorRGBA ret(v1.c1 + v2.c1, v1.c2 + v2.c2, v1.c3 + v2.c3, v1.c4 + v2.c4);
	return ret;
}
ColorRGBA operator-(const ColorRGBA& v1, const ColorRGBA& v2)
{
	ColorRGBA ret(v1.c1 - v2.c1, v1.c2 - v2.c2, v1.c3 - v2.c3, v1.c4 - v2.c4);
	return ret;
}
ColorRGBA operator*(const ColorRGBA& v1, tReal a)
{
	ColorRGBA ret(v1.c1*a, v1.c2*a, v1.c3*a, v1.c4*a);
	return ret;
}
namespace yewbow
{
	VecR3D Normalize(const VecR3D& normalize)
	{
		tReal below = sqrt(normalize.x*normalize.x +
			normalize.y*normalize.y + normalize.z*normalize.z);
		return VecR3D(normalize.x / below, normalize.y / below, normalize.z / below);
	}
	bool TriangleIntersection(const Triangle& tri, const Ray& ray, VecR3D& output)
	{
		return 1;
	}


	tReal  DotProduct(const VecR3D& v1, const VecR3D& v2)
	{
		return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
	}

	MatR4x4 Identity()
	{
		MatR4x4 mat = { 1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1 };
		return mat;
	}


	bool TriangleIntersection(const Point3D& p1, const Point3D& p2, const Point3D& p3,
		const VecR3D& dir,
		tReal& m, tReal& n)
	{
		tReal a1a3 = p1.x - p3.x;
		tReal a2a3 = p2.x - p3.x;
		tReal b1b3 = p1.y - p3.y;
		tReal b2b3 = p2.y - p3.y;
		tReal c1c3 = p1.z - p3.z;
		tReal c2c3 = p2.z - p3.z;

		tReal below = -(a1a3*b2b3*dir.z
			+ a2a3*c1c3*dir.y
			+ b1b3*c2c3*dir.x
			- c1c3*b2b3*dir.x
			- b1b3*a2a3*dir.z
			- a1a3*c2c3*dir.y);
		if (fabs(below) <= 0.000001)
			return 0;
		tReal root1above = p3.x*b2b3*dir.z
			+ a2a3*p3.z*dir.y
			+ p3.y*c2c3*dir.x
			- b2b3*p3.z*dir.x
			- p3.x*c2c3*dir.y
			- a2a3*p3.y*dir.z;
		tReal root2above = a1a3*p3.y*dir.z
			+ p3.x*c1c3*dir.y
			+ b1b3*p3.z*dir.x
			- p3.y*c1c3*dir.x
			- p3.x*b1b3*dir.z
			- a1a3*p3.z*dir.y;
		tReal root1 = root1above / below;
		tReal root2 = root2above / below;
		if (root1 < 0 || root2 < 0 || root1>1 || root2>1)
			return 0;
		m = root1;
		n = root2;
		return 1;
	}

	VecR3D CrossProduct(const VecR3D& v1, const VecR3D& v2)
	{
		VecR3D ret = { v1.y*v2.z - v1.z*v2.y,
			v1.z*v2.x - v1.x*v2.z,
			v1.x*v2.y - v1.y*v2.x };

		return ret;
	}
	std::random_device rd;
	std::mt19937_64 mt(rd());
	std::uniform_real_distribution<double> distribution(0, 3.1415926 / 300.0);


	tReal UniformRandomDistribution::GetValue()
	{
		return distribution(mt);
	}
}