#include "ResFX.h"
#include "AppFrame.h"
#include "UtilLua.h"
#include "Utility.h"
#include "ResourceMgr.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

class XGLProgramState : public GLProgramState
{
public:
	static XGLProgramState* create(GLProgram* glprogram)
	{
		auto ret = new (std::nothrow) XGLProgramState();
		if (ret && ret->init(glprogram))
		{
			ret->autorelease();
			return ret;
		}
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
	unordered_map<string, GLint> getUniformsByName() const { return _uniformsByName; }
};

vector<string> ResFX::predefined_uniform = {
	"POSTEFFECTTEXTURE",
	"VIEWPORT",
	"SCREENSIZE"
};

ResFX::ResFX(const std::string& name, GLProgram* program_)
	: Resource(ResourceType::FX, name), program(program_), state(nullptr)
{
	CC_ASSERT(program);
	if (program)
	{
		program->retain();
		// state is cached in GLProgramStateCache, no need to retain
		state = GLProgramState::getOrCreateWithGLProgram(program);
		uniforms = XGLProgramState::create(program)->getUniformsByName();
	}
}

ResFX::~ResFX()
{
	if (program)
	{
		program->release();
	}
}

void ResFX::setViewport(Rect rect)noexcept
{
	auto i = uniforms.find("VIEWPORT");
	if (i != uniforms.end() && state)
		state->setUniformVec4(i->second,
			Vec4(rect.origin.x, rect.origin.y, rect.getMaxX(), rect.getMaxY()));
}

void ResFX::setScreenSize(Vec2 size)noexcept
{
	auto i = uniforms.find("SCREENSIZE");
	if (i != uniforms.end() && state)
		state->setUniformVec4(i->second,
			Vec4(0, 0, size.x, size.y));
}

void ResFX::setValue(const char* key, float val)noexcept
{
	auto i = uniforms.find(key);
	if (i != uniforms.end() && state)
	{
		state->setUniformFloat(i->second, val);
	}
}

void ResFX::setColor(const char* key, Color4B val)noexcept
{
	auto i = uniforms.find(key);
	if (i != uniforms.end() && state)
	{
		state->setUniformVec4(i->second,
			Vec4(val.r / 255.f, val.g / 255.f, val.b / 255.f, val.a / 255.f));
	}
}

void ResFX::setTexture(const char* key, Texture2D* val)noexcept
{
	auto i = uniforms.find(key);
	if (i != uniforms.end() && state && val)
	{
		//TODO: check
		state->setUniformTexture(i->second, val);
	}
}

string ResFX::getInfo() const
{
	auto ret = Resource::getInfo();
	if (state)
	{
		ret += " | "+ StringUtils::format(
			"UniformCount = %d, VertexAttribCount = %d",
			state->getUniformCount(), state->getVertexAttribCount());
		if (!uniforms.empty())
		{
			ret += " | Uniforms:";
		}
		for (auto u : uniforms)
		{
			ret += " [" + u.first + "]";
		}
	}
	return ret;
}

ResFX* ResFX::create(const std::string& name, const std::string& vsPath, const std::string& fsPath)
{
	const auto vs = LRES.getStringFromFile(vsPath);
	const auto fs = LRES.getStringFromFile(fsPath);
	if (vs.empty() && fs.empty())
		return nullptr;
	const auto glProgram = util::CreateGLProgramFromString(vs, fs);
	if (!glProgram)
		return nullptr;
	auto ret = createWithGLProgram(name, glProgram);
	if (ret)
		ret->resPath = fsPath;
	return ret;
}

ResFX* ResFX::createWithGLProgram(const std::string& name, cocos2d::GLProgram* glProgram)
{
	return new (nothrow) ResFX(name, glProgram);
}

ResFX* ResFX::createWithString(const std::string& name, const std::string& vShader, const std::string& fShader)
{
	const auto glProgram = util::CreateGLProgramFromString(
		vShader, fShader);
	if (!glProgram)
		return nullptr;
	return createWithGLProgram(name, glProgram);
}
