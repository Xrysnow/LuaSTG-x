#include "GameObjectSymbol.h"
#include "Object/GameObjectPropertyHash.h"
#include "AppFrame.h"
#include "Util/UtilLua.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "xxhash/xxhash.h"
#include "GOSymbolNumber.h"
#include "GOSymbolBoolean.h"
#include "LogSystem.h"
#include <cmath>

using namespace lstg;
using namespace lstg::symbol;
using namespace cocos2d;

static std::vector<GameObject*> currentObjs;

#define CREATE_CHECK(p, _cond) if (_cond){(p)->autorelease();return (p);} CC_SAFE_DELETE(p); return nullptr;
#define PROP(O, P) O->cm->pool->P[O->id]

struct PropertyNumberGetter
{
	static float X(GameObject* obj) { return (float)PROP(obj, x); }
	static float Y(GameObject* obj) { return (float)PROP(obj, y); }
	static float DX(GameObject* obj) { return (float)PROP(obj, dx); }
	static float DY(GameObject* obj) { return (float)PROP(obj, dy); }
	static float ROT(GameObject* obj) { return (float)PROP(obj, rot); }
	static float OMEGA(GameObject* obj) { return (float)PROP(obj, omega); }
	static float TIMER(GameObject* obj) { return (float)obj->timer; }
	static float VX(GameObject* obj) { return (float)PROP(obj, vx); }
	static float VY(GameObject* obj) { return (float)PROP(obj, vy); }
	static float AX(GameObject* obj) { return (float)PROP(obj, ax); }
	static float AY(GameObject* obj) { return (float)PROP(obj, ay); }
	static float LAYER(GameObject* obj) { return (float)obj->layer; }
	static float GROUP(GameObject* obj) { return (float)obj->cm->getDataColli()->group; }
	static float HSCALE(GameObject* obj) { return (float)PROP(obj, hscale); }
	static float VSCALE(GameObject* obj) { return (float)PROP(obj, vscale); }
	static float A(GameObject* obj) {
		return (float)obj->cm->getDataColli()->a / LPOOL.getColliderScale();
	}
	static float B(GameObject* obj) {
		return (float)obj->cm->getDataColli()->b / LPOOL.getColliderScale();
	}
	static float RECT(GameObject* obj) {
		return (float)obj->cm->getDataColli()->type;
	}
	static float ANI(GameObject* obj) {
		return (float)obj->cm->getAniTimer();
	}
	static float _A(GameObject* obj) {
		if (obj->cls->extProperty)
			return (float)obj->cm->getColorA();
		return 0;
	}
	static float _R(GameObject* obj) {
		if (obj->cls->extProperty)
			return (float)obj->cm->getColorR();
		return 0;
	}
	static float _G(GameObject* obj) {
		if (obj->cls->extProperty)
			return (float)obj->cm->getColorG();
		return 0;
	}
	static float _B(GameObject* obj) {
		if (obj->cls->extProperty)
			return (float)obj->cm->getColorB();
		return 0;
	}
	static float Z(GameObject* obj) {
		if (obj->cls->is3D)
			return (float)obj->cm->getDataTrasform()->z;
		return 0;
	}
	static float DZ(GameObject* obj) {
		if (obj->cls->is3D)
			return (float)obj->cm->getDataTrasform()->dz;
		return 0;
	}
	static float VZ(GameObject* obj) {
		if (obj->cls->is3D)
			return (float)obj->cm->getDataTrasform()->vz;
		return 0;
	}
	static float AZ(GameObject* obj) {
		if (obj->cls->is3D)
			return (float)obj->cm->getDataTrasform()->az;
		return 0;
	}
	static float ZSCALE(GameObject* obj) {
		if (obj->cls->is3D)
			return (float)obj->cm->getDataTrasform()->zscale;
		return 0;
	}
};
struct PropertyBooleanGetter
{
	static bool HIDE(GameObject* obj) { return obj->hide; }
	static bool BOUND(GameObject* obj) { return obj->bound; }
	static bool NAVI(GameObject* obj) { return PROP(obj, navi); }
	static bool COLLI(GameObject* obj) { return obj->colli; }
};
struct PropertyNumberSetter
{
	static void X(GameObject* obj, float value) { obj->cm->setX(value); }
	static void Y(GameObject* obj, float value) { obj->cm->setY(value); }
	static void ROT(GameObject* obj, float value) { obj->cm->setRot(value); }
	static void OMEGA(GameObject* obj, float value) { PROP(obj, omega) = value; }
	static void TIMER(GameObject* obj, float value) { obj->timer = value; }
	static void VX(GameObject* obj, float value) { PROP(obj, vx) = value; }
	static void VY(GameObject* obj, float value) { PROP(obj, vy) = value; }
	static void AX(GameObject* obj, float value) { PROP(obj, ax) = value; }
	static void AY(GameObject* obj, float value) { PROP(obj, ay) = value; }
	static void LAYER(GameObject* obj, float value) {
		LPOOL.setObjectLayer(obj, value);
	}
	static void GROUP(GameObject* obj, float value) {
		LPOOL.setObjectGroup(obj, value);
	}
	static void HSCALE(GameObject* obj, float value) { obj->cm->setHScale(value); }
	static void VSCALE(GameObject* obj, float value) { obj->cm->setVScale(value); }
	static void A(GameObject* obj, float value) {
		obj->cm->setColliA(value * LPOOL.getColliderScale());
	}
	static void B(GameObject* obj, float value) {
		obj->cm->setColliB(value * LPOOL.getColliderScale());
	}
	static void RECT(GameObject* obj, float value) {
		obj->cm->getDataColli()->type = (decltype(obj->cm->getDataColli()->type))value;
	}
	static void ANI(GameObject* obj, float value) {
		obj->cm->setAniTimer(value);
	}
	static void _A(GameObject* obj, float value) { obj->cm->setColorA(value); }
	static void _R(GameObject* obj, float value) { obj->cm->setColorR(value); }
	static void _G(GameObject* obj, float value) { obj->cm->setColorG(value); }
	static void _B(GameObject* obj, float value) { obj->cm->setColorB(value); }
	static void Z(GameObject* obj, float value) {
		if (obj->cls->is3D) {
			obj->cm->getDataTrasform()->z = value;
			obj->cm->setTransformDirty(true);
		}
	}
	static void VZ(GameObject* obj, float value) {
		if (obj->cls->is3D) {
			obj->cm->getDataTrasform()->vz = value;
		}
	}
	static void AZ(GameObject* obj, float value) {
		if (obj->cls->is3D) {
			obj->cm->getDataTrasform()->az = value;
		}
	}
	static void ZSCALE(GameObject* obj, float value) {
		if (obj->cls->is3D) {
			obj->cm->getDataTrasform()->zscale = value;
			obj->cm->setTransformDirty(true);
		}
	}
};
struct PropertyBooleanSetter
{
	static void HIDE(GameObject* obj, bool value) { obj->hide = value; }
	static void BOUND(GameObject* obj, bool value) { obj->bound = value; }
	static void NAVI(GameObject* obj, bool value) { PROP(obj, navi) = value; }
	static void COLLI(GameObject* obj, bool value) { obj->colli = value; }
};

