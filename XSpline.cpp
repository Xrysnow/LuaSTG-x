#include "XSpline.h"

using namespace cc;
using namespace xmath;
using namespace xmath::spline;

//13 *op, 11 +op, slower
/*float spline::Cardinal(float t, float p1, float p2, float p3, float p4, float alpha)
{
	const auto t2 = t * t;
	const auto t3 = t2 * t;
	const auto m0 = alpha * (p3 - p1);
	const auto m1 = alpha * (p4 - p2);
	return ((2 * t3 - 3 * t2 + 1)*p2) +
		((t3 - 2 * t2 + t)*m0) +
		(t3 - t2)*m1 +
		((-2 * t3 + 3 * t2)*p3);
}*/

//9 *op, 11 +op

float spline::Cardinal(float t, float p1, float p2, float p3, float p4, float alpha)
{
	const auto t2 = t * t;
	const auto t3 = t2 * t;
	const auto m0 = alpha * (p3 - p1);
	const auto m0_add_m1 = m0 + alpha * (p4 - p2);
	const auto c2 = 3 * (p3 - p2) - m0_add_m1 - m0;
	const auto c3 = -2 * (p3 - p2) + m0_add_m1;
	return c3 * t3 + c2 * t2 + m0 * t + p2;
}

float spline::CatmullRom(float t, float p1, float p2, float p3, float p4)
{
	return Cardinal(t, p1, p2, p3, p4, .5f);
}

inline float t_next(float ti, const Vec2& pi, const Vec2& pj, float alpha = 0.5) {
	const auto dx = pj.x - pi.x;
	const auto dy = pj.y - pi.y;
	return std::pow(std::sqrt(dx*dx + dy * dy), alpha) + ti;
}
Vec2 spline::CentripetalCatmullRom(float t, const Vec2& p1, const Vec2& p2, const Vec2& p3, const Vec2& p4)
{
	constexpr auto t0 = 0.f;
	const auto t1 = t_next(t0, p1, p2);
	const auto t2 = t_next(t1, p2, p3);
	const auto t3 = t_next(t2, p3, p4);

	t = t1 * (1.f - t) + t2 * t;

	const auto t01 = (t - t0) / (t1 - t0);
	const auto t12 = (t - t1) / (t2 - t1);
	const auto t23 = (t - t2) / (t3 - t2);
	const auto t02 = (t - t0) / (t2 - t0);
	const auto t13 = (t - t1) / (t3 - t1);

	const auto A1_x = (1 - t01)*p1.x + t01 * p2.x;
	const auto A2_x = (1 - t12)*p2.x + t12 * p3.x;
	const auto A3_x = (1 - t23)*p3.x + t23 * p4.x;
	const auto B1_x = (1 - t02)*A1_x + t02 * A2_x;
	const auto B2_x = (1 - t13)*A2_x + t13 * A3_x;

	const auto A1_y = (1 - t01)*p1.y + t01 * p2.y;
	const auto A2_y = (1 - t12)*p2.y + t12 * p3.y;
	const auto A3_y = (1 - t23)*p3.y + t23 * p4.y;
	const auto B1_y = (1 - t02)*A1_y + t02 * A2_y;
	const auto B2_y = (1 - t13)*A2_y + t13 * A3_y;

	return {
		(1 - t12)*B1_x + t12 * B2_x,
		(1 - t12)*B1_y + t12 * B2_y};
}
