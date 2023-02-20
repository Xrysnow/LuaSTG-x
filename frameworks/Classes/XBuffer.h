#pragma once
#include "cocos2d.h"

namespace lstg
{
	class Buffer : public cocos2d::Ref
	{
		Buffer();
		virtual ~Buffer();

		std::vector<uint8_t> buffer;
		bool canWrite = true;
		bool canAppend = true;
		bool canShrink = true;
	public:
		using value_type = uint8_t;

		static Buffer* create(size_t size = 0);
		static Buffer* createFromString(const std::string& s);
		Buffer* clone() const;

		void setWritable(bool b);
		void setAppendable(bool b);
		void setShrinkable(bool b);
		void setResizable(bool b);

		bool isWritable() const;
		bool isAppendable() const;
		bool isShrinkable() const;
		bool isResizable() const;

		std::string to_string() const;
		uint8_t* data() const;

		void copy(Buffer* other);
		void move(Buffer* other);

		void assign(Buffer* other, size_t first, size_t last);
		void assign_value(size_t count, uint8_t value);
		void assign_values(const std::vector<uint8_t>& values);

		uint8_t at(size_t index) const;
		void set(size_t index, uint8_t value);
		void set_values(size_t pos, const std::vector<uint8_t>& values);

		uint8_t front() const;
		uint8_t back() const;

		bool empty() const;
		size_t size() const;

		void reserve(size_t size);
		size_t capacity() const;
		void shrink_to_fit();

		void clear();
		void insert(size_t pos, Buffer* other, size_t first, size_t last);
		void insert_value(size_t pos, size_t count, uint8_t value);
		void insert_values(size_t pos, const std::vector<uint8_t>& values);
		void insert_data(size_t pos, const char* data, size_t size);
		void erase(size_t first, size_t last);
		void push_back(uint8_t value);
		void pop_back();
		void resize(size_t size, uint8_t value = 0);
		void swap(Buffer* other);

	protected:
		bool init(size_t size);
		bool check_index(size_t index) const { return index < buffer.size(); }
		bool check_pos(size_t index) const { return index <= buffer.size(); }
	};

	class BufferStreamBuf : public std::streambuf
	{
		using traits = std::char_traits<char>;
		void init(Buffer* buffer);
	public:
		BufferStreamBuf();
		explicit BufferStreamBuf(size_t reserve);
		explicit BufferStreamBuf(Buffer* buffer);
		~BufferStreamBuf() noexcept override;
		Buffer* buffer() const { return _buf; }
	protected:
		int_type overflow(int_type ch) override;
		//int_type pbackfail(int_type) override;
		//std::streamsize showmanyc() override;
		//int_type underflow() override;
		//int_type uflow() override;
		std::streamsize xsgetn(char* s, std::streamsize count) override;
		std::streamsize xsputn(const char* s, std::streamsize count) override;
		pos_type seekoff(off_type, std::ios_base::seekdir, std::ios_base::openmode) override;
		pos_type seekpos(pos_type, std::ios_base::openmode) override;
		//basic_streambuf* setbuf(char*, std::streamsize) override;
		//int sync() override;
		//void imbue(const std::locale&) override;

		void pupdate(std::streamsize offset);
		void gupdate(std::streamsize offset);
		ptrdiff_t poff() const;
		ptrdiff_t goff() const;
		Buffer* _buf = nullptr;
	};
}
