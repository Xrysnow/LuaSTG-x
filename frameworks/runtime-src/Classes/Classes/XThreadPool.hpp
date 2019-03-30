#pragma once
#include <functional>
#include <condition_variable>
#include <vector>
#include <queue>

namespace lstg
{
	class XThreadPool
	{
	public:
		XThreadPool(int threads = 4)
			: _stop(false)
		{
			for (int index = 0; index < threads; ++index)
			{
				_workers.emplace_back(std::thread(std::bind(&XThreadPool::threadFunc, this)));
			}
			_numWorker = threads;
		}

		int size() const { return _numWorker; }

		void addTask(const std::function<void()> &task) {
			std::unique_lock<std::mutex> lk(_queueMutex);
			_taskQueue.emplace(task);
			_taskCondition.notify_one();
		}

		void stop()
		{
			std::unique_lock<std::mutex> lk(_queueMutex);
			_stop = true;
			_taskCondition.notify_all();
		}

		void join()
		{
			for (auto&& worker : _workers)
				worker.join();
		}

		~XThreadPool()
		{
			stop();
			join();
		}

	private:
		void threadFunc()
		{
			while (true) {
				std::function<void()> task = nullptr;
				{
					std::unique_lock<std::mutex> lk(_queueMutex);
					if (_stop)
					{
						break;
					}
					if (!_taskQueue.empty())
					{
						task = move(_taskQueue.front());
						_taskQueue.pop();
					}
					else
					{
						_taskCondition.wait(lk);
						continue;
					}
				}

				task();
			}
		}

		std::vector<std::thread>  _workers;
		std::queue< std::function<void()> > _taskQueue;

		std::mutex _queueMutex;
		std::condition_variable _taskCondition;
		bool _stop;
		int _numWorker;
	};

}
