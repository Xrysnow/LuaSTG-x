#pragma once
#include "ResBase.h"
#include "../Audio/AudioSource.h"
#include "../Classes/XBuffer.h"
#include "../Classes/XStream.h"

namespace lstg
{
	class ResAudio :
		public Resource
	{
	protected:
		// note: decoderBufferSize should >= bufferCopySize
		static constexpr size_t bufferCopySize = 4096;
		static constexpr size_t decoderBufferSize = 4096;
		cocos2d::RefPtr<audio::Source> source;
		cocos2d::RefPtr<StreamMemory> stream;
		std::string path;
		std::array<uint8_t, bufferCopySize> bufferCopy;
		std::array<float, bufferCopySize / 8> wavValue;
		std::array<float, bufferCopySize / 8> fftWindow;
		std::vector<char> fftWorkset;
		std::vector<float> fftOutComplex;
		std::array<float, bufferCopySize / 16> fftOutNorm;
	public:
		void play();
		void play(float vol, float pan = 0.f);

		void resume();

		void pause();

		void stop();

		bool isPlaying();

		bool isStopped();

		audio::Source* getSource() const { return source; }
		StreamMemory* getStream() const { return stream; }
		const std::string& getPath() const override { return path; }

		size_t getFFTSize() const;
		float* getFFT();

		std::unordered_map<std::string, std::string> getInfo() const override;
		size_t getMemorySize() override;
	protected:
		size_t fillBufferCopy();
		size_t fillWavValue();
		bool checkFFT();
		bool doFFT();

		bool init(StreamMemory* stream_);
		ResAudio(const std::string& name, ResourceType type, const std::string& _path);
	public:
		~ResAudio() override;
	};
	// sound effect
	class ResSound :
		public ResAudio
	{
		bool initWithBuffer(Buffer* data);
		ResSound(const std::string& name, const std::string& path);
		~ResSound() override;
	public:
		static ResSound* create(const std::string& name, const std::string& path);
	};
	// background music
	class ResMusic :
		public ResAudio
	{
		bool initWithBuffer(Buffer* data, double loopA, double loopB);
		ResMusic(const std::string& name, const std::string& path);
		~ResMusic() override;
	public:
		static ResMusic* create(const std::string& name, const std::string& path,
			double loopStart, double loopEnd);
	};
}
