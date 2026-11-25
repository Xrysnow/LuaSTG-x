#pragma once
#include "io/core/Stream.h"
#include <string>

namespace lstg
{
	class BinaryReader
	{
		cc::io::StreamPtr stream;
	public:
		const cc::io::StreamPtr& getStream() const noexcept { return stream; }
		// Values use native byte order and representation. A short scalar/string
		// read reports OutOfRange; bytes already consumed remain consumed.
		cc::io::Result<uint8_t> readByte() const;
		cc::io::IoResult readBytes(void* outBuffer, size_t length) const;
		// On failure, value contains only the prefix actually read, never padding.
		cc::io::Result<std::string> readString(size_t length) const;
		cc::io::Result<int16_t> readInt16() const;
		cc::io::Result<uint16_t> readUInt16() const;
		cc::io::Result<int32_t> readInt32() const;
		cc::io::Result<uint32_t> readUInt32() const;
		cc::io::Result<int64_t> readInt64() const;
		cc::io::Result<uint64_t> readUInt64() const;
		cc::io::Result<float> readFloat() const;
		cc::io::Result<double> readDouble() const;

		explicit BinaryReader(cc::io::StreamPtr stream);
	};

	class BinaryWriter
	{
		cc::io::StreamPtr stream;
	public:
		const cc::io::StreamPtr& getStream() const noexcept { return stream; }
		// Values use native byte order and representation. Results retain partial
		// byte counts and terminal status; failure does not roll back prior writes.
		cc::io::IoResult writeByte(uint8_t value) const;
		cc::io::IoResult writeBytes(const void* buffer, size_t length) const;
		cc::io::IoResult writeString(const std::string& value) const;
		cc::io::IoResult writeInt16(int16_t value) const;
		cc::io::IoResult writeUInt16(uint16_t value) const;
		cc::io::IoResult writeInt32(int32_t value) const;
		cc::io::IoResult writeUInt32(uint32_t value) const;
		cc::io::IoResult writeInt64(int64_t value) const;
		cc::io::IoResult writeUInt64(uint64_t value) const;
		cc::io::IoResult writeFloat(float value) const;
		cc::io::IoResult writeDouble(double value) const;

		explicit BinaryWriter(cc::io::StreamPtr stream);
	};
}
