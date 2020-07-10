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
		static constexpr size_t bufferCopySize = 4096;
		audio::Source* source = nullptr;
		StreamMemory* stream = nullptr;
		std::string path;
		std::array<uint8_t, bufferCopySize> bufferCopy;
		std::array<float, bufferCopySize / 8> wavValue;
		std::array<float, bufferCopySize / 8> fftWindow;
		char* fftWorkset = nullptr;
		float* fftOutComplex = nullptr;
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
		const std::string& getPath() const noexcept override { return path; }

		size_t getFFTSize() const;
		float* getFFT();

		std::unordered_map<std::string, std::string> getInfo() const override;
	protected:
		size_t fillBufferCopy();
		size_t fillWavValue();
		bool check_fft_tmp();
		bool do_fft();

		bool init(StreamMemory* _data);
		ResAudio(const std::string& name, ResourceType type, const std::string& _path);
	public:
		virtual ~ResAudio();
	};
	// sound effect
	class ResSound :
		public ResAudio
	{
		bool initWithBuffer(Buffer* data);
		ResSound(const std::string& name, const std::string& path);
		~ResSound();
	public:

		static ResSound* create(const std::string& name, const std::string& path);
	};
	// background music
	class ResMusic :
		public ResAudio
	{
		bool initWithBuffer(Buffer* data, double loopA, double loopB);
		ResMusic(const std::string& name, const std::string& path);
		~ResMusic();
	public:
		static ResMusic* create(const std::string& name, const std::string& path,
			double loopStart, double loopEnd);
	};
}
