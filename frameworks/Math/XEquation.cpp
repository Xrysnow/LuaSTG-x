#include "XEquation.h"
#include "XConstant.h"
#include <algorithm>
#include <limits>

using namespace xmath;
using xmath::Complex;

namespace
{
	template<size_t N>
	int ScalePolynomial(std::array<double, N>& c)
	{
		int leadingExponent;
		const auto leading = std::frexp(c[0], &leadingExponent);
		int exponent = std::numeric_limits<int>::min();
		for (size_t i = 1; i < N; ++i)
		{
			if (c[i] == 0.0)continue;
			int e;
			std::frexp(c[i], &e);
			const auto difference = e - leadingExponent;
			const auto degree = static_cast<int>(i);
			const auto candidate = difference >= 0 ?
				(difference + degree - 1) / degree : difference / degree;
			exponent = std::max(exponent, candidate);
		}
		if (exponent == std::numeric_limits<int>::min())exponent = 0;
		for (size_t i = 1; i < N; ++i)
		{
			int e;
			const auto mantissa = std::frexp(c[i], &e);
			c[i] = std::scalbn(mantissa / leading,
				e - leadingExponent - static_cast<int>(i) * exponent);
		}
		c[0] = 1.0;
		return exponent;
	}

	template<size_t N>
	std::array<Complex, N> UnscaleRoots(std::array<Complex, N> roots, int exponent)
	{
		for (auto& root : roots)
			root = Complex(std::scalbn(root.real(), exponent), std::scalbn(root.imag(), exponent));
		return roots;
	}

	double DifferenceOfProducts(double a, double b, double c, double d)
	{
		const auto cd = c * d;
		return std::fma(a, b, -cd) - std::fma(c, d, -cd);
	}
}

std::array<double, 2> equation::SolveLiner(double a1, double b1, double c1, double a2, double b2, double c2)
{
	const auto den = a2 * b1 - a1 * b2;
	return { (c2*b1 - c1 * b2) / den,(c1*a2 - c2 * a1) / den };
}

std::array<Complex, 2> equation::SolveQuadratic(double a, double b, double c)
{
	if (a == 0.0)
	{
		const auto x = Complex(-c / b);
		return { x,x };
	}
	else
	{
		if (c == 0.0)return { Complex(0.0),Complex(-b / a) };
		int ae, be, ce;
		const auto am = std::frexp(a, &ae);
		const auto bm = std::frexp(b, &be);
		const auto cm = std::frexp(c, &ce);
		const auto ace = ae + ce + 2;
		const auto half = ace >= 0 ? (ace + 1) / 2 : ace / 2;
		const auto exponent = b == 0.0 ? half : std::max(be, half);
		const auto bs = std::scalbn(b, -exponent);
		const auto ac = am * cm;
		const auto shift = ace - 2 * exponent;
		const auto delta = std::fma(bs, bs, -std::scalbn(ac, shift)) -
			std::scalbn(std::fma(am, cm, -ac), shift);
		if (delta >= 0.0)
		{
			const auto q = -0.5 * (bs + std::copysign(std::sqrt(delta), b));
			return { Complex(std::scalbn(q / am, exponent - ae)),
				Complex(std::scalbn(cm / q, ce - exponent)) };
		}
		const auto real = std::scalbn(-0.5 * bm / am, be - ae);
		const auto imag = std::scalbn(0.5 * std::sqrt(-delta) / am, exponent - ae);
		return { Complex(real, imag),Complex(real, -imag) };
	}
}

std::array<Complex, 3> equation::SolveCubic(double a, double b, double c, double d)
{
	if (d == 0.0)
	{
		const auto roots = SolveQuadratic(a, b, c);
		return { roots[0],roots[1],Complex(0.0) };
	}
	std::array<double, 4> coefficients{ a,b,c,d };
	const auto exponent = ScalePolynomial(coefficients);
	a = 1.0; b = coefficients[1]; c = coefficients[2]; d = coefficients[3];
	const auto restore = [exponent](std::array<Complex, 3> roots) { return UnscaleRoots(roots, exponent); };
	const auto A = std::fma(b, b, -3 * c);
	const auto B = std::fma(b, c, -9 * d);
	const auto C = DifferenceOfProducts(c, c, 3 * b, d);
	const auto delta = DifferenceOfProducts(B, B, 4 * A, C);
	if (A == 0.0&&B == 0.0)
	{
		const auto r = Complex(-b / (3 * a));
		return restore({ r,r,r });
	}
	else if (delta > 0.0)
	{
		const auto tmp = std::sqrt(delta);
		const auto center = std::fma(A, b, -1.5 * B);
		const auto y1_cbrt = std::cbrt(center + std::copysign(1.5 * tmp, center));
		const auto y2_cbrt = A / y1_cbrt;
		const auto tmp2 = y1_cbrt + y2_cbrt;
		const auto a3 = a * 3;
		const auto x1 = Complex((-b - tmp2) / a3);
		const auto real = (-b + 0.5*tmp2) / a3;
		const auto img = (y1_cbrt - y2_cbrt)*sqrt3_2 / a3;
		const auto x2 = Complex(real, img);
		const auto x3 = Complex(real, -img);
		return restore({ x1,x2,x3 });
	}
	else if (delta == 0.0)
	{
		const auto K = B / A;
		return restore({ Complex(-b / a + K),Complex(-K / 2),Complex(-K / 2) });
	}
	else// if (delta < 0.0)
	{
		const auto A_sqrt = std::sqrt(A);
		const auto T = (2 * A*b - 3 * a*B) / (2 * A*A_sqrt);
		const auto theta_3 = std::acos(std::max(-1.0, std::min(1.0, T))) / 3;
		const auto tcos = std::cos(theta_3);
		const auto tsin = std::sin(theta_3);
		const auto a3 = a * 3;
		const auto x1 = (-b - 2 * A_sqrt*tcos) / a3;
		const auto x2 = (-b + A_sqrt * (tcos + tsin * sqrt3)) / a3;
		const auto x3 = (-b + A_sqrt * (tcos - tsin * sqrt3)) / a3;
		return restore({ x1,x2,x3 });
	}
}

