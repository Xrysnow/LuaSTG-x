local base = require('imgui.Widget')
---@class xe.iunput.EditText:im.Widget
local M = class('xe.iunput.EditText', base)
local im = imgui
local wi = require('imgui.Widget')

function M:ctor()
    base.ctor(self)
end

function M:reset(title, node, prop_idx)
    self:removeAllChildren()
    self._title = title or 'Edit Text'
    local panel = require('xe.main').getProperty()
    self._str = panel:getValue(prop_idx) or ''
    self._strbak = self._str
    --TODO: more info in desc
    self._desc = panel:getSetter(prop_idx):getTitle()
    self:addChild(wi.Text(self._desc))

    self._btn1 = wi.Button('OK', function()
        panel:setValue(prop_idx, self:getString())
        require('xe.SceneTree').submit()
        self:setVisible(false)
    end)
    self._btn2 = wi.Button('Cancel', function()
        self:setVisible(false)
    end)
    self:addChild(self._btn1):addChild(im.sameLine):addChild(self._btn2)
end

function M:setString(str)
    self._str = str
end

function M:getString()
    return self._str
end

function M:setOnChanged(f)
    self._onchanged = f
end

function M:_handler()
    if not self._title then
        return
    end
    im.pushID(tostring(self))
    im.openPopup(self._title)
    im.setNextWindowSize(im.vec2(200, 100), im.Cond.Once)
    local ret = { im.beginPopupModal(self._title, nil) }
    im.popID()
    if ret[1] then
        im.setNextItemWidth(-1)
        local changed
        changed, self._str = im.inputText('', self._str)
        if changed and self._onchanged then
            self:_onchanged(self._str)
        end
        wi._handler(self)
        im.endPopup()
    end
end

function M.show(prop_idx, node)
    --local popup = M('Edit Text', node, prop_idx)
    --im.get():addChild(popup)
    local popup = require('xe.main'):getInstance()._edit_txt
    popup:reset('Edit Text', node, prop_idx)
    popup:setVisible(true)
    return popup
end

return M
