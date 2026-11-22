#pragma once
#include <cstdint>

namespace xmath
{
	namespace random
	{
		class Random
		{
		public:

			virtual void setSeed(uint32_t seed) = 0;
			virtual uint32_t getSeed() = 0;

			//-------------------- integer methods  -------------------

			/** Choose a random item from range(start, stop[, step]).
			 * It does not include the endpoint.
			 * If range is empty, it returns start. */
			int64_t range(int64_t start, int64_t stop, int64_t step = 1);
			/** Return a random int in the range [0, n).
			 * Consumes exactly two _rand() calls, including when n is 0.
			 * For positive n, scaling is unbiased only when n is a power of two.
			 * Return 0 if n is 0. */
			uint64_t below(uint64_t n);

			//-------------------- real-valued distributions  -------------------

			/** Uniform distribution.
			 * Get a random number in the range [a, b). */
			double uniform(double a, double b);
			/** Triangular distribution.
			 * Continuous distribution bounded by given lower and upper limits,
			 * and having a given mode value in-between.
			 * http://en.wikipedia.org/wiki/Triangular_distribution */
			double triangular();
			double triangular(double low, double high);
			double triangular(double low, double high, double mode);
			/** Normal distribution.
			 * mu is the mean, and sigma is the standard deviation.*/
			double normal(double mu, double sigma);
			/** Log normal distribution.
			 * If you take the natural logarithm of this distribution, you'll get a
			 * normal distribution with mean mu and standard deviation sigma.
			 * mu can have any value, and sigma must be greater than zero.*/
			double log_normal(double mu, double sigma);
			/** Exponential distribution.
			 * lambda is 1.0 divided by the desired mean. It should be
			 * nonzero. Returned values range from 0 to
			 * positive infinity if lambda is positive, and from negative
			 * infinity to 0 if lambda is negative.*/
			double expo(double lambda);
			/** von Mises distribution (Circular data distribution).
			 * mu is the mean angle, expressed in radians between 0 and 2*pi, and
			 * kappa is the concentration parameter, which must be greater than or
			 * equal to zero. If kappa is equal to zero, this distribution reduces
			 * to a uniform random angle over the range 0 to 2*pi.*/
			double vonMises(double mu, double kappa);
			/** Gamma distribution. (Not the gamma function)
			 * Conditions on the parameters are alpha > 0 and beta > 0.*/
			double gamma(double alpha, double beta);
			/** Gaussian distribution.
			 * mu is the mean, and sigma is the standard deviation. This is
			 * slightly faster than the normal() function.*/
			double gauss(double mu, double sigma);
			/** Beta distribution.
			 * Conditions on the parameters are alpha > 0 and beta > 0.
			 * Returned values range between 0 and 1.*/
			double beta(double alpha, double beta);
			/** Pareto distribution.
			 * alpha is the shape parameter.*/
			double pareto(double alpha);
			/** Weibull distribution.
			 * alpha is the scale parameter and beta is the shape parameter.*/
			double weibull(double alpha, double beta);

		protected:
			// Overrides of setSeed() must call _clear_state()
			void _clear_state();
			virtual double _rand() = 0;
			bool has_gauss_next = false;
			double _gauss_next = 0.0;

		public:
			Random(){}
			virtual ~Random(){}
		};
	}
}
