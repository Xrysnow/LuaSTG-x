#pragma once
#include "2d/CCLabel.h"

/**
 * \brief 继承Label类，实现重复绘制(仅BMF)
 * 
 * 重复绘制必须在 beginDraw 和 endDraw之间调用 visit\n
 * not used right now
 */
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
		const cocos2d::TextHAlignment& hAlignment = cocos2d::TextHAlignment::LEFT, int maxLineWidth = 0,
		const cocos2d::Vec2& imageOffset = cocos2d::Vec2::ZERO);

	static XLabel* createWithTTF(const cocos2d::TTFConfig& ttfConfig, const std::string& text,
		cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT, int maxLineWidth = 0);

	static XLabel* createWithSystemFont(const std::string& text, const std::string& font, float fontSize,
		const cocos2d::Size& dimensions = cocos2d::Size::ZERO, cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT, cocos2d::TextVAlignment vAlignment = cocos2d::TextVAlignment::TOP);

	XLabel(cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT,
		cocos2d::TextVAlignment vAlignment = cocos2d::TextVAlignment::TOP);
	~XLabel();

	void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;

	void beginDraw();
	void endDraw();
	// 强制设置纹理字体的颜色，设置为白色则不会起作用
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
