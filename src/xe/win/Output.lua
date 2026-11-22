local base = require('imgui.widgets.Window')
---@class xe.Output:im.Window
local M = class('xe.Output', base)
local im = imgui
local wi = require('imgui.Widget')

function M:ctor()
    base.ctor(self, 'Output')
    self._lines = {}
    self._max = 100

    local ifont = require('xe.ifont')
    local map = {
        Info    = { ifont.InfoCircle, im.color(77, 144, 255) },
        Warning = { ifont.ExclamationCircle, im.color(255, 200, 0) },
        Error   = { ifont.TimesCircle, im.color(233, 66, 66) },
    }
    map.info = map.Info
    map.warning = map.Warning
    map.warn = map.Warning
    map.error = map.Error
    map.erro = map.Error
    self._color_map = map

    local fsize = im.getFontSize()
    local btn_clear = wi.Button(ifont.TrashAlt, function()
        self:clear()
    end, im.vec2(fsize, fsize))
    self:addChild(btn_clear)
    self:addChild(function()
        if im.beginListBox('##', im.vec2(-1, -1)) then
            local lines = self._lines
            local n = #lines
            for i = 1, n do
                local str, typ = lines[i][1], lines[i][2]
                if typ then
                    if map[typ] then
                        im.textColored(map[typ][2], map[typ][1])
                        im.sameLine()
                        str = ' ' .. str
                    else
                        str = ('[%s] %s'):format(typ, str)
                    end
                end
                im.text(str)
            end
            im.endListBox()
        end
    end)
    --TODO: trace

    local map2 = { Info = 'I', Warning = 'W', Error = 'E' }
    map2.info = map2.Info
    map2.warning = map2.Warning
    map2.warn = map2.Warning
    map2.error = map2.Error
    map2.erro = map2.Error
    self._str_map = map2
end

function M:addLine(str, typ, trace)
    assert(type(str) == 'string')
    table.insert(self._lines, { str, typ, trace })
    if #self._lines > self._max then
        table.remove(self._lines, 1)
    end
    local s = ''

    if typ and typ ~= '' then
        if self._str_map[typ] then
            typ = self._str_map[typ]
        end
        s = ('%s[%s] '):format(s, typ)
    end
    s = s .. '[Editor] '
    if trace and trace ~= '' then
        s = ('%s[%s] '):format(s, trace)
    end
    s = s .. str
    print(s)
end

function M:clear()
    self._lines = {}
end

return M
