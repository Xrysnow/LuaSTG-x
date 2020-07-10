#pragma once
#include <array>
#include <vector>
#include <memory>

template <typename T, size_t Size, typename TBlock = std::array<T, Size>>
class AutoObjectPool
{
public:
	uint32_t array_index() const { return idx_a; }
	uint32_t block_index() const { return idx_b; }
	static uint32_t block_size() { return Size; }

	void set_trim_ratio(float r) { trim_r = std::max(0.0f, std::min(r, 1.0f)); }

	void reserve(uint32_t nBlock)
	{
		for (int i = 0; i < nBlock - blocks.size(); ++i)
			alloc();
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
		alloc();
		idx_a = 0;
		idx_b = 0;
	}
protected:
	void check_size()
	{
		if (idx_a == Size)
		{
			idx_a = 0;
			++idx_b;
			if (idx_b == blocks.size())
			{
				alloc();
			}
		}
	}

	void alloc()
	{
		on_alloc();
	}

	uint32_t idx_a = 0;
	uint32_t idx_b = 0;
	float trim_r = 0.5f;
	std::vector<std::shared_ptr<TBlock>> blocks;
	std::function<void()> on_alloc;
public:
	AutoObjectPool& operator=(const AutoObjectPool&) = delete;
	AutoObjectPool(const AutoObjectPool&) = delete;
	AutoObjectPool() = default;
	~AutoObjectPool() = default;
};

template <typename T, size_t Size>
class ArrayObjectPool : public AutoObjectPool<T, Size, std::array<T, Size>>
{
public:
	T* get()
	{
		this->check_size();
		return &(this->blocks[this->idx_b]->operator[](this->idx_a++));
	}
	T& operator[](uint32_t i)
	{
		return this->blocks[i / Size]->operator[](i % Size);
	}
	ArrayObjectPool()
	{
		this->on_alloc = [this]()
		{
			this->blocks.emplace_back(std::make_shared<std::array<T, Size>>());
		};
		this->clear();
	}
};
