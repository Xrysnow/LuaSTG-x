#include "XAudioStream.h"
#include "../LSTG/ResourceMgr.h"

using namespace lstg;
using namespace cocos2d;

void lstg::installAudioFileOpener()
{
	ResourceMgr::getInstance();
	AudioStream::setFileOpener([](const std::string& path) -> AudioStream*
	{
		const auto buffer = LRES.getBufferFromFile(path);
		if (!buffer)
			return nullptr;
		auto memory = StreamMemory::create(buffer);
		if (!memory)
			return nullptr;
		auto result = XAudioStream::create(memory);
		// StreamMemory factories return an owning reference; the wrapper retains it.
		memory->release();
		return result;
	});
}

void lstg::clearAudioFileOpener()
{
	AudioStream::setFileOpener({});
}