typedef float (*PPropertyNumberGetter) (GameObject* o);
typedef bool (*PPropertyBooleanGetter) (GameObject* o);
typedef void (*PPropertyNumberSetter) (GameObject* o, float v);
typedef void (*PPropertyBooleanSetter) (GameObject* o, bool v);

PPropertyNumberGetter symbol::GetPropertyNumberGetter(GameObjectProperty property)
{
	switch (property)
	{
	case GameObjectProperty::X: return PropertyNumberGetter::X;
	case GameObjectProperty::Y: return PropertyNumberGetter::Y;
	case GameObjectProperty::DX: return PropertyNumberGetter::DX;
	case GameObjectProperty::DY: return PropertyNumberGetter::DY;
	case GameObjectProperty::ROT: return PropertyNumberGetter::ROT;
	case GameObjectProperty::OMEGA: return PropertyNumberGetter::OMEGA;
	case GameObjectProperty::TIMER: return PropertyNumberGetter::TIMER;
	case GameObjectProperty::VX: return PropertyNumberGetter::VX;
	case GameObjectProperty::VY: return PropertyNumberGetter::VY;
	case GameObjectProperty::AX: return PropertyNumberGetter::AX;
	case GameObjectProperty::AY: return PropertyNumberGetter::AY;
	case GameObjectProperty::LAYER: return PropertyNumberGetter::LAYER;
	case GameObjectProperty::GROUP: return PropertyNumberGetter::GROUP;
	case GameObjectProperty::HSCALE: return PropertyNumberGetter::HSCALE;
	case GameObjectProperty::VSCALE: return PropertyNumberGetter::VSCALE;
	case GameObjectProperty::A: return PropertyNumberGetter::A;
	case GameObjectProperty::B: return PropertyNumberGetter::B;
	case GameObjectProperty::RECT: return PropertyNumberGetter::RECT;
	case GameObjectProperty::ANI: return PropertyNumberGetter::ANI;
	case GameObjectProperty::_A: return PropertyNumberGetter::_A;
	case GameObjectProperty::_R: return PropertyNumberGetter::_R;
	case GameObjectProperty::_G: return PropertyNumberGetter::_G;
	case GameObjectProperty::_B: return PropertyNumberGetter::_B;
	case GameObjectProperty::Z: return PropertyNumberGetter::Z;
	case GameObjectProperty::DZ: return PropertyNumberGetter::DZ;
	case GameObjectProperty::VZ: return PropertyNumberGetter::VZ;
	case GameObjectProperty::AZ: return PropertyNumberGetter::AZ;
	case GameObjectProperty::ZSCALE: return PropertyNumberGetter::ZSCALE;
	default: ;
	}
	return nullptr;
}
PPropertyBooleanGetter symbol::GetPropertyBooleanGetter(GameObjectProperty property)
{
	switch (property)
	{
	case GameObjectProperty::HIDE: return PropertyBooleanGetter::HIDE;
	case GameObjectProperty::BOUND: return PropertyBooleanGetter::BOUND;
	case GameObjectProperty::NAVI: return PropertyBooleanGetter::NAVI;
	case GameObjectProperty::COLLI: return PropertyBooleanGetter::COLLI;
	default:;
	}
	return nullptr;
}
PPropertyNumberSetter symbol::GetPropertyNumberSetter(GameObjectProperty property)
{
	switch (property)
	{
	case GameObjectProperty::X: return PropertyNumberSetter::X;
	case GameObjectProperty::Y: return PropertyNumberSetter::Y;
	//case GameObjectProperty::DX: return PropertyNumberSetter::DX;
	//case GameObjectProperty::DY: return PropertyNumberSetter::DY;
	case GameObjectProperty::ROT: return PropertyNumberSetter::ROT;
	case GameObjectProperty::OMEGA: return PropertyNumberSetter::OMEGA;
	case GameObjectProperty::TIMER: return PropertyNumberSetter::TIMER;
	case GameObjectProperty::VX: return PropertyNumberSetter::VX;
	case GameObjectProperty::VY: return PropertyNumberSetter::VY;
	case GameObjectProperty::AX: return PropertyNumberSetter::AX;
	case GameObjectProperty::AY: return PropertyNumberSetter::AY;
	case GameObjectProperty::LAYER: return PropertyNumberSetter::LAYER;
	case GameObjectProperty::GROUP: return PropertyNumberSetter::GROUP;
	case GameObjectProperty::HSCALE: return PropertyNumberSetter::HSCALE;
	case GameObjectProperty::VSCALE: return PropertyNumberSetter::VSCALE;
	case GameObjectProperty::A: return PropertyNumberSetter::A;
	case GameObjectProperty::B: return PropertyNumberSetter::B;
	case GameObjectProperty::RECT: return PropertyNumberSetter::RECT;
	case GameObjectProperty::ANI: return PropertyNumberSetter::ANI;
	case GameObjectProperty::_A: return PropertyNumberSetter::_A;
	case GameObjectProperty::_R: return PropertyNumberSetter::_R;
	case GameObjectProperty::_G: return PropertyNumberSetter::_G;
	case GameObjectProperty::_B: return PropertyNumberSetter::_B;
	case GameObjectProperty::Z: return PropertyNumberSetter::Z;
	//case GameObjectProperty::DZ: return PropertyNumberSetter::DZ;
	case GameObjectProperty::VZ: return PropertyNumberSetter::VZ;
	case GameObjectProperty::AZ: return PropertyNumberSetter::AZ;
	case GameObjectProperty::ZSCALE: return PropertyNumberSetter::ZSCALE;
	default: ;
	}
	return nullptr;
}
PPropertyBooleanSetter symbol::GetPropertyBooleanSetter(GameObjectProperty property)
{
	switch (property)
	{
	case GameObjectProperty::HIDE: return PropertyBooleanSetter::HIDE;
	case GameObjectProperty::BOUND: return PropertyBooleanSetter::BOUND;
	case GameObjectProperty::NAVI: return PropertyBooleanSetter::NAVI;
	case GameObjectProperty::COLLI: return PropertyBooleanSetter::COLLI;
	default:;
	}
	return nullptr;
}

