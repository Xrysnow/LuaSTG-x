#include "ResFX.h"
#include "AppFrame.h"
#include "Util/UtilLua.h"
#include "Util/Utility.h"
#include "ResourceMgr.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

//static const std::string Uniform_PosteffectTexture = "POSTEFFECTTEXTURE";
static const std::string Uniform_Viewport = "VIEWPORT";
static const std::string Uniform_ScreenSize = "SCREENSIZE";

ResFX::ResFX(const std::string& name, RenderMode* m)
	: Resource(ResourceType::FX, name)
{
	renderMode = m;
	renderMode->retain();
	program = renderMode->getProgram();
	// ShaderStage::VERTEX_AND_FRAGMENT is not valid for metal
	for (const auto& it : program->getAllActiveUniformInfo(backend::ShaderStage::FRAGMENT))
		uniforms[it.first] = program->getUniformLocation(it.first);
	for (const auto& it : program->getAllActiveUniformInfo(backend::ShaderStage::VERTEX))
		uniforms[it.first] = program->getUniformLocation(it.first);
	state = renderMode->getDefaultProgramState();
}

ResFX::~ResFX()
{
	renderMode->release();
}

void ResFX::setUniform(const std::string& name, const void* data, size_t size)
{
	const auto i = uniforms.find(name);
	if (i != uniforms.end())
		state->setUniform(i->second, data, size);
}

std::vector<std::string> ResFX::getUniformNames() const
{
	return renderMode->getUniformNames();
}

void ResFX::setViewport(const Viewport& vp)
{
	renderMode->setVec4(Uniform_Viewport,
		{ float(vp.x), float(vp.y), float(vp.w + vp.x), float(vp.h + vp.y) });
}

void ResFX::setScreenSize(const Vec2& size)
{
	renderMode->setVec4(Uniform_ScreenSize,
		{ 0, 0, size.x, size.y });
}

void ResFX::setFloat(const std::string& uniform, float value)
{
	renderMode->setFloat(uniform, value);
}

void ResFX::setVec2(const std::string& uniform, const Vec2& value)
{
	renderMode->setVec2(uniform, value);
}

void ResFX::setVec3(const std::string& uniform, const Vec3& value)
{
	renderMode->setVec3(uniform, value);
}

void ResFX::setVec4(const std::string& uniform, const Vec4& value)
{
	renderMode->setVec4(uniform, value);
}

void ResFX::setMat4(const std::string& uniform, const Mat4& value)
{
	renderMode->setMat4(uniform, value);
}

void ResFX::setColor(const std::string& uniform, const Color4B& value)
{
	renderMode->setColor(uniform, value);
}

void ResFX::setTexture(const std::string& uniform, Texture2D* value, uint32_t slot)
{
	renderMode->setTexture(uniform, value, slot);
}

std::unordered_map<std::string, std::string> ResFX::getInfo() const
{
	auto ret = Resource::getInfo();
	ret["n_uniform"] = to_string(uniforms.size());
	ret["n_attribute"] = to_string(program->getActiveAttributes().size());
	return ret;
}

size_t ResFX::getMemorySize()
{
	size_t total = sizeof(ResFX) + resName.size() + resPath.size();
	for (auto&& it : uniforms)
		total += it.first.size() + sizeof(backend::UniformLocation);
	return total;
}

ResFX* ResFX::create(const std::string& name,
                     const std::string& vsPath, const std::string& fsPath)
{
	const auto vs = LRES.getStringFromFile(vsPath);
	const auto fs = LRES.getStringFromFile(fsPath);
	if (vs.empty() && fs.empty())
		return nullptr;
	const auto program = util::CreateProgramFromString(vs, fs);
	if (!program)
		return nullptr;
	auto ret = createWithProgram(name, program);
	if (ret)
		ret->resPath = fsPath;
	return ret;
}

ResFX* ResFX::createWithString(const std::string& name,
	const std::string& vShader, const std::string& fShader)
{
	const auto program =
		util::CreateProgramFromString(vShader, fShader);
	if (!program)
		return nullptr;
	return createWithProgram(name, program);
}

ResFX* ResFX::createWithProgram(const std::string& name, backend::Program* program)
{
	if (!program)
		return nullptr;
	const auto m = RenderMode::create(name, program);
	if (!m)
		return nullptr;
	return new (nothrow) ResFX(name, m);
}
