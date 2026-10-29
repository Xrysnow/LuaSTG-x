#pragma once
#include "XStream.h"
#include "cocos/audio/AudioStream.h"
#include "cocos/audio/AudioDecoder.h"

namespace cocos2d
{
	class AudioSoundData;
}

namespace lstg
{
	class XAudioStream : public cocos2d::AudioStream
	{
		cocos2d::RefPtr<Stream> _src;
	public:
		// Retains src; the returned wrapper follows cocos autorelease ownership.
		static XAudioStream* create(Stream* src);

		uint64_t size() override;
		uint64_t tell() override;
		bool seek(SeekOrigin origin, int64_t offset) override;
		bool read(uint8_t* dst, uint64_t length, uint64_t* bytesRead = nullptr) override;
		void lock() override;
		void unlock() override;
	};

	// Host setup/complete shutdown only, without concurrent stream creation.
	// Engine restarts and game resets retain this resource-system configuration.
	void installAudioFileOpener();
	void clearAudioFileOpener();

	cocos2d::AudioStream* createAudioStreamFromStringData(const std::string& str);
	// Copies raw PCM bytes into independent storage; does not encode a file.
	cocos2d::AudioStream* createAudioStreamFromSoundData(cocos2d::AudioSoundData* soundData);
	cocos2d::AudioDecoder* createAudioDecoderFromStringData(const std::string& str,
		size_t bufferSize, cocos2d::AudioDecoder::DecoderType type);
	cocos2d::AudioDecoder* createAudioDecoderFromSoundData(cocos2d::AudioSoundData* soundData,
		size_t bufferSize, cocos2d::AudioDecoder::DecoderType type);
}
