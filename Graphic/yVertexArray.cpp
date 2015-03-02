#include"yVertexArray.h"
using namespace yewbow;
VertexArray* VertexArray::New(eVertexType type, int num)
{
	VertexArray* ret = new VertexArray;
	ret->_type = type;
	ret->_size = num;
	switch (type)
	{
	case eVertexType::XYZTCOLOR:
		ret->_vertexarr = new VertexXYZTCOLOR[num];
		break;
	case eVertexType::XYZTTEX:
		ret->_vertexarr = new Vertex[num];
		break;
	default:
		break;
	}
	return ret;
}
void VertexArray::Delete(VertexArray* pointer)
{
	switch (pointer->_type)
	{
	case eVertexType::XYZTCOLOR:
		delete[] (VertexXYZTCOLOR*)pointer->_vertexarr;
		break;
	case eVertexType::XYZTTEX:
		delete[](Vertex*)pointer->_vertexarr;
		break;
	default:
		break;
	}
	delete pointer;
}