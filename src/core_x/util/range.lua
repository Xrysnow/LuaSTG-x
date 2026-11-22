--

---@class x.range
local M = {}

--- Returns a iterator of range [start, stop) or [0, start)
---@param start number
---@param stop number
---@param step number @ will be 1 if ommited
---@return function
function M.range(start, stop, step)
    step = step or 1
    if step > 0 then
        if not stop then
            start, stop = 0, start
        end
    elseif step == 0 then
        error("range() step argument must not be zero")
    end

    local now = start
    local f
    if step > 0 then
        f = function()
            if now >= stop then
                return nil
            end
            now = now + step
            return now
        end
    else
        f = function()
            if now <= stop then
                return nil
            end
            now = now + step
            return now
        end
    end
    return f
end

return M