float symbol::BooleanToNumber(bool v)
{
	return v ? 1.f : 0.f;
}

bool symbol::NumberToBoolean(float v)
{
	return v != 0.f;
}

//

void symbol::ComputeNode::calcHash()
{
	_hash = XXH32(this, sizeof(void*), 0);
}

void ComputeNode::pushLua(lua_State* L)
{
	for (auto i = 0; i < num_out; i++)
		pushLua(L, i);
}

Operand::Type symbol::GetGamePropertyType(GameObjectProperty p)
{
	switch (p)
	{
	case GameObjectProperty::X:
	case GameObjectProperty::Y:
	case GameObjectProperty::DX:
	case GameObjectProperty::DY:
	case GameObjectProperty::ROT:
	case GameObjectProperty::OMEGA:
	case GameObjectProperty::TIMER:
	case GameObjectProperty::VX:
	case GameObjectProperty::VY:
	case GameObjectProperty::AX:
	case GameObjectProperty::AY:
	case GameObjectProperty::LAYER:
	case GameObjectProperty::GROUP:
	case GameObjectProperty::HSCALE:
	case GameObjectProperty::VSCALE:
	case GameObjectProperty::A:
	case GameObjectProperty::B:
	case GameObjectProperty::RECT:
	case GameObjectProperty::ANI:
	case GameObjectProperty::_A:
	case GameObjectProperty::_R:
	case GameObjectProperty::_G:
	case GameObjectProperty::_B:
	case GameObjectProperty::Z:
	case GameObjectProperty::DZ:
	case GameObjectProperty::VZ:
	case GameObjectProperty::AZ:
	case GameObjectProperty::ZSCALE:
		return Operand::Type::Number;
	case GameObjectProperty::HIDE:
	case GameObjectProperty::BOUND:
	case GameObjectProperty::NAVI:
	case GameObjectProperty::COLLI:
		return Operand::Type::Boolean;
	default:;
	}
	return Operand::Type::OprandTypeNum;
}

