#include "XTriangles.h"

#define CREATE(_init) auto ret = new (std::nothrow) XTriangles(); \
if (ret&&ret->_init){ ret->autorelease(); return ret; } \
CC_SAFE_DELETE(ret); return nullptr;

using namespace lstg;
using namespace cocos2d;

const Rect XTriangles::defaultRect = Rect(0, 0, 1, 1);

XTriangles::XTriangles()
{
	tri.verts = nullptr;
	tri.indices = nullptr;
	tri.vertCount = 0;
	tri.indexCount = 0;
}

XTriangles::~XTriangles()
{
	clear();
}

XTriangles* XTriangles::create(size_t nVertex, size_t nIndex)
{
	CREATE(init(nVertex, nIndex));
}

XTriangles* XTriangles::createQuad(const Vec2& scale, const Rect& texRect)
{
	CREATE(initQuad(scale, texRect));
}

XTriangles* XTriangles::createGrid(size_t nCol, size_t nRow, const Vec2& scale, const Rect& texRect)
{
	CREATE(initGrid(nCol, nRow, scale, texRect));
}

XTriangles* XTriangles::createSector(size_t nCol, size_t nRow, float rOuter, float rInner, float angle,
	const Rect& texRect)
{
	CREATE(initSector(nCol, nRow, rOuter, rInner, angle, texRect));
}

XTriangles* XTriangles::createCircle(size_t nCol, size_t nRow, float r, const Rect& texRect)
{
	return createSector(nCol, nRow, r, 0, M_PI * 2, texRect);
}

bool XTriangles::init(size_t nVertex, size_t nIndex)
{
	clear();
	if (nVertex == 0 || nIndex == 0)
		return false;
	tri.vertCount = nVertex;
	tri.verts = new V3F_C4B_T2F[tri.vertCount];
	tri.indexCount = nIndex;
	tri.indices = new unsigned short[tri.indexCount];
	return tri.verts && tri.indices;
}

bool XTriangles::initQuad(const Vec2& scale, const Rect& texRect)
{
	return initGrid(1, 1, scale, texRect);
}

bool XTriangles::initGrid(size_t nCol, size_t nRow, const Vec2& scale, const Rect& texRect)
{
	if (nCol == 0 || nRow == 0)
		return false;
	if (!init((nCol + 1)*(nRow + 1), nCol * nRow * 6))
		return false;
	for (auto row = 0u; row <= nRow; ++row)
	{
		const auto v = float(row) / nRow * texRect.size.height + texRect.origin.y;
		for (auto col = 0u; col <= nCol; ++col)
		{
			const auto u = float(col) / nCol * texRect.size.width + texRect.origin.x;
			auto pv = tri.verts + col + row * (nCol + 1);
			pv->colors = Color4B::WHITE;
			pv->texCoords.u = u;
			pv->texCoords.v = v;
			pv->vertices.set(scale.x*u, scale.y*(1.f - v), 0.f);
		}
	}
	setGridIndices(nCol, nRow);
	return true;
}

bool XTriangles::initSector(size_t nCol, size_t nRow, float rOuter, float rInner, float angle, const Rect& texRect)
{
	if (nCol == 0 || nRow == 0)
		return false;
	if (!init((nCol + 1)*(nRow + 1), nCol * nRow * 6))
		return false;
	for (auto row = 0u; row <= nRow; ++row)
	{
		const auto v = float(row) / nRow * texRect.size.height + texRect.origin.y;
		for (auto col = 0u; col <= nCol; ++col)
		{
			const auto u = float(col) / nCol * texRect.size.width + texRect.origin.x;
			auto pv = tri.verts + col + row * (nCol + 1);
			pv->colors = Color4B::WHITE;
			pv->texCoords.u = u;
			pv->texCoords.v = v;
			const auto theta = (1.f - v)*angle;
			const auto d = (rOuter - rInner)*u + rInner;
			pv->vertices.set(d*std::cos(theta), d*std::sin(theta), 0.f);
		}
	}
	setGridIndices(nCol, nRow);
	return true;
}

void XTriangles::setGridIndices(size_t nCol, size_t nRow)
{
	if (!tri.indices)
		return;
	size_t idx = 0;
	for (auto row = 0u; row < nRow; ++row)
	{
		for (auto col = 0u; col < nCol; ++col)
		{
			const auto i = col + row * (nCol + 1);
			const auto pi = tri.indices + idx * 6;
			pi[0] = (GLushort)(i);
			pi[1] = (GLushort)(i + nCol + 1);
			pi[2] = (GLushort)(i + 1);
			pi[3] = (GLushort)(i + nCol + 2);
			pi[4] = (GLushort)(i + 1);
			pi[5] = (GLushort)(i + nCol + 1);
			++idx;
		}
	}
}

void XTriangles::clear()
{
	CC_SAFE_DELETE_ARRAY(tri.verts);
	CC_SAFE_DELETE_ARRAY(tri.indices);
	tri.vertCount = 0;
	tri.indexCount = 0;
}

size_t XTriangles::getVertexCount() const
{
	return tri.verts ? tri.vertCount : 0;
}

size_t XTriangles::getIndexCount() const
{
	return tri.indices ? tri.indexCount : 0;
}

V3F_C4B_T2F* XTriangles::getVertexData() const
{
	return tri.verts;
}

unsigned short* XTriangles::getIndexData() const
{
	return tri.indices;
}

void XTriangles::setVertex(size_t index, float x, float y, float z, float u, float v, const Color4B& color)
{
	if (index > tri.vertCount)
		return;
	auto& vert = tri.verts[index];
	vert.vertices.set(x, y, z);
	vert.texCoords.u = u;
	vert.texCoords.v = v;
	vert.colors = color;
}

void XTriangles::setVertexPosition(size_t index, float x, float y, float z)
{
	if (index > tri.vertCount)
		return;
	tri.verts[index].vertices.set(x, y, z);
}

void XTriangles::setVertexCoords(size_t index, float u, float v)
{
	if (index > tri.vertCount)
		return;
	auto& vert = tri.verts[index];
	vert.texCoords.u = u;
	vert.texCoords.v = v;
}

void XTriangles::setVertexColor(size_t index, const Color4B& color)
{
	if (index > tri.vertCount)
		return;
	tri.verts[index].colors = color;
}

void XTriangles::setAllVertexColor(const cocos2d::Color4B& color)
{
	for (int i = 0; i < tri.vertCount; ++i)
		tri.verts[i].colors = color;
}

void XTriangles::setIndex(size_t index, unsigned short value)
{
	if (index > tri.indexCount)
		return;
	tri.indices[index] = value;
}

XTriangles* XTriangles::clone()
{
	auto ret = create(tri.vertCount, tri.indexCount);
	if (ret)
	{
		memcpy(ret->tri.indices, tri.indices, sizeof(unsigned short)*tri.indexCount);
		memcpy(ret->tri.verts, tri.verts, sizeof(V3F_C4B_T2F)*tri.indexCount);
	}
	return ret;
}
