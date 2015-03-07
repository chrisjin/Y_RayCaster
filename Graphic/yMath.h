#pragma once
#include"yBasic.h"
#include"yVertexArray.h"

using namespace yewbow;
MatR4x4 operator*(const MatR4x4& mat1, const MatR4x4& mat2);
VecR4D operator*(VecR4D& v, MatR4x4& m);
VecR3D operator*(VecR3D& v, MatR4x4& m);
VecR3D operator+(const VecR3D& v1, const VecR3D& v2);
VecR3D operator-(const VecR3D& v1, const VecR3D& v2);
VecR3D operator-(const VecR3D& v1);
VecR3D operator*(const VecR3D& v1, tReal a);

VecR2D operator+(const VecR2D& v1, const VecR2D& v2);
VecR2D operator-(const VecR2D& v1, const VecR2D& v2);
VecR2D operator-(const VecR2D& v1);
VecR2D operator*(const VecR2D& v1, tReal a);

ColorRGBA operator+(const ColorRGBA& v1, const ColorRGBA& v2);
ColorRGBA operator-(const ColorRGBA& v1, const ColorRGBA& v2);
ColorRGBA operator*(const ColorRGBA& v1, tReal a);
namespace yewbow
{
	VecR3D Normalize(const VecR3D& normalize);
	tReal  Length(const VecR3D& vec);
	MatR4x4 Identity();


	bool TriangleIntersection(const Point3D& p1, const Point3D& p2, const Point3D& p3,
		const VecR3D& dir,
		tReal& m, tReal& n);

	VecR3D CrossProduct(const VecR3D& v1, const VecR3D& v2);
	tReal  DotProduct(const VecR3D& v1, const VecR3D& v2);


	//bool TriangleIntersection(const Triangle& tri, const Ray& ray, VecR3D& output);

	class UniformRandomDistribution
	{
	public:
		static tReal GetValue();
	private:

	};
}