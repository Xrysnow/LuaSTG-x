#include "XZipArchive.h"
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace lstg;

namespace
{
	const char* getLibZipppError(int code)
	{
		switch (code)
		{
		case LIBZIPPP_OK: return "";
		case LIBZIPPP_ERROR_NOT_OPEN: return "NOT_OPEN";
		case LIBZIPPP_ERROR_NOT_ALLOWED: return "NOT_ALLOWED";
		case LIBZIPPP_ERROR_INVALID_ENTRY: return "INVALID_ENTRY";
		case LIBZIPPP_ERROR_INVALID_PARAMETER: return "INVALID_PARAMETER";
		case LIBZIPPP_ERROR_MEMORY_ALLOCATION: return "MEMORY_ALLOCATION";
		case LIBZIPPP_ERROR_FOPEN_FAILURE: return "FOPEN_FAILURE";
		case LIBZIPPP_ERROR_FREAD_FAILURE: return "FREAD_FAILURE";
		case LIBZIPPP_ERROR_OWRITE_FAILURE: return "OWRITE_FAILURE";
		case LIBZIPPP_ERROR_OWRITE_INDEX_FAILURE: return "OWRITE_INDEX_FAILURE";
		case LIBZIPPP_ERROR_HANDLE_FAILURE: return "HANDLE_FAILURE";
		default: return "UNKNOWN";
		}
	}

	int zipCompressionMethod(ZipArchive::CompressionMethod method)
	{
		switch (method)
		{
		case ZipArchive::DEFAULT: return ZIP_CM_DEFAULT;
		case ZipArchive::STORE: return ZIP_CM_STORE;
		case ZipArchive::DEFLATE: return ZIP_CM_DEFLATE;
#ifdef ZIP_CM_BZIP2
		case ZipArchive::BZIP2: return ZIP_CM_BZIP2;
#endif
#ifdef ZIP_CM_XZ
		case ZipArchive::XZ: return ZIP_CM_XZ;
#endif
#ifdef ZIP_CM_ZSTD
		case ZipArchive::ZSTD: return ZIP_CM_ZSTD;
#endif
		default: return std::numeric_limits<int>::min();
		}
	}

	bool compressionSupported(ZipArchive::CompressionMethod method)
	{
		int value = zipCompressionMethod(method);
		if (value == std::numeric_limits<int>::min()) return false;
		if (value == ZIP_CM_DEFAULT) value = ZIP_CM_DEFLATE;
		return zip_compression_method_supported(value, 1) != 0;
	}
}

ZipArchive::~ZipArchive()
{
	if (archive)
	{
		if (close() != LIBZIPPP_OK) discard();
		libzippp::ZipArchive::free(archive);
	}
	CC_SAFE_RELEASE(buffer);
}

int ZipArchive::recordResult(int result) const
{
	lastError = result >= 0 ? "" : getLibZipppError(result);
	return result;
}

bool ZipArchive::init(const std::string& path, const std::string& password, Encryption encryptionMethod)
{
	archive = new (std::nothrow) libzippp::ZipArchive(
		path, password, static_cast<libzippp::ZipArchive::Encryption>(encryptionMethod));
	return archive != nullptr;
}

bool ZipArchive::initWithBuffer(Buffer* input, bool checkConsistency)
{
	if (!input) return false;
	// A retained Buffer can still reallocate. Own a snapshot of the borrowed source.
	buffer = input->clone();
	if (!buffer) return false;
	buffer->retain();
	auto source = zip_source_buffer_create(buffer->data(), buffer->size(), 0, nullptr);
	if (!source) return false;
	archive = libzippp::ZipArchive::fromSource(source, libzippp::ZipArchive::ReadOnly, checkConsistency);
	if (!archive) zip_source_free(source);
	return archive != nullptr;
}

ZipArchive* ZipArchive::create(const std::string& path, const std::string& password, Encryption encryptionMethod)
{
	auto result = new (std::nothrow) ZipArchive();
	if (result && result->init(path, password, encryptionMethod))
	{
		result->autorelease();
		return result;
	}
	delete result;
	return nullptr;
}

ZipArchive* ZipArchive::createFromBuffer(Buffer* input, bool checkConsistency)
{
	auto result = new (std::nothrow) ZipArchive();
	if (result && result->initWithBuffer(input, checkConsistency))
	{
		result->autorelease();
		return result;
	}
	delete result;
	return nullptr;
}

bool ZipArchive::open(OpenMode mode, bool checkConsistency)
{
	const bool result = archive->open(static_cast<libzippp::ZipArchive::OpenMode>(mode), checkConsistency);
	recordResult(result ? OK : HANDLE_FAILURE);
	return result;
}

int ZipArchive::close()
{
	const int result = archive->close();
	if (result == OK)
	{
		addedData.clear();
		CC_SAFE_RELEASE_NULL(buffer);
	}
	return recordResult(result);
}

void ZipArchive::discard()
{
	archive->discard();
	addedData.clear();
	CC_SAFE_RELEASE_NULL(buffer);
	lastError.clear();
}

