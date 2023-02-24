#include "ResParticle.h"
#include "AppFrame.h"
#include "Util/Utility.h"
#include "Renderer.h"
#include <cstring>

using namespace std;
using namespace cocos2d;
using namespace lstg;

std::vector<unsigned short> ResParticle::ParticlePool::quadIndices;

void ResParticle::ParticlePool::initQuadIndices(size_t size)
{
	if (quadIndices.size() >= size)
		return;
	quadIndices.resize(size);
	for (size_t i = 0; i < size; ++i)
	{
		CC_ASSERT(i * 4 < std::numeric_limits<uint16_t>::max());
		const auto off = i * 4;
		quadIndices[i * 6 + 0] = 0 + off;
		quadIndices[i * 6 + 1] = 1 + off;
		quadIndices[i * 6 + 2] = 2 + off;
		quadIndices[i * 6 + 3] = 3 + off;
		quadIndices[i * 6 + 4] = 2 + off;
		quadIndices[i * 6 + 5] = 1 + off;
	}
}

Color4B ResParticle::ParticlePool::getColorStart()
{
	Color4B ret;
	if (particleInfo.ColorStart[0] < 0)
	{
		const auto sp = host->getBindSprite();
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

void ResParticle::ParticlePool::setColorStart(const Color4B& color)
{
	particleInfo.ColorStart[0] = color.r / 255.f;
	particleInfo.ColorStart[1] = color.g / 255.f;
	particleInfo.ColorStart[2] = color.b / 255.f;
	particleInfo.ColorStart[3] = color.a / 255.f;
}

Color4B ResParticle::ParticlePool::getColorEnd()
{
	Color4B ret;
	if (particleInfo.ColorEnd[0] < 0)
	{
		const auto sp = host->getBindSprite();
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

void ResParticle::ParticlePool::setColorEnd(const Color4B& color)
{
	particleInfo.ColorEnd[0] = color.r / 255.f;
	particleInfo.ColorEnd[1] = color.g / 255.f;
	particleInfo.ColorEnd[2] = color.b / 255.f;
	particleInfo.ColorEnd[3] = color.a / 255.f;
}

void ResParticle::ParticlePool::setRenderMode(RenderMode* m)
{
	renderMode = m;
}

void ResParticle::ParticlePool::setActive(bool b)
{
	if (b)
	{
		status = Status::Alive;
		life = 0.f;
	}
	else
		status = Status::Sleep;
}

void ResParticle::ParticlePool::setCenter(const cocos2d::Vec2& pos)
{
	if (status == Status::Alive)
		prevCenter = center;
	else
		prevCenter = pos;
	center = pos;
}

void ResParticle::ParticlePool::update(float delta)
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
				std::memcpy(&tInst, &particlePool[numAlive], sizeof(ParticleInstance));
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
		const auto fParticlesNeeded = pInfo.EmissionFreq * delta + emissionResidue;
		const auto nParticlesCreated = static_cast<uint32_t>(fParticlesNeeded);
		emissionResidue = fParticlesNeeded - static_cast<float>(nParticlesCreated);

		for (i = 0; i < nParticlesCreated; ++i)
		{
			if (numAlive >= particlePool.size())
				break;

			ParticleInstance& tInst = particlePool[numAlive++];
			tInst.life = 0.0f;
			tInst.terminalLife = rng.getRandFloat(pInfo.LifeMin, pInfo.LifeMax);
			// magic numbers here
			tInst.vecLocation = prevCenter + (center - prevCenter) * rng.getRandFloat(0.0f, 1.0f);
			tInst.vecLocation.x += rng.getRandFloat(-2.0f, 2.0f);
			tInst.vecLocation.y += rng.getRandFloat(-2.0f, 2.0f);

			constexpr auto LPI_HALF = 1.5707963267f;  // PI*0.5
			const float ang = /* pInfo.Direction */ (rotation - float(LPI_HALF)) - float(LPI_HALF) +
				rng.getRandFloat(0, pInfo.Spread) - pInfo.Spread / 2.0f;
			tInst.vecVelocity.x = cos(ang);
			tInst.vecVelocity.y = sin(ang);
			tInst.vecVelocity *= rng.getRandFloat(pInfo.SpeedMin, pInfo.SpeedMax);

			tInst.gravity = rng.getRandFloat(pInfo.GravityMin, pInfo.GravityMax);
			tInst.radialAccel = rng.getRandFloat(pInfo.RadialAccelMin, pInfo.RadialAccelMax);
			tInst.tangentialAccel = rng.getRandFloat(pInfo.TangentialAccelMin, pInfo.TangentialAccelMax);

			tInst.size = rng.getRandFloat(
				pInfo.SizeStart,
				pInfo.SizeStart + (pInfo.SizeEnd - pInfo.SizeStart) * pInfo.SizeVar);
			tInst.sizeDelta = (pInfo.SizeEnd - tInst.size) / tInst.terminalLife;

			//tInst.spin = /* pInfo.fSpinStart */ rotation +
			//	_rand.GetRandFloat(0, pInfo.SpinEnd) - pInfo.SpinEnd / 2.0f;
			//tInst.spinDelta = pInfo.SpinVar;

			tInst.spin = rng.getRandFloat(0, (pInfo.SpinEnd - pInfo.SpinStart)*pInfo.SpinVar) + pInfo.SpinStart;
			tInst.spinDelta = (pInfo.SpinEnd - tInst.spin) / tInst.terminalLife;

			auto _var = pInfo.ColorVar;
			for (int j = 0; j < 4; ++j)
			{
				if (j == 3)_var = pInfo.AlphaVar;
				tInst.color[j] = rng.getRandFloat(
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

void ResParticle::ParticlePool::render(float scaleX, float scaleY)
{
	Sprite* p = host->getBindSprite();
	const auto noInsColor = particleInfo.ColorStart[0] < 0;
	const auto _color = p->getColor();
	const auto _alpha = p->getOpacity();
	const auto spQuad = p->getQuad();
	const auto quadCenter = (spQuad.tl.vertices + spQuad.br.vertices) / 2;
	const auto tl_ = spQuad.tl.vertices - quadCenter;
	const Vec2 topLeft = { tl_.x,tl_.y };
	const auto z = 0.5f;

#define MEREGE_PARTICLE_TRANGLES

	initQuadIndices(LPARTICLE_MAXCNT);
	triangles.indexCount = numAlive * 6;
	triangles.vertCount = numAlive * 4;
	triangles.indices = quadIndices.data();
	triangles.verts = reinterpret_cast<V3F_C4B_T2F*>(quads.data());

	LRR.updateRenderMode(renderMode);

	for (size_t i = 0; i < numAlive; ++i)
	{
		ParticleInstance& pInst = particlePool[i];
#ifdef MEREGE_PARTICLE_TRANGLES
		auto& quad = quads[i];
		auto vert = reinterpret_cast<V3F_C4B_T2F*>(&quads[i]);
		if (!noInsColor)
		{
			const uint8_t r = pInst.color[0] * 255;
			const uint8_t g = pInst.color[1] * 255;
			const uint8_t b = pInst.color[2] * 255;
			const uint8_t a = pInst.color[3] * 255;
			const Color4B color = { r,g,b,a };
			for (auto j = 0; j < 4; ++j)
				vert[j].colors = color;
		}
		const auto rad = -pInst.spin;
		const auto x = pInst.vecLocation.x;
		const auto y = pInst.vecLocation.y;
		const auto rot = Vec2(std::cosf(rad), std::sinf(rad));
		//NOTE: anchor point of Sprite is ignored
		const auto tl0 = Vec2(topLeft.x * scaleX * pInst.size, topLeft.y * scaleY * pInst.size);
		const auto tl = tl0.rotate(rot);
		const auto tr = Vec2(-tl0.x, tl0.y).rotate(rot);
		quad.tl.vertices.set(tl.x + x, tl.y + y, z);
		quad.bl.vertices.set(-tr.x + x, -tr.y + y, z);
		quad.tr.vertices.set(tr.x + x, tr.y + y, z);
		quad.br.vertices.set(-tl.x + x, -tl.y + y, z);
#else
		if (noInsColor)  // r < 0
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
#endif // MEREGE_PARTICLE_TRANGLES
	}
#ifdef MEREGE_PARTICLE_TRANGLES
	LRR.renderTexture(p->getTexture(), triangles);
#endif // MEREGE_PARTICLE_TRANGLES
	p->setColor(_color);
	p->setOpacity(_alpha);
}

ResParticle::ParticleInstance* ResParticle::ParticlePool::getParticleInstance(int32_t index)
{
	if (0 <= index && index < numAlive)
		return &particlePool[index];
	return nullptr;
}

ResParticle::ParticlePool::ParticlePool(ResParticle* res)
	: host(res), particleInfo()
{
	CC_ASSERT(host);
	CC_SAFE_RETAIN(host);
	particleInfo = host->getParticleInfo();
	const auto quad = host->getBindSprite()->getQuad();
	// for texCoords
	for (auto&& q : quads)
		q = quad;
}

ResParticle::ParticlePool::~ParticlePool()
{
	host->poolInstances.erase(this);
	CC_SAFE_RELEASE_NULL(host);
}

ResParticle::ParticlePool* ResParticle::newPool()
{
	auto pool = new (std::nothrow) ParticlePool(this);
	if (pool)
	{		
		pool->setRenderMode(renderMode);
		//pool->setSeed(uint32_t(time(nullptr)));
		poolInstances.insert(pool);
	}
	return pool;
}

ParticleSystemQuad* ResParticle::newCocosParticle()
{
	auto ret = ParticleSystemQuad::create();
	if (!ret)
		return nullptr;

	ret->setEmitterMode(ParticleSystem::Mode::GRAVITY);
	ret->setPositionType(ParticleSystem::PositionType::GROUPED);
	ret->setRotationIsDir(false);
	ret->setSourcePosition(Vec2::ZERO);
	ret->setAutoRemoveOnFinish(false);
	ret->setTotalParticles(LPARTICLE_MAXCNT);

	auto& info = particleInfo;
	if (info.BlendInfo & 1)
		ret->setBlendAdditive(true);
	else
		ret->setBlendAdditive(false);
	if (info.BlendInfo & 2)
		ret->setBlendFunc(BlendFunc::ALPHA_NON_PREMULTIPLIED);
	else
		ret->setBlendFunc(BlendFunc::ADDITIVE);
	ret->setEmissionRate((float)info.EmissionFreq);
	if (info.Lifetime < 0)
		ret->setDuration(ParticleSystem::DURATION_INFINITY);
	else
		ret->setDuration(info.Lifetime);
	ret->setLife((info.LifeMax + info.LifeMin) / 2);
	ret->setLifeVar((info.LifeMax - info.LifeMin) / 2);
	ret->setAngle(CC_RADIANS_TO_DEGREES(info.Direction));
	ret->setAngleVar(CC_RADIANS_TO_DEGREES(info.Spread / 2));
	ret->setSpeed((info.SpeedMax + info.SpeedMin) / 2);
	ret->setSpeedVar((info.SpeedMax - info.SpeedMin) / 2);
	// no gravity var in cocos
	ret->setGravity({ 0, (info.GravityMax + info.GravityMin) / 2 });
	ret->setRadialAccel((info.RadialAccelMax + info.RadialAccelMin) / 2);
	ret->setRadialAccelVar((info.RadialAccelMax - info.RadialAccelMin) / 2);
	ret->setTangentialAccel((info.TangentialAccelMax + info.TangentialAccelMin) / 2);
	ret->setTangentialAccelVar((info.TangentialAccelMax - info.TangentialAccelMin) / 2);

	const auto& rect = bindSprite->getTextureRect();
	const auto size = (rect.size.width + rect.size.height) / 2;
	ret->setStartSize(info.SizeStart * size);
	ret->setStartSizeVar(info.SizeVar * size);
	ret->setEndSize(info.SizeEnd * size);
	ret->setEndSizeVar(info.SizeVar * size);
	
	ret->setStartSpin(CC_RADIANS_TO_DEGREES(info.SpinStart));
	ret->setStartSpinVar(CC_RADIANS_TO_DEGREES(info.SpinVar));
	ret->setEndSpin(CC_RADIANS_TO_DEGREES(info.SpinEnd));
	ret->setEndSpinVar(CC_RADIANS_TO_DEGREES(info.SpinVar));

	const auto ins_color = particleInfo.ColorStart[0] >= 0;
	if (ins_color)
		ret->setStartColor({ info.ColorStart[0],info.ColorStart[1],info.ColorStart[2],info.ColorStart[3] });
	else
		ret->setStartColor({ 1,1,1,info.ColorStart[3] });
	if (ins_color)
		ret->setEndColor({ info.ColorEnd[0],info.ColorEnd[1],info.ColorEnd[2],info.ColorEnd[3] });
	else
		ret->setEndColor({ 1,1,1,info.ColorEnd[3] });
	const auto colorVar = Color4F(info.ColorVar, info.ColorVar, info.ColorVar, info.AlphaVar);
	ret->setStartColorVar(colorVar);
	ret->setEndColorVar(colorVar);

	ret->setTextureWithRect(bindSprite->getTexture(), bindSprite->getTextureRect());
	return ret;
}

std::unordered_map<std::string, std::string> ResParticle::getInfo() const
{
	auto ret = ResourceColliable::getInfo();
	ret["render_mode"] = renderMode->getName();

	ret["EmissionFreq"] = to_string(particleInfo.EmissionFreq);
	ret["Lifetime"] = to_string(particleInfo.Lifetime);
	ret["LifeMin"] = to_string(particleInfo.LifeMin);
	ret["LifeMax"] = to_string(particleInfo.LifeMax);
	ret["Direction"] = to_string(particleInfo.Direction);
	ret["Spread"] = to_string(particleInfo.Spread);
	ret["Relative"] = particleInfo.Relative ? "true" : "false";
	ret["SpeedMin"] = to_string(particleInfo.SpeedMin);
	ret["SpeedMax"] = to_string(particleInfo.SpeedMax);
	ret["GravityMin"] = to_string(particleInfo.GravityMin);
	ret["GravityMax"] = to_string(particleInfo.GravityMax);
	ret["RadialAccelMin"] = to_string(particleInfo.RadialAccelMin);
	ret["RadialAccelMax"] = to_string(particleInfo.RadialAccelMax);
	ret["TangentialAccelMin"] = to_string(particleInfo.TangentialAccelMin);
	ret["TangentialAccelMax"] = to_string(particleInfo.TangentialAccelMax);
	ret["SizeStart"] = to_string(particleInfo.SizeStart);
	ret["SizeEnd"] = to_string(particleInfo.SizeEnd);
	ret["SizeVar"] = to_string(particleInfo.SizeVar);
	ret["SpinStart"] = to_string(particleInfo.SpinStart);
	ret["SpinEnd"] = to_string(particleInfo.SpinEnd);
	ret["SpinVar"] = to_string(particleInfo.SpinVar);
	ret["ColorVar"] = to_string(particleInfo.ColorVar);
	ret["AlphaVar"] = to_string(particleInfo.AlphaVar);

	const auto cstart = particleInfo.ColorStart;
	ret["ColorStart"] = StringFormat("%f, %f, %f, %f", cstart[0], cstart[1], cstart[2], cstart[3]);
	const auto cend = particleInfo.ColorEnd;
	ret["ColorEnd"] = StringFormat("%f, %f, %f, %f", cend[0], cend[1], cend[2], cend[3]);

	return ret;
}

size_t ResParticle::getMemorySize()
{
	size_t total = sizeof(ResParticle) + resName.size() + resPath.size();
	if (bindSprite->getReferenceCount() == 1)
		total += sizeof(Sprite);
	total += sizeof(ParticlePool) * poolInstances.size();
	return total;
}

ResParticle::ResParticle(const std::string& name, const ParticleInfo& pinfo, Sprite* sprite,
	RenderMode* rm, double a, double b, XColliderType colliType)
: ResourceColliable(ResourceType::Particle, name, colliType, a, b),
  particleInfo(pinfo), bindSprite(sprite), renderMode(rm)
{
	CC_ASSERT(bindSprite && renderMode);
}

ResParticle::~ResParticle()
{
}

ResParticle* ResParticle::create(const std::string& name, const std::string& path, ResSprite* sprite,
	double a, double b, XColliderType colliType)
{
	if (!sprite)
		return nullptr;
	const auto clone = Sprite::createWithSpriteFrame(sprite->getSprite()->getSpriteFrame());
	if (!clone)
		return nullptr;
	const auto data = LRES.getBufferFromFile(path);
	if (!data)
		return nullptr;
	if (data->size() != sizeof(ParticleInfo))
		return nullptr;
	try
	{
		ParticleInfo tInfo{};
		std::memcpy(&tInfo, data->data(), sizeof(ParticleInfo));
		tInfo.BlendInfo = (tInfo.BlendInfo >> 16) & 0x00000003;
		//TODO: move to lua
		auto blend = RenderMode::getByName("add+alpha");
		if (tInfo.BlendInfo & 1)  // ADD
		{
			if (tInfo.BlendInfo & 2)  // ALPHA
				blend = RenderMode::getByName("add+alpha");
			else
				blend = RenderMode::getByName("add+add");
		}
		else  // MUL
		{
			if (tInfo.BlendInfo & 2)  // ALPHA
				blend = RenderMode::getByName("mul+alpha");
			else
				blend = RenderMode::getByName("mul+add");
		}
		if (!blend)
			return nullptr;
		auto ret = new (nothrow) ResParticle(name, tInfo, clone,
			blend, a, b, colliType);
		if (ret)
			ret->resPath = path;
		return ret;
	}
	catch (const bad_alloc&)
	{
	}
	return nullptr;
}
