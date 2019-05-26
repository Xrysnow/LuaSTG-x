#include "XFileDialog.h"
#include "../../external/NativeFileDialog/include/nfd.h"
#include "cocos2d.h"

using namespace std;
using namespace lstg;
std::string FileDialog::lastError;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)\
||(CC_TARGET_PLATFORM == CC_PLATFORM_MAC)\
||(CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)

std::string FileDialog::open(const std::string& filterList, const std::string& defaultPath)
{
	string ret;
	char* out = nullptr;
	const auto result = NFD_OpenDialog(filterList.c_str(), defaultPath.c_str(), &out);
	if (result == NFD_OKAY)
	{
		ret = out;
		lastError = "";
	}
	else if (result == NFD_CANCEL)
		lastError = "cancel";
	else
		lastError = NFD_GetError();
	return ret;
}

std::vector<std::string> FileDialog::openMultiple(const std::string& filterList, const std::string& defaultPath)
{
	vector<string> ret;
	nfdpathset_t pathSet;
	const auto result = NFD_OpenDialogMultiple(filterList.c_str(), defaultPath.c_str(), &pathSet);
	if (result == NFD_OKAY)
	{
		size_t i;
		for (i = 0; i < NFD_PathSet_GetCount(&pathSet); i++)
		{
			ret.emplace_back(NFD_PathSet_GetPath(&pathSet, i));
		}
		NFD_PathSet_Free(&pathSet);
		lastError = "";
	}
	else if (result == NFD_CANCEL)
		lastError = "cancel";
	else
		lastError = NFD_GetError();
	return ret;
}

std::string FileDialog::save(const std::string& filterList, const std::string& defaultPath)
{
	string ret;
	char* out = nullptr;
	const auto result = NFD_SaveDialog(filterList.c_str(), defaultPath.c_str(), &out);
	if (result == NFD_OKAY)
	{
		ret = out;
		lastError = "";
	}
	else if (result == NFD_CANCEL)
		lastError = "cancel";
	else
		lastError = NFD_GetError();
	return ret;
}

std::string FileDialog::pickFolder(const std::string& defaultPath)
{
	string ret;
	char* out = nullptr;
	const auto result = NFD_PickFolder(defaultPath.c_str(), &out);
	if (result == NFD_OKAY)
	{
		ret = out;
		lastError = "";
	}
	else if (result == NFD_CANCEL)
		lastError = "cancel";
	else
		lastError = NFD_GetError();
	return ret;
}

std::string FileDialog::getLastError()
{
	return lastError;
}

#else

std::string FileDialog::open(const std::string& filterList, const std::string& defaultPath)
{
	return "";
}

std::vector<std::string> FileDialog::openMultiple(const std::string& filterList, const std::string& defaultPath)
{
	return { "" };
}

std::string FileDialog::save(const std::string& filterList, const std::string& defaultPath)
{
	return "";
}

std::string FileDialog::pickFolder(const std::string& defaultPath)
{
	return "";
}

std::string FileDialog::getLastError()
{
	return "unsupport platform";
}

#endif
