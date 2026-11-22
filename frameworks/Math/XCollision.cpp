#include "XCollision.h"
#include "XIntersect.h"
#include "XMath.h"
#include <functional>
#include <unordered_map>

using namespace std;
using namespace xmath;
using namespace cc;
using namespace xmath::collision;
using namespace xmath::intersect;

#define PARAM const Vec2& p0, float a0, float b0, float rot0, const Vec2& p1, float a1, float b1, float rot1
// Duplicate an endpoint when a is zero, preserving exact degeneracy after translation.
#define ToTriangle(N) float s##N, c##N; SinCos(rot##N, s##N, c##N);\
	const Vec2 hda##N(c##N * a##N, s##N * a##N);\
	const Vec2 db##N(-s##N * b##N, c##N * b##N);\
	const auto A##N = a##N == 0.f ? p##N + db##N : p##N + hda##N;\
	const auto B##N = p##N - hda##N + db##N;\
	const auto C##N = p##N - hda##N - db##N;

#define pCircle0 p0, a0
#define pCircle1 p1, a1
#define pOBB0 p0, a0, b0, rot0
#define pOBB1 p1, a1, b1, rot1
#define pEllipse0 pOBB0
#define pEllipse1 pOBB1
#define pDiamond0 pOBB0
#define pDiamond1 pOBB1
#define pTriangle0 A0, B0, C0
#define pTriangle1 A1, B1, C1

constexpr uint8_t ColliderTypeNum = (uint8_t)ColliderType::ColliderTypeNum;
constexpr uint8_t TCircle = (uint8_t)ColliderType::Circle;
constexpr uint8_t TOBB = (uint8_t)ColliderType::OBB;
constexpr uint8_t TEllipse = (uint8_t)ColliderType::Ellipse;
constexpr uint8_t TDiamond = (uint8_t)ColliderType::Diamond;
constexpr uint8_t TTriangle = (uint8_t)ColliderType::Triangle;
constexpr uint8_t TPoint = (uint8_t)ColliderType::Point;
using ColliFunc = function<bool(PARAM)>;
ColliFunc func[ColliderTypeNum][ColliderTypeNum];