bool symbol::IsValidNumberProperty(GameObject* obj, GameObjectProperty p)
{
	switch (p)
	{
	case GameObjectProperty::X:
	case GameObjectProperty::Y:
	case GameObjectProperty::DX:
	case GameObjectProperty::DY:
	case GameObjectProperty::ROT:
	case GameObjectProperty::OMEGA:
	case GameObjectProperty::TIMER:
	case GameObjectProperty::VX:
	case GameObjectProperty::VY:
	case GameObjectProperty::AX:
	case GameObjectProperty::AY:
	case GameObjectProperty::LAYER:
	case GameObjectProperty::GROUP:
	case GameObjectProperty::HSCALE:
	case GameObjectProperty::VSCALE:
	case GameObjectProperty::A:
	case GameObjectProperty::B:
	case GameObjectProperty::RECT:
	case GameObjectProperty::ANI:
		return true;
	case GameObjectProperty::_A:
	case GameObjectProperty::_R:
	case GameObjectProperty::_G:
	case GameObjectProperty::_B:
		return obj->cls->extProperty;
	case GameObjectProperty::Z:
	case GameObjectProperty::DZ:
	case GameObjectProperty::VZ:
	case GameObjectProperty::AZ:
	case GameObjectProperty::ZSCALE:
		return obj->cls->is3D;
	default:;
	}
	return false;
}

