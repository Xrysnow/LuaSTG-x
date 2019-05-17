#include "XStream.h"
#include <algorithm>

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

bool Stream::fill(Stream* src, Stream* dst, uint64_t length, size_t bufferSize)
{
	uint8_t* buffer = new uint8_t[bufferSize];
	uint64_t read = 0;
	uint64_t total = 0;
	while (total != length && (src->read(buffer,
		(length - total > bufferSize) ? bufferSize : length - total, &read)))
	{
		total += read;
		dst->write(buffer, read);
	}
	delete[] buffer;
	return total == length;
}

////////////////////////////////////////////////////////////////////////////////

bool StreamFile::resize(uint64_t /*Length*/)
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

uint8_t* StreamMemory::getInternalBuffer()
{
	return (uint8_t*)_data->getBytes();
}

bool StreamMemory::resize(uint64_t length)
{
	if(resizable)
	{
		if (length == _size) return true;
		auto buf = malloc(length);
		if (!buf)
			return false;
		auto new_data = new cocos2d::Data();
		new_data->fastSet((unsigned char*)buf, length);
		memcpy(new_data->getBytes(), _data->getBytes(), min(_size, length));
		// resizable means isOwner
		//if (!isOwner)
		//	data->fastSet(nullptr, 0);
		delete _data;
		_data = new_data;
		_size = length;
		if(pos > _size)
			pos = _size;
		return true;
	}
	return false;
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
		pos = _size;
		break;
	default:
		return false;
	}
	if (offset < 0 && uint64_t(-offset) > pos)
	{
		pos = 0;
		return false;
	}
	else if (offset > 0 && offset + pos >= _size)
	{
		pos = _size;
		return false;
	}
	pos += offset;
	return true;
}

bool StreamMemory::read(uint8_t* dst, uint64_t length, uint64_t* bytesRead)
{
	if (bytesRead) *bytesRead = 0;
	if(length == 0) return true;
	if(!dst) return false;

	const uint64_t rest_size = _size - pos;
	if(rest_size == 0) return false;

	const size_t real_read = min(length, rest_size);
	memcpy(dst, getInternalBuffer() + pos, real_read);
	pos += real_read;
	if (bytesRead) *bytesRead = real_read;

	return rest_size >= length;
}

bool StreamMemory::write(const uint8_t* src, uint64_t length, uint64_t* bytesWrite)
{
	if(!writable)
		return false;
	
	if(bytesWrite) *bytesWrite = 0;
	if(length == 0) return true;
	if(!src) return false;

	uint64_t tRestSize = _size - pos;

	if(tRestSize < length)
	{
		if(!resizable)
		{
			if(tRestSize == 0)
				return false;
			memcpy(getInternalBuffer() + pos, src, (size_t)tRestSize);
			pos += tRestSize;
			if (bytesWrite) *bytesWrite = tRestSize;
			return false;
		}
		else
		{
			auto ret = resize(max(uint64_t(_size*1.5f), _size + length - tRestSize));
			if (!ret)
				return ret;
		}
	}
	memcpy(getInternalBuffer() + pos, src, (size_t)length);
	pos += length;
	if(bytesWrite) *bytesWrite = length;
	return true;
}

StreamMemory* StreamMemory::create(uint8_t* src, uint64_t size, bool copy, bool canWrite, bool canResize)
{
	auto ret = new (nothrow) StreamMemory();
	if (ret&&ret->initWithBuffer(src, size, copy, canWrite, canResize))
	{
		return ret;
	}
	delete ret;
	return nullptr;
}

StreamMemory* StreamMemory::create(cocos2d::Data* src, uint64_t size, bool copy, bool canWrite)
{
	auto ret = new (nothrow) StreamMemory();
	if (ret&&ret->initWithData(src, size, copy, canWrite))
	{
		return ret;
	}
	delete ret;
	return nullptr;
}

bool StreamMemory::initWithBuffer(uint8_t* src, uint64_t length, bool copy, bool canWrite, bool canResize)
{
	isOwner = copy;
	resizable = canResize && copy;
	writable = canWrite;
	_data = new cocos2d::Data();
	if (copy && src)
		_data->copy(src, length);
	else if (src)
		_data->fastSet(src, length);
	else
		_data->fastSet((unsigned char*)malloc(length), length);
	if (!_data->getBytes())
		return false;
	_size = length;
	return true;
}

bool StreamMemory::initWithData(cocos2d::Data* src, uint64_t length, bool copy, bool canWrite)
{
	isOwner = copy;
	resizable = copy;
	writable = canWrite;
	_data = new cocos2d::Data();
	if (length == 0) length = src->getSize();
	if (copy&&src)
		_data->copy(src->getBytes(), length);
	else if (src)
		_data->fastSet(src->getBytes(), length);
	else
		_data->fastSet((unsigned char*)malloc(length), length);
	if (!_data->getBytes())
		return false;
	_size = length;
	return true;
}

StreamMemory::StreamMemory()
{
}

StreamMemory::~StreamMemory()
{
	if (_data)
	{
		if (!isOwner)
			_data->fastSet(nullptr, 0);
		delete _data;
	}
}

