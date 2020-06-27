#include "Utility.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "LogSystem.h"
//#ifndef CC_USE_METAL
//#include "renderer/backend/opengl/ProgramGL.h"
//#else
//#include "glsl_optimizer.h"
//#endif

using namespace std;
using namespace lstg;
using namespace cocos2d;

static const char * COCOS2D_SHADER_UNIFORMS =
"uniform mat4 CC_PMatrix;\n"
"uniform mat4 CC_MultiViewPMatrix[4];\n"
"uniform mat4 CC_MVMatrix;\n"
"uniform mat4 CC_MVPMatrix;\n"
"uniform mat4 CC_MultiViewMVPMatrix[4];\n"
"uniform mat3 CC_NormalMatrix;\n"
"uniform vec4 CC_Time;\n"
"uniform vec4 CC_SinTime;\n"
"uniform vec4 CC_CosTime;\n"
"uniform vec4 CC_Random01;\n"
"uniform sampler2D CC_Texture0;\n"
"uniform sampler2D CC_Texture1;\n"
"uniform sampler2D CC_Texture2;\n"
"uniform sampler2D CC_Texture3;\n"
"//CC INCLUDES END\n\n";

#ifndef CC_USE_METAL
static string logForOpenGLShader(GLuint shader)
{
#if 0
	GLint logLength = 0;

	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength < 1)
		return "";

	char *logBytes = (char*)malloc(sizeof(char) * logLength);
	glGetShaderInfoLog(shader, logLength, nullptr, logBytes);
	string ret(logBytes);

	free(logBytes);
	return ret;
#else
	return "";
#endif
}
#endif

bool CheckShader(const string& src, bool isVertexShader)
{
#if 0
#ifndef CC_USE_METAL
	if (src.empty())
	{
		XERROR("source is empty");
		return false;
	}

	auto type = isVertexShader ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;

	GLuint shader;
	GLint status;
	//string convertedDefines;

	const GLchar *sources[] = {
		COCOS2D_SHADER_UNIFORMS,
		//convertedDefines.c_str(),
		src.c_str() };

	shader = glCreateShader(type);
	glShaderSource(shader, sizeof(sources) / sizeof(*sources), sources, nullptr);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (!status)
	{
		GLsizei length;
		glGetShaderiv(shader, GL_SHADER_SOURCE_LENGTH, &length);
		GLchar* _src = (GLchar *)malloc(sizeof(GLchar) * length);

		glGetShaderSource(shader, length, nullptr, _src);
		XERROR("failed to compile shader:\n%s", _src);
		XERROR("error info:\n%s", logForOpenGLShader(shader).c_str());
		free(_src);
		return false;
	}
	return true;
#else
	auto source = src;
	glslopt_ctx* ctx = glslopt_initialize(kGlslTargetMetal);
	glslopt_shader_type shaderType = isVertexShader ? kGlslOptShaderVertex : kGlslOptShaderFragment;
	glslopt_shader* glslShader = glslopt_optimize(ctx, shaderType, source.c_str(), 0);
	if (!glslShader)
	{
		XERROR("failed to translate GLSL shader to metal shader:\n%s", source.c_str());
		return false;
	}
	const char* metalShader = glslopt_get_output(glslShader);
	if (!metalShader)
	{
		XERROR("can not get metal shader:\n%s", source.c_str());
		glslopt_cleanup(ctx);
		return false;
	}
	return true;
#endif

#else
	return true;
#endif
}

bool util::CheckFragmentShader(const std::string& src)
{
	return CheckShader(src, false);
}

bool util::CheckVertexShader(const std::string& src)
{
	return CheckShader(src, true);
}

bool util::CheckBlendOperation(backend::BlendOperation equation)
{
	return equation <= backend::BlendOperation::RESERVE_SUBTRACT;
}

bool util::CheckBlendFactor(backend::BlendFactor func)
{
	return func <= backend::BlendFactor::BLEND_CLOLOR;
}
