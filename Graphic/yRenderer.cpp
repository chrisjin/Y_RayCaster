#include"yRenderer.h"
#include"yMath.h"
#include<memory.h>
using namespace yewbow;
using namespace QuickCG;
Renderer::Renderer()
{
	_vertexbuffer = 0;
	_vertexbuffer_ori = 0;
	_modelmat = Identity();
	_viewmat = Identity();
	_modelmat = Identity();
	_projectmat = Identity();


	_distance = 1;
	_origin = Point3D(0, 0, 0);
	_width = 800;
	_height = 600;
	_xstep = 2/(tReal)_width;
	_ystep = 2 / (tReal)_width;
	_buffer = new tI32[_width * _height];
	for (int i = 0; i < _width*_height; i++)
	{
		_buffer[i] = 0xA0A0A0;
	}
	_zbuffer = new tReal[_width * _height];
	for (int i = 0; i < _width * _height; i++)
	{
		_zbuffer[i] = 10000000000.0;
	}

	unsigned long tw, th, error = 0;
	
	
	loadImage(_texture, tw, th, "pics/eagle.png");

	_is_vertexbufferdirty = 1;
	//CreateVertexBuffer(eVertexType::XYZTTEX, 3);

	//Vertex* varr = (Vertex*)_vertexbuffer->GetBuffer();
	//varr[0].pos = Point3D(-1, -1, 5);
	//varr[0].texcoor = Point2D(0, 0);
	//varr[0].color = ColorRGBA(0,255,0);
	//varr[1].pos = Point3D(1, -1, 5);
	//varr[1].texcoor = Point2D(1, 0);
	//varr[1].color = ColorRGBA(255, 0, 0);
	//varr[2].pos = Point3D(0, 6, 20);
	//varr[2].texcoor = Point2D(0.5, 1);
	//varr[2].color = ColorRGBA(0, 255, 255);
	//_shader.SetTriangle(Point3D(0,0,0),varr[0], varr[1], varr[2]);
}
void Renderer::UpdateVertexBuffer()
{
	if (_is_vertexbufferdirty)
	{
		Vertex* varr =(Vertex*) _vertexbuffer->GetBuffer();
		Vertex* varr_ori =(Vertex*) _vertexbuffer_ori->GetBuffer();
		for (int i = 0; i < _vertexbuffer->GetSize(); i++)
		{
			varr[i].pos = varr_ori[i].pos*_modelmat*_viewmat;
			varr[i].color = varr_ori[i].color;
			varr[i].texcoor = varr_ori[i].texcoor;
		}
		_is_vertexbufferdirty = false;
	}
}
VertexArray* Renderer::CreateVertexBuffer(eVertexType type, int num)
{
	if (_vertexbuffer)
		VertexArray::Delete(_vertexbuffer);
	if (_vertexbuffer_ori)
		VertexArray::Delete(_vertexbuffer_ori);
	_vertexbuffer = VertexArray::New(type, num);
	_vertexbuffer_ori = VertexArray::New(type, num);
	_is_vertexbufferdirty = true;
	return _vertexbuffer_ori;
}