bool symbol::IsValidBooleanProperty(GameObject* obj, GameObjectProperty p)
{
	switch (p)
	{
	case GameObjectProperty::HIDE:
	case GameObjectProperty::BOUND:
	case GameObjectProperty::NAVI:
	case GameObjectProperty::COLLI:
		return true;
	default:;
	}
	return false;
}

bool symbol::GetGamePropertyNumberValue(GameObject* obj, GameObjectProperty p, float* out)
{
	if (!obj || !out)
		return false;
	const auto getter = GetPropertyNumberGetter(p);
	if (!getter)
		return false;
	*out = getter(obj);
	return true;
}

bool symbol::GetGamePropertyBooleanValue(GameObject* obj, GameObjectProperty p, bool* out)
{
	if (!obj || !out)
		return false;
	const auto getter = GetPropertyBooleanGetter(p);
	if (!getter)
		return false;
	*out = getter(obj);
	return true;
}

std::function<float()> symbol::GetGamePropertyNumber(GameObjectProperty p)
{
#ifdef DISABLE_SYMBOL
	return nullptr;
#else
	const auto number_getter = GetPropertyNumberGetter(p);
	if (number_getter)
	{
		return [=]()
		{
			return number_getter(getCurrentGameObject());
		};
	}
	const auto boolean_getter = GetPropertyBooleanGetter(p);
	if (boolean_getter)
	{
		return [=]()
		{
			return boolean_getter(getCurrentGameObject()) ? 1.f : 0.f;
		};
	}
	return nullptr;
#endif
}

std::function<bool()> symbol::GetGamePropertyBoolean(GameObjectProperty p)
{
#ifdef DISABLE_SYMBOL
	return nullptr;
#else
	switch (GetGamePropertyType(p))
	{
	case ComputeNode::Type::Number:
		return [=]()
		{
			float v = 0;
			GetGamePropertyNumberValue(getCurrentGameObject(), p, &v);
			return v != 0.f;
		};
	case ComputeNode::Type::Boolean:
		return [=]()
		{
			bool v = false;
			GetGamePropertyBooleanValue(getCurrentGameObject(), p, &v);
			return v;
		};
	case ComputeNode::Type::String:
	case ComputeNode::Type::OprandTypeNum:
	default:;
	}
	return nullptr;
#endif
}

std::function<void()> symbol::SetGamePropertyByNode(GameObjectProperty p, ComputeNode* node)
{
#ifdef DISABLE_SYMBOL
	return nullptr;
#else
	const auto number_setter = GetPropertyNumberSetter(p);
	if (number_setter)
	{
		return [=]()
		{
			const auto o = getCurrentGameObject();
			if (o)
				number_setter(o, node->getNumber());
		};
	}
	const auto boolean_setter = GetPropertyBooleanSetter(p);
	if (boolean_setter)
	{
		return [=]()
		{
			const auto o = getCurrentGameObject();
			if (o)
				boolean_setter(o, node->getNumber() != 0.f);
		};
	}
	return nullptr;
#endif
}

