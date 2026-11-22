local base = require('imgui.Widget')

---@class im.LogWindow:im.Widget
local M = class('im.LogWindow', base)
local im = imgui

local function start_with(s, pattern)
    return s:sub(1, #pattern) == pattern
end

function M:ctor(...)
    base.ctor(self, ...)
    self:addChild(function()
        self:_toolbar()
    end)
    self._sub = require('imgui.Widget').ChildWindow(
            'c1', cc.size(0, 0), true, imgui.WindowFlags.HorizontalScrollbar)
    self:addChild(self._sub)
    -- we don't know the scroll of window at first frame
    -- so we have to wait one frame
    self._sub:setAutoScrollY(true)
    local ii = 0
    self._sub:addChild(function()
        self:_render()
        if ii >= 1 then
            self._sub:setAutoScrollY(false)
        else
            ii = ii + 1
        end
    end)
    local map = {
        info    = '[INFO] ',
        warning = '[WARN] ',
        error   = '[ERRO] ',
        log     = '[LOG] ',
    }
    SetOnWriteLog(function(str)
        local type
        for k, v in pairs(map) do
            if start_with(str, v) then
                str = str:sub(#v + 1, -1)
                type = k
                break
            end
        end
        if str:sub(-1, -1) == '\n' then
            str = str:sub(1, -2)
        end
        self:addString(str, type)
    end)
    lstg._onPrint = function(...)
        local args = { ... }
        local narg = select('#', ...)
        for i = 1, narg do
            args[i] = tostring(args[i])
        end
        local str = string.format('%s', table.concat(args, '\t'))
        self:addString(str, 'print')
    end
    -- nil to use default color (change with theme)
    self.style = {
        info    = nil,
        warning = imgui.c3b(194, 194, 90),
        error   = imgui.c3b(255, 0, 0),
        log     = imgui.c3b(204, 84, 46),
        normal  = nil,
        print   = imgui.c3b(0, 139, 139),
    }
    self.filters = {
        info    = true,
        warning = true,
        error   = true,
        log     = true,
        normal  = true,
        print   = true,
    }
    self.type_header = {
        info    = '[I] ',
        warning = '[W] ',
        error   = '[E] ',
        log     = '[L] ',
        normal  = '    ',
        print   = '[P] ',
    }
    self.items = {}
    self.max_item_count = 1000
    local f = cc.FileUtils:getInstance():getStringFromFile(lstg.LogSystem:getInstance():getPath())
    if #f > 0 then
        local t = string.split(f, '\n')
        for i, str in ipairs(t) do
            local type
            for k, v in pairs(map) do
                if start_with(str, v) then
                    str = str:sub(#v + 1, -1)
                    type = k
                    break
                end
            end
            self:addString(str, type)
        end
    end
end

function M:addString(str, type)
    if self._inAdd then
        return
    end
    self._inAdd = true
    type = type or 'normal'
    local color = self.style[type]
    table.insert(self.items, {
        string = str,
        color  = color,
        type   = type,
        header = self.type_header[type] or ''
    })
    if #self.items > self.max_item_count then
        table.remove(self.items, 1)
    end
    --local scr = self._sub:getScrollMaxY()
    --self._sub:setAutoScrollY(scr - self._sub:getScrollY() < 30)
    self._sub:setAutoScrollY(true)
    self._inAdd = false
end

function M:clear()
    self.items = {}
end

function M:getContent()
    local t = {}
    for i, v in ipairs(self.items) do
        if self.filters[v.type] then
            local header = self.type_header[v.type] or ''
            table.insert(t, header .. v.string)
        end
    end
    return table.concat(t, '\n')
end

function M:_toolbar()
    if imgui.button('Clear') then
        self:clear()
    end
    imgui.sameLine()
    if imgui.button('Copy') then
        imgui.setClipboardText(self:getContent())
    end
    imgui.sameLine()
    if imgui.arrowButton('##', imgui.Dir.Down) then
        self._sub:setScrollY(self._sub:getScrollMaxY())
    end
    imgui.separator()
end

function M:_render()
    local s = im.getStyle().ItemSpacing
    im.getStyle().ItemSpacing = cc.p(0, s.y)
    for i, item in ipairs(self.items) do
        if item.color then
            im.pushStyleColor(imgui.Col.Text, item.color)
        end
        im.textUnformatted(item.header)
        if item.color then
            im.popStyleColor()
        end
        im.sameLine()
        im.textUnformatted(item.string)
    end
    im.getStyle().ItemSpacing = s
end

function M.createWindow(...)
    local ret = require('imgui.widgets.Window')(...)
    ret:addChild(M())
    return ret
end

return M
