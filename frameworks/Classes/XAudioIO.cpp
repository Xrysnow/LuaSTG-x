#include "XAudioIO.h"
#include "audio/AudioSoundData.h"
#include "io/MemoryStream.h"
#include <new>
#include <stdexcept>

using namespace lstg;
using namespace cocos2d;

namespace
{
	AudioInputResult copyAudioInput(const void* bytes, size_t length)
	{
		auto buffer = io::MemoryBuffer::copy(bytes, length);
		if (!buffer)
			return AudioInputResult::failure(buffer.error);
		auto memory = io::MemoryStream::fromBuffer(std::move(buffer.value));
		if (!memory)
			return AudioInputResult::failure(memory.error);
		return AudioStreamAdapter::create(std::move(memory.value));
	}

	AudioDecodeResult decodeAudioInput(AudioInputResult input, size_t bufferSize,
		AudioDecoder::DecoderType type)
	{
		if (!input)
			return AudioDecodeResult::failure(input.error);
		try
		{
			RefPtr<AudioDecoder> decoder = AudioDecoder::createFromStream(input.value.get(), bufferSize, type);
			if (!decoder)
				return AudioDecodeResult::failure({io::ErrorCode::IoError});
			return AudioDecodeResult::success(std::move(decoder));
		}
		catch (const std::bad_alloc&) { return AudioDecodeResult::failure({io::ErrorCode::OutOfMemory}); }
		catch (const std::length_error&) { return AudioDecodeResult::failure({io::ErrorCode::Overflow}); }
	}
}

AudioInputResult lstg::createAudioInputFromStringData(const std::string& bytes)
{
	return copyAudioInput(bytes.data(), bytes.size());
}

AudioInputResult lstg::createAudioInputFromSoundData(const AudioSoundData* soundData)
{
	if (!soundData)
		return AudioInputResult::failure({io::ErrorCode::InvalidArgument});
	return copyAudioInput(soundData->getData(), soundData->getSize());
}

AudioDecodeResult lstg::decodeAudioStringData(const std::string& bytes,
	size_t bufferSize, AudioDecoder::DecoderType type)
{
	return decodeAudioInput(createAudioInputFromStringData(bytes), bufferSize, type);
}

AudioDecodeResult lstg::decodeAudioSoundData(const AudioSoundData* soundData,
	size_t bufferSize, AudioDecoder::DecoderType type)
{
	return decodeAudioInput(createAudioInputFromSoundData(soundData), bufferSize, type);
}
