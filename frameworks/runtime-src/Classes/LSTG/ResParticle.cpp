#include "ResParticle.h"
#include "AppFrame.h"
#include "Utility.h"
#include "Renderer.h"
#include "../fcyLib/fcyMemPool.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

static fcyMemPool<sizeof(ResParticle::ParticlePool)> s_MemoryPool;

Color4B ResParticle::ParticlePool::getColorStart() noexcept
{
	Color4B ret;
	if (particleInfo.ColorStart[0] < 0)
	{
		const auto sp = _res->getBindSprite();
		ret = Color4B(sp->getColor());
		ret.a = sp->getOpacity();
	}
	else
	{
		ret.r = particleInfo.ColorStart[0] * 255;
		ret.g = particleInfo.ColorStart[1] * 255;
		ret.b = particleInfo.ColorStart[2] * 255;
		ret.a = particleInfo.ColorStart[3] * 255;
	}
	return ret;
}

void ResParticle::ParticlePool::setColorStart(const Color4B& color) noexcept
{
	particleInfo.ColorStart[0] = color.r / 255.f;
	particleInfo.ColorStart[1] = color.g / 255.f;
	particleInfo.ColorStart[2] = color.b / 255.f;
	particleInfo.ColorStart[3] = color.a / 255.f;
}

Color4B ResParticle::ParticlePool::getColorEnd() noexcept
{
	Color4B ret;
	if (particleInfo.ColorEnd[0] < 0)
	{
		const auto sp = _res->getBindSprite();
		ret = Color4B(sp->getColor());
		ret.a = sp->getOpacity();
	}
	else
	{
		ret.r = particleInfo.ColorEnd[0] * 255;
		ret.g = particleInfo.ColorEnd[1] * 255;
		ret.b = particleInfo.ColorEnd[2] * 255;
		ret.a = particleInfo.ColorEnd[3] * 255;
	}
	return ret;
}

void ResParticle::ParticlePool::setColorEnd(const Color4B& color) noexcept
{
	particleInfo.ColorEnd[0] = color.r / 255.f;
	particleInfo.ColorEnd[1] = color.g / 255.f;
	particleInfo.ColorEnd[2] = color.b / 255.f;
	particleInfo.ColorEnd[3] = color.a / 255.f;
}

void ResParticle::ParticlePool::setActive(bool b) noexcept
{
	if (b)
	{
		status = Status::Alive;
		life = 0.f;
	}
	else
		status = Status::Sleep;
}

void ResParticle::ParticlePool::setCenter(const cocos2d::Vec2& pos) noexcept
{
	if (status == Status::Alive)
		prevCenter = center;
	else
		prevCenter = pos;
	center = pos;
}

