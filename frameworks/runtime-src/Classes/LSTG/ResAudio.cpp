#include "ResAudio.h"
#include "../Audio/AudioEngine.h"
//#include "../Audio/AudioDecoderManager.h"
//#include "../Audio/AudioDecoder.h"
#include "LogSystem.h"
#include "AppFrame.h"
#include "Utility.h"
#include "Math/XFFT.h"

using namespace std;
using namespace lstg;
using AudioState = XAudioEngine::AudioState;
//TODO: add start time
void ResAudio::play()
{
	if (isStopped())
	{
		//fcyStopWatch sw;
		audioID = XAudioEngine::play2d(path, &param, true);
		if (audioID == XAudioEngine::INVALID_AUDIO_ID)
		{
			XINFO("failed to play [%s]", resName.c_str());
			return;
		}
		if (XAudioEngine::getState(audioID) == AudioState::INITIALIZING)
		{
			XINFO("[%s] still initializing", resName.c_str());
		}
		//XINFO("audio [%s] load cost %fms", resName.c_str(), sw.GetElapsed() * 1000);
	}
	else
	{		
		auto state = XAudioEngine::getState(audioID);
		if (state == AudioState::INITIALIZING)
		{
			XAudioEngine::setSourceParam(audioID, param);
			XINFO("[%s] is still initializing", resName.c_str());
		}
		else
		{
			XAudioEngine::pause(audioID);
			XAudioEngine::setSourceParam(audioID, param);
			XAudioEngine::setCurrentTime(audioID, 0.f);
			XAudioEngine::resume(audioID);		
			//XINFO("audio [%s] is playing, reset", resName.c_str());
		}
	}
}

void ResAudio::play(float vol, float pan)
{
	param.position.x = pan;
	param.volume = vol;
	play();
}

void ResAudio::resume()
{
	if (isPlaying())
		return;
	if (isStopped())
	{
		play();
		return;
	}
	XAudioEngine::resume(audioID);
}

void ResAudio::pause()
{
	auto state = XAudioEngine::getState(audioID);
	if (state == AudioState::INITIALIZING)
	{
		cache->addPlayCallback([this]() { XAudioEngine::pause(audioID); });
		XINFO("[%s] is still initializing", resName.c_str());
	}
	else
		XAudioEngine::pause(audioID);
	_sinceLastCurrentTime = 0;
}

void ResAudio::stop()
{
	XAudioEngine::stop(audioID);
	_sinceLastCurrentTime = 0;
}

bool ResAudio::isPlaying()
{
	auto state = XAudioEngine::getState(audioID);
	return state == AudioState::PLAYING || state == AudioState::INITIALIZING;
}

bool ResAudio::isStopped()
{
	auto state = XAudioEngine::getState(audioID);
	return state == AudioState::ERROR;
}

float ResAudio::getTime()
{
	return XAudioEngine::getCurrentTime(audioID);
}

void ResAudio::setTime(float time)
{
	auto state = XAudioEngine::getState(audioID);
	if (state == AudioState::INITIALIZING)
	{
		cache->addPlayCallback([this, time]() { XAudioEngine::setCurrentTime(audioID, time); });
		XINFO("[%s] is still initializing", resName.c_str());
	}
	else
	{
		XAudioEngine::setCurrentTime(audioID, time);
		//XINFO("audio [%s] set time to %f", resName.c_str(), time);
	}
}

float ResAudio::getTotalTime()
{
	const auto t = XAudioEngine::getDuration(audioID);
	if (t == XAudioEngine::TIME_UNKNOWN && cache)
		return cache->getDuration();
	return t;
}

void ResAudio::setVolume(float v)
{
	param.volume = v;
	XAudioEngine::setVolume(audioID, v);
}

void ResAudio::setParam(const xAudio::SourceParam& _param)
{
	param = _param;
	XAudioEngine::setSourceParam(audioID, param);
}

void ResAudio::setPosition(const cocos2d::Vec3& pos)
{
	param.position = pos;
	XAudioEngine::setSourceParam(audioID, param);
}

void ResAudio::setVelocity(const cocos2d::Vec3& v)
{
	param.velocity = v;
	XAudioEngine::setSourceParam(audioID, param);
}

