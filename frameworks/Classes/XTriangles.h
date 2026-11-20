#pragma once
#include "cocos2d.h"

namespace lstg
{
	class Triangles : public cc::Ref
	{
		cc::TrianglesCommand::Triangles tri;
		static const cc::Rect defaultRect;
		Triangles();
	public:
		~Triangles();
		CC_DISALLOW_COPY_AND_ASSIGN(Triangles);

		static cc::IntrusivePtr<Triangles> create(size_t nVertex, size_t nIndex);
		static cc::IntrusivePtr<Triangles> createQuad(const cc::Vec2& scale,
			const cc::Rect& texRect = defaultRect);
		static cc::IntrusivePtr<Triangles> createGrid(size_t nCol, size_t nRow, const cc::Vec2& scale,
			const cc::Rect& texRect = defaultRect);
		static cc::IntrusivePtr<Triangles> createSector(size_t nCol, size_t nRow, float rOuter, float rInner, float angle,
			const cc::Rect& texRect = defaultRect);
		static cc::IntrusivePtr<Triangles> createCircle(size_t nCol, size_t nRow, float r,
			const cc::Rect& texRect = defaultRect);
	private:

		bool init(size_t nVertex, size_t nIndex);
		bool initQuad(const cc::Vec2& scale, const cc::Rect& texRect);
		bool initGrid(size_t nCol, size_t nRow, const cc::Vec2& scale, const cc::Rect& texRect);
		bool initSector(size_t nCol, size_t nRow, float rOuter, float rInner, float angle, const cc::Rect& texRect);

		void setGridIndices(size_t nCol, size_t nRow);
		void clear();
	public:

		size_t getVertexCount() const;
		size_t getIndexCount() const;
		cc::V3F_C4B_T2F* getVertexData() const;
		unsigned short* getIndexData() const;

		void setVertex(size_t index, float x, float y, float z, float u, float v, const cc::Color4B& color);
		void setVertexPosition(size_t index, float x, float y, float z);
		void setVertexCoords(size_t index, float u, float v);
		void setVertexColor(size_t index, const cc::Color4B& color);
		void setAllVertexColor(const cc::Color4B& color);

		void setIndex(size_t index, unsigned short value);

		cc::IntrusivePtr<Triangles> clone();
	};
}