void ResParticle::ParticlePool::Update(float delta)
{
	//const ParticleInfo& pInfo = m_pInstance->getParticleInfo();
	const auto& pInfo = particleInfo;

	if (status == Status::Alive)
	{
		life += delta;
		if (life >= pInfo.Lifetime && pInfo.Lifetime >= 0.f)
			status = Status::Sleep;
	}

	// 更新所有粒子
	size_t i = 0;
	while (i < numAlive)
	{
		ParticleInstance& tInst = particlePool[i];
		tInst.life += delta;
		if (tInst.life >= tInst.terminalLife)
		{
			--numAlive;
			if (numAlive > i + 1)
				memcpy(&tInst, &particlePool[numAlive], sizeof(ParticleInstance));
			continue;
		}

		// 计算线加速度和切向加速度
		auto vecAccel = tInst.vecLocation - center;
		vecAccel.normalize();
		auto vecAccel2 = vecAccel;
		vecAccel *= tInst.radialAccel;
		// vecAccel2.Rotate(M_PI_2);
		swap(vecAccel2.x, vecAccel2.y);
		vecAccel2.x = -vecAccel2.x;
		vecAccel2 *= tInst.tangentialAccel;

		// 计算速度
		tInst.vecVelocity += (vecAccel + vecAccel2) * delta;
		tInst.vecVelocity.y += tInst.gravity * delta;

		// 计算位置
		tInst.vecLocation += tInst.vecVelocity * delta;

		// 计算自旋和大小
		tInst.spin += tInst.spinDelta * delta;
		tInst.size += tInst.sizeDelta * delta;
		tInst.color[0] += tInst.colorDelta[0] * delta;
		tInst.color[1] += tInst.colorDelta[1] * delta;
		tInst.color[2] += tInst.colorDelta[2] * delta;
		tInst.color[3] += tInst.colorDelta[3] * delta;

		++i;
	}

	// 产生新的粒子
	if (status == Status::Alive)
	{
		//const auto fParticlesNeeded = emissionFreq * delta + emissionResidue;
		const auto fParticlesNeeded = pInfo.EmissionFreq * delta + emissionResidue;
		const auto nParticlesCreated = uint32_t(fParticlesNeeded);
		emissionResidue = fParticlesNeeded - float(nParticlesCreated);

		for (i = 0; i < nParticlesCreated; ++i)
		{
			if (numAlive >= particlePool.size())
				break;

			ParticleInstance& tInst = particlePool[numAlive++];
			tInst.life = 0.0f;
			tInst.terminalLife = _rand.GetRandFloat(pInfo.LifeMin, pInfo.LifeMax);
			// magic numbers here
			tInst.vecLocation = prevCenter + (center - prevCenter) * _rand.GetRandFloat(0.0f, 1.0f);
			tInst.vecLocation.x += _rand.GetRandFloat(-2.0f, 2.0f);
			tInst.vecLocation.y += _rand.GetRandFloat(-2.0f, 2.0f);

			const float ang = /* pInfo.fDirection */ (rotation - float(LPI_HALF)) - float(LPI_HALF) +
				_rand.GetRandFloat(0, pInfo.Spread) - pInfo.Spread / 2.0f;
			tInst.vecVelocity.x = cos(ang);
			tInst.vecVelocity.y = sin(ang);
			tInst.vecVelocity *= _rand.GetRandFloat(pInfo.SpeedMin, pInfo.SpeedMax);

			tInst.gravity = _rand.GetRandFloat(pInfo.GravityMin, pInfo.GravityMax);
			tInst.radialAccel = _rand.GetRandFloat(pInfo.RadialAccelMin, pInfo.RadialAccelMax);
			tInst.tangentialAccel = _rand.GetRandFloat(pInfo.TangentialAccelMin, pInfo.TangentialAccelMax);

			tInst.size = _rand.GetRandFloat(
				pInfo.SizeStart,
				pInfo.SizeStart + (pInfo.SizeEnd - pInfo.SizeStart) * pInfo.SizeVar);
			tInst.sizeDelta = (pInfo.SizeEnd - tInst.size) / tInst.terminalLife;

			tInst.spin = /* pInfo.fSpinStart */ rotation +
				_rand.GetRandFloat(0, pInfo.SpinEnd) - pInfo.SpinEnd / 2.0f;
			tInst.spinDelta = pInfo.SpinVar;

			auto _var = pInfo.ColorVar;
			for (int j = 0; j < 4; ++j)
			{
				if (j == 3)_var = pInfo.AlphaVar;
				tInst.color[j] = _rand.GetRandFloat(
					pInfo.ColorStart[j],
					pInfo.ColorStart[j] + (pInfo.ColorEnd[j] - pInfo.ColorStart[j])*_var);
			}
			for (int j = 0; j < 4; ++j)
			{
				tInst.colorDelta[j] = (pInfo.ColorEnd[j] - tInst.color[j]) / tInst.terminalLife;
			}
		}
	}

	prevCenter = center;
}

void ResParticle::ParticlePool::Render(float scaleX, float scaleY)
{
	Sprite* p = _res->getBindSprite();
	const auto no_ins_color = particleInfo.ColorStart[0] < 0;
	const auto _color = p->getColor();
	const auto _alpha = p->getOpacity();

	LRR.updateBlendMode(blendMode);

	for (size_t i = 0; i < numAlive; ++i)
	{
		ParticleInstance& pInst = particlePool[i];
		if (no_ins_color)  // r < 0
		{
			//p->setColor(tOrgColor);
		}
		else
		{
			p->setColor(Color3B(
				pInst.color[0] * 255,
				pInst.color[1] * 255,
				pInst.color[2] * 255
			));
		}
		p->setOpacity(pInst.color[3] * 255);
		//TODO: merge triangles
		LRR.render(p, nullptr, pInst.vecLocation.x, pInst.vecLocation.y, CC_RADIANS_TO_DEGREES(pInst.spin),
			scaleX * pInst.size, scaleY * pInst.size);
	}
	p->setColor(_color);
	p->setOpacity(_alpha);
}

ResParticle::ParticlePool::ParticlePool(ResParticle* ref)
	: _res(ref)//, emissionFreq(float(ref->getParticleInfo().EmissionFreq)), m_ParticlePool()
{
	_res->retain();
	particleInfo = _res->getParticleInfo();
}

ResParticle::ParticlePool::~ParticlePool()
{
	_res->release();
}

ResParticle::ParticlePool* ResParticle::AllocInstance()noexcept
{
	// ！ 警告：潜在bad_alloc导致错误，暂时不予处理
	ParticlePool* pRet = new(s_MemoryPool.Alloc()) ParticlePool(this);
	pRet->setBlendMode(blendMode);
	//pRet->setSeed(uint32_t(time(nullptr)));
	return pRet;
}

