#pragma once
#include "Global.h"

namespace lstg
{
	template <typename T, size_t MaxSize>
	class CirularQueue
	{
	private:
		std::array<T, MaxSize> data;
		size_t iFront = 0;
		size_t iRear = 0;
		size_t count = 0;
	public:
		T& operator[](size_t idx)
		{
			CCASSERT(idx < count, "CirularQueue: Out of boundary.");
			return data[(idx + iFront) % MaxSize];
		}
		T* at(size_t idx)
		{
			if (idx >= count)
				return nullptr;
			else
				return &data[(idx + iFront) % MaxSize];
		}
		bool isEmpty() const { return iFront == iRear; }
		bool isFull() const { return (iFront == (iRear + 1) % MaxSize); }
		size_t size() const { return count; }
		size_t max() const { return MaxSize - 1; }

		T* new_back(){
			if (isFull())
				return nullptr;
			const auto ret = &data[iRear];
			iRear = (iRear + 1) % MaxSize;
			++count;
			return ret;
		}
		T* new_front(){
			if (isFull())
				return nullptr;
			if (iFront > 0)
				--iFront;
			else
				iFront = MaxSize - 1;
			++count;
			return &data[iFront];
		}

		void push_back(const T& val)
		{
			if (isFull())
				return;
			data[iRear] = val;
			iRear = (iRear + 1) % MaxSize;
			++count;
		}
		void push_front(const T& val)
		{
			if (isFull())
				return;
			if (iFront > 0)
				--iFront;
			else
				iFront = MaxSize - 1;
			data[iFront] = val;
			++count;
		}

		bool pop_front(T& out)
		{
			if (isEmpty())
				return false;
			out = front();
			pop_front();
			return true;
		}
		void pop_front()
		{
			if (isEmpty())
				return;
			iFront = (iFront + 1) % MaxSize;
			--count;
		}

		bool pop_back(T& out)
		{
			if (isEmpty())
				return false;
			out = back();
			pop_back();
			return true;
		}
		void pop_back()
		{
			if (isEmpty())
				return;
			if (iRear > 0)
				--iRear;
			else
				iRear = MaxSize - 1;
			--count;
		}

		T Queue(T val)
		{
			if (!isFull())
				++count;
			else
				iFront = (iFront + 1) % MaxSize;
			T ret = data[iRear];
			data[iRear] = val;
			iRear = (iRear + 1) % MaxSize;
			return ret;
		}
		T& front()
		{
			CCASSERT(!isEmpty(), "CirularQueue: Try to get front when empty.");
			return data[iFront];
		}
		T& back()
		{
			CCASSERT(!isEmpty(), "CirularQueue: Try to get back when empty.");
			if (iRear == 0)
				return data[MaxSize - 1];
			else
				return data[iRear - 1];
		}

		size_t begin() const { return iFront; }
		size_t end() const { return (iRear == 0) ? MaxSize - 1 : iRear; }
		void clear(){ iFront = 0; iRear = 0; count = 0; }
	};
}
