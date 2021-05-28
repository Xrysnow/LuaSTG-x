#pragma once
#include "ResBase.h"
#include "../Classes/XLabel.h"
#include "RenderMode.h"

namespace lstg {
	class ResFont :
		public Resource
	{
	public:
		enum class LabelType {
			TTF,
			BMFONT,
			CHARMAP,
			SYSTEM
		};
		struct GlyphInfo
		{
			cocos2d::Rect GlyphPos;    // glyph uv coords in texture
			cocos2d::Vec2 GlyphSize;   // glyph size
			cocos2d::Vec2 BrushPos;    // brush position (to left-top)
			cocos2d::Vec2 Advance;     // brush advance (pixel)
		};
	private:
		RenderMode* renderMode = RenderMode::getDefault();
		cocos2d::Color4B textColor = cocos2d::Color4B::WHITE;
		cocos2d::Color4B outlineColor = cocos2d::Color4B(0, 0, 0, 0xFF);
		cocos2d::Color4B glowColor = cocos2d::Color4B::WHITE;

		XLabel* label;
		cocos2d::TTFConfig config;

		cocos2d::TextHAlignment h_alignment = cocos2d::TextHAlignment::LEFT;
		cocos2d::TextVAlignment v_alignment = cocos2d::TextVAlignment::TOP;
		LabelType labelType;

		bool _isOutlined = false;
		bool _isGlowed = false;
		bool _isShadowed = false;

	public:
		RenderMode* getRenderMode()const { return renderMode; }
		void setRenderMode(RenderMode* m);

		cocos2d::Color4B getColor() const { return textColor; }
		void setColor(const cocos2d::Color4B& c);
	// outline

		// only for system font and TTF
		void enableOutline(const cocos2d::Color4B& color, int size = -1);
		void disableOutline();
		void setOutlineSize(int size) { enableOutline(outlineColor, size); }
		void setOutlineColor(const cocos2d::Color4B& color) { enableOutline(color, config.outlineSize); }
		cocos2d::Color4B getOutlineColor() const { return outlineColor; }
		int getOutlineSize()const { return config.outlineSize; }
	// glow

		// only for TTF
		void enableGlow(const cocos2d::Color4B& color);
		void disableGlow();
		cocos2d::Color4B getGlowColor() const { return glowColor; }
	// shadow

		void enableShadow(const cocos2d::Color4B& color = cocos2d::Color4B::BLACK,
			const cocos2d::Size &offset = cocos2d::Size(2, -2), int blurRadius = 0);
		void disableShadow();
		cocos2d::Color4B getShadowColor() const { return cocos2d::Color4B(label->getShadowColor()); }
		cocos2d::Size getShadowOffset() const { return label->getShadowOffset(); }
		float getShadowBlurRadius() const { return label->getShadowBlurRadius(); }
	// italics

		void enableItalics();
		void disableItalics();
	// bold

		// only for system font and TTF
		void enableBold();
		void disableBold();
	// underline

		void enableUnderline();
		void disableUnderline();
	// strikethrough

		void enableStrikethrough();
		void disableStrikethrough();

		void disableAllEffects();


		XLabel* getLabel() const { return label; }
		LabelType getLabelType() const { return labelType; }
		cocos2d::TTFConfig& getTTFConfig() { return config; }
		void setTTFConfig(const cocos2d::TTFConfig& conf) { config = conf; }

		cocos2d::TextHAlignment getHAlign() const { return h_alignment; }
		void setHAlign(cocos2d::TextHAlignment ha) { h_alignment = ha; }
		cocos2d::TextVAlignment getVAlign() const { return v_alignment; }
		void setVAlign(cocos2d::TextVAlignment va) { v_alignment = va; }

		bool isOutlined() const { return _isOutlined; }
		bool isGlowed() const { return _isGlowed; }
		bool isShadowed() const { return _isShadowed; }
		bool isItalics() const { return label->isItalics(); }
		bool isBold() const { return label->isBold(); }
		bool isUnderlined() const { return label->isUnderlined(); }
		bool isStrikethrough() const { return label->isStrikethrough(); }
		int getFontAscender() const;

		bool render(const std::string& str, float x, float y, float width = -1, float height = -1, float scaleX = 1, float scaleY = 1);
		cocos2d::Vec2 calcSize(const std::string& text);
		std::unordered_map<std::string, std::string> getInfo() const override;

		cocos2d::Label* createLabel();
		void syncLabelSetting(cocos2d::Label* target);

		ResFont(const std::string& name, XLabel* label, LabelType type);
		~ResFont();

		static ResFont* createHGE(const std::string& name, const std::string& path);
		static ResFont* createBMF(const std::string& name, const std::string& path);
		static ResFont* createTTF(const std::string& name, const std::string& path, float fontSize);

		static void ReadHGEDefine(const std::string& data, std::unordered_map<char, GlyphInfo>& out, std::string& tex);
		static std::string HGE2BMF(const std::string& data, std::string& outTexName);
	};
}
