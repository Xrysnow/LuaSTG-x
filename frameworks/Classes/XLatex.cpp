#include "XLatex.h"
#include "2d/CCFontFreeType.h"
#include "Util/Utility.h"
#include "../external/cLaTeXMath/src/src/latex.h"

using namespace lstg;

bool cmpTTFConfig(const cocos2d::TTFConfig& c1, const cocos2d::TTFConfig& c2)
{
	return c1.fontFilePath == c2.fontFilePath &&
		c1.fontSize == c2.fontSize &&
		c1.distanceFieldEnabled == c2.distanceFieldEnabled &&
		c1.outlineSize == c2.outlineSize &&
		c1.italics == c2.italics &&
		c1.bold == c2.bold &&
		c1.underline == c2.underline &&
		c1.strikethrough == c2.strikethrough;
}

class TexFont : public tex::Font
{
	TexFont(){}
public:
	virtual ~TexFont() {}
	cocos2d::TTFConfig cfg;
	int _style = 0;
	TexFont(const string& name, int style, float size)
	{
		cfg.fontFilePath = name;
		cfg.fontSize = size;
		setStyle(style);
	}
	TexFont(const string& file, float size)
	{
		cfg.fontFilePath = file;
		cfg.fontSize = size;
		setStyle(PLAIN);
	}

	float getSize() const override {
		return cfg.fontSize;
	}

	sptr<Font> deriveFont(int style) const override
	{
		auto f = new TexFont();
		f->cfg = cfg;
		f->setStyle(style);
		return sptr<Font>(f);
	}

	bool operator==(const Font& ft) const override
	{
		const auto& f = static_cast<const TexFont&>(ft);
		return cmpTTFConfig(f.cfg, cfg);
	}
	bool operator!=(const Font& f) const override {
		return !(*this == f);
	}

	void setStyle(int style)
	{
		switch (style) {
		case BOLD:
			cfg.bold = true;
			break;
		case ITALIC:
			cfg.italics = true;
			break;
		case BOLDITALIC:
			cfg.bold = true;
			cfg.italics = true;
			break;
		default:
			break;
		}
		_style = style;
	}
	cocos2d::Label* createLabel(const std::string& str) const {
		return cocos2d::Label::createWithTTF(cfg, str);
	}
};

Font* Font::create(const string& file, float size)
{
	return new TexFont(file, size);
}

sptr<Font> Font::_create(const string& name, int style, float size)
{
	return sptr<Font>(new TexFont(name, style, size));
}

/**************************************************************************************************/

class TexTextLayout : public tex::TextLayout
{
	sptr<TexFont> _font;
	wstring _txt;
	cocos2d::Label* _lb = nullptr;
public:
	TexTextLayout(const wstring& src, const sptr<TexFont>& font)
	: _font(font), _txt(src)
	{
		const auto txt = util::WideCharToMultiByte_UTF8(src);
		_lb = cocos2d::Label::createWithTTF(_font->cfg, txt);
		CC_SAFE_RETAIN(_lb);
	}
	void getBounds(Rect& bounds) override
	{
		const auto sz = _lb->getContentSize();
		bounds.x = 0;
		bounds.y = 0;
		bounds.w = sz.width;
		bounds.h = sz.height;
		cocos2d::log("%s (%.1f, %.1f)", __FUNCTION__, sz.width, sz.height);
	}
	void draw(Graphics2D& g2, float x, float y) override {
		const auto prev = g2.getFont();
		g2.setFont(_font.get());
		g2.drawText(_txt, x, y);
		g2.setFont(prev);
	}
	virtual ~TexTextLayout()
	{
		CC_SAFE_RELEASE(_lb);
	}
};

sptr<TextLayout> tex::TextLayout::create(const wstring& src, const sptr<Font>& font)
{
	return sptr<TextLayout>(new TexTextLayout(src, static_pointer_cast<TexFont>(font)));
}

/**************************************************************************************************/

class TexGraphics2D : public tex::Graphics2D
{
public:
	using DrawTextCb = std::function<void(const string&, float, float, TexGraphics2D*)>;
private:
	cocos2d::DrawNode* _drawNode = nullptr;
	//cocos2d::Node* _node = nullptr;
	DrawTextCb _onDrawText;
	color _color = 0;
	TexFont* _font = nullptr;
	Stroke _stroke;
	float _sx = 1.f;
	float _sy = 1.f;
public:
	cocos2d::Vec2 curPos;
	cocos2d::Vec2 curScale = cocos2d::Vec2::ONE;
	float curRot = 0.f;
	cocos2d::Color4F col;
	cocos2d::Mat4 tr;

