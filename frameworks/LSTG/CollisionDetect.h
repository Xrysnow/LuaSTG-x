#pragma once
#include "cocos2d.h"

namespace lstg
{
	int SampleBezierA1(int count, float length, float rate,
		const std::vector<cc::Vec2>& in_pos, std::vector<cc::Vec2>& out_pos, std::vector<float>& out_rot) noexcept;
}
