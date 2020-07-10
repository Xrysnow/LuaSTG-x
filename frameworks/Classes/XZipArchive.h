#pragma once
#include "base/CCRef.h"
#include "XBuffer.h"
#include "libzippp.h"

namespace lstg
{
	class ZipArchive : public cocos2d::Ref
	{
	public:
        using OpenMode = libzippp::ZipArchive::OpenMode;
        using State = libzippp::ZipArchive::State;

        struct ZipEntryInfo
        {
            uint64_t index = 0;
            time_t time = 0;
            uint16_t compressionMethod = 0;
            uint16_t encryptionMethod = 0;
            uint64_t size = 0;
            uint64_t sizeComp = 0;
            int crc = 0;
        };
	private:
        ZipArchive() = default;
        virtual ~ZipArchive();
		bool init(const std::string& path, const std::string& password);
		bool initWithBuffer(Buffer* buffer, OpenMode mode, bool checkConsistency);
	public:
		/**
		 * Creates a new ZipArchive with the given path. If the password is defined, it
		 * will be used to read encrypted archive. It won't affect the files added
		 * to the archive.
		 */
		static ZipArchive* create(const std::string& path, const std::string& password = "");
		/**
		 * Creates a new ZipArchive from the specified buffer. The archive will
		 * directly be open with the given mode. If the archive fails to be open or
		 * if the consistency check fails, this method will return null.
		 */
		static ZipArchive* createFromBuffer(
			Buffer* buffer, OpenMode mode = OpenMode::READ_ONLY, bool checkConsistency = false);
		/**
		 * Open the ZipArchive with the given mode. This method will return true if the operation
		 * is successful, false otherwise. If the OpenMode is NOT_OPEN an invalid_argument
		 * will be thrown. If the archive is already open, this method returns true only if the
		 * mode is the same.
		 */
        bool open(OpenMode mode = OpenMode::READ_ONLY, bool checkConsistency = false) {
	        return archive->open(mode, checkConsistency);
        }
		/**
		 * Closes the ZipArchive and releases all the resources held by it. If the ZipArchive was
		 * not open previously, this method does nothing. If the archive was open in modification
		 * and some were done, they will be committed.
		 */
        bool close() { return archive->close() == LIBZIPPP_OK; }
		/**
		 * Closes the ZipArchive and releases all the resources held by it. If the ZipArchive was
		 * not open previously, this method does nothing. If the archive was open in modification
		 * and some were done, they will be rollbacked.
		 */
        void discard() { archive->discard(); }
		/**
		 * Deletes the file denoted by the path. If the ZipArchive is open, all the changes will
		 * be discarded and the file removed.
		 */
        bool unlink() { return archive->unlink(); }

        /**
         * Returns true if the ZipArchive is currently open.
         */
        bool isOpen() const { return archive->isOpen(); }

        /**
         * Returns true if the ZipArchive is open and mutable.
         */
        bool isMutable() const { return archive->isMutable(); }

        /**
         * Returns true if the ZipArchive is encrypted. This method returns true only if
         * a password has been set in the constructor.
         */
        bool isEncrypted() const { return archive->isEncrypted(); }

        /**
         * Returns the comment of the archive. In order to set the comment, the archive
         * must have been open in WRITE or NEW mode. If the archive is not open, then
         * an empty string will be returned.
         */
        std::string getComment(State state = State::CURRENT) const { return archive->getComment(state); }

        /**
         * Defines the comment of the archive. In order to set the comment, the archive
         * must have been open in WRITE or NEW mode. If the archive is not open, then
         * false will be returned.
         */
        bool setComment(const std::string& comment) const { return archive->setComment(comment); }

        /**
         * Removes the comment of the archive, if any. The archive must have been open
         * in WRITE or NEW mode.
         */
        bool removeComment() const { return archive->removeComment(); }

