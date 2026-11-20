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
			cc::Rect GlyphPos;    // glyph uv coords in texture
			cc::Vec2 GlyphSize;   // glyph size
			cc::Vec2 BrushPos;    // brush position (to left-top)
			cc::Vec2 Advance;     // brush advance (pixel)
		};
	private:
		RenderMode* renderMode = RenderMode::getDefault();
		cc::Color4B textColor = cc::Color4B::WHITE;
		cc::Color4B outlineColor = cc::Color4B(0, 0, 0, 0xFF);
		cc::Color4B glowColor = cc::Color4B::WHITE;

		cc::IntrusivePtr<XLabel> label;
		cc::TTFConfig config;

		cc::TextHAlignment h_alignment = cc::TextHAlignment::LEFT;
		cc::TextVAlignment v_alignment = cc::TextVAlignment::TOP;
		LabelType labelType;

		bool _isOutlined = false;
		bool _isGlowed = false;
		bool _isShadowed = false;

	public:
		RenderMode* getRenderMode() const { return renderMode; }
		void setRenderMode(RenderMode* m);

		cc::Color4B getColor() const { return textColor; }
		void setColor(const cc::Color4B& c);
	// outline

		// only for system font and TTF
		void enableOutline(const cc::Color4B& color, int size = -1);
		void disableOutline();
		void setOutlineSize(int size) { enableOutline(outlineColor, size); }
		void setOutlineColor(const cc::Color4B& color) { enableOutline(color, config.outlineSize); }
		cc::Color4B getOutlineColor() const { return outlineColor; }
		int getOutlineSize() const { return config.outlineSize; }
	// glow

		// only for TTF
		void enableGlow(const cc::Color4B& color);
		void disableGlow();
		cc::Color4B getGlowColor() const { return glowColor; }
	// shadow

		void enableShadow(const cc::Color4B& color = cc::Color4B::BLACK,
			const cc::Size &offset = cc::Size(2, -2), int blurRadius = 0);
		void disableShadow();
		cc::Color4B getShadowColor() const { return cc::Color4B(label->getShadowColor()); }
		cc::Size getShadowOffset() const { return label->getShadowOffset(); }
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
		cc::TTFConfig& getTTFConfig() { return config; }
		void setTTFConfig(const cc::TTFConfig& conf) { config = conf; }

		cc::TextHAlignment getHAlign() const { return h_alignment; }
		void setHAlign(cc::TextHAlignment ha) { h_alignment = ha; }
		cc::TextVAlignment getVAlign() const { return v_alignment; }
		void setVAlign(cc::TextVAlignment va) { v_alignment = va; }

		bool isOutlined() const { return _isOutlined; }
		bool isGlowed() const { return _isGlowed; }
		bool isShadowed() const { return _isShadowed; }
		bool isItalics() const { return label->isItalics(); }
		bool isBold() const { return label->isBold(); }
		bool isUnderlined() const { return label->isUnderlined(); }
		bool isStrikethrough() const { return label->isStrikethrough(); }
		int getFontAscender() const;

		bool render(const std::string& str, float x, float y, float width = -1, float height = -1, float scaleX = 1, float scaleY = 1);
		cc::Vec2 calcSize(const std::string& text);
		std::unordered_map<std::string, std::string> getInfo() const override;
		size_t getMemorySize() override;

		cc::IntrusivePtr<cc::Label> createLabel();
		void syncLabelSetting(cc::Label* target);

		ResFont(const std::string& name, cc::IntrusivePtr<XLabel> label_, LabelType type);
		~ResFont() override;

		static cc::IntrusivePtr<ResFont> createHGE(const std::string& name, const std::string& path);
		static cc::IntrusivePtr<ResFont> createBMF(const std::string& name, const std::string& path);
		static cc::IntrusivePtr<ResFont> createTTF(const std::string& name, const std::string& path, float fontSize);

		static void ReadHGEDefine(const std::string& data, std::unordered_map<char, GlyphInfo>& out, std::string& tex);
		static std::string HGE2BMF(const std::string& data, std::string& outTexName);
	};
}
