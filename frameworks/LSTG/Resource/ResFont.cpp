#include "ResFont.h"
#include "Global.h"
#include "Util/Utility.h"
#include "XFileUtils.h"
#include "AppFrame.h"
#include "LogSystem.h"
#include "Renderer.h"
#include "ResourceMgr.h"
#include "LabelPool.h"
#include "2d/CCFontFreeType.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

void ResFont::setRenderMode(RenderMode* m)
{
	renderMode = m;
}

void ResFont::setColor(const Color4B& c)
{
	label->setBlendColor(c);
	if (labelType == LabelType::TTF || labelType == LabelType::SYSTEM)
		label->setTextColor(c);
	textColor = c;
}

void ResFont::enableOutline(const Color4B& color, int size)
{
	if (labelType == LabelType::TTF || labelType == LabelType::SYSTEM)
	{
		if (size < 0)
			size = 2;
		config.outlineSize = size;
		label->enableOutline(color, size);
		_isOutlined = true;
	}
}

void ResFont::disableOutline()
{
	label->disableEffect(LabelEffect::OUTLINE);
	_isOutlined = false;
}

void ResFont::enableGlow(const Color4B& color)
{
	label->enableGlow(color);
	glowColor = color;
	_isGlowed = true;
}

void ResFont::disableGlow()
{
	label->disableEffect(LabelEffect::GLOW);
	_isGlowed = false;
}

void ResFont::enableShadow(const Color4B& color, const Size& offset, int blurRadius)
{
	label->enableShadow(color, offset, blurRadius);
	_isShadowed = true;
}

void ResFont::disableShadow()
{
	label->disableEffect(LabelEffect::SHADOW);
	_isShadowed = false;
}

void ResFont::enableItalics()
{
	label->enableItalics();
}

void ResFont::disableItalics()
{
	label->disableEffect(LabelEffect::ITALICS);
}

void ResFont::enableBold()
{
	label->enableBold();
}

void ResFont::disableBold()
{
	label->disableEffect(LabelEffect::BOLD);
}

void ResFont::enableUnderline()
{
	label->enableUnderline();
}

void ResFont::disableUnderline()
{
	label->disableEffect(LabelEffect::UNDERLINE);
}

void ResFont::enableStrikethrough()
{
	label->enableStrikethrough();
}

void ResFont::disableStrikethrough()
{
	label->disableEffect(LabelEffect::STRIKETHROUGH);
}

void ResFont::disableAllEffects()
{
	label->disableEffect(LabelEffect::ALL);
	_isOutlined = false;
	_isGlowed = false;
	_isShadowed = false;
}

int ResFont::getFontAscender() const
{
	const auto atlas = label->getFontAtlas();
	if (!atlas)
		return -1;
	const auto font = dynamic_cast<const FontFreeType*>(atlas->getFont());
	if(!font)
		return -1;
	return font->getFontAscender();
}

bool ResFont::render(const std::string& str, float x, float y, float width, float height, float scaleX, float scaleY)
{
	return LRR.renderText(this, str, x, y, width, height, scaleX, scaleY);
}

Vec2 ResFont::calcSize(const string& text)
{
	const auto last_str = label->getString();
	label->setString(text);
	const auto s = label->getContentSize();// content size
	//auto s = label->getDimensions();// display size
	label->setString(last_str);
	return Vec2(s.width, s.height);
}

std::unordered_map<std::string, std::string> ResFont::getInfo() const
{
	auto ret = Resource::getInfo();
	ret["render_mode"] = renderMode->getName();
	ret["color"] = tostring(label->getBlendColor());
	ret["description"] = label->getDescription();
	ret["h_align"] = tostring(h_alignment);
	ret["v_align"] = tostring(v_alignment);
	return ret;
}

Label* ResFont::createLabel()
{
	Label* ret;
	const auto exist = FileUtils::getInstance()->isFileExist(config.fontFilePath);
	switch (getLabelType())
	{
	case LabelType::TTF:
		if (exist)
			ret = Label::createWithTTF(config, "");
		else
			ret = Label::createWithSystemFont("", config.fontFilePath, config.fontSize);
		break;
	case LabelType::BMFONT:
		ret = Label::createWithBMFont(config.fontFilePath, "");
		break;
	case LabelType::SYSTEM:
		ret = Label::createWithSystemFont("", config.fontFilePath, config.fontSize);
		break;
	case LabelType::CHARMAP:
	default:
		XERROR("Unexpected LabelType.");
		ret = Label::create();
	}
	CC_ASSERT(ret);
	syncLabelSetting(getLabel(), ret);
	return ret;
}

