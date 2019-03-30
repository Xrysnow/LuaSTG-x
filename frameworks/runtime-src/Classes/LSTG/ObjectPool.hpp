#pragma once
#include "Global.h"

namespace lstg
{
	// fixed length object pool
	template <typename T, size_t AllocCount>
	class FixedObjectPool
	{
	private:
		//static_assert(std::is_pod<typename T>::value, "T must be a pod type.");
		std::vector<size_t> m_FreeIndex;
		std::array<bool, AllocCount> m_DataUsed;
		std::array<T, AllocCount> m_DataBuffer;
	public:
		/// @brief 申请一个对象
		/// @param[out] id 对象id
		/// @return 是否成功，失败返回false表明对象池已满
		bool Alloc(size_t& id)
		{
			if (!m_FreeIndex.empty())
			{
				id = m_FreeIndex.back();
				m_FreeIndex.pop_back();
				m_DataUsed[id] = true;
				return true;
			}
			id = static_cast<size_t>(-1);
			return false;
		}
		/// @brief 回收一个对象
		void Free(size_t id)
		{
			if (id < AllocCount && m_DataUsed[id])
			{
				m_DataUsed[id] = false;
				m_FreeIndex.push_back(id);
			}
		}
		/// @brief 获取对象的数据
		/// @return 若id无效返回nullptr
		T* Data(size_t id)
		{
			if (id < AllocCount && m_DataUsed[id])
				return &m_DataBuffer[id];
			return nullptr;
		}
		/// @brief 返回已分配对象数
		size_t Size()
		{
			return m_DataBuffer.size() - m_FreeIndex.size();
		}
		/// @brief 清空对象池并回收所有对象
		void Clear()
		{
			m_FreeIndex.resize(m_DataBuffer.size());
			for (size_t i = 0; i < m_DataBuffer.size(); ++i)
			{
				m_FreeIndex[i] = (m_DataBuffer.size() - 1) - i;
				m_DataUsed[i] = false;
			}
		}
	public:
		FixedObjectPool& operator=(const FixedObjectPool&) = delete;
		FixedObjectPool(const FixedObjectPool&) = delete;
		FixedObjectPool()
		{
			Clear();
		}
		~FixedObjectPool()
		{
		}
	};
}
