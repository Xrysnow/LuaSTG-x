#pragma once
#include "ResBase.h"

namespace lstg {
	class ResFX :
		public Resource
	{
		cc::IntrusivePtr<cc::backend::Program> program;
		cc::IntrusivePtr<cc::backend::ProgramState> state;
		RenderMode* renderMode = nullptr;
		std::unordered_map<std::string, cc::backend::UniformLocation> uniforms;
		ResFX(const std::string& name, RenderMode* m);
		~ResFX() override;
		void setUniform(const std::string& name, const void* data, size_t size);
	public:
		RenderMode* getRenderMode() const { return renderMode; }
		cc::backend::Program* getProgram() const { return program; }
		cc::backend::ProgramState* getProgramState() const { return state; }
		std::vector<std::string> getUniformNames() const;

		void setViewport(const cc::Viewport& vp);
		void setScreenSize(const cc::Vec2& size);

		void setFloat(const std::string& uniform, float value);
		void setVec2(const std::string& uniform, const cc::Vec2& value);
		void setVec3(const std::string& uniform, const cc::Vec3& value);
		void setVec4(const std::string& uniform, const cc::Vec4& value);
		void setMat4(const std::string& uniform, const cc::Mat4& value);
		void setColor(const std::string& uniform, const cc::Color4B& value);
		void setTexture(const std::string& uniform, cc::Texture2D* value, uint32_t slot = 0);

		std::unordered_map<std::string, std::string> getInfo() const override;
		size_t getMemorySize() override;

		static cc::IntrusivePtr<ResFX> create(const std::string& name,
			const std::string& vsPath, const std::string& fsPath);
		static cc::IntrusivePtr<ResFX> createWithString(const std::string& name,
			const std::string& vShader, const std::string& fShader);
		static cc::IntrusivePtr<ResFX> createWithProgram(const std::string& name,
			cc::IntrusivePtr<cc::backend::Program> program);
	};
}
