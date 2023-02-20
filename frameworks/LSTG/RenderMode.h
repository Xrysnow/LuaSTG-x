#pragma once
#include "cocos2d.h"

namespace lstg
{
	class RenderMode : public cocos2d::Ref
	{
		RenderMode();
		~RenderMode();
	public:
		static RenderMode* create(const std::string& name,
			cocos2d::backend::BlendOperation blendOp,
			cocos2d::backend::BlendFactor blendFactorSrc,
			cocos2d::backend::BlendFactor blendFactorDst,
			cocos2d::backend::Program* program);
		static RenderMode* create(const std::string& name,
			cocos2d::backend::Program* program);

		std::string getName() const { return _name; }
		size_t getID() const { return id; }
		cocos2d::BlendFunc getBlendFunc() const;
		cocos2d::backend::BlendDescriptor getBlendDescriptor() const { return desc; }
		std::vector<std::string> getUniformNames() const { return uniformNames; }

		void setProgram(cocos2d::backend::Program* program);
		cocos2d::backend::Program* getProgram() const;
		cocos2d::backend::ProgramState* getDefaultProgramState() const;
		cocos2d::backend::ProgramState* newProgramState();

		// uniform setter

		void setFloat(const std::string& uniform, float value);
		void setVec2(const std::string& uniform, const cocos2d::Vec2& value);
		void setVec3(const std::string& uniform, const cocos2d::Vec3& value);
		void setVec4(const std::string& uniform, const cocos2d::Vec4& value);
		void setMat4(const std::string& uniform, const cocos2d::Mat4& value);
		void setColor(const std::string& uniform, const cocos2d::Color4B& value);
		void setTexture(const std::string& uniform, cocos2d::Texture2D* value, uint32_t slot = 0);

		void setUniformBuffer(const std::string& buffer);
		std::string getUniformBuffer() const;
		RenderMode* clone(const std::string& newName);

	protected:
		bool init(const std::string& name,
		    cocos2d::backend::BlendOperation equation,
			cocos2d::backend::BlendFactor funcSrc,
			cocos2d::backend::BlendFactor funcDst,
			cocos2d::backend::Program* program);
		cocos2d::backend::ProgramState* tempraryProgramState();
		void setVertexLayout(cocos2d::backend::ProgramState* state) const;
		void syncUniform(cocos2d::backend::ProgramState* state);
		void setUniform(const std::string& name, const void* data, size_t size);
		static void setAllUniform(const std::string& name, const void* data, size_t size);

		std::string _name;
		size_t id = 0;
		cocos2d::backend::BlendDescriptor desc;
		cocos2d::backend::Program* _program = nullptr;
		cocos2d::backend::ProgramState* defaultState = nullptr;
		char* fragUniformBuffer = nullptr;
		char* vertUniformBuffer = nullptr;
		size_t fragUniformBufferSize = 0;
		size_t vertUniformBufferSize = 0;
		cocos2d::backend::VertexLayout defaultLayout;
		std::unordered_map<std::string, cocos2d::backend::UniformLocation> locations;
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
		static cocos2d::Map<std::string, RenderMode*> modeMap;

		friend class XRenderer;
		friend class XTrianglesCommand;
		friend class ComponentManager;
		friend class AppFrame;
	};
}
