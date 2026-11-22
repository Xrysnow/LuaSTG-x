#pragma once
#include "math/Vec2.h"
#include <algorithm>
#include <cmath>

namespace xmath
{
	namespace detail
	{
		inline double orientation(const cc::Vec2& A, const cc::Vec2& B, const cc::Vec2& C)
		{
			const auto abx = double(B.x) - A.x;
			const auto aby = double(B.y) - A.y;
			const auto acx = double(C.x) - A.x;
			const auto acy = double(C.y) - A.y;
			return abx * acy - aby * acx;
		}

		inline bool collinear(const cc::Vec2& A, const cc::Vec2& B, const cc::Vec2& C)
		{
			return orientation(A, B, C) == 0.0;
		}

		inline double pointSegmentDistance(double px, double py,
			double ax, double ay, double bx, double by)
		{
			const auto dx = bx - ax;
			const auto dy = by - ay;
			const auto length2 = dx * dx + dy * dy;
			if (length2 == 0.0)
				return std::hypot(px - ax, py - ay);
			const auto projection = (px - ax) * dx + (py - ay) * dy;
			if (projection <= 0.0)
				return std::hypot(px - ax, py - ay);
			if (projection >= length2)
				return std::hypot(px - bx, py - by);
			return std::abs(dx * (py - ay) - dy * (px - ax)) / std::sqrt(length2);
		}

		inline double pointSegmentDistance(const cc::Vec2& p,
			const cc::Vec2& A, const cc::Vec2& B)
		{
			return pointSegmentDistance(p.x, p.y, A.x, A.y, B.x, B.y);
		}

		inline double degenerateTriangleDistance(const cc::Vec2& p,
			const cc::Vec2& A, const cc::Vec2& B, const cc::Vec2& C)
		{
			return std::min(pointSegmentDistance(p, A, B),
				std::min(pointSegmentDistance(p, B, C), pointSegmentDistance(p, C, A)));
		}

		inline bool pointInClosedTriangle(const cc::Vec2& p,
			const cc::Vec2& A, const cc::Vec2& B, const cc::Vec2& C)
		{
			if (collinear(A, B, C))
				return degenerateTriangleDistance(p, A, B, C) == 0.0;
			const auto a = orientation(A, B, p);
			const auto b = orientation(B, C, p);
			const auto c = orientation(C, A, p);
			return (a >= 0.0 && b >= 0.0 && c >= 0.0) || (a <= 0.0 && b <= 0.0 && c <= 0.0);
		}

		inline bool triangleEdgesIntersect(const cc::Vec2& A, const cc::Vec2& B,
			const cc::Vec2& C, const cc::Vec2& D)
		{
			const auto a = orientation(A, B, C);
			const auto b = orientation(A, B, D);
			const auto c = orientation(C, D, A);
			const auto d = orientation(C, D, B);
			if (a == 0.0 && b == 0.0 && c == 0.0 && d == 0.0)
			{
				return std::max(std::min(A.x, B.x), std::min(C.x, D.x)) <=
					std::min(std::max(A.x, B.x), std::max(C.x, D.x)) &&
					std::max(std::min(A.y, B.y), std::min(C.y, D.y)) <=
					std::min(std::max(A.y, B.y), std::max(C.y, D.y));
			}
			return ((a <= 0.0 && b >= 0.0) || (a >= 0.0 && b <= 0.0)) &&
				((c <= 0.0 && d >= 0.0) || (c >= 0.0 && d <= 0.0));
		}
	}
}