GameObject* symbol::getCurrentGameObject()
{
	if (currentObjs.empty())
		return nullptr;
	return currentObjs.back();
}

//

std::unordered_map<std::string, Operator::OperatorDef> Operator::registry;

bool Operator::init(const std::string& name)
{
	const auto it = registry.find(name);
	if (it == registry.end())
		return false;
	const auto def = it->second;
	_name = def.name;
	num_in = def.numIn;
	num_out = def.numOut;
	_type = def.outType;
	_func = def.func;
	switch (_type)
	{
	case Type::Boolean:
		for (auto i = 0; i < num_out; ++i)
			outputs.pushBack(Boolean::createWithValue(false));
		break;
	//case Type::Number: break;
	//case Type::String: break;
	//case Type::OprandTypeNum: break;
	default:
		for (auto i = 0; i < num_out; ++i)
		outputs.pushBack(Number::createWithValue(0.f));
	}
	return static_cast<bool>(_func);
}

Operator* Operator::create(const std::string& name)
{
	auto ret = new (std::nothrow) Operator();
	CREATE_CHECK(ret, ret&&ret->init(name));
}

void Operator::addInput(ComputeNode* node)
{
	if (node)
	{
		if (!node->isAtomic())
			is_atomic = false;
		if (node->requireLuaObj())
			require_luaobj = true;
		inputs.pushBack(node);
	}
}

bool Operator::check()
{
	return inputs.size() == num_in && outputs.size() == num_out;
}

void Operator::execute()
{
	if (!executed)
	{
		_func(this);
		executed = true;
	}
}

void Operator::reset()
{
	executed = false;
	for (auto i : inputs)
		i->reset();
}

float Operator::getNumber(uint32_t idx)
{
	execute();
	return outputs.at(idx)->getNumber();
}

bool Operator::getBoolean(uint32_t idx)
{
	execute();
	return outputs.at(idx)->getBoolean();
}

float Operator::getNumber()
{
	return getNumber(0);
}

bool Operator::getBoolean()
{
	return getBoolean(0);
}

void Operator::pushLua(lua_State* L)
{
	for (auto o : outputs)
	{
		o->pushLua(L);
	}
}

void Operator::pushLua(lua_State* L, uint32_t idx)
{
	if (idx < outputs.size())
	{
		outputs.at(idx)->pushLua(L);
	}
}

void Operator::regist(const std::string& name, uint32_t nIn, uint32_t nOut, Type type, OperatorFunc func)
{
	OperatorDef def;
	def.name = name;
	def.numIn = nIn;
	def.numOut = nOut;
	def.outType = type;
	def.func = func;
	registry[name] = def;
}

