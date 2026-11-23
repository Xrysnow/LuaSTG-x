#include "XAudioIO.h"
#include "../LSTG/ResourceMgr.h"

using namespace lstg;
using namespace cc;

void lstg::installAudioFileOpener()
{
	ResourceMgr::getInstance();
	AudioStream::setFileOpener([](const std::string& path) -> cc::IntrusivePtr<AudioStream>
	{
		auto bytes = LRES.getFileData(path);
		auto stream = ResourceMgr::openFileSnapshot(bytes);
		if (!stream)
			return nullptr;
		auto result = AudioStreamAdapter::create(std::move(stream.value), makeAudioFileReopener(std::move(bytes)));
		if (!result)
			return nullptr;
		return std::move(result.value).asRef();
	});
}

AudioStream::ReopenFactory lstg::makeAudioFileReopener(FileBytes bytes)
{
	return [bytes = std::move(bytes)]() -> cc::IntrusivePtr<AudioStream>
	{
		auto stream = ResourceMgr::openFileSnapshot(bytes);
		if (!stream)
			return nullptr;
		auto result = AudioStreamAdapter::create(std::move(stream.value));
		return result ? std::move(result.value).asRef() : nullptr;
	};
}

void lstg::clearAudioFileOpener()
{
	AudioStream::setFileOpener({});
}