	TexGraphics2D(
		cocos2d::DrawNode* drawNode,
		cocos2d::Node* node,
		const DrawTextCb& onDrawText)
	{
		_drawNode = drawNode;
		//_node = node;
		_onDrawText = onDrawText;
	}
	virtual ~TexGraphics2D(){}

	void setColor(color c) override
	{
		_color = c;
		const auto a = (uint8_t)color_a(c);
		const auto r = (uint8_t)color_r(c);
		const auto g = (uint8_t)color_g(c);
		const auto b = (uint8_t)color_b(c);
		col = { r / 255.f,g / 255.f,b / 255.f,a / 255.f };
	}
	color getColor() const override { return _color; }

	void setStroke(const Stroke& s) override {
		_stroke = s;
		_drawNode->setLineWidth(s.lineWidth);
	}
	const Stroke& getStroke() const override { return _stroke; }

	void setStrokeWidth(float w) override {
		_stroke.lineWidth = w;
		_drawNode->setLineWidth(w);
	}

	const Font* getFont() const override { return _font; }

	void setFont(const Font* font) override {
		_font = (TexFont*)font;
	}

	void translate(float dx, float dy) override
	{
		curPos.add({ dx*curScale.x,dy*curScale.y });
		tr.translate(dx, dy, 0);
	}

	void scale(float sx, float sy) override
	{
		curScale.scale({ sx,sy });
		curPos.scale({ sx,sy });
		tr.scale(sx, sy, 1);
	}

	void rotate(float angle) override
	{
		//cocos2d::log("[%s] (%.2f)", __FUNCTION__,
		//	angle);
		curRot += angle;
		curPos.rotate(cocos2d::Vec2::ZERO, angle);
		tr.rotateZ(angle);
	}

	void rotate(float angle, float px, float py) override
	{
		//cocos2d::log("[%s1] (%.2f,%.2f,%.2f)", __FUNCTION__,
		//	angle, px, py);
		translate(px, py);
		rotate(angle);
		translate(-px, -py);
	}

	void reset() override
	{
		curPos.setZero();
		curScale.set(1.f, 1.f);
		curRot = 0.f;
		tr = cocos2d::Mat4::IDENTITY;
		_sx = _sy = 1.f;
	}

	float sx() const override { return _sx;}
	float sy() const override { return _sy; }

	cocos2d::Vec2 transformPoint(float x, float y, bool round = false)
	{
		cocos2d::Vec3 p{ x,y,0 };
		tr.transformVector(&p);
		if (round)
			return { std::round(p.x),std::round(-p.y) };
		return { p.x,-p.y };
	}

	void drawChar(wchar_t c, float x, float y) override {
		drawText({ c, L'\0' }, x, y);
	}

	void drawText(const wstring& c, float x, float y) override
	{
		const auto txt = util::WideCharToMultiByte_UTF8(c);
		if (_onDrawText)_onDrawText(txt, x, y, this);
	}

	void drawLine(float x1, float y1, float x2, float y2) override
	{
		fillRect(x1, (y1 + y2) / 2 - _stroke.lineWidth / 2, x2 - x1, _stroke.lineWidth);
	}

	void drawRect(float x, float y, float w, float h) override
	{
		_drawNode->drawRect(transformPoint(x, y, true), transformPoint(x + w, y + h), col);
	}

	void fillRect(float x, float y, float w, float h) override
	{
		_drawNode->drawSolidRect(transformPoint(x, y, true), transformPoint(x + w, y + h), col);
	}

	void drawArc(float x, float y, float r, float angle, float rot)
	{
		const auto segments = 60u;
		angle = angle / 180 * M_PI;
		rot = rot / 180 * M_PI;
		const float coef = angle / segments;
		auto vertices = new (std::nothrow) cocos2d::Vec2[segments + 2];
		if (!vertices)
			return;
		for (unsigned int i = 0; i <= segments; i++) {
			const auto rads = i * coef + rot;
			auto xx = r * cosf(rads) + x;
			auto yy = r * sinf(rads) + y;
			vertices[i] = transformPoint(xx, yy);
		}
		_drawNode->drawPoly(vertices, segments + 1, true, col);
		CC_SAFE_DELETE_ARRAY(vertices);
	}