void Operator::registBase()
{
	DEF_OP_NUMBER2("add", op1 + op2);
	DEF_OP_NUMBER2("sub", op1 - op2);
	DEF_OP_NUMBER2("mul", op1 * op2);
	DEF_OP_NUMBER2("div", op1 / op2);

	DEF_OP_NUMBER1("abs", abs(op1));

	DEF_OP_NUMBER1("exp", exp(op1));
	DEF_OP_NUMBER1("exp2", exp2(op1));
	DEF_OP_NUMBER1("expm1", expm1(op1));
	DEF_OP_NUMBER1("log", log(op1));
	DEF_OP_NUMBER1("log10", log10(op1));
	DEF_OP_NUMBER1("log2", log2(op1));
	DEF_OP_NUMBER1("log1p", log1p(op1));

	DEF_OP_NUMBER2("pow", pow(op1, op2));
	DEF_OP_NUMBER1("sqrt", sqrt(op1));
	DEF_OP_NUMBER1("cbrt", cbrt(op1));
	DEF_OP_NUMBER2("hypot", hypot(op1, op2));

	DEF_OP_NUMBER1("sin", sin(op1));
	DEF_OP_NUMBER1("cos", cos(op1));
	DEF_OP_NUMBER1("tan", tan(op1));
	DEF_OP_NUMBER1("asin", asin(op1));
	DEF_OP_NUMBER1("acos", acos(op1));
	DEF_OP_NUMBER1("atan", atan(op1));
	DEF_OP_NUMBER2("atan2", atan2(op1, op2));

	DEF_OP_NUMBER1("ceil", ceil(op1));
	DEF_OP_NUMBER1("floor", floor(op1));
	DEF_OP_NUMBER1("trunc", trunc(op1));
	DEF_OP_NUMBER1("round", round(op1));
	DEF_OP_NUMBER1("nearbyint", nearbyint(op1));

	DEF_OP_NUMBER2("fmod", fmod(op1, op2));
	DEF_OP_NUMBER2("remainder", remainder(op1, op2));

	DEF_OP_BOOLEAN2("and", op1&&op2);
	DEF_OP_BOOLEAN2("or", op1||op2);
	DEF_OP_BOOLEAN1("not", !op1);

	regist("eq", 2, 1, Type::Boolean, [](Operator* op)
	{
		if (op->inputs.at(0)->getType() != op->inputs.at(1)->getType())
			op->outBoolean(0, false);
		else
			op->outBoolean(0, op->getInNumber(0) == op->getInNumber(1));
	});
	regist("le", 2, 1, Type::Boolean, [](Operator* op)
	{
		if (op->inputs.at(0)->getType() != op->inputs.at(1)->getType())
			op->outBoolean(0, false);
		else
		{
			op->outBoolean(0, op->getInNumber(0) <= op->getInNumber(1));
		}
	});
	regist("lt", 2, 1, Type::Boolean, [](Operator* op)
	{
		if (op->inputs.at(0)->getType() != op->inputs.at(1)->getType())
			op->outBoolean(0, false);
		else
		{
			op->outBoolean(0, op->getInNumber(0) < op->getInNumber(1));
		}
	});
	regist("cond", 3, 1, Type::Number, [](Operator* op)
	{
		if (op->getInBoolean(0))
			op->outNumber(0, op->getInNumber(1));
		else
			op->outNumber(0, op->getInNumber(2));
	});
	regist("assert", 1, 1, Type::Boolean, [](Operator* op)
	{
		op->outBoolean(0, op->getInBoolean(0));
		if (!op->getInBoolean(0))
		{
			XINFO("assertation failed");
		}
	});
}

Assigment* Assigment::create(ComputeNode* var)
{
	auto ret = new(std::nothrow) Assigment();
	CREATE_CHECK(ret, ret&&ret->initWithRValue(var));
}

Assigment* Assigment::createWithObjProperty(const std::string& property, ComputeNode* var)
{
	auto ret = new(std::nothrow) Assigment();
	CREATE_CHECK(ret, ret&&ret->initWithObjProperty(property, var));
}

float Assigment::getNumber()
{
	if (output)
		return output->getNumber();
	return rvalue->getNumber();
}

bool Assigment::getBoolean()
{
	if (output)
		return output->getBoolean();
	return rvalue->getBoolean();
}

void Assigment::pushLua(lua_State* L, uint32_t idxOut)
{
	if (output)
		output->pushLua(L, idxOut);
	else if(rvalue)
		rvalue->pushLua(L, idxOut);
}

void Assigment::exe()
{
	rvalue->reset();
	eval();
}

bool Assigment::initWithRValue(ComputeNode* var)
{
	if (!var)
		return false;
	rvalue = var;
	rvalue->retain();
	num_in = 0;
	num_out = 0;
	is_atomic = var->isAtomic();
	require_luaobj = var->requireLuaObj();
	switch (rvalue->getType()) {
	case Type::Number:
		output = Number::createWithValue(0.f);
		output->retain();
		eval = [this]() {output->_setNumber(rvalue->getNumber()); };
		return true;
	case Type::Boolean:
		output = Boolean::createWithValue(false);
		output->retain();
		eval = [this]() {output->_setBoolean(rvalue->getBoolean()); };
		return true;
	//case Type::String: break;
	//case Type::OprandTypeNum: break;
	default:
		XWARNING("wrong type: %d",int(rvalue->getType()));
		return false;
	}
}

