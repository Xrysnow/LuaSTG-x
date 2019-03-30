#include "ComponentDataTrasform.h"

bool lstg::ComponentDataTrasform2D::init()
{
	reset();
	return true;
}

void lstg::ComponentDataTrasform2D::reset()
{
	x = y = z = 0;
	vx = vy = 0;
	ax = ay = 0;
	dx = dy = 0;
	lastx = lasty = 0;
	rot = omega = 0;
	hscale = vscale = 1;
	anchor = cocos2d::Vec2::ANCHOR_MIDDLE;

	is3D = false;
	rotAxis = cocos2d::Vec3(0, 0, 1);
	vz = dz = lastz = 0;
	zscale = 1;
}

void lstg::ComponentDataTrasform2D::update()
{
	vx += ax;
	vy += ay;
	x += vx;
	y += vy;
	rot += omega;

	dx = x - lastx;
	dy = y - lasty;
	lastx = x;
	lasty = y;

	if(!is3D)
	{
		if (navi && (dx != 0 || dy != 0))
			rot = atan2(dy, dx);
	}
	else
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
