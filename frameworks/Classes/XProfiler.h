#pragma once
#include "CirularQueue.hpp"
#include "XStopWatch.h"
#include <string>

namespace lstg
{
	class XProfiler
	{
	public:
		static XProfiler* getInstance();
		static void setEnable(bool b);

		void tic(const std::string& name);
		double toc(const std::string& name);

		CirularQueue<double, 60>* getQueue(const std::string& name);
		double getAverage(const std::string& name);
		double getMin(const std::string& name);
		double getMax(const std::string& name);
		double getLast(const std::string& name);

		std::unordered_map<std::string, double> getAllLast();

		void clear(const std::string& name);
		void clearAll();

		struct ProfileTimer
		{
			StopWatch sw;
			CirularQueue<double, 60> que;
			double sum = 0.0;
			double avg = 0.0;
			double min = 1e10;
			double max = 0.0;
			bool _toc = false;
			void tic();
			double toc();
			void clear();
		};

		ProfileTimer* getTimer(const std::string& name);

	private:

		std::unordered_map<std::string, ProfileTimer> timers;
		static bool enable;

		XProfiler() = default;
		~XProfiler() = default;
	};	
}