void ResParticle::FreeInstance(ParticlePool* p)noexcept
{
	CC_ASSERT(p);
	p->~ParticlePool();
	s_MemoryPool.Free(p);
}

string ResParticle::getInfo() const
{
	string ret = Resource::getInfo();
	string format = " | Blend Mode = %s | ParticleInfo = { | %w = %u | ";
	int i;
	for (i = 0; i < 5; ++i) format += "%w = %f | ";
	format += "%w = %b | ";
	for (i = 0; i < 14; ++i) format += "%w = %f | ";
	for (i = 0; i < 2; ++i) format += "%w = %f, %f, %f, %f | ";
	format += "%w = %f | ";
	format += "%w = %f | }";
	const auto cstart = particleInfo.ColorStart;
	const auto cend = particleInfo.ColorStart;
	const auto info = StringFormat(format.c_str(),
		blendMode->getName().c_str(),
		L"每秒发射个数", particleInfo.EmissionFreq,
		L"生命期", particleInfo.Lifetime,
		L"粒子最小生命期", particleInfo.LifeMin,
		L"粒子最大生命期", particleInfo.LifeMax,
		L"发射方向", particleInfo.Direction,
		L"偏移角度", particleInfo.Spread,
		L"使用相对值", particleInfo.Relative,
		L"速度最小值", particleInfo.SpeedMin,
		L"速度最大值", particleInfo.SpeedMax,
		L"重力最小值", particleInfo.GravityMin,
		L"重力最大值", particleInfo.GravityMax,
		L"最低线加速度", particleInfo.RadialAccelMin,
		L"最高线加速度", particleInfo.RadialAccelMax,
		L"最低角加速度", particleInfo.TangentialAccelMin,
		L"最高角加速度", particleInfo.TangentialAccelMax,
		L"起始大小", particleInfo.SizeStart,
		L"最终大小", particleInfo.SizeEnd,
		L"大小抖动值", particleInfo.SizeVar,
		L"起始自旋", particleInfo.SpinStart,
		L"最终自旋", particleInfo.SpinEnd,
		L"自旋抖动值", particleInfo.SpinVar,
		L"起始颜色(rgba)", cstart[0], cstart[1], cstart[2], cstart[3],
		L"最终颜色(rgba)", cend[0], cend[1], cend[2], cend[3],
		L"颜色抖动值", particleInfo.ColorVar,
		L"alpha抖动值", particleInfo.AlphaVar
	);
	ret += info;
	return ret;
}

ResParticle::ResParticle(const std::string& name, const ParticleInfo& pinfo, Sprite* sprite,
	BlendMode* bld, double a, double b, XColliderType colliType)
: ResourceColliable(ResourceType::Particle, name, colliType, a, b),
bindSprite(sprite), particleInfo(pinfo), blendMode(bld)
{
	CC_ASSERT(sprite&&bld);
	bindSprite->retain();
}

ResParticle::~ResParticle()
{
	bindSprite->release();
}

ResParticle* ResParticle::create(const std::string& name, const std::string& path, ResSprite* sprite,
	double a, double b, XColliderType colliType)
{
	if (!sprite)
		return nullptr;
	const auto clone = Sprite::createWithSpriteFrame(sprite->getSprite()->getSpriteFrame());
	if (!clone)
		return nullptr;
	const auto data = LRES.getDataFromFile(path);
	if (!data)
		return nullptr;
	if (data->getSize() != sizeof(ParticleInfo))
		return nullptr;
	try
	{
		ParticleInfo tInfo{};
		memcpy(&tInfo, data->getBytes(), sizeof(ParticleInfo));
		tInfo.BlendInfo = (tInfo.BlendInfo >> 16) & 0x00000003;
		//TODO: move to lua
		auto blend = BlendMode::getByName("add+alpha");
		if (tInfo.BlendInfo & 1)  // ADD
		{
			if (tInfo.BlendInfo & 2)  // ALPHA
				blend = BlendMode::getByName("add+alpha");
			else
				blend = BlendMode::getByName("add+add");
		}
		else  // MUL
		{
			if (tInfo.BlendInfo & 2)  // ALPHA
				blend = BlendMode::getByName("mul+alpha");
			else
				blend = BlendMode::getByName("mul+add");
		}
		if (!blend)
			return nullptr;
		return new (nothrow) ResParticle(name, tInfo, clone,
			blend, a, b, colliType);
	}
	catch (const bad_alloc&)
	{
	}
	return nullptr;
}
