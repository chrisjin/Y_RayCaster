#pragma once
#include"quickcg.h"
#include"yVertexArray.h"
#include<vector>
#include"SurfaceShader.h"
using namespace std;
namespace yewbow
{
	enum ePrimitiveType
	{
		TRIANGLELIST,
		RECTANGLELIST

	};
	class Renderer
	{
	public:
		
		Renderer();
		VertexArray* CreateVertexBuffer(eVertexType type, int num);
		void SetModelTransform(MatR4x4& m);
		void SetViewTransform(MatR4x4& v);
		void SetProjectTransform(MatR4x4& v);
		tI32* GetBuffer(){ return _buffer; }
		void Update();
		tI32 GetWidth(){ return _width; }
		tI32 GetHeight(){ return _height; }
		void Begin();
		void DrawPrimitive(ePrimitiveType type,int vertexnum);
	private:
		inline void SetDirty();
		inline void RemoveDirty();
		void UpdateVertexBuffer();
		void DrawTriangleList(int vertexnum);
		void DrawRectangleList(int vertexnum);
		void DrawShaders(vector<TriangleShader*>& shaders);
		VertexArray* _vertexbuffer;
		VertexArray* _vertexbuffer_ori;
		volatile bool         _is_vertexbufferdirty;
		volatile bool         _is_screenbufferdirty;
		MatR4x4 _modelmat;
		MatR4x4 _viewmat;
		MatR4x4 _projectmat;

		tReal   _distance;
		tReal   _xstep;
		tReal   _ystep;
		tI32    _width;
		tI32    _height;

		tI32   *_buffer;
		tReal  *_zbuffer;
		std::vector<Uint32> _texture;

		TriangleShader _shader;

		Point3D _origin;

		Point3D _light_source;
		Point3D _light_source_ori;
	};

}