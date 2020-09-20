#include "RenderMode.h"
#include "Utility.h"
#include "UtilLua.h"
#include "LogSystem.h"
#include "../Classes/MemPoolManager.h"
#include "Renderer.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;
using namespace backend;

RenderMode RenderMode::_Default = {};
RenderMode* RenderMode::Default = &_Default;

std::vector<RenderMode*> RenderMode::modeVector;
Map<std::string, RenderMode*> RenderMode::modeMap;

static void GetDefaultVertexLayout(Program* state, VertexLayout* v)
{
	if(!state) return;
	v->setAttribute(ATTRIBUTE_NAME_POSITION,
		state->getAttributeLocation(POSITION),
		VertexFormat::FLOAT3,
		0,
		false);
	v->setAttribute(ATTRIBUTE_NAME_TEXCOORD,
		state->getAttributeLocation(TEXCOORD),
		VertexFormat::FLOAT2,
		offsetof(V3F_C4B_T2F, texCoords),
		false);
	v->setAttribute(ATTRIBUTE_NAME_COLOR,
		state->getAttributeLocation(COLOR),
		VertexFormat::UBYTE4,
		offsetof(V3F_C4B_T2F, colors),
		true);
	v->setLayout(sizeof(V3F_C4B_T2F));
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

RenderMode* RenderMode::create(const std::string& name, BlendOperation blendOp,
	BlendFactor blendFactorSrc, BlendFactor blendFactorDst, Program* program)
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
	return create(name, BlendOperation::ADD,
		BlendFactor::SRC_ALPHA, BlendFactor::ONE_MINUS_SRC_ALPHA, program);
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
	CC_SAFE_RELEASE(defaultState);
	defaultState = new ProgramState(_program);
	setVertexLayout(defaultState);
	defaultState->getFragmentUniformBuffer(&fragUniformBuffer, fragUniformBufferSize);
	defaultState->getVertexUniformBuffer(&vertUniformBuffer, vertUniformBufferSize);

	locations.clear();
	uniformNames.clear();
	auto infos = _program->getAllActiveUniformInfo(ShaderStage::VERTEX_AND_FRAGMENT);
	for (auto& it : infos)
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

void RenderMode::setTexture(const std::string& uniform, Texture2D* value)
{
	const auto it = locations.find(uniform);
	if (it != locations.end() && value)
		defaultState->setTexture(it->second, 0, value->getBackendTexture());
}

void RenderMode::setUniformBuffer(const std::string& buffer)
{
	if (buffer.size() != fragUniformBufferSize + vertUniformBufferSize)
		return;
	if (fragUniformBuffer)
		memcpy(fragUniformBuffer,
			buffer.c_str(), fragUniformBufferSize);
	if (vertUniformBuffer)
		memcpy(vertUniformBuffer,
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

bool RenderMode::init(const std::string& name, BlendOperation equation,
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
	desc.alphaBlendOperation = BlendOperation::ADD;
	desc.sourceAlphaBlendFactor = BlendFactor::ONE;
	desc.destinationAlphaBlendFactor = BlendFactor::ONE_MINUS_SRC_ALPHA;

	GetDefaultVertexLayout(program, &defaultLayout);
	setProgram(program);
	return true;
}

ProgramState* RenderMode::tempraryProgramState()
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
	assert(state);
	// VertexLayout is copyable
	*state->getVertexLayout() = defaultLayout;
}

void RenderMode::syncUniform(ProgramState* state)
{
	assert(state);
	char* fBuffer = nullptr;
	char* vBuffer = nullptr;
	size_t fSize = 0;
	size_t vSize = 0;
	state->getFragmentUniformBuffer(&fBuffer, fSize);
	state->getVertexUniformBuffer(&vBuffer, vSize);
	assert(fSize == fragUniformBufferSize && vSize == vertUniformBufferSize);
	if (fBuffer)
		memcpy(fBuffer, fragUniformBuffer, fragUniformBufferSize);
	if (vBuffer)
		memcpy(vBuffer, vertUniformBuffer, vertUniformBufferSize);
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
	return Default;
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
