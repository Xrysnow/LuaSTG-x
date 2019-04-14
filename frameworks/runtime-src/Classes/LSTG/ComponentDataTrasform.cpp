#include "ComponentDataTrasform.h"

bool lstg::ComponentDataTrasform2D::init()
{
	reset();
	return true;
}

void lstg::ComponentDataTrasform2D::reset()
{
	is3D = false;
	rotAxis = cocos2d::Vec3(0, 0, 1);
	vz = dz = lastz = 0;
	zscale = 1;
}

void lstg::ComponentDataTrasform2D::update()
{
	if(is3D)
	{
		vz += az;
		z += vz;
		dz = z - lastz;
		lastz = z;
		//if (navi && (dx != 0 || dy != 0 || dz != 0))
		//{
		//}
	}
}
