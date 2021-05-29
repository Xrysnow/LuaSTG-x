#include "XStream.h"
#include <algorithm>
#include <cstring>

using namespace std;
using namespace lstg;

void Stream::lock()
{
	mut.lock();
}

bool Stream::tryLock()
{
	return mut.try_lock();
}

void Stream::unlock()
{
	mut.unlock();
}

bool Stream::fill(Stream* dst, uint64_t length, Buffer* buffer)
{
	if (!buffer)
		buffer = Buffer::create(4096);
	if (!buffer || buffer->empty())
		return false;
	uint64_t read = 0;
	uint64_t total = 0;
	while (total != length && (this->read(buffer->data(),
		(length - total > buffer->size()) ? buffer->size() : length - total, &read)))
	{
		total += read;
		dst->write(buffer->data(), read);
	}
	return total == length;
}

////////////////////////////////////////////////////////////////////////////////

bool StreamFile::resize(uint64_t /*length*/)
{
	return false;
}

bool StreamFile::seek(SeekOrigin origin, int64_t offset)
{
	auto tOrigin = ios::cur;
	switch(origin)
	{
	case CUR:
		tOrigin = ios::cur;
		break;
	case BEG:
		tOrigin = ios::beg;
		break;
	case END:
		tOrigin = ios::end;
		break;
	default:
		return false;
	}
	auto last_pos = tell();
	file.seekg(offset, tOrigin);
	if (writable)
		file.seekp(offset, tOrigin);

	if(file.fail())
	{
		file.clear();
		seek(BEG, last_pos);
		return false;
	}
	pos = file.tellg();
	return true;
}

bool StreamFile::read(uint8_t* dst, uint64_t length, uint64_t* bytesRead)
{
	if (bytesRead)*bytesRead = 0;
	if(length == 0)
		return true;
	if(!dst)
		return false;
	file.read((char*)dst, length);
	uint64_t real_read = file.gcount();
	pos += real_read;
	if (bytesRead)*bytesRead = real_read;
	return length == real_read;
}

bool StreamFile::write(const uint8_t* src, uint64_t length, uint64_t* bytesWrite)
{
	if (bytesWrite)*bytesWrite = 0;
	if(!writable)
		return false;
	if(length == 0)
		return true;
	if(!src)
		return false;
	file.write((char*)src, length);
	if (file.fail())
	{
		file.clear();
		return false;
	}
	pos = file.tellp();
	if (bytesWrite)*bytesWrite = length;

	// update size
	file.seekg(0, std::fstream::end);
	_size = file.tellg();
	file.seekg(pos, ios::beg);
	return true;
}

StreamFile* StreamFile::create(const string& path, bool canWrite)
{
	auto ret = new (nothrow) StreamFile();
	if (ret&&ret->init(path, canWrite))
	{
		return ret;
	}
	delete ret;
	return nullptr;
}

bool StreamFile::init(const std::string& path, bool canWrite)
{
	_path = path;
	writable = canWrite;
	auto flag = ios::in | ios::binary;
	if (writable)
		flag = flag | ios::out;
	file.open(_path, flag);
	if (!file.is_open())
		return false;
	file.seekg(0, std::fstream::end);
	_size = file.tellg();
	file.seekg(0);
	return file.is_open();
}

StreamFile::StreamFile()
{
}

StreamFile::~StreamFile()
{
	file.close();
}

////////////////////////////////////////////////////////////////////////////////

uint8_t* StreamMemory::data()
{
	return _buffer->data();
}

bool StreamMemory::isWritable()
{
	return _buffer->isWritable();
}

bool StreamMemory::isResizable()
{
	return _buffer->isResizable();
}

uint64_t StreamMemory::size()
{
	return _buffer->size();
}

bool StreamMemory::resize(uint64_t length)
{
	if(!isResizable())
		return false;
	if (length == size())
		return true;
	_buffer->resize(length);
	if(pos > size())
		pos = size();
	return true;
}

