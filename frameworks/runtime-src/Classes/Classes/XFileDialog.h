#pragma once
#include <string>
#include <vector>

namespace lstg
{
	class FileDialog
	{
	public:
		static std::string open(
			const std::string& filterList, const std::string& defaultPath);
		static std::vector<std::string> openMultiple(
			const std::string& filterList, const std::string& defaultPath);
		static std::string save(
			const std::string& filterList, const std::string& defaultPath);
		static std::string pickFolder(const std::string& defaultPath);
		static std::string getLastError();
	private:
		static std::string lastError;
	};
}
