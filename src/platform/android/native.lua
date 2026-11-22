---
--- native.lua
---
--- Copyright (C) 2018-2020 Xrysnow. All rights reserved.
---

local M = {}
local luaj = require('cocos.cocos2d.luaj')
local call = luaj.callStaticMethod
local osname = lstg.GetPlatform()

local function jCall(className, methodName, args, sig)
    if osname == 'android' then
        local ok, ret = call(className, methodName, args, sig)
        if not ok then
            error(('luaj error: %s.%s%s failed (%s)'):format(
                className, methodName, sig, tostring(ret)), 2)
        else
            return ret
        end
    end
end
local andHelper = 'org/cocos/lib/CocosEngine'
local andApp = 'org/cocos/game/AppActivity'
local storageHelper = 'org/cocos/game/StorageBridge'

---@return string
function M.getAssetsPath()
    local methodName = 'getAssetsPath'
    local sig = '()Ljava/lang/String;'
    return jCall(andHelper, methodName, {}, sig)
end

---@return string
function M.getCocos2dxPackageName()
    local methodName = 'getPackageName'
    local sig = '()Ljava/lang/String;'
    return jCall(andHelper, methodName, {}, sig)
end

---vibrate
---@param duration number @duration in seconds
---@return void
function M.vibrate(duration)
    local methodName = 'vibrate'
    local sig = '(F)V'
    return jCall(andHelper, methodName, { duration }, sig)
end

---@return string
function M.getVersion()
    local methodName = 'getVersion'
    local sig = '()Ljava/lang/String;'
    return jCall(andHelper, methodName, {}, sig)
end

---@param url string
---@return boolean
function M.openURL(url)
    local methodName = 'openURL'
    local sig = '(Ljava/lang/String;)Z'
    assert(type(url) == 'string')
    return jCall(andHelper, methodName, { url }, sig)
end

---@return number
function M.getDPI()
    local methodName = 'getDPI'
    local sig = '()I'
    return jCall(andHelper, methodName, {}, sig)
end

---Internal app-specific storage; does not require storage permission.
---@return string
function M.getInternalDataPath()
    return jCall(storageHelper, 'getInternalDataPath', {}, '()Ljava/lang/String;')
end

---Optional external app-specific storage; Java falls back to internal storage
---when external storage is unavailable or not writable. This only queries a
---path and does not change the active save location.
---@return string
function M.getExternalDataPath()
    return jCall(storageHelper, 'getExternalDataPath', {}, '()Ljava/lang/String;')
end

---@param path string
---@return string|nil Canonical path within an app-specific files directory.
function M.canonicalAppOwnedDocumentSource(path)
    local canonical = jCall(storageHelper, 'canonicalAppOwnedDocumentSource', { path },
        '(Ljava/lang/String;)Ljava/lang/String;')
    return canonical ~= '' and canonical or nil
end

---@param permission string Android permission name
---@return boolean Current granted state; does not submit a permission request.
function M.hasPermission(permission)
    assert(type(permission) == 'string' and permission ~= '', 'a permission name is required')
    return jCall(storageHelper, 'hasPermission', { permission }, '(Ljava/lang/String;)Z') or false
end

---The callback receives {requestId,status,path,uri,message} on the engine thread.
---Keep the ID and cancel it when its owning scene/UI is released. Java releases
---the retained bridge function after the single terminal result.
---@param permission string
---@param callback function
---@return number|nil,string|nil
function M.requestPermissionAsync(permission, callback)
    assert(type(permission) == 'string' and permission ~= '', 'a permission name is required')
    assert(type(callback) == 'function', 'a completion callback is required')
    if osname ~= 'android' then
        return nil, 'unsupported: Android permission requests require Android'
    end
    local requestId
    local function completed(payload)
        if not callback then
            return
        end
        local finish = callback
        callback = nil
        local ok, result = pcall(require('cjson').decode, payload)
        if not ok or type(result) ~= 'table' then
            result = { requestId = requestId, status = 'error', path = '', uri = '',
                message = 'invalid permission result' }
        end
        finish(result)
    end
    local ok, value = call(storageHelper, 'requestPermission', { permission, completed },
            '(Ljava/lang/String;I)I')
    if not ok then
        return nil, 'permission request failed: ' .. tostring(value)
    end
    requestId = value
    return requestId
end

---@param requestId number
---@return boolean Whether an active permission or document request was cancelled.
function M.cancelRequest(requestId)
    assert(type(requestId) == 'number' and requestId % 1 == 0 and requestId > 0,
            'a positive request ID is required')
    if requestId >= 2147483648 then
        return require('platform.FileDialog').cancel(requestId)
    end
    return jCall(storageHelper, 'cancelRequest', { requestId }, '(I)Z') or false
end

M.cancelPermissionRequest = M.cancelRequest

---Legacy location query only. Startup never loads scripts or saves here.
---@return string
function M.getSDCardPath()
    local methodName = 'getSDCardPath'
    local sig = '()Ljava/lang/String;'
    local ret = jCall(andApp, methodName, {}, sig)
    if not ret or ret == '' then
        lstg.SystemLog('getSDCardPath: failed')
    end
    return ret
end

---@return void
function M.messageBox(title, msg)
    local methodName = 'showDialog'
    local sig = '(Ljava/lang/String;Ljava/lang/String;)V'
    return jCall(andHelper, methodName, { title, msg }, sig)
end

local ActivityInfo = require('platform.android.ActivityInfo')

function M.setOrientation(ori)
    local methodName = 'setActivityOrientation'
    local sig = '(I)V'
    if type(ori) == 'string' then
        ori = ActivityInfo['SCREEN_ORIENTATION_' .. string.upper(ori)]
    end
    assert(type(ori) == 'number' and -1 <= ori and ori <= 14, 'wrong param')
    lstg.SystemLog('setOrientation: set to ' .. ori)
    return jCall(andApp, methodName, { ori }, sig)
end

function M.setOrientationLandscape()
    return M.setOrientation('SENSOR_LANDSCAPE')
end

function M.setOrientationPortrait()
    return M.setOrientation('PORTRAIT')
end

---@return number
function M.getOrientation()
    local methodName = 'getActivityOrientation'
    local sig = '()I'
    return jCall(andApp, methodName, {}, sig)
end

---@return table
function M.getNativeInfo()
    local ret = {}
    if osname == 'android' then
        ret['AssetsPath'] = M.getAssetsPath()
        ret['PackageName'] = M.getCocos2dxPackageName()
        ret['Version'] = M.getVersion()
        ret['DPI'] = M.getDPI()
        ret['InternalDataPath'] = M.getInternalDataPath()
    end
    return ret
end

return M
