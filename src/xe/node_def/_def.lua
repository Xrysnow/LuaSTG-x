--
local M = {}
local nodeType = {}

function M.DefineNode(type, def)
    nodeType[type] = def
end

function M.DefineNodes(t)
    for k, v in pairs(t) do
        nodeType[k] = v
    end
end

function M.UndefineNode(type)
    nodeType[type] = nil
end

function M.getDefine(type)
    return nodeType[type]
end

function M.getNodeType()
    return nodeType
end

function M.regist()
    require('xe.node_def.legacy.__init__')
    require('xe.node_def.x.__init__')
    i18n.addDict('xe.node', require('xe.node_def._dict'))

    local helper = require('xe.TreeHelper')
    for k, v in pairs(nodeType) do
        v.name = k
        if not v.disptype then
            v.disptype = k
        end
        if v.allowchild then
            for _, typename in ipairs(v.allowchild) do
                v.allowchild[typename] = true
            end
        end
        if v.forbidchild then
            for _, typename in ipairs(v.forbidchild) do
                v.forbidchild[typename] = true
            end
        end
        if v.allowparent then
            for _, typename in ipairs(v.allowparent) do
                v.allowparent[typename] = true
            end
        end
        if v.forbidparent then
            for _, typename in ipairs(v.forbidparent) do
                v.forbidparent[typename] = true
            end
        end
        if v.needancestor then
            for _, typename in ipairs(v.needancestor) do
                v.needancestor[typename] = true
            end
        end
        if v.forbidancestor then
            for _, typename in ipairs(v.forbidancestor) do
                v.forbidancestor[typename] = true
            end
        end
        if v.watch then
            helper.watch[v.watch] = {}
        end
    end

    --local types = {}
    --for k, v in pairs(nodeType) do
    --    for i, item in ipairs(v) do
    --        if item[2] then
    --            types[item[2]] = true
    --        end
    --    end
    --end
    --print('---')
    --for k, v in pairs(types) do
    --    print(k)
    --end
    --print('---')
end

return M
