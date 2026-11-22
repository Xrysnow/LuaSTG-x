--
local M = {}
local fu = cc.FileUtils:getInstance()
local node_json = fu:getStringFromFile('xe/node.json')
local node_small_json = fu:getStringFromFile('xe/node_small.json')
local node_data = json.decode(node_json)
local node_small_data = json.decode(node_small_json)
local cache = cc.Director:getInstance():getTextureCache()

---@return cc.Sprite
function M.getIcon(name)
    local data = node_data[name]
    if data then
        local tex = cache:addImage('xe/node.png')
        return cc.Sprite:createWithTexture(tex, cc.rect(unpack(data)))
    else
        return cc.Sprite:create('null.png')
    end
end

function M.getSmallIcon(name)
    local data = node_small_data[name]
    if data then
        local tex = cache:addImage('xe/node_small.png')
        return cc.Sprite:createWithTexture(tex, cc.rect(unpack(data)))
    else
        return cc.Sprite:create('null.png')
    end
end

return M
