#include "XFileUtils.h"
#include "platform/CCFileUtils.h"
#include "../LSTG/AppFrame.h"
#include "Utility.h"

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

string XFileUtils::getStringFromFile(const string& filename) const
{
	if (filename.empty())
	{
		//CCLOG("XFileUtils: filename is empty");
		return "";
	}

	// force replace, used for HGE font
	auto i = fileStringToReplace.find(filename);
	if (i != fileStringToReplace.end())
	{
		return i->second;
	}
	// via ResourceMgr
	return LRES.getStringFromFile(filename);
}

Data XFileUtils::getDataFromFile(const string& filename) const
{
	Data d;
	if (filename.empty())
	{
		//CCLOG("XFileUtils: filename is empty");
	}
	else
	{
		const auto data = LRES.getBufferFromFile(filename);
		d.copy(data->data(), data->size());
	}
	return d;
}

string XFileUtils::fullPathForFilename(const string& filename) const
{
	if (filename.empty())
		return "";
	if (LRES.isFileOrDirectoryExist(filename))
	{
		return filename;
	}
	return _FileUtilsBase::fullPathForFilename(filename);
}

bool XFileUtils::isAbsolutePath(const std::string& strPath) const
{
	if (LRES.isFileOrDirectoryExist(strPath))
		return true;
	return _FileUtilsBase::isAbsolutePath(strPath);
}

bool XFileUtils::isFileExist(const string& filename) const
{
	if (filename.empty())
		return false;
	if (LRES.isFileOrDirectoryExist(filename))
		return true;
	// todo: may fail on linux
	return _FileUtilsBase::isFileExist(filename);
}

bool XFileUtils::isDirectoryExistInternal(const string& dirPath) const
{
	if (dirPath.empty())
		return false;
	if (LRES.isFileOrDirectoryExist(dirPath))
		return true;
	return _FileUtilsBase::isDirectoryExistInternal(dirPath);
}

vector<string> XFileUtils::listFiles(const string& dirPath) const
{
	vector<string> ret;
	if (dirPath.empty())
		return ret;
	for (auto& pack : LRES.getResourcePacks())
	{
		if (pack->isFileOrDirectoryExist(dirPath))
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

string XFileUtils::getFullPathForFilenameWithinDirectory(const string& directory, const string& filename) const
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	string dir = convertPathFormatToUnixStyle(directory);
	const string f = convertPathFormatToUnixStyle(filename);
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
