#include "XAudioIO.h"
#include "../LSTG/ResourceMgr.h"

using namespace lstg;
using namespace cocos2d;

void lstg::installAudioFileOpener()
{
	ResourceMgr::getInstance();
	AudioStream::setFileOpener([](const std::string& path) -> AudioStream*
	{
		auto stream = LRES.openReadStream(path);
		if (!stream)
			return nullptr;
		auto result = AudioStreamAdapter::create(std::move(stream.value));
		if (!result)
			return nullptr;
		// The core callback returns an autoreleased pointer. Give that pool its
		// own reference before the local owning result releases its reference.
		auto raw = result.value.get();
		raw->retain();
		raw->autorelease();
		return raw;
	});
}

void lstg::clearAudioFileOpener()
{
	AudioStream::setFileOpener({});
}
