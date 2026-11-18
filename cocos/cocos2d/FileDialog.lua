local dialog = cc.FileDialog
local filters = {}

-- Each call returns a new filter so applications can customize its label or types.
function filters.image()
    return {
        label = "Images",
        extensions = { "png", "jpg", "jpeg", "gif", "webp", "bmp" },
        mimeTypes = { "image/png", "image/jpeg", "image/gif", "image/webp", "image/bmp" },
    }
end

function filters.audio()
    return {
        label = "Audio",
        extensions = { "wav", "mp3", "ogg", "flac", "m4a" },
        mimeTypes = { "audio/wav", "audio/x-wav", "audio/mpeg", "audio/ogg", "audio/flac", "audio/mp4" },
    }
end

function filters.video()
    return {
        label = "Video",
        extensions = { "mp4", "mov", "webm" },
        mimeTypes = { "video/mp4", "video/quicktime", "video/webm" },
    }
end

function filters.font()
    return {
        label = "Fonts",
        extensions = { "ttf", "otf", "ttc" },
        mimeTypes = { "font/ttf", "font/otf", "font/collection" },
    }
end

function filters.text()
    return { label = "Text files", extensions = { "txt" }, mimeTypes = { "text/plain" },
        appleTypeIdentifiers = { "public.plain-text" } }
end

function filters.json()
    return { label = "JSON", extensions = { "json" }, mimeTypes = { "application/json" },
        appleTypeIdentifiers = { "public.json" } }
end

function filters.lua()
    -- Some providers assign Lua scripts a generic text or binary MIME type.
    return { label = "Lua scripts", extensions = { "lua" } }
end

function filters.zip()
    return { label = "ZIP archives", extensions = { "zip" }, mimeTypes = { "application/zip" },
        appleTypeIdentifiers = { "public.zip-archive" } }
end

dialog.filters = filters

local function open(multiple, filter, callback)
    if type(filter) == "function" and callback == nil then
        callback, filter = filter, nil
    end
    return dialog.openFiles({
        allowMultiple = multiple,
        allowAllFiles = filter == nil,
        filters = { filter },
    }, callback)
end

function dialog.openFile(filter, callback)
    return open(false, filter, callback)
end

function dialog.openMultiple(filter, callback)
    return open(true, filter, callback)
end

function dialog.openFolder(callback)
    return dialog.pickFolder({}, callback)
end

function dialog.exportAs(source, suggestedName, callback)
    return dialog.exportFile({ suggestedName = suggestedName }, source, callback)
end

return dialog
