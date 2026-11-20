#pragma once
#include "cocos2d.h"

namespace lstg
{
	class Latex : public cc::Node
	{
		bool _init(const std::string& str,
			int width, float textSize, float lineSpace, const cc::Color4B& color);
	public:
		static cc::IntrusivePtr<Latex> create(const std::string& str,
			int width, float textSize, float lineSpace,
			const cc::Color4B& color = cc::Color4B::BLACK);

		static void setDebug(bool b);

		float getWidth() const { return width; }
		float getHeight() const { return height; }
		float getDepth() const { return depth; }
		float getTextSize() const { return textSize; }
		float getBaseline() const { return baseline; }
		cc::Rect getInsets() const { return insets; }
	private:
		//cocos2d::RenderTexture* rt = nullptr;
		cc::Node* root = nullptr;
		cc::DrawNode* drawNode = nullptr;
		float width = 0;
		float height = 0;
		float depth = 0;
		float textSize = 0;
		float baseline = 0;
		cc::Rect insets;
	};	
}
