--
local M = io

local is_win = jit.os == 'Windows'
local fu = is_win and cc.FileUtils:getInstance()

---
---@param path string
---@return file
function M.open_u8(path, ...)
    if is_win then
        path = fu:getSuitableFOpen(path)
    end
    return io.open(path, ...)
end

return M
