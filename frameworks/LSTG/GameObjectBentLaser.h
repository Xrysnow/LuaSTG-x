#pragma once
#include "Global.h"
#include "CirularQueue.hpp"
#include "RenderMode.h"
#include "GameObject.h"

namespace lstg
{
	class GameObjectBentLaser : public cocos2d::Ref
	{
	public:
		enum class ColorMode
		{
			Normal,
			Node,
			NodeSmooth,
			ColorModeNum
		};
		enum class ColorMixMode
		{
			None,
			Multi,
			Add,
			ColorMixModeNum
		};
		struct LaserNode
		{
			cocos2d::Vec2 pos;
			cocos2d::Vec2 d;
			cocos2d::Vec2 dNormalized;
			cocos2d::Vec2 expandVec;
			cocos2d::Color4B color;
			float dLength = 0.f;
			float half_width = 0.f;
			bool dirty = false;
		};
	private:
		CirularQueue<LaserNode, LGOBJ_MAXLASERNODE> queue;
		float laserLength = 0.f;
		size_t nodeLimit = LGOBJ_MAXLASERNODE;
		float lengthLimit = FLT_MAX;
		float defaultWidth = 1.f;
		cocos2d::Color4B defaultColor = cocos2d::Color4B::WHITE;
		float renderScale = 1.f;
		ColorMode colorMode = ColorMode::Normal;
		ColorMixMode colorMixMode = ColorMixMode::None;
		std::set<float> xSet;
		std::set<float> ySet;
		std::set<float> hwSet;
	public:
		static GameObjectBentLaser* create();

		size_t getNodeCount() const { return queue.size(); }
		float getLength() const { return laserLength; }
		size_t getNodeLimit() const { return nodeLimit; }
		void setNodeLimit(size_t n);
		float getLengthLimit() const { return lengthLimit; }
		void setLengthLimit(float v) { lengthLimit = v; }

		float getDefaultWidth() const { return defaultWidth; }
		void setDefaultWidth(float width) { defaultWidth = std::abs(width); }
		cocos2d::Color4B getDefaultColor()const { return defaultColor; }
		void setDefaultColor(const cocos2d::Color4B& color) { defaultColor = color; }
		float getRenderScale()const { return renderScale; }
		void setRenderScale(float scale) { renderScale = scale; }
		ColorMode getColorMode()const { return colorMode; }
		ColorMixMode getColorMixMode()const { return colorMixMode; }
		void setColorMode(ColorMode mode, ColorMixMode mixMode = ColorMixMode::None);

		void pushHead(float x, float y) { pushHead(x, y, defaultWidth); }
		void pushHead(float x, float y, float width) { pushHead(x, y, width, defaultColor); }
		void pushHead(float x, float y, float width, const cocos2d::Color4B& color);

		void pushTail(float x, float y) { pushTail(x, y, defaultWidth); }
		void pushTail(float x, float y, float width) { pushTail(x, y, width, defaultColor); }
		void pushTail(float x, float y, float width, const cocos2d::Color4B& color);

		void popHead();
		void popHead(size_t n);
		void popTail();
		void popTail(size_t n);

		// check with GameObject
		bool collisionCheck(GameObject* p);
		// check with point, fast
		bool collisionCheck(float x, float y);
		bool collisionCheckExtendWidth(GameObject* p, float extend);
		bool collisionCheckExtendWidth(float x, float y, float extend);
		bool strictCollisionCheck(GameObject* p);
		bool strictCollisionCheck(float x, float y);
		bool boundCheck();

		void render(ResSprite* sprite);
		void render(ResTexture* texture, RenderMode* blend, const cocos2d::Color4B& color,
			float tex_left, float tex_top, float tex_width, float tex_height);

		cocos2d::Vec2 getNodePosition(int32_t i);
		float getNodeWidth(int32_t i);
		cocos2d::Color4B getNodeColor(int32_t i);
		// get length of this node (to the next node)
		float getNodeLength(int32_t i);

		void setNodePosition(int32_t i, float x, float y);
		void setNodeWidth(int32_t i, float width);
		void setNodeColor(int32_t i, const cocos2d::Color4B& color);

		/** set width of all nodes */
		void setAllWidth(float width);
		/** set color of all nodes */
		void setAllColor(const cocos2d::Color4B& color);

		void clear();
		void reset();
	protected:

		LaserNode* getNodeByIndex(int32_t i);

		void renderWithTexture2D(
			cocos2d::Texture2D* tex, RenderMode* blend, const cocos2d::Color4B& color,
			float tex_left, float tex_top, float tex_width, float tex_height);

		void updateNode(size_t i);
		void updateNodes();

		bool fastCollisionCheck(GameObject* p);
		bool fastCollisionCheck(float x, float y);
		GameObjectBentLaser();
	public:
		virtual ~GameObjectBentLaser();
	};
}
