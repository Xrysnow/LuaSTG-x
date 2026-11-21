local KEY_BIT = { 128, 64, 32, 16, 8, 4, 2, 1 }
local KEY_NAME = { "up", "down", "left", "right", "slow", "shoot", "spell", "special" }
local KEY_INDEX = {}
for i, name in ipairs(KEY_NAME) do KEY_INDEX[name] = i end
local FILE_VERSION = 2

--- 将按键状态转换为二进制数值
---@return number 返回二进制按键数值
local function KeyState2Byte(state)
    local ret = 0
    for i, k in ipairs(KEY_NAME) do
        if state[k] then
            ret = ret + KEY_BIT[i]
        end
    end
    return ret
end

--- 将二进制数值转换为按键状态
local function Byte2KeyState(state, b)
    for i, k in ipairs(KEY_NAME) do
        if b >= KEY_BIT[i] then
            state[k] = true
            b = b - KEY_BIT[i]
        else
            state[k] = false
        end
    end
end

---------------------------------------------------ReplayFrameReader

---@class plus.ReplayFrameReader
local ReplayFrameReader = plus.Class()
plus.ReplayFrameReader  = ReplayFrameReader

--- 构造ReplayFrameReader
---@param path string 文件路径
---@param offset number 录像数据偏移
---@param count number 录像帧数量
function ReplayFrameReader:init(path, offset, count)
    self._fs = plus.FileStream(path, "rb")
    local ok, failure = pcall(function()
        local header = plus.BinaryReader(self._fs)
        assert(header:ReadString(4) == "STGR", "invalid file format.")
        self._version = header:ReadUShort()
        assert(self._version == 1 or self._version == FILE_VERSION, "unsupported file version.")
        local length = count
        if self._version == FILE_VERSION then
            assert(offset >= 10, "invalid replay offset.")
            self._fs:Seek(offset - 4, "set")
            length = header:ReadUInt()
            assert(length >= count * 3, "invalid replay stage length.")
        end
        self._fs:Seek(offset, "set")
        assert(length <= self._fs:GetSize(), "truncated replay stage.")
        self._limit = offset + length
    end)
    if not ok then
        self._fs:Close()
        error(failure, 0)
    end
    self._offset = offset
    self._read = 0  ---已读取数量
    self._count = count  ---帧数量
end

