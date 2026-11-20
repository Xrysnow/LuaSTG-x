#pragma once
#include "ResBase.h"
#include "ResTexture.h"

namespace lstg {
	class ResSprite :
		public ResourceQuad
	{
		cc::IntrusivePtr<cc::Sprite> sprite;
		cc::IntrusivePtr<cc::Texture2D> normalMap;
	public:
		cc::Sprite* getSprite() const { return sprite; }
		cc::Texture2D* getTexture() const { return sprite->getTexture(); }
		cc::Texture2D* getNormalMap() const { return normalMap; }
		void setNormalMap(cc::IntrusivePtr<cc::Texture2D> texture);

		bool render(float x, float y, float rot = 0,
			float hscale = 1, float vscale = 1, float z = 0.5);
		bool renderRect(float x1, float y1, float x2, float y2);
		bool render4v(float x1, float y1, float z1, float x2, float y2, float z2,
			float x3, float y3, float z3, float x4, float y4, float z4);

		cc::IntrusivePtr<ResSprite> clone(const std::string& newName);
		std::unordered_map<std::string, std::string> getInfo() const override;
		size_t getMemorySize() override;

		ResSprite(const std::string& name, cc::IntrusivePtr<cc::Sprite> sprite_,
			XColliderType colliType, double a, double b, const std::string& path = "");
		~ResSprite() override;

		static cc::IntrusivePtr<ResSprite> create(const std::string& name, ResTexture* texture,
			double x, double y, double w, double h,
			double a, double b, XColliderType colliType);
		static cc::IntrusivePtr<ResSprite> createWithSprite(const std::string& name, cc::IntrusivePtr<cc::Sprite> sprite,
			double a, double b, XColliderType colliType);
	};
}
