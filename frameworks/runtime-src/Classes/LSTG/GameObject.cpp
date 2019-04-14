#include "GameObject.h"
#include "LogSystem.h"
#include "GameObjectManager.h"

using namespace lstg;
#define USE_ComponentManager

void GameObject::_Reset()
{
	status = STATUS_FREE;
	uid = 0;

	layer = 0.;
	colli = bound = true;
	hide = false;
	timer = 0;

	ReleaseResource();
	res = nullptr;
	cm = nullptr;

	pObjectPrev = pObjectNext = nullptr;
	pRenderPrev = pRenderNext = nullptr;
	pCollisionPrev = pCollisionNext = nullptr;

	cls = nullptr;
}

void GameObject::ReleaseResource()
{
	if (res)
	{
		res->release();
		res = nullptr;
	}
	if (cm)
	{
		// just release things related to game resource
		cm->resetForGameObject();
	}
}

bool GameObject::ChangeResource(Resource* r)
{
	if (!r || r == res)
		return true;
	//const auto factor = LRES.GetGlobalImageScaleFactor();
	switch (r->getType()) {
	case ResourceType::Sprite:
	{
		ReleaseResource();
		const auto sprite = dynamic_cast<ResSprite*>(r);
		res = sprite;
		res->retain();
		cm->applyResSprite(sprite);
		return true;
	}
	case ResourceType::Animation:
	{
		ReleaseResource();
		const auto animation = dynamic_cast<ResAnimation*>(r);
		res = animation;
		res->retain();
		const auto data = ComponentDataAni::create(animation);
		cm->setDataAni(data);
		cm->applyResAnimation(animation);
		return true;
	}
	case ResourceType::Particle:
	{
		ReleaseResource();
		const auto particle = dynamic_cast<ResParticle*>(r);
		res = particle;
		const auto data = ComponentDataParticle::create(particle);
		if (!data || !data->pool)
		{
			res = nullptr;
			LERROR("failed to create particle pool");
			return false;
		}
		cm->setDataParticle(data);
		cm->applyResParticle(particle);
		auto ps = data->pool;
		const auto tr = cm->getDataTrasform();
		ps->setActive(false);
		ps->setCenter(cm->pool->getPosition(id));
		ps->setRotation(cm->pool->rot[id]);
		ps->setActive(true);
		res->retain();
		return true;
	}
	case ResourceType::Font:
	{
		ReleaseResource();
		const auto font = dynamic_cast<ResFont*>(r);
		res = font;
		res->retain();
		const auto data = ComponentDataLabel::create(font);
		cm->setDataLabel(data);
		cm->applyResFont(font);
		return true;
	}
	case ResourceType::Texture:
	{
		ReleaseResource();
		const auto tex = dynamic_cast<ResTexture*>(r);
		res = tex;
		res->retain();
		const auto data = ComponentDataVertex::create(tex);
		cm->setDataVertex(data);
		return true;
	}
	default:;
	}

	return false;
}

void GameObject::UpdateXY()
{
}

void GameObject::OnDoFrame()
{
	// update particle
	GameObjectManager::UpdateParticle(this);
}

void GameObject::CopyAttrFrom(GameObject* other)
{
	//TODO: ComponentManager
	colli = other->colli;
	layer = other->layer;
	timer = other->timer;
	bound = other->bound;
	hide = other->hide;
	status = other->status;
	cls = other->cls;
}

void GameObject::removeFromList()
{
	// remove from obj list
	pObjectPrev->pObjectNext = pObjectNext;
	pObjectNext->pObjectPrev = pObjectPrev;
	// remove from render list
	pRenderPrev->pRenderNext = pRenderNext;
	pRenderNext->pRenderPrev = pRenderPrev;
	// remove from collision list
	pCollisionPrev->pCollisionNext = pCollisionNext;
	pCollisionNext->pCollisionPrev = pCollisionPrev;
}

cocos2d::Vec2 GameObject::getPosition() const
{
	return cm->pool->getPosition(id);
}

float GameObject::getRotation() const
{
	return cm->pool->rot[id];
}
