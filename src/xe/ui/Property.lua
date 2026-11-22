local base = require('imgui.widgets.Window')
---@class xe.ui.Property:im.Window
local M = class('xe.ui.Property', base)
local im = imgui
local wi = require('imgui.Widget')

function M:ctor()
    base.ctor(self, 'Property')
    self._data = {}
end

function M:clear()
    self:removeAllChildren()
end

--function M:addPropertyInput(title, data, k, param)
--    self:addChild(function()
--        im.columns(2, title, false)
--        wi.propertyInput(title, data, k, param)
--        im.columns(1)
--    end)
--end

function M:insert(node, idx)
    local count = self:getChildrenCount()
    assert(1 <= idx and idx <= count + 1)
    local tmp = {}
    for i, c in ipairs(self:getChildren()) do
        if i == idx then
            table.insert(tmp, node)
        end
        c:retain()
        table.insert(tmp, c)
    end
    if idx == count + 1 then
        table.insert(tmp, node)
    end
    self:removeAllChildren()
    node:retain()
    for i, c in ipairs(tmp) do
        self:addChild(c)
        c:release()
    end
end

function M:erase(idx)
    local count = self:getChildrenCount()
    assert(1 <= idx and idx <= count)
    local tmp = {}
    for i, c in ipairs(self:getChildren()) do
        c:retain()
        table.insert(tmp, c)
    end
    self:removeAllChildren()
    for i, c in ipairs(tmp) do
        if i ~= idx then
            self:addChild(c)
        end
        c:release()
    end
end

return M
