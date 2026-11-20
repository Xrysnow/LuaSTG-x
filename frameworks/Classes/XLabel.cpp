#include "XLabel.h"

using namespace std;
using namespace cc;

cc::IntrusivePtr<XLabel> XLabel::createWithBMFont(const string& bmfontFilePath, const string& text, const Vec2& imageOffset)
{
	cc::IntrusivePtr ret{new (nothrow) XLabel()};
	if (ret && ret->setBMFontFilePath(bmfontFilePath, Rect(imageOffset.x, imageOffset.y, 0, 0), false))
	{
		ret->setString(text);
		return ret;
	}
	return nullptr;
}

cc::IntrusivePtr<XLabel> XLabel::createWithTTF(const TTFConfig& ttfConfig, const string& text, TextHAlignment hAlignment, int maxLineWidth)
{
	cc::IntrusivePtr ret{new (nothrow) XLabel(hAlignment)};
	if (ret && ret->initWithTTF(ttfConfig, text, hAlignment, maxLineWidth))
	{
		return ret;
	}
	return nullptr;
}

cc::IntrusivePtr<XLabel> XLabel::createWithSystemFont(const string& text, const string& font, float fontSize, const Size& dimensions, TextHAlignment hAlignment, TextVAlignment vAlignment)
{
	cc::IntrusivePtr ret{new (nothrow) XLabel(hAlignment, vAlignment)};
	if (ret)
	{
		ret->setSystemFontName(font);
		ret->setSystemFontSize(fontSize);
		ret->setDimensions(dimensions.width, dimensions.height);
		ret->setString(text);
		return ret;
	}
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
