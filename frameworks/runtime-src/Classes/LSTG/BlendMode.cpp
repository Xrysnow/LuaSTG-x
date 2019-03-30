#include "BlendMode.h"
#include "Utility.h"
#include "Global.h"
#include "UtilLua.h"
#include "LogSystem.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;

BlendMode BlendMode::_Default = { GL_FUNC_ADD ,{ GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA } };
BlendMode* BlendMode::Default = &_Default;

std::vector<BlendMode*> BlendMode::modeVector;
Map<std::string, BlendMode*> BlendMode::modeMap;

BlendMode* BlendMode::create(const std::string& name,
	GLuint equation, GLenum funcSrc, GLenum funcDst, GLProgram* glp)
{
	auto ret = new (std::nothrow) BlendMode();
	if (ret&&ret->init(name, equation, funcSrc, funcDst, glp))
	{
		ret->autorelease();
		addMode(ret);
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BlendMode* BlendMode::createByNames(const std::string& name,
	const std::string& equation, const std::string& funcSrc,
	const std::string& funcDst, const std::string& glp)
{
	auto ret = new (std::nothrow) BlendMode();
	if (ret&&ret->init(name, equation, funcSrc, funcDst, glp))
	{
		ret->autorelease();
		addMode(ret);
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BlendMode::BlendMode(): blendEquation(GL_FUNC_ADD), id(0)
{
	for (auto i = 0; i < FogMode::FogModeNum; ++i)
	{
		glProgram[i] = nullptr;
		glProgramState[i] = nullptr;
	}
}

BlendMode::BlendMode(GLuint equation, BlendFunc func)
: blendEquation(equation), blendFunc(func), id(0)
{
	for (int i = 0; i < 4; ++i)
	{
		glProgram[i] = nullptr;
		glProgramState[i] = nullptr;
	}
}

BlendMode::~BlendMode()
{
	XINFO("BlendMode named '%s' destructed", _name.c_str());
}

GLProgram* BlendMode::getGLProgram(FogMode mode)
{
	if (mode < 0 || mode >= FogMode::FogModeNum)
		return  glProgram[0];
	return glProgram[mode] ? glProgram[mode] : glProgram[0];
}

GLProgramState* BlendMode::getGLProgramState(FogMode mode)
{
	if (mode < 0 || mode >= FogMode::FogModeNum)
		return  glProgramState[0];
	return glProgramState[mode] ? glProgramState[mode] : glProgramState[0];
}

void BlendMode::setFogGLProgram(FogMode mode, GLProgram* glp)
{
	if (mode < 0 || mode >= FogMode::FogModeNum)
		return;
	glProgram[mode] = glp;
	glProgramState[mode] = GLProgramState::getOrCreateWithGLProgram(glp);
}

bool BlendMode::init(const std::string& name, GLuint equation, GLenum funcSrc, GLenum funcDst,
	GLProgram* glp)
{
	if (!glp)return false;
	const auto state = GLProgramState::getOrCreateWithGLProgram(glp);
	if (!state)return false;
	if (!util::CheckBlendEquation(equation))return false;
	if (!util::CheckBlendFunc(funcSrc))return false;
	if (!util::CheckBlendFunc(funcDst))return false;
	_name = name;
	blendEquation = equation;
	blendFunc.src = funcSrc;
	blendFunc.dst = funcDst;
	glProgram[0] = glp;
	glProgramState[0] = state;
	for (auto i = 1; i < FogMode::FogModeNum; ++i)
	{
		glProgram[i] = nullptr;
		glProgramState[i] = nullptr;
	}
	return true;
}

bool BlendMode::init(const std::string& name, const std::string& equation, const std::string& funcSrc,
	const std::string& funcDst, GLProgram* glp)
{
	GLuint eq, src, dst;
	if (!util::glMacroFromString(equation, eq) ||
		!util::glMacroFromString(funcSrc, src) ||
		!util::glMacroFromString(funcDst, dst))
		return false;
	return init(name, eq, src, dst, glp);
}

bool BlendMode::init(const std::string& name, const std::string& equation, const std::string& funcSrc,
	const std::string& funcDst, const std::string& glp)
{
	const auto p = GLProgramCache::getInstance()->getGLProgram(glp);
	if (!p)
		return false;
	return init(name, equation, funcSrc, funcDst, p);
}

BlendMode* BlendMode::getByName(const char* name)
{
	const auto it = modeMap.find(name);
	if (it != modeMap.end())
		return it->second;
	return nullptr;
	//return Default;
}

BlendMode* BlendMode::getByID(size_t idx)
{
	if (0 < idx && idx <= modeVector.size())
		return modeVector[idx - 1];
	return Default;
}

size_t BlendMode::getIDByName(const char* name)
{
	const auto it = modeMap.find(name);
	if (it != modeMap.end())
		return it->second->getID();
	return 0;
}

void BlendMode::setGLProgram(GLProgram* p0, GLProgram* p1, GLProgram* p2, GLProgram* p3)
{
	glProgram[0] = p0;
	glProgram[1] = p1;
	glProgram[2] = p2;
	glProgram[3] = p3;
	glProgramState[0] = GLProgramState::getOrCreateWithGLProgram(p0);
	glProgramState[1] = GLProgramState::getOrCreateWithGLProgram(p1);
	glProgramState[2] = GLProgramState::getOrCreateWithGLProgram(p2);
	glProgramState[3] = GLProgramState::getOrCreateWithGLProgram(p3);
}

void BlendMode::addMode(BlendMode* mode)
{
	if (!mode)
		return;
	const auto it = modeMap.find(mode->getName());
	if (it != modeMap.end())
	{
		//if (it->second == Default)
		//	Default = &_Default;
		modeVector[it->second->id - 1] = nullptr;
		XINFO("BlendMode named '%s' is replaced", it->second->getName().c_str());
	}
	modeMap.insert(mode->getName(), mode);
	modeVector.push_back(mode);
	mode->id = modeVector.size();
}

size_t BlendMode::addMode(BlendMode* mode, const char* name)
{
	modeMap.insert(name, mode);
	modeVector.push_back(mode);
	const auto idx = modeVector.size() - 1;
	return idx;
}
