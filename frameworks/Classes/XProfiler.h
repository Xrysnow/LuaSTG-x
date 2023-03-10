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
		void setEnabled(bool b);
		bool isEnabled() const;

		void tic(const std::string& name);
		double toc(const std::string& name);

		double getAverageTime(const std::string& name);
		double getMinTime(const std::string& name);
		double getMaxTime(const std::string& name);
		double getTime(const std::string& name);
		size_t getCount(const std::string& name);

		void next();
		void next(const std::string& name);
		void reset();
		void reset(const std::string& name);
		void clear();

		struct Record
		{
			double time = 0;
			size_t count = 0;
		};

		struct ProfileTimer
		{
			StopWatch sw;
			CirularQueue<Record, 60> que;
			double sum = 0.0;
			double avg = 0.0;
			double min = 1e10;
			double max = 0.0;
			double current = 0.0;
			size_t count = 0;
			bool _toc = false;
			void tic();
			double toc();
			void next();
			void reset();
		};

		ProfileTimer* getTimer(const std::string& name);

	private:

		std::unordered_map<std::string, ProfileTimer> timers;
		bool enable = true;

		XProfiler() = default;
		~XProfiler() = default;
	};

	void ProfilingBegin(const std::string& name);
	double ProfilingEnd(const std::string& name);

	struct ProfilingScope
	{
		ProfilingScope(const ProfilingScope&) = delete;
		ProfilingScope& operator=(const ProfilingScope&) = delete;

		ProfilingScope(const std::string& name)
			: _name(name)
		{
			ProfilingBegin(_name);
		}
		~ProfilingScope()
		{
			ProfilingEnd(_name);
		}
		std::string _name;
	};
}
