#include"ymath.h"
#include<stdio.h>
#include"quickcg.h"
#include"yRenderer.h"
#include"yTransform.h"
using namespace QuickCG;
using namespace yewbow;

#define screenWidth (400)
#define screenHeight (300)
Uint32 buffer[screenWidth][screenHeight];
int main(int /*argc*/, char */*argv*/[])
{
	
	Renderer rdr;
	rdr.SetViewTransform(LookAt(Point3D(0,0,1.6),Point3D(0,0,3),Point3D(0,1,0)));
	VertexArray* vbuffer;
	Vertex* varr;
	vbuffer = rdr.CreateVertexBuffer(eVertexType::XYZTTEX,6);
	varr = (Vertex*)vbuffer->GetBuffer();
	varr[0].pos = Point3D(-1, -1, 3);
	varr[0].texcoor = Point2D(0, 0);
	varr[0].color = ColorRGBA(0, 255, 0);

	varr[1].pos = Point3D(1, -1, 3);
	varr[1].texcoor = Point2D(1, 0);
	varr[1].color = ColorRGBA(255, 0, 0);
	
	varr[2].pos = Point3D(-1, 1, 3);
	varr[2].texcoor = Point2D(0, 1);
	varr[2].color = ColorRGBA(0, 255, 255);

	varr[3].pos = Point3D(1, -1, 3);
	varr[3].texcoor = Point2D(1, 0);
	varr[3].color = ColorRGBA(255, 0, 0);

	varr[4].pos = Point3D(-1, 1, 3);
	varr[4].texcoor = Point2D(0, 1);
	varr[4].color = ColorRGBA(0, 255, 255);


	varr[5].pos = Point3D(1, 1, 3);
	varr[5].texcoor = Point2D(1, 1);
	varr[5].color = ColorRGBA(0, 255, 255);
	rdr.DrawPrimitive(TRIANGLELIST, 6);

	vbuffer = rdr.CreateVertexBuffer(eVertexType::XYZTTEX, 4);
	varr = (Vertex*)vbuffer->GetBuffer();
	varr[0].pos = Point3D(-1, -1, 2);
	varr[0].texcoor = Point2D(0, 0);
	varr[0].color = ColorRGBA(0, 255, 0);

	varr[1].pos = Point3D(1, -1, 2);
	varr[1].texcoor = Point2D(1, 0);
	varr[1].color = ColorRGBA(255, 0, 0);

	varr[2].pos = Point3D(1, 5, 9);
	varr[2].texcoor = Point2D(1, 1);
	varr[2].color = ColorRGBA(0, 255, 255);

	varr[3].pos = Point3D(-1,5, 9);
	varr[3].texcoor = Point2D(0, 1);
	varr[3].color = ColorRGBA(255, 0, 0);
	rdr.DrawPrimitive(RECTANGLELIST,4);


	screen(rdr.GetWidth(), rdr.GetHeight(), 0, "Raycaster");
	while (!done())
	{
		drawBuffer((Uint32*)rdr.GetBuffer());

		redraw();
	}


	VecR4D v = { 1, 2, 3, 4 };
	MatR4x4 mat = {  1, 0, 3, 4, 
					0, 2, 0, 0, 
					0, 0, 1, 0, 
					3, 2, 0, 1 };
	VecR4D r = v*mat;
	Point3D p1 = {-1,-1,5};
	Point3D p2 = { 1, -1, 5 };
	Point3D p3 = { 0, 1, 5 };
	VecR3D  d = { 0, 0, 1 };
	tReal root1, root2;
	int flag=TriangleIntersection(p1,p2,p3,d,root1,root2);
	
	
	printf("__%f\n", CrossProduct({ 3, 4, 5 }, { 2, 0, 0 }).z);
	
	for (int i = 0; i < 4; i++)
	{
		printf("%f ", r.c[i]);
	}
	getchar();

	return 0;
}