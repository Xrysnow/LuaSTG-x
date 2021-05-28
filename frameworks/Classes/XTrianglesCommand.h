#pragma once
#include "renderer/CCTrianglesCommand.h"
#include "../LSTG/RenderMode.h"

namespace lstg
{
	class RenderMode;

	class XTrianglesCommand : public cocos2d::TrianglesCommand
	{
	public:
		XTrianglesCommand();

		void init(float globalOrder, cocos2d::Texture2D* texture,
			RenderMode* renderMode, cocos2d::backend::ProgramState* programState);
		//TODO: setExternalMV
		cocos2d::Mat4* getMV() { return &_mv; }
		Triangles* getTri() { return &_triangles; }
		cocos2d::PipelineDescriptor* getDesc() { return &_pipelineDescriptor; }

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
