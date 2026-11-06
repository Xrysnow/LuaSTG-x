#pragma once
#include "audio/AudioStreamAdapter.h"
#include "audio/AudioDecoder.h"
#include <string>

namespace cocos2d
{
	class AudioSoundData;
}

namespace lstg
{
	using AudioInputResult = cocos2d::io::Result<cocos2d::ThreadSafeRefPtr<cocos2d::AudioStreamAdapter>>;
	using AudioDecodeResult = cocos2d::io::Result<cocos2d::RefPtr<cocos2d::AudioDecoder>>;

	// Host setup/complete shutdown only, without concurrent stream creation.
	// Engine restarts and game resets retain this resource-system configuration.
	void installAudioFileOpener();
	void clearAudioFileOpener();

	// Independent immutable input snapshots with an owned Atomic adapter and
	// cursor. These factories do not use autorelease pools or expose a Lua object.
	AudioInputResult createAudioInputFromStringData(const std::string& bytes);
	// Copies raw PCM bytes; it does not encode a WAV/OGG/FLAC/MP3 container.
	AudioInputResult createAudioInputFromSoundData(const cocos2d::AudioSoundData* soundData);

	// Returned decoders have an independent strong reference. Creating a core
	// decoder still requires the caller's normal cocos autorelease pool.
	AudioDecodeResult decodeAudioStringData(const std::string& bytes,
		size_t bufferSize, cocos2d::AudioDecoder::DecoderType type);
	AudioDecodeResult decodeAudioSoundData(const cocos2d::AudioSoundData* soundData,
		size_t bufferSize, cocos2d::AudioDecoder::DecoderType type);
}