bool ZipArchive::unlink()
{
	discard();
	const bool result = archive->unlink();
	recordResult(result ? OK : HANDLE_FAILURE);
	return result;
}

std::string ZipArchive::getComment(State state) const
{
	return archive->getComment(static_cast<libzippp::ZipArchive::State>(state));
}

int64_t ZipArchive::getNbEntries(State state) const
{
	return archive->getNbEntries(static_cast<libzippp::ZipArchive::State>(state));
}

std::vector<std::string> ZipArchive::getEntries(State state) const
{
	const auto entries = archive->getEntries(static_cast<libzippp::ZipArchive::State>(state));
	std::vector<std::string> result;
	result.reserve(entries.size());
	for (const auto& entry : entries) result.push_back(entry.getName());
	return result;
}

bool ZipArchive::hasEntry(const std::string& name, bool excludeDirectories, bool caseSensitive, State state) const
{
	return archive->hasEntry(name, excludeDirectories, caseSensitive, static_cast<libzippp::ZipArchive::State>(state));
}

std::string ZipArchive::getEntryByIndex(int64_t index, State state) const
{
	return archive->getEntry(index, static_cast<libzippp::ZipArchive::State>(state)).getName();
}

std::string ZipArchive::getEntryComment(const std::string& entry, State state) const
{
	return archive->getEntryComment(getEntry(entry, state), static_cast<libzippp::ZipArchive::State>(state));
}

bool ZipArchive::setEntryComment(const std::string& entry, const std::string& comment, State state) const
{
	return isMutable() && archive->setEntryComment(getEntry(entry, state), comment);
}

ZipArchive::CompressionMethod ZipArchive::getEntryCompressionMethod(const std::string& name, State state) const
{
	const auto entry = getEntry(name, state);
	zip_stat_t stat;
	zip_stat_init(&stat);
	if (entry.isNull() || zip_stat_index(archive->getZipHandle(), entry.getIndex(),
		state == Original ? ZIP_FL_UNCHANGED : 0, &stat) != 0) return DEFAULT;
	switch (stat.comp_method)
	{
	case ZIP_CM_STORE: return STORE;
	case ZIP_CM_DEFLATE: return DEFLATE;
#ifdef ZIP_CM_BZIP2
	case ZIP_CM_BZIP2: return BZIP2;
#endif
#ifdef ZIP_CM_XZ
	case ZIP_CM_XZ: return XZ;
#endif
#ifdef ZIP_CM_ZSTD
	case ZIP_CM_ZSTD: return ZSTD;
#endif
	default: return DEFAULT;
	}
}

bool ZipArchive::setEntryCompressionConfig(const std::string& name, CompressionMethod method, uint32_t level, State state) const
{
	if (!isMutable()) { recordResult(isOpen() ? NOT_ALLOWED : NOT_OPEN); return false; }
	const auto entry = getEntry(name, state);
	if (entry.isNull()) { recordResult(INVALID_ENTRY); return false; }
	if (!compressionSupported(method)) { recordResult(INVALID_PARAMETER); return false; }
	// Keep ZIP_CM_DEFAULT signed; libzippp narrows -1 to uint16_t here.
	const bool result = zip_set_file_compression(archive->getZipHandle(), entry.getIndex(),
		zipCompressionMethod(method), level) == 0;
	recordResult(result ? OK : UNKNOWN);
	return result;
}

void ZipArchive::setCompressionMethod(CompressionMethod method)
{
	if (!compressionSupported(method)) { recordResult(INVALID_PARAMETER); return; }
	archive->setCompressionMethod(static_cast<libzippp::CompressionMethod>(method));
	recordResult(OK);
}

ZipArchive::CompressionMethod ZipArchive::getCompressionMethod() const
{
	return static_cast<CompressionMethod>(archive->getCompressionMethod());
}

void ZipArchive::setCompressionLevel(uint32_t level)
{
	archive->setCompressionLevel(level);
	recordResult(OK);
}

uint32_t ZipArchive::getCompressionLevel() const
{
	return archive->getCompressionLevel();
}

Buffer* ZipArchive::readEntry(const std::string& name, State state)
{
	if (!isOpen()) { recordResult(NOT_OPEN); return nullptr; }
	const auto entry = getEntry(name, state);
	if (entry.isNull()) { recordResult(INVALID_ENTRY); return nullptr; }
	const auto size = entry.getSize();
	if (size > std::numeric_limits<size_t>::max()) { recordResult(MEMORY_ALLOCATION); return nullptr; }
	auto file = zip_fopen_index(archive->getZipHandle(), entry.getIndex(), state == Original ? ZIP_FL_UNCHANGED : 0);
	if (!file) { recordResult(FOPEN_FAILURE); return nullptr; }
	auto output = Buffer::create(static_cast<size_t>(size));
	int result = output ? OK : MEMORY_ALLOCATION;
	uint64_t offset = 0;
	while (result == OK && offset < size)
	{
		const auto count = zip_fread(file, output->data() + offset,
			std::min<uint64_t>(size - offset, LIBZIPPP_DEFAULT_CHUNK_SIZE));
		if (count <= 0) { result = FREAD_FAILURE; break; }
		offset += count;
	}
	if (zip_fclose(file) != 0 && result == OK) result = FREAD_FAILURE;
	recordResult(result);
	return result == OK ? output : nullptr;
}

