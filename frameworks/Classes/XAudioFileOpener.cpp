#include "XAudioIO.h"
#include "../LSTG/ResourceMgr.h"

using namespace lstg;
using namespace cocos2d;

void lstg::installAudioFileOpener()
{
	ResourceMgr::getInstance();
	AudioStream::setFileOpener([](const std::string& path) -> cc::IntrusivePtr<AudioStream>
	{
		auto stream = LRES.openReadStream(path);
		if (!stream)
			return nullptr;
		auto result = AudioStreamAdapter::create(std::move(stream.value));
		if (!result)
			return nullptr;
		return std::move(result.value).asRef();
	});
}

void lstg::clearAudioFileOpener()
{
	AudioStream::setFileOpener({});
}
