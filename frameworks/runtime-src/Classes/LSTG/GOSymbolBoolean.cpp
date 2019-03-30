#include "GOSymbolBoolean.h"
#include "UtilLua.h"

using namespace lstg;
using namespace lstg::symbol;

#define CREATE_CHECK(p, _cond) if (_cond){(p)->autorelease();return (p);} CC_SAFE_DELETE(p); return nullptr;


//

Boolean* Boolean::createWithValue(bool v)
{
	auto ret = new(std::nothrow) Boolean();
	CREATE_CHECK(ret, ret&&ret->initWithValue(v));
}

Boolean* Boolean::createWithObjProperty(const std::string& property)
{
	Boolean* ret = BooleanFromGameObject::create(GameObjectPropertyHash(property.c_str()));
	if (!ret)
		ret = BooleanFromGameObjectLua::create(property);
	return ret;
}

bool Boolean::initWithValue(bool v)
{
	_source = Source::Value;
	_value = v;
	return true;
}

void Boolean::pushLua(lua_State* L, uint32_t /*idxOut*/)
{
	lua_pushboolean(L, _value);
}

BooleanFromGameObject* BooleanFromGameObject::create(GameObjectProperty p)
{
	auto ret = new (std::nothrow) BooleanFromGameObject();
	CREATE_CHECK(ret, ret&&ret->init(p));
}

bool BooleanFromGameObject::getBoolean()
{
	return _eval();
}

void BooleanFromGameObject::pushLua(lua_State* L, uint32_t /*idxOut*/)
{
	lua_pushboolean(L, _eval());
}

bool BooleanFromGameObject::init(GameObjectProperty p)
{
	_source = Source::GameObject;
	_p = p;
	is_atomic = true;
	require_luaobj = false;
	_eval = GetGamePropertyBoolean(p);
	return _eval != nullptr;
}

BooleanFromGameObjectLua* BooleanFromGameObjectLua::create(const std::string& field)
{
	auto ret = new (std::nothrow) BooleanFromGameObjectLua();
	CREATE_CHECK(ret, ret&&ret->init(field));
}

bool BooleanFromGameObjectLua::getBoolean()
{
	const auto L = lua::stack()->getLuaState();
	lua_pushstring(L, _field.c_str());
	lua_rawget(L, -2);
	//lua_getfield(L, -1, _field.c_str());
	const bool ret = lua_toboolean(L, -1);
	lua_pop(L, 1);
	return ret;
}

void BooleanFromGameObjectLua::pushLua(lua_State* L, uint32_t /*idxOut*/)
{
	lua_pushstring(L, _field.c_str());
	lua_rawget(L, -2);
	//lua_getfield(L, -1, _field.c_str());
	const bool ret = lua_toboolean(L, -1);
	lua_pop(L, 1);
	lua_pushboolean(L, ret);
}

bool BooleanFromGameObjectLua::init(const std::string& field)
{
	_source = Source::GameObjectLua;
	is_atomic = false;
	require_luaobj = true;
	_field = field;
	return true;
}
