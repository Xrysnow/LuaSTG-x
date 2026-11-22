---------------------------------------------------FileStream

---@class plus.FileSeekOrigin
---@field Begin string
---@field Current string
---@field End string
plus.FileSeekOrigin = {
    Begin   = "set",
    Current = "cur",
    End     = "end"
}

---@class plus.FileStream
local FileStream = plus.Class()
plus.FileStream = FileStream

---@brief 初始化文件流
---@param path string 文件路径
---@param mode string 打开模式
function FileStream:init(path, mode)
    self._f = assert(io.open_u8(path, mode))
end

---@brief 获取文件大小
---@return number 文件大小（字节）
function FileStream:GetSize()
    assert(self._f, "file is closed.")
    local cur = assert(self._f:seek("cur", 0))
    local eof = assert(self._f:seek("end", 0))
    assert(self._f:seek("set", cur))
    return eof - cur
end

---@brief 获取当前读写位置
---@return number 读写位置
function FileStream:GetPosition()
    assert(self._f, "file is closed.")
    return assert(self._f:seek("cur", 0))
end

---@brief 跳转到位置
---@param offset number 新的位置
---@param base number 基准
function FileStream:Seek(offset, base)
    assert(self._f, "file is closed.")
    if base then
        assert(self._f:seek(base, offset))
    else
        assert(self._f:seek("cur", offset))
    end
end

---@brief 关闭文件流
function FileStream:Close()
    assert(self._f, "file is closed.")
    self._f:flush()
    self._f:close()
    self._f = nil
end

---@brief 立即刷新缓冲区
function FileStream:Flush()
    assert(self._f, "file is closed.")
    self._f:flush()
end

---@brief 读取一个字节
---@return number 若为文件尾则为nil，否则以number返回所读字节
function FileStream:ReadByte()
    assert(self._f, "file is closed.")
    local b = self._f:read(1)
    if b then
        return string.byte(b)
    else
        return nil
    end
end

---@brief 读取若干个字节
---@param count number 字节数
function FileStream:ReadBytes(count)
    assert(self._f, "file is closed.")
    return self._f:read(count)
end

---@brief 写入一个字节
---@param b number 要写入的字节
function FileStream:WriteByte(b)
    assert(self._f, "file is closed.")
    assert(type(b) == "number" and b >= 0 and b <= 255, "invalid byte.")
    assert(self._f:write(string.char(b)))
end

---@brief 写入字节数组
---@param data string 要写入的字节
function FileStream:WriteBytes(data)
    assert(self._f, "file is closed.")
    assert(type(data) == "string", "invalid bytes.")
    assert(self._f:write(data))
end

------------------------------------------------------BinaryReader

---@class plus.BinaryReader
local BinaryReader = plus.Class()
plus.BinaryReader = BinaryReader

function BinaryReader:init(stream)
    assert(type(stream) == "table", "invalid argument type.")
    self._stream = stream
end

---@brief 关闭上行流
function BinaryReader:Close()
    self._stream:Close()
end

---@brief 获取流
function BinaryReader:GetStream()
    return self._stream
end

---@brief 读取一个字符
---@return string 以string返回读取的字符
function BinaryReader:ReadChar()
    local byte = assert(self._stream:ReadByte(), "end of stream.")
    return string.char(byte)
end

---@brief 读取一个字节
---@return number 以number返回读取的字节
function BinaryReader:ReadByte()
    local byte = assert(self._stream:ReadByte(), "end of stream.")
    return byte
end

---@brief 以小端序读取一个16位带符号整数
---@return number 以number返回读取的整数
function BinaryReader:ReadShort()
    local b1, b2 = self:ReadByte(), self:ReadByte()
    local neg = (b2 >= 0x80)
    if neg then
        return -(0xFFFF - (b1 + b2 * 0x100 - 1))
    else
        return b1 + b2 * 0x100
    end
end

---@brief 以小端序读取一个16位无符号整数
---@return number 以number返回读取的整数
function BinaryReader:ReadUShort()
    local b1, b2 = self:ReadByte(), self:ReadByte()
    return b1 + b2 * 0x100
end

---@brief 以小端序读取一个32位带符号整数
---@return number 以number返回读取的整数
function BinaryReader:ReadInt()
    local b1, b2, b3, b4 = self:ReadByte(), self:ReadByte(), self:ReadByte(), self:ReadByte()
    local neg = (b4 >= 0x80)
    if neg then
        return -(0xFFFFFFFF - (b1 + b2 * 0x100 + b3 * 0x10000 + b4 * 0x1000000 - 1))
    else
        return b1 + b2 * 0x100 + b3 * 0x10000 + b4 * 0x1000000
    end
end

---@brief 以小端序读取一个32位无符号整数
---@return number 以number返回读取的整数
function BinaryReader:ReadUInt()
    local b1, b2, b3, b4 = self:ReadByte(), self:ReadByte(), self:ReadByte(), self:ReadByte()
    return b1 + b2 * 0x100 + b3 * 0x10000 + b4 * 0x1000000
end

---@brief 以小端序读取一个32位浮点数
---@return number 以number返回读取的浮点数
function BinaryReader:ReadFloat()
    local b1, b2, b3, b4 = self:ReadByte(), self:ReadByte(), self:ReadByte(), self:ReadByte()
    local sign = (b4 >= 0x80)
    local expo = (b4 % 0x80) * 0x2 + math.floor(b3 / 0x80)
    local mant = ((b3 % 0x80) * 0x100 + b2) * 0x100 + b1

    if sign then
        sign = -1
    else
        sign = 1
    end

    local n

    if mant == 0 and expo == 0 then
        n = sign * 0.0
    elseif expo == 0xFF then
        if mant == 0 then
            n = sign * math.huge
        else
            n = 0.0 / 0.0
        end
    else
        n = sign * math.ldexp(1.0 + mant / 0x800000, expo - 0x7F)
    end

    return n