--- 下一帧
---@return boolean 若达到结尾则返回false，否则返回true
function ReplayFrameReader:Next(state)
    if self._read >= self._count then
        return false
    end
    local fs = self._fs
    local held = assert(fs:ReadByte(), "truncated replay frame.")
    local actions
    if self._version == FILE_VERSION then
        assert(fs:GetPosition() + 2 <= self._limit, "truncated replay frame.")
        local size = fs:ReadByte() + fs:ReadByte() * 256
        assert(fs:GetPosition() + size <= self._limit, "invalid replay edge count.")
        actions = { held = {}, pressed = {}, released = {}, edges = {}, tick = self._read + 1 }
        Byte2KeyState(actions.held, held)
        if size > 0 then
            local bytes = assert(fs:ReadBytes(size), "truncated replay edges.")
            assert(#bytes == size, "truncated replay edges.")
            for i = 1, size do
                local value = bytes:byte(i)
                local action = assert(KEY_NAME[math.floor(value / 2) + 1], "invalid replay action.")
                local down = value % 2 == 1
                actions.edges[i] = { action = action, down = down }
                if down then actions.pressed[action] = true else actions.released[action] = true end
            end
        end
    end
    if self._read + 1 == self._count then
        assert(fs:GetPosition() == self._limit, "invalid replay frame data length.")
    end
    self._read = self._read + 1
    Byte2KeyState(state, held)
    if state == KeyState and lstg and lstg.SetReplayInputActions then
        lstg.SetReplayInputActions(actions)
    end
    return true, actions
end

--- 重置
function ReplayFrameReader:Reset()
    self._read = 0
    self._fs:Seek(self._offset, "set")
end

--- 关闭文件流
function ReplayFrameReader:Close()
    self._fs:Close()
end

---------------------------------------------------ReplayFrameWriter

---@class plus.ReplayFrameWriter
local ReplayFrameWriter = plus.Class()
plus.ReplayFrameWriter  = ReplayFrameWriter

function ReplayFrameWriter:init()
    self._data = {}
    self._count = 0
    self._size = 0
    self._held = {}
end

function ReplayFrameWriter:Record(state, actions)
    if not actions and state == KeyState and lstg and lstg.GetInputActions then
        actions = lstg.GetInputActions()
    end
    local edges = {}
    local function append(name, down)
        local index = KEY_INDEX[name]
        if index then
            edges[#edges + 1] = string.char((index - 1) * 2 + (down and 1 or 0))
            self._held[name] = down
        end
    end
    -- Stage entry can inherit held inputs from the previous stage. Preserve the
    -- simulation's own transition order and add any unreported state changes.
    if actions then
        for _, edge in ipairs(actions.edges) do append(edge.action, edge.down) end
    end
    for _, name in ipairs(KEY_NAME) do
        if (not not state[name]) ~= (not not self._held[name]) then append(name, state[name]) end
    end
    assert(#edges <= 65535, "too many replay action edges in one frame.")
    local record = string.char(KeyState2Byte(state), #edges % 256, math.floor(#edges / 256)) .. table.concat(edges)
    self._count = self._count + 1
    self._data[self._count] = record
    self._size = self._size + #record
end

function ReplayFrameWriter:Write(fs)
    for i = 1, self._count do
        fs:WriteBytes(self._data[i])
    end
end

function ReplayFrameWriter:GetSize()
    return self._size
end

function ReplayFrameWriter:GetCount()
    return self._count
end

---------------------------------------------------ReplayManager

---@class plus.ReplayManager
local ReplayManager = plus.Class()
plus.ReplayManager  = ReplayManager

---构造ReplayManager
---@param replayDirectory string 录像文件夹
function ReplayManager:init(replayDirectory)
    self._repdir = replayDirectory
    self._filefmt = "slot(%d).rep"
    self._filefmt2 = "slot%d.rep"
    self._slots = nil
    self._slotmax = 16

    --检查录像目录是否存在
    if not plus.DirectoryExists(replayDirectory) then
        plus.CreateDirectory(replayDirectory)
    end

    ---刷新录像数据
    self:Refresh()
end

--- [静态函数]读取录像数据
---
--- 返回的录像数据信息以下述格式表述：
---  {
---    path = "文件路径",
---    fileVersion = 2, gameName = "游戏名称", gameVersion = 1, gameExtendInfo = "",
---    userName = "用户名", userExtendInfo = "用户额外信息",
---    stages = {
---      {
---        stageName = "关卡名称", stageExtendInfo = "", score = 0, randomSeed = 0,
---        stageTime = 0, stageDate = 0, stagePlayer=lstg.var.rep_player，
---       frameCount = 300, frameDataPosition = 12345
---      }
---    }
---  }
function ReplayManager.ReadReplayInfo(path)
    --SystemLog('read replay info from '..path)
    local ret = { path = path }
    local f = plus.FileStream(path, "rb")
    local r = plus.BinaryReader(f)

    plus.TryCatch {
        try =
            function()
                ---读取文件头
                assert(r:ReadString(4) == "STGR", "invalid file format.")

                ret.fileVersion = r:ReadUShort()  ---文件版本
                assert(ret.fileVersion == 1 or ret.fileVersion == FILE_VERSION, "unsupported file version.")

                ---游戏数据
                local gameNameLength = r:ReadUShort()  ---游戏名称
                ret.gameName = r:ReadString(gameNameLength)
                ret.gameVersion = r:ReadUShort()  ---游戏版本
                ret.group_finish = r:ReadUShort() --是否完成关卡
                local gameExtendInfoLength = r:ReadUInt()  ---额外信息
                ret.gameExtendInfo = r:ReadString(gameExtendInfoLength)

                ---玩家信息
                local userNameLength = r:ReadUShort()  ---机签
                ret.userName = r:ReadString(userNameLength)
                local userExtendInfoLength = r:ReadUInt()  ---额外信息
                ret.userExtendInfo = r:ReadString(userExtendInfoLength)

                ---关卡数据
                ret.stages = {}
                local recordStageCount = r:ReadUShort()  ---关卡数量
                for i = 1, recordStageCount do
                    local stage = {}

                    local stageNameLength = r:ReadUShort()  ---关卡名称
                    stage.stageName = r:ReadString(stageNameLength)
                    local stageExtendInfoLength = r:ReadUInt()  ---额外信息
                    stage.stageExtendInfo = r:ReadString(stageExtendInfoLength)
                    local scoreHigh = r:ReadUInt()  ---分数的高32位
                    local scoreLow = r:ReadUInt()  ---分数的低32位
                    stage.score = scoreLow + scoreHigh * 0x100000000
                    stage.randomSeed = r:ReadUInt()  ---随机数种子
                    stage.stageTime = r:ReadFloat()  ---通关时间
                    stage.stageDate = r:ReadUInt()  ---游戏日期(UNIX时间戳)
                    local stagePlayerLength = r:ReadUShort()  ---使用自机
                    stage.stagePlayer = r:ReadString(stagePlayerLength)
--                  local stage_num = r:ReadUShort()  --关卡所在位置
--                  stage.cur_stage_num = stage_num
--                  stage.group_num= r:ReadUShort() --关卡组长度
                    --录像数据
                    stage.frameCount = r:ReadUInt()  ---帧数
                    stage.frameDataSize = ret.fileVersion == 1 and stage.frameCount or r:ReadUInt()
                    assert(ret.fileVersion == 1 or stage.frameDataSize >= stage.frameCount * 3,
                        "invalid replay stage length.")
                    stage.frameDataPosition = f:GetPosition()  ---数据起始位置
                    assert(stage.frameDataSize <= f:GetSize(), "truncated replay stage.")
                    f:Seek(stage.frameDataSize)

                    table.insert(ret.stages, stage)
                end
            end,
        finally =
            function()
                f:Close()
            end
    }

    --SystemLog(stringify(ret))
    return ret
end

--- [静态函数] 写入录像数据
--- 输入的录像信息需要满足下述表述：
--- {
---　gameName = "游戏名称", gameVersion = 1, gameExtendInfo = "额外信息",
---　userName = "用户名", userExtendInfo = "用户额外信息",
---　stages = {
---　　{
---　　　stageName = "关卡名称", stageExtendInfo = "", score = 0, randomSeed = 0,
---　　　stageTime = 0, stageDate = 0, stagePlayer=lstg.var.rep_player，
---　　　frameData = ReplayFrameWriter()
---　　}
---　}
---}
function ReplayManager.SaveReplayInfo(path, data)
    local f = plus.FileStream(path, "wb")
    local w = plus.BinaryWriter(f)

    plus.TryCatch {
        try =
            function()
                ---写入文件头
                w:WriteString("STGR", false)

                w:WriteUShort(FILE_VERSION)

                ---游戏数据
                w:WriteUShort(string.len(data.gameName))  ---游戏名称
                w:WriteString(data.gameName, false)
                w:WriteUShort(data.gameVersion)  ---游戏版本
                w:WriteUShort(data.group_finish) --是否完成关卡
                if data.gameExtendInfo then
                    w:WriteUInt(string.len(data.gameExtendInfo))  ---额外信息
                    w:WriteString(data.gameExtendInfo, false)
                else
                    w:WriteUInt(0)
                end

                ---玩家信息
                w:WriteUShort(string.len(data.userName))  ---机签
                w:WriteString(data.userName, false)
                if data.userExtendInfo then
                    w:WriteUInt(string.len(data.userExtendInfo))  ---额外信息
                    w:WriteString(data.userExtendInfo, false)
                else
                    w:WriteUInt(0)
                end

                ---关卡数据
                local stageCount = #data.stages
                w:WriteUShort(stageCount)  ---关卡数量
                for i = 1, stageCount do
                    local stage = data.stages[i]

                    w:WriteUShort(string.len(stage.stageName))  ---关卡名称
                    w:WriteString(stage.stageName, false)
                    if stage.stageExtendInfo then
                        w:WriteUInt(string.len(stage.stageExtendInfo))  ---额外信息
                        w:WriteString(stage.stageExtendInfo, false)
                    else
                        w:WriteUInt(0)
                    end
                    w:WriteUInt(math.floor(stage.score / 0x100000000))  ---分数的高32位
                    w:WriteUInt(math.floor(stage.score % 0x100000000))  ---分数的低32位
                    w:WriteUInt(stage.randomSeed)  ---随机数种子
                    w:WriteFloat(stage.stageTime or 0)  ---通关时间
                    w:WriteUInt(stage.stageDate or 0)  ---游戏日期(UNIX时间戳)
                    w:WriteUShort(string.len(stage.stagePlayer))  ---使用自机
                    w:WriteString(stage.stagePlayer, false)
--                  w:WriteUShort(stage.cur_stage_num)--关卡所在位置
--                  w:WriteUShort(stage.group_num)  --关卡组长度
                    --录像数据
                    w:WriteUInt(stage.frameData:GetCount())  ---帧数
                    w:WriteUInt(stage.frameData:GetSize())  ---数据字节数
                    stage.frameData:Write(f)  ---数据
                end
            end,
        finally =
            function()
                f:Close()
            end
    }
end

--- 获取录像目录
function ReplayManager:GetReplayDirectory()
    return self._repdir
end

--- 构造录像文件名称
function ReplayManager:MakeReplayFilename(slot)
    return self._repdir.."/"..string.format(self._filefmt2, slot)
end

--- 刷新
function ReplayManager:Refresh()
    self._slots = {}

    local files = plus.EnumFiles(self._repdir)
    for _, v in ipairs(files) do
        local _, _, id = string.find(v.name, self._filefmt)
        if v.isDirectory == false and id ~= nil then
            id = tonumber(id)
            assert(self._slots[id] == nil)

            local filename = self._repdir.."/"..v.name
            if not (id <= 0 or id > self._slotmax) then
                plus.TryCatch {
                    try = 
                        function()
                            self._slots[id] = ReplayManager.ReadReplayInfo(filename)
                        end,
                    catch = 
                        function(err)
                            self._slots[id] = nil
                            SystemLog("加载录像文件'"..filename.."'失败: "..err)
                        end
                }
            end
        end
    end
end

--- 获取录像数量
function ReplayManager:GetSlotCount()
    return self._slotmax
end

--- 获取录像信息
---@param slot number 录像槽
function ReplayManager:GetRecord(slot)
    assert(slot >= 0 and slot <= self._slotmax, "invalid argument.")
    return self._slots[slot]
end
