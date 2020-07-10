#include "GOSymbolNumber.h"
#include "UtilLua.h"
//#include "AppFrame.h"
//#include "xxhash/xxhash.h"

using namespace lstg;
using namespace lstg::symbol;

#define CREATE_CHECK(p, _cond) if (_cond){(p)->autorelease();return (p);} CC_SAFE_DELETE(p); return nullptr;

Number* Number::createWithValue(float v)
{
	auto ret = new(std::nothrow) Number();
	CREATE_CHECK(ret, ret&&ret->initWithValue(v));
}

Number* Number::createWithObjProperty(const std::string& property)
{
	Number* ret = NumberFromGameObject::create(GameObjectPropertyHash(property.c_str()));
	if (!ret)
		ret = NumberFromGameObjectLua::create(property);
	return ret;
}

bool Number::initWithValue(float v)
{
	_source = Source::Value;
	is_atomic = true;
	_value = v;
	return true;
}

void Number::pushLua(lua_State* L, uint32_t /*idxOut*/)
{
	lua_pushnumber(L, _value);
}

NumberFromGameObject* NumberFromGameObject::create(GameObjectProperty p)
{
	auto ret = new (std::nothrow) NumberFromGameObject();
	CREATE_CHECK(ret, ret&&ret->init(p));
}

float NumberFromGameObject::getNumber()
{
	return _eval();
}

void NumberFromGameObject::pushLua(lua_State* L, uint32_t idxOut)
{
	lua_pushnumber(L, _eval());
}

bool NumberFromGameObject::init(GameObjectProperty p)
{
	_source = Source::GameObject;
	_p = p;
	is_atomic = true;
	require_luaobj = false;
	_eval = GetGamePropertyNumber(p);
	return _eval != nullptr;
}

NumberFromGameObjectLua* NumberFromGameObjectLua::create(const std::string& field)
{
	auto ret = new (std::nothrow) NumberFromGameObjectLua();
	CREATE_CHECK(ret, ret&&ret->init(field));
}

float NumberFromGameObjectLua::getNumber()
{
	const auto L = lua::stack()->getLuaState();
	lua_pushstring(L, _field.c_str());
	lua_rawget(L, -2);
	//lua_getfield(L, -1, _field.c_str());
	const float ret = lua_tonumber(L, -1);
	lua_pop(L, 1);
	return ret;
}

void NumberFromGameObjectLua::pushLua(lua_State* L, uint32_t idxOut)
{
	lua_pushstring(L, _field.c_str());
	lua_rawget(L, -2);
	//lua_getfield(L, -1, _field.c_str());
	const float ret = lua_tonumber(L, -1);
	lua_pop(L, 1);
	lua_pushnumber(L, ret);
}

bool NumberFromGameObjectLua::init(const std::string& field)
{
	_source = Source::GameObjectLua;
	is_atomic = false;
	require_luaobj = true;
	_field = field;
	return true;
}
