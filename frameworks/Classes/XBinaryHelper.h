#pragma once
#include "io/Stream.h"
#include <string>

namespace lstg
{
	class BinaryReader
	{
		cocos2d::io::StreamPtr stream;
	public:
		const cocos2d::io::StreamPtr& getStream() const noexcept { return stream; }
		// Values use native byte order and representation. A short scalar/string
		// read reports OutOfRange; bytes already consumed remain consumed.
		cocos2d::io::Result<uint8_t> readByte() const;
		cocos2d::io::IoResult readBytes(void* outBuffer, size_t length) const;
		// On failure, value contains only the prefix actually read, never padding.
		cocos2d::io::Result<std::string> readString(size_t length) const;
		cocos2d::io::Result<int16_t> readInt16() const;
		cocos2d::io::Result<uint16_t> readUInt16() const;
		cocos2d::io::Result<int32_t> readInt32() const;
		cocos2d::io::Result<uint32_t> readUInt32() const;
		cocos2d::io::Result<int64_t> readInt64() const;
		cocos2d::io::Result<uint64_t> readUInt64() const;
		cocos2d::io::Result<float> readFloat() const;
		cocos2d::io::Result<double> readDouble() const;

		explicit BinaryReader(cocos2d::io::StreamPtr stream);
	};

	class BinaryWriter
	{
		cocos2d::io::StreamPtr stream;
	public:
		const cocos2d::io::StreamPtr& getStream() const noexcept { return stream; }
		// Values use native byte order and representation. Results retain partial
		// byte counts and terminal status; failure does not roll back prior writes.
		cocos2d::io::IoResult writeByte(uint8_t value) const;
		cocos2d::io::IoResult writeBytes(const void* buffer, size_t length) const;
		cocos2d::io::IoResult writeString(const std::string& value) const;
		cocos2d::io::IoResult writeInt16(int16_t value) const;
		cocos2d::io::IoResult writeUInt16(uint16_t value) const;
		cocos2d::io::IoResult writeInt32(int32_t value) const;
		cocos2d::io::IoResult writeUInt32(uint32_t value) const;
		cocos2d::io::IoResult writeInt64(int64_t value) const;
		cocos2d::io::IoResult writeUInt64(uint64_t value) const;
		cocos2d::io::IoResult writeFloat(float value) const;
		cocos2d::io::IoResult writeDouble(double value) const;

		explicit BinaryWriter(cocos2d::io::StreamPtr stream);
	};
}
