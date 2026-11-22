#pragma once
#include "math/Vec2.h"

namespace xmath
{
	namespace spline
	{
		float Cardinal(float t, float p1, float p2, float p3, float p4, float alpha);
		float CatmullRom(float t, float p1, float p2, float p3, float p4);
		cc::Vec2 CentripetalCatmullRom(float t,
			const cc::Vec2& p1, const cc::Vec2& p2, const cc::Vec2&, const cc::Vec2& p4);
	}
}
