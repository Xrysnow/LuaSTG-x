#pragma once
#include "renderer/TrianglesCommand.h"
#include "../LSTG/RenderMode.h"

namespace lstg
{
	class RenderMode;

	class XTrianglesCommand : public cc::TrianglesCommand
	{
	public:
		XTrianglesCommand();

		void init(float globalOrder, cc::Texture2D* texture,
			RenderMode* renderMode, cc::backend::ProgramState* programState);
		//TODO: setExternalMV
		cc::Mat4* getMV() { return &_mv; }
		Triangles* getTri() { return &_triangles; }
		cc::PipelineDescriptor* getDesc() { return &_pipelineDescriptor; }
		RenderMode* getRenderMode() const { return _renderMode; }

		void copyProperties(XTrianglesCommand* other) const;

	protected:
		RenderMode* _renderMode = nullptr;

	/*
		XTrianglesCommand();
		~XTrianglesCommand();

		static Triangles mergeTiangles(Triangles* trangles, uint32_t count);
		static Triangles mergeTiangles(Triangles trangles, cocos2d::Mat4* mats, uint32_t count);
		static Triangles mergeTiangles(Triangles* trangles, cocos2d::Mat4* mats, uint32_t count);
		static void releaseTiangles(Triangles* trangles);

		static bool isBlendFuncSeparate;
	*/
	};
}
