#include "XDistance.h"
#include "XMath.h"
#include "XMathInternal.h"

using namespace cc;
using namespace xmath;

float distance::Point_Triangle(const Vec2& p,
	const Vec2& A, const Vec2& B, const Vec2& C)
{
	if (detail::collinear(A, B, C))
		return float(detail::degenerateTriangleDistance(p, A, B, C));
	const auto AX = p - A;
	const auto AB = B - A;
	const auto AC = C - A;
	const auto nA2B = AB.dot(AX) < 0.f;
	const auto nA2C = AC.dot(AX) < 0.f;
	if (nA2B && nA2C)
		return AX.length();
	const auto BX = p - B;
	//const auto BA = -AB;
	const auto BC = C - B;
	const auto nB2A = AB.dot(BX) > 0.f;
	const auto nB2C = BC.dot(BX) < 0.f;
	if (nB2A && nB2C)
		return BX.length();
	const auto CX = p - C;
	//const auto CA = -AC;
	//const auto CB = -BC;
	const auto nC2A = AC.dot(CX) > 0.f;
	const auto nC2B = BC.dot(CX) > 0.f;
	if (nC2A && nC2B)
		return CX.length();
	if (!nA2B && !nB2A && AC.cross(AB)*AB.cross(AX) > 0)
	{
		const auto e = AB.getNormalized();
		return Point_Line(p, A, e.x, e.y);
	}
	if (!nC2B && !nB2C && AB.cross(BC)*BC.cross(BX) < 0)
	{
		const auto e = BC.getNormalized();
		return Point_Line(p, B, e.x, e.y);
	}
	if (!nC2A && !nA2C && BC.cross(AC)*AC.cross(CX) < 0)
	{
		const auto e = AC.getNormalized();
		return Point_Line(p, C, e.x, e.y);
	}
	return 0.f;
}

float distance::Point_Triangle2(const Vec2& p,
	const Vec2& A, const Vec2& B, const Vec2& C)
{
	if (detail::collinear(A, B, C))
		return float(detail::degenerateTriangleDistance(p, A, B, C));
	const auto E0 = A - B;
	const auto E1 = C - B;
	const auto P = p - B;
	//const auto st = equation::SolveLiner(
	//	E0.x, E1.x, P.x,
	//	E0.y, E1.y, P.y);
	//const auto s = st[0];
	//const auto t = st[1];
	const auto _den = E0.y*E1.x - E0.x*E1.y;
	const auto s = (P.y*E1.x - P.x*E1.y) / _den;
	const auto t = (P.x*E0.y - P.y*E0.x) / _den;
	if (s >= 0.0&&t >= 0.0&&s + t <= 1.0)
		return 0.f;
	const auto a = E0.dot(E0);
	const auto b = E0.dot(E1);
	const auto c = E1.dot(E1);
	const auto d = -E0.dot(P);
	const auto e = -E1.dot(P);
	float s_, t_;
	if (t > 0.0)
	{
		if (s > 0.0)//r1
		{
			const auto num = c + e - b - d;
			if (num <= 0)
				s_ = 0.f;
			else
			{
				const auto den = a - 2 * b + c;
				s_ = (num >= den) ? 1.f : num / den;
			}
			t_ = 1.f - s_;
		}
		else
		{
			if (s + t > 1.0)//r2
			{
				const auto tmp0 = b + d;
				const auto tmp1 = c + e;
				if (tmp1 > tmp0)
				{
					const auto num = tmp1 - tmp0;
					const auto den = a - 2 * b + c;
					s_ = (num >= den) ? 1.f : num / den;
					t_ = 1.f - s_;
				}
				else
				{
					s_ = 0.f;
					if (tmp1 <= 0.f)
						t_ = 1.f;
					else if (e >= 0.f)
						t_ = 0.f;
					else
						t_ = -e / c;
				}
			}
			else//r3
			{
				s_ = 0.f;
				t_ = std::max(0.f, std::min(-e / c, 1.f));
			}
		}
	}
	else
	{
		if (s < 0.0)//r4
		{
			if (d < 0.f)
			{
				t_ = 0.f;
				s_ = (-d >= a) ? 1.f : -d / a;
			}
			else
			{
				s_ = 0.f;
				if (e >= 0.f)
					t_ = 0.f;
				else if (-e >= c)
					t_ = 1.f;
				else
					t_ = -e / c;
			}
		}
		else
		{
			if (s + t < 1.0)//r5
			{
				t_ = 0.f;
				s_ = std::max(0.f, std::min(-d / a, 1.f));
			}
			else//r6
			{
				const auto tmp0 = b + e;
				const auto tmp1 = a + d;
				if (tmp1 > tmp0)
				{
					const auto num = tmp1 - tmp0;
					const auto den = a - 2 * b + c;
					t_ = (num >= den) ? 1.f : num / den;
					s_ = 1.f - t_;
				}
				else
				{
					t_ = 0.f;
					if (tmp1 <= 0.f)
						s_ = 1.f;
					else if (d >= 0.f)
						s_ = 0.f;
					else
						s_ = -d / a;
				}
			}
		}
	}
	return (s_*E0 + t_ * E1 - P).length();
}