void init()
{
	for (auto& i : func)
		for (auto& j : i)
			j = [](PARAM) { return false; };

	func[TCircle][TCircle] = [](PARAM) {return Circle_Circle(pCircle0, pCircle1); };
	func[TCircle][TOBB] = [](PARAM) {return OBB_Circle(pOBB1, pCircle0); };
	func[TCircle][TEllipse] = [](PARAM) {return Circle_Ellipse(pCircle0, pEllipse1); };
	func[TCircle][TDiamond] = [](PARAM) {return Circle_Diamond(pCircle0, pDiamond1); };
	func[TCircle][TTriangle] = [](PARAM) { ToTriangle(1); return Circle_Triangle(pCircle0, pTriangle1); };
	func[TCircle][TPoint] = [](PARAM) {return Point_Circle(p1, pCircle0); };

	func[TOBB][TCircle] = [](PARAM) {return OBB_Circle(pOBB0, pCircle1); };
	func[TOBB][TOBB] = [](PARAM) {return OBB_OBB(pOBB0, pOBB1); };
	func[TOBB][TEllipse] = [](PARAM) {return OBB_Ellipse(pOBB0, pEllipse1); };
	func[TOBB][TDiamond] = [](PARAM) {return OBB_Diamond(pOBB0, pDiamond1); };
	func[TOBB][TTriangle] = [](PARAM) { ToTriangle(1); return OBB_Triangle(pOBB0, pTriangle1); };
	func[TOBB][TPoint] = [](PARAM) {return Point_OBB(p1, pOBB0); };

	func[TEllipse][TCircle] = [](PARAM) {return Circle_Ellipse(pCircle1, pEllipse0); };
	func[TEllipse][TOBB] = [](PARAM) {return OBB_Ellipse(pOBB1, pEllipse0); };
	func[TEllipse][TEllipse] = [](PARAM) {return Ellipse_Ellipse(pEllipse0, pEllipse1); };
	func[TEllipse][TDiamond] = [](PARAM) {return Ellipse_Diamond(pEllipse0, pDiamond1); };
	func[TEllipse][TTriangle] = [](PARAM) { ToTriangle(1); return Ellipse_Triangle(pEllipse0, pTriangle1); };
	func[TEllipse][TPoint] = [](PARAM) {return Point_Ellipse(p1, pEllipse0); };

	func[TDiamond][TCircle] = [](PARAM) {return Circle_Diamond(pCircle1, pDiamond0); };
	func[TDiamond][TOBB] = [](PARAM) {return OBB_Diamond(pOBB1, pDiamond0); };
	func[TDiamond][TEllipse] = [](PARAM) {return Ellipse_Diamond(pEllipse1, pDiamond0); };
	func[TDiamond][TDiamond] = [](PARAM) {return Diamond_Diamond(pDiamond0, pDiamond1); };
	func[TDiamond][TTriangle] = [](PARAM) { ToTriangle(1); return Diamond_Triangle(pDiamond0, pTriangle1); };
	func[TDiamond][TPoint] = [](PARAM) {return Point_Diamond(p1, pDiamond0); };

	func[TTriangle][TCircle] = [](PARAM) { ToTriangle(0); return Circle_Triangle(pCircle1, pTriangle0); };
	func[TTriangle][TOBB] = [](PARAM) { ToTriangle(0); return OBB_Triangle(pOBB1, pTriangle0); };
	func[TTriangle][TEllipse] = [](PARAM) { ToTriangle(0); return Ellipse_Triangle(pEllipse1, pTriangle0); };
	func[TTriangle][TDiamond] = [](PARAM) { ToTriangle(0); return Diamond_Triangle(pDiamond1, pTriangle0); };
	func[TTriangle][TTriangle] = [](PARAM) { ToTriangle(0); ToTriangle(1); return Triangle_Triangle(pTriangle0, pTriangle1); };
	func[TTriangle][TPoint] = [](PARAM) { ToTriangle(0); return Point_Triangle(p1, pTriangle0); };

	func[TPoint][TCircle] = [](PARAM) {return Point_Circle(p0, pCircle1); };
	func[TPoint][TOBB] = [](PARAM) {return Point_OBB(p0, pOBB1); };
	func[TPoint][TEllipse] = [](PARAM) {return Point_Ellipse(p0, pEllipse1); };
	func[TPoint][TDiamond] = [](PARAM) {return Point_Diamond(p0, pDiamond1); };
	func[TPoint][TTriangle] = [](PARAM) { ToTriangle(1); return Point_Triangle(p0, pTriangle1); };
	func[TPoint][TPoint] = [](PARAM) {return p0 == p1; };
}

struct _CollisionInit
{
	_CollisionInit() { init(); }
};
static _CollisionInit __CollisionInit;

bool collision::check(
	const Vec2& p0, float a0, float b0, float rot0, ColliderType t0,
	const Vec2& p1, float a1, float b1, float rot1, ColliderType t1)
{
	return func[int(t0)][int(t1)](p0, a0, b0, rot0, p1, a1, b1, rot1);
}

unordered_map<string, ColliderType> _map = {
	{"Circle", ColliderType::Circle},
	{"OBB", ColliderType::OBB},
	{"Ellipse", ColliderType::Ellipse},
	{"Diamond", ColliderType::Diamond},
	{"Triangle", ColliderType::Triangle},
	{"Point", ColliderType::Point},
	{"circle", ColliderType::Circle},
	{"obb", ColliderType::OBB},
	{"ellipse", ColliderType::Ellipse},
	{"diamond", ColliderType::Diamond},
	{"triangle", ColliderType::Triangle},
	{"point", ColliderType::Point},
};
ColliderType collision::from_string(const std::string& str)
{
	const auto it = _map.find(str);
	if (it != _map.end())
		return it->second;
	return ColliderType::ColliderTypeNum;
}

const char* collision::to_string(ColliderType t)
{
	switch (t) {
	case ColliderType::Circle: return "circle";
	case ColliderType::OBB: return "obb";
	case ColliderType::Ellipse: return "ellipse";
	case ColliderType::Diamond: return "diamond";
	case ColliderType::Triangle: return "triangle";
	case ColliderType::Point: return "point";
	case ColliderType::ColliderTypeNum: ;
	default: ;
	}
	return "unknown";
}