        /**
         * Returns the number of entries in this zip file (folders are included).
         * The zip file must be open otherwise LIBZIPPP_ERROR_NOT_OPEN will be returned.
         * If the state is ORIGINAL, then the number entries of the original archive are returned.
         * Any change will not be considered.
         * Note also that the deleted entries does not affect the result of this method
         * with the CURRENT state. For instance, if there are 3 entries and you delete one,
         * this method will still return 3. However, if you add one entry, it will return
         * 4 with the state CURRENT and 3 with the state ORIGINAL.
         * If you wanna know the "real" entries effectively in the archive, you might use
         * the getEntries method.
         */
        int64_t getEntryCount(State state = State::CURRENT) const { return archive->getNbEntries(state); }

        /**
         * Returns all the entries of the ZipArchive. If the state is ORIGINAL, then
         * returns the entries in the original archive, any change will not be considered.
         * The zip file must be open otherwise an empty vector will be returned.
         */
        std::vector<std::string> getEntries(State state = State::CURRENT) const;

        /**
         * Returns true if an entry with the specified name exists. If no such entry exists,
         * then false will be returned. If a directory is searched, the name must end with a '/' !
         * The zip file must be open otherwise false will be returned.
         */
        bool hasEntry(const std::string& name,
            bool excludeDirectories = false, bool caseSensitive = true, State state = State::CURRENT) const {
            return archive->hasEntry(name, excludeDirectories, caseSensitive, state);
        }

        /**
         * Returns the entry for the specified index. If the index is out of range,
         * then a null-entry will be returned.
         * The zip file must be open otherwise a null-entry will be returned.
         */
        std::string getEntryByIndex(int64_t index, State state = State::CURRENT) const;

        /**
         * Returns the comment of the entry. If the ZipArchive is not open or the
         * entry is not linked to this archive, then an empty string will
         * be returned.
         */
        std::string getEntryComment(const std::string& entry, State state = State::CURRENT) const;

        /**
         * Defines the comment of the entry. If the ZipArchive is not open or the
         * entry is not linked to this archive, then false will be returned.
         */
        bool setEntryComment(const std::string& entry, const std::string& comment, State state = State::CURRENT) const;

        /**
         * Returns the compression method of an entry. If the ZipArchive is not open
         * or the entry is not linked to this archive, false will be returned.
         **/
        bool isEntryCompressionEnabled(const std::string& entry, State state = State::CURRENT) const;

        /**
         * Defines the compression method of an entry. If the ZipArchive is not open
         * or the entry is not linked to this archive, false will be returned.
         **/
        bool setEntryCompressionEnabled(const std::string& entry, bool value, State state = State::CURRENT) const;

        /**
         * Reads the specified entry of the ZipArchive and returns its content within
         * a char array. If there is an error while reading the entry, then null will be returned.
         * The data must be deleted by the developer once not used anymore.
         * The zip file must be opened otherwise null will be returned. If the entry was not
         * created by this ZipArchive, null will be returned. If the entry does not exist,
         * this method returns NULL:
         */
        Buffer* readEntry(const std::string& entry, State state = State::CURRENT);

        /**
         * Reads the specified entry of the ZipArchive and writes its content to
         * dstPath. If there is an error while reading the entry, then false will be returned.
         * The zip file must be opened otherwise null will be returned. If the entry was not
         * created by this ZipArchive, null will be returned. If the entry does not exist,
         * this method returns NULL:
         */
        bool extractEntry(const std::string& entry, const std::string& dstPath, State state = State::CURRENT);

        /**
         * Deletes the specified entry from the zip file. If the entry is a folder, all its
         * subentries will be removed. This method returns the number of entries removed.
         * If the open mode does not allow a deletion, this method will return LIBZIPPP_ERROR_NOT_ALLOWED.
         * If the ZipArchive is not open, LIBZIPPP_ERROR_NOT_OPEN will be returned. If the entry is not handled
         * by this ZipArchive or is a null-entry, then LIBZIPPP_ERROR_INVALID_ENTRY will be returned.
         * If an error occurs during deletion, this method will return LIBZIPPP_ERROR_UNKNOWN.
         * If the entry does not exist, this method returns LIBZIPPP_ERROR_INVALID_PARAMETER.
         * Note that this method does not affect the result returned by getEntryCount !
         */
        bool deleteEntry(const std::string& entry);

