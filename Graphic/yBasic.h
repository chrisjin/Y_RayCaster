#pragma once
namespace yewbow
{
	typedef float tReal;
	typedef int    tI32;
	typedef unsigned int    tUI32;
	typedef unsigned char tByte;
	struct ColorRGBA
	{
		ColorRGBA(){}
		ColorRGBA(tByte rr, tByte gg, tByte bb, tByte aa = 0){ c1 = rr; c2 = gg; c3 = bb; c4 = aa; }
		ColorRGBA(tUI32 c){ rgba = c; }
		union
		{
			struct
			{
				tByte c1;
				tByte c2;
				tByte c3;
				tByte c4;
			};
			struct 
			{
				tUI32 rgba;
			};
			struct
			{
				tByte c[4];
			};
		};

	};

	template <typename T>
	struct Vec2D
	{
		Vec2D(){}
		Vec2D(T xx, T yy){ x = xx; y = yy; }
		union
		{
			struct
			{
				T x;
				T y;
			};
			struct
			{
				T x1, x2;
			};
			T c[2];
		};
	};
	template<class T>
	struct Vec3D
	{
		Vec3D(){}
		Vec3D(T xx, T yy, T zz){ x = xx; y = yy; z = zz; }
		union
		{
			struct
			{
				T x;
				T y;
				T z;
			};
			struct
			{
				T x1, x2, x3;
			};
			struct
			{
				T p1, p2, p3;
			};
			T c[3];
		};
	};
	template<class T>
	struct Mat4x4
	{
		union
		{
			struct
			{
				T x11, x12, x13, x14;
				T x21, x22, x23, x24;
				T x31, x32, x33, x34;
				T x41, x42, x43, x44;
			};
			struct
			{
				T c[16];
			};
			struct
			{
				T cc[4][4];
			};
		};


	};

	template<class T>
	struct Vec4D
	{
		union 
		{
			struct 
			{
				T x;
				T y;
				T z;
				T t;
			};
			struct
			{
				T x1, x2, x3, x4;
			};
			struct
			{
				T p1, p2, p3, p4;
			};
			struct
			{
				T c[4];
			};
		};
	};

	template<class T>
	struct Mat3x3
	{
		union
		{
			struct
			{
				T x11, x12, x13;
				T x21, x22, x23;
				T x31, x32, x33;
			};
			T c[9];
		};
	};


	typedef Mat4x4<tReal> MatR4x4;
	typedef Vec2D<tReal> VecR2D;
	typedef Vec2D<tI32>  VecI2D;
	typedef Vec4D<tReal> VecR4D;
	typedef Vec3D<tReal> VecR3D;
	typedef VecR3D Point3D;
	typedef VecR4D Point4D;
	typedef VecR2D Point2D;
	typedef Vec3D<Point3D> Triangle;
	typedef Vec4D<Point3D> Rectangle;

	struct Sphere
	{
		tReal radius;
		VecR3D origin;
	};
	struct Ray
	{
		Ray(){}
		Ray(const Point3D& o, const VecR3D& dir){ source = o; direction = dir; }
		VecR3D direction;
		Point3D source;
	};
}