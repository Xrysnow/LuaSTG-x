#include "Utility.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "LogSystem.h"

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

static string logForOpenGLShader(GLuint shader)
{
	GLint logLength = 0;

	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength < 1)
		return "";

	char *logBytes = (char*)malloc(sizeof(char) * logLength);
	glGetShaderInfoLog(shader, logLength, nullptr, logBytes);
	string ret(logBytes);

	free(logBytes);
	return ret;
}

bool CheckShader(const string& src, bool isVertexShader)
{
	if (src.empty())
	{
		XERROR("source is empty");
		return false;
	}

	auto type = isVertexShader ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;

	GLuint shader;
	GLint status;

	string headersDef;
	string convertedDefines;
#if CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
	headersDef = (type == GL_VERTEX_SHADER ? "precision mediump float;\n precision mediump int;\n" : "precision mediump float;\n precision mediump int;\n");
#elif (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32 && CC_TARGET_PLATFORM != CC_PLATFORM_LINUX && CC_TARGET_PLATFORM != CC_PLATFORM_MAC)
	headersDef = (type == GL_VERTEX_SHADER ? "precision highp float;\n precision highp int;\n" : "precision mediump float;\n precision mediump int;\n");
#endif

	const GLchar *sources[] = {
		headersDef.c_str(),
		COCOS2D_SHADER_UNIFORMS,
		convertedDefines.c_str(),
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
		XERROR("failed to compile shader:\n%m", _src);
		XERROR("error info:\n%m", logForOpenGLShader(shader).c_str());
		free(_src);
		return false;
	}
	return true;
}

bool util::CheckFragmentShader(const std::string& src)
{
	return CheckShader(src, false);
}

bool util::CheckVertexShader(const std::string& src)
{
	return CheckShader(src, true);
}

std::unordered_set<GLuint> _BlendEquation = {
	GL_FUNC_ADD,
	GL_FUNC_SUBTRACT,
	GL_FUNC_REVERSE_SUBTRACT,
#ifdef GL_MIN
	GL_MIN,
#endif
#ifdef GL_MAX
	GL_MAX
#endif
};
bool util::CheckBlendEquation(GLuint equation)
{
	return _BlendEquation.find(equation) != _BlendEquation.end();
}

std::unordered_set<GLenum> _BlendFunc = {
	GL_ZERO,
	GL_ONE,
	GL_SRC_COLOR,
	GL_ONE_MINUS_SRC_COLOR,
	GL_DST_COLOR,
	GL_ONE_MINUS_DST_COLOR,
	GL_SRC_ALPHA,
	GL_ONE_MINUS_SRC_ALPHA,
	GL_DST_ALPHA,
	GL_ONE_MINUS_DST_ALPHA,
	GL_CONSTANT_COLOR,
	GL_ONE_MINUS_CONSTANT_COLOR,
	GL_CONSTANT_ALPHA,
	GL_ONE_MINUS_CONSTANT_ALPHA,
	GL_SRC_ALPHA_SATURATE
};
bool util::CheckBlendFunc(GLenum func)
{
	return _BlendFunc.find(func) != _BlendFunc.end();
}