void ResAudio::setPitch(float pitch)
{
	param.pitch = pitch;
	XAudioEngine::setSourceParam(audioID, param);
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
	if(cache)
	{
		if (cache->isLoopAB())
		{
			double a, b;
			cache->getLoopAB(a, b);
			ret += StringFormat("loop = %f, %f | ", a, b);
		}
		ret += StringFormat("%u Hz, %u ch, %u frames, %f s",
			cache->getSampleRate(),
			cache->getChannelCount(),
			cache->getTotalFrames(),
			cache->getDuration()
		);
	}
	else
		ret += "no cache";
	return ret;
}

size_t ResAudio::fillBufferCopy()
{
	if (!isPlaying())return 0;
	auto player = XAudioEngine::getPlayer(audioID);
	if(!player)return 0;
	size_t offset = 0;
	const auto curr = XAudioEngine::getCurrentTime(audioID);
	if (player->isStreamingSource())
	{
		if (curr != _lastCurrentTime)
		{
			_lastCurrentTime = curr;
			_sinceLastCurrentTime = 0;
		}
		else
		{
			_sinceLastCurrentTime++;
		}
		if (_sinceLastCurrentTime > 0)
		{
			const auto dt = cocos2d::Director::getInstance()->getAnimationInterval();
			offset = (dt * _sinceLastCurrentTime)*cache->getSampleRate()*cache->getBytesPerFrame();
		}
		else
			offset = 0;
	}
	else
	{
		offset = curr * cache->getSampleRate()*cache->getBytesPerFrame();
	}
	return player->copyBuffer((char*)bufferCopy.data(), bufferCopy.size(), offset);
}

size_t ResAudio::fillWavValue()
{
	wavValue.fill(0.f);
	const auto size = fillBufferCopy();
	if (size == 0)return 0;
	const auto nBA = cache->getBytesPerFrame();
	const auto nCh = cache->getChannelCount();
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
	param.position.z = -1.f;// note: set this
	return true;
}

ResAudio::ResAudio(const std::string& name, ResourceType type, const std::string& _path):
	Resource(type, name), audioID(XAudioEngine::INVALID_AUDIO_ID)
{
	path = _path;
}

ResAudio::~ResAudio()
{
	CC_SAFE_RELEASE_NULL(stream);
	XAudioEngine::uncache(path);
	if (fftWorkset)
	{
		free(fftWorkset);
		free(fftOutComplex);
	}
}

void ResSound::play(float vol, float pan)
{
	ResAudio::play(vol, pan);
}

void ResSound::setVolume(float v)
{
	ResAudio::setVolume(v);
}

bool ResSound::initWithBuffer(Buffer* data)
{
	if (!data)
		return false;
	const auto memory = StreamMemory::create(data->data(), data->size(), true, false, false);
	if(!memory)
		return false;
	if (!init(memory))
		return false;
	XAudioEngine::preload(path, XAudioStream::create(memory), nullptr, &cache);
	if (cache)
		cache->blockToReady();
	else
	{
		XINFO("failed to load cache of '%s' at [%s]", getName().c_str(), path.c_str());
		return false;
	}
	return true;
}

ResSound::ResSound(const std::string& name, const std::string& path) :
	ResAudio(name, ResourceType::SoundEffect, path)
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

void ResMusic::play(float vol, float pan)
{
	ResAudio::play(vol, pan);
}

void ResMusic::setVolume(float v)
{
	ResAudio::setVolume(v);
}

bool ResMusic::initWithBuffer(Buffer* data, double loopA, double loopB)
{
	if (!data)
		return false;
	const auto memory = StreamMemory::create(data->data(), data->size(), true, false, false);
	if (!memory)
		return false;
	if (!init(memory))
		return false;
	XAudioEngine::preload(path, XAudioStream::create(memory), loopA, loopB, nullptr, &cache);
	if (cache)
		cache->blockToReady();
	else
	{
		XINFO("failed to load cache of '%s' at [%s]", getName().c_str(), path.c_str());
		return false;
	}
	return true;
}

ResMusic::ResMusic(const std::string& name, const std::string& path) :
	ResAudio(name, ResourceType::Music, path)
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
