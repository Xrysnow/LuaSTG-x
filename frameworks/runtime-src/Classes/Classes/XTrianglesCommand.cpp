#include "XTrianglesCommand.h"
#include "renderer/ccGLStateCache.h"
#include "renderer/CCGLProgram.h"
#include "renderer/CCGLProgramState.h"
#include "xxhash/xxhash.h"
#include "renderer/CCRenderState.h"

using namespace cocos2d;
bool XTrianglesCommand::isBlendFuncSeparate = false;

void XTrianglesCommand::init(float globalOrder, GLuint textureID, GLProgramState* glProgramState,
	BlendFunc blendType, GLuint blendEquation, const Triangles& triangles, const Mat4& mv)
{
	_glBlendEquation = blendEquation;
	TrianglesCommand::init(globalOrder, textureID, glProgramState, blendType, triangles, mv, 0);
}

void XTrianglesCommand::init(float globalOrder, Texture2D* texture, GLProgramState* glProgramState,
	BlendFunc blendType, GLuint blendEquation, const Triangles& triangles, const Mat4& mv)
{
	_glBlendEquation = blendEquation;
	TrianglesCommand::init(globalOrder, texture, glProgramState, blendType, triangles, mv, 0);
}

void XTrianglesCommand::init(float globalOrder, Texture2D* texture, GLProgramState* glProgramState,
	BlendFunc blendType, GLuint blendEquation)
{
	_glBlendEquation = blendEquation;
	_globalOrder = globalOrder;
	_is3D = false;
	_depth = 0;
	if (_triangles.indexCount % 3 != 0)
	{
		const int count = _triangles.indexCount;
		_triangles.indexCount = count / 3 * 3;
		CCLOGERROR("Resize indexCount from %zd to %zd, size must be multiple times of 3",
			count, _triangles.indexCount);
	}

	const auto textureID = texture->getName();
	if (_textureID != textureID || _blendType.src != blendType.src || _blendType.dst != blendType.dst ||
		_glProgramState != glProgramState || _isBlendFuncSeparate != isBlendFuncSeparate)
	{
		_textureID = textureID;
		_blendType = blendType;
		_glProgramState = glProgramState;
		_isBlendFuncSeparate = isBlendFuncSeparate;
		generateMaterialID();
	}
	_alphaTextureID = texture->getAlphaTextureName();
}

void XTrianglesCommand::generateMaterialID()
{
	//add blendEquation and isBlendFuncSeparate
	struct {
		GLuint textureId;
		GLenum blendSrc;
		GLenum blendDst;
		GLuint blendEquation;
		void* glProgramState;
		bool isBlendFuncSeparate;
	} hashMe;

	hashMe.textureId = _textureID;
	hashMe.blendSrc = _blendType.src;
	hashMe.blendDst = _blendType.dst;
	hashMe.blendEquation = _glBlendEquation;
	hashMe.glProgramState = _glProgramState;
	hashMe.isBlendFuncSeparate = isBlendFuncSeparate;
	_materialID = XXH32((const void*)&hashMe, sizeof(hashMe), 0);
}

void XTrianglesCommand::useMaterial() const
{
	//Set texture
	GL::bindTexture2D(_textureID);

	if (_alphaTextureID > 0)
	{ // ANDROID ETC1 ALPHA supports.
		GL::bindTexture2DN(1, _alphaTextureID);
	}
	//set blend mode
	if (_isBlendFuncSeparate)
	{
		// for render in fbo
		glBlendFuncSeparate(_blendType.src, _blendType.dst, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
		GL::blendFunc(_blendType.src, _blendType.dst);
	}
	else
	{
		GL::blendFunc(_blendType.src, _blendType.dst);
	}
	glBlendEquation(_glBlendEquation);
	_glProgramState->apply(_mv);
}

void XTrianglesCommand::copyProperties(XTrianglesCommand* other) const
{
	other->_glBlendEquation = _glBlendEquation;
	other->_globalOrder = _globalOrder;
	other->_is3D = _is3D;
	other->_depth = _depth;
	other->_textureID = _textureID;
	other->_blendType = _blendType;
	other->_glProgramState = _glProgramState;
	other->_isBlendFuncSeparate = _isBlendFuncSeparate;
	other->_alphaTextureID = _alphaTextureID;
	other->_materialID = _materialID;
}

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