	void drawRoundRect(float x, float y, float w, float h, float rx, float ry) override
	{
		const auto r = std::max(rx, ry);
		drawArc(x + r, y + r, r, 90, 180);
		drawArc(x + w - r, y + r, r, 90, 270);
		drawArc(x + w - r, y + h - r, r, 90, 0);
		drawArc(x + r, y + h - r, r, 90, 90);
		drawLine(x + r, y, x + w - r, y);
		drawLine(x + r, y + h, x + w - r, y + h);
		drawLine(x, y + r, x, y + h - r);
		drawLine(x + w, y + r, x + w, y + h - r);
	}

	void fillRoundRect(float x, float y, float w, float h, float rx, float ry) override
	{
		fillRect(x, y, w, h);
	}
};

struct _LatexInit {
	_LatexInit() {
		LaTeX::init("latex");
		//tex::Font::setCreator(
		//	[](const string& file, float size) {
		//	return new TexFont(file, size); },
		//	[](const string& name, int style, float size) {
		//	return sptr<Font>(new TexFont(name, style, size)); });
		//tex::TextLayout::setCreator(
		//	[](const wstring& src, const sptr<Font>& font){
		//	return sptr<TextLayout>(new TexTextLayout(src, static_pointer_cast<TexFont>(font)));
		//});
	}
	~_LatexInit() {
		LaTeX::release();
	}
};

bool Latex::_init(const std::string& str,
	int width_, float textSize_, float lineSpace, const cocos2d::Color4B& color)
{
	if(!Node::init())
		return false;
	root = cocos2d::Node::create();
	if (!root)
		return false;
	addChild(root);
	drawNode = cocos2d::DrawNode::create();
	if (!drawNode)
		return false;
	root->addChild(drawNode);
	const auto txt = util::MultiByteToWideChar_UTF8(str);
	const TexGraphics2D::DrawTextCb cb = [&](const string& s, float x, float y, TexGraphics2D* g2)
	{
		auto f = (TexFont*)g2->getFont();
		auto cfg = f->cfg;
		cocos2d::Vec3 scale, trans;
		cocos2d::Quaternion q;
		g2->tr.decompose(&scale, &q, &trans);
		cfg.fontSize *= std::max(scale.x, scale.y);
		auto lb = cocos2d::Label::createWithTTF(cfg, s);
		auto ttf = dynamic_cast<const cocos2d::FontFreeType*>(lb->getFontAtlas()->getFont());
		int ascent = ttf ? ttf->getFontAscender() : cfg.fontSize;
		lb->setAlignment(cocos2d::TextHAlignment::LEFT, cocos2d::TextVAlignment::TOP);
		lb->setAnchorPoint(cocos2d::Vec2::ANCHOR_TOP_LEFT);
		lb->setIgnoreAnchorPointForPosition(false);
		lb->setTextColor(cocos2d::Color4B{ g2->col });
		root->addChild(lb);
		lb->setPosition({ std::round(trans.x),std::round(-trans.y) + ascent });
		lb->setScaleX(scale.x / cfg.fontSize);
		lb->setScaleY(scale.y / cfg.fontSize);
		lb->setRotation(CC_RADIANS_TO_DEGREES(q.toAxisAngle(&trans)));
	};
	try
	{
		auto r = LaTeX::parse(
			// LaTeX code to parse
			txt,
			// logical width of the graphics context (in pixel)
			width_,
			// font size (in point)
			textSize_,
			// space between 2 lines (in pixel)
			lineSpace,
			// foreground color
			tex::argb(color.a, color.r, color.g, color.b)
		);
		TexGraphics2D g{ drawNode,root,cb };
		r->draw(g, 0, 0);
		width = r->getWidth();
		height = r->getHeight();
		depth = r->getDepth();
		textSize = r->getTextSize();
		baseline = r->getBaseline();
		const auto ins = r->getInsets();
		insets.setRect(ins.left, ins.bottom, ins.right - ins.left, ins.top - ins.bottom);
		delete r;
	}
	catch (...)
	{
		return false;
	}
	return true;
}

Latex* Latex::create(const std::string& str, int width, float textSize, float lineSpace, const cocos2d::Color4B& color)
{
	static struct _LatexInit _;
	auto ret = new (std::nothrow) Latex();
	if (ret&&ret->_init(str, width, textSize, lineSpace, color))
	{
		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}

void Latex::setDebug(bool b)
{
	LaTeX::setDebug(b);
}
