local base = require('imgui.Widget')
---@class xe.ToolBar:im.Widget
local M = class('xe.ToolBar', base)
local im = imgui
local wi = base

function M:ctor()
    base.ctor(self)
    ---@type table<string,im.ImageButton[]>
    self._btns = {}
    self._states = {}

    local colors = { [im.Col.Button] = function()
        local col = im.getStyleColorVec4(im.Col.Button)
        col.w = 0.1
        return col
    end }
    local vars = { [im.StyleVar.ItemSpacing] = im.vec2(2, 2) }
    local style = wi.style(colors, vars)
    self:addChild(style)

    local toolbar_data = require('xe.tools.toolbar_data')
    local scale = lstg.WindowHelper:getInstance():getDpiScale()
    local img_size = cc.size(24 * scale, 24 * scale)
    for i, v in ipairs(toolbar_data) do
        local sp ---@type cc.Sprite
        local path = 'xe/tool/' .. v.bitmap
        if string.fileext(v.bitmap) == 'svg' then
            sp = cc.Sprite:createWithSVGFile(path, img_size)
        else
            sp = cc.Sprite:create(path)
            sp:setScale(scale)
        end
        assert(sp)

        local fname = v.name:sub(1, 1):lower() .. v.name:sub(2)
        local cb = function()
            print(string.format('[TOOL] %s', fname))
            require('xe.ToolMgr')[fname]()
        end

        local btn, btn_disable = self:_addContent(sp, cb)
        style:addChild(btn):addChild(btn_disable)
        if i < #toolbar_data then
            style:addChild(im.sameLine)
        end

        local tip = i18n(v.tooltip or v.name)
        if tip then
            style:addChild(function()
                if im.isItemHovered() then
                    im.setTooltip(tip)
                end
            end)
        end

        self._btns[fname] = { btn, btn_disable }
        self._states[fname] = true
    end

    self:addChild(function()
        self:_applyEnable()
    end)

    self:onClose()
end
---@param sp cc.Sprite
function M:_addContent(sp, cb)
    local btn, btn_disable = require('xe.util').createButton(sp, 4)
    btn:setOnClick(cb)
    return btn, btn_disable
end

function M:onOpen()
    self:enableAll()
    self:disable('debugSC')
    self:disable('debugStage')
    self:disable('insertChild')
end

function M:onClose()
    self:disableAll()
    self:enable('new')
    self:enable('open')
    self:enable('setting')
end

function M:disable(name)
    if self:_checkName(name) then
        self._states[name] = false
    end
end
function M:disableAll()
    local states = {}
    for k, v in pairs(self._states) do
        states[k] = false
    end
    self._states = states
end
function M:enable(name)
    if self:_checkName(name) then
        self._states[name] = true
    end
end
function M:enableAll()
    local states = {}
    for k, v in pairs(self._states) do
        states[k] = true
    end
    self._states = states
end
function M:setEnabled(name, b)
    if self:_checkName(name) then
        self._states[name] = b and true or false
    end
end
function M:isEnabled(name)
    if self:_checkName(name) then
        return self._states[name]
    end
end

function M:_checkName(name)
    local v = self._btns[name]
    if not v then
        print('invalid tool name:', name)
    end
    return v and true or false
end
function M:_applyEnable()
    local tree = require('xe.main').getTree()
    local pos = tree:getInsertPos()
    self:setEnabled('insertAfter', pos ~= 'after')
    self:setEnabled('insertChild', pos ~= 'child')
    self:setEnabled('insertBefore', pos ~= 'before')
    for k, v in pairs(self._btns) do
        local b = self._states[k]
        v[1]:setVisible(b)
        v[2]:setVisible(not b)
    end
end

return M
