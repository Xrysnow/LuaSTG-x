#include "XGifRecoder.h"
#include "../LSTG/Renderer.h"
#include "../LSTG/AppFrame.h"
#include "../LSTG/Utility.h"
#include "../../external/BurstLinker/src/include/BurstLinker.h"

using namespace lstg;

GifRecoder::GifRecoder()
{
}

GifRecoder::~GifRecoder()
{
}

GifRecoder* GifRecoder::create(const cocos2d::Rect& rect, bool transparent, int32_t defaultInterval,
	int32_t quantizerType, int32_t ditherType)
{
	auto ret = new (std::nothrow) GifRecoder();
	if (ret)
	{
		ret->area = rect;
		ret->trans = transparent;
		ret->defaultItv = defaultInterval;
		ret->quantizer = quantizerType;
		ret->dither = ditherType;
		return ret;
	}
	delete ret;
	return nullptr;
}

bool GifRecoder::capture(int32_t interval)
{
	//TODO: use as RenderTexture
	const auto fb = LRR.copyFrameBuffer(trans);
	if (!fb)
		return false;
	captures.pushBack(fb);
	intervals.push_back(interval > 0 ? interval : defaultItv);
	return true;
}

bool GifRecoder::save(const std::string& path)
{
	blk::BurstLinker burstLinker;
	std::stringstream out;
	if (!burstLinker.init(out, area.size.width, area.size.height, 0, 0))
		return false;
	//cocos2d::Vector<cocos2d::Image*> imgs;
	//for (auto& cap : captures)
	//	imgs.pushBack(cap->newImage(false));
	for (auto i = 0u; i < captures.size(); ++i)
	{
		cocos2d::Image* img = nullptr;
		captures.at(i)->newImage([&](cocos2d::Image* im) { img = im; }, false);
		std::vector<uint32_t> buf;
		buf.assign(img->getData(), img->getData() + img->getDataLen());
		burstLinker.connect(buf, intervals.at(i), (blk::QuantizerType)quantizer, (blk::DitherType)dither, 1, 0, 0);
		CC_SAFE_DELETE(img);
	}
	burstLinker.release();
	return cocos2d::FileUtils::getInstance()->writeStringToFile(out.str(), path);
}

void GifRecoder::clear()
{
	captures.clear();
	intervals.clear();
}
