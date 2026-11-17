--
local M = {}
local proj = require('xe.Project')
local his = require('xe.history')
local logger = require('xe.logger')

---@return xe.SceneTree
local function get_tree()
    return assert(require('xe.main').getEditor():getTree())
end

local function check_return(msg)
    if type(msg) == 'string' then
        logger.log(msg, "error")
        return false
    end
    return true
end

--

function M.new()
    check_return(proj.new())
end

function M.open()
    check_return(proj.open())
end

function M.save()
    check_return(proj.save())
end

function M.close()
    check_return(proj.close())
end

function M.exit()
    if not proj.getFile() then
        GameExit()
    else
        proj.close(function()
            GameExit()
        end)
    end
end

--

function M.merge()
    if not proj.getFile() then
        return
    end
    local path = require('xe.Project').getDir()
    local original = proj.getGeneration()
    require('platform.DocumentWorkspace').openProject(path, function(fileName)
        local ok = proj._loadFromFile(fileName, true)
        if ok then his.clear() end
    end, function() return original == proj.getGeneration() end)
end

--

function M.undo()
    if not proj.getFile() then
        return
    end
    if true then
        his.undo(function(op)
            op.undo()
        end)
    end
end

function M.redo()
    if not proj.getFile() then
        return
    end
    if true then
        his.redo(function(op)
            op.exe()
        end)
    end
end

function M.delete()
    if not proj.getFile() then
        return
    end
    local op, ok = get_tree():deleteCurrent()
    if op and ok then
        his.add(op)
    end
end

function M.copy()
    if not proj.getFile() then
        return
    end
    get_tree():copyCurrent()
end

function M.cut()
    if not proj.getFile() then
        return
    end
    local op, ok = get_tree():cutCurrent()
    if op and ok then
        his.add(op)
    end
end

function M.paste()
    if not proj.getFile() then
        return
    end
    local op, ok = get_tree():pasteToCurrent()
    if op and ok then
        his.add(op)
    end
end

function M.build(debugStage, debugSC)
    if not proj.getFile() then
        return
    end
    local dir = proj.getDir()
    local root_path = dir .. '/root.lua'
    local root = "Include('THlib.lua')\nInclude('_editor_output.lua')"
    cc.FileUtils:getInstance():writeStringToFile(root, root_path)
    local path = dir .. '/_editor_output.lua'
    return proj.compileToFile(path, debugStage, debugSC)
end

function M.pack()
    if not proj.getFile() then
        return
    end
    if not proj.pack() then
        logger.log('failed to pack project', 'error')
    end
end

function M.debugStage()
    if not proj.getFile() then
        return
    end
    local _debug_stage_name
    local curNode = get_tree():getCurrent()
    local taskNode = curNode:getParentNode()
    if taskNode:getType() == 'stagetask' then
        local stageNode = taskNode:getParentNode()
        local groupNode = stageNode:getParentNode()
        local stageName = stageNode:getAttrValue(1)
        local groupName = groupNode:getAttrValue(1)
        _debug_stage_name = ("%s@%s"):format(stageName, groupName)
    else
        logger.log("must debug from direct child node of stagetask node", 'error')
        return
    end
    if check_return(M.build(true, nil)) then
        proj.launchGame(nil, nil, nil, _debug_stage_name)
    end
end

function M.debugSC()
    if not proj.getFile() then
        return
    end
    local scDebugNode = get_tree():getCurrent()
    if scDebugNode:getType() ~= 'bossspellcard' then
        logger.log('current node is not a spell card node', "Error")
    else
        if check_return(M.build(nil, true)) then
            proj.launchGame(nil, nil, nil, nil, true)
        end
    end
end

function M.run()
    if not proj.getFile() then
        return
    end
    if check_return(M.build()) then
        proj.launchGame()
    end
end

--

function M.insertAfter()
    get_tree():setInsertPos('after')
end
function M.insertBefore()
    get_tree():setInsertPos('before')
end
function M.insertChild()
    get_tree():setInsertPos('child')
end

--

local lineNum = 0
local function count_line(s)
    local _, n = s:gsub("\n", "\n")
    lineNum = lineNum - n
end

---@param node xe.ui.TreeNode
local function FindNode(node)
    local head = node:toHead()
    local foot = node:toFoot()
    if head then
        count_line(head)
    end
    if lineNum <= 0 then
        node:select()
        return true
    end
    for i = 1, node:getChildrenCount() do
        if FindNode(node:getChildAt(i)) then
            return true
        end
    end
    if foot then
        count_line(foot)
    end
    if lineNum <= 0 then
        node:select()
        return true
    end
end
local function GoToLineNum()
    local curProjFile = require('xe.Project').getFile()
    if curProjFile then
        lineNum = tonumber(lineNumText:GetValue())
        if lineNum == nil then
            require('xe.ui.MessageBox').OK('Error', "Must input an integer")
            --lineNumText:SetValue("")
            return
        end
        --local projectTree = projMgr.getTree()
        local rootNode = proj.getRoot()
        --for child in Tree.Children(projectTree, rootNode) do
        --    if FindNode(child) then
        --        projectTree:SetFocus()
        --        return
        --    end
        --end
        for i = 1, rootNode:getChildrenCount() do
            if FindNode(rootNode:getChildAt(i)) then
                --projectTree:SetFocus()
                return
            end
        end
        require('xe.ui.MessageBox').OK('Info', "End of project is reached")
    end
end

function M.find()
    if not proj.getFile() then
        return
    end
    GoToLineNum()
    --TODO
end

--

function M.moveDown()
    if not proj.getFile() then
        return
    end
    local cur = get_tree():getCurrent()
    if cur then
        cur:moveDown()
    end
end

function M.moveUp()
    if not proj.getFile() then
        return
    end
    local cur = get_tree():getCurrent()
    if cur then
        cur:moveUp()
    end
end

--

function M.exportNode()
    proj.exportNode()
end

function M.importNode()
    proj.importNode()
end

--

function M.setting()
    require('xe.setting.Setting').show()
end

--

function M.about()
    require('imgui.ui.About').show()
end

return M
