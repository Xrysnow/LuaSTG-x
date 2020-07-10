#pragma once
#include "ComponentData.h"
#include "cocos2d.h"
#include "ResSprite.h"
#include "../Classes/XTrianglesCommand.h"
#include "GameObjectPool.h"

namespace lstg
{
	class GameObjectPool;
	struct GameObject;

	class ComponentManager
	{
	protected:
		XTrianglesCommand xtcmd;
		cocos2d::Node* _node;
	public:
		GameObjectPool* pool = nullptr;
		GameObject* obj = nullptr;

#define PROPERTY_RETAIN(varType, varName, funName)    \
private: varType varName; \
public: inline varType get##funName(void) const { return varName; } \
inline void set##funName(varType var) \
{ \
    if (varName != var) \
    { \
        CC_SAFE_RETAIN(var); \
        CC_SAFE_RELEASE(varName); \
        varName = var; \
    } \
}
		PROPERTY_RETAIN(ComponentDataAni*, ani, DataAni);
		PROPERTY_RETAIN(ComponentDataBlend*, blend, DataBlend);
		PROPERTY_RETAIN(ComponentDataColli*, colli, DataColli);
		PROPERTY_RETAIN(ComponentDataLabel*, label, DataLabel);
		PROPERTY_RETAIN(ComponentDataParticle*, par, DataParticle);
		PROPERTY_RETAIN(ComponentDataVertex*, vert, DataVertex);
		PROPERTY_RETAIN(ComponentDataTrasform2D*, tr, DataTrasform);
		PROPERTY_RETAIN(ComponentDataLight*, light, DataLight);

		PROPERTY_RETAIN(cocos2d::BaseLight*, lightSource, LightSource);
		PROPERTY_RETAIN(cocos2d::backend::ProgramState*, programStateCopy, ProgramStateCopy);
#undef PROPERTY_RETAIN

	public:
		cocos2d::Node* getBindNode() const { return _node; }
		void setBindNode(cocos2d::Node* node);

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
		cocos2d::Texture2D* cmdTex = nullptr;
		RenderMode* cmdBlend = nullptr;
		cocos2d::backend::ProgramState* cmdState = nullptr;

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
		void applyLights(const std::vector<cocos2d::BaseLight*>& lights);

		//

		void renderAnimation(ResAnimation* res);
		void renderLabel();
		void renderParticle();
		void renderSprite(ResSprite* res);
		void renderTexture(ResTexture* res);

		void drawCollider(const cocos2d::Color4B& color);
	};
}
