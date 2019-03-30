#pragma once
#include "ResBase.h"
#include "../Classes/XLabel.h"
#include "BlendMode.h"

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
			cocos2d::Rect GlyphPos;    // 字形在纹理上的uv坐标
			cocos2d::Vec2 GlyphSize;   // 字形大小
			cocos2d::Vec2 BrushPos;    // 笔触距离字形左上角坐标
			cocos2d::Vec2 Advance;     // 笔触的前进量(像素)
		};
	private:
		BlendMode* blendMode = BlendMode::Default;
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
		BlendMode* getBlendMode()const { return blendMode; }
		void setBlendMode(BlendMode* m) { blendMode = m; }

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
		int getShadowBlurRadius() const { return label->getShadowBlurRadius(); }
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
		
		cocos2d::Vec2 calcSize(const std::string& text);
		std::string getInfo() const override;

		cocos2d::Label* createLabel();
		static void syncLabelSetting(XLabel* src, cocos2d::Label* target);

		ResFont(const std::string& name, XLabel* label, LabelType type);
		~ResFont();

		static ResFont* createHGE(const std::string& name, const std::string& path);
		static ResFont* createBMF(const std::string& name, const std::string& path);
		static ResFont* createTTF(const std::string& name, const std::string& path, float fontSize);

		static void ReadHGEDefine(const std::string& data, std::unordered_map<char, GlyphInfo>& out, std::string& tex);
		static std::string HGE2BMF(const std::string& data, std::string& outTexName);
	};
}
