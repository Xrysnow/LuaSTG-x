#include "XBinaryHelper.h"

using namespace std;
using namespace lstg;

////////////////////////////////////////////////////////////////////////////////

BinaryReader::BinaryReader(Stream* pStream)
	: stream(pStream)
{
	if (!stream)
		throw runtime_error("fcyBinaryReader::fcyBinaryReader");
	stream->retain();
}

BinaryReader::~BinaryReader()
{
	stream->release();
}

Stream* BinaryReader::getStream() const
{
	return stream;
}

uint8_t BinaryReader::readByte() const
{
	uint8_t tRet = 0;
	stream->read((uint8_t*)&tRet, sizeof tRet);
	return tRet;
}

void BinaryReader::readBytes(uint8_t* outBuffer, uint64_t length) const
{
	stream->read((uint8_t*)outBuffer, length);
}

std::string BinaryReader::readString(uint64_t length) const
{
	std::string tRet;
	tRet.resize(length);
	stream->read((uint8_t*)tRet.c_str(), length);
	return tRet;
}

int16_t BinaryReader::readInt16() const
{
	int16_t tRet = 0;
	stream->read((uint8_t*)&tRet, sizeof tRet);
	return tRet;
}

uint16_t BinaryReader::readUInt16() const
{
	uint16_t tRet = 0;
	stream->read((uint8_t*)&tRet, sizeof tRet);
	return tRet;
}

int32_t BinaryReader::readInt32() const
{
	int32_t tRet = 0;
	stream->read((uint8_t*)&tRet, sizeof tRet);
	return tRet;
}

uint32_t BinaryReader::readUInt32() const
{
	uint32_t tRet = 0;
	stream->read((uint8_t*)&tRet, sizeof tRet);
	return tRet;
}

int64_t BinaryReader::readInt64() const
{
	int64_t tRet = 0;
	stream->read((uint8_t*)&tRet, sizeof tRet);
	return tRet;
}

uint64_t BinaryReader::readUInt64() const
{
	uint64_t tRet = 0;
	stream->read((uint8_t*)&tRet, sizeof tRet);
	return tRet;
}

float BinaryReader::readFloat() const
{
	float tRet = 0;
	stream->read((uint8_t*)&tRet, sizeof tRet);
	return tRet;
}

double BinaryReader::readDouble() const
{
	double tRet = 0;
	stream->read((uint8_t*)&tRet, sizeof tRet);
	return tRet;
}

////////////////////////////////////////////////////////////////////////////////

BinaryWriter::BinaryWriter(Stream* pStream)
	: stream(pStream)
{
	if (!stream||!stream->isWritable())
		throw runtime_error("fcyBinaryWriter::fcyBinaryWriter");
	stream->retain();
}

BinaryWriter::~BinaryWriter()
{
	stream->release();
}

Stream* BinaryWriter::getStream() const
{
	return stream;
}

void BinaryWriter::writeByte(uint8_t Value) const
{
	stream->write((uint8_t*)&Value, sizeof Value);
}

void BinaryWriter::writeBytes(uint8_t* Buffer, uint64_t Length) const
{
	stream->write((uint8_t*)Buffer, Length);
}

void BinaryWriter::writeString(const std::string& value) const
{
	stream->write((uint8_t*)value.c_str(), value.size());
}

void BinaryWriter::writeInt16(int16_t Value) const
{
	stream->write((uint8_t*)&Value, sizeof Value);
}

void BinaryWriter::writeUInt16(uint16_t Value) const
{
	stream->write((uint8_t*)&Value, sizeof Value);
}

void BinaryWriter::writeInt32(int32_t Value) const
{
	stream->write((uint8_t*)&Value, sizeof Value);
}

void BinaryWriter::writeUInt32(uint32_t Value) const
{
	stream->write((uint8_t*)&Value, sizeof Value);
}

void BinaryWriter::writeInt64(int64_t Value) const
{
	stream->write((uint8_t*)&Value, sizeof Value);
}

void BinaryWriter::writeUInt64(uint64_t Value) const
{
	stream->write((uint8_t*)&Value, sizeof Value);
}

void BinaryWriter::writeFloat(float Value) const
{
	stream->write((uint8_t*)&Value, sizeof Value);
}

void BinaryWriter::writeDouble(double Value) const
{
	stream->write((uint8_t*)&Value, sizeof Value);
}