float distance::Point_Diamond(const Vec2& p0,
	const Vec2& p1, float halfW, float halfH, float rotation)
{
	float tCos, tSin;
	SinCos(rotation, tSin, tCos);
	const Vec2 rot(tCos, tSin);
	return distance::Point_Parallelogram(p0, p1, Vec2(halfW, 0.f).rotate(rot), Vec2(0.f, halfH).rotate(rot));
}

float distance::Point_Parallelogram(const Vec2& p0,
	const Vec2& p1, const Vec2& A, const Vec2& B)
{
	const auto p = p0 - p1;
	//const auto A = halfDiagA;
	//const auto B = halfDiagB;
	//const auto C = - A;
	//const auto D = - B;
	const auto AB = B - A;
	const auto AD = -B - A;
	const auto AX = p - A;
	const auto nA2B = AB.dot(AX) < 0.f;
	const auto nA2D = AD.dot(AX) < 0.f;
	if (nA2B&&nA2D)
		return AX.length();
	//const auto BA = -AB;
	//const auto& BC = AD;
	const auto BX = p - B;
	//const auto nB2A = BA.dot(BX) < 0.f;
	const auto nB2A = AB.dot(BX) > 0.f;
	const auto nB2C = AD.dot(BX) < 0.f;
	if (nB2A&&nB2C)
		return BX.length();
	//const auto CB = -AD;
	//const auto& CD = BA;
	const auto CX = p + A;
	const auto nC2B = AD.dot(CX) > 0.f;
	//const auto nC2D = CD.dot(CX) < 0.f;
	const auto nC2D = AB.dot(CX) > 0.f;
	if (nC2B&&nC2D)
		return CX.length();
	//const auto DA = -AD;
	//const auto& DC = AB;
	const auto DX = p + B;
	//const auto nD2A = DA.dot(DX) < 0.f;
	const auto nD2A = AD.dot(DX) > 0.f;
	//const auto nD2C = DC.dot(DX) < 0.f;
	const auto nD2C = AB.dot(DX) < 0.f;
	if (nD2A&&nD2C)
		return DX.length();

	if (!nA2B && !nB2A && AB.cross(A)*AB.cross(AX) > 0.f)
	{
		const auto e = AB.getNormalized();
		return Point_Line(p, A, e.x, e.y);
	}
	if (!nC2D && !nD2C && AB.cross(A)*AB.cross(CX) < 0.f)
	{
		const auto e = AB.getNormalized();
		return Point_Line(p, -A, e.x, e.y);
	}
	if (!nA2D && !nD2A && AD.cross(A)*AD.cross(AX) > 0.f)
	{
		const auto e = AD.getNormalized();
		return Point_Line(p, A, e.x, e.y);
	}
	if (!nC2B && !nB2C && AD.cross(A)*AD.cross(BX) < 0.f)
	{
		const auto e = AD.getNormalized();
		return Point_Line(p, B, e.x, e.y);
	}
	return 0.f;
}

