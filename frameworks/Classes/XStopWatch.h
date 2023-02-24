#pragma once
#include <cstdint>

namespace lstg
{
	class StopWatch
	{
		uint64_t freq = 0;
		uint64_t last = 0;
		uint64_t fixStart = 0;
		uint64_t fixAll = 0;
	public:
		StopWatch();
		~StopWatch();
		StopWatch(const StopWatch &) = delete;
		StopWatch &operator =(const StopWatch &) = delete;

		void pause();
		void resume();
		void reset();
		// in seconds
		double get();
	};
}
