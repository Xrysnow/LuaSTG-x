--
local M = {}

function M.log(str, type, trace)
    --print(type, str)
    str = tostring(str)
    require('xe.main'):getInstance()._output:addLine(str, type, trace)
end

function M.clear()
    require('xe.main'):getInstance()._output:clear()
end

---@return fun
function M.getLogger(trace, type)
    if not type then
        return function(type_, msg, ...)
            M.log(msg:format(...), type_, trace)
        end
    else
        return function(msg, ...)
            M.log(msg:format(...), type, trace)
        end
    end
end

return M
