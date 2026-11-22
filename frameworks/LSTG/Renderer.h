#pragma once
#include "cocos2d.h"
#include "RenderMode.h"
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
		static bool isRenderTargetFlipped();
		
		static unsigned short* quadIndices9;
		static unsigned short* quadIndices512;

private:
	// options

	int optAALevel = 0;

		cc::Renderer* pRenderer = nullptr;
	bool bRenderStarted = false;

		// RenderMode
		RenderMode* currentRenderMode = nullptr;
		cc::backend::ProgramState* currentProgramState = nullptr;
		cc::Texture2D* currentTexture = nullptr;

		cc::Mat4 storeProjection;
		cc::Mat4 currentProjection;
		cc::Viewport storeViewport;
		cc::Viewport currentVP;

		cc::IntrusivePtr<cc::Camera> movingCamera;

		cc::IntrusivePtr<cc::DrawNode> drawNode;
		cc::IntrusivePtr<cc::Sprite> clearRect;
		cc::V3F_C4B_T2F_Quad clearRectQuad;
		cc::Mat4 clearRectProj;
		RenderMode* clearRectRenderMode = nullptr;

		bool bUseFrameBuffer = true;
		cc::IntrusivePtr<cc::RenderTexture> frameBuffer;
		cc::Mat4 _FBProjection;
		cc::Size _lastFBSize;
		bool bOffscreen = false;

		cc::Size _lastFrameSize;

		// PostEffect/RenderTarget
		std::vector<ResRenderTarget*> renderTargetStack;
		std::unordered_set<ResRenderTarget*> renderTargetUsed;
		cc::RenderTexture* tempRenderTexture = nullptr;

		LabelPool labelPool;

		std::vector<XTrianglesCommand*> triToDraw;
		std::vector<cc::V3F_C4B_T2F> _verts;
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
		void updateRenderMode(RenderMode* m);
		//TODO: should be set before GLViewImpl::create
		void setAALevel(int lv)noexcept;
		void setVsync(bool v)noexcept;
		bool isVsync() const noexcept;

		void setUseFrameBuffer(bool v)noexcept { bUseFrameBuffer = v; }
		bool isUseFrameBuffer() const noexcept { return bUseFrameBuffer; }
		cc::RenderTexture* getFrameBuffer() const noexcept { return frameBuffer.get(); }
		void setOffscreen(bool b) noexcept;
		bool isOffscreen() const noexcept { return bOffscreen; }

		void pushCallbackCommand(const std::function<void()>& f)noexcept;
		void pushCallbackCommand(
			cc::RenderQueue::QUEUE_GROUP group,
			float globalZOrder,
			const std::function<void()>& f)noexcept;

		// must be called before render funcs
		bool beginScene()noexcept;

		// must be called after render funcs
		bool endScene()noexcept;

		// if not in PE, clear in VP. else, clear all
		void renderClear(const cc::Color4F& c)noexcept;

		//TODO: camera manager

		// set viewport
		bool setViewport(int left, int right, int bottom, int top)noexcept;

		// set ortho projection
		void setOrtho(float left, float right, float bottom, float top)noexcept;

		// set perspective projection
		void setPerspective(float eyeX, float eyeY, float eyeZ, float atX, float atY, float atZ,
			float upX, float upY, float upZ, float fovy, float aspect, float zn, float zf)noexcept;

		void setProjection(const cc::Mat4& proj);

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
		bool render(cc::Sprite* p, const cc::V3F_C4B_T2F_Quad* quad, float x, float y, float rot = 0,
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
		bool renderTexture(cc::Texture2D* t, const cc::V3F_C4B_T2F_Quad* quad)noexcept;
		bool renderTexture(cc::Texture2D* t, const cc::TrianglesCommand::Triangles& triangles)noexcept;
		bool renderTexture(ResTexture* p, const cc::V3F_C4B_T2F_Quad* quad)noexcept;

		// TODO: render video

		// render text
		bool renderText(ResFont* p, const std::string& str, float x, float y, float scale,
			cc::TextHAlignment halign, cc::TextVAlignment valign)noexcept;
		bool renderTextAutoAlign(ResFont* p, const std::string& str, const cc::Rect& rect, float scale,
			cc::TextHAlignment halign, cc::TextVAlignment valign, const cc::Color4B& c)noexcept;
		bool renderText(ResFont* p, const std::string& str, float x, float y, float width, float height, float scaleX, float scaleY)noexcept;

		/******************************************************************************/

		bool checkRenderTargetInUse(cc::RenderTexture* rt)noexcept;

		bool pushRenderTarget(ResRenderTarget* p)noexcept;

		bool popRenderTarget()noexcept;

		bool postEffect(ResRenderTarget* p, ResFX* shader, RenderMode* blend)noexcept;

		/******************************************************************************/

		void setProgramStateDirty();
		void setCommand(cc::RenderCommand* cmd, cc::Texture2D* t);
		void setXTCommand(XTrianglesCommand* cmd, cc::Texture2D* t);
		void addCommand(cc::RenderCommand* cmd);
		void addXTCommand(XTrianglesCommand* cmd);
		void flushTriangles();

	private:
		void updateBatchedVerts();

		/******************************************************************************/
	private:
		void frameBufferStart();
		void frameBufferEnd();
		void renderFrameBuffer(float scale, const cc::Mat4& projection, bool copy = false);

	public:
		cc::IntrusivePtr<cc::RenderTexture> copyFrameBuffer(bool transparent = false);

		cc::Renderer* getRenderer() const noexcept { return pRenderer; }
		cc::DrawNode* getDrawNode() const noexcept { return drawNode.get(); }
		const cc::Mat4& getCurrentProjection() const noexcept { return currentProjection; }
		cc::Viewport getCurrentViewport() const noexcept { return currentVP; }

		LabelPool& getLabelPool() noexcept { return labelPool; }
	};
}
