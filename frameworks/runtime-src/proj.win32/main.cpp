/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "main.h"
#include "cocos2d.h"
#include "AppFrame.h"

USING_NS_CC;

// A portable release keeps legacy relative data/save paths beside the EXE.
// Development launches without the marker retain their chosen working directory.
static bool preparePortableDirectory()
{
    std::vector<WCHAR> path(512);
    for (;;)
    {
        const DWORD length = GetModuleFileNameW(nullptr, path.data(), static_cast<DWORD>(path.size()));
        if (!length)
            return false;
        if (length < path.size())
            break;
        if (path.size() >= 32768)
            return false;
        path.resize(std::min<size_t>(path.size() * 2, 32768));
    }
    const std::wstring executable(path.data());
    const auto separator = executable.find_last_of(L"\\/");
    if (separator == std::wstring::npos)
        return false;
    const auto directory = executable.substr(0, separator + 1);
    const auto attributes = GetFileAttributesW((directory + L"portable.flag").c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES || (attributes & FILE_ATTRIBUTE_DIRECTORY))
        return true;
    return SetCurrentDirectoryW(directory.c_str()) != FALSE;
}

int WINAPI _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	if (!preparePortableDirectory())
	{
		MessageBoxW(nullptr, L"Unable to open the application directory.", L"LuaSTG-x", MB_OK | MB_ICONERROR);
		return 1;
	}

	bool useConsole = false;
	std::vector<std::string> args;
	for (int i = 0; i < __argc; ++i)
	{
		const int length = WideCharToMultiByte(CP_UTF8, 0, __wargv[i], -1, nullptr, 0, nullptr, nullptr);
		if (length <= 0)
			return 1;
		std::string argument(static_cast<size_t>(length), '\0');
		WideCharToMultiByte(CP_UTF8, 0, __wargv[i], -1, argument.data(), length, nullptr, nullptr);
		argument.pop_back();
		args.emplace_back(std::move(argument));
		if (args.back() == "--console" && !useConsole)
		{
			AllocConsole();
			freopen("CONIN$", "r", stdin);
			freopen("CONOUT$", "w", stdout);
			freopen("CONOUT$", "w", stderr);
            useConsole = true;
		}
	}
	lstg::AppFrame::setCmdLineArgs(args);
    int ret = lstg::AppFrame::getInstance()->run();
	lstg::AppFrame::destroyInstance();

	if (useConsole)
		FreeConsole();

    return ret;
}
