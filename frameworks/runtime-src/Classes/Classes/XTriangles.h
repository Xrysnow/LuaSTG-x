#pragma once
#include "cocos2d.h"

namespace lstg
{
	class Triangles : public cocos2d::Ref
	{
		cocos2d::TrianglesCommand::Triangles tri;
		static const cocos2d::Rect defaultRect;
		Triangles();
	public:
		~Triangles();
		CC_DISALLOW_COPY_AND_ASSIGN(Triangles);

		static Triangles* create(size_t nVertex, size_t nIndex);
		static Triangles* createQuad(const cocos2d::Vec2& scale,
			const cocos2d::Rect& texRect = defaultRect);
		static Triangles* createGrid(size_t nCol, size_t nRow, const cocos2d::Vec2& scale,
			const cocos2d::Rect& texRect = defaultRect);
		static Triangles* createSector(size_t nCol, size_t nRow, float rOuter, float rInner, float angle,
			const cocos2d::Rect& texRect = defaultRect);
		static Triangles* createCircle(size_t nCol, size_t nRow, float r,
			const cocos2d::Rect& texRect = defaultRect);
	private:

		bool init(size_t nVertex, size_t nIndex);
		bool initQuad(const cocos2d::Vec2& scale, const cocos2d::Rect& texRect);
		bool initGrid(size_t nCol, size_t nRow, const cocos2d::Vec2& scale, const cocos2d::Rect& texRect);
		bool initSector(size_t nCol, size_t nRow, float rOuter, float rInner, float angle, const cocos2d::Rect& texRect);

		void setGridIndices(size_t nCol, size_t nRow);
		void clear();
	public:

		size_t getVertexCount() const;
		size_t getIndexCount() const;
		cocos2d::V3F_C4B_T2F* getVertexData() const;
		unsigned short* getIndexData() const;

		void setVertex(size_t index, float x, float y, float z, float u, float v, const cocos2d::Color4B& color);
		void setVertexPosition(size_t index, float x, float y, float z);
		void setVertexCoords(size_t index, float u, float v);
		void setVertexColor(size_t index, const cocos2d::Color4B& color);
		void setAllVertexColor(const cocos2d::Color4B& color);

		void setIndex(size_t index, unsigned short value);

		Triangles* clone();
	};
}