void Renderer::SetViewTransform(MatR4x4& v)
{
	_viewmat = v;
	_is_vertexbufferdirty = 1;
}
void Renderer::SetProjectTransform(MatR4x4& v)
{
	_projectmat = v;
}
void Renderer::SetModelTransform(MatR4x4& m)
{
	_modelmat = m;
	_is_vertexbufferdirty = 1;
}
void Renderer::Update()
{
	//DrawTriangleList(TRIANGLELIST,3);
	////tByte* tmp = (tByte*)_buffer;
	////for (int i = 0; i < 300; i++)
	////{
	////	_buffer[i] = 0xffffff;
	////	
	////}
	//Vertex* varr = (Vertex*)_vertexbuffer->GetBuffer();
	//int size = _vertexbuffer->GetSize();
	//tReal x = -(tReal)_width*_xstep/2.0;
	//tReal y = -(tReal)_height*_ystep / 2.0;
	//for (int i = 0; i < _height; i++)
	//{
	//	for (int j = 0; j < _width; j++)
	//	{

	//		VecR3D dir = {x,y,this->_distance};
	//		tReal m=0, n=0;
	//		bool flag=0;// = TriangleIntersection(varr[0].pos, varr[1].pos, varr[2].pos,
	//			//dir,m,n);

	//		Vertex test;
	//		bool aflag;
	//		aflag= _shader.ComputeTexcoor(dir, test);
	//		Uint32 color = 0xA0A0A0;
	//		if (aflag)
	//		{
	//			//if (aflag&&flag)
	//			int xcoor = test.texcoor.x * 64;
	//			int ycoor = test.texcoor.y * 64;
	//			color = _texture[ycoor * 64 + xcoor];
	//			//color = test.color.rgba;
	//		}
	//		//else if (flag)
	//		//{
	//		//	//color = 0x00ff00;//_texture[test.y * 64 + test.x];
	//		//	tReal texx = m*(varr[0].texcoor.x - varr[2].texcoor.x) 
	//		//		+ n*(varr[1].texcoor.x - varr[2].texcoor.x);
	//		//	tReal texy = m*(varr[0].texcoor.y - varr[2].texcoor.y)
	//		//		+ n*(varr[1].texcoor.y - varr[2].texcoor.y);
	//		//	texx += varr[2].texcoor.x;
	//		//	texy += varr[2].texcoor.y;
	//		//	if (texx <= 1 && texx >= 0 && texy <= 1 && texy >= 0)
	//		//	{

	//		//		int xcoor = texx * 64;
	//		//		int ycoor = texy * 64;
	//		//		color = _texture[ycoor * 64 + xcoor];
	//		//		//color = 0x00ff00;
	//		//	}
	//		//	//else if (texy < 0)
	//		//	//{
	//		//	//	while (texy < 0)
	//		//	//	{
	//		//	//		texy += 1.0;
	//		//	//	}
	//		//	//	int xcoor = texx * 64;
	//		//	//	int ycoor = texy * 64;
	//		//	//	color = _texture[ycoor * 64 + xcoor];
	//		//	//}
	//		//}

	//		//memcpy(&(tmp[(i*_width + j) * 3 * sizeof(tByte)]),&color,4);
	//		this->_buffer[j*_height + i] = color;

	//		x += _xstep;
	//	}
	//	x = -(tReal)_width*_xstep / 2.0;
	//	y += this->_ystep;
	//}
}

void Renderer::DrawPrimitive(ePrimitiveType type, int vertexnum)
{
	UpdateVertexBuffer();
	switch (type)
	{
	case ePrimitiveType::TRIANGLELIST:
		DrawTriangleList(vertexnum);
		break;
	case ePrimitiveType::RECTANGLELIST:
		DrawRectangleList(vertexnum);
	default:
		break;

	}
}
void Renderer::DrawShaders(vector<TriangleShader*>& shaders)
{
	tReal x = -(tReal)_width*_xstep / 2.0;
	tReal y = -(tReal)_height*_ystep / 2.0;
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{

			VecR3D dir = { x, y, this->_distance };

			for (int k = 0; k < shaders.size(); k++)
			{
				Vertex test;
				bool aflag;
				aflag = shaders[k]->ComputeTexcoor(dir, test);
				if (aflag)
				{
					int xcoor = test.texcoor.x * 64;
					int ycoor = test.texcoor.y * 64;
					tReal& zvalue = this->_zbuffer[j*_height + i];
					if (test.pos.z <= zvalue && test.pos.z >= _distance)
					{
						Uint32 color = _texture[ycoor * 64 + xcoor];
						zvalue = test.pos.z;
						this->_buffer[j*_height + i] = color;
					}
				}
			}

			
			x += _xstep;
		}
		x = -(tReal)_width*_xstep / 2.0;
		y += this->_ystep;
	}
}
void Renderer::DrawTriangleList(int vertexnum)
{
	int numoftriangle = vertexnum / 3;
	vector<TriangleShader*> shaders;
	Vertex* vertex = (Vertex*)_vertexbuffer->GetBuffer();
	for (int i = 0; i < numoftriangle; i++)
	{
		TriangleShader* shader = new TriangleShader();
		shader->SetTriangle(_origin,vertex[3 * i], vertex[3 * i + 1], vertex[3*i+2]);
		shaders.push_back(shader);
	}
	DrawShaders(shaders);
	for (int i = 0; i < shaders.size(); i++)
	{
		delete shaders[i];
	}
}

void Renderer::DrawRectangleList(int vertexnum)
{
	int numofrect = vertexnum / 4;
	vector<TriangleShader*> shaders;
	Vertex* vertex = (Vertex*)_vertexbuffer->GetBuffer();
	for (int i = 0; i < numofrect; i++)
	{
		TriangleShader* shader1 = new TriangleShader();
		TriangleShader* shader2 = new TriangleShader();
		shader1->SetTriangle(_origin, vertex[4 * i], vertex[4 * i + 1], vertex[4*i+3]);
		shader2->SetTriangle(_origin, vertex[4 * i+1], vertex[4 * i + 2], vertex[4 * i + 3]);
		shaders.push_back(shader1);
		shaders.push_back(shader2);
	}
	DrawShaders(shaders);
	for (int i = 0; i < shaders.size(); i++)
	{
		delete shaders[i];
	}
}