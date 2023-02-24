#pragma once
#include "ResBase.h"
#include "RenderMode.h"
#include "../Classes/XTriangles.h"

namespace lstg {
	class ResTexture :
		public Resource
	{
		cocos2d::RefPtr<cocos2d::Texture2D> texture;
		cocos2d::RefPtr<Triangles> triangles;
	public:
		cocos2d::Texture2D* getTexture() const { return texture; }
		bool isTextureFlipped();

		Triangles* getTriangles() const { return triangles; }
		void setTriangles(Triangles* tri);

		bool render(const cocos2d::V3F_C4B_T2F_Quad& quad);
		bool render(RenderMode* blend, const cocos2d::V3F_C4B_T2F_Quad& quad);

		std::unordered_map<std::string, std::string> getInfo() const override;
		size_t getMemorySize() override;

		ResTexture(const std::string& name, cocos2d::Texture2D* tex);
		~ResTexture() override;

		static ResTexture* create(const std::string& name, const std::string& path);
		static ResTexture* createWithTexture(const std::string& name, cocos2d::Texture2D* texture);
	};
}
