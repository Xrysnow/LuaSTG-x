﻿#pragma once

#include "Global.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/CCFileUtils-android.h"
using _FileUtilsBase = cocos2d::FileUtilsAndroid;

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)

#ifdef CC_FILEUTILS_APPLE_ENABLE_OBJC
#undef CC_FILEUTILS_APPLE_ENABLE_OBJC
#endif
#include "platform/apple/CCFileUtils-apple.h"
#define CC_FILEUTILS_APPLE_ENABLE_OBJC
using _FileUtilsBase = cocos2d::FileUtilsApple;

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "platform/win32/CCFileUtils-win32.h"
using _FileUtilsBase = cocos2d::FileUtilsWin32;

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
#include "platform/linux/CCFileUtils-linux.h"
using _FileUtilsBase = cocos2d::FileUtilsLinux;
#endif

//TODO: getPathXX
class XFileUtils : public _FileUtilsBase
{
public:
	static void start();

	bool init() override;

	std::string getStringFromFile(std::string_view filename) const override;
	cocos2d::Data getDataFromFile(std::string_view filename) const override;

	std::string fullPathForFilename(std::string_view filename) const override;
	bool isAbsolutePath(std::string_view strPath) const override;
	bool isFileExist(std::string_view filename) const override;
	bool isDirectoryExistInternal(std::string_view dirPath) const override;
	std::vector<std::string> listFiles(std::string_view dirPath) const override;

	std::string getFullPathForFilenameWithinDirectory(std::string_view directory, std::string_view filename) const override;

	static void SetFileStringToReplace(const std::string& filename, std::string content);
	static void CancelFileStringToReplace(const std::string& filename);
	static void ClearFileStringToReplace();
};
