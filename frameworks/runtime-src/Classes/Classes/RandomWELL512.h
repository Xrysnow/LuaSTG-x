#pragma once
#include <cstdint>

namespace lstg
{
	class RandomWELL512
	{
		uint32_t state[16];
		uint32_t index;
		uint32_t seed;
	public:
		uint32_t getSeed() const;
		void setSeed(uint32_t newSeed);
		/** unsigned int in [0, 2^32-1] */
		uint32_t getRandUInt();
		/** unsigned int in [0, hi] */
		uint32_t getRandUInt(uint32_t hi);
		/** random float in [0, 1] */
		float getRandFloat();
		/** random float in [lo, hi] */
		float getRandFloat(float lo, float hi);

		RandomWELL512();
		RandomWELL512(uint32_t seed);
		~RandomWELL512();
	};
}
