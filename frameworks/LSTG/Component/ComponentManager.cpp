﻿#include "ComponentManager.h"
#include "Renderer.h"
#include "AppFrame.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "Math/XMath.h"
#include "Util/Utility.h"
#include "Util/UtilLua.h"
using namespace lstg;
using namespace cocos2d;
using xmath::collision::ColliderType;

#define PROP(_P) pool->_P[obj->id]

void ComponentManager::setBindNode(Node* node)
{
	if (_node != node)
	{
		CC_SAFE_RETAIN(node);
		CC_SAFE_RELEASE(_node);
		_node = node;
		if (_node&&tr)
		{
			PROP(anchor) = _node->getAnchorPointInPoints();
		}
	}
}

ComponentDataBlend* ComponentManager::getOrCreateBlend()
{
	if (!blend)
		setDataBlend(ComponentDataBlend::create());
	return blend;
}

ComponentDataColli* ComponentManager::getOrCreateColli()
{
	if (!colli)
		setDataColli(ComponentDataColli::create());
	return colli;
}

ComponentDataTrasform2D* ComponentManager::getOrCreateTrasform2D()
{
	if (!tr)
		setDataTrasform(ComponentDataTrasform2D::create());
	return tr;
}

ComponentDataLight* ComponentManager::getOrCreateLight()
{
	if (!light)
		setDataLight(ComponentDataLight::create());
	return light;
}

void ComponentManager::updateCommandAni(ResAnimation* res)
{
	if (!ani)
		return;
	auto i = int32_t(std::floor(ani->timer / ani->interval)) % int32_t(res->getCount());
	if (i < 0)
		i += res->getCount();
	const auto sp = res->getSprite(i);
	const auto vert = LMP.getQuad();
	*vert = res->getVertex(i);

	auto renderMode = res->getRenderMode();
	if (blend)
	{
		if (blend->renderMode)
			renderMode = blend->renderMode;
		if (blend->useColor)
		{
			for (int j = 0; j < 4; ++j)
				((V3F_C4B_T2F*)vert)[j].colors = blend->blendColor;
		}
	}
	LRR.updateRenderMode(renderMode);
	LRR.setXTCommand(&xtcmd, sp->getTexture());
	xtcmd.getTri()->verts = (V3F_C4B_T2F*)vert;
}

void ComponentManager::updateCommandSprite(ResSprite* res)
{
	const auto sp = res->getSprite();
	// need a copy because vert of res may change
	const auto vert = LMP.getQuad();
	*vert = res->getVertex();

	auto renderMode = res->getRenderMode();
	if (blend)
	{
		if(blend->renderMode)
			renderMode = blend->renderMode;
		if (blend->useColor)
		{
			for (int j = 0; j < 4; ++j)
				((V3F_C4B_T2F*)vert)[j].colors = blend->blendColor;
		}
	}
	LRR.updateRenderMode(renderMode);
	auto state = renderMode->getDefaultProgramState();

	if (light && (light->lightFlag != 0) && res->getNormalMap())
	{
		// apply light uniforms to state
		light->applyUniforms(state);
		state->setTexture(
			state->getUniformLocation("u_normalTex"),
			0, res->getNormalMap()->getBackendTexture());
	}
	// uniform should be set before this
	LRR.setXTCommand(&xtcmd, sp->getTexture());
	xtcmd.getTri()->verts = (V3F_C4B_T2F*)vert;
}

void ComponentManager::updateCommandTexture(ResTexture* res)
{
	if (!vert) return;
	auto renderMode = RenderMode::getDefault();
	if (blend)
	{
		if (blend->renderMode)
			renderMode = blend->renderMode;
	}
	LRR.updateRenderMode(renderMode);
	LRR.setXTCommand(&xtcmd, res->getTexture());
	*xtcmd.getTri() = vert->tri;
}

ComponentManager::ComponentManager():
	ani(nullptr), blend(nullptr), colli(nullptr), label(nullptr), par(nullptr),
	vert(nullptr), tr(nullptr), light(nullptr), lightSource(nullptr),
	_node(nullptr), programStateCopy(nullptr)
{
	auto tri = xtcmd.getTri();
	tri->vertCount = 4;
	tri->indexCount = 6;
	tri->indices = XRenderer::quadIndices9;
}

