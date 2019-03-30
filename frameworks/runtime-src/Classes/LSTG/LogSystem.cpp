#include "LogSystem.h"
#include "Utility.h"
#include "Global.h"

using namespace std;
using namespace lstg;

// note: FileUtils uses "wb" and will call fopen/fclose once at each writing

LogSystem* LogSystem::getInstance()
{
	static LogSystem s_Instance;
	return &s_Instance;
}

LogSystem::LogSystem()
{
	const string fileName = LLOGFILE;
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	changePath(fileName);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	if (!changePath(string("/storage/emulated/0/lstg/") + fileName))
		changePath(cocos2d::FileUtils::getInstance()->getWritablePath() + fileName);
#else
	changePath(cocos2d::FileUtils::getInstance()->getWritablePath() + fileName);
#endif
	CCASSERT(logFile.is_open(), "can't create log file.");
}

LogSystem::LogSystem(const string& fileName)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	changePath(fileName);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	if (!changePath(string("/storage/emulated/0/lstg/") + fileName))
		changePath(cocos2d::FileUtils::getInstance()->getWritablePath() + fileName);
#else
	changePath(cocos2d::FileUtils::getInstance()->getWritablePath() + fileName);
#endif
	CCASSERT(logFile.is_open(), "can't create log file.");
}

LogSystem::~LogSystem()
{
	logFile.flush();
	logFile.close();
}

void LogSystem::Log(LogType type, const char* info, ...) noexcept
{
	string s;
	try
	{
		switch (type)
		{
		case LogType::Error:
			s = "[ERRO] ";
			break;
		case LogType::Warning:
			s = "[WARN] ";
			break;
		default:
			s = "[INFO] ";
			break;
		}
		va_list vargs;
		va_start(vargs, info);
		s += StringFormatV(info, vargs);
		va_end(vargs);
		s.push_back('\n');
	}
	catch (const bad_alloc&)
	{
		CCLOGERROR("[ERRO] OOM");
		return;
	}

	write(s);
	s.pop_back();
	if ((int)type >= 3 - consoleLevel)
	{
		cocos2d::log("%s", s.c_str());
	}
}

bool LogSystem::changePath(const std::string& path)noexcept
{
	//lock_guard<mutex> lock(mut);
	if (logFileName == path)
		return true;
	try
	{
		stringstream s;
		if(logFile.is_open())
		{
			ifstream f;
			f.open(logFileName);
			if(f.is_open())
				s << f.rdbuf();
			f.close();
			logFile.close();
			logFile.clear();
		}
		logFile.open(path, ios::out);
		if (!logFile.is_open())
		{
			logFile.open(logFileName, ios::app | ios::out);
			return false;
		}
		logFile << s.str();
		logFile.flush();
		logFileName = path;
		return true;
	}
	catch (const bad_alloc&)
	{
		CCLOGERROR("[ERRO] OOM");
	}
	return false;
}

std::string LogSystem::getPath() const noexcept
{
	return logFileName;
}

bool LogSystem::write(const std::string& str) noexcept
{
	lock_guard<mutex> lock(mut);
	try
	{
		if (logFile.is_open())
		{
			logFile << str;
			logFile.flush();
			return true;
		}
	}
	catch (const bad_alloc&)
	{
		CCLOGERROR("[ERRO] OOM");
	}
	return false;
}

bool LogSystem::writeLine(const std::string& str) noexcept
{
	return write(str + "\n");
}

void LogSystem::setConsoleLevel(int level)
{
	consoleLevel = level;
}