uint64_t StreamMemory::tell()
{
	return pos;
}

bool StreamMemory::seek(SeekOrigin origin, int64_t offset)
{
	switch(origin)
	{
	case CUR:
		break;
	case BEG:
		pos = 0;
		break;
	case END:
		pos = size();
		break;
	default:
		return false;
	}
	if (offset < 0 && -offset > pos)
	{
		pos = 0;
		return false;
	}
	else if (offset > 0 && offset + pos >= size())
	{
		pos = size();
		return false;
	}
	pos += offset;
	return true;
}

bool StreamMemory::read(uint8_t* dst, uint64_t length, uint64_t* bytesRead)
{
	if (bytesRead)
		*bytesRead = 0;
	if(length == 0)
		return true;
	if(!dst)
		return false;

	const int64_t rest_size = (int64_t)size() - (int64_t)pos;
	if(rest_size <= 0)
		return false;

	const size_t real_read = std::min(length, (uint64_t)rest_size);
	memcpy(dst, data() + pos, real_read);
	pos += real_read;
	if (bytesRead)
		*bytesRead = real_read;

	return rest_size >= length;
}

bool StreamMemory::write(const uint8_t* src, uint64_t length, uint64_t* bytesWrite)
{
	if(!isWritable())
		return false;
	
	if(bytesWrite)
		*bytesWrite = 0;
	if(length == 0)
		return true;
	if(!src)
		return false;

	const uint64_t rest_size = size() - pos;

	if(rest_size < length)
	{
		if(!isResizable())
		{
			if(rest_size == 0)
				return false;
			memcpy(data() + pos, src, (size_t)rest_size);
			pos += rest_size;
			if (bytesWrite)
				*bytesWrite = rest_size;
			return false;
		}
		else
		{
			if (!resize(size() + length - rest_size))
				return false;
		}
	}
	memcpy(data() + pos, src, (size_t)length);
	pos += length;
	if(bytesWrite)
		*bytesWrite = length;
	return true;
}

StreamMemory* StreamMemory::create(Buffer* src, bool copy)
{
	auto ret = new (nothrow) StreamMemory();
	if (ret&&ret->init(src, copy))
	{
		return ret;
	}
	delete ret;
	return nullptr;
}

bool StreamMemory::init(Buffer* src, bool copy)
{
	if (src)
		_buffer = copy ? src->clone() : src;
	else
		_buffer = Buffer::create();
	if (!_buffer)
		return false;
	CC_SAFE_RETAIN(_buffer);
	return true;
}

StreamMemory::StreamMemory()
{
}

StreamMemory::~StreamMemory()
{
	CC_SAFE_RELEASE(_buffer);
}

// implemente audio stream creator

#include "../LSTG/ResourceMgr.h"
#include "../Audio/AudioSoundData.h"

audio::Stream* audio::Stream::createFromFile(const std::string& path)
{
	const auto buffer = LRES.getBufferFromFile(path);
	if (!buffer)
		return nullptr;
	return XAudioStream::create(lstg::StreamMemory::create(buffer));
}

audio::Stream* audio::Stream::createFromLocalFile(const std::string& path)
{
	return XAudioStream::create(lstg::StreamFile::create(path, false));
}

audio::Stream* audio::Stream::createFromStringData(const std::string& str)
{
	const auto buffer = lstg::Buffer::createFromString(str);
	if (!buffer)
		return nullptr;
	return XAudioStream::create(lstg::StreamMemory::create(buffer));
}

audio::Stream* audio::Stream::createFromSoundData(audio::SoundData* soundData)
{
	if (!soundData)
		return nullptr;
	const auto s = lstg::StreamMemory::create();
	if (!s)
		return nullptr;
	if (!s->resize(soundData->getSize()))
		return nullptr;
	// copy data
	if (!s->write((const uint8_t*)soundData->getData(), soundData->getSize(), nullptr))
		return nullptr;
	return XAudioStream::create(s);
}
