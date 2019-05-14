#include "XBuffer.h"

std::vector<uint8_t> vec;
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
