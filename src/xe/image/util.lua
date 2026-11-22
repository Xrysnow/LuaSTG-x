--
local M = {}

function M.selectImage(callback)
    return require('platform.FileDialog').openPath('png,jpg,bmp', nil, callback)
end

function M.selectImages(callback)
    local id, err = require('platform.FileDialog').openPaths('png,jpg,bmp', nil, true, function(result)
        if result.status == 'success' then callback(result.paths)
        elseif result.error then print(result.error.message) end
    end)
    if not id then print(err) end
    return id
end

function M.saveRegions(view, sourceImage, rects, basename)
    local regions = {}
    for i, r in ipairs(rects) do
        regions[i] = {r.x, r.y, r.width, r.height}
    end
    local director = cc.Director:getInstance()
    local scene = director:getRunningScene()
    local function current()
        return director:getRunningScene() == scene and view:isRunning() and view:isVisible() and view._img == sourceImage
    end
    return require('platform.FileDialog').selectDirectory(nil, function(directory)
        local function nextRegion(index)
            if not regions[index] or not current() then return end
            local name = ('%s_%d.png'):format(basename, index - 1)
            require('platform.DocumentWorkspace').prepared(name, function(path)
                local image = sourceImage.sprite:getTexture():newImage(unpack(regions[index]))
                if not image then return false end
                local ok = image:saveToFile(path, false)
                image:release()
                return ok
            end, function(path, cleanup)
                local source = cc.FileDialog.fromLocalPath(path)
                local request, err = cc.FileDialog.exportChild(directory, name, source, {}, function(result)
                    cleanup()
                    if result.status == 'ok' then nextRegion(index + 1)
                    elseif result.error then print(result.error.message) end
                end)
                if not request then cleanup(); print(err.message) end
            end)
        end
        nextRegion(1)
    end)
end

function M.create(name, path, rect)
    local im = imgui
    local wi = require('imgui.Widget')

    local sp = cc.Sprite:create(unpack({ path, rect }))
    if not sp then
        print('failed to load:', path)
        return nil
    end
    local sz = sp:getContentSize()
    local t = { name = name, sprite = sp, size = { x = sz.x, y = sz.y } }
    local viewer = require('xe.image.ImageViewer')(t)
    sp:addTo(viewer):setVisible(false)

    local id = 'Image Viewer'
    local popup
    popup = wi.Widget(function()
        im.setNextWindowSize(im.vec2(350, 350), im.Cond.Once)
        im.openPopup(id)
        if im.beginPopupModal(id) then
            wi._handler(popup)
            im.endPopup()
        end
    end)
    viewer:addTo(popup)
    popup:addTo(require('xe.main'):getInstance()._la)
end

return M
