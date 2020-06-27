#pragma once
#include "2d/CCLabel.h"

class XLabel : public cocos2d::Label
{
public:
	enum class LabelType {
		TTF,
		BMFONT,
		CHARMAP,
		STRING_TEXTURE
	};

	static XLabel* createWithBMFont(const std::string& bmfontPath, const std::string& text,
		const cocos2d::Vec2& imageOffset = cocos2d::Vec2::ZERO);

	static XLabel* createWithTTF(const cocos2d::TTFConfig& ttfConfig, const std::string& text,
		cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT, int maxLineWidth = 0);

	static XLabel* createWithSystemFont(const std::string& text, const std::string& font, float fontSize,
		const cocos2d::Size& dimensions = cocos2d::Size::ZERO,
		cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT,
		cocos2d::TextVAlignment vAlignment = cocos2d::TextVAlignment::TOP);

	XLabel(cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT,
		cocos2d::TextVAlignment vAlignment = cocos2d::TextVAlignment::TOP);
	~XLabel();

	void setBlendColor(const cocos2d::Color4B& color) { blendColor = color; }
	cocos2d::Color4B& getBlendColor() { return blendColor; }

	bool isItalics() const { return getRotationSkewX() == 12.0f; }
	bool isBold() const { return _boldEnabled; }
	bool isUnderlined() const { return (!!_underlineNode) && (!_strikethroughEnabled); }
	bool isStrikethrough()const { return _strikethroughEnabled; }

	LabelType getLabelType() const;

protected:
	std::vector<cocos2d::V3F_C4B_T2F_Quad> tempQuads;
	std::vector<std::shared_ptr<cocos2d::RenderCommand>> tempCommends;

	cocos2d::Color4B blendColor;
};
