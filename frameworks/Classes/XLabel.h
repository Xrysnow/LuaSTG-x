#pragma once
#include "2d/Label.h"

class XLabel : public cc::Label
{
public:
	enum class LabelType {
		TTF,
		BMFONT,
		CHARMAP,
		STRING_TEXTURE
	};

	static cc::IntrusivePtr<XLabel> createWithBMFont(const std::string& bmfontPath, const std::string& text,
		const cc::Vec2& imageOffset = cc::Vec2::ZERO);

	static cc::IntrusivePtr<XLabel> createWithTTF(const cc::TTFConfig& ttfConfig, const std::string& text,
		cc::TextHAlignment hAlignment = cc::TextHAlignment::LEFT, int maxLineWidth = 0);

	static cc::IntrusivePtr<XLabel> createWithSystemFont(const std::string& text, const std::string& font, float fontSize,
		const cc::Size& dimensions = cc::Size::ZERO,
		cc::TextHAlignment hAlignment = cc::TextHAlignment::LEFT,
		cc::TextVAlignment vAlignment = cc::TextVAlignment::TOP);

	XLabel(cc::TextHAlignment hAlignment = cc::TextHAlignment::LEFT,
		cc::TextVAlignment vAlignment = cc::TextVAlignment::TOP);
	~XLabel() override;

	void setBlendColor(const cc::Color4B& color) { blendColor = color; }
	cc::Color4B& getBlendColor() { return blendColor; }

	bool isItalics() const { return getRotationSkewX() == 12.0f; }
	bool isBold() const { return _boldEnabled; }
	bool isUnderlined() const { return (!!_underlineNode) && (!_strikethroughEnabled); }
	bool isStrikethrough()const { return _strikethroughEnabled; }

	LabelType getLabelType() const;

protected:
	XLabel(cc::FontRasterMode mode, cc::TextHAlignment hAlignment, cc::TextVAlignment vAlignment);

	std::vector<cc::V3F_C4B_T2F_Quad> tempQuads;
	std::vector<std::shared_ptr<cc::RenderCommand>> tempCommends;

	cc::Color4B blendColor;
};
