#include "WindowHelperWin32.h"

using namespace lstg;

#define F2DWINDOWSTYLENONEBORDER     ( WS_POPUP   | WS_SYSMENU )
#define F2DWINDOWSTYLEFIXEDBORDER    ( WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION )
#define F2DWINDOWSTYLESIZEABLEBORDER ( WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CAPTION | WS_THICKFRAME )

int32_t WindowHelperWin32::GetHandle()
{
	return (int32_t)m_hWnd;
}

void WindowHelperWin32::SetAbsoluteForeground()
{
	DWORD nTargetID, nForegroundID;
	DWORD sp_time;
	nForegroundID = GetWindowThreadProcessId(GetForegroundWindow(), NULL);
	nTargetID = GetWindowThreadProcessId(m_hWnd, NULL);
	AttachThreadInput(nTargetID, nForegroundID, TRUE);
	SystemParametersInfoW(SPI_GETFOREGROUNDLOCKTIMEOUT, 0, &sp_time, 0);
	SystemParametersInfoW(SPI_SETFOREGROUNDLOCKTIMEOUT, 0, (LPVOID)0, 0);
	//Sleep(1);

	SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	SetWindowPos(m_hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	//BringWindowToTop(handle);
	AllowSetForegroundWindow(ASFW_ANY);
	SetForegroundWindow(m_hWnd);
	SetActiveWindow(m_hWnd);
	//SetFocus(hWnd);

	//Sleep(1);
	SystemParametersInfoW(SPI_SETFOREGROUNDLOCKTIMEOUT, 0, &sp_time, 0);
	AttachThreadInput(nTargetID, nForegroundID, FALSE);
}

int WindowHelperWin32::PopMessageBox(const std::wstring& text, const std::wstring& caption, bool moreButton)
{
	auto flag = MB_ICONERROR;
	if (moreButton)
		flag = flag | MB_ABORTRETRYIGNORE;
	else
		flag = flag | MB_OK;
	return MessageBoxW(m_hWnd, text.c_str(), caption.c_str(), flag);
}

F2DWINBORDERTYPE WindowHelperWin32::GetBorderType()
{
	if (!m_hWnd) return F2DWINBORDERTYPE_NONE;
	uint32_t tStyle = GetWindowLong(m_hWnd, GWL_STYLE);
	switch (tStyle)
	{
	case F2DWINDOWSTYLENONEBORDER:
		return F2DWINBORDERTYPE_NONE;
	case F2DWINDOWSTYLEFIXEDBORDER:
		return F2DWINBORDERTYPE_FIXED;
	case F2DWINDOWSTYLESIZEABLEBORDER:
		return F2DWINBORDERTYPE_SIZEABLE;
	default:
		return F2DWINBORDERTYPE_NONE;
	}
}

int WindowHelperWin32::SetBorderType(F2DWINBORDERTYPE Type)
{
	if (!m_hWnd) return 0;
	switch (Type)
	{
	case F2DWINBORDERTYPE_NONE:
		SetWindowLong(m_hWnd, GWL_STYLE, F2DWINDOWSTYLENONEBORDER);
		break;
	case F2DWINBORDERTYPE_FIXED:
		SetWindowLong(m_hWnd, GWL_STYLE, F2DWINDOWSTYLEFIXEDBORDER);
		break;
	case F2DWINBORDERTYPE_SIZEABLE:
		SetWindowLong(m_hWnd, GWL_STYLE, F2DWINDOWSTYLESIZEABLEBORDER);
		break;
	default:
		return 0;
	}

	SetWindowPos(m_hWnd, NULL, 0, 0, 0, 0, m_bShow ? SWP_SHOWWINDOW | SWP_NOZORDER | SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE : SWP_NOZORDER | SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE);
	return 1;
}

const wchar_t* WindowHelperWin32::GetCaption()
{
	wchar_t tTemp[1024];
	GetWindowText(m_hWnd, tTemp, 1024);
	m_CaptionText = tTemp;
	return m_CaptionText.c_str();
}

int WindowHelperWin32::SetCaption(const wchar_t* Caption)
{
	if (!m_hWnd) return 0;
	m_CaptionText = Caption;
	return SetWindowText(m_hWnd, Caption) == TRUE;
}

bool WindowHelperWin32::GetVisiable()
{
	return m_bShow;
}

int WindowHelperWin32::SetVisiable(bool Visiable)
{
	if (!m_hWnd) return 0;
	m_bShow = Visiable;
	return ShowWindow(m_hWnd, m_bShow ? SW_SHOW : SW_HIDE) == TRUE;
}

cc::Rect WindowHelperWin32::GetRect()
{
	RECT tRect;
	GetWindowRect(m_hWnd, &tRect);
	return {
		(float)tRect.left,
		(float)tRect.bottom,
		(float)tRect.right - tRect.left,
		(float)tRect.top - tRect.bottom };
}

int WindowHelperWin32::SetRect(const cc::Rect& Range)
{
	if (!m_hWnd) return 0;
	return SetWindowPos(m_hWnd, 0,
		(int)Range.getMinX(), (int)Range.getMaxY(),
		(int)Range.size.width, (int)Range.size.height,
		SWP_NOZORDER) == TRUE;
}

cc::Rect WindowHelperWin32::GetClientRect()
{
	RECT tRect;
	::GetClientRect(m_hWnd, &tRect);
	return {
		(float)tRect.left,
		(float)tRect.bottom,
		(float)tRect.right - tRect.left,
		(float)tRect.top - tRect.bottom };
}

int WindowHelperWin32::SetClientRect(const cc::Rect& Range)
{
	RECT tWinRect = { (int)Range.getMinX() , (int)Range.getMaxY() , (int)Range.getMaxX() , (int)Range.getMinY() };
	AdjustWindowRect(&tWinRect, GetWindowLong(m_hWnd, GWL_STYLE), FALSE);
	return SetWindowPos(m_hWnd, 0,
		tWinRect.left, tWinRect.top,
		tWinRect.right - tWinRect.left, tWinRect.bottom - tWinRect.top,
		SWP_NOZORDER) == TRUE;
}

bool WindowHelperWin32::IsTopMost()
{
	return (WS_EX_TOPMOST & GetWindowLong(m_hWnd, GWL_EXSTYLE)) != 0;
}

int WindowHelperWin32::SetTopMost(bool TopMost)
{
	if (!m_hWnd) return 0;
	if (TopMost)
		if (SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE) == FALSE)
			return 0;
		else
			return 1;
	else
		if (SetWindowPos(m_hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE) == FALSE)
			return 0;
		else
			return 1;
}

