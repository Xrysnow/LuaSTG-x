#pragma once
#include "ResBase.h"
#include "Global.h"

namespace lstg {
	class ResFX :
		public Resource
	{
	private:
		cocos2d::GLProgram* program;
		cocos2d::GLProgramState* state;

		std::unordered_map<std::string, GLint> uniforms;
		static std::vector<std::string> predefined_uniform;
	public:
		cocos2d::GLProgram* getProgram() const noexcept { return program; }
		cocos2d::GLProgramState* getProgramState() const noexcept { return state; }

		//void SetPostEffectTexture(Texture2D* val)noexcept;
		void setViewport(cocos2d::Rect rect)noexcept;
		void setScreenSize(cocos2d::Vec2 size)noexcept;

		void setValue(const char* key, float val)noexcept;
		void setColor(const char* key, cocos2d::Color4B val)noexcept;
		void setTexture(const char* key, cocos2d::Texture2D* val)noexcept;

		std::string getInfo()const override;
	public:
		ResFX(const std::string& name, cocos2d::GLProgram* program);
		~ResFX();

		static ResFX* create(const std::string& name, const std::string& vsPath, const std::string& fsPath);
		static ResFX* createWithGLProgram(const std::string& name, cocos2d::GLProgram* glProgram);
		static ResFX* createWithString(const std::string& name, const std::string& vShader, const std::string& fShader);
	};
}
