#include "GameObjectSymbol.h"
#include "GameObjectPropertyHash.h"
#include "AppFrame.h"
#include "UtilLua.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "xxhash/xxhash.h"
#include "GOSymbolNumber.h"
#include "GOSymbolBoolean.h"
#include <cmath>

using namespace lstg;
using namespace lstg::symbol;
using namespace cocos2d;

static std::vector<GameObject*> currentObjs;

#define CREATE_CHECK(p, _cond) if (_cond){(p)->autorelease();return (p);} CC_SAFE_DELETE(p); return nullptr;

#ifndef DISABLE_SYMBOL

#define GET_PROPERTY_TRANS(_P) [](){\
	const auto o = getCurrentGameObject();\
	return o ? o->cm->pool->_P[o->id] : 0.f; }
#define GET_PROPERTY_COLLI(_P) [](){\
	return getCurrentGameObject() ? getCurrentGameObject()->cm->getDataColli()->_P : 0.f; }
#define GET_PROPERTY_OBJ_NUMBER(_P) [](){\
	return getCurrentGameObject() ? getCurrentGameObject()->_P : 0.f; }

#define GET_PROPERTY_BOOLEAN_NUMBER(_P) [](){\
	return getCurrentGameObject() ? float(int(getCurrentGameObject()->_P)) : 0.f; }
#define GET_PROPERTY_OBJ_BOOLEAN(_P) [](){\
	return getCurrentGameObject() ? getCurrentGameObject()->_P : false; }

#define GET_PROPERTY_TRANS_BOOLEAN(_P) [](){\
	const auto o = getCurrentGameObject();\
	return o ? (o->cm->pool->_P[o->id] != 0.f) : false; }

#define SET_PROPERTY_TRANS(_P) [node](){\
	const auto o = getCurrentGameObject();\
	if(o) o->cm->pool->_P[o->id] = node->getNumber(); }
#define SET_PROPERTY_COLLI(_P) [node](){\
	if(getCurrentGameObject()) getCurrentGameObject()->cm->getDataColli()->_P = node->getNumber(); }
#define SET_PROPERTY_OBJ(_P) [node](){\
	if(getCurrentGameObject()) getCurrentGameObject()->_P = node->getNumber(); }

#define SET_PROPERTY_BOOLEAN(_P) [node](){\
	if(getCurrentGameObject()) getCurrentGameObject()->_P = node->getBoolean(); }

#endif

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
		return Operand::Type::Number;
	case GameObjectProperty::HIDE:
	case GameObjectProperty::BOUND:
	case GameObjectProperty::NAVI:
	case GameObjectProperty::COLLI:
		return Operand::Type::Boolean;
	case GameObjectProperty::STATUS:
	case GameObjectProperty::CLASS:
	case GameObjectProperty::IMG:
	case GameObjectProperty::_KEY_NOT_FOUND:
	default:
		return Operand::Type::OprandTypeNum;
	}
}

std::function<float()> symbol::GetGamePropertyNumber(GameObjectProperty p)
{
#ifdef DISABLE_SYMBOL
	return nullptr;
#else
	switch (p)
	{
	case GameObjectProperty::X: return GET_PROPERTY_TRANS(x);
	case GameObjectProperty::Y: return GET_PROPERTY_TRANS(y);
	case GameObjectProperty::DX: return GET_PROPERTY_TRANS(dx);
	case GameObjectProperty::DY: return GET_PROPERTY_TRANS(dy);
	case GameObjectProperty::ROT: return GET_PROPERTY_TRANS(rot);
	case GameObjectProperty::OMEGA: return GET_PROPERTY_TRANS(omega);
	case GameObjectProperty::TIMER: return GET_PROPERTY_OBJ_NUMBER(timer);
	case GameObjectProperty::VX: return GET_PROPERTY_TRANS(vx);
	case GameObjectProperty::VY: return GET_PROPERTY_TRANS(vy);
	case GameObjectProperty::AX: return GET_PROPERTY_TRANS(ax);
	case GameObjectProperty::AY: return GET_PROPERTY_TRANS(ay);
	case GameObjectProperty::LAYER: return GET_PROPERTY_OBJ_NUMBER(layer);
	case GameObjectProperty::GROUP: return GET_PROPERTY_COLLI(group);
	case GameObjectProperty::HSCALE: return GET_PROPERTY_TRANS(hscale);
	case GameObjectProperty::VSCALE: return GET_PROPERTY_TRANS(vscale);
	case GameObjectProperty::A: return GET_PROPERTY_COLLI(a);
	case GameObjectProperty::B: return GET_PROPERTY_COLLI(b);
	case GameObjectProperty::ANI: return GET_PROPERTY_OBJ_NUMBER(ani_timer);
	case GameObjectProperty::RECT: return []()
	{
		return getCurrentGameObject() ? int(getCurrentGameObject()->cm->getDataColli()->type) : 0.f;
	};

	case GameObjectProperty::HIDE: return GET_PROPERTY_BOOLEAN_NUMBER(hide);
	case GameObjectProperty::BOUND: return GET_PROPERTY_BOOLEAN_NUMBER(bound);
	case GameObjectProperty::NAVI: return GET_PROPERTY_TRANS(navi);
	case GameObjectProperty::COLLI: return GET_PROPERTY_BOOLEAN_NUMBER(colli);

	default:
		return nullptr;
	}
#endif
}