ComponentManager::~ComponentManager()
{
}

void ComponentManager::reset()
{
	if(ani)
	{
		ani->timer = 0;
	}
	if (blend)
	{
		blend->renderMode = RenderMode::getDefault();
		blend->blendColor = Color4B::WHITE;
		blend->useColor = false;
	}
	if (colli)
	{
		colli->reset();
	}
	if (tr)
	{
		tr->reset();
	}
	releaseComponentsForGameObject();
	*xtcmd.getMV() = Mat4::IDENTITY;
	setTransformDirty(false);
}

void ComponentManager::resetForGameObject()
{
	// note: do not release things not related to game resource
	//setDataLight(nullptr);
	//setLightSource(nullptr);
	//setProgramStateCopy(nullptr);
	setDataLabel(nullptr);
	setDataParticle(nullptr);
	setDataVertex(nullptr);
	const auto tri = xtcmd.getTri();
	tri->vertCount = 4;
	tri->verts = nullptr;
	tri->indexCount = 6;
	tri->indices = XRenderer::quadIndices9;
}

void ComponentManager::releaseComponentsForGameObject()
{
	setDataLight(nullptr);
	setLightSource(nullptr);
	setProgramStateCopy(nullptr);
	setDataLabel(nullptr);
	setDataParticle(nullptr);
	setDataVertex(nullptr);
	setBindNode(nullptr);
	setDataBlend(nullptr); // cannot reuse, should be released
	const auto tri = xtcmd.getTri();
	tri->vertCount = 4;
	tri->verts = nullptr;
	tri->indexCount = 6;
	tri->indices = XRenderer::quadIndices9;
}

void ComponentManager::pushLua(lua_State* L, Resource* res)
{
	if (res)
	{
		switch (res->getType())
		{
			case ResourceType::Texture:
				if (vert&&vert->tri.verts)
				{
					lua::V3F_C4B_T2F_ptr_to_luaval(L, vert->tri.verts);
					return;
				}
			break;
			case ResourceType::Sprite: break;
			case ResourceType::Animation: break;
			case ResourceType::Music: break;
			case ResourceType::SoundEffect: break;
			case ResourceType::Particle:
				if (par&&par->pool)
				{
					const auto p = par->pool;
					toluafix_pushusertype_ccobject(L, (int)p->_ID, &p->_luaID,
						(void*)p, "lstg.ResParticle::ParticlePool");
					return;
				}
			break;
			case ResourceType::Font:
				if (label&&label->label)
				{
					const auto p = label->label;
					toluafix_pushusertype_ccobject(L, (int)p->_ID, &p->_luaID,
						(void*)p, "cc.Label");
					return;
				}
			break;
			case ResourceType::FX: break;
			case ResourceType::RenderTarget: break;
			case ResourceType::Video: break;
			default: ;
		}
	}
	lua_pushnil(L);
}

void ComponentManager::updateAni()
{
	if (ani)
	{
		ani->timer++;
	}
}

void ComponentManager::updateColli()
{
	if (!colli) return;
	switch (colli->type)
	{
	case ColliderType::Circle:
		colli->col_r = colli->a;
		break;
	case ColliderType::OBB:
		colli->col_r = ::sqrt(colli->a * colli->a + colli->b * colli->b);
		break;
	case ColliderType::Ellipse:
		colli->col_r = std::max(colli->a, colli->b);
		break;
	case ColliderType::Diamond:
		colli->col_r = std::max(colli->a, colli->b);
		break;
	case ColliderType::Triangle:
		colli->col_r = ::sqrt(colli->a * colli->a + colli->b * colli->b);
		break;
	case ColliderType::Point:
		colli->col_r = 0.f;
		break;
	case ColliderType::ColliderTypeNum:
		break;
	default:;
	}
}

