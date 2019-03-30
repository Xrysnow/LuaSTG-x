#pragma once
#include "ResBase.h"
#include "BlendMode.h"
#include "../Classes/XTriangles.h"

namespace lstg {
	class ResTexture :
		public Resource
	{
	private:
		cocos2d::Texture2D* texture = nullptr;
		XTriangles* xtri = nullptr;
	public:
		cocos2d::Texture2D* getTexture() const { return texture; }

		XTriangles* getTriangles() const { return xtri; }
		void setTriangles(XTriangles* tri);

		bool render(const cocos2d::V3F_C4B_T2F_Quad& quad);
		bool render(BlendMode* blend, const cocos2d::V3F_C4B_T2F_Quad& quad);

		std::string getInfo() const override;

		ResTexture(const std::string& name, cocos2d::Texture2D* tex);
		~ResTexture();

		static ResTexture* create(const std::string& name, const std::string& path);
		static ResTexture* createWithTexture(const std::string& name, cocos2d::Texture2D* texture);
	};
}
