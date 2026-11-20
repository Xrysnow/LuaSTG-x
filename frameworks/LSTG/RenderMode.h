#pragma once
#include "cocos2d.h"

namespace lstg
{
	class RenderMode : public cc::Ref
	{
		RenderMode();
		~RenderMode();
	public:
		static cc::IntrusivePtr<RenderMode> create(const std::string& name,
			cc::backend::BlendOperation blendOp,
			cc::backend::BlendFactor blendFactorSrc,
			cc::backend::BlendFactor blendFactorDst,
			cc::IntrusivePtr<cc::backend::Program> program);
		static cc::IntrusivePtr<RenderMode> create(const std::string& name,
			cc::IntrusivePtr<cc::backend::Program> program);

		std::string getName() const { return _name; }
		size_t getID() const { return id; }
		cc::BlendFunc getBlendFunc() const;
		cc::backend::BlendDescriptor getBlendDescriptor() const { return desc; }
		std::vector<std::string> getUniformNames() const { return uniformNames; }

		void setProgram(cc::IntrusivePtr<cc::backend::Program> program);
		cc::backend::Program* getProgram() const;
		cc::backend::ProgramState* getDefaultProgramState() const;
		cc::IntrusivePtr<cc::backend::ProgramState> newProgramState();

		// uniform setter

		void setFloat(const std::string& uniform, float value);
		void setVec2(const std::string& uniform, const cc::Vec2& value);
		void setVec3(const std::string& uniform, const cc::Vec3& value);
		void setVec4(const std::string& uniform, const cc::Vec4& value);
		void setMat4(const std::string& uniform, const cc::Mat4& value);
		void setColor(const std::string& uniform, const cc::Color4B& value);
		void setTexture(const std::string& uniform, cc::Texture2D* value, uint32_t slot = 0);

		void setUniformBuffer(const std::string& buffer);
		std::string getUniformBuffer() const;
		cc::IntrusivePtr<RenderMode> clone(const std::string& newName);

	protected:
		bool init(const std::string& name,
		    cc::backend::BlendOperation equation,
			cc::backend::BlendFactor funcSrc,
			cc::backend::BlendFactor funcDst,
			cc::IntrusivePtr<cc::backend::Program> program);
		cc::backend::ProgramState* tempraryProgramState();
		void syncUniform(cc::backend::ProgramState* state);
		void setUniform(const std::string& name, const void* data, size_t size);
		static void setAllUniform(const std::string& name, const void* data, size_t size);

		std::string _name;
		size_t id = 0;
		cc::backend::BlendDescriptor desc;
		cc::IntrusivePtr<cc::backend::Program> _program;
		cc::IntrusivePtr<cc::backend::ProgramState> defaultState;
		char* fragUniformBuffer = nullptr;
		char* vertUniformBuffer = nullptr;
		size_t fragUniformBufferSize = 0;
		size_t vertUniformBufferSize = 0;
		std::unordered_map<std::string, cc::backend::UniformLocation> locations;
		std::vector<std::string> uniformNames;
		std::shared_ptr<void> pool = nullptr;

	public:
		static RenderMode* getDefault();
		static RenderMode* getByName(const std::string& name);
		static RenderMode* getByID(size_t idx);
		static size_t getIDByName(const std::string& name);
		static std::vector<RenderMode*> listRenderModes();

	protected:
		static void addMode(RenderMode* mode);
		static void clearModes();
		static void destructDefault();

		static std::vector<RenderMode*> modeVector;
		static cc::Map<std::string, RenderMode*> modeMap;

		friend class XRenderer;
		friend class XTrianglesCommand;
		friend class ComponentManager;
		friend class AppFrame;
	};
}
