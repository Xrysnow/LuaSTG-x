---@class im.Widget:cc.Node
local M = class('imgui.Widget', cc.Node)
local imgui = imgui
local pairs = pairs
local type = type

function M:ctor(...)
    self._param = { ... }
    self._ret = {}
end

function M:_handler()
    local c = self:getChildren()
    for _, v in ipairs(c) do
        if v.handler then
            v:handler()
        end
    end
end

function M:handler()
    if self:isVisible() then
        self:_handler()
    end
end

function M:setParam(idx, value)
    self._param[idx] = value
    return self
end

function M:getParam(idx)
    if idx then
        return self._param[idx]
    else
        return self._param
    end
end

function M:getReturn(idx)
    if idx then
        return self._ret and self._ret[idx]
    else
        return self._ret
    end
end

function M:setHandler(f)
    self._handler = function()
        f()
    end
end

function M:setContentSize(size)
    cc.Node.setContentSize(self, size)
    return self
end

function M:getContentSize()
    return cc.Node.getContentSize(self)
end

function M:addChild(child, localZOrder, name)
    if type(child) == 'function' then
        local c = M()
        c:setHandler(child)
        child = c
    end
    assert(type(name) ~= 'string', 'got ' .. tostring(name))
    cc.Node.addChild(unpack({ self, child, localZOrder, name }))
    return self
end

function M:addChildChain(...)
    local arg = { ... }
    if #arg == 0 then
        return self
    end
    self:addChild(arg[1])
    for i = 1, #arg - 1 do
        arg[i]:addChild(arg[i + 1])
    end
    return self
end

function M:addChildren(...)
    for _, v in ipairs({ ... }) do
        self:addChild(v)
    end
    return self
end

--------------------------------------------------
-- widgets
--------------------------------------------------

---@return im.Widget
local function begin_end_wrapper(begin, end_, args)
    local ret = M(unpack(args or {}))
    ret:setHandler(function()
        if begin(unpack(ret._param)) then
            M._handler(ret)
            end_()
        end
    end)
    return ret
end
M._begin_end_wrapper = begin_end_wrapper

---@return im.Widget
function M.Widget(handler)
    local ret = M()
    if handler then
        ret:setHandler(handler)
    end
    return ret
end

---@return im.Bullet
function M.Bullet()
    return require('imgui.widgets.Bullet')()
end

---@return im.Button
function M.Button(label_or_id, onClick, size_or_dir, style)
    local ret = require('imgui.widgets.Button')(label_or_id, size_or_dir)
    if style then
        ret:setStyle(style)
    end
    if onClick then
        ret:setOnClick(onClick)
    end
    return ret
end

---@return im.Checkbox
function M.Checkbox(label, checked, onChange, onCheck)
    local ret = require('imgui.widgets.Checkbox')(label, checked)
    if onChange then
        ret:setOnChange(onChange)
    end
    if onCheck then
        ret:setOnCheck(onCheck)
    end
    return ret
end

---@return im.ChildWindow
function M.ChildWindow(id, size, border, flags)
    return require('imgui.widgets.ChildWindow')(id, size, border, flags)
end

---@return im.CollapsingHeader
function M.CollapsingHeader(label, flags, closable)
    local ret = require('imgui.widgets.CollapsingHeader')(label, flags)
    if closable then
        ret:setClosable(closable)
    end
    return ret
end

---@return im.Combo
function M.Combo(label, items, current, flags)
    local ret = require('imgui.widgets.Combo')(label, '', flags)
    if items then
        ret:setItems(items)
    end
    if current then
        ret:setCurrent(current)
    end
    return ret
end

---@return im.InputText
function M.InputText(label, string, onChange, width)
    local ret = require('imgui.widgets.InputText')(label, string)
    if onChange then
        ret:setOnChange(onChange)
    end
    if width then
        ret:setWidth(width)
    end
    return ret
end

function M.MenuBar()
    return begin_end_wrapper(imgui.beginMenuBar, imgui.endMenuBar)
end

function M.CCNode(node, tint_color, border_color)
    local ret = M()
    node:addTo(ret):setVisible(false)
    ret:setHandler(function()
        imgui.ccNode(unpack { node, tint_color, border_color })
    end)
    return ret
end

function M.CCNodeButton(node, frame_padding, bg_color, tint_color)
    local ret = M()
    node:addTo(ret):setVisible(false)
    ret:setHandler(function()
        imgui.ccNodeButton(unpack { node, frame_padding, bg_color, tint_color })
    end)
    return ret
