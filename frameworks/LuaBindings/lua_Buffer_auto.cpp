#include "lua_Buffer_auto.hpp"
#include "XBuffer.h"

int lua_lstg_Buffer_assign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:assign");
	LUA_TRY_INVOKE(3, &lstg::Buffer::assign);
	LUA_INVOKE_FOOTER("3");
}
int lua_lstg_Buffer_assign_value(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:assign_value");
	LUA_TRY_INVOKE(2, &lstg::Buffer::assign_value);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Buffer_assign_values(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:assign_values");
	LUA_TRY_INVOKE(1, &lstg::Buffer::assign_values);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Buffer_at(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:at");
	LUA_TRY_INVOKE_R(1, &lstg::Buffer::at);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Buffer_back(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:back");
	LUA_TRY_INVOKE_R(0, &lstg::Buffer::back);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_capacity(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:capacity");
	LUA_TRY_INVOKE_R(0, &lstg::Buffer::capacity);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_clear(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:clear");
	LUA_TRY_INVOKE(0, &lstg::Buffer::clear);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_clone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:clone");
	LUA_TRY_INVOKE_R(0, &lstg::Buffer::clone);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_copy(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:copy");
	LUA_TRY_INVOKE(1, &lstg::Buffer::copy);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Buffer_empty(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:empty");
	LUA_TRY_INVOKE_R(0, &lstg::Buffer::empty);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_erase(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:erase");
	LUA_TRY_INVOKE(2, &lstg::Buffer::erase);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Buffer_front(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:front");
	LUA_TRY_INVOKE_R(0, &lstg::Buffer::front);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_insert(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:insert");
	LUA_TRY_INVOKE(4, &lstg::Buffer::insert);
	LUA_INVOKE_FOOTER("4");
}
int lua_lstg_Buffer_insert_data(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:insert_data");
	LUA_TRY_INVOKE(3, &lstg::Buffer::insert_data);
	LUA_INVOKE_FOOTER("3");
}
int lua_lstg_Buffer_insert_value(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:insert_value");
	LUA_TRY_INVOKE(3, &lstg::Buffer::insert_value);
	LUA_INVOKE_FOOTER("3");
}
int lua_lstg_Buffer_insert_values(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:insert_values");
	LUA_TRY_INVOKE(2, &lstg::Buffer::insert_values);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Buffer_isAppendable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:isAppendable");
	LUA_TRY_INVOKE_R(0, &lstg::Buffer::isAppendable);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_isResizable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:isResizable");
	LUA_TRY_INVOKE_R(0, &lstg::Buffer::isResizable);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_isShrinkable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:isShrinkable");
	LUA_TRY_INVOKE_R(0, &lstg::Buffer::isShrinkable);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_isWritable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:isWritable");
	LUA_TRY_INVOKE_R(0, &lstg::Buffer::isWritable);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_move(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:move");
	LUA_TRY_INVOKE(1, &lstg::Buffer::move);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Buffer_pop_back(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:pop_back");
	LUA_TRY_INVOKE(0, &lstg::Buffer::pop_back);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_push_back(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:push_back");
	LUA_TRY_INVOKE(1, &lstg::Buffer::push_back);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Buffer_reserve(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:reserve");
	LUA_TRY_INVOKE(1, &lstg::Buffer::reserve);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Buffer_resize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:resize");
	LUA_TRY_INVOKE(2, static_cast<void(lstg::Buffer::*)(size_t, uint8_t)>(&lstg::Buffer::resize));
	LUA_TRY_INVOKE(1, [](lstg::Buffer* obj, size_t arg0){{return obj->resize(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_Buffer_set(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:set");
	LUA_TRY_INVOKE(2, &lstg::Buffer::set);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Buffer_setAppendable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:setAppendable");
	LUA_TRY_INVOKE(1, &lstg::Buffer::setAppendable);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Buffer_setResizable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:setResizable");
	LUA_TRY_INVOKE(1, &lstg::Buffer::setResizable);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Buffer_setShrinkable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:setShrinkable");
	LUA_TRY_INVOKE(1, &lstg::Buffer::setShrinkable);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Buffer_setWritable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:setWritable");
	LUA_TRY_INVOKE(1, &lstg::Buffer::setWritable);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Buffer_set_values(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:set_values");
	LUA_TRY_INVOKE(2, &lstg::Buffer::set_values);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Buffer_shrink_to_fit(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:shrink_to_fit");
	LUA_TRY_INVOKE(0, &lstg::Buffer::shrink_to_fit);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_size(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:size");
	LUA_TRY_INVOKE_R(0, &lstg::Buffer::size);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_swap(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:swap");
	LUA_TRY_INVOKE(1, &lstg::Buffer::swap);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Buffer_to_string(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Buffer", "lstg.Buffer:to_string");
	LUA_TRY_INVOKE_R(0, &lstg::Buffer::to_string);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Buffer_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Buffer", "lstg.Buffer:create");
	LUA_TRY_INVOKE_R(1, static_cast<lstg::Buffer*(*)(size_t)>(&lstg::Buffer::create));
	LUA_TRY_INVOKE_R(0, [](){{return lstg::Buffer::create();}});
	LUA_SINVOKE_FOOTER("0,1");
}
int lua_lstg_Buffer_createFromString(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Buffer", "lstg.Buffer:createFromString");
	LUA_TRY_INVOKE_R(1, &lstg::Buffer::createFromString);
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_Buffer_lstgBuffer(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::Buffer, "Buffer", "lstg.Buffer",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("assign", lua_lstg_Buffer_assign);
	LUA_METHOD("assign_value", lua_lstg_Buffer_assign_value);
	LUA_METHOD("assign_values", lua_lstg_Buffer_assign_values);
	LUA_METHOD("at", lua_lstg_Buffer_at);
	LUA_METHOD("back", lua_lstg_Buffer_back);
	LUA_METHOD("capacity", lua_lstg_Buffer_capacity);
	LUA_METHOD("clear", lua_lstg_Buffer_clear);
	LUA_METHOD("clone", lua_lstg_Buffer_clone);
	LUA_METHOD("copy", lua_lstg_Buffer_copy);
	LUA_METHOD("empty", lua_lstg_Buffer_empty);
	LUA_METHOD("erase", lua_lstg_Buffer_erase);
	LUA_METHOD("front", lua_lstg_Buffer_front);
	LUA_METHOD("insert", lua_lstg_Buffer_insert);
	LUA_METHOD("insert_data", lua_lstg_Buffer_insert_data);
	LUA_METHOD("insert_value", lua_lstg_Buffer_insert_value);
	LUA_METHOD("insert_values", lua_lstg_Buffer_insert_values);
	LUA_METHOD("isAppendable", lua_lstg_Buffer_isAppendable);
	LUA_METHOD("isResizable", lua_lstg_Buffer_isResizable);
	LUA_METHOD("isShrinkable", lua_lstg_Buffer_isShrinkable);
	LUA_METHOD("isWritable", lua_lstg_Buffer_isWritable);
	LUA_METHOD("move", lua_lstg_Buffer_move);
	LUA_METHOD("pop_back", lua_lstg_Buffer_pop_back);
	LUA_METHOD("push_back", lua_lstg_Buffer_push_back);
	LUA_METHOD("reserve", lua_lstg_Buffer_reserve);
	LUA_METHOD("resize", lua_lstg_Buffer_resize);
	LUA_METHOD("set", lua_lstg_Buffer_set);
	LUA_METHOD("setAppendable", lua_lstg_Buffer_setAppendable);
	LUA_METHOD("setResizable", lua_lstg_Buffer_setResizable);
	LUA_METHOD("setShrinkable", lua_lstg_Buffer_setShrinkable);
	LUA_METHOD("setWritable", lua_lstg_Buffer_setWritable);
	LUA_METHOD("set_values", lua_lstg_Buffer_set_values);
	LUA_METHOD("shrink_to_fit", lua_lstg_Buffer_shrink_to_fit);
	LUA_METHOD("size", lua_lstg_Buffer_size);
	LUA_METHOD("swap", lua_lstg_Buffer_swap);
	LUA_METHOD("to_string", lua_lstg_Buffer_to_string);
	LUA_METHOD("create", lua_lstg_Buffer_create);
	LUA_METHOD("createFromString", lua_lstg_Buffer_createFromString);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
