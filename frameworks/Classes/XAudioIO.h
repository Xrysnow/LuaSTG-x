#pragma once
#include "audio/AudioStreamAdapter.h"
#include "audio/AudioDecoder.h"
#include <string>

namespace cc
{
	class AudioSoundData;
}

namespace lstg
{
	using AudioInputResult = cc::io::Result<cc::ThreadSafeRefPtr<cc::AudioStreamAdapter>>;
	using AudioDecodeResult = cc::io::Result<cc::IntrusivePtr<cc::AudioDecoder>>;

	// Host setup/complete shutdown only, without concurrent stream creation.
	// Engine restarts and game resets retain this resource-system configuration.
	void installAudioFileOpener();
	void clearAudioFileOpener();

	// Independent immutable input snapshots with an owned Atomic adapter and
	// cursor. These factories do not use autorelease pools or expose a Lua object.
	AudioInputResult createAudioInputFromStringData(const std::string& bytes);
	// Copies raw PCM bytes; it does not encode a WAV/OGG/FLAC/MP3 container.
	AudioInputResult createAudioInputFromSoundData(const cc::AudioSoundData* soundData);

	// Returned decoders have an independent strong reference and require no pool.
	AudioDecodeResult decodeAudioStringData(const std::string& bytes,
		size_t bufferSize, cc::AudioDecoder::DecoderType type);
	AudioDecodeResult decodeAudioSoundData(const cc::AudioSoundData* soundData,
		size_t bufferSize, cc::AudioDecoder::DecoderType type);
}
