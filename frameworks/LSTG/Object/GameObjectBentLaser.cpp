#include "GameObjectBentLaser.h"
#include "GameObjectManager.h"
#include "AppFrame.h"
#include "Renderer.h"
#include "Util/Utility.h"
#include "Util/UtilColor.h"
#include "../Math/XIntersect.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

#define USE_FASTCHECK 1

GameObjectBentLaser::GameObjectBentLaser()
{
}

GameObjectBentLaser::~GameObjectBentLaser()
{
}

GameObjectBentLaser* GameObjectBentLaser::create()
{
	auto ret = new (std::nothrow) GameObjectBentLaser();
	if (ret)
	{
		ret->reset();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

void GameObjectBentLaser::setNodeLimit(size_t n)
{
	if (n > LGOBJ_MAXLASERNODE)
		n = LGOBJ_MAXLASERNODE;
	if (n < 2)
		n = 2;
	nodeLimit = n;
}

void GameObjectBentLaser::setColorMode(ColorMode mode, ColorMixMode mixMode)
{
	if ((int)mode >= 0 && (int)mode < (int)ColorMode::ColorModeNum)
		colorMode = mode;
	if ((int)mixMode >= 0 && (int)mixMode < (int)ColorMixMode::ColorMixModeNum)
		colorMixMode = mixMode;
}

void GameObjectBentLaser::pushHead(float x, float y, float width, const Color4B& color)
{
	while (queue.size() >= nodeLimit || queue.full())
		popTail();
	auto node = queue.new_back();
	CC_ASSERT(node);
	node->pos.set(x, y);
	node->half_width = width / 2;
	node->color = color;
	node->dirty = true;
#if USE_FASTCHECK
	xSet.insert(x);
	ySet.insert(y);
	hwSet.insert(width);
#endif
	updateNode(queue.size() - 1);
	if (queue.size() > 1)
	{
		auto& last = queue.back();
		auto& beforeLast = queue[queue.size() - 2];
		laserLength += (beforeLast.pos - last.pos).length();
	}
	while (laserLength > lengthLimit)
		popTail();
}

void GameObjectBentLaser::pushTail(float x, float y, float width, const Color4B& color)
{
	while (queue.size() >= nodeLimit || queue.full())
		popHead();
	auto node = queue.new_front();
	CC_ASSERT(node);
	node->pos.set(x, y);
	node->half_width = width / 2;
	node->color = color;
	node->dirty = true;
#if USE_FASTCHECK
	xSet.insert(x);
	ySet.insert(y);
	hwSet.insert(width);
#endif
	updateNode(0);
	if (queue.size() > 1)
	{
		laserLength += queue.front().dLength;
	}
	while (laserLength > lengthLimit)
		popHead();
}

void GameObjectBentLaser::popHead()
{
	if (queue.empty())return;
	auto& back = queue.back();
#if USE_FASTCHECK
	xSet.erase(back.pos.x);
	ySet.erase(back.pos.y);
	hwSet.erase(back.half_width);
#endif
	if (queue.size() > 1)
		laserLength -= back.dLength;
	else
		laserLength = 0.f;
	queue.pop_back();
}

void GameObjectBentLaser::popHead(size_t n)
{
	for (auto i = 0U; i < n; ++i)
		popHead();
}

void GameObjectBentLaser::popTail()
{
	if (queue.empty())return;
	auto& front = queue.front();
#if USE_FASTCHECK
	xSet.erase(front.pos.x);
	ySet.erase(front.pos.y);
	hwSet.erase(front.half_width);
#endif
	if (queue.size() > 1)
		laserLength -= front.dLength;
	else
		laserLength = 0.f;
	queue.pop_front();
}

void GameObjectBentLaser::popTail(size_t n)
{
	for (auto i = 0U; i < n; ++i)
		popTail();
}

bool GameObjectBentLaser::collisionCheck(GameObject* p)
{
	if (!p)return false;
	if (!fastCollisionCheck(p))
		return false;
	for (size_t i = 0; i < queue.size(); ++i)
	{
		auto& node = queue[i];
		const auto colli = p->cm->getDataColli();
		if (xmath::collision::check(
			node.pos, node.half_width, node.half_width, 0.f, XColliderType::Circle,
			p->getPosition(), colli->a, colli->b, p->getRotation(), colli->type))
			return true;
	}
	return false;
}

bool GameObjectBentLaser::collisionCheck(float x, float y)
{
	if (!fastCollisionCheck(x, y))
		return false;
	for (size_t i = 0; i < queue.size(); ++i)
	{
		auto& node = queue[i];
		const auto dx = node.pos.x - x;
		const auto dy = node.pos.y - y;
		if (dx * dx + dy * dy < node.half_width*node.half_width)
			return true;
	}
	return false;
}

bool GameObjectBentLaser::collisionCheckExtendWidth(GameObject* p, float extend)
{
	if (!p)return false;
	if (!fastCollisionCheck(p))
		return false;
	for (size_t i = 0; i < queue.size(); ++i)
	{
		auto& node = queue[i];
		const auto colli = p->cm->getDataColli();
		if (xmath::collision::check(
			node.pos, node.half_width + extend, node.half_width + extend, 0.f, XColliderType::Circle,
			p->getPosition(), colli->a, colli->b, p->getRotation(), colli->type))
			return true;
	}
	return false;
}

bool GameObjectBentLaser::collisionCheckExtendWidth(float x, float y, float extend)
{
	if (!fastCollisionCheck(x, y))
		return false;
	for (size_t i = 0; i < queue.size(); ++i)
	{
		auto& node = queue[i];
		const auto dx = node.pos.x - x;
		const auto dy = node.pos.y - y;
		const auto r = node.half_width + extend;
		if (dx * dx + dy * dy < r * r)
			return true;
	}
	return false;
}

bool GameObjectBentLaser::strictCollisionCheck(GameObject* p)
{
	if (!p)return false;
	if (!fastCollisionCheck(p))
		return false;
	for (size_t i = 0; i < queue.size() - 1; ++i)
	{
		auto& node = queue[i];
		const auto rot0 = node.dNormalized.getAngle();
		const auto a0 = node.dLength / 2;
		const auto b0 = node.half_width;
		const auto colli = p->cm->getDataColli();
		if (xmath::collision::check(
			node.pos + node.d / 2, a0, b0, rot0, XColliderType::OBB,
			p->getPosition(), colli->a, colli->b, p->getRotation(), colli->type))
			return true;
	}
	return false;
}

bool GameObjectBentLaser::strictCollisionCheck(float x, float y)
{
	if (!fastCollisionCheck(x, y))
		return false;
	for (size_t i = 0; i < queue.size() - 1; ++i)
	{
		auto& node = queue[i];
		const auto rot0 = node.dNormalized.getAngle();
		const auto a0 = node.dLength / 2;
		const auto b0 = node.half_width;
		if (xmath::intersect::Point_OBB(Vec2(x, y), node.pos, a0, b0, rot0))
			return true;
	}
	return false;
}

void GameObjectBentLaser::render(ResSprite* sprite)
{
	const auto quad = sprite->getSprite()->getQuad();
	const auto tex = sprite->getSprite()->getTexture();
	const auto tw = tex->getPixelsWide();
	const auto th = tex->getPixelsHigh();
	renderWithTexture2D(tex, sprite->getRenderMode(), sprite->getColor(0),
		quad.tl.texCoords.u*tw,
		quad.tl.texCoords.v*th,
		(quad.br.texCoords.u - quad.tl.texCoords.u)*tw,
		(quad.br.texCoords.v - quad.tl.texCoords.v)*th);//todo: refactor this
}

void GameObjectBentLaser::render(ResTexture* texture, RenderMode* blend, const Color4B& color,
	float tex_left, float tex_top, float tex_width, float tex_height)
{
	renderWithTexture2D(texture->getTexture(), blend, color,
		tex_left, tex_top, tex_width, tex_height);
}

bool GameObjectBentLaser::boundCheck()
{
	auto& lp = LPOOL;
	for (size_t i = 0; i < queue.size(); ++i)
	{
		auto& n = queue[i];
		if (lp.IsInBound(n.pos.x, n.pos.y))
			return true;
	}
	// all nodes are out of bound
	return false;
}

Vec2 GameObjectBentLaser::getNodePosition(int32_t i)
{
	const auto p = getNodeByIndex(i);
	return p ? p->pos : Vec2::ZERO;
}

float GameObjectBentLaser::getNodeWidth(int32_t i)
{
	const auto p = getNodeByIndex(i);
	return p ? p->half_width * 2 : 0.f;
}

Color4B GameObjectBentLaser::getNodeColor(int32_t i)
{
	const auto p = getNodeByIndex(i);
	return p ? p->color : Color4B::WHITE;
}

float GameObjectBentLaser::getNodeLength(int32_t i)
{
	const auto p = getNodeByIndex(i);
	return p ? p->dLength : 0.f;
}

void GameObjectBentLaser::setNodePosition(int32_t i, float x, float y)
{
	const auto node = getNodeByIndex(i);
	if (!node)
		return;
#if USE_FASTCHECK
	xSet.erase(node->pos.x);
	xSet.insert(x);
	ySet.erase(node->pos.y);
	ySet.insert(y);
#endif
	node->pos.x = x;
	node->pos.y = y;
	node->dirty = true;
	updateNode(i > 0 ? i - 1 : i + queue.size());
}

void GameObjectBentLaser::setNodeWidth(int32_t i, float width)
{
	const auto p = getNodeByIndex(i);
	if (p)
		p->half_width = std::abs(width) / 2;
}

void GameObjectBentLaser::setNodeColor(int32_t i, const Color4B& color)
{
	const auto p = getNodeByIndex(i);
	if (p)
		p->color = color;
}

void GameObjectBentLaser::setAllWidth(float width)
{
	const auto hw = std::abs(width) / 2;
	for (auto i = 0u; i < queue.size(); ++i)
		queue[i].half_width = hw;
}

void GameObjectBentLaser::setAllColor(const Color4B& color)
{
	for (auto i = 0u; i < queue.size(); ++i)
		queue[i].color = color;
}

void GameObjectBentLaser::clear()
{
	queue.clear();
	xSet.clear();
	ySet.clear();
	hwSet.clear();
	laserLength = 0.f;
}

void GameObjectBentLaser::reset()
{
	clear();
	nodeLimit = LGOBJ_MAXLASERNODE;
	lengthLimit = FLT_MAX;
	defaultWidth = 1.f;
	defaultColor = Color4B::WHITE;
}

GameObjectBentLaser::LaserNode* GameObjectBentLaser::getNodeByIndex(int32_t i)
{
	if (i > 0 && i <= int32_t(queue.size()))
		return &queue[i - 1];
	if (i < 0 && i >= -int32_t(queue.size()))
		return &queue[i + queue.size()];
	return nullptr;
}

void GameObjectBentLaser::renderWithTexture2D(Texture2D* tex, RenderMode* blend, const Color4B& color,
	float tex_left, float tex_top, float tex_width, float tex_height)
{
	if (queue.size() <= 1)
		return;
	LRR.updateRenderMode(blend);
	const auto tw = tex->getPixelsWide();
	const auto th = tex->getPixelsHigh();
	auto quadsArr = LMP.getLaserQuads();
	auto quads = quadsArr->data();

	tex_left = tex_left / tw;
	tex_width = tex_width / tw;
	tex_top = tex_top / th;
	tex_height = tex_height / th;

	static const Vec3 _p0(0.f, 0.f, 0.5f);
	V3F_C4B_T2F renderVertex[4] = {
		{ _p0, color, { 0, tex_top } },
		{ _p0, color, { 0, tex_top } },
		{ _p0, color, { 0, tex_top + tex_height } },
		{ _p0, color, { 0, tex_top + tex_height } },
	};
	auto vt0 = &renderVertex[0];
	auto vt1 = &renderVertex[1];
	auto vt2 = &renderVertex[3];
	auto vt3 = &renderVertex[2];

	float tVecLength = 0;
	int quadCount = 0;
	size_t i_start = 0;
	bool skip_copy = false;
	for (size_t i = 0; i < queue.size() - 1; ++i)
	{
		LaserNode& cur = queue[i];
		LaserNode& next = queue[i + 1];

		// skip close nodes
		float lenOffsetA = cur.dLength;
		if (lenOffsetA < 0.0001f && i + 1 != queue.size() - 1)
		{
			if (i == i_start)
				i_start++;
			continue;
		}

		auto& offsetA_Norm = cur.dNormalized;
		auto& expandVec = cur.expandVec;

		if (i == i_start)
		{
			// use half_width for the first node
			const float expX = expandVec.x * renderScale * cur.half_width;
			const float expY = expandVec.y * renderScale * cur.half_width;
			vt0->vertices.x = cur.pos.x + expX;
			vt0->vertices.y = cur.pos.y + expY;
			vt0->texCoords.u = tex_left;
			vt3->vertices.x = cur.pos.x - expX;
			vt3->vertices.y = cur.pos.y - expY;
			vt3->texCoords.u = tex_left;
		}
		else if (!skip_copy)
		{
			vt0->vertices.x = vt1->vertices.x;
			vt0->vertices.y = vt1->vertices.y;
			vt0->texCoords.u = vt1->texCoords.u;
			vt3->vertices.x = vt2->vertices.x;
			vt3->vertices.y = vt2->vertices.y;
			vt3->texCoords.u = vt2->texCoords.u;
		}
		skip_copy = false;

		tVecLength += lenOffsetA;
		if (i == queue.size() - 2)
		{
			// last two nodes
			if (lenOffsetA > 0.0001f)
			{
				const float expX = expandVec.x * renderScale * next.half_width;
				const float expY = expandVec.y * renderScale * next.half_width;
				vt1->vertices.x = next.pos.x - expX;
				vt1->vertices.y = next.pos.y - expY;
				vt1->texCoords.u = tex_left + tex_width;
				vt2->vertices.x = next.pos.x + expX;
				vt2->vertices.y = next.pos.y + expY;
				vt2->texCoords.u = tex_left + tex_width;

				// fix if crossed
				// cross1 = (v1 - v0).dot(v2 - v3);
				// cross2 = (v2 - v0).dot(v1 - v3);
				const float cross1 =
					(vt1->vertices.x - vt0->vertices.x)*(vt2->vertices.x - vt3->vertices.x) +
					(vt1->vertices.y - vt0->vertices.y)*(vt2->vertices.y - vt3->vertices.y);
				const float cross2 =
					(vt2->vertices.x - vt0->vertices.x)*(vt1->vertices.x - vt3->vertices.x) +
					(vt2->vertices.y - vt0->vertices.y)*(vt1->vertices.y - vt3->vertices.y);

				if (cross2 > cross1)
				{
					std::swap(vt1->vertices.x, vt2->vertices.x);
					std::swap(vt1->vertices.y, vt2->vertices.y);
				}
			}
			else
			{
				vt1->vertices.x = vt0->vertices.x;
				vt1->vertices.y = vt0->vertices.y;
				vt1->texCoords.u = tex_left + tex_width;
				vt2->vertices.x = vt3->vertices.x;
				vt2->vertices.y = vt3->vertices.y;
				vt2->texCoords.u = tex_left + tex_width;
			}
		}
		else
		{
			float expX, expY;
			auto angleBisect = offsetA_Norm - next.dNormalized;
			const float angleBisectLen = angleBisect.length();

			if (angleBisectLen < 1e-3f
				&& colorMode == ColorMode::Normal
				&& std::abs(cur.half_width - next.half_width) < 1e-3f)
			{
				// nearly a line, no vert color, no width change
				skip_copy = true;
				continue;
			}
			else if (angleBisectLen > 1.99998f)
			{
				expX = expandVec.x * renderScale * next.half_width;
				expY = expandVec.y * renderScale * next.half_width;
			}
			else
			{
				angleBisect = angleBisect / angleBisectLen;
				const float expandDelta = renderScale * next.half_width;
				expX = angleBisect.x * expandDelta;
				expY = angleBisect.y * expandDelta;
			}

			// set verts
			const float u = tex_left + tVecLength / laserLength * tex_width;
			vt1->vertices.x = next.pos.x - expX;
			vt1->vertices.y = next.pos.y - expY;
			vt1->texCoords.u = u;
			vt2->vertices.x = next.pos.x + expX;
			vt2->vertices.y = next.pos.y + expY;
			vt2->texCoords.u = u;

			// fix if crossed
			// cross1 = (v1 - v0).dot(v2 - v3);
			// cross2 = (v2 - v0).dot(v1 - v3);
			const float cross1 =
				(vt1->vertices.x - vt0->vertices.x)*(vt2->vertices.x - vt3->vertices.x) +
				(vt1->vertices.y - vt0->vertices.y)*(vt2->vertices.y - vt3->vertices.y);
			const float cross2 =
				(vt2->vertices.x - vt0->vertices.x)*(vt1->vertices.x - vt3->vertices.x) +
				(vt2->vertices.y - vt0->vertices.y)*(vt1->vertices.y - vt3->vertices.y);
			if (cross2 > cross1)
			{
				std::swap(vt1->vertices.x, vt2->vertices.x);
				std::swap(vt1->vertices.y, vt2->vertices.y);
			}
		}
		auto quad = &quads[quadCount];
		*quad = *(V3F_C4B_T2F_Quad*)renderVertex;
		if (colorMode != ColorMode::Normal)
		{
			const auto q = (V3F_C4B_T2F*)quad;
			auto curColor = cur.color;
			switch (colorMixMode) {
			case ColorMixMode::None:break;
			case ColorMixMode::Multi: curColor *= color; break;
			case ColorMixMode::Add: curColor += color; break;
			case ColorMixMode::ColorMixModeNum: break;
			default: ;
			}
			if (colorMode == ColorMode::NodeSmooth)
			{
				auto nextColor = cur.color;
				switch (colorMixMode) {
				case ColorMixMode::None: break;
				case ColorMixMode::Multi: nextColor *= color; break;
				case ColorMixMode::Add: nextColor += color; break;
				case ColorMixMode::ColorMixModeNum: break;
				default: ;
				}
				q[0].colors = q[2].colors = curColor;
				q[1].colors = q[3].colors = nextColor;
			}
			else if(colorMode == ColorMode::Node)
			{
				for (auto ii = 0; ii < 4; ++ii)
					q[ii].colors = curColor;
			}
		}
		quadCount++;
	}
	TrianglesCommand::Triangles tri;
	tri.verts = (V3F_C4B_T2F*)quads;
	tri.indices = XRenderer::quadIndices512;
	tri.vertCount = quadCount * 4;
	tri.indexCount = quadCount * 6;
	LRR.renderTexture(tex, tri);
}

void GameObjectBentLaser::updateNode(size_t i)
{
	const auto size = queue.size();
	if (i >= size || size < 2)
		return;
	if (i == size - 1)
	{
		auto& curr = queue[i];
		curr.d.setZero();
		curr.dNormalized.setZero();
		curr.dLength = 0.f;
		auto& prev = queue[i - 1];
		curr.dirty = false;
		if (!prev.dirty)
		{
			prev.d.set(curr.pos, prev.pos);
			prev.dNormalized.set(prev.d.getNormalized());
			prev.expandVec.set(prev.dNormalized.y, -prev.dNormalized.x);
			prev.dLength = prev.d.getLength();
			curr.expandVec = prev.expandVec;
		}
	}
	else
	{
		auto& curr = queue[i];
		if (!curr.dirty)
			return;
		auto& next = queue[i + 1];
		curr.d.set(next.pos, curr.pos);
		const auto dLength = curr.d.length();
		if (dLength < 1e-5)
		{
			curr.dNormalized = next.dNormalized;
			curr.expandVec = next.expandVec;
			curr.dLength = 0.f;
		}
		else
		{
			curr.dNormalized.set(curr.d.x / dLength, curr.d.y / dLength);
			curr.expandVec.set(curr.dNormalized.y, -curr.dNormalized.x);
			curr.dLength = dLength;
		}
		curr.dirty = false;

		if (i == 0)
			return;

		auto& prev = queue[i - 1];
		if (!prev.dirty)
		{
			prev.d.set(curr.pos, prev.pos);
			const auto prevLength = prev.d.length();
			if (prevLength < 1e-5)
			{
				prev.dNormalized = curr.dNormalized;
				prev.expandVec = curr.expandVec;
				prev.dLength = 0.f;
			}
			else
			{
				prev.dNormalized.set(prev.d.x / prevLength, prev.d.y / prevLength);
				prev.expandVec.set(prev.dNormalized.y, -prev.dNormalized.x);
				prev.dLength = prevLength;
			}
		}
		//else
		//{
		//	updateNode(i - 1);
		//}
	}
}

void GameObjectBentLaser::updateNodes()
{
	for (int i = queue.size() - 1; i > 0; --i)
	{
		if (queue[i].dirty)
			updateNode(i);
	}
}

bool GameObjectBentLaser::fastCollisionCheck(GameObject* p)
{
#if USE_FASTCHECK
	if (!p)return false;
	const auto minX = *xSet.begin();
	const auto maxX = *xSet.rbegin();
	const auto minY = *ySet.begin();
	const auto maxY = *ySet.rbegin();
	const auto maxHW = *hwSet.rbegin();
	const Vec2 p0((minX + maxX) / 2, (minY + maxY) / 2);
	const auto a0 = (maxX - minX) / 2 + maxHW;
	const auto b0 = (maxY - minY) / 2 + maxHW;

	const auto colli = p->cm->getDataColli();
	return xmath::intersect::AABB_Circle(p0, a0, b0, p->getPosition(), colli->col_r);
#else
	return false;
#endif
}

bool GameObjectBentLaser::fastCollisionCheck(float x, float y)
{
#if USE_FASTCHECK
	return x>*xSet.begin() && x<*xSet.rbegin() && y>*ySet.begin() && y<*ySet.rbegin();
#else
	return false;
#endif
}
