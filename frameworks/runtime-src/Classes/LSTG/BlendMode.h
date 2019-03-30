#pragma once
#include "base/ccTypes.h"
#include "renderer/CCGLProgram.h"
#include <renderer/CCGLProgramState.h>
#include "Dictionary.hpp"

namespace lstg
{
	enum FogMode
	{
		None,
		Liner,
		Exp1,
		Exp2,
		FogModeNum
	};
	//TODO: Move this
	struct FogParam
	{
		float start = 0.f;
		float end = 0.f;
		float density = 0.f;
		cocos2d::Color4F color = cocos2d::Color4F(1.f, 1.f, 1.f, 1.f);
	};

	/** BlendMode TODO: setAsDefault
	 */
	class BlendMode : public cocos2d::Ref
	{
	public:
		GLuint blendEquation;
		cocos2d::BlendFunc blendFunc;
	private:
		std::string _name;
		size_t id;
	public:

		static BlendMode* create(const std::string& name,
			GLuint equation, GLenum funcSrc,
			GLenum funcDst, cocos2d::GLProgram* glp);
		static BlendMode* createByNames(const std::string& name,
			const std::string& equation, const std::string& funcSrc,
			const std::string& funcDst, const std::string& glp);

		BlendMode();
		BlendMode(GLuint blendEquation, cocos2d::BlendFunc blendFunc);
		~BlendMode();

		std::string getName() const { return _name; }
		size_t getID() const { return id; }
		cocos2d::GLProgram* getGLProgram(FogMode mode = None);
		cocos2d::GLProgramState* getGLProgramState(FogMode mode = None);

		void setFogGLProgram(FogMode mode, cocos2d::GLProgram* glp);
	protected:

		bool init(const std::string& name,
			GLuint equation, GLenum funcSrc,
			GLenum funcDst, cocos2d::GLProgram* glp);
		bool init(const std::string& name,
			const std::string& equation, const std::string& funcSrc,
			const std::string& funcDst, cocos2d::GLProgram* glp);
		bool init(const std::string& name,
			const std::string& equation, const std::string& funcSrc,
			const std::string& funcDst, const std::string& glp);

		void setGLProgram(
			cocos2d::GLProgram* p0, cocos2d::GLProgram* p1,
			cocos2d::GLProgram* p2, cocos2d::GLProgram* p3);
		cocos2d::GLProgram* glProgram[FogMode::FogModeNum] = {};
		cocos2d::GLProgramState* glProgramState[FogMode::FogModeNum] = {};

		static void addMode(BlendMode* mode);
		static size_t addMode(BlendMode* mode, const char* name);
	public:
		static BlendMode* Default;

		static BlendMode* getByName(const char* name);
		static BlendMode* getByID(size_t idx);
		static size_t getIDByName(const char* name);

	protected:
		static BlendMode _Default;

		static std::vector<BlendMode*> modeVector;
		static cocos2d::Map<std::string, BlendMode*> modeMap;
	};
}