void ResFont::syncLabelSetting(XLabel* src, Label* target)
{
	if (!src || !target)return;
	const auto type = src->getLabelType();
	if (type == XLabel::LabelType::TTF || type == XLabel::LabelType::STRING_TEXTURE)
		target->setTextColor(src->getTextColor());
	if (src->isShadowEnabled())
		target->enableShadow(Color4B(src->getShadowColor()), src->getShadowOffset(), src->getShadowBlurRadius());
	target->setAlignment(src->getHorizontalAlignment(), src->getVerticalAlignment());
	target->setMaxLineWidth(src->getMaxLineWidth());
	if (type == XLabel::LabelType::BMFONT)
		target->setBMFontSize(src->getBMFontSize());
	target->enableWrap(src->isWrapEnabled());
	target->setOverflow(src->getOverflow());
	target->setWidth(src->getWidth());
	target->setHeight(src->getHeight());
	target->setDimensions(src->getDimensions().width, src->getDimensions().height);
	target->setClipMarginEnabled(src->isClipMarginEnabled());
	if (type != XLabel::LabelType::STRING_TEXTURE)
	{
		target->setLineHeight(src->getLineHeight());
		target->setAdditionalKerning(target->getAdditionalKerning());
	}
	target->setLineSpacing(src->getLineSpacing());
	if (src->getBlendFunc() != target->getBlendFunc())
		target->setBlendFunc(src->getBlendFunc());
	target->setOpacityModifyRGB(src->isOpacityModifyRGB());

	target->setAnchorPoint(src->getAnchorPoint());
	if (src->isItalics())target->enableItalics();
	if (src->isBold())target->enableBold();
	if (src->isUnderlined())target->enableUnderline();
	if (src->isStrikethrough())target->enableStrikethrough();
}

ResFont::ResFont(const std::string& name, XLabel* label, LabelType type)
	: Resource(ResourceType::Font, name), label(label), labelType(type)
{
	CC_ASSERT(label);
	label->retain();
	config = label->getTTFConfig();
}

ResFont::~ResFont()
{
	LRR.getLabelPool().onResFontRemove(this);
	label->release();
}

ResFont* ResFont::createHGE(const std::string& name, const std::string& path)
{
	if (!FileUtils::getInstance()->isFileExist(path))
		return nullptr;
	try
	{
		const string fData = LRES.getStringFromFile(path);
		auto pos = path.find_last_of('/');
		if (pos == string::npos)
			pos = path.find_last_of('\\');
		if (pos == string::npos)
			return nullptr;
		string fpath = path.substr(0, pos);
		string tex_name;
		auto bmf = HGE2BMF(fData, tex_name);
		if (bmf.empty())
			return nullptr;
		// convert to '/'
		//auto tpath  = ReplacePathSep(fpath + "\\" + tex_name);
		const auto font_path = ReplacePathSep(path);
		XFileUtils::SetFileStringToReplace(font_path, bmf);
		const auto lb = XLabel::createWithBMFont(font_path, "");// very slow here
		if (!lb)
			return nullptr;
		// construct
		auto res = new (nothrow) ResFont(name, lb, LabelType::BMFONT);
		if (!res)
			return nullptr;
		res->getTTFConfig().fontFilePath = font_path;
		res->resPath = font_path;
		return res;
	}
	catch (...){}
	return nullptr;
}

ResFont* ResFont::createBMF(const std::string& name, const std::string& path)
{
	try
	{
		const auto font_path = ReplacePathSep(path);
		const auto lb = XLabel::createWithBMFont(font_path, "");
		if (!lb)
			return nullptr;
		auto res = new ResFont(name, lb, LabelType::BMFONT);
		if (!res)
			return nullptr;
		res->getTTFConfig().fontFilePath = font_path;
		res->resPath = font_path;
		return res;
	}
	catch (...){}
	return nullptr;
}

ResFont* ResFont::createTTF(const std::string& name, const std::string& path, float fontSize)
{
	try
	{
		TTFConfig cfg;
		cfg.fontFilePath = path;
		if (fontSize > 1.f)
			cfg.fontSize = fontSize;
		auto type = LabelType::TTF;
		auto lb = XLabel::createWithTTF(cfg, "_");
		if (!lb)
		{
			type = LabelType::SYSTEM;
			lb = XLabel::createWithSystemFont("_", path, fontSize);
			if (!lb)
				return nullptr;
		}
		return new (nothrow) ResFont(name, lb, type);
	}
	catch (...) {}
	return nullptr;
}

