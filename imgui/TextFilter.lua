---@class im.TextFilter
local M = class('im.TextFilter')

function M:ctor()
    self._filters = {}
    self._grep = 0
    self._buf = ''
end

function M:build(s)
    local t = {}
    self._grep = 0
    for i, v in ipairs(string.split(s, ',')) do
        v = string.trim(v)
        if v ~= '' then
            table.insert(t, v)
            if v:sub(1, 1) ~= '-' or v == '-' then
                self._grep = self._grep + 1
            end
        end
    end
    self._filters = t
end

function M:filter(str)
    if #self._filters == 0 then
        return true
    end
    for i, v in ipairs(self._filters) do
        if v:sub(1, 1) == '-' then
            v = v:sub(2, -1)
            if v == '' then
                -- filter is '-'
                if str:find('-') then
                    return true
                end
            else
                if str:find(v) then
                    return false
                end
            end
        else
            if str:find(v) then
                return true
            end
        end
    end
    -- if there are only negative filters, subtract from all
    return self._grep == 0
end

function M:inputText(label, width)
    if width and width ~= 0 then
        imgui.setNextItemWidth(width)
    end
    local changed
    imgui.pushID(tostring(self))
    changed, self._buf = imgui.inputText(label, self._buf)
    imgui.popID()
    if changed then
        self:build(self._buf)
    end
    return changed
end

return M
