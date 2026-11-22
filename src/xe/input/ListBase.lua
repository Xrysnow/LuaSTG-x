local base = require('xe.input.Base')
---@class xe.input.ListBase:xe.input.Base
local M = class('xe.input.ListBase', base)
local im = imgui
local wi = require('imgui.Widget')

---@param node xe.SceneNode
function M:ctor(node, idx, type)
    base.ctor(self, node, idx, type)
    self._nameFilter = require('imgui.TextFilter')()
    self._curPage = 1
    self._perPage = 10
    self._sel = 0
end

function M:_renderList(list)
    local ret, filter_changed

    ret = self._nameFilter:inputText('Filter')
    if ret then
        filter_changed = true
    end

    if filter_changed then
        self._curPage = 1
    end

    local filtered = {}
    for i, v in ipairs(list) do
        if self._nameFilter:filter(v) then
            table.insert(filtered, v)
        end
    end
    local npage = 1
    if #filtered > 0 then
        npage = math.ceil(#filtered / self._perPage)
    end
    if self._curPage > npage then
        self._curPage = npage
    end
    local lo = (self._curPage - 1) * self._perPage + 1
    local hi = lo + self._perPage - 1

    local hh = im.getTextLineHeightWithSpacing() * self._perPage + im.getStyle().ItemSpacing.y
    im.beginChildFrame(im.getID(tostring(self)), im.vec2(0, hh))

    for i = lo, math.min(#filtered, hi) do
        local v = filtered[i]
        im.pushID(i)
        if im.selectable(v, self._sel == i,
                         im.SelectableFlags.SpanAllColumns) then
            self._sel = i
        end
        im.popID()
    end
    for i = #filtered + 1, hi do
        im.selectable('', false, im.SelectableFlags.Disabled)
    end

    im.endChildFrame()

    -- page slider
    if npage > 1 then
        im.setNextItemWidth(-1)
        ret, self._curPage = im.sliderInt('##', self._curPage, 1, npage)
    end
end

return M
