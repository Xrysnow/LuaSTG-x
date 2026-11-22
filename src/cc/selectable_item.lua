local M                 = {}

local default_c3b_sel   = cc.c3b(128, 128, 64)
local default_c3b_unsel = cc.c3b(48, 48, 48)

function M.create(size, c3b_sel, c3b_unsel, label_x, label, button)
    local _w     = size.width
    local _h     = size.height
    c3b_sel      = c3b_sel or default_c3b_sel
    c3b_unsel    = c3b_unsel or default_c3b_unsel

    local widget = ccui.Widget:create()
    widget:setAnchorPoint(cc.p(0, 0))
    widget:setContentSize(size)

    local btn = button
    if not btn then
        btn = ccui.Button:create()
        btn:setScale9Enabled(true)
        btn:loadTextures(
                'creator/image/default_btn_normal.png',
                'creator/image/default_btn_pressed.png',
                'creator/image/default_btn_disabled.png'
        )
        --assert(btn:getRendererNormal())

        btn:getRendererNormal():setCapInsets(cc.rect(4, 4, 32, 32))
        btn:getRendererClicked():setCapInsets(cc.rect(4, 4, 32, 32))
        btn:getRendererDisabled():setCapInsets(cc.rect(4, 4, 32, 32))
    end

    btn:setContentSize(size)
    btn:setAnchorPoint(cc.p(0, 0))
    btn:setPosition(cc.size(_w / 2, 0))
    btn:setColor(c3b_unsel)

    local lb = label or cc.Label:createWithSystemFont('button', 'Arial', _h / 2)
    lb:setAnchorPoint(cc.p(0, 0.5))
    lb:setAlignment(cc.TEXT_ALIGNMENT_LEFT, cc.VERTICAL_TEXT_ALIGNMENT_CENTER)
    lb:setPosition(cc.p(label_x or _w / 10, _h / 2))

    widget:addChild(btn)
    widget:addChild(lb)

    widget:setPosition(cc.p(_w / 2, _h / 2))

    widget.is_selected    = false
    widget.lb             = lb
    widget.btn            = btn
    widget.lb.parent      = widget
    widget.btn.parent     = widget

    widget.callback_sel   = function() end
    widget.callback_unsel = function() end
    widget.setSelected    = function(self, b)
        if self.is_selected ~= b then
            self.is_selected = b
            if b then
                self.btn:setColor(c3b_sel)
                self:callback_sel()
            else
                self.btn:setColor(c3b_unsel)
                self:callback_unsel()
            end
        end
    end
    return widget
end

return M
