--
local M = {}
local ffi = require('ffi')
require('util.ffi_cstd.stdlib')
require('core_x.util.ffi')

ffi.cdef [[
char* get_current_dir_name();
]]

function M.get_current_dir_name()
    local p = ffi.C.get_current_dir_name()
    if ffi.isnullptr(p) then
        return nil
    end
    local s = ffi.string(p)
    ffi.C.free(p)
    if s == '' then
        return nil
    end
    if s:sub(-1) ~= '/' then
        s = s .. '/'
    end
    return s
end

return M
