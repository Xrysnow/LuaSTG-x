--

local FU = cc.FileUtils:getInstance()
local LRES = lstg.ResourceMgr:getInstance()

---@~chinese 加载指定位置的ZIP资源包，可选填密码。失败将导致错误。
---
---@~chinese 细节
---
---@~chinese >   后加载的资源包有较高的查找优先级。这意味着可以通过该机制加载资源包来覆盖基础资源包中的文件。
---
---@~chinese >   文件查找按 FileUtils 中配置的适配器优先级进行。
---
---@~english Load zip pack at `path` with an optional password. Will throw an error if failed.
---
---@~english Detail
---
---@~english >   Zip pack loaded later will have higher priority. So you can override files in previous packs.
---
---@~english >   Files are looked up in the configured FileUtils adapter order.
---
---@param path string
---@param password string @optional
---@return lstg.ResourcePack
function LoadPack(path, password)
    local pack = LRES:loadResourcePack(path, password or '')
    if not pack then
        error("failed to load resource pack at " .. path)
    end
    return pack
end

---@~chinese 卸载指定位置的资源包，要求路径名必须一致。若资源包不存在不发生错误。
---
---@~english Unload zip pack loaded at `path`. Will NOT throw an error if failed.
---
function UnloadPack(path)
    if not LRES:unloadResourcePack(path) then
        Print("failed to unload resource pack " .. path)
    end
end

---@~chinese 将资源包中的数据解压到本地。若失败将抛出错误。
---
---@~english Extract files in pack to local path. Will throw an error if failed.
---
function ExtractRes(path, target)
    if not LRES:extractFile(path, target) then
        error("failed to extract resource pack " .. path)
    end
end

--

---FindResourcePackForPath
---@param path string
---@return lstg.ResourcePack|nil
function FindResourcePackForPath(path)
    for _, hit in ipairs(FU:findAllFiles(path) or {}) do
        local pack = LRES:getResourcePackForHit(hit)
        if pack then
            return pack
        end
    end
end

---@return boolean,lstg.ResourcePack|nil
function CacheFile(path)
    local hit = FU:findFile(path)
    if hit and LRES:cacheFileHit(hit) then
        return true, LRES:getResourcePackForHit(hit)
    end
    return false
end

---@return lstg.ResourcePack|nil
function CacheFileAsync(path, callback)
    local hit = FU:findFile(path)
    LRES:cacheFileHitAsync(hit, callback)
    return hit and LRES:getResourcePackForHit(hit)
end

function FileTaskWrapper(path, autoRelease, task)
    local hit = FU:findFile(path)
    local ok = hit and LRES:cacheFileHit(hit)
    local ret = { task() }
    if autoRelease and ok then
        LRES:removeFileHitCache(hit)
    end
    return unpack(ret)
end

function FileTaskAsyncWrapper(path, autoRelease, task)
    local hit = FU:findFile(path)
    LRES:cacheFileHitAsync(hit, function()
        task()
        if autoRelease and hit then
            LRES:removeFileHitCache(hit)
        end
    end)
end