end

---@brief 读取一个字符串
---@param len number 长度
---@return string 读取的字符串
function BinaryReader:ReadString(len)
    return self._stream:ReadBytes(len)
end

------------------------------------------------------BinaryWriter

---@class plus.BinaryWriter
local BinaryWriter = plus.Class()
plus.BinaryWriter = BinaryWriter

function BinaryWriter:init(stream)
    assert(type(stream) == "table", "invalid argument type.")
    self._stream = stream
end

---@brief 关闭上行流
function BinaryWriter:Close()
    self._stream:Close()
end

---@brief 获取流
function BinaryWriter:GetStream()
    return self._stream
end

---@brief 写入一个字符
---@param c string 要写入的字符
function BinaryWriter:WriteChar(c)
    assert(type(c) == "string" and string.len(c) == 1, "invalid argument.")
    self._stream:WriteByte(string.byte(c))
end

---@brief 写入一个字节
---@param b number 要写入的字节
function BinaryWriter:WriteByte(b)
    assert(type(b) == "number" and b >= 0 and b <= 255, "invalid argument.")
    self._stream:WriteByte(b)
end

---@brief 以小端序写入一个16位带符号整数
---@param s number 要写入的整数
function BinaryWriter:WriteShort(s)
    assert(type(s) == "number" and s >= -32768 and s <= 32767, "invalid argument.")
    if s < 0 then
        s = (0xFFFF + s) + 1
    end
    local b1, b2 = s % 0x100, math.floor(s / 0x100)
    self._stream:WriteByte(b1)
    self._stream:WriteByte(b2)
end

---@brief 以小端序写入一个16位无符号整数
---@param s number 要写入的整数
function BinaryWriter:WriteUShort(s)
    assert(type(s) == "number" and s >= 0 and s <= 65535, "invalid argument.")
    local b1, b2 = s % 0x100, math.floor(s / 0x100)
    self._stream:WriteByte(b1)
    self._stream:WriteByte(b2)
end

---@brief 以小端序写入一个32位带符号整数
---@param i number 要写入的整数
function BinaryWriter:WriteInt(i)
    assert(type(i) == "number" and i >= -2147483648 and i <= 2147483647, "invalid argument.")
    if i < 0 then
        i = (0xFFFFFFFF + i) + 1
    end
    local b1, b2, b3, b4 = i % 0x100, math.floor(i % 0x10000 / 0x100), math.floor(i % 0x1000000 / 0x10000), math.floor(i / 0x1000000)
    self._stream:WriteByte(b1)
    self._stream:WriteByte(b2)
    self._stream:WriteByte(b3)
    self._stream:WriteByte(b4)
end

---@brief 以小端序写入一个32位无符号整数
---@param i number 要写入的整数
function BinaryWriter:WriteUInt(i)
    assert(type(i) == "number" and i >= 0 and i <= 0xFFFFFFFF, "invalid argument.")
    local b1, b2, b3, b4 = i % 0x100, math.floor(i % 0x10000 / 0x100), math.floor(i % 0x1000000 / 0x10000), math.floor(i / 0x1000000)
    self._stream:WriteByte(b1)
    self._stream:WriteByte(b2)
    self._stream:WriteByte(b3)
    self._stream:WriteByte(b4)
end

---@brief 以小端序写入一个32位浮点数
---@param f number 要写入的浮点数
function BinaryWriter:WriteFloat(f)
    if f == 0.0 then
        self._stream:WriteByte(0)
        self._stream:WriteByte(0)
        self._stream:WriteByte(0)
        self._stream:WriteByte(0)
    end

    local sign = 0
    if f < 0.0 then
        sign = 0x80
        f = -f
    end

    local mant, expo = math.frexp(f)
    if mant ~= mant then
        self._stream:WriteByte(0x00)
        self._stream:WriteByte(0x00)
        self._stream:WriteByte(0x88)
        self._stream:WriteByte(0xFF)
    elseif mant == math.huge or expo > 0x80 then
        if sign == 0 then
            self._stream:WriteByte(0x00)
            self._stream:WriteByte(0x00)
            self._stream:WriteByte(0x80)
            self._stream:WriteByte(0x7F)
        else
            self._stream:WriteByte(0x00)
            self._stream:WriteByte(0x00)
            self._stream:WriteByte(0x80)
            self._stream:WriteByte(0xFF)
        end
    elseif (mant == 0.0 and expo == 0) or expo < -0x7E then
        self._stream:WriteByte(0x00)
        self._stream:WriteByte(0x00)
        self._stream:WriteByte(0x00)
        self._stream:WriteByte(sign)
    else
        expo = expo + 0x7E
        mant = (mant * 2.0 - 1.0) * math.ldexp(0.5, 24)
        self._stream:WriteByte(mant % 0x100)
        self._stream:WriteByte(math.floor(mant / 0x100) % 0x100)
        self._stream:WriteByte((expo % 0x2) * 0x80 + math.floor(mant / 0x10000))
        self._stream:WriteByte(sign + math.floor(expo / 0x2))
    end
end

---@brief 写入一个字符串
---@param s string 字符串
---@param nullTerminate boolean 是否以\0结尾
function BinaryWriter:WriteString(s, nullTerminate)
    if nullTerminate then
        local len = string.len(s)
        if len == 0 or string.byte(s, len) ~= 0 then
            s = s .. "\0"
        end
    end
    if string.len(s) ~= 0 then
        self._stream:WriteBytes(s)
    end
end