bool Assigment::initWithObjProperty(const std::string& objProperty, ComputeNode* var)
{
	if (!var)
		return false;
	rvalue = var;
	rvalue->retain();
	num_in = 0;
	num_out = 0;
	is_atomic = var->isAtomic();
	require_luaobj = var->requireLuaObj();
	objField = objProperty;
	const auto t = GameObjectPropertyHash(objProperty.c_str());
	eval = SetGamePropertyByNode(t, var);
	if (eval)
		return true;
	const auto type = var->getType();
	const auto L = lua::stack()->getLuaState();
	if (type == Operand::Type::Number)
	{
		eval = [L, this]()
		{
			//if (!getCurrentGameObject())
			//	return;
			lua_pushstring(L, objField.c_str());
			lua_pushnumber(L, rvalue->getNumber());
			lua_rawset(L, -3);
			//lua_setfield(L, -2, objField.c_str());
		};
		return true;
	}
	else if (type == Operand::Type::Boolean)
	{
		eval = [L, this]()
		{
			//if (!getCurrentGameObject())
			//	return;
			lua_pushstring(L, objField.c_str());
			lua_pushboolean(L, rvalue->getBoolean());
			lua_rawset(L, -3);
			//lua_setfield(L, -2, objField.c_str());
		};
		return true;
	}
	return false;
}

Assigment::~Assigment()
{
	CC_SAFE_RELEASE_NULL(rvalue);
	CC_SAFE_RELEASE_NULL(output);
}

cocos2d::Vector<Block*> Block::created;

Block* Block::create()
{
	auto ret = new(std::nothrow) Block();
	if (ret)
	{
		ret->autorelease();
		created.pushBack(ret);
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;;
}

void Block::push(Statement* s)
{
	if (!s)
		return;
	statements.pushBack(s);
	if (!s->isAtomic())
		is_atomic = false;
	if (s->requireLuaObj())
		require_luaobj = true;
}

void Block::clear()
{
	statements.clear();
	outputs.clear();
	num_out = 0;
	require_luaobj = false;
	is_atomic = true;
}

void Block::exe(GameObject* obj)
{
	if (!obj)
		return;
	currentObjs.push_back(obj);
	for (auto s: statements)
	{
		s->exe();
	}
	currentObjs.pop_back();
}

void Block::addOutputNode(ComputeNode* node)
{
	if(node)
	{
		outputs.pushBack(node);
		num_out += node->getNumOut();
		if (num_out > 0)
			is_atomic = false;
	}
}

void Block::executeLua(GameObject* obj)
{
	if (!obj)
		return;
	//if (require_luaobj)
	//{
	//	LPOOL.pushObject(obj);
	//}
	currentObjs.push_back(obj);
	for (auto s : statements)
		s->exe();
	currentObjs.pop_back();
	const auto L = lua::stack()->getLuaState();
	//if (require_luaobj)
	//{
	//	lua_pop(L, 1);
	//}
	for (auto o : outputs)
		o->pushLua(L);
}

void Block::executeLua()
{
	const auto obj = LPOOL.getCurrentObject();
	if (!obj)
		return;
	if (require_luaobj)
	{
		LPOOL.pushObject(obj);
	}
	currentObjs.push_back(obj);
	for (auto s : statements)
		s->exe();
	currentObjs.pop_back();
	const auto L = lua::stack()->getLuaState();
	if (require_luaobj)
	{
		lua_pop(L, 1);
	}
	for (auto o : outputs)
		o->pushLua(L);
}

Block::~Block()
{
	clear();
}
