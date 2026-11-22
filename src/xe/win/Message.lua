local base = require('imgui.Widget')
---@class xe.Message:im.Widget
local M = class('xe.Message', base)
local im = imgui
local wi = base

function M:ctor(title, msg)
    base.ctor(self)
    self._title = title or 'Info'
    self._msg = msg or 'Choose one operation'

    local frame = wi._begin_end_wrapper(function()
        local sz = im.vec2(-1, -im.getFrameHeightWithSpacing())
        return im.beginChildFrame(im.getID('xe.win.ask'), sz)
    end, im.endChildFrame)
    self:addChild(frame)
    self._frame = frame

    frame:addChild(function()
        im.textWrapped(self._msg)
    end)

    self._hdl = {}
end

function M:addHandler(name, f)
    if #self._hdl > 0 then
        self:addChild(im.sameLine)
    end
    local btn = wi.Button(name, function()
        if f then
            f()
        end
        self._rm = true
    end)
    self:addChild(btn)
    table.insert(self._hdl, btn)
end

function M:_handler()
    im.setNextWindowSize(im.vec2(300, 200), im.Cond.Once)
    im.openPopup(self._title)
    if im.beginPopupModal(self._title) then
        wi._handler(self)
        im.endPopup()
    end
    if self._rm then
        self:removeSelf()
    end
end

return M
