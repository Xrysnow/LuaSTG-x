#pragma once
#include "ResBase.h"

namespace lstg {
	class ResFX;

	class ResRenderTarget :
		public Resource
	{
	private:
		cocos2d::RenderTexture* target = nullptr;
		bool autoResize;
		bool pushed = false;
		bool blendFix = false;
		cocos2d::Color4B clearColor;
	public:
		bool isNeedBlendFix() const;
		void setNeedBlendFix(bool b);
		cocos2d::Color4B getClearColor() const;
		void setClearColor(const cocos2d::Color4B& color);

		cocos2d::RenderTexture* getTarget();
		cocos2d::Texture2D* getTexture();
		cocos2d::Texture2D* copyTexture();
		bool checkTarget();
		bool push();
		bool pop();
		bool render(ResFX* shader, BlendMode* blend);

		std::string getInfo() const override;

		ResRenderTarget(const std::string& name, cocos2d::RenderTexture* tex, bool autoResize = true);
		~ResRenderTarget();

		static ResRenderTarget* create(const std::string& name);
	};
}
