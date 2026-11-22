local M = {}

---@param editBox ccui.EditBox
function M.setEditBox(editBox)
    editBox.handler = {
        began      = {},
        ended      = {},
        changed    = {},
        ['return'] = {},
    }
    editBox:registerScriptEditBoxHandler(function(e)
        local h = editBox.handler[e]
        if h then
            for i, v in ipairs(h) do
                v()
            end
        end
    end)
    function editBox:addHandler(type, handler)
        table.insert(assert(self.handler[type]), handler)
    end
    function editBox:clearHandler(type)
        if type and self.handler[type] then
            self.handler[type] = {}
        elseif type == nil then
            self.handler = {
                began      = {},
                ended      = {},
                changed    = {},
                ['return'] = {},
            }
        end
    end
end

return M
