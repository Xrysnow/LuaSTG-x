#pragma once
#include "XStream.h"

namespace lstg
{
	class BinaryReader
	{
	private:
		Stream* stream;
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
		~BinaryReader();
	};

	class BinaryWriter
	{
	private:
		Stream* stream;
	public:

		Stream* getStream() const;

		void writeByte(uint8_t Value) const;

		void writeBytes(uint8_t* Buffer, uint64_t Length) const;

		void writeString(const std::string& value) const;

		void writeInt16(int16_t Value) const;

		void writeUInt16(uint16_t Value) const;

		void writeInt32(int32_t Value) const;

		void writeUInt32(uint32_t Value) const;

		void writeInt64(int64_t Value) const;

		void writeUInt64(uint64_t Value) const;

		void writeFloat(float Value) const;

		void writeDouble(double Value) const;

		BinaryWriter(Stream* pStream);
		~BinaryWriter();
	};
}
