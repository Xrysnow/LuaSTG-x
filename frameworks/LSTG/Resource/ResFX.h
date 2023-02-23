#pragma once
#include "ResBase.h"

namespace lstg {
	class ResFX :
		public Resource
	{
		cocos2d::backend::Program* program = nullptr;
		cocos2d::backend::ProgramState* state = nullptr;
		RenderMode* renderMode = nullptr;
		std::unordered_map<std::string, cocos2d::backend::UniformLocation> uniforms;
		ResFX(const std::string& name, RenderMode* m);
		~ResFX();
		void setUniform(const std::string& name, const void* data, size_t size);
	public:
		RenderMode* getRenderMode() const { return renderMode; }
		cocos2d::backend::Program* getProgram() const { return program; }
		cocos2d::backend::ProgramState* getProgramState() const { return state; }
		std::vector<std::string> getUniformNames() const;

		void setViewport(const cocos2d::Viewport& vp);
		void setScreenSize(const cocos2d::Vec2& size);

		void setFloat(const std::string& uniform, float value);
		void setVec2(const std::string& uniform, const cocos2d::Vec2& value);
		void setVec3(const std::string& uniform, const cocos2d::Vec3& value);
		void setVec4(const std::string& uniform, const cocos2d::Vec4& value);
		void setMat4(const std::string& uniform, const cocos2d::Mat4& value);
		void setColor(const std::string& uniform, const cocos2d::Color4B& value);
		void setTexture(const std::string& uniform, cocos2d::Texture2D* value, uint32_t slot = 0);

		std::unordered_map<std::string, std::string> getInfo() const override;
		size_t getMemorySize() override;

		static ResFX* create(const std::string& name,
			const std::string& vsPath, const std::string& fsPath);
		static ResFX* createWithString(const std::string& name,
			const std::string& vShader, const std::string& fShader);
		static ResFX* createWithProgram(const std::string& name,
			cocos2d::backend::Program* program);
	};
}
