﻿#include "RenderMode.h"
#include "Util/Utility.h"
#include "Util/UtilLua.h"
#include "LogSystem.h"
#include "../Classes/MemPoolManager.h"
#include "Renderer.h"
#ifdef CC_USE_GFX
#include "renderer/backend/gfx/ProgramGFX.h"
#endif
#include <cstring>

using namespace std;
using namespace lstg;
using namespace cocos2d;
using backend::ProgramState;
using backend::ShaderStage;
using backend::BlendFactor;

static RenderMode* RenderModeDefault = nullptr;
std::vector<RenderMode*> RenderMode::modeVector;
Map<std::string, RenderMode*> RenderMode::modeMap;

static void SetDefaultVertexLayout(Program* program, VertexLayout* v)
{
	if(!program)
		return;
	v->setAttribute(backend::ATTRIBUTE_NAME_POSITION,
		program->getAttributeLocation(backend::POSITION),
		backend::VertexFormat::FLOAT3,
		0,
		false);
	v->setAttribute(backend::ATTRIBUTE_NAME_TEXCOORD,
		program->getAttributeLocation(backend::TEXCOORD),
		backend::VertexFormat::FLOAT2,
		offsetof(V3F_C4B_T2F, texCoords),
		false);
	v->setAttribute(backend::ATTRIBUTE_NAME_COLOR,
		program->getAttributeLocation(backend::COLOR),
		backend::VertexFormat::UBYTE4,
		offsetof(V3F_C4B_T2F, colors),
		true);
	v->setStride(sizeof(V3F_C4B_T2F));
}

RenderMode::RenderMode()
{
}

RenderMode::~RenderMode()
{
	//if(pool)
	//	LMP.removeProgramStatePool(_program);
	CC_SAFE_RELEASE(_program);
	CC_SAFE_RELEASE(defaultState);
}

RenderMode* RenderMode::getDefault()
{
	if (!RenderModeDefault)
		RenderModeDefault = new RenderMode();
	CC_ASSERT(RenderModeDefault);
	return RenderModeDefault;
}

void RenderMode::destructDefault()
{
	delete RenderModeDefault;
	RenderModeDefault = nullptr;
}

