#include "XBinaryHelper.h"
#include <new>
#include <stdexcept>

using namespace std;
using namespace lstg;
using namespace cocos2d::io;

namespace
{
	StreamError readError(const IoResult& result)
	{
		if (result.error)
			return result.error;
		switch (result.status)
		{
		case IoStatus::EndOfStream: return {ErrorCode::OutOfRange};
		case IoStatus::WouldBlock: return {ErrorCode::WouldBlock};
		case IoStatus::Cancelled: return {ErrorCode::Cancelled};
		case IoStatus::Timeout: return {ErrorCode::Timeout};
		default: return {ErrorCode::InvalidBackend};
		}
	}

	template<class T>
	Result<T> readValue(Stream& stream)
	{
		T value{};
		const auto result = stream.readExact(&value, sizeof value);
		if (!result)
			return Result<T>::failure(readError(result));
		return Result<T>::success(value);
	}
}

BinaryReader::BinaryReader(StreamPtr pStream)
	: stream(std::move(pStream))
{
	if (!stream || !stream->isOpen() || !hasCapability(stream->capabilities(), Capability::Read))
		throw invalid_argument("invalid stream in BinaryReader");
}

Result<uint8_t> BinaryReader::readByte() const { return readValue<uint8_t>(*stream); }
Result<int16_t> BinaryReader::readInt16() const { return readValue<int16_t>(*stream); }
Result<uint16_t> BinaryReader::readUInt16() const { return readValue<uint16_t>(*stream); }
Result<int32_t> BinaryReader::readInt32() const { return readValue<int32_t>(*stream); }
Result<uint32_t> BinaryReader::readUInt32() const { return readValue<uint32_t>(*stream); }
Result<int64_t> BinaryReader::readInt64() const { return readValue<int64_t>(*stream); }
Result<uint64_t> BinaryReader::readUInt64() const { return readValue<uint64_t>(*stream); }
Result<float> BinaryReader::readFloat() const { return readValue<float>(*stream); }
Result<double> BinaryReader::readDouble() const { return readValue<double>(*stream); }

IoResult BinaryReader::readBytes(void* outBuffer, size_t length) const
{
	return stream->readExact(outBuffer, length);
}

Result<string> BinaryReader::readString(size_t length) const
{
	string value;
	try { value.resize(length); }
	catch (const bad_alloc&) { return Result<string>::failure({ErrorCode::OutOfMemory}); }
	catch (const length_error&) { return Result<string>::failure({ErrorCode::Overflow}); }
	const auto result = stream->readExact(value.data(), length);
	if (!result)
	{
		value.resize(result.transferred);
		return {std::move(value), readError(result)};
	}
	return Result<string>::success(std::move(value));
}

BinaryWriter::BinaryWriter(StreamPtr pStream)
	: stream(std::move(pStream))
{
	if (!stream || !stream->isOpen() || !hasCapability(stream->capabilities(), Capability::Write))
		throw invalid_argument("invalid stream in BinaryWriter");
}

IoResult BinaryWriter::writeByte(uint8_t value) const { return stream->writeAll(&value, sizeof value); }
IoResult BinaryWriter::writeInt16(int16_t value) const { return stream->writeAll(&value, sizeof value); }
IoResult BinaryWriter::writeUInt16(uint16_t value) const { return stream->writeAll(&value, sizeof value); }
IoResult BinaryWriter::writeInt32(int32_t value) const { return stream->writeAll(&value, sizeof value); }
IoResult BinaryWriter::writeUInt32(uint32_t value) const { return stream->writeAll(&value, sizeof value); }
IoResult BinaryWriter::writeInt64(int64_t value) const { return stream->writeAll(&value, sizeof value); }
IoResult BinaryWriter::writeUInt64(uint64_t value) const { return stream->writeAll(&value, sizeof value); }
IoResult BinaryWriter::writeFloat(float value) const { return stream->writeAll(&value, sizeof value); }
IoResult BinaryWriter::writeDouble(double value) const { return stream->writeAll(&value, sizeof value); }

IoResult BinaryWriter::writeBytes(const void* buffer, size_t length) const
{
	return stream->writeAll(buffer, length);
}

IoResult BinaryWriter::writeString(const string& value) const
{
	return stream->writeAll(value.data(), value.size());
}
