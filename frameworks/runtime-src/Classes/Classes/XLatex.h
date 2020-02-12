#pragma once
#include "cocos2d.h"

namespace lstg
{
	class Latex : public cocos2d::Node
	{
		bool _init(const std::string& str,
			int width, float textSize, float lineSpace, const cocos2d::Color4B& color);
	public:
		static Latex* create(const std::string& str,
			int width, float textSize, float lineSpace,
			const cocos2d::Color4B& color = cocos2d::Color4B::BLACK);

		static void setDebug(bool b);

		float getWidth() const { return width; }
		float getHeight() const { return height; }
		float getDepth() const { return depth; }
		float getTextSize() const { return textSize; }
		float getBaseline() const { return baseline; }
		cocos2d::Rect getInsets() const { return insets; }
	private:
		//cocos2d::RenderTexture* rt = nullptr;
		cocos2d::Node* root = nullptr;
		cocos2d::DrawNode* drawNode = nullptr;
		float width = 0;
		float height = 0;
		float depth = 0;
		float textSize = 0;
		float baseline = 0;
		cocos2d::Rect insets;
	};	
}
