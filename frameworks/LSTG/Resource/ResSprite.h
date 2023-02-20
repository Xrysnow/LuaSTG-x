#pragma once
#include "ResBase.h"
#include "ResTexture.h"

namespace lstg {
	class ResSprite :
		public ResourceQuad
	{
	private:
		cocos2d::Sprite* sprite = nullptr;
		cocos2d::Texture2D* normalMap = nullptr;
	public:
		cocos2d::Sprite* getSprite() const { return sprite; }
		cocos2d::Texture2D* getTexture() const { return sprite->getTexture(); }
		cocos2d::Texture2D* getNormalMap() const { return normalMap; }
		void setNormalMap(cocos2d::Texture2D* texture);

		bool render(float x, float y, float rot = 0,
			float hscale = 1, float vscale = 1, float z = 0.5);
		bool renderRect(float x1, float y1, float x2, float y2);
		bool render4v(float x1, float y1, float z1, float x2, float y2, float z2,
			float x3, float y3, float z3, float x4, float y4, float z4);

		ResSprite* clone(const std::string& newName);
		std::unordered_map<std::string, std::string> getInfo() const override;

	public:
		ResSprite(const std::string& name, cocos2d::Sprite* sprite,
			XColliderType colliType, double a, double b, const std::string& path = "");
		~ResSprite();

		static ResSprite* create(const std::string& name, ResTexture* texture,
			double x, double y, double w, double h,
			double a, double b, XColliderType colliType);
		static ResSprite* createWithSprite(const std::string& name, cocos2d::Sprite* sprite,
			double a, double b, XColliderType colliType);
	};
}