end

---@return im.ProgressBar
function M.ProgressBar(fraction, size, overlay)
    return require('imgui.widgets.ProgressBar')(fraction, size, overlay)
end

---@return im.RadioButton
function M.RadioButton(label, checked, checker, onCheck)
    local ret = require('imgui.widgets.RadioButton')(label, checked)
    if checker then
        ret:setActiveChecker(checker)
    end
    if onCheck then
        ret:setOnCheck(onCheck)
    end
    return ret
end

---@return im.RadioButtonGroup
function M.RadioButtonGroup(labels, onChange, initIndex, sameLine)
    local ret = require('imgui.widgets.RadioButtonGroup')(labels, initIndex, sameLine)
    if onChange then
        ret:setOnChange(onChange)
    end
    return ret
end

---@return im.Selectable
function M.Selectable(label, selected, flags, size, onSelect)
    local ret = require('imgui.widgets.Selectable')(label, selected, flags, size)
    if onSelect then
        ret:setOnSelect(onSelect)
    end
    return ret
end

---@return im.SelectableGroup
function M.SelectableGroup(labels, current, flags, sizes, onSelect)
    local ret = require('imgui.widgets.SelectableGroup')(labels, current, flags, sizes)
    if onSelect then
        ret:setOnSelect(onSelect)
    end
    return ret
end

---@return im.TabBar
function M.TabBar(id, flags)
    return require('imgui.widgets.TabBar')(id, flags)
end

---@return im.TabItem
function M.TabItem(name, open, flags)
    return require('imgui.widgets.TabItem')(name, open, flags)
end

---@return im.Text
function M.Text(string, color, style)
    local ret = require('imgui.widgets.Text')(string)
    if color then
        ret:setColor(color)
    end
    if style then
        ret:setStyle(style)
    end
    return ret
end

---@return im.TreeNode
function M.TreeNode(label, flags)
    return require('imgui.widgets.TreeNode')(label, flags)
end

---@return im.Window
function M.Window(name, open, flags)
    return require('imgui.widgets.Window')(name, open, flags)
end

--------------------------------------------------
-- non widgets: push pop
--------------------------------------------------

---@return im.Widget
local function push_pop_wrapper(push, pop, pushArgs)
    local ret = M(unpack(pushArgs))
    ret:setHandler(function()
        push(unpack(ret._param))
        M._handler(ret)
        pop()
    end)
    return ret
end
M._push_pop_wrapper = push_pop_wrapper

---   allow focusing using TAB/Shift-TAB, enabled by default but you can disable it for certain widgets
---@param allow_keyboard_focus boolean
function M.AllowKeyboardFocus(allow_keyboard_focus)
    return push_pop_wrapper(
            imgui.pushAllowKeyboardFocus,
            imgui.popAllowKeyboardFocus,
            { allow_keyboard_focus })
end

---   in 'repeat' mode, Button*() functions return repeated true in a typematic manner (using io.KeyRepeatDelay/io.KeyRepeatRate setting). Note that you can call IsItemActive() after any Button() to tell if the button is held in the current frame.
---@param repeat_ boolean
function M.buttonRepeat(repeat_)
    return push_pop_wrapper(
            function(value)
                imgui.pushItemFlag(imgui.ImGuiItemFlags.ImGuiItemFlags_ButtonRepeat, value)
            end,
            imgui.popItemFlag,
            { repeat_ })
end

---
---@param clip_rect_min ImVec2
---@param clip_rect_max ImVec2
---@param intersect_with_current_clip_rect boolean
function M.clipRect(clip_rect_min, clip_rect_max, intersect_with_current_clip_rect)
    return push_pop_wrapper(
            imgui.pushClipRect,
            imgui.popClipRect,
            { clip_rect_min, clip_rect_max, intersect_with_current_clip_rect })
end

--- - Read the FAQ for more details about how ID are handled in dear imgui. If you are creating widgets in a loop you most
---   likely want to push a unique identifier (e.g. object pointer, loop index) to uniquely differentiate them.
--- - The resulting ID are hashes of the entire stack.
--- - You can also use the "Label##foobar" syntax within widget label to distinguish them from each others.
--- - In this header file we use the "label"/"name" terminology to denote a string that will be displayed and used as an ID,
---   whereas "str_id" denote a string that is only used as an ID and not normally displayed.
---@param id number|string
function M.id(id)
    return push_pop_wrapper(
            imgui.pushID,
            imgui.popID,
            { id })
