#include "XTrianglesCommand.h"
#include "Renderer.h"
#include "xxhash/xxhash.h"

using namespace lstg;
using namespace cocos2d;
using namespace backend;

XTrianglesCommand::XTrianglesCommand()
{
	_renderMode = RenderMode::getDefault();
}

void XTrianglesCommand::init(float globalOrder, Texture2D* texture,
	RenderMode* renderMode, ProgramState* programState)
{
	_globalOrder = globalOrder;
	_is3D = false;
	_depth = 0;
	assert(programState && renderMode && texture);
	const auto new_tex = texture->getBackendTexture();
	// use RenderMode to avoid compare BlendDescriptor
	if (_renderMode != renderMode ||
		_texture != new_tex ||
		_pipelineDescriptor.programState != programState)
	{
		_renderMode = renderMode;
		_pipelineDescriptor.programState = programState;
		_pipelineDescriptor.blendDescriptor = renderMode->desc;
		_programType = programState->getProgram()->getProgramType();
		_texture = new_tex;
		_blendType.src = renderMode->desc.sourceRGBBlendFactor;
		_blendType.dst = renderMode->desc.destinationRGBBlendFactor;

		// safe to use cocos batching
		setSkipBatching(false);

		struct
		{
			void* texture;
			void* renderMode;
			void* programState;
		}hashMe;
		memset(&hashMe, 0, sizeof(hashMe));
		hashMe.texture = _texture;
		hashMe.renderMode = renderMode;
		hashMe.programState = programState;
		_materialID = XXH32((const void*)&hashMe, sizeof(hashMe), 0);
	}
}

void XTrianglesCommand::copyProperties(XTrianglesCommand* other) const
{
	other->_blendType = _blendType;
	other->_materialID = _materialID;
	other->_alphaTextureID = _alphaTextureID;
	other->_blendType = _blendType;
	other->_programType = _programType;
	other->_texture = _texture;

	other->_globalOrder = _globalOrder;
	other->_isTransparent = _isTransparent;
	other->_skipBatching = _skipBatching;
	other->_is3D = _is3D;
	other->_depth = _depth;
	other->_pipelineDescriptor = _pipelineDescriptor;
	
	other->_renderMode = _renderMode;
}
/*
XTrianglesCommand::XTrianglesCommand()
{
}

XTrianglesCommand::~XTrianglesCommand()
{
}

TrianglesCommand::Triangles XTrianglesCommand::mergeTiangles(Triangles* trangles, uint32_t count)
{
	Triangles ret;
	uint32_t iCount = 0;
	uint32_t vCount = 0;
	for (uint32_t i = 0; i < count; ++i)
	{
		iCount += trangles[i].indexCount;
		vCount += trangles[i].vertCount;
	}
	ret.indexCount = iCount;
	ret.vertCount = vCount;
	ret.indices = new (std::nothrow) unsigned short[iCount];
	ret.verts = new (std::nothrow) V3F_C4B_T2F[vCount];
	uint32_t iFilled = 0;
	uint32_t vFilled = 0;
	for (uint32_t i = 0; i < count; ++i)
	{
		iCount = trangles[i].indexCount;
		vCount = trangles[i].vertCount;
		for (uint32_t j = 0; j < iCount; ++j)
		{
			ret.indices[iFilled + j] = trangles[i].indices[j] + iFilled;
		}
		memcpy(ret.verts + vFilled, trangles[i].verts, vCount);
		iFilled += iCount;
		vFilled += vCount;
	}
	return ret;
}

TrianglesCommand::Triangles XTrianglesCommand::mergeTiangles(Triangles trangles, Mat4* mats, uint32_t count)
{
	Triangles ret;
	uint32_t iCount = trangles.indexCount*count;
	uint32_t vCount = trangles.vertCount*count;
	for (uint32_t i = 0; i < count; ++i)
	{
		iCount += trangles.indexCount;
		vCount += trangles.vertCount;
	}
	ret.indexCount = iCount;
	ret.vertCount = vCount;
	ret.indices = new (std::nothrow) unsigned short[iCount];
	ret.verts = new (std::nothrow) V3F_C4B_T2F[vCount];
	uint32_t iFilled = 0;
	uint32_t vFilled = 0;
	iCount = trangles.indexCount;
	vCount = trangles.vertCount;
	for (uint32_t i = 0; i < count; ++i)
	{
		for (uint32_t j = 0; j < iCount; ++j)
		{
			ret.indices[iFilled + j] = trangles.indices[j] + iFilled;
		}
		memcpy(ret.verts + vFilled, trangles.verts, vCount);
		for (uint32_t j = 0; j < vCount; ++j)
		{
			mats[i].transformPoint(&(ret.verts[vFilled + j].vertices));
		}
		iFilled += iCount;
		vFilled += vCount;
	}
	return ret;
}

TrianglesCommand::Triangles XTrianglesCommand::mergeTiangles(Triangles* trangles, Mat4* mats, uint32_t count)
{
	Triangles ret;
	uint32_t iCount = 0;
	uint32_t vCount = 0;
	for (uint32_t i = 0; i < count; ++i)
	{
		iCount += trangles[i].indexCount;
		vCount += trangles[i].vertCount;
	}
	ret.indexCount = iCount;
	ret.vertCount = vCount;
	ret.indices = new (std::nothrow) unsigned short[iCount];
	ret.verts = new (std::nothrow) V3F_C4B_T2F[vCount];
	uint32_t iFilled = 0;
	uint32_t vFilled = 0;
	for (uint32_t i = 0; i < count; ++i)
	{
		iCount = trangles[i].indexCount;
		vCount = trangles[i].vertCount;
		for (uint32_t j = 0; j < iCount; ++j)
		{
			ret.indices[iFilled + j] = trangles[i].indices[j] + iFilled;
		}
		memcpy(ret.verts + vFilled, trangles[i].verts, vCount);
		for (uint32_t j = 0; j < vCount; ++j)
		{
			mats[i].transformPoint(&(ret.verts[vFilled + j].vertices));
		}
		iFilled += iCount;
		vFilled += vCount;
	}
	return ret;
}

void XTrianglesCommand::releaseTiangles(Triangles* trangles)
{
	CC_SAFE_DELETE_ARRAY(trangles->indices);
	CC_SAFE_DELETE_ARRAY(trangles->verts);
	trangles->indexCount = 0;
	trangles->vertCount = 0;
}

void XTrianglesCommand::releaseTrangles()
{
	releaseTiangles(&_triangles);
}
*/