std::array<Complex, 3> equation::SolveCubic2(double a, double b, double c, double d)
{
	if (d == 0.0)
	{
		const auto roots = SolveQuadratic(a, b, c);
		return { roots[0],roots[1],Complex(0.0) };
	}
	std::array<double, 4> coefficients{ a,b,c,d };
	const auto exponent = ScalePolynomial(coefficients);
	b = coefficients[1]; c = coefficients[2]; d = coefficients[3];
	const auto restore = [exponent](std::array<Complex, 3> roots) { return UnscaleRoots(roots, exponent); };
	const auto D = std::fma(b, b, -3 * c);
	const auto R = (std::fma(b, std::fma(-2 * b, b, 9 * c), -27 * d)) / 2;
	const auto delta = DifferenceOfProducts(R, R, D * D, D);
	if (D > 0.0 && delta <= 0.0)
	{
		const auto Dsq = std::sqrt(D);
		const auto r = R / (D * Dsq);
		const auto th = std::acos(std::max(-1.0, std::min(1.0, r))) / 3;
		return restore({
			Complex((-b + 2 * Dsq * std::cos(th)) / 3),
			Complex((-b + 2 * Dsq * std::cos(th + pix2_3)) / 3),
			Complex((-b + 2 * Dsq * std::cos(th - pix2_3)) / 3) });
	}
	const auto u = std::cbrt(R + std::copysign(std::sqrt(std::max(0.0, delta)), R));
	const auto v = u == 0.0 ? 0.0 : D / u;
	const auto sum = u + v;
	const auto real = (-b - 0.5 * sum) / 3;
	const auto imag = (u - v) * sqrt3_2 / 3;
	return restore({ Complex((-b + sum) / 3),Complex(real, imag),Complex(real, -imag) });
}

std::array<Complex, 4> equation::SolveQuartic(double a, double b, double c, double d, double e)
{
	if (e == 0.0)
	{
		const auto roots = SolveCubic(a, b, c, d);
		return { roots[0],roots[1],roots[2],Complex(0.0) };
	}
	std::array<double, 5> coefficients{ a,b,c,d,e };
	const auto exponent = ScalePolynomial(coefficients);
	a = 1.0; b = coefficients[1]; c = coefficients[2]; d = coefficients[3]; e = coefficients[4];
	const double P = (c*c + 12 * a*e - 3 * b*d) / 9;
	const auto Q = (27 * a*d*d + 2 * c*c*c + 27 * b*b*e - 72 * a*c*e - 9 * b*c*d) / 54;
	const auto D = std::sqrt(Complex(Q*Q - P*P*P, 0.f));
	Complex u;
	if (D.real() * Q > 0.f)
		u = Q + D;
	else
		u = Q - D;
	u = cbrt(u);
	const auto v = (u == complex_zero) ? complex_zero : P / u;
	double m_abs = -1.f;
	Complex m;
	const auto tmp = b * b - 8.0 / 3.0 * a*c;
	Complex tmp2;
	for (auto k = 1; k < 4; k++)
	{
		const auto t = (std::pow(complex_omiga_3, k - 1)*u + std::pow(complex_omiga_3, 4 - k)*v)*4.0*a;
		const auto mm = std::sqrt(t + tmp);
		const auto mm_abs = std::abs(mm);
		if (mm_abs > m_abs)
		{
			m_abs = mm_abs;
			m = mm;
			tmp2 = t;
		}
	}
	Complex S, T;
	if (m_abs == 0.0)
	{
		m = complex_zero;
		S = tmp;
		T = complex_zero;
	}
	else
	{
		S = tmp * 2 - tmp2;
		T = (8 * a*b*c - 16 * a*a*d - 2 * b*b*b) / m;
	}
	const auto sq1 = std::sqrt(S - T);
	const auto sq2 = std::sqrt(S + T);
	const auto b1 = -b - m;
	const auto b2 = -b + m;
	const auto a4 = a * 4;
	return UnscaleRoots<4>({
		(b1 + sq1) / a4,
		(b1 - sq1) / a4,
		(b2 + sq2) / a4,
		(b2 - sq2) / a4
	}, exponent);
}
