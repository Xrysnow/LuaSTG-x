#pragma once
#include "ResBase.h"
#include "RenderMode.h"
#include "../Classes/XTriangles.h"

namespace lstg {
	class ResTexture :
		public Resource
	{
		cc::IntrusivePtr<cc::Texture2D> texture;
		cc::IntrusivePtr<Triangles> triangles;
	public:
		cc::Texture2D* getTexture() const { return texture; }
		bool isTextureFlipped();

		Triangles* getTriangles() const { return triangles; }
		void setTriangles(cc::IntrusivePtr<Triangles> tri);

		bool render(const cc::V3F_C4B_T2F_Quad& quad);
		bool render(RenderMode* blend, const cc::V3F_C4B_T2F_Quad& quad);

		std::unordered_map<std::string, std::string> getInfo() const override;
		size_t getMemorySize() override;

		ResTexture(const std::string& name, cc::IntrusivePtr<cc::Texture2D> tex);

		static cc::IntrusivePtr<ResTexture> create(const std::string& name, const std::string& path);
		static cc::IntrusivePtr<ResTexture> createWithTexture(const std::string& name, cc::IntrusivePtr<cc::Texture2D> texture);
	};
}
