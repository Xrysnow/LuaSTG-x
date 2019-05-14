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
		static Buffer* create(size_t size = 0);
		static Buffer* createFromString(const std::string& s);
		Buffer* clone() const;

		void setWritable(bool b);
		void setAppendable(bool b);
		void setShrinkable(bool b);

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
}

namespace cocos2d
{
	template<>
	class ResizableBufferAdapter<lstg::Buffer> : public ResizableBuffer {
		typedef lstg::Buffer BufferType;
		BufferType* _buffer;
	public:
		explicit ResizableBufferAdapter(BufferType* buffer) : _buffer(buffer) {}
		virtual void resize(size_t size) override {
			_buffer->resize(size);
		}
		virtual void* buffer() const override {
			if (_buffer->empty())
				return nullptr;
			return _buffer->data();
		}
	};

}
