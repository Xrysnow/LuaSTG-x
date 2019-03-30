#pragma once
#include "ResTexture.h"

namespace lstg {
	/// @brief 动画资源
	class ResAnimation :
		public ResourceQuad
	{
	public:
		void setVertex(const cocos2d::V3F_C4B_T2F_Quad& v) override {}
		cocos2d::V3F_C4B_T2F_Quad& getVertex() override { return verts[0]; }

		void setColor(const cocos2d::Color4B& color) override;
		void setColor(const cocos2d::Color4B& color, int i) override;
		void setAlpha(uint8_t alpha) override;

		void setVertex(const cocos2d::V3F_C4B_T2F_Quad& v, size_t i);
		cocos2d::V3F_C4B_T2F_Quad& getVertex(size_t i);
		size_t getCount()const noexcept { return images.size(); }
		cocos2d::Sprite* getSprite(uint32_t index) noexcept;

		void setInterval(float v);
		float getInterval()const noexcept { return interval; }

		bool render(int ani_timer, float x, float y, float rot = 0,
			float hscale = 1, float vscale = 1);

		std::string getInfo() const override;

	private:
		cocos2d::Vector<cocos2d::Sprite*> images;
		std::vector<cocos2d::V3F_C4B_T2F_Quad> verts;
		float interval = 1.f;
		float w, h; int m, n;

	public:
		ResAnimation(const char* name, ResTexture* tex,
			float x, float y, float w, float h,
			int n, int m, int intv, double a, double b,
			XColliderType colliType = XColliderType::Circle,
			const std::string& path = "");
		~ResAnimation();

		static ResAnimation* create(const std::string& name, ResTexture* texture,
			float x, float y, float w, float h,
			int nCol, int nRow, int interval, double a, double b,
			XColliderType colliType);
	};
}