bool ZipArchive::extractEntry(const std::string& name, const std::string& dstPath, State state)
{
	if (!isOpen()) { recordResult(NOT_OPEN); return false; }
	const auto entry = getEntry(name, state);
	if (entry.isNull()) { recordResult(INVALID_ENTRY); return false; }
	const auto path = cocos2d::FileUtils::getInstance()->getSuitableFOpen(dstPath);
	std::ofstream output(path, std::ios::out | std::ios::binary);
	if (!output.is_open()) { recordResult(INVALID_PARAMETER); return false; }
	int result = archive->readEntry(entry, output, static_cast<libzippp::ZipArchive::State>(state));
	output.close();
	if (result == OK && output.fail()) result = OWRITE_FAILURE;
	return recordResult(result) == OK;
}

int ZipArchive::deleteEntry(const std::string& entry)
{
	return recordResult(archive->deleteEntry(entry));
}

int ZipArchive::renameEntry(const std::string& name, const std::string& newName)
{
	const auto entry = getEntry(name, Current);
	if (entry.isNull()) return recordResult(INVALID_PARAMETER);
	if (!isMutable()) return recordResult(NOT_ALLOWED);
	if (newName.empty() || newName == name) return recordResult(INVALID_PARAMETER);
	if (entry.isDirectory()) return recordResult(archive->renameEntry(entry, newName));
	if (newName.back() == '/') return recordResult(INVALID_PARAMETER);
	// Avoid libzippp's attempt to create an empty parent when renaming a root file.
	const auto slash = newName.rfind('/');
	if (slash != std::string::npos && !archive->addEntry(newName.substr(0, slash + 1)))
		return recordResult(UNKNOWN);
	const auto result = zip_file_rename(archive->getZipHandle(), entry.getIndex(), newName.c_str(), ZIP_FL_ENC_GUESS);
	return recordResult(result == 0 ? 1 : UNKNOWN);
}

bool ZipArchive::applyCompression(const std::string& name) const
{
	// libzippp's addFile/addData ignore the configured compression level.
	return setEntryCompressionConfig(name, getCompressionMethod(), getCompressionLevel());
}

bool ZipArchive::addFile(const std::string& name, const std::string& file) const
{
	if (!archive->addFile(name, file))
	{
		recordResult(!isOpen() ? NOT_OPEN : (!isMutable() ? NOT_ALLOWED : UNKNOWN));
		return false;
	}
	return applyCompression(name);
}

bool ZipArchive::addBytes(const std::string& name, const void* data, size_t size) const
{
	if (!isMutable()) { recordResult(isOpen() ? NOT_ALLOWED : NOT_OPEN); return false; }
	try
	{
		auto copy = std::make_unique<std::vector<uint8_t>>(size);
		if (size) std::memcpy(copy->data(), data, size);
		auto address = copy->data();
		// libzip borrows the source until close/discard, even after replacement/deletion.
		addedData.push_back(std::move(copy));
		if (!archive->addData(name, address, size)) { recordResult(UNKNOWN); return false; }
		return applyCompression(name);
	}
	catch (const std::bad_alloc&) { recordResult(MEMORY_ALLOCATION); return false; }
}

bool ZipArchive::addData(const std::string& name, Buffer* data) const
{
	if (!data) { recordResult(INVALID_PARAMETER); return false; }
	return addBytes(name, data->data(), data->size());
}

bool ZipArchive::addString(const std::string& name, const std::string& data) const
{
	return addBytes(name, data.data(), data.size());
}

ZipArchive::OpenMode ZipArchive::getMode() const
{
	return static_cast<OpenMode>(archive->getMode());
}

ZipArchive::ZipEntryInfo ZipArchive::getEntryInfo(const std::string& name, State state)
{
	ZipEntryInfo info{};
	const auto entry = getEntry(name, state);
	if (!entry.isNull())
	{
		info.index = entry.getIndex();
		info.time = entry.getDate();
		// Preserve the existing Lua table's raw ZIP method IDs.
		zip_stat_t stat;
		zip_stat_init(&stat);
		if (zip_stat_index(archive->getZipHandle(), entry.getIndex(),
			state == Original ? ZIP_FL_UNCHANGED : 0, &stat) == 0)
			info.compressionMethod = stat.comp_method;
		info.encryptionMethod = entry.getEncryptionMethod();
		info.size = entry.getSize();
		info.sizeComp = entry.getDeflatedSize();
		info.crc = entry.getCRC();
	}
	return info;
}

libzippp::ZipEntry ZipArchive::getEntry(const std::string& name, State state) const
{
	return archive->getEntry(name, false, true, static_cast<libzippp::ZipArchive::State>(state));
}
