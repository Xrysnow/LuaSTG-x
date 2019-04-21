#pragma once
#include <functional>
#include <condition_variable>
#include <vector>
#include <queue>

namespace lstg
{
	class XThreadPool
	{
		using _lock = std::unique_lock<std::mutex>;
	public:
		XThreadPool(size_t threads)
			: _stop(false), _numTaskLeft(0)
		{
			for (size_t i = 0; i < threads; ++i)
				add_worker();
			_numWorker = threads;
		}

		size_t size() const { return _numWorker; }
		bool empty() const { return _numWorker == 0; }
		size_t task_count() const { return _numTaskLeft; }
		bool task_empty() const { return _numTaskLeft == 0; }
		size_t queue_size() {
			_lock lk(_queueMutex);
			return _taskQueue.size();
		}
		bool queue_empty() { return queue_size() == 0; }

		size_t active_worker_count() { return task_count() - queue_size(); }

		void resize(size_t size)
		{
			if (size > _numWorker)
			{
				for (size_t i = 0; i < size - _numWorker; ++i)
					add_worker();
			}
			else if (size < _numWorker)
			{
				wait();
				join();
				_workers.clear();
				for (size_t i = 0; i < size; ++i)
					add_worker();
			}
			_numWorker = size;
		}

		void add_task(const std::function<void()> &task) {
			if (_numWorker == 0)
			{
				task();
			}
			else
			{
				_lock lk(_queueMutex);
				_taskQueue.emplace(task);
				++_numTaskLeft;
				_taskCondition.notify_one();
			}
		}

		template<class F, class... Args>
		auto add_task_future(F&& f, Args&&... args)
			-> std::future<typename std::result_of<F(Args...)>::type>
		{
			using return_type = typename std::result_of<F(Args...)>::type;
			auto task = std::make_shared<std::packaged_task<return_type()>>(
				std::bind(std::forward<F>(f), std::forward<Args>(args)...)
			);
			std::future<return_type> fu = task->get_future();
			add_task([task]() { (*task)(); });
			return fu;
		}

		void wait() {
			if (_numTaskLeft > 0 && _numWorker > 0) {
				_lock lk(_waitMutex);
				_waitCondition.wait(lk, [this] { return this->_numTaskLeft == 0; });
			}
		}

		~XThreadPool()
		{
			join();
		}

	private:
		void thread_func()
		{
			while (true) {
				std::function<void()> task = nullptr;
				{
					_lock lk(_queueMutex);
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
				--_numTaskLeft;
				_waitCondition.notify_one();
			}
		}

		void add_worker() {
			_workers.emplace_back(std::thread(std::bind(&XThreadPool::thread_func, this)));
		}

		void join()
		{
			{
				_lock lk(_queueMutex);
				_stop = true;
				_taskCondition.notify_all();
			}
			for (auto&& worker : _workers)
				worker.join();
		}

		std::vector<std::thread> _workers;
		std::queue<std::function<void()>> _taskQueue;

		std::mutex _queueMutex;
		std::mutex _waitMutex;
		std::condition_variable _taskCondition;
		std::condition_variable _waitCondition;
		bool _stop;
		size_t _numWorker;
		std::atomic_int _numTaskLeft;
	};
}