bool ComponentManager::collisionCheck(ComponentManager* other) const
{
	if (other && other->colli && other->tr && tr && colli)
	{
		const auto colli1 = this->colli;
		const auto colli2 = other->colli;
		const auto dx = PROP(x) - pool->x[other->obj->id];
		const auto dy = PROP(y) - pool->y[other->obj->id];
		const auto sum = colli1->col_r + colli2->col_r;
		// AABB fast check
		if (dx >= sum ||
			dx <= -sum ||
			dy >= sum ||
			dy <= -sum)
		{
			return false;
		}
		// circumscribed circle check
		if (dx*dx + dy * dy > sum*sum)
			return false;
		if (colli1->type == ColliderType::Circle && colli2->type == ColliderType::Circle)
			return true;
		// precise check
		return check(
			obj->getPosition(), colli1->a, colli1->b, PROP(rot), colli1->type,
			other->obj->getPosition(), colli2->a, colli2->b, pool->rot[other->obj->id], colli2->type);
	}
	return false;
}

bool ComponentManager::collisionCheck3D(ComponentManager* other) const
{
	// only support sphere
	if (other && other->colli && other->tr && tr && colli)
	{
		const auto tr1 = this->tr;
		const auto tr2 = other->tr;
		const auto colli1 = this->colli;
		const auto colli2 = other->colli;
		const auto dx = PROP(x) - pool->x[other->obj->id];
		const auto dy = PROP(y) - pool->y[other->obj->id];
		const auto dz = tr1->z - tr2->z;
		const auto sum = colli1->col_r + colli2->col_r;
		return dx * dx + dy * dy + dz * dz < sum * sum;
	}
	return false;
}

bool ComponentManager::boundCheck(float l, float r, float b, float t) const
{
	return l < PROP(x) && PROP(x) < r && b < PROP(y) && PROP(y) < t;
}

void ComponentManager::applyResAnimation(ResAnimation* res)
{
	if (ani)
	{
		ani->interval = res->getInterval();
	}
	if (blend)
	{
		blend->renderMode = res->getRenderMode();
		blend->blendColor = res->getColor();
		//blend->useColor = true;
	}
	if (colli)
	{
		const auto factor = L_CLD_FACTOR;
		colli->a = res->getHalfSizeX()*factor;
		colli->b = res->getHalfSizeY()*factor;
		colli->type = res->getColliderType();
		updateColli();
	}
	PROP(anchor) = res->getSprite(0)->getAnchorPointInPoints();
}

void ComponentManager::applyResSprite(ResSprite* res)
{
	if (blend)
	{
		blend->renderMode = res->getRenderMode();
		blend->blendColor = res->getColor();
		//blend->useColor = true;
	}
	if (colli)
	{
		const auto factor = L_CLD_FACTOR;
		colli->a = res->getHalfSizeX()*factor;
		colli->b = res->getHalfSizeY()*factor;
		colli->type = res->getColliderType();
		updateColli();
	}
	PROP(anchor) = res->getSprite()->getAnchorPointInPoints();
}

void ComponentManager::applyResParticle(ResParticle* res)
{
	if (blend)
	{
		blend->renderMode = res->getRenderMode();
		//blend->blendColor = res->getColor();
		//blend->useColor = true;
	}
	if (colli)
	{
		const auto factor = L_CLD_FACTOR;
		colli->a = res->getHalfSizeX()*factor;
		colli->b = res->getHalfSizeY()*factor;
		colli->type = res->getColliderType();
		updateColli();
	}
}

void ComponentManager::applyResFont(ResFont* res)
{
	if (blend)
	{
		blend->renderMode = res->getRenderMode();
		blend->blendColor = res->getColor();
		//blend->useColor = true;
	}
}

void ComponentManager::applyLights(const std::vector<BaseLight*>& lights)
{
	if (light && light->lightFlag != 0)
	{
		light->resetUniforms();
		if(!lights.empty())
			light->applyLights(lights);
	}
}

void ComponentManager::updateParticle()
{
	if (!par || !par->pool) return;
	auto ps = par->pool;
	if (tr)
	{
		if(ps->isActive())
		{
			ps->setActive(false);
			ps->setCenter(pool->getPosition(obj->id));
			ps->setActive(true);
		}
		else
		{
			ps->setCenter(pool->getPosition(obj->id));
		}
		ps->setRotation(pool->rot[obj->id]);
	}
	if (blend)
	{
		ps->setRenderMode(blend->renderMode);
	}
	par->pool->update(1.0 / 60);
}

void ComponentManager::updateTransform()
{
	if (!tr) return;
	if (tr->is3D)
	{
		tr->update();
	}
	setTransformDirty(true);
}

