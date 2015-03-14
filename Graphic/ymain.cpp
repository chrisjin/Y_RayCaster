#include"ymath.h"
#include<stdio.h>
#include"quickcg.h"
#include"yRenderer.h"
#include"yTransform.h"
using namespace QuickCG;
using namespace yewbow;
#define OFFSETX (0)
#define OFFSETY (0)
#define OFFSETZ (0)
#define screenWidth (400)
#define screenHeight (300)
Uint32 buffer[screenWidth][screenHeight];

int main(int /*argc*/, char */*argv*/[])
{
	
	Renderer rdr;
	rdr.SetViewTransform(LookAt(Point3D(0,0, 0), Point3D(0,0,1), Point3D(0,1, 0)));
	//rdr.SetModelTransform(Translate(VecR3D(0,0,0)));
	VertexArray* vbuffer;
	Vertex* varr;
	//vbuffer = rdr.CreateVertexBuffer(eVertexType::XYZTTEX,6);
	//varr = (Vertex*)vbuffer->GetBuffer();
	//varr[0].pos = Point3D(-1, -1, 3);
	//varr[0].texcoor = Point2D(0, 0);
	//varr[0].color = ColorRGBA(0, 255, 0);

	//varr[1].pos = Point3D(1, -1, 3);
	//varr[1].texcoor = Point2D(1, 0);
	//varr[1].color = ColorRGBA(255, 0, 0);
	//
	//varr[2].pos = Point3D(-1, 6, 3);
	//varr[2].texcoor = Point2D(0, 1);
	//varr[2].color = ColorRGBA(0, 255, 255);

	//varr[3].pos = Point3D(1, -1, 3);
	//varr[3].texcoor = Point2D(1, 0);
	//varr[3].color = ColorRGBA(255, 0, 0);

	//varr[4].pos = Point3D(-1, 1, 3);
	//varr[4].texcoor = Point2D(0, 1);
	//varr[4].color = ColorRGBA(0, 255, 255);


	//varr[5].pos = Point3D(1, 1, 3);
	//varr[5].texcoor = Point2D(1, 1);
	//varr[5].color = ColorRGBA(0, 255, 255);
	////rdr.DrawPrimitive(TRIANGLELIST, 6);


	//rdr.SetModelTransform(Translate(VecR3D(0, 0, 3)));
	vbuffer = rdr.CreateVertexBuffer(eVertexType::XYZTTEX, 24);
	varr = (Vertex*)vbuffer->GetBuffer();

	varr[0].pos = Point3D(-1 + OFFSETX, 1 + OFFSETY, -1 + OFFSETZ);
	varr[0].texcoor = Point2D(0, 0);
	varr[0].color = ColorRGBA(0, 255, 0);

	varr[1].pos = Point3D(1 + OFFSETX, 1 + OFFSETY, -1 + OFFSETZ);
	varr[1].texcoor = Point2D(1, 0);
	varr[1].color = ColorRGBA(255, 0, 0);

	varr[2].pos = Point3D(1 + OFFSETX, 1 + OFFSETY, 1 + OFFSETZ);
	varr[2].texcoor = Point2D(1, 1);
	varr[2].color = ColorRGBA(0, 255, 255);

	varr[3].pos = Point3D(-1 + OFFSETX, 1 + OFFSETY, 1 + OFFSETZ);
	varr[3].texcoor = Point2D(0, 1);
	varr[3].color = ColorRGBA(255, 0, 0);

	varr[0].normal = varr[1].normal
		= varr[2].normal = varr[3].normal = VecR3D(0,1,0);
	/////////////////////////////////////////////////
	varr[4].pos = Point3D(-1 + OFFSETX, -1 + OFFSETY, -1 + OFFSETZ);
	varr[4].texcoor = Point2D(0, 0);
	varr[4].color = ColorRGBA(0, 255, 0);

	varr[5].pos = Point3D(1 + OFFSETX, -1 + OFFSETY, -1 + OFFSETZ);
	varr[5].texcoor = Point2D(1, 0);
	varr[5].color = ColorRGBA(255, 0, 0);

	varr[6].pos = Point3D(1 + OFFSETX, -1 + OFFSETY, 1 + OFFSETZ);
	varr[6].texcoor = Point2D(1, 1);
	varr[6].color = ColorRGBA(0, 255, 255);

	varr[7].pos = Point3D(-1 + OFFSETX, -1 + OFFSETY, 1 + OFFSETZ);
	varr[7].texcoor = Point2D(0, 1);
	varr[7].color = ColorRGBA(255, 0, 0);

	varr[4].normal = varr[5].normal
		= varr[6].normal = varr[7].normal = VecR3D(0, -1, 0);
	/////////////////////////////////////////////////
	varr[8].pos = Point3D(-1 + OFFSETX, 1 + OFFSETY, -1 + OFFSETZ);
	varr[8].texcoor = Point2D(0, 0);
	varr[8].color = ColorRGBA(0, 255, 0);

	varr[9].pos = Point3D(-1 + OFFSETX, -1 + OFFSETY, -1 + OFFSETZ);
	varr[9].texcoor = Point2D(1, 0);
	varr[9].color = ColorRGBA(255, 0, 0);

	varr[10].pos = Point3D(-1 + OFFSETX, -1 + OFFSETY, 1 + OFFSETZ);
	varr[10].texcoor = Point2D(1, 1);
	varr[10].color = ColorRGBA(0, 255, 255);

	varr[11].pos = Point3D(-1 + OFFSETX, 1 + OFFSETY, 1 + OFFSETZ);
	varr[11].texcoor = Point2D(0, 1);
	varr[11].color = ColorRGBA(255, 0, 0);

	varr[8].normal = varr[9].normal
		= varr[10].normal = varr[11].normal = VecR3D(-1, 0, 0);
	/////////////////////////////////////////////////
	varr[12].pos = Point3D(1 + OFFSETX, 1 + OFFSETY, -1 + OFFSETZ);
	varr[12].texcoor = Point2D(0, 0);
	varr[12].color = ColorRGBA(0, 255, 0);

	varr[13].pos = Point3D(1 + OFFSETX, -1 + OFFSETY, -1 + OFFSETZ);
	varr[13].texcoor = Point2D(1, 0);
	varr[13].color = ColorRGBA(255, 0, 0);

	varr[14].pos = Point3D(1 + OFFSETX, -1 + OFFSETY, 1 + OFFSETZ);
	varr[14].texcoor = Point2D(1, 1);
	varr[14].color = ColorRGBA(0, 255, 255);

	varr[15].pos = Point3D(1 + OFFSETX, 1 + OFFSETY, 1 + OFFSETZ);
	varr[15].texcoor = Point2D(0, 1);
	varr[15].color = ColorRGBA(255, 0, 0);

	varr[12].normal = varr[13].normal
		= varr[14].normal = varr[15].normal = VecR3D(1, 0, 0);
	/////////////////////////////////////////////////
	varr[16].pos = Point3D(1 + OFFSETX, 1 + OFFSETY, 1 + OFFSETZ);
	varr[16].texcoor = Point2D(0, 0);
	varr[16].color = ColorRGBA(0, 255, 0);

	varr[17].pos = Point3D(-1 + OFFSETX, 1 + OFFSETY, 1 + OFFSETZ);
	varr[17].texcoor = Point2D(1, 0);
	varr[17].color = ColorRGBA(255, 0, 0);

	varr[18].pos = Point3D(-1 + OFFSETX, -1 + OFFSETY, 1 + OFFSETZ);
	varr[18].texcoor = Point2D(1, 1);
	varr[18].color = ColorRGBA(0, 255, 255);

	varr[19].pos = Point3D(1 + OFFSETX, -1 + OFFSETY, 1 + OFFSETZ);
	varr[19].texcoor = Point2D(0, 1);
	varr[19].color = ColorRGBA(255, 0, 0);

	varr[16].normal = varr[17].normal
		= varr[18].normal = varr[19].normal = VecR3D(0, 0, 1);
	/////////////////////////////////////////////////
	varr[20].pos = Point3D(-1 + OFFSETX, -1 + OFFSETY, -1 + OFFSETZ);
	varr[20].texcoor = Point2D(0, 0);
	varr[20].color = ColorRGBA(0, 255, 0);

	varr[21].pos = Point3D(1 + OFFSETX, -1 + OFFSETY, -1 + OFFSETZ);
	varr[21].texcoor = Point2D(1, 0);
	varr[21].color = ColorRGBA(255, 0, 0);

	varr[22].pos = Point3D(1 + OFFSETX, 1 + OFFSETY, -1 + OFFSETZ);
	varr[22].texcoor = Point2D(1, 1);
	varr[22].color = ColorRGBA(0, 255, 255);

	varr[23].pos = Point3D(-1 + OFFSETX, 1 + OFFSETY, -1 + OFFSETZ);
	varr[23].texcoor = Point2D(0, 1);
	varr[23].color = ColorRGBA(255, 0, 0);

	varr[20].normal = varr[21].normal
		= varr[22].normal = varr[23].normal = VecR3D(0, 0, -1);
	/////////////////////////////////////////////////
	


	screen(rdr.GetWidth(), rdr.GetHeight(), 0, "Raycaster");
	MatR4x4 tmat = Translate(VecR3D(0, 0, 7));
	rdr.SetModelTransform(tmat);
	MatR4x4 rotate = RotateX(1.0*3.1415/180.0);
	MatR4x4 trans = Translate(VecR3D(0.5, 0, 0));
	MatR4x4 trans2 = Translate(VecR3D(-0.5, 0, 0));
	tReal rangle = 1;
	while (!done())
	{
		if (keyDown(SDLK_UP))
		{
			tmat = RotateX(rangle*3.1415 / 180.0)*Translate(VecR3D(0, 0, 7));
			rangle += 10;
			rdr.Begin();
			rdr.SetModelTransform(tmat);
		}
		
		if (keyDown(SDLK_RIGHT))
		{
			tmat = RotateY(rangle*3.1415 / 180.0)*Translate(VecR3D(0, 0, 7));
			rangle -= 1;
			rdr.Begin();
			rdr.SetModelTransform(tmat);
		}
		if (keyDown(SDLK_LEFT))
		{

			tmat = RotateY(rangle*3.1415 / 180.0)*Translate(VecR3D(0, 0, 7));
			rangle += 1;
			rdr.Begin();
			rdr.SetModelTransform(tmat);
		}
		
		
		
		rdr.DrawPrimitive(RECTANGLELIST, 24);
		drawBuffer((Uint32*)rdr.GetBuffer());

		redraw();
		

	}


	VecR4D v = { 1, 2, 3, 4 };
	MatR4x4 mat = {  1, 0, 3, 4, 
					0, 2, 0, 0, 
					0, 0, 1, 0, 
					3, 2, 0, 1 };
	MatR4x4 matk = { 1, 0, 3, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1 };
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
		printf("%f ", mat.cc[0][i]);
	}
	getchar();

	return 0;
}