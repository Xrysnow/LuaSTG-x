#include "XAudioStream.h"
#include "cocos/audio/AudioSoundData.h"
#include <cstring>
#include <limits>

using namespace lstg;
using namespace cocos2d;

namespace
{
	AudioStream* createAudioStreamFromBuffer(Buffer* buffer)
	{
		if (!buffer)
			return nullptr;
		auto memory = StreamMemory::create(buffer);
		if (!memory)
			return nullptr;
		auto result = XAudioStream::create(memory);
		// StreamMemory::create returns an owning reference, unlike the wrapper.
		memory->release();
		return result;
	}
}

XAudioStream* XAudioStream::create(Stream* src)
{
	if (!src)
		return nullptr;
	auto result = new (std::nothrow) XAudioStream();
	if (result)
	{
		result->_src = src;
		result->autorelease();
	}
	return result;
}

uint64_t XAudioStream::size()
{
	return _src->size();
}

uint64_t XAudioStream::tell()
{
	return _src->tell();
}

bool XAudioStream::seek(SeekOrigin origin, int64_t offset)
{
	uint64_t base = 0;
	switch (origin)
	{
	case SeekOrigin::BEGINNING: break;
	case SeekOrigin::CURRENT: base = tell(); break;
	case SeekOrigin::END: base = size(); break;
	default: return false;
	}
	uint64_t position = 0;
	if (offset < 0)
	{
		// Avoid negating INT64_MIN while validating the unsigned cursor.
		const auto distance = uint64_t(-(offset + 1)) + 1;
		if (distance > base)
			return false;
		position = base - distance;
	}
	else
	{
		if (uint64_t(offset) > std::numeric_limits<uint64_t>::max() - base)
			return false;
		position = base + uint64_t(offset);
	}
	const auto length = size();
	if (position > length)
		return false;
	// StreamMemory rejects positive BEG offsets exactly at EOF. END/0 is valid.
	if (position == length)
		return _src->seek(Stream::END, 0);
	if (position > uint64_t(std::numeric_limits<int64_t>::max()))
		return false;
	return _src->seek(Stream::BEG, int64_t(position));
}

bool XAudioStream::read(uint8_t* dst, uint64_t length, uint64_t* bytesRead)
{
	return _src->read(dst, length, bytesRead);
}

void XAudioStream::lock()
{
	_src->lock();
}

void XAudioStream::unlock()
{
	_src->unlock();
}

AudioStream* lstg::createAudioStreamFromStringData(const std::string& str)
{
	return createAudioStreamFromBuffer(Buffer::createFromString(str));
}

AudioStream* lstg::createAudioStreamFromSoundData(AudioSoundData* soundData)
{
	if (!soundData)
		return nullptr;
	const auto size = soundData->getSize();
	if (size && !soundData->getData())
		return nullptr;
	auto buffer = Buffer::create(size);
	if (!buffer)
		return nullptr;
	if (size)
		std::memcpy(buffer->data(), soundData->getData(), size);
	return createAudioStreamFromBuffer(buffer);
}

AudioDecoder* lstg::createAudioDecoderFromStringData(const std::string& str,
	size_t bufferSize, AudioDecoder::DecoderType type)
{
	return AudioDecoder::createFromStream(createAudioStreamFromStringData(str), bufferSize, type);
}

AudioDecoder* lstg::createAudioDecoderFromSoundData(AudioSoundData* soundData,
	size_t bufferSize, AudioDecoder::DecoderType type)
{
	return AudioDecoder::createFromStream(createAudioStreamFromSoundData(soundData), bufferSize, type);
}