void ComponentManager::updateTransformMat()
{
	setTransformDirty(false);
	if (!tr) return;
	const auto factor = L_IMG_FACTOR;
	// note: rotation in cocos2dx is adverse to lstg
	// TODO: RAD version for getNodeTransform
	if(!tr->is3D)
	{
		pool->getTransformMat(obj->id, factor, tr->z, xtcmd.getMV());
	}
	else
	{
		getNodeTransform3D(PROP(anchor), PROP(x), PROP(y), tr->z, tr->rotAxis, PROP(rot),
			PROP(hscale) * factor, PROP(vscale) * factor, tr->zscale*factor, xtcmd.getMV());
	}
	if (lightSource)
		lightSource->setNodeToParentTransform(xtcmd.getModelView());
	if (_node)
		_node->setNodeToParentTransform(xtcmd.getModelView());
}

void ComponentManager::renderAnimation(ResAnimation* res)
{
	if (!ani) return;
	updateCommandAni(res);
	LRR.addXTCommand(&xtcmd);
}

void ComponentManager::renderLabel()
{
	if (label&&label->label)
	{
		LRR.flushTriangles();
		auto lb = label->label;
		if(blend)
		{
			lb->setBlendFunc({
				blend->renderMode->desc.sourceRGBBlendFactor,
				blend->renderMode->desc. destinationRGBBlendFactor});
			// TTF label uses shader for effects
			//lb->setProgram(blend->renderMode->getProgram());// no fog
			if (blend->useColor)
			{
				lb->setOpacity(blend->blendColor.a);
				lb->setColor(Color3B(blend->blendColor));
			}
			LRR.updateRenderMode(blend->renderMode);
		}
		else
		{
			LRR.updateRenderMode(RenderMode::getDefault());
		}
		//TODO: check
		lb->visit(LRR.getRenderer(), xtcmd.getModelView(), Node::FLAGS_TRANSFORM_DIRTY);
	}
}

void ComponentManager::renderParticle()
{
	if (par&&par->pool)// TODO: can use programStateCopy
	{
		const auto factor = L_IMG_FACTOR;
		if (tr)
			par->pool->render(PROP(hscale) * factor, PROP(vscale) * factor);
		else
			par->pool->render(1.f*factor, 1.f*factor);
	}
}

void ComponentManager::renderSprite(ResSprite* res)
{
	updateCommandSprite(res);
	LRR.addXTCommand(&xtcmd);
}

void ComponentManager::renderTexture(ResTexture* res)
{
	if (!vert) return;
	updateCommandTexture(res);
	LRR.addXTCommand(&xtcmd);
}

void ComponentManager::drawCollider(const Color4B& color)
{
	if (!tr || !colli)return;
	LRR.flushTriangles();
	const Color4F color_f(color);
	const auto colli = getDataColli();
	const auto a = colli->a;
	const auto b = colli->b;
	const auto rot = PROP(rot);
	const auto col_r = colli->col_r;
	const auto pos = pool->getPosition(obj->id);
	switch (colli->type)
	{
	case ColliderType::Circle:
		LRR.getDrawNode()->drawSolidCircle(
			pos,
			col_r,
			rot,
			col_r < 5 ? 6 : (col_r < 10 ? 12 : 16),
			color_f);
		break;
	case ColliderType::OBB:
		do
		{
			Vec2 tPos[4] = {
				{ -a, -b },
				{ a, -b },
				{ a, b },
				{ -a, b } };
			float tSin, tCos;
			xmath::SinCos(rot, tSin, tCos);
			for (auto& tPo : tPos)
			{
				const auto tx = tPo.x * tCos - tPo.y * tSin;
				const auto ty = tPo.x * tSin + tPo.y * tCos;
				tPo.x = tx + pos.x;
				tPo.y = ty + pos.y;
			}
			LRR.getDrawNode()->drawSolidPoly(tPos, 4, color_f);
		} while (false);
		break;
	case ColliderType::Ellipse:
		do
		{
			const int segments = 16;
			const auto coef = 2.0f * (float)M_PI / segments;
			auto vertices = new (std::nothrow) Vec2[segments];
			if (!vertices)break;
			for (size_t i = 0; i < segments; i++)
			{
				float s, c;
				xmath::SinCos(i * coef, s, c);
				Vec2 v(c*a, s*b);
				v.rotate(Vec2::ZERO, rot);
				vertices[i] = v + pos;
			}
			LRR.getDrawNode()->drawSolidPoly(vertices, segments, color_f);
			CC_SAFE_DELETE_ARRAY(vertices);
		} while (false);
		break;
	case ColliderType::Diamond:
		do
		{
			float s, c;
			xmath::SinCos(rot, s, c);
			const Vec2 hda(c*a, s*a);
			const Vec2 hdb(-s * b, c*b);
			LRR.getDrawNode()->drawTriangle(
				pos + hda, pos - hda, pos + hdb, color_f);
			LRR.getDrawNode()->drawTriangle(
				pos + hda, pos - hda, pos - hdb, color_f);
		} while (false);
		break;
	case ColliderType::Triangle:
		do
		{
			float s, c;
			xmath::SinCos(rot, s, c);
			const Vec2 hda(c*a, s*a);
			const Vec2 db(-s * b, c*b);
			LRR.getDrawNode()->drawTriangle(
				pos + hda, pos - hda + db, pos - hda - db, color_f);
		} while (false);
		break;
	case ColliderType::Point: break;
	case ColliderType::ColliderTypeNum: break;
	default:;
	}
}

