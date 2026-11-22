#pragma once
#include "math/Vec2.h"

namespace xmath
{
	namespace distance
	{
		inline float Point_Point_squared(const cc::Vec2& p0, const cc::Vec2& p1)
		{
			const auto dx = p0.x - p1.x;
			const auto dy = p0.y - p1.y;
			return dx * dx + dy * dy;
		}
		inline float Point_Point(const cc::Vec2& p0, const cc::Vec2& p1)
		{
			return std::sqrt(Point_Point_squared(p0, p1));
		}
		/**
		 * \param p0 the point
		 * \param p1 a point on the line
		 * \param aCos cos(line angle)
		 * \param aSin sin(line angle)
		 */
		inline float Point_Line_signed(const cc::Vec2& p0, const cc::Vec2& p1, float aCos, float aSin)
		{
			return aSin * (p0.x - p1.x) - aCos * (p0.y - p1.y);
		}
		/**
		 * \param p0 the point
		 * \param p1 a point on the line
		 * \param e normal vector of the line
		 * \return if >0, p0 and e are on the same side of the line
		 */
		inline float Point_Line_signed(const cc::Vec2& p0, const cc::Vec2& p1, const cc::Vec2& e)
		{
			return e.x * (p0.x - p1.x) + e.y * (p0.y - p1.y);
		}

		inline float Point_Line(const cc::Vec2& p0, const cc::Vec2& p1, float aCos, float aSin)
		{
			return std::abs(Point_Line_signed(p0, p1, aCos, aSin));
		}

		inline float Point_Line(const cc::Vec2& p0, const cc::Vec2& p1, const cc::Vec2& e)
		{
			return std::abs(Point_Line_signed(p0, p1, e));
		}

		inline float Point_Circle(const cc::Vec2& p0, const cc::Vec2& p1, float r)
		{
			const auto dx = p0.x - p1.x;
			const auto dy = p0.y - p1.y;
			return std::max(std::sqrt(dx*dx + dy * dy) - r, 0.f);
		}

		inline float Point_OBB_squared(const cc::Vec2& p0,
			const cc::Vec2& p1, float halfW, float halfH, float aCos, float aSin)
		{
			const auto d = p0 - p1;
			const auto dw = std::max(0.f, std::abs(aCos * d.x + aSin * d.y) - halfW);
			const auto dh = std::max(0.f, std::abs(-aSin * d.x + aCos * d.y) - halfH);
			return dh * dh + dw * dw;
		}
		inline float Point_OBB(const cc::Vec2& p0,
			const cc::Vec2& p1, float halfW, float halfH, float aCos, float aSin)
		{
			return std::sqrt(Point_OBB_squared(p0, p1, halfW, halfH, aCos, aSin));
		}
		// faster when point not in triangle
		float Point_Triangle(const cc::Vec2& p,
			const cc::Vec2& A,const cc::Vec2& B,const cc::Vec2& C);
		// faster when point in triangle
		// reference: https://www.geometrictools.com/Documentation/DistancePoint3Triangle3.pdf
		float Point_Triangle2(const cc::Vec2& p,
			const cc::Vec2& A,const cc::Vec2& B,const cc::Vec2& C);
		float Point_Diamond(const cc::Vec2& p0,
			const cc::Vec2& p1, float halfW, float halfH, float rotation);
		float Point_Parallelogram(const cc::Vec2& p0,
			const cc::Vec2& p1, const cc::Vec2& halfDiagA, const cc::Vec2& halfDiagB);
		// high accuracy
		float Point_Ellipse(const cc::Vec2& p0,
			const cc::Vec2& p1, float a, float b, float rotation);
		// faster
		float Point_Ellipse2(const cc::Vec2& p0,
			const cc::Vec2& p1, float a, float b, float rotation);
	}
}
