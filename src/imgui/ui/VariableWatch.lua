local base = require('imgui.Widget')

---@class im.VariableWatch:im.Widget
local M = class('im.VariableWatch', base)
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
    self._selected = -1
    -- nil to use default color (change with theme)
    self.style = {
        keyword      = imgui.c3b(86, 154, 214),
        identifier   = nil,
        operator     = nil,
        -- builtin function
        ['function'] = imgui.c3b(0, 139, 139),
        string       = imgui.c3b(214, 157, 133),
        comment      = imgui.c3b(87, 166, 74),
        constant     = imgui.c3b(0, 139, 139),
        library      = imgui.c3b(0, 139, 139),
        number       = imgui.c3b(181, 206, 168),
        label        = imgui.c3b(86, 154, 214),

        global_var   = imgui.c3b(0, 139, 139),
        global_func  = imgui.c3b(72, 61, 255),
        member_var   = imgui.c3b(204, 84, 46),
        member_func  = nil,
        static_func  = imgui.c3b(194, 194, 90),
        self         = imgui.c3b(86, 154, 214),
        bool         = imgui.c3b(108, 218, 218),
        ['nil']      = imgui.c3b(108, 218, 218),

        error        = imgui.c3b(255, 0, 0),
    }
    self:addChild(function()
        self:_render()
    end)
end

function M:clear()
    self.Items = {}
    self.ScrollToBottom = true
end

--function M:log(str, highlight, hinter)
--    str = tostring(str)
--    if type(highlight) == 'table' then
--        str = { str, color = highlight }
--    elseif highlight then
--        local tokens = require('coding.ReplParser')(str):getSenments()
--        --Print(stringify(tokens))
--        tokens.string = str
--        tokens.hinter = hinter
--        str = tokens
--    end
--    table.insert(self.Items, str)
--    if #self.Items > self.max_item_count then
--        table.remove(self.Items, 1)
--    end
--    if self.AutoScroll then
--        self.ScrollToBottom = true
--    end
--end

function M:getContent()
    local t = {}
    for i, v in ipairs(self.Items) do
        local typ = type(v)
        if typ == 'string' then
            table.insert(v)
        elseif t == 'table' then
            if item.color then
                table.insert(v[1])
            else
                table.insert(v.string)
            end
        end
    end
    return table.concat(t, '\n')
end

local function get_ret(...)
    return select('#', ...), { ... }
end

function M:addItem(str)
    local tokens = require('util.ReplParser')(str):getSegments()
    -- treat as value
    local ret, msg = loadstring('return ' .. str)
    if not ret then
        table.insert(self.Items, { string = str, tokens = tokens, error = msg })
    else
        table.insert(self.Items, { string = str, tokens = tokens, f = ret })
    end
    self.InputBuf = ''
    self.HistoryPos = -1
    self.ScrollToBottom = true
end

function M:getItemContent(idx)
    local item = self.Items[idx]
    if not item then
        return ''
    end
    local str, val = item.string, item.value_str or ''
    return string.format('%s\t%s', str, val)
end

function M:removeItem(idx)
    local item = self.Items[idx]
    if not item then
        return
    end
    table.remove(self.Items, idx)
end

function M:_renderItem(idx)
    local item = self.Items[idx]
    if not item then
        return
    end
    if im.selectable(tostring(idx),
                     self._selected == idx,
                     im.SelectableFlags.SpanAllColumns) then
        self._selected = idx
    end
    im.nextColumn()
    -- render highlighted string
    local s = im.getStyle().ItemSpacing
    im.getStyle().ItemSpacing = cc.p(0, s.y)
    for i, seg in ipairs(item.tokens) do
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
        if i < #item.tokens then
            im.sameLine()
        end
    end
    im.getStyle().ItemSpacing = s
    im.nextColumn()
    --
    local txt_err
    if item.error then
        txt_err = 'Error'
    else
        local ret = { pcall(function()
            return get_ret(item.f())
        end) }
        if ret[1] then
            -- format result
            local n, values = ret[2], ret[3]
            local t = {}
            for i = 1, n do
                local v = values[i]
                if type(v) == 'string' then
                    v = string.format('%q', v)
                else
                    v = tostring(v)
                end
                table.insert(t, v)
            end
            if n == 0 then
                t[1] = 'nil'
            end
            local str = table.concat(t, '\t')
            item.value_str = str
            im.textUnformatted(str)
            txt_err = nil
        else
            txt_err = 'Error'
        end
    end
    if txt_err then
        item.value_str = txt_err
        -- error message
        local color = self.style.error
        if color then
            im.pushStyleColor(im.Col.Text, color)
        end
        im.textUnformatted(txt_err)
        if color then
            im.popStyleColor()
        end
    end
    im.nextColumn()
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
        im.setClipboardText(self:getItemContent(self._selected))
    end
    im.sameLine()
    ret = im.button('Remove')
    if ret then
        self:removeItem(self._selected)
    end

    im.separator()
    local hfooter = im.getFrameHeightWithSpacing() + im.getStyle().ItemSpacing.y

    im.beginChild("ScrollingRegion", cc.p(0, -hfooter), false,
                  im.ImGuiWindowFlags.HorizontalScrollbar)

    im.pushStyleVar(im.ImGuiStyleVar.ItemSpacing, cc.p(4, 1))

    im.columns(3, 'columns', true)
    if not self._setCW then
        im.setColumnWidth(0, 64)
        self._setCW = true
    end
    im.separator()

    im.text("No.")
    im.nextColumn()
    im.text("Name")
    im.nextColumn()
    im.text("Value")
    im.nextColumn()
    im.separator()
    for i = 1, #self.Items do
        self:_renderItem(i)
    end
    im.columns(1)
    im.separator()

    if self.ScrollToBottom then
        im.setScrollHereY(1)
    end
    self.ScrollToBottom = false

    im.popStyleVar()

    im.endChild()
    im.separator()

    local reclaim_focus = false
    ret, self.InputBuf = im.inputText('Add Watch', self.InputBuf,
                                      im.ImGuiInputTextFlags.EnterReturnsTrue)
    if ret then
        local str = string.trim(self.InputBuf)
        if str ~= '' then
            self:addItem(str)
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