void WindowHelperWin32::HideMouse(bool bHide)
{
	ShowCursor((BOOL)!bHide);
}

void WindowHelperWin32::setCloseNotify(bool notify)
{
	//SimulatorWin::setCloseNotify(notify);
}

void WindowHelperWin32::setCloseNotifyInfo(const std::string& caption, const std::string& text)
{
	//SimulatorWin::setCloseNotifyInfo(caption, text);
}

typedef LONG(WINAPI * PFN_RtlVerifyVersionInfo)(OSVERSIONINFOEXW*, ULONG, ULONGLONG);

BOOL WindowHelperWin32::IsWindowsVersionOrGreaterWin32(WORD major, WORD minor, WORD sp)
{
	const auto ntdll = LoadLibraryA("ntdll.dll");
	if(ntdll)
	{
		auto RtlVerifyVersionInfo = (PFN_RtlVerifyVersionInfo)
			GetProcAddress(ntdll, "RtlVerifyVersionInfo");
		if (RtlVerifyVersionInfo)
		{
			OSVERSIONINFOEXW osvi = { sizeof(osvi), major, minor, 0, 0, {0}, sp };
			DWORD mask = VER_MAJORVERSION | VER_MINORVERSION | VER_SERVICEPACKMAJOR;
			ULONGLONG cond = VerSetConditionMask(0, VER_MAJORVERSION, VER_GREATER_EQUAL);
			cond = VerSetConditionMask(cond, VER_MINORVERSION, VER_GREATER_EQUAL);
			cond = VerSetConditionMask(cond, VER_SERVICEPACKMAJOR, VER_GREATER_EQUAL);
			// HACK: Use RtlVerifyVersionInfo instead of VerifyVersionInfoW as the
			//       latter lies unless the user knew to embedd a non-default manifest
			//       announcing support for Windows 10 via supportedOS GUID
			return RtlVerifyVersionInfo(&osvi, mask, cond) == 0;
		}
	}
	return 0;
}

BOOL WindowHelperWin32::IsWindows10BuildOrGreaterWin32(WORD build)
{
	const auto ntdll = LoadLibraryA("ntdll.dll");
	if (ntdll)
	{
		auto RtlVerifyVersionInfo = (PFN_RtlVerifyVersionInfo)
			GetProcAddress(ntdll, "RtlVerifyVersionInfo");
		if (RtlVerifyVersionInfo)
		{
			OSVERSIONINFOEXW osvi = { sizeof(osvi), 10, 0, build };
			DWORD mask = VER_MAJORVERSION | VER_MINORVERSION | VER_BUILDNUMBER;
			ULONGLONG cond = VerSetConditionMask(0, VER_MAJORVERSION, VER_GREATER_EQUAL);
			cond = VerSetConditionMask(cond, VER_MINORVERSION, VER_GREATER_EQUAL);
			cond = VerSetConditionMask(cond, VER_BUILDNUMBER, VER_GREATER_EQUAL);
			// HACK: Use RtlVerifyVersionInfo instead of VerifyVersionInfoW as the
			//       latter lies unless the user knew to embedd a non-default manifest
			//       announcing support for Windows 10 via supportedOS GUID
			return RtlVerifyVersionInfo(&osvi, mask, cond) == 0;
		}
	}
	return 0;
}

WindowHelperWin32::WindowHelperWin32(cc::GLViewImpl* view, HWND handle)
	: WindowHelperDesktop(view), m_hWnd(handle), m_bShow(false), m_CaptionText(L"")
{
}

WindowHelperWin32::~WindowHelperWin32()
{
}
