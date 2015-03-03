#pragma once
#include"yVertexArray.h"
#include<random>
using namespace std;
namespace yewbow
{
	class TriangleShader
	{
	public:
		TriangleShader(){}
		void SetTriangle(const Point3D& ori, 
			const Vertex& p1, const Vertex& p2, const Vertex& p3);
		bool ComputeTexcoor(const VecR3D& dir, Vertex& output);
	private:

		Vertex _p1;
		Vertex _p2;
		Vertex _p3;
		Point3D _ori;

		VecR3D _p1p2Xp1p3;
		VecR3D _p2p1Xp2p3;
		VecR3D _p1p2;
		VecR3D _p1p3;
		VecR3D _p2p3;
		tReal _above;

	};

}