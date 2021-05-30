#include "ComponentDataVertex.h"
#include <cstring>

lstg::ComponentDataVertex::ComponentDataVertex()
{
	tri.vertCount = 0;
	tri.verts = nullptr;
	tri.indexCount = 0;
	tri.indices = nullptr;
}

lstg::ComponentDataVertex::~ComponentDataVertex()
{
	CC_SAFE_DELETE_ARRAY(tri.verts);
	CC_SAFE_DELETE_ARRAY(tri.indices);
}

lstg::ComponentDataVertex* lstg::ComponentDataVertex::create(ResTexture* res)
{
	auto pRet = new(std::nothrow) ComponentDataVertex();
	if (pRet && pRet->init(res))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool lstg::ComponentDataVertex::init(ResTexture* res)
{
	if (!res)
		return false;
	const auto xtri = res->getTriangles();
	tri.vertCount = xtri->getVertexCount();
	tri.indexCount = xtri->getIndexCount();
	if (tri.vertCount == 0 || tri.indexCount == 0)
		return false;
	CC_SAFE_DELETE_ARRAY(tri.verts);
	CC_SAFE_DELETE_ARRAY(tri.indices);
	tri.verts = new cocos2d::V3F_C4B_T2F[tri.vertCount];
	tri.indices = new unsigned short[tri.indexCount];
	std::memcpy(tri.verts, xtri->getVertexData(), sizeof(cocos2d::V3F_C4B_T2F)*tri.vertCount);
	std::memcpy(tri.indices, xtri->getIndexData(), sizeof(unsigned short)*tri.indexCount);
	return true;
}
