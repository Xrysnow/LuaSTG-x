#pragma once
#include <array>
#include <vector>
#include <memory>

template <typename T, size_t Size>
class ArrayObjectPool
{
private:
	uint32_t idx_a;
	uint32_t idx_b;
	float trim_r = 0.5f;
	std::vector<std::shared_ptr<std::array<T, Size>>> blocks;
public:
	T* get()
	{
		try
		{
			if (idx_a == Size)
			{
				idx_a = 0;
				++idx_b;
				if (idx_b == blocks.size())
				{
					blocks.emplace_back(std::make_shared<std::array<T, Size>>());
				}
			}
			return &blocks[idx_b]->operator[](idx_a++);
		}
		catch (...)
		{
			return nullptr;
		}
	}

	uint32_t getArrIdx() const { return idx_a; }
	uint32_t getBlockIdx() const { return idx_b; }
	static uint32_t getBlockSize() { return Size; }

	void setTrimRatio(float r) { trim_r = std::max(0.0f, std::min(r, 1.0f)); }

	T& at(uint32_t i)
	{
		return blocks.at(i / Size)->at(i%Size);
	}

	T& at(uint32_t ia, uint32_t ib)
	{
		return blocks.at(ib)->at(ia);
	}

	T& operator[](uint32_t i)
	{
		return blocks[i / Size]->operator[](i%Size);
	}

	void reserve(uint32_t nBlock)
	{
		for (int i = 0; i < nBlock - blocks.size(); ++i)
		{
			try
			{
				blocks.emplace_back(std::make_shared<std::array<T, Size>>());
			}
			catch (...)
			{
			}
		}
	}

	void shrink_to_fit()
	{
		blocks.resize(idx_b + 1);
	}

	void reset()
	{
		idx_a = 0;
		idx_b = 0;
	}

	size_t size() const
	{
		return idx_b*Size + idx_a;
	}

	size_t capacity()
	{
		return blocks.size()*Size;
	}

	void trim()
	{
		if (Size < size() && size() < capacity()*trim_r)
			shrink_to_fit();
	}

	void clear()
	{
		blocks.clear();
		try
		{
			blocks.emplace_back(std::make_shared<std::array<T, Size>>());
		}
		catch (...)
		{
		}
		idx_a = 0;
		idx_b = 0;
	}

	ArrayObjectPool& operator=(const ArrayObjectPool&) = delete;
	ArrayObjectPool(const ArrayObjectPool&) = delete;
public:
	ArrayObjectPool()
	{
		clear();
	}
	~ArrayObjectPool()
	{
	}
};
