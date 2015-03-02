#pragma once 
#include"yBasic.h"
namespace yewbow
{
	class Camera
	{
	public:
		void SetDist2Scrn(tReal dist);
		void SetPosition(Point3D pos);
		void SetDirection(VecR3D dir);
	private:
		Point3D _position;
		VecR3D  _direction;
		tReal   _dist;

	};
	class RayIterator
	{
	public:
		RayIterator(Camera* cmr);
		bool NextRay(VecR3D& ori);
	};
	class PixelIterator
	{
	public:
		PixelIterator(Camera* pixel);
		bool NextPixel(void* &pixeladdress);
	};
}