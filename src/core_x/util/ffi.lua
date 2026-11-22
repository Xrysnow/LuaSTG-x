---
--- ffi.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---


local ffi = ffi or require('ffi')

ffi.nullptr = ffi.cast('void*', 0)

function ffi.isnullptr(p)
    return not (ffi.cast('void*', p) > nil)
end

local C = ffi.C
local typeof = ffi.typeof
local sizeof = ffi.sizeof
local cast = ffi.cast
local gc = ffi.gc
--local new = ffi.new
--local byte = ffi.typeof('uint8_t')
--local _ptr_size = sizeof('void*')
local _ptr_t = typeof('void*')
--local _pptr_t = typeof('void*[1]')

function ffi.alloc(typestr, size)
    size = size or 1
    local ptr = cast(typeof("$ *", typestr), C.malloc(sizeof(typestr) * size))
    gc(ptr, C.free)
    return ptr
end

function ffi.alloc_raw(size)
    local ptr = C.malloc(size)
    gc(ptr, C.free)
    return ptr
end

function ffi.convert_ptr(userdata, cdata_ptr_t)
    return cast(cdata_ptr_t or _ptr_t, userdata)
end

function ffi.try_cdef(s)
    assert(type(s) == 'string')
    local ok, msg = pcall(ffi.cdef, s)
    if not ok then
        print(msg)
    end
end

