---@class ui.DropDownList:cc.Layer
local M = class("DropDownList", cc.Layer)

---@param button ccui.Button
function M:ctor(button, cell_h, cell_w_min, cell_w_max)
    self:setAnchorPoint(cc.p(0, 1))
    self:setPosition(button:getPosition())
    self:addChild(button)
    button:setAnchorPoint(cc.p(0, 0))
    button:setPosition(cc.p(0, 0))
    ---@type cc.Label
    self.label = button:getTitleLabel()
    local cfg = self.label:getTTFConfig()
    self.fontsize = cfg.fontSize
    assert(self.fontsize and self.fontsize > 0)

    cell_w_min = cell_w_min + 5
    cell_w_max = cell_w_max + 5
    self.cellsize = { h = cell_h, wmin = cell_w_min, wmax = cell_w_max }
    self.w = cell_w_min

    ---@type button.toggle
    self.button = button
    self.button:addClickEvent(function()
        --Print('click')
        if self.isShow then
            self:hide()
        else
            self:show()
        end
    end)
    ---@type cc.Label[]
    self.cells = {}
    ---@type cc.Label[]
    self.namedcells = {}

    local list = ccui.Layout:create()
    self:add(list)
    list:setLayoutType(ccui.LayoutType.VERTICAL)
    --list:setBackGroundColorType(ccui.LayoutBackGroundColorType.solid)
    --list:setBackGroundColor(cc.c3b(242, 242, 100))

    list:setBackGroundImage('res/editor/menu1.png')
    list:setBackGroundImageScale9Enabled(true)
    list:setBackGroundImageCapInsets(cc.rect(6, 6, 20, 20))

    local param = ccui.LinearLayoutParameter:create()
    param:setGravity(ccui.LinearGravity.centerHorizontal)
    self.param = param

    list:setLayoutParameter(param)
    list:setAnchorPoint(cc.p(0, 1))
    list:setPosition(cc.p(0, 0))
    list:setGlobalZOrder(1)

    self.list = list
    self._onShowTask = {}
    self._onHideTask = {}

    self:enableNodeEvents()
    self:hide()
end

function M:onEnter()
    --require('editor.main').addMaskClickTask(self, function()
    --    self:hide()
    --    self.button:setClicked(false)
    --end)
end

function M:onExit()
    --require('editor.main').removeMaskClickTask(self)
end

local _btn_tag = 1

function M:_createCell(text, cb)
    local param = ccui.LinearLayoutParameter:create()
    param:setGravity(ccui.LinearGravity.left)
    param:setMargin({ left = 1, top = 1, right = 0, bottom = 0 })

    local la = ccui.Layout:create()
    la:setLayoutType(ccui.LayoutType.VERTICAL)
    la:setContentSize(cc.size(self.cellsize.wmin - 7, self.cellsize.h))
    la:setLayoutParameter(param)

    --la:setBackGroundColorType(1)
    --la:setBackGroundColor(cc.c3b(0, 0, 255))

    local btn = ccui.Button:create(
            'res/editor/base_button_normal.png',
            'res/editor/base_button_pressed.png',
            'res/editor/base_button_disabled.png', 0)
    btn:setScale9Enabled(true)
    btn:setContentSize(cc.size(self.cellsize.wmin - 13, self.cellsize.h))
    btn:setSwallowTouches(true)
    if cb then
        btn:addClickEventListener(cb)
    end
    btn:setLayoutParameter(self.param)

    btn:setTitleFontName('Arial')
    btn:setTitleText(text)
    btn:setTitleColor(cc.c3b(0, 0, 0))
    btn:setTitleAlignment(cc.TEXT_ALIGNMENT_LEFT)
    btn:setTitleFontSize(self.cellsize.h * 0.6)
    --Print(tostring(self.cellsize.h * 0.6))
    --btn:setColor(cc.c3b(127, 0, 0))

    local lb = btn:getTitleRenderer()
    lb:setAnchorPoint(cc.p(0, 0.5))
    lb:setPosition(cc.p(5, self.cellsize.h / 2))

    la:addChild(btn, 1, _btn_tag)
    la:requestDoLayout()

    --Print(stringify(la:getContentSize()))
    return la
end

function M:addCell(text, cb)
    local cell = self:_createCell(text, cb)
    table.insert(self.cells, cell)
    self.namedcells[text] = cell
    self.list:setContentSize(cc.size(self.w, #self.cells * (self.cellsize.h + 1) + 6))
    self.list:addChild(cell)
    self.list:requestDoLayout()
    --cell:setGlobalZOrder(1)
end

---@return ccui.Button
function M:getCell(idx)
    local btn
    if type(idx) == 'number' then
        if idx < 1 or idx > #self.cells then
            error('wrong index')
        end
        btn = self.cells[idx]:getChildByTag(_btn_tag)
    else
        btn = self.namedcells[idx]
    end
    assert(btn)
    return btn
end

function M:setCallback(idx, cb)
    self:getCell(idx):addClickEventListener(cb)
end

function M:getCurrentString()
    return self.button:getTitleRenderer():getString()
end

function M:getCurrentIndex()
    return self._cur
end

function M:show()
    self.isShow = true
    self.list:setVisible(true)
    for i, v in ipairs(self._onShowTask) do
        v()
    end
end

function M:hide()
    self.isShow = false
    self.list:setVisible(false)
    for i, v in ipairs(self._onHideTask) do
        v()
    end
end

function M:addShowTask(f)
    table.insert(self._onShowTask, f)
end

function M:addHideTask(f)
    table.insert(self._onHideTask, f)
end

function M.createBase(w, h, contents, defaultIdx)
    local btn = require('cc.ui.ButtonToggle'):createBase(
            cc.size(w, h), contents[defaultIdx or 1] or '')
    btn:setTitleFontName('Arial'):setTitleFontSize(h * 0.6)
    btn:setTitleColor(cc.c3b(0, 0, 0))
    btn:setTitleAlignment(cc.TEXT_ALIGNMENT_LEFT)
    local lb = btn:getTitleRenderer()
    lb:setAnchorPoint(cc.p(0, 0.5))
    lb:setPosition(cc.p(9, h / 2))
    local hinter = cc.Sprite:create('res/editor/dropdown_hinter.png')
    hinter:addTo(btn):setPosition(cc.p(w - 8, h / 2))
    ---@type ui.DropDownList
    local ret = M:create(btn, h, w, w)
    ret._cur = defaultIdx or 1
    local titles = {}
    for i, v in ipairs(contents) do
        --assert(type(v) == 'string')
        titles[i] = tostring(v)
        ret:addCell(v, function()
            ret.button:getTitleRenderer():setString(titles[i])
            ret:hide()
            ret._cur = i
        end)
    end
    ret:addShowTask(function()
        hinter:setScaleY(-1)
    end)
    ret:addHideTask(function()
        hinter:setScaleY(1)
    end)
    return ret
end

return M
