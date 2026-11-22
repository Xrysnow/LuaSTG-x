---@class ui.ImagePicker:ccui.Layout
local M = class('editor.ColorPickerEnum', ccui.Layout)
local margin = 6
local btn_margin = 4
local caption_h = 22

function M:ctor(title, images, btn_size, nCol, init_idx, onConfirm)
    title = title or 'Select Image'
    self._onConfirm = onConfirm
    self:setBackGroundColorType(1):setBackGroundColor(cc.c3b(63, 63, 63))
    init_idx = init_idx or 1
    nCol = nCol or 4
    self._images = table.clone(images)
    if type(self._images[1]) == 'string' then
        for i = 1, #self._images do
            self._images[i] = assert(cc.Sprite:create(self._images[i]), 'invalid path: ' .. self._images[i])
        end
    end
    self._pos = {}
    local nRow = math.ceil(#images / nCol)
    local sz = cc.size(
            nCol * (btn_size.width + btn_margin) - btn_margin + margin * 2,
            nRow * (btn_size.height + btn_margin) - btn_margin + margin * 2 + caption_h
    )
    self:setContentSize(sz)
    local cap = require('cc.ui.Caption')(title, nil, sz.width, caption_h)
    cap:addTo(self):setPosition(0, sz.height - caption_h)

    for i = 1, nRow do
        for j = 1, nCol do
            local idx = (i - 1) * nCol + j
            if idx > #self._images then
                break
            end
            ---@type cc.Sprite
            local img = self._images[idx]
            assert(img)
            local btn = self:_createButton(btn_size, idx, img)
            local posx = margin + btn_size.width / 2 + (j - 1) * (btn_size.width + btn_margin)
            local posy = margin + btn_size.height / 2 + (nRow - i) * (btn_size.height + btn_margin)
            self._pos[idx] = cc.p(posx, posy)
            btn:addTo(self):setPosition(posx, posy)
        end
    end

    local hinter = require('cc.ui.sprite').Frame(
            cc.size(btn_size.width, btn_size.height),
            cc.c4b(0, 127, 255, 255), 1.5
    )
    hinter:addTo(self)
    self._hinter = hinter

    self:select(init_idx)
end

function M:select(idx)
    self._cur = idx
    self._hinter:setPosition(self._pos[idx])
end

---@return number
function M:getIndex()
    return self._cur
end

function M:_createButton(size, idx, img)
    local ret = require('cc.ui.button').Button1(size, function()
        self:select(idx)
        if self._onConfirm then
            self._onConfirm()
        end
    end)
    ret:setAnchorPoint(cc.p(0.5, 0.5))
    img:addTo(ret):setPosition(size.width / 2, size.height / 2)
    return ret
end

function M:setOnConfirm(cb)
    self._onConfirm = cb
end

return M
