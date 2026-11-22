local base = require('imgui.Widget')

---@class im.Console:im.Widget
local M = class('im.Console', base)
local im = imgui

function M:ctor(...)
    base.ctor(self, ...)
    self.InputBuf = ''
    self.Items = {}
    self.max_item_count = 1000
    self.Commands = {}
    self.History = {}
    -- -1: new line, 0..History.Size-1 browsing history.
    self.HistoryPos = -1
    self.AutoScroll = true
    self.ScrollToBottom = true
    -- nil to use default color (change with theme)
    self.style = {
        keyword      = im.c3b(86, 154, 214),
        identifier   = nil,
        operator     = nil,
        -- builtin function
        ['function'] = im.c3b(0, 139, 139),
        string       = im.c3b(214, 157, 133),
        comment      = im.c3b(87, 166, 74),
        constant     = im.c3b(0, 139, 139),
        library      = im.c3b(0, 139, 139),
        number       = im.c3b(181, 206, 168),
        label        = im.c3b(86, 154, 214),

        global_var   = im.c3b(0, 139, 139),
        global_func  = im.c3b(72, 61, 255),
        member_var   = im.c3b(204, 84, 46),
        member_func  = nil,
        static_func  = im.c3b(194, 194, 90),
        self         = im.c3b(86, 154, 214),
        bool         = im.c3b(108, 218, 218),
        ['nil']      = im.c3b(108, 218, 218),

        error        = im.c3b(255, 0, 0),
    }
    self:addChild(function()
        self:_render()
    end)

    -- print in console
    self._print = function(...)
        local args = { ... }
        local narg = select('#', ...)
        for i = 1, narg do
            args[i] = tostring(args[i])
        end
        self:log(table.concat(args, '\t'))
    end
    self._env = setmetatable(
            {},
            { __index = _G })
    self._fenv = setmetatable(
            { print = self._print },
            { __index = self._env, __newindex = self._env })
end

function M:clear()
    self.Items = {}
    self.ScrollToBottom = true
end

function M:log(str, highlight, hinter)
    str = tostring(str)
    if type(highlight) == 'table' then
        str = { str, color = highlight }
    elseif highlight then
        local tokens = require('util.ReplParser')(str):getSegments()
        tokens.string = str
        tokens.hinter = hinter
        str = tokens
    end
    table.insert(self.Items, str)
    if #self.Items > self.max_item_count then
        table.remove(self.Items, 1)
    end
    if self.AutoScroll then
        self.ScrollToBottom = true
    end
end

function M:logArray(t, n)
    for i = 1, n do
        t[i] = tostring(t[i])
    end
    t = table.concat(t, ',\t')
    self:log(t)
end

function M:getContent()
    local t = {}
    for i, v in ipairs(self.Items) do
        local typ = type(v)
        if typ == 'string' then
            table.insert(t, v)
        elseif typ == 'table' then
            if v.color then
                table.insert(t, v[1])
            else
                table.insert(t, v.string)
            end
        end
    end
    return table.concat(t, '\n')
end

local function get_ret(...)
    return select('#', ...), { ... }
end

function M:exec(str)
    self:log(str, true, true)
    -- treat as value
    local ret, msg = loadstring('return ' .. str)
    local n, result
    if not ret then
        -- treat as statement
        ret, msg = loadstring(str)
        if not ret then
            -- error
            self:log(msg, self.style.error)
        end
    end
    if ret then
        setfenv(ret, self._fenv)
        n, result = get_ret(pcall(ret))
    end
    if result then
        if not result[1] then
            -- error
            self:log(result[2], self.style.error)
        elseif n > 1 then
            table.remove(result, 1)
            self:logArray(result, n - 1)
        end
    end
    self.InputBuf = ''
    self.HistoryPos = -1
    self.ScrollToBottom = true
end

function M:_renderItem(idx)
    local item = self.Items[idx]
    if not item then
        return
    end
    local t = type(item)
    if t == 'string' then
        imgui.textUnformatted(item)
    elseif t == 'table' then
        if item.color then
            imgui.textColored(im.color(item.color), item[1])
        else
            if item.hinter then
                im.textUnformatted('> ')
                im.sameLine()
            end
            local s = im.getStyle().ItemSpacing
            im.getStyle().ItemSpacing = cc.p(0, s.y)

            for i, seg in ipairs(item) do
                local type, str = seg[1], seg[2]
                local color = self.style[type]
                for k, v in pairs(self.style) do
                    if seg['is_' .. k] then
                        color = v
                        break
                    end
                end
                if color then
                    im.pushStyleColor(im.Col.Text, color)
                end
                im.textUnformatted(str)
                if color then
                    im.popStyleColor()
                end
                if i < #item then
                    im.sameLine()
                end
            end
            im.getStyle().ItemSpacing = s
        end
    end
end

function M:_render()
    local ret
    ret = im.button('Clear')
    if ret then
        self:clear()
    end
    im.sameLine()
    ret = im.button('Copy')
    if ret then
        im.setClipboardText(self:getContent())
    end

    im.separator()
    local hfooter = im.getFrameHeightWithSpacing() + im.getStyle().ItemSpacing.y

    im.beginChild("ScrollingRegion", cc.p(0, -hfooter), false,
                  im.ImGuiWindowFlags.HorizontalScrollbar)

    im.pushStyleVar(im.ImGuiStyleVar.ItemSpacing, cc.p(4, 1))

    for i = 1, #self.Items do
        self:_renderItem(i)
    end

    if self.ScrollToBottom then
        im.setScrollHereY(1)
    end
    self.ScrollToBottom = false

    im.popStyleVar()

    im.endChild()
    im.separator()

    local reclaim_focus = false
    ret, self.InputBuf = im.inputText('Input', self.InputBuf,
                                      im.ImGuiInputTextFlags.EnterReturnsTrue)
    if ret then
        local str = string.trim(self.InputBuf)
        if str ~= '' then
            self:exec(str)
        end
        reclaim_focus = true
    end
    im.setItemDefaultFocus()
    if reclaim_focus then
        im.setKeyboardFocusHere(-1)
    end
end

function M.createWindow(...)
    local ret = require('imgui.widgets.Window')(...)
    ret:addChild(M())
    return ret
end

return M
