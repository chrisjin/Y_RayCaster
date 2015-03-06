#include"yBasic.h"

namespace yewbow
{
	MatR4x4 LookAt(const Point3D& pos,const VecR3D& target,const VecR3D& upvector);
	MatR4x4 Translate(const VecR3D& dir);
	MatR4x4 RotateX(tReal angle);
	MatR4x4 RotateY(tReal angle);
	MatR4x4 RotateZ(tReal angle);
} 