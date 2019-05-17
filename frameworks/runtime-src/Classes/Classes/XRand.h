#pragma once
#include "../fcyLib/fcyMisc/fcyRandom.h"
#include "cocos2d.h"
#include "../Math/XRandom.h"

namespace lstg
{
	class Random : public cocos2d::Ref, public xmath::random::Random
	{
	private:
		fcyRandomWELL512 random;
	public:
		static Random* create();
		static Random* create(uint32_t seed);

		void setSeed(uint32_t seed) override;
		uint32_t getSeed() override;

		/** get random int32 in range [a, b] */
		int32_t randInt(int32_t a, int32_t b);
		/** get random float in range [a, b] */
		float randFloat(float a, float b);
		/** get random 1 or -1 */
		int32_t randSign();

	private:
		double _rand() override;
		Random();
	public:
		virtual ~Random();
		Random(const Random &) = delete;
		Random &operator =(const Random &) = delete;
	};
}
