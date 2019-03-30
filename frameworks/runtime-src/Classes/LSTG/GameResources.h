#pragma once
#include "ResBase.h"
#include "ResTexture.h"
#include "ResAnimation.h"
#include "ResSprite.h"
#include "ResParticle.h"
#include "ResFont.h"
#include "ResAudio.h"
#include "ResFX.h"
#include "ResRenderTarget.h"

namespace lstg
{
	//TODO: WIP
	/*
	class ResVideo :
	public Resource
	{
	private:
	fcyRefPointer<f2dVideo> m_pVideo;
	BlendMode m_BlendMode = BlendMode::MulAlpha;
	Color4B m_Color[4];
	public:
	BlendMode GetBlendMode()const LNOEXCEPT { return m_BlendMode; }
	void SetBlendMode(BlendMode m)LNOEXCEPT { m_BlendMode = m; }
	Color4B GetColor(fuInt Index)LNOEXCEPT {
	if (Index >= 4)
	return Color4B();
	return m_Color[Index];
	}
	void SetColor(Color4B c)LNOEXCEPT {
	for (int i = 0; i < 4; ++i)
	m_Color[i] = c;
	}
	void SetColor(Color4B* cArr)LNOEXCEPT {//TODO 未做检查
	memcpy(m_Color, cArr, sizeof(Color4B) * 4);
	}
	public:
	void Play(float vol, float pan)
	{
	m_pVideo->Stop();

	float nv = VolumeFix(vol);
	if (m_pVideo->GetVolume() != nv)
	m_pVideo->SetVolume(nv);
	if (m_pVideo->GetPan() != pan)
	m_pVideo->SetPan(pan);

	m_pVideo->Play();
	}

	void Update() { m_pVideo->Update(); }
	f2dTexture2D* GetVideoTex() { return static_cast<f2dTexture2D*>(m_pVideo->GetVideoTex()); }
	fuInt GetVideoWidth() { return m_pVideo->GetVideoWidth(); }
	fuInt GetVideoHeight() { return m_pVideo->GetVideoHeight(); }
	float GetVideoDataRate() { return m_pVideo->GetVideoDataRate(); }
	float GetVideoRenderFPS() { return m_pVideo->GetVideoRenderFPS(); }
	F2DVIDEOSTATE GetState() { return m_pVideo->GetState(); }
	void Resume() { m_pVideo->Play(); }
	void Pause() { m_pVideo->Pause(); }
	void Stop() { m_pVideo->Stop(); }
	void SetLoop(fBool bLoop) { m_pVideo->SetLoop(bLoop); }
	bool IsLoop() { return m_pVideo->IsLoop(); }
	fDouble GetTotalTime() { return m_pVideo->GetTotalTime(); }
	fDouble GetCurTime() { return m_pVideo->GetCurTime(); }
	fResult SetCurTime(fDouble Time) { return m_pVideo->SetCurTime(Time); }
	fResult Seek(fuInt KeyFrame) { return m_pVideo->Seek(KeyFrame); }
	fDouble GetRate() { return m_pVideo->GetRate(); }
	fResult SetRate(fDouble Rate) { return m_pVideo->SetRate(Rate); }
	float GetVolume() { return m_pVideo->GetVolume(); }
	fResult SetVolume(float Volume) { return m_pVideo->SetVolume(Volume); }
	float GetPan() { return m_pVideo->GetPan(); }
	fResult SetPan(float Pan) { return m_pVideo->SetPan(Pan); }

	public:
	ResVideo(const char* name, fcyRefPointer<f2dVideo> video)
	: Resource(ResourceType::SoundEffect, name), m_pVideo(video)
	{
	SetColor(Color4B(255, 255, 255, 255));
	}
	};
	*/
}