float distance::Point_Ellipse(const Vec2& p0,
	const Vec2& p1, float a, float b, float rotation)
{
	const auto px = double(p0.x) - p1.x;
	const auto py = double(p0.y) - p1.y;
	if (a == b)
	{
		if (a == 0.f)
			return float(std::hypot(px, py));
		const auto major = std::max(std::abs(px), std::abs(py));
		const auto minor = std::min(std::abs(px), std::abs(py));
		const auto excess = (major - a) * (major + a) + minor * minor;
		return float(std::max(excess / (std::hypot(px, py) + a), 0.0));
	}
	const auto tCos = std::cos(double(rotation));
	const auto tSin = std::sin(double(rotation));
	const auto x = std::abs(px * tCos + py * tSin);
	const auto y = std::abs(py * tCos - px * tSin);
	if (a == 0.f || b == 0.f)
		return float(std::hypot(std::max(x - a, 0.0), std::max(y - b, 0.0)));
	if (y == 0.0)
		return float(std::max(x - a, 0.0));
	if (x == 0.0)
		return float(std::max(y - b, 0.0));

	const auto a2 = double(a) * a;
	const auto b2 = double(b) * b;
	const auto ax = a * x;
	const auto by = b * y;
	const auto axExcess = a * (x - a);
	const auto byExcess = b * (y - b);
	double lo = 0.0;
	double hi = std::hypot(ax, by);
	double t = 0.0;
	while (hi - lo > 1e-8 * hi)
	{
		const auto previousWidth = hi - lo;
		const auto da = t + a2;
		const auto db = t + b2;
		const auto u = ax / da;
		const auto v = by / db;
		const auto u2 = u * u;
		const auto v2 = v * v;
		const auto norm2 = u2 + v2;
		const auto f = u > v ? (axExcess - t) / da * (u + 1.0) + v2
			: (byExcess - t) / db * (v + 1.0) + u2;
		if (t == 0.0 && f <= 0.0)
			return 0.f;
		if (f == 0.0)
		{
			lo = hi = t;
			break;
		}
		if (f > 0.0)
			lo = t;
		else
			hi = t;
		const auto offset = f / (std::sqrt(norm2) + 1.0);
		const auto boundA = t + offset * da;
		const auto boundB = t + offset * db;
		const auto newLo = std::max(lo, std::min(boundA, boundB));
		const auto newHi = std::min(hi, std::max(boundA, boundB));
		if (newLo <= newHi)
		{
			lo = newLo;
			hi = newHi;
		}
		if (hi - lo <= 1e-8 * hi)
			break;
		const auto candidate = t + f / (2.0 * (u2 / da + v2 / db));
		if (candidate > lo && candidate < hi && hi - lo <= 0.5 * previousWidth)
			t = candidate;
		else
			t = (lo + hi) * 0.5;
	}
	t = (lo + hi) * 0.5;
	const auto dx = x * (t / (t + a2));
	const auto dy = y * (t / (t + b2));
	return float(std::hypot(dx, dy));
}

float distance::Point_Ellipse2(const Vec2& p0,
	const Vec2& p1, float a, float b, float rotation)
{
	if (a == b)
		return Point_Circle(p0, p1, a);
	const auto p = p0 - p1;
	float tCos, tSin;
	SinCos(-rotation, tSin, tCos);
	const auto x = std::abs(double(p.x) * tCos - double(p.y) * tSin);
	const auto y = std::abs(double(p.y) * tCos + double(p.x) * tSin);
	const auto a2 = double(a) * a;
	const auto b2 = double(b) * b;
	if (x * x / a2 + y * y / b2 <= 1.0)
		return 0.f;
	const auto ax = a * x;
	const auto by = b * y;
	double lo = 0.0;
	double hi = std::sqrt(ax * ax + by * by);
	double t = 0.0;
	while (hi - lo > 1e-4 * hi)
	{
		const auto previousWidth = hi - lo;
		const auto da = t + a2;
		const auto db = t + b2;
		const auto u = ax / da;
		const auto v = by / db;
		const auto u2 = u * u;
		const auto v2 = v * v;
		const auto norm2 = u2 + v2;
		const auto f = norm2 - 1.0;
		if (f > 0.0)
			lo = t;
		else
			hi = t;
		const auto offset = f / (std::sqrt(norm2) + 1.0);
		const auto boundA = t + offset * da;
		const auto boundB = t + offset * db;
		const auto newLo = std::max(lo, std::min(boundA, boundB));
		const auto newHi = std::min(hi, std::max(boundA, boundB));
		if (newLo <= newHi)
		{
			lo = newLo;
			hi = newHi;
		}
		if (hi - lo <= 1e-4 * hi)
			break;
		const auto candidate = t + f / (2.0 * (u2 / da + v2 / db));
		if (candidate > lo && candidate < hi && hi - lo <= 0.5 * previousWidth)
			t = candidate;
		else
			t = (lo + hi) * 0.5;
	}
	t = (lo + hi) * 0.5;
	const auto dx = x * (t / (t + a2));
	const auto dy = y * (t / (t + b2));
	return float(std::sqrt(dx * dx + dy * dy));
}
