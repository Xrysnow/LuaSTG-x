#pragma once
#include "cocos2d.h"
#include "BlendMode.h"
#include "LabelPool.h"
#include "MemPoolManager.h"

#define LRR (*lstg::XRenderer::getInstance())

namespace lstg
{
	class XRenderer
	{
	public:
		static XRenderer* getInstance();
	private:
		XRenderer();
		~XRenderer();
	public:
		static bool init();
		static bool end();
		
		static unsigned short* quadIndices9;
		static unsigned short* quadIndices512;

	private:
		// options

		bool optVsync = true;
		int optAALevel = 0;

		cocos2d::Renderer* pRenderer;
		bool bRenderStarted = false;

		// BlendMode
		BlendMode* currentBlendMode = nullptr;
		FogMode currentFogMode = None;
		FogParam currentFogParam;

		cocos2d::Mat4 storeProjection;
		cocos2d::Mat4 currentProjection;
		GLint storeViewport[4];
		cocos2d::experimental::Viewport currentVP;

		cocos2d::Camera* movingCamera = nullptr;

		cocos2d::DrawNode* drawNode = nullptr;

		bool bUseFrameBuffer = true;
		cocos2d::RenderTexture* frameBuffer = nullptr;
		cocos2d::Mat4 _FBProjection;
		cocos2d::Size _lastFBSize;
		bool bOffscreen = false;

		cocos2d::Size _lastFrameSize;

		// PostEffect/RenderTarget
		std::vector<ResRenderTarget*> renderTargetStack;
		cocos2d::RenderTexture* tempRenderTexture = nullptr;

		LabelPool labelPool;

		std::vector<XTrianglesCommand*> triToDraw;
		std::vector<cocos2d::V3F_C4B_T2F> _verts;
		std::vector<unsigned short> _indices;
		std::vector<XTrianglesCommand*> _cmds;
		struct BatchTaskInfo
		{
			XTrianglesCommand* cmd;
			size_t vOffset;
			size_t iOffset;
			size_t cmdOffset;
			size_t cmdCount;
		};
		std::vector<BatchTaskInfo> batchTaskInfo;

	public:
		void updateBlendMode(BlendMode* m);
		//TODO: should be set before GLViewImpl::create
		void setAALevel(int lv)noexcept;
		void setVsync(bool v)noexcept;
		bool isVsync() const noexcept { return optVsync; }

		void setUseFrameBuffer(bool v)noexcept { bUseFrameBuffer = v; }
		bool isUseFrameBuffer() const noexcept { return bUseFrameBuffer; }
		cocos2d::RenderTexture* getFrameBuffer() const noexcept { return frameBuffer; }
		void setOffscreen(bool b) noexcept;
		bool isOffscreen() const noexcept { return bOffscreen; }

		void pushCustomCommend(std::function<void()> f)noexcept;
		void pushCustomCommend(
			cocos2d::RenderQueue::QUEUE_GROUP group,
			float globalZOrder,
			std::function<void()> f)noexcept;
		// workaround for XTrianglesCommand::useMaterial
		void pushDummyCommand()noexcept;

		// must be called before render funcs
		bool beginScene()noexcept;

		// must be called after render funcs
		bool endScene()noexcept;

		// if not in PE, clear in VP. else, clear all
		void renderClear(const cocos2d::Color4F& c)noexcept;

		//TODO: camera manager

		// set viewport
		bool setViewport(double left, double right, double bottom, double top)noexcept;

		// set ortho projection
		void setOrtho(float left, float right, float bottom, float top)noexcept;

		// set perspective projection
		void setPerspective(float eyeX, float eyeY, float eyeZ, float atX, float atY, float atZ,
			float upX, float upY, float upZ, float fovy, float aspect, float zn, float zf)noexcept;

		// set fog param
		void setFog(float start, float end, const cocos2d::Color4F& color)noexcept;

		/******************************************************************************/

		/**
		 * \brief Render
		 * \param p sprite
		 * \param quad vertex, will use sprite's vertex if it's null
		 * \param x pos x
		 * \param y pos y
		 * \param rot rotation in degrees
		 * \param hscale horizontal scale
		 * \param vscale vertical scale
		 * \param z z value
		 * \return true
		 */
		bool render(cocos2d::Sprite* p, cocos2d::V3F_C4B_T2F_Quad* quad, float x, float y, float rot = 0,
			float hscale = 1, float vscale = 1, float z = 0.5)noexcept;

		// render ResSprite
		bool render(ResSprite* p, float x, float y, float rot = 0,
			float hscale = 1, float vscale = 1, float z = 0.5)noexcept;
		bool renderRect(ResSprite* p, float x1, float y1, float x2, float y2)noexcept;
		// TODO: 顶点顺序不同
		bool render4V(ResSprite* p, float x1, float y1, float z1, float x2, float y2, float z2,
			float x3, float y3, float z3, float x4, float y4, float z4)noexcept;

		// render ResAnimation
		bool render(ResAnimation* p, int ani_timer, float x, float y, float rot = 0,
			float hscale = 1, float vscale = 1)noexcept;

		// render ResParticle
		bool render(ResParticle::ParticlePool* p, float hscale = 1, float vscale = 1)noexcept;

		// render texture TODO: 顶点顺序不同
		bool renderTexture(cocos2d::Texture2D* t, cocos2d::V3F_C4B_T2F_Quad* quad)noexcept;
		bool renderTexture(cocos2d::Texture2D* t, const cocos2d::TrianglesCommand::Triangles& triangles)noexcept;
		bool renderTexture(ResTexture* p, cocos2d::V3F_C4B_T2F_Quad* quad)noexcept;

		// TODO: render video

		// render text
		bool renderText(ResFont* p, const char* str, float x, float y, float scale,
			cocos2d::TextHAlignment halign, cocos2d::TextVAlignment valign)noexcept;
		bool renderTextAutoAlign(ResFont* p, const char* str, cocos2d::Rect& rect, float scale,
			cocos2d::TextHAlignment halign, cocos2d::TextVAlignment valign, cocos2d::Color4B c)noexcept;
		bool renderText(ResFont* p, const char* str, float x, float y, float width, float height, float scale)noexcept;

		/******************************************************************************/

		bool checkRenderTargetInUse(cocos2d::RenderTexture* rt)noexcept;

		bool pushRenderTarget(ResRenderTarget* p)noexcept;

		bool popRenderTarget()noexcept;

		bool postEffect(ResRenderTarget* p, ResFX* shader, BlendMode* blend)noexcept;

		/******************************************************************************/

		void addCommand(cocos2d::RenderCommand* cmd);
		void addXTCommand(XTrianglesCommand* cmd);
		void flushTriangles();

	private:
		void updateBatchedVerts();

		/******************************************************************************/
	private:
		void frameBufferStart();
		void frameBufferEnd();
		void renderFrameBuffer(float scale, bool copy = false);

	public:
		cocos2d::RenderTexture* copyFrameBuffer(bool transparent = false);

		cocos2d::Renderer* getRenderer() const noexcept { return pRenderer; }
		cocos2d::DrawNode* getDrawNode() const noexcept { return drawNode; }
		const cocos2d::Mat4& getCurrentProjection() const noexcept { return currentProjection; }
		FogMode getCurrentFogMode() const noexcept { return currentFogMode; }
		cocos2d::experimental::Viewport getCurrentViewport() const noexcept { return currentVP; }
	};

}
