#include "ResAudio.h"
#include "LogSystem.h"
#include "AppFrame.h"
#include "Utility.h"
#include "ResourceMgr.h"
#include "../Math/XFFT.h"
#include "../Audio/AudioDecoder.h"
#include "../Audio/AudioEngine.h"

using namespace std;
using namespace lstg;

void ResAudio::play()
{
	if (!source)
		return;
	if (!isPlaying())
	{
		source->play();
	}
	else
	{
		source->setTime(0);
	}
}

void ResAudio::play(float vol, float pan)
{
	if (!source)
		return;
	source->setVolume(vol);
	source->setPosition({ pan,0,0 });
	play();
}

void ResAudio::resume()
{
	if (source)
		play();
}

void ResAudio::pause()
{
	if (source)
		source->pause();
}

void ResAudio::stop()
{
	if(source)
		source->stop();
}

bool ResAudio::isPlaying()
{
	return source ? source->isPlaying() : false;
}

bool ResAudio::isStopped()
{
	return source ? source->isFinished() : true;
}

size_t ResAudio::getFFTSize() const
{
	return fftOutNorm.size();
}

float* ResAudio::getFFT()
{
	// keep value when it's not 0 to avoid flicker
	//if (_sinceLastCurrentTime == 0)
	//	fftOutNorm.fill(0.f);
	if (fillWavValue() == wavValue.size())
		do_fft();
	return fftOutNorm.data();
}

string ResAudio::getInfo() const
{
	auto ret = Resource::getInfo() + " | ";
	if(source)
	{
		if (source->isLooping())
		{
			ret += StringFormat("loop = %f, %f | ", source->getLoopingStart(), source->getLoopingEnd());
		}
		ret += StringFormat("%d Hz, %d ch, %d frames, %.3f s",
			int((double)source->getTotalFrames() / source->getTotalTime()),
			source->getChannelCount(),
			source->getTotalFrames(),
			source->getTotalTime()
		);
	}
	else
		ret += "no source";
	return ret;
}

size_t ResAudio::fillBufferCopy()
{
	if (!isPlaying() || !source)
		return 0;
	size_t offset = 0;
	const auto off = source->getBufferOffset();
	const auto curr = source->tell();
	if (curr > off)
		offset = (curr - off)*source->getBytesPerFrame();
	return source->copyBuffer((char*)bufferCopy.data(), bufferCopy.size(), offset);
}

size_t ResAudio::fillWavValue()
{
	if (!source)
		return 0;
	wavValue.fill(0.f);
	const auto size = fillBufferCopy();
	if (size == 0)return 0;
	const auto nBA = source->getBytesPerFrame();
	const auto nCh = source->getChannelCount();
	const auto factor = 1u << (nBA / nCh * 8 - 1);
	size_t filled = 0;
	if (nCh == 1)
	{
		for (size_t i = 0; i < wavValue.size(); i++)
		{
			filled = i + 1;
			if (i * nBA >= size)
				break;
			int64_t val = 0;
			for (size_t j = 0; j < nBA; ++j)
				val += bufferCopy[j + i * nBA] << (j * 8);
			if (val > factor - 1)
				val = val - factor * 2;
			wavValue[i] = double(val) / factor * fftWindow[i];
		}
	}
	else
	{
		//auto val = new int64_t[nCh];
		for (size_t i = 0; i < wavValue.size(); i++)
		{
			filled = i + 1;
			if (i * nBA >= size)
				break;
			//for (size_t k = 0; k < nCh; ++k)
			//{
			//	val[k] = 0;
			//	for (size_t j = 0; j < nBA / nCh; ++j)
			//		val[k] ^= bufferCopy[j + i * nBA + k * nBA / nCh] << (j * 8);
			//	if (val[k] > factor - 1)
			//		val[k] = val[k] - factor * 2;
			//}
			//wavValue[i] = double(val[0]) / factor * fftWindow[i];

			// only calculate channel 0
			int64_t val = 0;
			for (size_t j = 0; j < nBA / nCh; ++j)
				val ^= bufferCopy[j + i * nBA] << (j * 8);
			if (val > factor - 1)
				val = val - factor * 2;
			wavValue[i] = double(val) / factor * fftWindow[i];
		}
		//delete[] val;
	}
	return filled;
}

