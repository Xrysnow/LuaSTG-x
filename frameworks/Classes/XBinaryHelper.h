#pragma once
#include "XStream.h"

namespace lstg
{
	class BinaryReader
	{
		cocos2d::RefPtr<Stream> stream;
	public:
		Stream* getStream() const;
		uint8_t readByte() const;
		void readBytes(uint8_t* outBuffer, uint64_t length) const;
		std::string readString(uint64_t length) const;
		int16_t readInt16() const;
		uint16_t readUInt16() const;
		int32_t readInt32() const;
		uint32_t readUInt32() const;
		int64_t readInt64() const;
		uint64_t readUInt64() const;
		float readFloat() const;
		double readDouble() const;

		BinaryReader(Stream* pStream);
	};

	class BinaryWriter
	{
		cocos2d::RefPtr<Stream> stream;
	public:
		Stream* getStream() const;
		void writeByte(uint8_t value) const;
		void writeBytes(const uint8_t* buffer, uint64_t length) const;
		void writeString(const std::string& value) const;
		void writeInt16(int16_t value) const;
		void writeUInt16(uint16_t value) const;
		void writeInt32(int32_t value) const;
		void writeUInt32(uint32_t value) const;
		void writeInt64(int64_t value) const;
		void writeUInt64(uint64_t value) const;
		void writeFloat(float value) const;
		void writeDouble(double value) const;

		BinaryWriter(Stream* pStream);
	};
}