std::function<bool()> symbol::GetGamePropertyBoolean(GameObjectProperty p)
{
#ifdef DISABLE_SYMBOL
	return nullptr;
#else
	switch (p)
	{
	case GameObjectProperty::X: return GET_PROPERTY_TRANS_BOOLEAN(x);
	case GameObjectProperty::Y: return GET_PROPERTY_TRANS_BOOLEAN(y);
	case GameObjectProperty::DX: return GET_PROPERTY_TRANS_BOOLEAN(dx);
	case GameObjectProperty::DY: return GET_PROPERTY_TRANS_BOOLEAN(dy);
	case GameObjectProperty::ROT: return GET_PROPERTY_TRANS_BOOLEAN(rot);
	case GameObjectProperty::OMEGA: return GET_PROPERTY_TRANS_BOOLEAN(omega);
	case GameObjectProperty::TIMER: return GET_PROPERTY_OBJ_BOOLEAN(timer);
	case GameObjectProperty::VX: return GET_PROPERTY_TRANS_BOOLEAN(vx);
	case GameObjectProperty::VY: return GET_PROPERTY_TRANS_BOOLEAN(vy);
	case GameObjectProperty::AX: return GET_PROPERTY_TRANS_BOOLEAN(ax);
	case GameObjectProperty::AY: return GET_PROPERTY_TRANS_BOOLEAN(ay);
	case GameObjectProperty::LAYER: return GET_PROPERTY_OBJ_BOOLEAN(layer);
	case GameObjectProperty::GROUP: return GET_PROPERTY_COLLI(group);
	case GameObjectProperty::HSCALE: return GET_PROPERTY_TRANS_BOOLEAN(hscale);
	case GameObjectProperty::VSCALE: return GET_PROPERTY_TRANS_BOOLEAN(vscale);
	case GameObjectProperty::A: return GET_PROPERTY_COLLI(a);
	case GameObjectProperty::B: return GET_PROPERTY_COLLI(b);
	case GameObjectProperty::ANI: return GET_PROPERTY_OBJ_BOOLEAN(ani_timer);
	case GameObjectProperty::RECT: return []()
	{
		return getCurrentGameObject() ? int(getCurrentGameObject()->cm->getDataColli()->type) != 0 : false;
	};

	case GameObjectProperty::HIDE: return GET_PROPERTY_OBJ_BOOLEAN(hide);
	case GameObjectProperty::BOUND: return GET_PROPERTY_OBJ_BOOLEAN(bound);
	case GameObjectProperty::NAVI: return GET_PROPERTY_TRANS_BOOLEAN(navi);
	case GameObjectProperty::COLLI: return GET_PROPERTY_OBJ_BOOLEAN(colli);

	default:
		return nullptr;
	}
#endif
}

std::function<void()> symbol::SetGamePropertyByNode(GameObjectProperty p, ComputeNode* node)
{
#ifdef DISABLE_SYMBOL
	return nullptr;
#else
	switch (p)
	{
	case GameObjectProperty::X: return SET_PROPERTY_TRANS(x);
	case GameObjectProperty::Y: return SET_PROPERTY_TRANS(y);
	case GameObjectProperty::DX: return SET_PROPERTY_TRANS(dx);
	case GameObjectProperty::DY: return SET_PROPERTY_TRANS(dy);
	case GameObjectProperty::ROT: return SET_PROPERTY_TRANS(rot);
	case GameObjectProperty::OMEGA: return SET_PROPERTY_TRANS(omega);
	case GameObjectProperty::TIMER: return SET_PROPERTY_OBJ(timer);
	case GameObjectProperty::VX: return SET_PROPERTY_TRANS(vx);
	case GameObjectProperty::VY: return SET_PROPERTY_TRANS(vy);
	case GameObjectProperty::AX: return SET_PROPERTY_TRANS(ax);
	case GameObjectProperty::AY: return SET_PROPERTY_TRANS(ay);
	case GameObjectProperty::LAYER: return SET_PROPERTY_OBJ(layer);
	case GameObjectProperty::GROUP: return SET_PROPERTY_COLLI(group);
	case GameObjectProperty::HSCALE: return SET_PROPERTY_TRANS(hscale);
	case GameObjectProperty::VSCALE: return SET_PROPERTY_TRANS(vscale);
	case GameObjectProperty::A: return SET_PROPERTY_COLLI(a);
	case GameObjectProperty::B: return SET_PROPERTY_COLLI(b);
	case GameObjectProperty::ANI: return SET_PROPERTY_OBJ(ani_timer);
	case GameObjectProperty::RECT: return [node]()
	{
		if(getCurrentGameObject()) getCurrentGameObject()->cm->getDataColli()->type = (XColliderType)int(node->getNumber());
	};

	case GameObjectProperty::HIDE: return SET_PROPERTY_BOOLEAN(hide);
	case GameObjectProperty::BOUND: return SET_PROPERTY_BOOLEAN(bound);
	case GameObjectProperty::NAVI: return SET_PROPERTY_TRANS(navi);
	case GameObjectProperty::COLLI: return SET_PROPERTY_BOOLEAN(colli);

	default:
		return nullptr;
	}
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
