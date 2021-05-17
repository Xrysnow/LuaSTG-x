#include "XZipArchive.h"
#include <string>
#include <fstream>

using namespace lstg;

static std::unordered_map<int, std::string> LIBZIPPP_ERROR_STRING = {
	{ LIBZIPPP_OK, "" },
	{ LIBZIPPP_ERROR_NOT_OPEN, "NOT_OPEN" },
	{ LIBZIPPP_ERROR_NOT_ALLOWED, "NOT_ALLOWED" },
	{ LIBZIPPP_ERROR_INVALID_ENTRY, "INVALID_ENTRY" },
	{ LIBZIPPP_ERROR_INVALID_PARAMETER, "INVALID_PARAMETER" },
	{ LIBZIPPP_ERROR_MEMORY_ALLOCATION, "MEMORY_ALLOCATION" },
	{ LIBZIPPP_ERROR_FOPEN_FAILURE, "FOPEN_FAILURE" },
	{ LIBZIPPP_ERROR_FREAD_FAILURE, "FREAD_FAILURE" },
	{ LIBZIPPP_ERROR_OWRITE_FAILURE, "OWRITE_FAILURE" },
	{ LIBZIPPP_ERROR_OWRITE_INDEX_FAILURE, "OWRITE_INDEX_FAILURE" },
	{ LIBZIPPP_ERROR_UNKNOWN, "UNKNOWN" },
};
static std::string getLibZipppError(int code)
{
	const auto it = LIBZIPPP_ERROR_STRING.find(code);
	return it == LIBZIPPP_ERROR_STRING.end() ? "UNKNOWN" : it->second;
}

ZipArchive::~ZipArchive()
{
	CC_SAFE_RELEASE(buffer);
	CC_SAFE_DELETE(archive);
}

bool ZipArchive::init(const std::string& path, const std::string& password, Encryption encryptionMethod)
{
	archive = new (std::nothrow) libzippp::ZipArchive(path, password, encryptionMethod);
	return archive;
}

bool ZipArchive::initWithBuffer(Buffer* buffer_, OpenMode mode, bool checkConsistency)
{
	if (!buffer_)
		return false;
	archive = libzippp::ZipArchive::fromBuffer((const char*)buffer_->data(), buffer_->size(), mode, checkConsistency);
	return archive;
}

ZipArchive* ZipArchive::create(const std::string& path, const std::string& password, Encryption encryptionMethod)
{
	const auto ret = new (std::nothrow) ZipArchive();
	if (ret && ret->init(path, password, encryptionMethod))
	{
		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}

ZipArchive* ZipArchive::createFromBuffer(Buffer* buffer, OpenMode mode, bool checkConsistency)
{
	const auto ret = new (std::nothrow) ZipArchive();
	if (ret && ret->initWithBuffer(buffer, mode, checkConsistency))
	{
		ret->autorelease();
		return ret;
	}
	delete ret;
	return nullptr;
}

std::vector<std::string> ZipArchive::getEntries(State state) const
{
	const auto entries = archive->getEntries(state);
	std::vector<std::string> ret;
	ret.reserve(entries.size());
	for (auto& e : entries)
	{
		ret.push_back(e.getName());
	}
	return ret;
}

std::string ZipArchive::getEntryByIndex(int64_t index, State state) const
{
	const auto entry = archive->getEntry(index, state);
	return entry.getName();
}

std::string ZipArchive::getEntryComment(const std::string& entry, State state) const
{
	return archive->getEntryComment(getEntry(entry, state), state);
}

bool ZipArchive::setEntryComment(const std::string& entry, const std::string& comment, State state) const
{
	return archive->setEntryComment(getEntry(entry, state), comment);
}

bool ZipArchive::isEntryCompressionEnabled(const std::string& entry, State state) const
{
	return archive->isEntryCompressionEnabled(getEntry(entry, state));
}

bool ZipArchive::setEntryCompressionEnabled(const std::string& entry, bool value, State state) const
{
	return archive->setEntryCompressionEnabled(getEntry(entry, state), value);
}

Buffer* ZipArchive::readEntry(const std::string& entry, State state)
{
	const auto e = getEntry(entry, state);
	if (e.isNull())
		return nullptr;
	const auto size = e.getSize();
	if (size > std::numeric_limits<size_t>::max())
	{
		lastError = getLibZipppError(LIBZIPPP_ERROR_MEMORY_ALLOCATION);
		return nullptr;
	}
	auto b = Buffer::create();
	b->reserve((size_t)size);
	const std::function<bool(const void*, libzippp_uint64)> readFunc =
		[=](const void* data, libzippp_uint64 size_)
	{
		b->insert_data(b->size(), (const char*)data, (size_t)size_);
		return true;
	};
	const auto ret = archive->readEntry(getEntry(entry, state), readFunc, state);
	if (ret != LIBZIPPP_OK)
	{
		lastError = getLibZipppError(ret);
		return nullptr;
	}
	return b;
}

bool ZipArchive::extractEntry(const std::string& entry, const std::string& dstPath, State state)
{
	const auto path = cocos2d::FileUtils::getInstance()->getSuitableFOpen(dstPath);
	std::ofstream out(path, std::ios_base::out | std::ios_base::binary);
	if(!out.is_open())
		return false;
	const auto ret = archive->readEntry(getEntry(entry, state), out, state);
	if (ret != LIBZIPPP_OK)
	{
		lastError = getLibZipppError(ret);
		return false;
	}
	return true;
}

bool ZipArchive::deleteEntry(const std::string& entry)
{
	const auto ret = archive->deleteEntry(entry);
	if (ret != LIBZIPPP_OK)
	{
		lastError = getLibZipppError(ret);
		return false;
	}
	return true;
}

bool ZipArchive::renameEntry(const std::string& entry, const std::string& newName)
{
	const auto ret = archive->renameEntry(entry, newName);
	lastError = getLibZipppError(ret);
	return archive->renameEntry(entry, newName) == LIBZIPPP_OK;
}

bool ZipArchive::addData(const std::string& entry, Buffer* data) const
{
	if (!data)
		return false;
	return archive->addData(entry, data->data(), data->size());
}

bool ZipArchive::addString(const std::string& entry, const std::string& string) const
{
	if (string.empty())
		return false;
	return archive->addData(entry, string.data(), string.size());
}

ZipArchive::ZipEntryInfo ZipArchive::getEntryInfo(const std::string& entry, State state)
{
	ZipEntryInfo info{};
	const auto e = getEntry(entry, state);
	if (!e.isNull())
	{
		info.index = e.getIndex();
		info.time = e.getDate();
		info.compressionMethod = e.getCompressionMethod();
		info.encryptionMethod = e.getEncryptionMethod();
		info.size = e.getSize();
		info.sizeComp = e.getInflatedSize();
		info.crc = e.getCRC();
	}
	return info;
}

libzippp::ZipEntry ZipArchive::getEntry(const std::string& name, State state) const
{
	return archive->getEntry(name, false, true, state);
}