        /**
         * Renames the entry with the specified newName. The method returns the number of entries
         * that have been renamed, LIBZIPPP_ERROR_INVALID_PARAMETER if the new name is invalid,
         * LIBZIPPP_ERROR_NOT_ALLOWED if the mode doesn't allow modification or LIBZIPPP_ERROR_UNKNOWN if an error
         * occurred. If the entry is a directory, a '/' will automatically be appended at the end of newName if the
         * latter hasn't it already. All the files in the folder will be moved.
         * If the ZipArchive is not open or the entry was not edited by this ZipArchive or is a null-entry,
         * then LIBZIPPP_ERROR_INVALID_ENTRY will be returned. If the entry does not exist, this method returns LIBZIPPP_ERROR_INVALID_PARAMETER.
         */
        bool renameEntry(const std::string& entry, const std::string& newName);

        /**
         * Adds the specified file in the archive with the given entry. If the entry already exists,
         * it will be replaced. This method returns true if the file has been added successfully.
         * If the entry contains folders that don't exist in the archive, they will be automatically created.
         * If the entry denotes a directory, this method returns false.
         * The zip file must be open otherwise false will be returned.
         */
        bool addFile(const std::string& entry, const std::string& file) const { return archive->addFile(entry, file); }

        /**
         * Adds the given data to the specified entry name in the archive. If the entry already exists,
         * its content will be erased.
         * If the entry contains folders that don't exist in the archive, they will be automatically created.
         * If the entry denotes a directory, this method returns false.
         * If the zip file is not open, this method returns false.
         */
        bool addData(const std::string& entry, Buffer* data) const;

        /**
         * Adds the given string to the specified entry name in the archive. If the entry already exists,
         * its content will be erased.
         * If the entry contains folders that don't exist in the archive, they will be automatically created.
         * If the entry denotes a directory, this method returns false.
         * If the zip file is not open, this method returns false.
         */
        bool addString(const std::string& entry, const std::string& string) const;

        /**
         * Adds the specified entry to the ZipArchive. All the needed hierarchy will be created.
         * The entry must be a directory (end with '/').
         * If the ZipArchive is not open or the entry is not a directory, this method will
         * returns false. If the entry already exists, this method returns true.
         * This method will only add the specified entry. The 'real' directory may exist or not.
         * If the directory exists, the files in it won't be added to the archive.
         */
        bool addEntry(const std::string& entry) const { return archive->addEntry(entry); }

        /**
         * Returns the mode in which the file has been open.
         * If the archive is not open, then NOT_OPEN will be returned.
         */
        OpenMode getMode() const { return archive->getMode(); }

        ZipEntryInfo getEntryInfo(const std::string& entry, State state = State::CURRENT);

        ZipArchive(const ZipArchive &) = delete;
		ZipArchive &operator =(const ZipArchive &) = delete;;

	private:
        libzippp::ZipEntry getEntry(const std::string& name, State state) const;
		
        libzippp::ZipArchive* archive = nullptr;
        Buffer* buffer = nullptr;
        std::string lastError;
	};
}

#include "UtilLuaConversion.h"

namespace lstg
{
	namespace lua
	{
        template<>
        struct to_lua<ZipArchive::ZipEntryInfo>
        {
            static void F(lua_State* L, const ZipArchive::ZipEntryInfo& inValue) {
                if (!L) return;
                lua_createtable(L, 0, 7);
                native_to_luaval_field(L, -1, "index", inValue.index);
                native_to_luaval_field(L, -1, "time", inValue.time);
                native_to_luaval_field(L, -1, "compressionMethod", inValue.compressionMethod);
                native_to_luaval_field(L, -1, "encryptionMethod", inValue.encryptionMethod);
                native_to_luaval_field(L, -1, "size", inValue.size);
                native_to_luaval_field(L, -1, "sizeComp", inValue.sizeComp);
                native_to_luaval_field(L, -1, "crc", inValue.crc);
            }
        };
	}
}
