#pragma once
#include "cocos2d.h"

namespace lstg
{
	class GifRecoder : public cocos2d::Ref
	{
		cocos2d::Rect area;
		bool trans = true;
		cocos2d::Vector<cocos2d::RenderTexture*> captures;
		std::vector<int32_t> intervals;
		int32_t defaultItv = 1000;
		int32_t quantizer = 0;
		int32_t dither = 0;

		GifRecoder();
		virtual ~GifRecoder();
	public:
		static GifRecoder* create(
			const cocos2d::Rect& rect = cocos2d::Rect::ZERO,
			bool transparent = true, int32_t defaultInterval = -1,
			int32_t quantizerType = 0, int32_t ditherType = 0
		);
		bool capture(int32_t interval = -1);
		bool save(const std::string& path);
		void clear();
	};
}