end

---   set width of items for common large "item+label" widgets. >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side). 0.0f = default to ~2/3 of windows width,
---@param item_width number
function M.itemWidth(item_width)
    return push_pop_wrapper(
            imgui.pushItemWidth,
            imgui.popItemWidth,
            { item_width })
end

---   word-wrapping for Text*() commands. < 0.0f: no wrapping; 0.0f: wrap to end of window (or column); > 0.0f: wrap at 'wrap_pos_x' position in window local space
---@param pos number
function M.textWrapPos(pos)
    return push_pop_wrapper(
            imgui.pushTextWrapPos,
            imgui.popTextWrapPos,
            { pos })
end

function M.styleColor(idx, color)
    return push_pop_wrapper(
            imgui.pushStyleColor,
            imgui.popStyleColor,
            { idx, color })
end

local function pushStyleColors(t)
    for k, v in pairs(t) do
        if type(v) == 'function' then
            v = v()
        end
        imgui.pushStyleColor(k, v)
    end
end
local function popStyleColors(t)
    for _, _ in pairs(t) do
        imgui.popStyleColor()
    end
end

function M.styleColors(t)
    local on_push = function()
        pushStyleColors(t)
    end
    local on_pop = function()
        popStyleColors(t)
    end
    return M.wrapper(on_push, on_pop)
end

function M.styleVar(idx, value)
    return push_pop_wrapper(
            imgui.pushStyleVar,
            imgui.popStyleVar,
            { idx, value })
end

local function pushStyleVars(t)
    for k, v in pairs(t) do
        if type(v) == 'function' then
            v = v()
        end
        imgui.pushStyleVar(k, v)
    end
end
local function popStyleVars(t)
    for _, _ in pairs(t) do
        imgui.popStyleVar()
    end
end

function M.styleVars(t)
    local on_push = function()
        pushStyleVars(t)
    end
    local on_pop = function()
        popStyleVars(t)
    end
    return M.wrapper(on_push, on_pop)
end

function M.style(colors, vars)
    colors = colors or {}
    vars = vars or {}
    local on_push = function()
        pushStyleColors(colors)
        pushStyleVars(vars)
    end
    local on_pop = function()
        popStyleColors(colors)
        popStyleVars(vars)
    end
    return M.wrapper(on_push, on_pop)
end

---@return im.Widget
function M.wrapper(onPush, onPop)
    local ret = M()
    ret:setHandler(function()
        if onPush then
            onPush()
        end
        M._handler(ret)
        if onPop then
            onPop()
        end
    end)
    return ret
end

--------------------------------------------------
-- prefabs
--------------------------------------------------

function M.propertyHeader(label, data, k, params)
    local im = imgui
    params = params or {}
    local textcolor = params.textcolor
    local p = im.getCursorScreenPos()
    local w = im.getColumnWidth(-1)
    local h = im.getFrameHeight()
    local id = tostring(data) .. label .. k
    im.invisibleButton('wi.pinput.ib.' .. id, im.p(w, h))
    local tooltip = params.tooltip
    if im.isItemHovered() then
        if type(tooltip) == 'string' then
            im.setTooltip(tooltip)
        elseif type(tooltip) == 'function' then
            tooltip()
        end
        textcolor = im.getStyleColorVec4(im.Col.ButtonHovered)
    elseif not textcolor then
        textcolor = im.getStyleColorVec4(im.Col.Text)
    end
    local pa = im.getStyle().FramePadding
    p = cc.pAdd(p, pa)
    local dl = im.getWindowDrawList()
    dl:addText(p, im.colorConvertFloat4ToU32(textcolor), label)
end

