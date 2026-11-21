-- STGR v1 录像兼容层，由 plus/plus.lua 在原版回放读写器加载后启用。
-- v1 每帧只保存八个动作的最终按住状态，同帧内按下又松开的短按会被忽略。

local reader = plus.ReplayFrameReader
local nextFrame = reader.Next

function reader:Next(state)
    local result = nextFrame(self, state)
    if result and state == KeyState and lstg.SetReplayInputActions then
        -- 写入游戏的 KeyState 时清除实时输入帧，由相邻的录像帧判定按下和松开。
        lstg.SetReplayInputActions(nil)
    end
    return result
end

-- 录像偏移量以文件开头为基准。FileStream:Seek 默认从当前位置计算偏移。
function reader:Reset()
    self._read = 0
    self._fs:Seek(self._offset, 'set')
end

-- 旧版 BinaryWriter:WriteFloat(0) 会写入八字节。STGR v1 的关卡时长字段固定为四字节，
-- 因此保存录像时将零时长直接写为四个零字节，避免后续字段错位。
local saveReplay = plus.ReplayManager.SaveReplayInfo
local replayIO = setmetatable({}, { __index = plus })

function replayIO.BinaryWriter(file)
    local writer = plus.BinaryWriter(file)
    local writeFloat = writer.WriteFloat
    function writer:WriteFloat(value)
        if value == 0 then
            self:WriteUInt(0)
        else
            writeFloat(self, value)
        end
    end
    return writer
end

-- 通过 SaveReplayInfo 的函数环境提供录像专用写入器。
setfenv(saveReplay, setmetatable({ plus = replayIO }, { __index = getfenv(saveReplay) }))
