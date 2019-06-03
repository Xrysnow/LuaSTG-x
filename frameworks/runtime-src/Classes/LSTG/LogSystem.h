#pragma once
#include "cocos2d.h"
#include <fstream>
#include <functional>

#define LLOGGER (*lstg::LogSystem::getInstance())
#define LERROR(info, ...) LLOGGER.Log(lstg::LogType::Error, info, ##__VA_ARGS__)
#define LWARNING(info, ...) LLOGGER.Log(lstg::LogType::Warning, info, ##__VA_ARGS__)
#define LINFO(info, ...) LLOGGER.Log(lstg::LogType::Information, info, ##__VA_ARGS__)

#define XERROR(_str, ...) LLOGGER.Log(lstg::LogType::Error,\
	"[%s] " _str, lstg::__cut_ns(__FUNCTION__), ##__VA_ARGS__)
#define XWARNING(_str, ...) LLOGGER.Log(lstg::LogType::Warning,\
	"[%s] " _str, lstg::__cut_ns(__FUNCTION__), ##__VA_ARGS__)
#define XINFO(_str, ...) LLOGGER.Log(lstg::LogType::Information,\
	"[%s] " _str, lstg::__cut_ns(__FUNCTION__), ##__VA_ARGS__)

namespace lstg
{
	enum class LogType
	{
		Information,
		Warning,
		Error
	};

	class LogSystem : protected cocos2d::Ref
	{
	public:

		static LogSystem* getInstance();

		void Log(LogType type, const char* info, ...)noexcept;

		bool changePath(const std::string& path)noexcept;
		std::string getPath() const noexcept;
		bool write(const std::string& str)noexcept;
		bool writeLine(const std::string& str)noexcept;
		void setConsoleLevel(int level);
		void setOnWrite(const std::function<void(const std::string&)>& f);

	private:
		std::string logFileName;
		std::fstream logFile;
		std::mutex mut;
		std::function<void(const std::string&)> onWrite = nullptr;
		int consoleLevel = 0;
	public:
		LogSystem();
		LogSystem(const std::string& fileName);
		~LogSystem();
		LogSystem(const LogSystem &) = delete;
		LogSystem &operator =(const LogSystem &) = delete;
	};

	constexpr const char* __cut_ns(const char* s)
	{
		bool eq = true;
		//const char* ns = "lstg::";
		for (int i = 0; i < 6; ++i)
		{
			if (s[i] != "lstg::"[i])
			{
				eq = false;
				break;
			}
		}
		return eq ? (s + 6) : s;
	}
}