---
---@param label string
---@param data table
---@param k string
---@param params table
---@return boolean
function M.propertyInput(label, data, k, params)
    local im = imgui
    params = params or {}
    M.propertyHeader(label, data, k, params)
    im.nextColumn()
    --
    local id = tostring(data) .. label .. k
    im.setNextItemWidth(-1)
    local ptype = params.type
    local int = params.int or ptype == 'int'
    local step, step_fast = params.step, params.step_fast
    if int then
        step = step or 1
        step_fast = step_fast or 100
    else
        step = step or 0
        step_fast = step_fast or 0
    end
    local flags = params.flags or 0
    im.pushID('wi.pinput.' .. id)
    label = ''
    local val = data[k]
    local vtype = type(val)
    local ret, ret2
    if params.combo then
        local c = params.combo
        local idx = 0
        local items = {}
        for i, v in ipairs(c) do
            if val == v[1] then
                idx = i - 1
            end
            table.insert(items, v[2] or tostring(v[1]))
        end
        ret, idx = im.combo(label, idx, items)
        data[k] = c[idx + 1][1]
    elseif vtype == 'table' or ptype == 'color' or ptype == 'vec' then
        local v = {}
        local is_vec = ptype == 'vec'
        local is_color = ptype == 'color'
        if val.x then
            v = { val.x, val.y, val.z, val.w }
            is_vec = true
        elseif val.r then
            is_color = true
        end
        if is_vec and #v > 1 then
            if int then
                ret, ret2 = im.inputIntN(
                        label, v, step, step_fast, flags)
            else
                ret, ret2 = im.inputFloatN(
                        label, v, step, step_fast, params.format or '%.3f', flags)
            end
            data[k].x = ret2[1]
            data[k].y = ret2[2]
            data[k].z = ret2[3]
            data[k].w = ret2[4]
            --TODO: limit
        elseif is_color then
            local col = im.color(val)
            ret, ret2 = im.colorEdit4(
                    label, { col.x, col.y, col.z, col.w }, flags)
            data[k] = im.tocc4b(im.vec4(unpack(ret2)))
        else
            im.text('N/A')
        end
    elseif vtype == 'number' or ptype == 'number' or ptype == 'int' then
        if params.slider then
            local min = params.min or 0
            local max = params.max or 100
            if int then
                ret, data[k] = im.sliderInt(
                        label, val, min, max, params.format or '%d')
            else
                ret, data[k] = im.sliderInt(
                        label, val, min, max, params.format or '%.3f')
            end
        else
            if int then
                ret, data[k] = im.inputInt(label, val, step, step_fast, flags)
            else
                ret, data[k] = im.inputFloat(label, val, step, step_fast, params.format or '%.3f', flags)
            end
        end
        -- limit
        if params.min and data[k] < params.min then
            data[k] = params.min
        end
        if params.max and data[k] > params.max then
            data[k] = params.max
        end
    elseif vtype == 'boolean' or ptype == 'bool' then
        if params.bool_show then
            label = val and 'True' or 'False'
        end
        ret, data[k] = im.checkbox(label, val)
    elseif vtype == 'string' or ptype == 'string' then
        local hint = params.hint
        local multiline = params.multiline
        if multiline then
            ret, data[k] = im.inputTextMultiline(label, val, params.size or im.p(), flags)
        elseif hint then
            ret, data[k] = im.inputTextWithHint(label, hint, val, flags)
        else
            ret, data[k] = im.inputText(label, val, flags)
        end
        if params.on_finish and im.isItemDeactivatedAfterEdit() then
            params.on_finish()
        end
    else
        im.text('N/A')
    end
    im.popID()
    im.nextColumn()
    return ret
end

function M.propertyConst(label, value, params)
    local im = imgui
    params = params or {}
    M.propertyHeader(label, params, '', params)
    im.nextColumn()
    --
    local val = value
    local vtype = type(val)
    local fmt = params.fmt
    local int = params.int
    if not fmt then
        if vtype == 'number' then
            if int then
                fmt = '%d'
            else
                fmt = '%.3f'
            end
        elseif vtype == 'string' then
            fmt = '%s'
        elseif vtype == 'boolean' then
            fmt = val and 'true' or 'false'
        elseif vtype == 'table' then
            if val.x then
                val = { val.x, val.y, val.z, val.w }
                if int then
                    fmt = string.rep('%d', #val, ', ')
                else
                    fmt = string.rep('%.3f', #val, ', ')
                end
            elseif val.r then
                val = { val.r, val.g, val.b, val.a }
                fmt = string.rep('%d', #val, ', ')
            end
        end
    end
    fmt = fmt or 'N/A'
    local str = ''
    if vtype == 'table' then
        str = string.format(fmt, unpack(val))
    else
        str = string.format(fmt, val)
    end
    --local textcolor = im.getStyleColorVec4(im.Col.Text)
    --local p = im.getCursorScreenPos()
    --local pa = im.getStyle().FramePadding
    --p = cc.pAdd(p, pa)
    --local dl = im.getWindowDrawList()
    --dl:addText(p, im.colorConvertFloat4ToU32(textcolor), str)

    im.alignTextToFramePadding()
    --im.setCursorPosY(im.getCursorPosY() + im.getStyle().FramePadding.y)
    im.textWrapped(str)

    im.nextColumn()
end

return M