void ResFont::ReadHGEDefine(const string& data, unordered_map<char, GlyphInfo>& out, string& tex)
{
	out.clear();
	tex.clear();

	vector<string> tLines = util::stringSplit(data, "\n", true);
	for (auto& i : tLines)
	{
		i = util::stringTrim(i);
	}

	// check header
	if (tLines.size() <= 1 || tLines[0] != "[HGEFONT]")
	{
		XERROR("bad file format");
		CC_ASSERT(0);
		return;
	}
	for (size_t i = 1; i < tLines.size(); ++i)
	{
		string& tLine = tLines[i];
		if (tLine.empty())
			continue;

		auto tPos = tLine.find_first_of('=');
		if (string::npos == tPos)
		{
			XERROR("bad file format");
			CC_ASSERT(0);
			return;
		}
		string tKey = tLine.substr(0, tPos);
		string tValue = tLine.substr(tPos + 1, tLine.size() - tPos - 1);
		if (tKey == "Bitmap")
			tex = tValue;
		else if (tKey == "Char")
		{
			char c;
			int c_hex;
			float x, y, w, h, left_offset, right_offset;
			if (7 != sscanf(tValue.c_str(), "\"%c\",%f,%f,%f,%f,%f,%f", &c, &x, &y, &w, &h, &left_offset, &right_offset))
			{
				if (7 != sscanf(tValue.c_str(), "%X,%f,%f,%f,%f,%f,%f", &c_hex, &x, &y, &w, &h, &left_offset, &right_offset))
					throw runtime_error("ResFont::HGEFont::readDefine: Bad file format.");
				c = static_cast<char>(c_hex);
			}

			// calculate offset
			//TODO: CHECK
			GlyphInfo tInfo = {
				Rect(x, y, w, h),
				Vec2(w, h),
				Vec2(-left_offset, h),
				Vec2(w + left_offset + right_offset, 0)
			};
			if (out.find(c) != out.end())
				throw runtime_error("ResFont::HGEFont::readDefine: Duplicated character defination.");
			out.emplace(c, tInfo);
		}
		else
			throw runtime_error("ResFont::HGEFont::readDefine: Bad file format.");
	}

	if (tex.empty())
		throw runtime_error("ResFont::HGEFont::readDefine: Bad file format.");
}

string ResFont::HGE2BMF(const string& data, string& outTexName)
{
	unordered_map<char, GlyphInfo> tOutputCharset;
	string tOutputTextureName;
	try
	{
		ReadHGEDefine(data, tOutputCharset, tOutputTextureName);
	}
	catch (runtime_error& e)
	{
		LERROR("%s", e.what());
		return "";
	}
	outTexName = tOutputTextureName;

	float maxX = 0.f;
	float maxY = 0.f;
	float maxH = 0.f;
	for (auto i : tOutputCharset)
	{
		const auto xx = i.second.GlyphPos.getMaxX();
		const auto yy = i.second.GlyphPos.getMaxY();
		const auto hh = i.second.GlyphSize.y;
		if (xx > maxX)
			maxX = xx;
		if (yy > maxY)
			maxY = yy;
		if (hh > maxH)
			maxH = hh;
	}

	string size = to_string(int(maxH));

	string ret = "info face=\"Script\" size=";
	ret += size;
	ret += " bold=0 italic=0 charset=\"\" unicode=1 stretchH=100 smooth=1 aa=1 padding=0,0,0,0 spacing=1,1 outline=0\r\ncommon lineHeight=";
	ret += size;
	ret += " base=26 scaleW=";
	ret += to_string(int(maxX));
	ret += " scaleH=";
	ret += to_string(int(maxY));
	ret += " pages=1 packed=0 alphaChnl=1 redChnl=1 greenChnl=1 blueChnl=1\r\npage id=0 file=\"";
	ret += tOutputTextureName + "\"\r\n";
	ret += "chars count=";
	ret += to_string(tOutputCharset.size()) + "\r\n";
	for (auto i : tOutputCharset)
	{
		ret += "char id=";
		ret += to_string(unsigned(i.first)) + " ";
		ret += "x=" + to_string(int(i.second.GlyphPos.getMinX())) + " ";
		ret += "y=" + to_string(int(i.second.GlyphPos.getMinY())) + " ";
		ret += "width=" + to_string(int(i.second.GlyphPos.size.width)) + " ";
		ret += "height=" + to_string(int(i.second.GlyphPos.size.height)) + " ";
		ret += "xoffset=0 ";
		ret += "yoffset=0 ";
		ret += "xadvance=" + to_string(int(i.second.Advance.x)) + " ";
		ret += "page=0 chnl=0\r\n";
	}
	ret += "kernings count=0\r\n";

	return ret;
}
