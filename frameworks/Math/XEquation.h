#pragma once
#include <array>
#include "XComplex.h"

namespace xmath
{
	namespace equation
	{
		/** solve:
		 * a1 x + b1 y = c1
		 * a2 x + b2 y = c2 */
		std::array<double, 2> SolveLiner(
			double a1, double b1, double c1,
			double a2, double b2, double c2);

		// solve: a x^2 + b x + c = 0 (a == 0, b != 0 repeats the linear root)
		std::array<Complex, 2> SolveQuadratic(double a, double b, double c);
		// solve: a x^3 + b x^2 + c x + d = 0, a != 0, scaled Shengjin method
		std::array<Complex, 3> SolveCubic(double a, double b, double c, double d);
		// Alternative scaled Cardano / trigonometric method (same preconditions).
		std::array<Complex, 3> SolveCubic2(double a, double b, double c, double d);
		// solve: a x^4 + b x^3 + c x^2 + d x + e = 0, a != 0, scaled Ferrari method
		std::array<Complex, 4> SolveQuartic(double a, double b, double c, double d, double e);
	}
}
