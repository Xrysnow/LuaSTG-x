--
local M = {}
local w = lstg.WindowHelper:getInstance()
local last_set = ''

function M.set(s)
    if not s then
        last_set = ''
        if plus.isDesktop() then
            w:setClipboardString('')
        end
        return
    end
    assert(type(s) == 'string')
    last_set = s
    if plus.isDesktop() then
        w:setClipboardString(s)
    end
end

function M.get()
    --TODO
    if plus.isMobile() then
        return last_set
    end
    return w:getClipboardString()
end

function M.getLastSet()
    return last_set
end

return M
