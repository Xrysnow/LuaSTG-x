#include "XBuffer.h"
#include <cstring>

using namespace lstg;

Buffer::Buffer()
{
}

Buffer::~Buffer()
{
}

Buffer* Buffer::create(size_t size)
{
	auto ret = new (std::nothrow) Buffer();
	if (ret&&ret->init(size))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

Buffer* Buffer::createFromString(const std::string& s)
{
	auto ret = new (std::nothrow) Buffer();
	if (ret&&ret->init(0))
	{
		ret->autorelease();
		ret->buffer.assign(s.begin(), s.end());
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

Buffer* Buffer::clone() const
{
	auto ret = create();
	if (!ret)
		return nullptr;
	ret->buffer = buffer;
	return ret;
}

void Buffer::setWritable(bool b)
{
	canWrite = b;
}

void Buffer::setAppendable(bool b)
{
	canAppend = b;
}

void Buffer::setShrinkable(bool b)
{
	canShrink = b;
}

void Buffer::setResizable(bool b)
{
	canAppend = b;
	canShrink = b;
}

bool Buffer::isWritable() const
{
	return canWrite;
}

bool Buffer::isAppendable() const
{
	return canAppend;
}

bool Buffer::isShrinkable() const
{
	return canShrink;
}

bool Buffer::isResizable() const
{
	return canAppend && canShrink;
}

std::string Buffer::to_string() const
{
	return buffer.empty() ? "" : std::string((char*)buffer.data(), buffer.size());
}

uint8_t* Buffer::data() const
{
	return buffer.empty() ? nullptr: (uint8_t*)buffer.data();
}

void Buffer::copy(Buffer* other)
{
	if (!isWritable() || !isResizable())
		return;
	if (other && other != this)
		buffer = other->buffer;
}

void Buffer::move(Buffer* other)
{
	if (!isWritable() || !isResizable())
		return;
	if (other && other != this)
	{
		clear();
		std::swap(buffer, other->buffer);
	}
}

void Buffer::assign(Buffer* other, size_t first, size_t last)
{
	if (!isWritable() || !isResizable())
		return;
	if (!other || !other->check_pos(first) || !other->check_pos(last))
		return;
	if (first <= last)
		return;
	const auto beg = other->buffer.begin();
	buffer.assign(beg + first, beg + last);
}

void Buffer::assign_value(size_t count, uint8_t value)
{
	if (!isWritable() || !isResizable())
		return;
	buffer.assign(count, value);
}

void Buffer::assign_values(const std::vector<uint8_t>& values)
{
	if (!isWritable() || !isResizable())
		return;
	buffer = values;
}

uint8_t Buffer::at(size_t index) const
{
	if (!check_index(index))
		return 0;
	return buffer[index];
}

void Buffer::set(size_t index, uint8_t value)
{
	if (!isWritable())
		return;
	if (!check_index(index))
		return;
	buffer[index] = value;
}

void Buffer::set_values(size_t pos, const std::vector<uint8_t>& values)
{
	if (!isWritable())
		return;
	if (!check_pos(pos))
		return;
	auto end = pos + values.size();
	if (end > size())
	{
		if (canAppend)
			resize(end);
		else
			end = size();
	}
	for (auto i = pos; i < end; ++i)
	{
		buffer[i] = values[i - pos];
	}
}

uint8_t Buffer::front() const
{
	return buffer.empty() ? 0 : buffer.front();
}

uint8_t Buffer::back() const
{
	return buffer.empty() ? 0 : buffer.back();
}

bool Buffer::empty() const
{
	return buffer.empty();
}

size_t Buffer::size() const
{
	return buffer.size();
}

void Buffer::reserve(size_t size)
{
	if (size > buffer.size() && !canAppend)
		return;
	buffer.reserve(size);
}

size_t Buffer::capacity() const
{
	return buffer.capacity();
}

void Buffer::shrink_to_fit()
{
	buffer.shrink_to_fit();
}

void Buffer::clear()
{
	if (!isWritable() || !canShrink)
		return;
	buffer.clear();
}

void Buffer::insert(size_t pos, Buffer* other, size_t first, size_t last)
{
	if (!isWritable() || !canAppend)
		return;
	if (!other || !other->check_pos(first) || !other->check_pos(last))
		return;
	if (!check_pos(pos) || first <= last)
		return;
	const auto beg = other->buffer.begin();
	buffer.insert(buffer.begin() + pos, beg + first, beg + last);
}

void Buffer::insert_value(size_t pos, size_t count, uint8_t value)
{
	if (!isWritable() || !canAppend)
		return;
	if (!check_pos(pos) || count == 0)
		return;
	buffer.insert(buffer.begin() + pos, count, value);
}

void Buffer::insert_values(size_t pos, const std::vector<uint8_t>& values)
{
	if (!isWritable() || !canAppend)
		return;
	if (!check_pos(pos) || values.empty())
		return;
	buffer.insert(buffer.begin() + pos, values.begin(), values.end());
}

void Buffer::insert_data(size_t pos, const char* data, size_t size)
{
	if (!isWritable() || !canAppend)
		return;
	if (!check_pos(pos) || !data || !size)
		return;
	buffer.insert(buffer.begin() + pos, (const uint8_t*)data, (const uint8_t*)data + size);
}

void Buffer::erase(size_t first, size_t last)
{
	if (!isWritable() || !canShrink)
		return;
	if (first <= last)
		return;
	const auto beg = buffer.begin();
	buffer.erase(beg + first, beg + last);
}

void Buffer::push_back(uint8_t value)
{
	if (!canAppend)
		return;
	buffer.push_back(value);
}

void Buffer::pop_back()
{
	if (!canShrink)
		return;
	if (!buffer.empty())
		buffer.pop_back();
}

void Buffer::resize(size_t size, uint8_t value)
{
	if (size > buffer.size() && !canAppend)
		return;
	if (size < buffer.size() && !canShrink)
		return;
	if (value == 0)
		buffer.resize(size);
	else
		buffer.resize(size, value);
}

void Buffer::swap(Buffer* other)
{
	if (!isWritable() || !isResizable())
		return;
	if (!other)
		return;
	buffer.swap(other->buffer);
}

bool Buffer::init(size_t size)
{
	try
	{
		buffer.resize(size);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

void BufferStreamBuf::init(Buffer* buffer)
{
	_buf = buffer;
	CC_SAFE_RETAIN(_buf);
	pupdate(0);
	gupdate(0);
}

BufferStreamBuf::BufferStreamBuf()
{
	init(Buffer::create());
}

BufferStreamBuf::BufferStreamBuf(size_t reserve)
{
	init(Buffer::create());
	if (_buf)
		_buf->reserve(reserve);
}

BufferStreamBuf::BufferStreamBuf(Buffer* buffer)
{
	init(buffer);
}

BufferStreamBuf::~BufferStreamBuf() noexcept
{
	CC_SAFE_RELEASE(_buf);
}

std::basic_streambuf<char>::int_type BufferStreamBuf::overflow(int_type ch)
{
	if (!_buf || !_buf->isWritable())
		return traits::eof();
	if (traits::eq_int_type(traits::eof(), ch))
		return traits::not_eof(ch);
	const auto value = (uint8_t)traits::to_char_type(ch);
	const auto p_off = poff();
	if (p_off < _buf->size())
	{
		pbump(1);
		_buf->set((size_t)p_off, value);
		return ch;
	}
	if(_buf->isAppendable())
	{
		_buf->push_back(value);
		pupdate(p_off + 1);
		gupdate(goff());
	}
	return ch;
}

std::streamsize BufferStreamBuf::xsgetn(char* s, std::streamsize count)
{
	if (!_buf)
		return 0;
	const auto g_off = goff();
	const auto avail = (std::streamsize)_buf->size() - g_off;
	if (avail <= 0)
		return 0;
	count = std::min(count, avail);
	std::memcpy(s, _buf->data() + g_off, count);
	gupdate(g_off + count);
	return count;
}

std::streamsize BufferStreamBuf::xsputn(const char* s, std::streamsize count)
{
	if (!_buf || !_buf->isWritable())
		return 0;
	const auto p_off = poff();
	if (p_off + count > _buf->size())
	{
		if (_buf->isResizable())
		{
			_buf->resize(p_off + count);
			gupdate(goff());
		}
		else
		{
			count = std::max((std::streamsize)_buf->size() - p_off, (std::streamsize)0);
		}
	}
	std::memcpy(_buf->data() + p_off, s, count);
	pupdate(p_off + count);
	return count;
}

std::basic_streambuf<char>::pos_type BufferStreamBuf::seekoff(
	off_type off, std::ios_base::seekdir dir, std::ios_base::openmode which)
{
	if (!_buf)
		return pos_type(off_type(-1));
	off_type p_off = -1;
	off_type g_off = -1;
	switch (dir)
	{
	case std::ios_base::beg:
		p_off = 0;
		g_off = 0;
		break;
	case std::ios_base::end:
		p_off = _buf->size();
		g_off = _buf->size();
		break;
	case std::ios_base::cur:
		p_off = poff();
		g_off = goff();
		break;
	default:
		return pos_type(off_type(-1));
	}
	bool ok = true;
	if (which & std::ios_base::in)
	{
		g_off += off;
		if (g_off < 0 || g_off >= _buf->size())
			ok = false;
		else
			gupdate(g_off);
	}
	if (which & std::ios_base::out)
	{
		p_off += off;
		if (p_off < 0 || p_off >= _buf->size())
			ok = false;
		else if(ok)
			pupdate(p_off);
	}
	return ok ? pos_type(off) : pos_type(off_type(-1));
}

std::basic_streambuf<char>::pos_type BufferStreamBuf::seekpos(pos_type off, std::ios_base::openmode which)
{
	if (!_buf)
		return pos_type(off_type(-1));
	if (off < 0 || off >= _buf->size())
		return pos_type(off_type(-1));
	if (which & std::ios_base::in)
	{
		gupdate(off);
	}
	if (which & std::ios_base::out)
	{
		pupdate(off);
	}
	return pos_type(off);
}

void BufferStreamBuf::pupdate(std::streamsize offset)
{
	if (!_buf)
		return;
	const auto base = (char*)_buf->data();
	setp(base + offset, base + _buf->size());
}

void BufferStreamBuf::gupdate(std::streamsize offset)
{
	if (!_buf)
		return;
	const auto base = (char*)_buf->data();
	setg(base, base + offset, base + _buf->size());
}

ptrdiff_t BufferStreamBuf::poff() const
{
	return pptr() - pbase();;
}

ptrdiff_t BufferStreamBuf::goff() const
{
	return gptr() - eback();
}
