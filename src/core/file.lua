--

local FU = cc.FileUtils:getInstance()
local LRES = lstg.ResourceMgr:getInstance()

---@~chinese 加载指定位置的ZIP资源包，可选填密码。失败将导致错误。
---
---@~chinese 细节
---
---@~chinese >   后加载的资源包有较高的查找优先级。这意味着可以通过该机制加载资源包来覆盖基础资源包中的文件。
---
---@~chinese >   一旦zip文件被打开，将不能被访问。
---
---@~chinese >   加载文件时将按照优先级依次搜索资源包，若资源包中不含文件则从当前目录加载。
---
---@~english Load zip pack at `path` with an optional password. Will throw an error if failed.
---
---@~english Detail
---
---@~english >   Zip pack loaded later will have higher priority. So you can override files in previous packs.
---
---@~english >   Zip file will be occupied after loaded.
---
---@~english >   Files required by engine will be searched in packs at first, then local path.
---
---@param path string
---@param password string @optional
---@return lstg.ResourcePack
function LoadPack(path, password)
    path = FU:fullPathForFilename(path)
    local pack = LRES:loadResourcePack(path, password or '')
    if not pack then
        error("failed to load resource pack at " .. path)
    end
    --local lst = pack:listFiles()
    --Print('---------------')
    --for i, v in ipairs(lst) do
    --    Print(v)
    --end
    return pack
end

---@~chinese 卸载指定位置的资源包，要求路径名必须一致。若资源包不存在不发生错误。
---
---@~english Unload zip pack loaded at `path`. Will NOT throw an error if failed.
---
function UnloadPack(path)
    path = FU:fullPathForFilename(path)
    if not LRES:unloadResourcePack(path) then
        Print("failed to unload resource pack " .. path)
    end
end

---@~chinese 将资源包中的数据解压到本地。若失败将抛出错误。
---
---@~english Extract files in pack to local path. Will throw an error if failed.
---
function ExtractRes(path, target)
    path = FU:fullPathForFilename(path)
    if not LRES:extractFile(path, target) then
        error("failed to extract resource pack " .. path)
    end
end

--

---FindResourcePackForPath
---@param path string
---@return lstg.ResourcePack
function FindResourcePackForPath(path)
    local packs = LRES:getResourcePacks()
    for _, v in ipairs(packs) do
        if v:isFileOrDirectoryExist(path) then
            return v
        end
    end
end

---@return boolean,lstg.ResourcePack
function CacheFile(path)
    local packs = LRES:getResourcePacks()
    for _, v in ipairs(packs) do
        if v:cacheFile(path) then
            --Print(string.format('cache file %q in pack %q',path,v:getPath()))
            return true, v
        end
    end
    path = FU:fullPathForFilename(path)
    --Print(string.format('cache file %q from local',path))
    return LRES:cacheLocalFile(path)
end

---@return lstg.ResourcePack
function CacheFileAsync(path, callback)
    local packs = LRES:getResourcePacks()
    callback = callback or function()
    end
    for _, v in ipairs(packs) do
        if v:isFileOrDirectoryExist(path) then
            v:cacheFileAsync(path, callback)
            return v
        end
    end
    LRES:cacheLocalFileAsync(path, callback)
end

function FileTaskWrapper(path, autoRelease, task)
    local ok, pack = CacheFile(path)
    local ret = { task() }
    if autoRelease and ok then
        if pack then
            pack:removeFileCache(path)
        else
            LRES:removeLocalFileCache(path)
        end
    end
    return unpack(ret)
end

function FileTaskAsyncWrapper(path, autoRelease, task)
    local pack = FindResourcePackForPath(path)
    if pack then
        local pack_path = pack:getPath()
        pack:cacheFileAsync(path, function()
            task()
            if autoRelease then
                -- pack may be unloaded
                local pack_ = LRES:getResourcePack(pack_path)
                if pack_ then
                    pack_:removeFileCache(path)
                end
            end
        end)
    else
        LRES:cacheLocalFileAsync(path, function()
            task()
            if autoRelease then
                LRES:removeLocalFileCache(path)
            end
        end)
    end
end

