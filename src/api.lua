--

---@~chinese 设置窗口化(true)/非窗口化(false)，请使用 `ChangeVideoMode`
---
---@~english Set the engine windowed or full-screen. `true` for windowed and `false` for full-screen. Default is `true`. Please use `ChangeVideoMode` instead.
---
---@param b boolean
---@deprecated
function SetWindowed(b)
end
lstg.SetWindowed = SetWindowed

---@~chinese 设置窗口大小。可以在运行时动态设置。
---
---@~english Set window resolution (size) if game is windowed.
---
---@param width number
---@param height number
function SetResolution(width, height)
    if type(width) ~= 'number' or type(height) ~= 'number'
            or width <= 0 or height <= 0 or width == math.huge or height == math.huge
            or width ~= width or height ~= height then
        return false, 'invalid-resolution'
    end
    local w = lstg.WindowHelper:getInstance()
    if not w or not w:supportsOperation('setSize') then
        return false, 'unsupported:setSize'
    end
    if not w:isFullscreen() then
        w:setSize(cc.size(width, height))
        return true
    end
    return false, 'fullscreen'
end
lstg.SetResolution = SetResolution

--- Change logical rendering dimensions without resizing the native window.
function SetDesignResolution(width, height)
    if type(width) ~= 'number' or type(height) ~= 'number'
            or width <= 0 or height <= 0 or width == math.huge or height == math.huge
            or width ~= width or height ~= height then
        return false, 'invalid-resolution'
    end
    local view = cc.Director:getInstance():getOpenGLView()
    if not view then return false, 'view-unavailable' end
    view:setDesignResolutionSize(width, height, cc.ResolutionPolicy.SHOW_ALL)
    return true, 'design-resolution-only'
end
lstg.SetDesignResolution = SetDesignResolution

---@~chinese 改变视频选项。若成功返回true，否则返回false
---
---@~english Change video parameters. Returns `true` if success, otherwise returns `false` and restore last parameters.
---
---@param width number
---@param height number
---@param windowed boolean
---@param vsync boolean
function ChangeVideoMode(width, height, windowed, vsync)
    if windowed and (type(width) ~= 'number' or type(height) ~= 'number'
            or width <= 0 or height <= 0 or width == math.huge or height == math.huge
            or width ~= width or height ~= height) then
        return false, 'invalid-resolution'
    end
    local w = lstg.WindowHelper:getInstance()
    if w then
        local operation = windowed and 'setSize' or 'setFullscreen'
        if not w:supportsOperation(operation) then
            return false, 'unsupported:' .. operation
        end
        if not w:supportsOperation('setVsync') then
            return false, 'unsupported:setVsync'
        end
        if windowed then
            w:setSize(cc.size(width, height))
        else
            w:setFullscreen()
            if not w:isFullscreen() then
                return false, 'display-unavailable'
            end
            --cc.Director:getInstance():getOpenGLView():setFrameSize(width, height)
        end
        w:setVsync(vsync)
        SystemLog(string.format(
                'change video mode to: (%d, %d), %s, %s',
                width, height,
                windowed and 'Windowed' or 'FullScreen',
                vsync and 'VSync On' or 'VSync Off'))
        w:moveToCenter()
        return true
    else
        return false
    end
end
lstg.ChangeVideoMode = ChangeVideoMode

---@~chinese 设置是否显示光标，默认显示
---
---@~english Set if the mouse cursor is displayed in game window. Default is `true`.
---
---@param b boolean
function SetSplash(b)
    local w = lstg.WindowHelper:getInstance()
    if w then
        w:setCursorVisible(b)
    end
end
lstg.SetSplash = SetSplash

---@~chinese 设置窗口标题。默认为"LuaSTG-x"。
---
---@~english Set the caption of window. Default is `"LuaSTG-x"`.
---
---@param title string
function SetTitle(title)
    local w = lstg.WindowHelper:getInstance()
    if w then
        w:setTitle(title)
        --Print('set title to '..title)
    end
end
lstg.SetTitle = SetTitle
