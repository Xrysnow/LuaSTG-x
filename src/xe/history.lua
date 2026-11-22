--
local M = {}
local stack = {}
local cur = 0
local _start = false

function M.clear()
    stack = {}
end

function M.startTracing()
    _start = true
end

function M.stopTracing()
    _start = false
end

function M.add(op)
    if _start then
        assert(0 <= cur and cur <= #stack)
        if cur ~= #stack then
            for i = cur + 1, #stack do
                stack[i] = nil
            end
        end
        table.insert(stack, op)
        cur = #stack
    end
end

function M.undo(f)
    if #stack == 0 then
        return
    end
    cur = cur - 1
    if f then
        return f(stack[cur])
    else
        return stack[cur]
    end
end

function M.redo(f)
    if cur == #stack then
        return
    end
    cur = cur + 1
    if f then
        return f(stack[cur])
    else
        return stack[cur]
    end
end

return M
