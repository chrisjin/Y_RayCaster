#pragma once
#include"yBasic.h"
namespace yewbow
{
	enum eVertexType
	{
		XYZTCOLOR,
		XYZTTEX
	};
	struct VertexXYZTCOLOR
	{
		Point3D pos;
		ColorRGBA color;
	};
	struct Vertex
	{
		Vertex(){}
		Point3D pos;
		ColorRGBA color;
		Point2D texcoor;
	};
	class VertexArray
	{
	public:
		static VertexArray* New(eVertexType type,int num);
		static void Delete(VertexArray* pointer);
		eVertexType GetType(){ return _type; }
		void*       GetBuffer(){ return _vertexarr; }
		int         GetSize(){ return _size; }
	private:
		VertexArray(){}
		eVertexType _type;
		void*       _vertexarr;
		int         _size;
	};

}