bool ResAudio::check_fft_tmp()
{
	if(!fftWorkset)
	{
		fftWorkset = (char*)malloc(xmath::fft::getNeededWorksetSize(wavValue.size()));
		if (!fftWorkset)
			return false;
		fftOutComplex = (float*)malloc(wavValue.size() * sizeof(float) * 2);
		if (!fftOutComplex)
		{
			free(fftWorkset);
			fftWorkset = nullptr;
			return false;
		}
		xmath::fft::getWindow(fftWindow.size(), fftWindow.data());
	}
	return true;
}

bool ResAudio::do_fft()
{
	if (!check_fft_tmp())
		return false;
	xmath::fft::fft(wavValue.size(), fftWorkset, wavValue.data(), fftOutComplex, fftOutNorm.data());
	return true;
}

bool ResAudio::init(StreamMemory* _data)
{
	if (!_data)
		return false;
	stream = _data;
	stream->retain();
	if (!audio::Engine::isValid())
		return true;
	auto s = XAudioStream::create(stream);
	if (!s)
		return false;
	auto d = audio::Decoder::createFromStream(s, 4096, audio::Decoder::getDecoderTypeFromPath(path));
	if (!d)
	{
		XINFO("failed to create Decoder");
		return false;
	}
	source = audio::Source::createFromDecoder(d);
	if (!source)
	{
		XINFO("failed to create Source");
		return false;
	}
	source->retain();
	return true;
}

ResAudio::ResAudio(const std::string& name, ResourceType type, const std::string& _path):
	Resource(type, name)
{
	path = _path;
	resPath = _path;
}

ResAudio::~ResAudio()
{
	CC_SAFE_RELEASE_NULL(stream);
	CC_SAFE_RELEASE_NULL(source);
	if (fftWorkset)
	{
		free(fftWorkset);
		free(fftOutComplex);
	}
}

bool ResSound::initWithBuffer(Buffer* data)
{
	if (!data)
		return false;
	const auto memory = StreamMemory::create(data);
	if(!memory)
	{
		XINFO("failed to create StreamMemory");
		return false;
	}
	return init(memory);
}

ResSound::ResSound(const std::string& name, const std::string& path)
	:ResAudio(name, ResourceType::SoundEffect, path)
{
}

ResSound::~ResSound()
{
}

ResSound* ResSound::create(const std::string& name, const std::string& path)
{
	const auto data = LRES.getBufferFromFile(path);
	if (!data)
		return nullptr;
	auto ret = new (nothrow) ResSound(name, path);
	if (ret && ret->initWithBuffer(data))
	{
		//ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool ResMusic::initWithBuffer(Buffer* data, double loopA, double loopB)
{
	if (!data)
		return false;
	const auto memory = StreamMemory::create(data);
	if (!memory)
		return false;
	if (!init(memory))
		return false;
	if (source)
	{
		source->setLooping(true);
		source->setLoopingPoint(loopA, loopB);		
	}
	return true;
}

ResMusic::ResMusic(const std::string& name, const std::string& path)
	:ResAudio(name, ResourceType::Music, path)
{
}

ResMusic::~ResMusic()
{
}

ResMusic* ResMusic::create(const std::string& name, const std::string& path, double loopStart, double loopEnd)
{
	const auto data = LRES.getBufferFromFile(path);
	if (!data)
		return nullptr;
	auto ret = new (nothrow) ResMusic(name, path);
	if (ret && ret->initWithBuffer(data, loopStart, loopEnd))
	{
		//ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}
