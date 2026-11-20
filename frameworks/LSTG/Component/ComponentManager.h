#pragma once
#include "ComponentData.h"
#include "cocos2d.h"
#include "Resource/ResSprite.h"
#include "../Classes/XTrianglesCommand.h"
#include "Object/GameObjectPool.h"
#include <utility>

namespace lstg
{
	class GameObjectPool;
	struct GameObject;

	class ComponentManager
	{
	protected:
		XTrianglesCommand xtcmd;
		cc::IntrusivePtr<cc::Node> _node;
	public:
		GameObjectPool* pool = nullptr;
		GameObject* obj = nullptr;

#define PROPERTY_INTRUSIVE_PTR(varType, varName, funName) \
private: cc::IntrusivePtr<varType> varName; \
public: varType* get##funName() const { return varName.get(); } \
void set##funName(cc::IntrusivePtr<varType> value) { varName = std::move(value); }
		PROPERTY_INTRUSIVE_PTR(ComponentDataAni, ani, DataAni);
		PROPERTY_INTRUSIVE_PTR(ComponentDataBlend, blend, DataBlend);
		PROPERTY_INTRUSIVE_PTR(ComponentDataColli, colli, DataColli);
		PROPERTY_INTRUSIVE_PTR(ComponentDataLabel, label, DataLabel);
		PROPERTY_INTRUSIVE_PTR(ComponentDataParticle, par, DataParticle);
		PROPERTY_INTRUSIVE_PTR(ComponentDataVertex, vert, DataVertex);
		PROPERTY_INTRUSIVE_PTR(ComponentDataTrasform2D, tr, DataTrasform);
		PROPERTY_INTRUSIVE_PTR(ComponentDataLight, light, DataLight);

		PROPERTY_INTRUSIVE_PTR(cc::BaseLight, lightSource, LightSource);
		PROPERTY_INTRUSIVE_PTR(cc::backend::ProgramState, programStateCopy, ProgramStateCopy);
#undef PROPERTY_INTRUSIVE_PTR

	public:
		cc::Node* getBindNode() const { return _node.get(); }
		void setBindNode(cc::Node* node);

		//ComponentDataAni* getOrCreateAni(ResAnimation* res);
		ComponentDataBlend* getOrCreateBlend();
		ComponentDataColli* getOrCreateColli();
		//ComponentDataLabel* getOrCreateLabel(ResFont* res);
		//ComponentDataParticle* getOrCreateParticle(ResParticle* res);
		//ComponentDataQuadVert* getOrCreateVertex(ResTexture* res);
		ComponentDataTrasform2D* getOrCreateTrasform2D();
		ComponentDataLight* getOrCreateLight();
	protected:
		bool transformDirty = true;
		bool cmdDirty = true;
		cc::Texture2D* cmdTex = nullptr;
		RenderMode* cmdBlend = nullptr;
		cc::backend::ProgramState* cmdState = nullptr;

		void updateCommandAni(ResAnimation* res);
		void updateCommandSprite(ResSprite* res);
		void updateCommandTexture(ResTexture* res);
	public:
		ComponentManager();
		virtual ~ComponentManager();

		// used when allocate new game object
		void reset();
		// used when release resource on game object
		void resetForGameObject();
		// used when free game object
		void releaseComponentsForGameObject();
		void pushLua(lua_State* L, Resource* res);
		bool isTransformDirty() const { return transformDirty; }
		void setTransformDirty(bool b) { transformDirty = b; }

		XTrianglesCommand* getTrianglesCommand() { return &xtcmd; }

		//

		// [par] update ani timer
		void updateAni();
		// [par] update col_r
		void updateColli();

		// [par]
		void updateParticle();
		// [par]
		void updateTransform();
		// [par]
		void updateTransformMat();

		// [par]
		bool collisionCheck(ComponentManager* other) const;
		bool collisionCheck3D(ComponentManager* other) const;
		// [par] return true if in bound
		bool boundCheck(float l, float r, float b, float t) const;

		//

		void applyResAnimation(ResAnimation* res);
		void applyResSprite(ResSprite* res);
		void applyResParticle(ResParticle* res);
		void applyResFont(ResFont* res);
		void applyLights(const std::vector<cc::BaseLight*>& lights);

		//

		void renderAnimation(ResAnimation* res);
		void renderLabel();
		void renderParticle();
		void renderSprite(ResSprite* res);
		void renderTexture(ResTexture* res);

		void drawCollider(const cc::Color4B& color);

		void setX(float value);
		void setY(float value);
		void setRot(float value);
		void setHScale(float value);
		void setVScale(float value);
		void setZ(float value);
		void setZScale(float value);
		bool setColliA(float value);
		bool setColliB(float value);
		void setAniTimer(int32_t value);
		int32_t getAniTimer() const;
		void setColorA(uint8_t value);
		void setColorR(uint8_t value);
		void setColorG(uint8_t value);
		void setColorB(uint8_t value);
		uint8_t getColorA();
		uint8_t getColorR();
		uint8_t getColorG();
		uint8_t getColorB();
	};
}
