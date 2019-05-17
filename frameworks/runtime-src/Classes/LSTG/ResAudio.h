#pragma once
#include "ResBase.h"
#include "../Audio/AudioParam.h"
#include "../Audio/AudioCache.h"
#include "../Classes/XBuffer.h"
#include "../Classes/XStream.h"

namespace lstg {

	class ResAudio :
		public Resource
	{
	protected:
		static constexpr size_t bufferCopySize = 4096;
		int audioID;
		xAudio::SourceParam param;
		xAudio::AudioCache* cache = nullptr;
		StreamMemory* stream = nullptr;
		std::string path;
		std::array<uint8_t, bufferCopySize> bufferCopy;
		std::array<float, bufferCopySize / 8> wavValue;
		std::array<float, bufferCopySize / 8> fftWindow;
		char* fftWorkset = nullptr;
		float* fftOutComplex = nullptr;
		std::array<float, bufferCopySize / 16> fftOutNorm;
		float _lastCurrentTime = 0.f;
		uint32_t _sinceLastCurrentTime = 0;
	public:
		void play();
		virtual void play(float vol, float pan = 0.f);

		void resume();

		void pause();

		void stop();

		bool isPlaying();

		bool isStopped();
		// current time in seconds
		float getTime();
		// set time in seconds
		void setTime(float time);
		// total time in seconds
		float getTotalTime();

		virtual void setVolume(float v);

		xAudio::AudioCache* getCache() const { return cache; }
		StreamMemory* getStream() const { return stream; }
		const std::string& getPath() const noexcept override { return path; }
		xAudio::SourceParam getParam() const { return param; }
		void setParam(const xAudio::SourceParam& _param);
		void setPosition(const cocos2d::Vec3& pos);
		void setVelocity(const cocos2d::Vec3& v);
		void setPitch(float pitch);

		size_t getFFTSize() const;
		float* getFFT();

		std::string getInfo()const override;
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
	public:

		void play(float vol, float pan = 0.f) override;
		void setVolume(float v) override;
	private:

		bool initWithBuffer(Buffer* data);
		ResSound(const std::string& name, const std::string& path);
		~ResSound();
	public:

		static ResSound* create(const std::string& name, const std::string& path);
	};
	// background music TODO: FFT
	class ResMusic :
		public ResAudio
	{
	public:
		//bool ReadCurrentData(fData pBuffer, fuInt SizeToRead, fuInt* pSizeRead);
		//bool GetFFT(float* in, fuInt N);

		void play(float vol, float pan = 0.f) override;
		void setVolume(float v) override;
	private:

		bool initWithBuffer(Buffer* data, double loopA, double loopB);
		ResMusic(const std::string& name, const std::string& path);
		~ResMusic();
	public:
		static ResMusic* create(const std::string& name, const std::string& path,
			double loopStart, double loopEnd);
	};
}
