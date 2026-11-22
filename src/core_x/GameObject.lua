--local ffi = ffi or require('ffi')
--ffi.cdef
--[[
	struct GameObject
	{
		double x, y;  // 中心坐标
		double vx, vy;  // 速度
		double ax, ay;  // 加速度
		double rot, omiga;  // 旋转角度与角度增量
		double lastx, lasty;  // (不可见)上一帧中心坐标
		double dx, dy;  // (只读)上一帧中心坐标相对中心坐标的偏移量
		double a, b;  // 单位的横向、纵向碰撞大小的一半
		double hscale, vscale;  // 横向、纵向拉伸率，仅影响渲染

		void *__pObjectPrev, *__pObjectNext;
		void *__pRenderPrev, *__pRenderNext;
		void *__pCollisionPrev, *__pCollisionNext;
		void* __res;  // 渲染资源
		void* __ps;  // 粒子系统

		double __layer;  // 图层
		double __col_r;

		ptrdiff_t group;  // 对象所在的碰撞组
		ptrdiff_t timer, ani;  // 计数器

		bool colli;  // 是否参与碰撞
		bool rect;   // 是否为矩形碰撞盒
		bool bound;  // 是否越界清除
		bool hide;   // 是否隐藏
		bool navi;   // 是否自动转向

		int __status;  // (不可见)对象状态
		size_t id;  // (不可见)对象在对象池中的id
		int64_t __uid;  // (不可见)对象唯一id
		uint32_t __classID;
	}
]]
--[[
--local rawget = rawget
--local rawset = rawset
local assert = assert

local pool = ObjTable()
--local ot = ObjTable()

local IDX_INIT = 1
local IDX_DEL = 2
local IDX_FRAME = 3
local IDX_RENDER = 4
local IDX_COLLI = 5
local IDX_KILL = 6
local IDX_CID = 7

local GAMEOBJECTSTATUS = {
    STATUS_FREE    = 0, -- 空闲状态、用于标识链表伪头部
    STATUS_DEFAULT = 1, -- 正常状态
    STATUS_KILL    = 2, -- 被kill事件触发
    STATUS_DEL     = 3  -- 被del事件触发
}
local _status_set_t = {
    normal = GAMEOBJECTSTATUS.STATUS_DEFAULT,
    kill   = GAMEOBJECTSTATUS.STATUS_KILL,
    del    = GAMEOBJECTSTATUS.STATUS_DEL
}
local _status_get_t = {
    [GAMEOBJECTSTATUS.STATUS_DEFAULT] = 'normal',
    [GAMEOBJECTSTATUS.STATUS_KILL]    = 'kill',
    [GAMEOBJECTSTATUS.STATUS_DEL]     = 'del'
}

local getter = {
    layer  = function(o)
        return o.__layer
    end,
    status = function(o)
        return _status_get_t[o.__status] or 'normal'
    end,

    img    = function(o)
    end,
    class  = function(o)
        return pool[o.id + 1][1]
    end,
    layer  = function(o)
    end,
    layer  = function(o)
    end,
}
local setter = {
    layer  = function(o, v)
    end,
    status = function(o, v)
        o.__status = _status_set_t[v] or 1
    end,

    img    = function(o, v)
    end,
    class  = function(o, v)
        assert(v.is_class)
        pool[o.id + 1][1] = v
        o.__classID = v[IDX_CID]
    end,
    layer  = function(o, v)
    end,
    layer  = function(o, v)
    end,
}

local mt = {
    __index    = function(obj, k)
        local t = pool[obj.id + 1]
        return t[k]
    end,
    __newindex = function(obj, k, v)
        local t = pool[obj.id + 1]
        t[k] = v
    end
}
local obj_t = ffi.metatype(ffi.typeof('struct GameObject'), mt)

local _alloc = lstg.AllocateObject
local _is64 = ffi.abi('64bit')
local function allocObj()
    local t = _alloc()
    if _is64 then
        t = loadstring(t)()
        return ffi.cast('struct GameObject*', t)[0]
    else
        t = ffi.cast('uint32_t', t)
        return ffi.cast('struct GameObject*', t)[0]
    end
end

local m = {}

function m:New(cls, ...)
    assert(cls.is_class)
    local obj = allocObj()
    local id = obj.id
    local t = { cls, id }
    pool[id + 1] = t
    obj.__classID = cls[IDX_CID]
    cls[IDX_INIT](obj, ...)
    obj.lastx = obj.x
    obj.lasty = obj.y
    return obj
end

return m
]]
