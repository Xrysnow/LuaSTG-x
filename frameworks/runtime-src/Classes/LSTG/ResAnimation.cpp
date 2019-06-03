#include "ResAnimation.h"
#include "Utility.h"
#include "Renderer.h"

using namespace std;
using namespace cocos2d;
using namespace lstg;

void ResAnimation::setColor(const Color4B& color)
{
	ResourceQuad::setColor(color);
	for (auto& v : verts)
	{
		v.tl.colors = color;
		v.tr.colors = color;
		v.bl.colors = color;
		v.br.colors = color;
	}
}

void ResAnimation::setColor(const Color4B& color, int i)
{
	ResourceQuad::setColor(color, i);
	switch (i)
	{
	case 0:
		for (auto& v : verts)v.tl.colors = color;
		break;
	case 1:
		for (auto& v : verts)v.tr.colors = color;
		break;
	case 2:
		for (auto& v : verts)v.bl.colors = color;
		break;
	case 3:
		for (auto& v : verts)v.br.colors = color;
		break;
	default:
		break;
	}
}

void ResAnimation::setAlpha(uint8_t alpha)
{
	ResourceQuad::setAlpha(alpha);
	for (auto& v : verts)
	{
		v.tl.colors.a = alpha;
		v.tr.colors.a = alpha;
		v.bl.colors.a = alpha;
		v.br.colors.a = alpha;
	}
}

void ResAnimation::setVertex(const V3F_C4B_T2F_Quad& v, size_t i)
{
	if (i < verts.size())
		verts[i] = v;
}

V3F_C4B_T2F_Quad& ResAnimation::getVertex(size_t i)
{
	if (i < verts.size())
		return verts[i];
	return verts[0];
}

Sprite* ResAnimation::getSprite(uint32_t index) noexcept
{
	if (index >= getCount())
		return nullptr;
	return images.at(index);
}

void ResAnimation::setInterval(float v)
{
	if (v == 0.f)v = FLT_MAX;
	interval = v;
}

bool ResAnimation::render(int ani_timer, float x, float y, float rot, float hscale, float vscale)
{
	return LRR.render(this, ani_timer, x, y, rot, hscale, vscale);
}

string ResAnimation::getInfo() const
{
	auto ret = ResourceQuad::getInfo();
	ret += StringUtils::format(" | w = %d, h = %d, row = %d, col = %d", (int)w, (int)h, m, n);
	ret += " | Sprite0 = { | " + images.at(0)->getDescription() + " | }";
	return ret;
}

ResAnimation::ResAnimation(const char* name, ResTexture* tex,
	float x, float y, float w, float h,
	int n, int m, int intv, double a, double b,
	XColliderType colliType, const std::string& path)
: ResourceQuad(ResourceType::Animation, name, colliType, a, b, path),
interval(intv), w(w), h(h), m(m), n(n)
{
	// slice texture
	for (int j = 0; j < m; ++j) // row
	{
		for (int i = 0; i < n; ++i) // col
		{
			const auto s = Sprite::createWithTexture(
				tex->getTexture(),
				Rect(x + w * i, y + h * j, w, h));
			if (!s)
			{
				for (auto img : images) img->release();
				throw runtime_error("ResAnimation: CreateSprite2D failed.");
			}
			images.pushBack(s);
			verts.push_back(s->getQuad());
		}
	}
	resPath = tex->getPath();
}

ResAnimation::~ResAnimation()
{
	images.clear();
}

ResAnimation* ResAnimation::create(const std::string& name, ResTexture* texture,
	float x, float y, float w, float h,
	int nCol, int nRow, int interval, double a, double b, XColliderType colliType)
{
	return new (nothrow) ResAnimation(name.c_str(), texture,
		x, y, w, h, nCol, nRow, interval, a, b, colliType);
}

