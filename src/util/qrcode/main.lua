--
local M = {}
local qr = require('util.qrcode.qrencode')

---@param str string
---@param ec_level number
function M.encode(str, ec_level)
    local ok, ret = qr.qrcode(str, ec_level)
    if ok then
        return ret
    else
        return nil, ret
    end
end

---@param str string
---@param ec_level number
---@param padding number number of padding rows/columns around QR code
---@param padding_char string
---@param white_pixel string
---@param black_pixel string
function M.string(str, ec_level, padding, padding_char, white_pixel, black_pixel)
    local ok, tab = qr.qrcode(str, ec_level)
    if not ok then
        return nil, tab
    end
    padding = padding or 1
    black_pixel = black_pixel or "■"
    white_pixel = white_pixel or "  "
    padding_char = padding_char or white_pixel
    local padding_string
    local str_tab = {}
    padding_string = string.rep(padding_char, padding)
    for i = 1, #tab + 2 * padding do
        str_tab[i] = padding_string
    end
    for x = 1, #tab do
        for y = 1, #tab do
            if tab[x][y] > 0 then
                str_tab[y + padding] = str_tab[y + padding] .. black_pixel
            elseif tab[x][y] < 0 then
                str_tab[y + padding] = str_tab[y + padding] .. white_pixel
            else
                str_tab[y + padding] = str_tab[y + padding] .. " X"
            end
        end
    end
    padding_string = string.rep(padding_char, #tab)
    for i = 1, padding do
        str_tab[i] = str_tab[i] .. padding_string
        str_tab[#tab + padding + i] = str_tab[#tab + padding + i] .. padding_string
    end
    padding_string = string.rep(padding_char, padding)
    for i = 1, #tab + 2 * padding do
        str_tab[i] = str_tab[i] .. padding_string
    end
    return str_tab
end

---@param str string
---@param ec_level number
---@return cc.Sprite
function M.sprite(str, ec_level)
    local ok, ret = qr.qrcode(str, ec_level)
    if not ok then
        return nil
    end
    local data = ''
    local size = #ret
    for col = 1, size do
        for row = 1, size do
            if ret[row][col] > 0 then
                data = data .. '\x00\x00\x00\xff'
            else
                data = data .. '\xff\xff\xff\xff'
            end
        end
    end
    assert(#data / 4 == size * size)
    local buf = lstg.Buffer:createFromString(data)
    -- Restricted Ref construction: research/lua-binding-convergence_2026-11-01/core/callers.md
    local img = cc.Image()
    if not img:initWithRawData(buf, size, size, 4) then
        return nil
    end
    -- Restricted Ref construction: research/lua-binding-convergence_2026-11-01/core/callers.md
    local tex = cc.Texture2D()
    if not tex:initWithImage(img) then
        return nil
    end
    tex:setAliasTexParameters()
    return cc.Sprite:createWithTexture(tex)
end

return M
