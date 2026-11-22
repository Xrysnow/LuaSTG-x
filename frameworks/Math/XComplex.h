#pragma once
#include <array>
#include <complex>
#include "XConstant.h"

namespace xmath
{
	using Complex = std::complex<double>;
	constexpr auto complex_zero = Complex(0, 0);
	constexpr auto complex_i = Complex(0, 1);
	constexpr auto complex_omiga_3 = Complex(-0.5, sqrt3_2);
	constexpr auto complex_omiga_3c = Complex(-0.5, -sqrt3_2);

	Complex cbrt(Complex x);
	std::array<Complex, 3> cbrt_all(Complex x);
}
