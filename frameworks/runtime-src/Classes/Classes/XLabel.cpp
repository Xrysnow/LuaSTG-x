#include "XLabel.h"

using namespace std;
using namespace cocos2d;

XLabel* XLabel::createWithBMFont(const string& bmfontFilePath, const string& text, const TextHAlignment& hAlignment, int maxLineWidth, const Vec2& imageOffset)
{
	auto ret = new (nothrow) XLabel(hAlignment);
	if (ret && ret->setBMFontFilePath(bmfontFilePath, imageOffset))
	{
		ret->setMaxLineWidth(maxLineWidth);
		ret->setString(text);
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

XLabel* XLabel::createWithTTF(const TTFConfig& ttfConfig, const string& text, TextHAlignment hAlignment, int maxLineWidth)
{
	auto ret = new (nothrow) XLabel(hAlignment);
	if (ret && ret->initWithTTF(ttfConfig, text, hAlignment, maxLineWidth))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

XLabel* XLabel::createWithSystemFont(const string& text, const string& font, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment)
{
	auto ret = new (nothrow) XLabel(hAlignment, vAlignment);
	if (ret)
	{
		ret->setSystemFontName(font);
		ret->setSystemFontSize(fontSize);
		ret->setDimensions(dimensions.width, dimensions.height);
		ret->setString(text);
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

XLabel::XLabel(TextHAlignment hAlignment, TextVAlignment vAlignment) :Label(hAlignment, vAlignment)
{
}

XLabel::~XLabel()
{
}

XLabel::LabelType XLabel::getLabelType() const
{
	auto i = static_cast<underlying_type<Label::LabelType>::type>(_currentLabelType);
	return (LabelType)i;
}
