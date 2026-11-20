#pragma once
#include "cocos2d.h"
#include "ArrayObjectPool.hpp"
#include "XTrianglesCommand.h"
#include "Object/GameObjectBentLaser.h"

#define LMP (*lstg::MemPoolManager::getInstance())

namespace lstg
{
	class ProgramStatePool;

	// note: pointer get from this class only avalible for one frame
	class MemPoolManager
	{
	public:
		static MemPoolManager* getInstance();

		using LaserQuads = std::array<cc::V3F_C4B_T2F_Quad, LGOBJ_MAXLASERNODE>;

		XTrianglesCommand* getXTrianglesCommand() { return xtcmdPool.get(); }
		cc::CallbackCommand* getCallbackCommand();
		cc::V3F_C4B_T2F_Quad* getQuad() { return quadsPool.get(); }
		cc::Mat4* getMat4() { return matPool.get(); }
		cc::Mat4* getMat4(float x, float y, float z,
			float rot, float hscale, float vscale, const cc::Vec2& anchorPointInPoints);
		LaserQuads* getLaserQuads() { return laserQuadsPool.get(); }

		void trim();
		void reset();
		void clear();

		template<typename T, size_t N>
		std::shared_ptr<std::array<T, N>> applyArray();
		void clearArrays();
	protected:
		std::shared_ptr<ProgramStatePool> getProgramStatePool(cc::IntrusivePtr<cc::backend::Program> program);
		void removeProgramStatePool(cc::backend::Program* program);
	private:
		ArrayObjectPool<XTrianglesCommand, 4096> xtcmdPool;
		ArrayObjectPool<cc::V3F_C4B_T2F_Quad, 4096> quadsPool;
		ArrayObjectPool<cc::Mat4, 4096> matPool;
		ArrayObjectPool<LaserQuads, 1> laserQuadsPool;
		std::unordered_map<cc::backend::Program*, std::shared_ptr<ProgramStatePool>> statePool;
		std::vector<std::shared_ptr<void>> arrays;
		MemPoolManager() = default;
		friend class RenderMode;
	};

	template <typename T, size_t N>
	std::shared_ptr<std::array<T, N>> MemPoolManager::applyArray()
	{
		auto ret = std::make_shared<std::array<T, N>>();
		arrays.push_back(ret);
		return ret;
	}

	constexpr size_t ProgramStatePoolBlockSize = 32;

	class ProgramStatePool : public AutoObjectPool<
		cc::backend::ProgramState, ProgramStatePoolBlockSize, cc::Vector<cc::backend::ProgramState*>>
	{
	protected:
		cc::IntrusivePtr<cc::backend::Program> _program;
		void alloc_();
	public:
		cc::backend::ProgramState* get();
		explicit ProgramStatePool(cc::IntrusivePtr<cc::backend::Program> program);
	};
}
