#include "XLabel.h"
#include "2d/CCCamera.h"
#include "renderer/CCRenderer.h"
#include "2d/CCSprite.h"
#include "2d/CCSpriteBatchNode.h"

#include <algorithm>
#include "2d/CCFont.h"
#include "2d/CCFontAtlasCache.h"
#include "2d/CCFontAtlas.h"
#include "2d/CCDrawNode.h"
#include "base/ccUTF8.h"
#include "platform/CCFileUtils.h"
#include "renderer/ccGLStateCache.h"
#include "base/CCDirector.h"
#include "base/CCEventListenerCustom.h"
#include "base/CCEventDispatcher.h"
#include "base/CCEventCustom.h"
#include "2d/CCFontFNT.h"

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

	delete ret;
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

	return nullptr;
}

XLabel::XLabel(TextHAlignment hAlignment, TextVAlignment vAlignment) :Label(hAlignment, vAlignment)
{
}

XLabel::~XLabel()
{
	tempQuads.clear();
	tempCommends.clear();
}

void XLabel::draw(Renderer* renderer, const Mat4& transform, uint32_t flags)
{
	if (_batchNodes.empty() || _lengthOfString <= 0)
	{
		return;
	}
	// Don't do calculate the culling if the transform was not updated
	bool transformUpdated = flags & FLAGS_TRANSFORM_DIRTY;
//#if CC_USE_CULLING
//	auto visitingCamera = Camera::getVisitingCamera();
//	auto defaultCamera = Camera::getDefaultCamera();
//	if (visitingCamera == defaultCamera) {
//		_insideBounds = (transformUpdated || visitingCamera->isViewProjectionUpdated()) ? renderer->checkVisibility(transform, _contentSize) : _insideBounds;
//	}
//	else
//	{
//		_insideBounds = renderer->checkVisibility(transform, _contentSize);
//	}
//
//	if (_insideBounds)
//#endif
	{
		if (!_shadowEnabled && (getLabelType() == LabelType::BMFONT || getLabelType() == LabelType::CHARMAP))
		{
			for (auto&& it : _letters)
			{
				it.second->updateTransform();
			}
			// ETC1 ALPHA supports for BMFONT & CHARMAP
			auto textureAtlas = _batchNodes.at(0)->getTextureAtlas();
			auto texture = textureAtlas->getTexture();

			auto qs = textureAtlas->getQuads();
			auto nq = textureAtlas->getTotalQuads();
			//修改颜色
			if (blendColor != Color4B::WHITE)
			{
				auto verts = (V3F_C4B_T2F*)qs;
				for (size_t i = 0; i < nq * 4; ++i)
					verts[i].colors = blendColor;
			}
			//tempQuads.insert(tempQuads.end(), qs, qs + nq);
			//auto pQuad = tempQuads.end()._Ptr - nq;
			//auto cmd = make_shared<QuadCommand>();
			//cmd->init(_globalZOrder, texture, getGLProgramState(),
			//	_blendFunc, pQuad, nq, transform, flags);
			//renderer->addCommand(cmd.get());
			//tempCommends.push_back(cmd);

			//_quadCommand->init(_globalZOrder, texture, getGLProgramState(),
			//	_blendFunc, textureAtlas->getQuads(), textureAtlas->getTotalQuads(), transform, flags);
			_quadCommand.init(_globalZOrder, texture, getGLProgramState(),
				_blendFunc, qs, textureAtlas->getTotalQuads(), transform, flags);

			renderer->addCommand(&_quadCommand);
		}
		else
		{
			_customCommand.init(_globalZOrder, transform, flags);
			_customCommand.func = CC_CALLBACK_0(/*Label::*/XLabel::onDraw, this, transform, transformUpdated);
			renderer->addCommand(&_customCommand);
		}
	}
}

void XLabel::beginDraw()
{
	tempQuads.clear();
	tempCommends.clear();
}

void XLabel::endDraw()
{
}

XLabel::LabelType XLabel::getLabelType() const
{
	auto i = static_cast<underlying_type<Label::LabelType>::type>(_currentLabelType);
	return (LabelType)i;
}
