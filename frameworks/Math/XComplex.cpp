#include "XComplex.h"
#include "XConstant.h"
#include <cmath>

using xmath::Complex;

Complex xmath::cbrt(Complex x)
{
	//todo: pow?
	return std::polar(std::cbrt(std::abs(x)), std::arg(x) / 3);
}

std::array<Complex, 3> xmath::cbrt_all(Complex x)
{
	const auto a = std::arg(x) / 3;
	const auto r = std::cbrt(std::abs(x));
	return {
		std::polar(r,a),
		std::polar(r,a + pix2_3),
		std::polar(r,a + pix4_3)
	};
}
