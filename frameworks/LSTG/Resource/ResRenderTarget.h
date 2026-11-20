#pragma once
#include "ResBase.h"

namespace lstg {
	class ResFX;

	class ResRenderTarget :
		public Resource
	{
		cc::IntrusivePtr<cc::RenderTexture> target;
		cc::Color4B clearColor;
		bool autoResize;
		bool pushed = false;
		bool blendFix = false;
	public:
		bool isNeedBlendFix() const;
		void setNeedBlendFix(bool b);
		cc::Color4B getClearColor() const;
		void setClearColor(const cc::Color4B& color);

		cc::RenderTexture* getTarget();
		cc::Texture2D* getTexture();
		cc::IntrusivePtr<cc::Texture2D> copyTexture(bool flip = false);
		bool checkTarget();
		bool push();
		bool pop();
		bool render(ResFX* shader, RenderMode* blend);

		std::unordered_map<std::string, std::string> getInfo() const override;
		size_t getMemorySize() override;

		ResRenderTarget(const std::string& name, cc::IntrusivePtr<cc::RenderTexture> tex, bool autoResize = true);
		~ResRenderTarget() override;

		static cc::IntrusivePtr<ResRenderTarget> create(const std::string& name);
	};
}