void ComponentManager::setX(float value)
{
	PROP(x) = value;
	setTransformDirty(true);
}

void ComponentManager::setY(float value)
{
	PROP(y) = value;
	setTransformDirty(true);
}

void ComponentManager::setRot(float value)
{
	PROP(rot) = value;
	setTransformDirty(true);
}

void ComponentManager::setHScale(float value)
{
	PROP(hscale) = value;
	setTransformDirty(true);
}

void ComponentManager::setVScale(float value)
{
	PROP(vscale) = value;
	setTransformDirty(true);
}

void ComponentManager::setZ(float value)
{
	if (obj->cls->is3D)
	{
		getDataTrasform()->z = value;
		setTransformDirty(true);
	}
}

void ComponentManager::setZScale(float value)
{
	if (obj->cls->is3D)
	{
		getDataTrasform()->zscale = value;
		setTransformDirty(true);
	}
}

bool ComponentManager::setColliA(float value)
{
	if (value < 0.f)
		return false;
	getDataColli()->a = value;
	updateColli();
	return true;
}

bool ComponentManager::setColliB(float value)
{
	if (value < 0.f)
		return false;
	getDataColli()->b = value;
	updateColli();
	return true;
}

void ComponentManager::setAniTimer(int32_t value)
{
	if (getDataAni())
		getDataAni()->timer = value;
	else
		obj->ani_timer = value;
}

int32_t ComponentManager::getAniTimer() const
{
	if (getDataAni())
		return getDataAni()->timer;
	return obj->ani_timer;
}

void ComponentManager::setColorA(uint8_t value)
{
	if (obj->cls->extProperty)
	{
		const auto b = getOrCreateBlend();
		b->blendColor.a = value;
		b->useColor = true;
	}
}

void ComponentManager::setColorR(uint8_t value)
{
	if (obj->cls->extProperty)
	{
		const auto b = getOrCreateBlend();
		b->blendColor.r = value;
		b->useColor = true;
	}
}

void ComponentManager::setColorG(uint8_t value)
{
	if (obj->cls->extProperty)
	{
		const auto b = getOrCreateBlend();
		b->blendColor.g = value;
		b->useColor = true;
	}
}

void ComponentManager::setColorB(uint8_t value)
{
	if (obj->cls->extProperty)
	{
		const auto b = getOrCreateBlend();
		b->blendColor.b = value;
		b->useColor = true;
	}
}

uint8_t ComponentManager::getColorA()
{
	if (obj->cls->extProperty)
		return getOrCreateBlend()->blendColor.a;
	return 0;
}

uint8_t ComponentManager::getColorR()
{
	if (obj->cls->extProperty)
		return getOrCreateBlend()->blendColor.r;
	return 0;
}

uint8_t ComponentManager::getColorG()
{
	if (obj->cls->extProperty)
		return getOrCreateBlend()->blendColor.g;
	return 0;
}

uint8_t ComponentManager::getColorB()
{
	if (obj->cls->extProperty)
		return getOrCreateBlend()->blendColor.b;
	return 0;
}
