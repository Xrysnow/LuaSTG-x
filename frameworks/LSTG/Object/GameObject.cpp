#include "GameObject.h"
#include "LogSystem.h"
#include "GameObjectManager.h"
#include "GameClass.h"
#include <utility>

using namespace lstg;

void GameObject::_Reset()
{
	status = STATUS_FREE;
	uid = 0;

	layer = 0.;
	colli = bound = true;
	hide = false;
	timer = 0;

	ReleaseResource();
	cm = nullptr;
	cls = nullptr;
}

void GameObject::ReleaseResource()
{
	res.reset();
	if (cm)
	{
		// just release things related to game resource
		cm->resetForGameObject();
	}
}

bool GameObject::ChangeResource(Resource* r)
{
	if (!r || r == res.get())
		return true;
	const auto replaceResource = [this](Resource* replacement)
	{
		cc::IntrusivePtr<Resource> next{replacement, cc::retain_ref};
		ReleaseResource();
		res = std::move(next);
	};
	switch (r->getType()) {
	case ResourceType::Sprite:
	{
		const auto sprite = dynamic_cast<ResSprite*>(r);
		replaceResource(sprite);
		cm->applyResSprite(sprite);
		return true;
	}
	case ResourceType::Animation:
	{
		const auto animation = dynamic_cast<ResAnimation*>(r);
		replaceResource(animation);
		cm->setDataAni(ComponentDataAni::create(animation));
		cm->applyResAnimation(animation);
		return true;
	}
	case ResourceType::Particle:
	{
		const auto particle = dynamic_cast<ResParticle*>(r);
		replaceResource(particle);
		auto data = ComponentDataParticle::create(particle);
		if (!data || !data->pool)
		{
			res.reset();
			LERROR("failed to create particle pool");
			return false;
		}
		auto ps = data->pool;
		cm->setDataParticle(std::move(data));
		cm->applyResParticle(particle);
		const auto tr = cm->getDataTrasform();
		ps->setActive(false);
		ps->setCenter(cm->pool->getPosition(id));
		ps->setRotation(cm->pool->rot[id]);
		ps->setActive(true);
		return true;
	}
	case ResourceType::Font:
	{
		const auto font = dynamic_cast<ResFont*>(r);
		replaceResource(font);
		cm->setDataLabel(ComponentDataLabel::create(font));
		cm->applyResFont(font);
		return true;
	}
	case ResourceType::Texture:
	{
		const auto tex = dynamic_cast<ResTexture*>(r);
		replaceResource(tex);
		cm->setDataVertex(ComponentDataVertex::create(tex));
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

cc::Vec2 GameObject::getPosition() const
{
	return cm->pool->getPosition(id);
}

float GameObject::getRotation() const
{
	return cm->pool->rot[id];
}
