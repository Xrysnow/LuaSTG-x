#include "RandomWELL512.h"
#include <ctime>

using namespace lstg;

RandomWELL512::RandomWELL512()
{
	setSeed(uint32_t(time(nullptr)));
}

RandomWELL512::RandomWELL512(uint32_t seed)
{
	setSeed(seed);
}

RandomWELL512::~RandomWELL512()
{
}

uint32_t RandomWELL512::getSeed() const
{
	return seed;
}

void RandomWELL512::setSeed(uint32_t newSeed)
{
	seed = newSeed;
	index = 0;
	const unsigned int mask = ~0u;
	state[0] = newSeed & mask;
	for (int i = 1; i < 16; ++i)
	{
		state[i] = (1812433253UL * (state[i - 1] ^ (state[i - 1] >> 30)) + i) & mask;
	}
}

uint32_t RandomWELL512::getRandUInt()
{
	uint32_t a, b, c, d;
	a = state[index];
	c = state[(index + 13) & 15];
	b = a ^ c ^ (a << 16) ^ (c << 15);
	c = state[(index + 9) & 15];
	c ^= (c >> 11);
	a = state[index] = b ^ c;
	d = a ^ ((a << 5) & 0xDA442D24UL);
	index = (index + 15) & 15;
	a = state[index];
	state[index] = a ^ b ^ d ^ (a << 2) ^ (b << 18) ^ (c << 28);
	return state[index];
}

uint32_t RandomWELL512::getRandUInt(uint32_t hi)
{
	return getRandUInt() % (hi + 1);
}

float RandomWELL512::getRandFloat()
{
	return getRandUInt(1000000) / 1000000.f;
}

float RandomWELL512::getRandFloat(float lo, float hi)
{
	return getRandFloat()*(hi - lo) + lo;
}
