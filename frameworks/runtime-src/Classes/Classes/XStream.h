#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <mutex>
#include "base/CCData.h"
#include "base/CCRef.h"
#include "../Audio/AudioStream.h"

namespace lstg
{
	class Stream : public cocos2d::Ref
	{
	public:

		enum SeekOrigin
		{
			/** Seek from the beginning. */
			BEG = 0,
			/** Seek from current position. */
			CUR = 1,
			/** Seek from the end. */
			END = 2
		};

		Stream() = default;
		virtual ~Stream() = default;

		/** If the stream is writable. */
		virtual bool isWritable() { return writable; }

		/** If the stream is resizable. */
		virtual bool isResizable() { return resizable; }

		/** Size of the stream. */
		virtual uint64_t size() { return _size; }

		/** Resize the stream. */
		virtual bool resize(uint64_t size) = 0;

		/** Get the position to read or write. */
		virtual uint64_t tell() { return pos; }

		/** Set the position to read or write. */
		virtual bool seek(SeekOrigin Origin, int64_t Offset) = 0;

		/**
		 * Read bytes from the stream.
		 * @param[in]  dst      target buffer
		 * @param[in]  length     length to read
		 * @param[out] bytesRead length actually read, can be NULL
		 */
		virtual bool read(uint8_t* dst, uint64_t length, uint64_t* bytesRead = nullptr) = 0;

		/**
		 * Write bytes to the stream.
		 * @param[in]  src        source buffer
		 * @param[in]  length      length to write
		 * @param[out] bytesWrite length actually write, can be NULL
		 */
		virtual bool write(const uint8_t* src, uint64_t length, uint64_t* bytesWrite = nullptr) = 0;

		/**
		 * Lock the stream. It is necessary when used in multi-thread.
		 *
		 * @note May cause block.
		 */
		virtual void lock();

		/**
		 * Try to lock the stream, will return false when already locked.
		 *
		 * This function will not block.
		 */
		virtual bool tryLock();

		/**
		 * Unlock the stream.
		 */
		virtual void unlock();
	protected:
		uint64_t _size = 0;
		uint64_t pos = 0;
		bool resizable = false;
		bool writable = false;
	private:
		std::mutex mut;

	public:
		/** Read from src and write to dst. */
		static bool fill(Stream* src, Stream* dst, uint64_t length, size_t bufferSize);

		Stream(const Stream &) = delete;
		Stream &operator =(const Stream &) = delete;
	};

	class StreamFile :
		public Stream
	{
	private:
		std::fstream file;
		std::string _path;
	public:
		bool resize(uint64_t length) override;
		bool seek(SeekOrigin origin, int64_t offset) override;
		bool read(uint8_t* dst, uint64_t length, uint64_t* bytesRead) override;
		bool write(const uint8_t* src, uint64_t length, uint64_t* bytesWrite) override;

		static StreamFile* create(const std::string& path, bool canWrite);
	protected:

		bool init(const std::string& path, bool canWrite);
		StreamFile();
		virtual ~StreamFile();
	};

	class StreamMemory :
		public Stream
	{
	private:
		cocos2d::Data* _data = nullptr;
		bool isOwner;
	public:
		bool resize(uint64_t length) override;
		uint64_t tell() override;
		bool seek(SeekOrigin origin, int64_t offset) override;
		bool read(uint8_t* dst, uint64_t length, uint64_t* bytesRead) override;
		bool write(const uint8_t* src, uint64_t length, uint64_t* bytesWrite) override;

		uint8_t* getInternalBuffer();

		/** src can be NULL */
		static StreamMemory* create(uint8_t* src, uint64_t size, bool copy = true, bool canWrite = false, bool canResize = false);
		static StreamMemory* create(cocos2d::Data* src, uint64_t size = 0, bool copy = true, bool canWrite = false);
	protected:
		bool initWithBuffer(uint8_t* src, uint64_t length, bool copy, bool canWrite, bool canResize);
		bool initWithData(cocos2d::Data* src, uint64_t length, bool copy, bool canWrite);

		StreamMemory();
		~StreamMemory();
	};

	//TODO: StreamZip, StreamNetwork

	class XAudioStream : public xAudio::AudioStream
	{
		Stream* _src = nullptr;
	public:
		static XAudioStream* create(Stream* src) {
			if (!src)
				return nullptr;
			auto ret = new (std::nothrow) XAudioStream();
			if (ret)
			{
				ret->_src = src;
				ret->_src->retain();
				ret->autorelease();
				return ret;
			}
			return nullptr;
		}
		virtual ~XAudioStream() { if (_src)_src->release(); }

		uint64_t size() override { return _src->size(); }
		uint64_t tell() override { return _src->tell(); }
		bool seek(SeekOrigin origin, int64_t offset) override {
			auto ori = Stream::BEG;
			switch (origin) {
			case SeekOrigin::BEGINNING: break;
			case SeekOrigin::CURRENT: ori = Stream::CUR; break;
			case SeekOrigin::END: ori = Stream::END; break;
			default: return false;
			}
			return _src->seek(ori, offset);
		}
		bool read(uint8_t* dst, uint64_t length, uint64_t* bytesRead) override {
			return _src->read(dst, length, bytesRead);
		}
		void lock() override { _src->lock(); }
		void unlock() override { _src->unlock(); }
	};
}
