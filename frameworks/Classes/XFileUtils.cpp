#include "XFileUtils.h"
#include "platform/CCFileUtils.h"
#include "../LSTG/AppFrame.h"
#include "Util/Utility.h"
#include "ResourceMgr.h"

#define DECLARE_GUARD std::lock_guard<std::recursive_mutex> mutexGuard(_mutex)

using namespace std;
using namespace cocos2d;

unordered_map<string, string> fileStringToReplace;
// D:\aaa\bbb\ccc\ddd\abc.txt --> D:/aaa/bbb/ccc/ddd/abc.txt
static inline string convertPathFormatToUnixStyle(const string& path)
{
	string ret = path;
	int len = ret.length();
	for (int i = 0; i < len; ++i)
	{
		if (ret[i] == '\\')
		{
			ret[i] = '/';
		}
	}
	return ret;
}

void XFileUtils::start()
{
	// replace FileUtils
	auto fu = new XFileUtils();
	fu->init();
	setDelegate(fu);
}

bool XFileUtils::init()
{
	DECLARE_GUARD;
	const auto ret = _FileUtilsBase::init();
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID && 0
	auto am = getAssetManager();
	if (am)
	{
		AAssetDir* aa = AAssetManager_openDir(am, "");
		if (aa)
		{
			const char* filename;
			while ((filename = AAssetDir_getNextFileName(aa)) != nullptr) {
				//
			}
			AAssetDir_close(aa);
		}
	}
#endif
	return ret;
}

string XFileUtils::getStringFromFile(string_view filename) const
{
	if (filename.empty())
	{
		//CCLOG("XFileUtils: filename is empty");
		return "";
	}

	// force replace, used for HGE font
	auto i = fileStringToReplace.find(std::string{filename});
	if (i != fileStringToReplace.end())
	{
		return i->second;
	}
	// via ResourceMgr
	return LRES.getStringFromFile(std::string{filename});
}

Data XFileUtils::getDataFromFile(string_view filename) const
{
	Data d;
	if (filename.empty())
	{
		//CCLOG("XFileUtils: filename is empty");
	}
	else
	{
		const auto data = LRES.getBufferFromFile(std::string{filename});
		if(data)
			d.copy(data->data(), data->size());
	}
	return d;
}

string XFileUtils::fullPathForFilename(string_view filename) const
{
	if (filename.empty())
		return "";
	if (LRES.isFileOrDirectoryExist(std::string{filename}))
	{
		return std::string{filename};
	}
	// fullPathForDirectory is not public
	if (!filename.empty() && filename[filename.size() - 1] == '/')
		return _FileUtilsBase::fullPathForDirectory(filename);
	return _FileUtilsBase::fullPathForFilename(filename);
}

bool XFileUtils::isAbsolutePath(string_view strPath) const
{
	if (LRES.isFileOrDirectoryExist(std::string{strPath}))
		return true;
	return _FileUtilsBase::isAbsolutePath(strPath);
}

bool XFileUtils::isFileExist(string_view filename) const
{
	if (filename.empty())
		return false;
	if (LRES.isFileOrDirectoryExist(std::string{filename}))
		return true;
	if (_FileUtilsBase::isDirectoryExist(filename))
		return false;
	// todo: may fail on linux
	return _FileUtilsBase::isFileExist(filename);
}

bool XFileUtils::isDirectoryExistInternal(string_view dirPath) const
{
	if (dirPath.empty())
		return false;
	if (LRES.isFileOrDirectoryExist(std::string{dirPath}))
		return true;
	return _FileUtilsBase::isDirectoryExistInternal(dirPath);
}

vector<string> XFileUtils::listFiles(string_view dirPath) const
{
	vector<string> ret;
	if (dirPath.empty())
		return ret;
	for (auto& pack : LRES.getResourcePacks())
	{
		if (pack->isFileOrDirectoryExist(std::string{dirPath}))
		{
			for (auto& p : pack->listFiles())
			{
				if (p.compare(0, dirPath.size(), dirPath) == 0
					&& p.find('/', dirPath.size()) == string::npos)
					ret.push_back(p);
			}
		}
	}
	if (ret.empty())
		return _FileUtilsBase::listFiles(dirPath);
	return ret;
}

string XFileUtils::getFullPathForFilenameWithinDirectory(string_view directory, string_view filename) const
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	string dir = convertPathFormatToUnixStyle(std::string{directory});
	const string f = convertPathFormatToUnixStyle(std::string{filename});
	// get directory+filename, safely adding '/' as necessary
	string ret = dir;
	if (!dir.empty() && dir[dir.size() - 1] != '/')
		ret += '/';
	ret += f;
	// fix
	if (!isFileExistInternal(ret) && !isDirectoryExistInternal(ret))
		ret = "";
	return ret;
#else
	return _FileUtilsBase::getFullPathForFilenameWithinDirectory(directory, filename);
#endif
}

void XFileUtils::SetFileStringToReplace(const string& filename, string content)
{
	fileStringToReplace[filename] = content;
}

void XFileUtils::CancelFileStringToReplace(const string& filename)
{
	const auto i = fileStringToReplace.find(filename);
	if (i != fileStringToReplace.end())
	{
		fileStringToReplace.erase(i);
	}
}

void XFileUtils::ClearFileStringToReplace()
{
	fileStringToReplace.clear();
}