RenderMode* RenderMode::create(const std::string& name,
	backend::BlendOperation blendOp,
	backend::BlendFactor blendFactorSrc,
	backend::BlendFactor blendFactorDst,
	Program* program)
{
	auto ret = new (std::nothrow) RenderMode();
	if (ret&&ret->init(name, blendOp, blendFactorSrc, blendFactorDst, program))
	{
		ret->autorelease();
		addMode(ret);
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

RenderMode* RenderMode::create(const std::string& name, Program* program)
{
	return create(name,
		backend::BlendOperation::ADD,
		backend::BlendFactor::SRC_ALPHA,
		backend::BlendFactor::ONE_MINUS_SRC_ALPHA,
		program);
}

BlendFunc RenderMode::getBlendFunc() const
{
	return { desc.sourceRGBBlendFactor, desc.destinationRGBBlendFactor };
}

void RenderMode::setProgram(Program* program)
{
	if (!program || program == _program)
		return;
	// need to set this when program changes
	LRR.setProgramStateDirty();
	if (pool)
	{
		//LMP.removeProgramStatePool(_program);
		pool = LMP.getProgramStatePool(program);
	}
	CC_SAFE_RELEASE(_program);
	_program = program;
	CC_SAFE_RETAIN(_program);

	if (_program->getVertexLayout()->getAttributes().empty())
	{
		// set layout
		SetDefaultVertexLayout(_program, _program->getVertexLayout());
	}

	CC_SAFE_RELEASE(defaultState);
	defaultState = new backend::ProgramState(_program);
	setVertexLayout(defaultState);
	defaultState->getFragmentUniformBuffer(&fragUniformBuffer, fragUniformBufferSize);
	defaultState->getVertexUniformBuffer(&vertUniformBuffer, vertUniformBufferSize);

	locations.clear();
	uniformNames.clear();
	// ShaderStage::VERTEX_AND_FRAGMENT is not valid for metal
	for (const auto& it : _program->getAllActiveUniformInfo(ShaderStage::FRAGMENT))
	{
		locations[it.first] = _program->getUniformLocation(it.first);
		uniformNames.push_back(it.first);
	}
	for (const auto& it : _program->getAllActiveUniformInfo(ShaderStage::VERTEX))
	{
		locations[it.first] = _program->getUniformLocation(it.first);
		uniformNames.push_back(it.first);
	}
}

Program* RenderMode::getProgram() const
{
	return _program;
}

ProgramState* RenderMode::getDefaultProgramState() const
{
	return defaultState;
}

ProgramState* RenderMode::newProgramState()
{
	const auto ret = new ProgramState(_program);
	setVertexLayout(ret);
	syncUniform(ret);
	return ret;
}

void RenderMode::setFloat(const std::string& uniform, float value)
{
	setUniform(uniform, &value, sizeof(value));
}

void RenderMode::setVec2(const std::string& uniform, const Vec2& value)
{
	setUniform(uniform, &value, sizeof(value));
}

void RenderMode::setVec3(const std::string& uniform, const Vec3& value)
{
	setUniform(uniform, &value, sizeof(value));
}

void RenderMode::setVec4(const std::string& uniform, const Vec4& value)
{
	setUniform(uniform, &value, sizeof(value));
}

void RenderMode::setMat4(const std::string& uniform, const Mat4& value)
{
	setUniform(uniform, &value, sizeof(value));
}

void RenderMode::setColor(const std::string& uniform, const Color4B& value)
{
	Vec4 v{ value.r / 255.f, value.g / 255.f, value.b / 255.f, value.a / 255.f };
	setUniform(uniform, &v, sizeof(v));
}

void RenderMode::setTexture(const std::string& uniform, Texture2D* value, uint32_t slot)
{
	const auto it = locations.find(uniform);
	if (it != locations.end() && value)
		defaultState->setTexture(it->second, slot, value->getBackendTexture());
}

void RenderMode::setUniformBuffer(const std::string& buffer)
{
	if (buffer.size() != fragUniformBufferSize + vertUniformBufferSize)
		return;
	if (fragUniformBuffer)
		std::memcpy(fragUniformBuffer,
			buffer.c_str(), fragUniformBufferSize);
	if (vertUniformBuffer)
		std::memcpy(vertUniformBuffer,
			buffer.c_str() + fragUniformBufferSize, vertUniformBufferSize);
}

std::string RenderMode::getUniformBuffer() const
{
	string f, v;
	if (fragUniformBuffer)
		f = string(fragUniformBuffer, fragUniformBufferSize);
	if (vertUniformBuffer)
		v = string(vertUniformBuffer, vertUniformBufferSize);
	return f + v;
}

RenderMode* RenderMode::clone(const std::string& newName)
{
	if (newName == _name)
		return this;
	auto ret = create(newName, _program);
	if (ret)
	{
		ret->desc = desc;
		ret->setUniformBuffer(getUniformBuffer());
	}
	return ret;
}

bool RenderMode::init(const std::string& name, backend::BlendOperation equation,
                      BlendFactor funcSrc, BlendFactor funcDst, Program* program)
{
	if (!program)return false;
	if (!util::CheckBlendOperation(equation))return false;
	if (!util::CheckBlendFactor(funcSrc))return false;
	if (!util::CheckBlendFactor(funcDst))return false;

	_name = name;
	desc.blendEnabled = true;
	desc.rgbBlendOperation = equation;
	desc.sourceRGBBlendFactor = funcSrc;
	desc.destinationRGBBlendFactor = funcDst;
	//note: keep alpha here
	//TODO: custom for RenderTarget
	desc.alphaBlendOperation = backend::BlendOperation::ADD;
	desc.sourceAlphaBlendFactor = backend::BlendFactor::ONE;
	desc.destinationAlphaBlendFactor = backend::BlendFactor::ONE_MINUS_SRC_ALPHA;

#ifndef CC_USE_GFX
	SetDefaultVertexLayout(program, &defaultLayout);
#endif // !CC_USE_GFX
	setProgram(program);
	return true;
}

backend::ProgramState* RenderMode::tempraryProgramState()
{
	if(!pool)
		pool = LMP.getProgramStatePool(_program);
	const auto ret = ((ProgramStatePool*)pool.get())->get();
	setVertexLayout(ret);
	syncUniform(ret);
	return ret;
}

void RenderMode::setVertexLayout(ProgramState* state) const
{
	CC_ASSERT(state);
#ifndef CC_USE_GFX
	// VertexLayout is copyable
	*state->getVertexLayout() = defaultLayout;
#endif // !CC_USE_GFX
}

void RenderMode::syncUniform(ProgramState* state)
{
	CC_ASSERT(state);
	char* fBuffer = nullptr;
	char* vBuffer = nullptr;
	size_t fSize = 0;
	size_t vSize = 0;
	state->getFragmentUniformBuffer(&fBuffer, fSize);
	state->getVertexUniformBuffer(&vBuffer, vSize);
	CC_ASSERT(fSize == fragUniformBufferSize && vSize == vertUniformBufferSize);
	if (fBuffer)
		std::memcpy(fBuffer, fragUniformBuffer, fragUniformBufferSize);
	if (vBuffer)
		std::memcpy(vBuffer, vertUniformBuffer, vertUniformBufferSize);

#ifndef CC_USE_GFX
	for (auto&& it : defaultState->getVertexTextureInfos())
	{
		UniformLocation loc;
		loc.shaderStage = ShaderStage::VERTEX;
		loc.location[0] = it.first;
		state->setTextureArray(loc, it.second.slot, it.second.textures);
	}
	for (auto&& it : defaultState->getFragmentTextureInfos())
	{
		UniformLocation loc;
		loc.shaderStage = ShaderStage::FRAGMENT;
		loc.location[1] = it.first;
		state->setTextureArray(loc, it.second.slot, it.second.textures);
	}
#else
	for (auto&& it : defaultState->getVertexTextureInfos())
	{
		backend::UniformLocation loc;
		loc.shaderStage = ShaderStage::VERTEX_AND_FRAGMENT;
		// location[0] is sampler index, location[1] is 0
		loc.location[0] = it.first;
		loc.location[1] = 0;
		state->setTextureArray(loc, it.second.slots, it.second.textures);
	}

	auto p = static_cast<backend::ProgramGFX*>(state->getProgram());
	CC_ASSERT(p);
	if (p)
	{
		auto dst = p->getState(state);
		CC_ASSERT(dst);
		dst->setAllBuffer(vertUniformBuffer, vertUniformBufferSize);
		auto src = p->getState(defaultState);
		CC_ASSERT(src);
		src->syncTextures(dst);
	}
#endif
}

void RenderMode::setUniform(const std::string& name, const void* data, size_t size)
{
	const auto it = locations.find(name);
	if (it != locations.end())
		defaultState->setUniform(it->second, data, size);
}

void RenderMode::setAllUniform(const std::string& name, const void* data, size_t size)
{
	for (auto& m : modeVector)
		m->setUniform(name, data, size);
}

RenderMode* RenderMode::getByName(const std::string& name)
{
	const auto it = modeMap.find(name);
	if (it != modeMap.end())
		return it->second;
	return nullptr;
}

RenderMode* RenderMode::getByID(size_t idx)
{
	if (0 < idx && idx <= modeVector.size())
		return modeVector[idx - 1];
	return getDefault();
}

size_t RenderMode::getIDByName(const std::string& name)
{
	const auto it = modeMap.find(name);
	if (it != modeMap.end())
		return it->second->getID();
	return 0;
}

std::vector<RenderMode*> RenderMode::listRenderModes()
{
	return modeVector;
}

void RenderMode::addMode(RenderMode* mode)
{
	if (!mode)
		return;
	const auto it = modeMap.find(mode->getName());
	if (it != modeMap.end())
	{
		modeVector[it->second->id - 1] = nullptr;
		XINFO("RenderMode '%s' is replaced", it->second->getName().c_str());
	}
	modeMap.insert(mode->getName(), mode);
	modeVector.push_back(mode);
	mode->id = modeVector.size();
}

void RenderMode::clearModes()
{
	modeVector.clear();
	modeMap.clear();
}
