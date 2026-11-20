#pragma once
#include "../../LSTG/Global.h"
#include <cstdint>
#include <string>
#include "../../Classes/WindowHelper.h"

namespace lstg
{
	enum F2DWINBORDERTYPE
	{
		F2DWINBORDERTYPE_NONE,
		F2DWINBORDERTYPE_FIXED,
		F2DWINBORDERTYPE_SIZEABLE
	};

	// TODO: error handle
	class WindowHelperWin32 : public WindowHelperDesktop
	{
	private:
		// 状态
		HWND m_hWnd;
		bool m_bShow;
		std::wstring m_CaptionText;

	public: // 接口实现

		int32_t GetHandle();

		void SetAbsoluteForeground();
		int PopMessageBox(const std::wstring& text, const std::wstring& caption, bool moreButton);

		F2DWINBORDERTYPE GetBorderType();
		int SetBorderType(F2DWINBORDERTYPE Type);
		const wchar_t* GetCaption();
		int SetCaption(const wchar_t* Caption);
		bool GetVisiable();
		int SetVisiable(bool Visiable);
		cc::Rect GetRect();
		int SetRect(const cc::Rect& Range);
		cc::Rect GetClientRect();
		int SetClientRect(const cc::Rect& Range);
		bool IsTopMost();
		int SetTopMost(bool TopMost);
		void HideMouse(bool bShow);

		static void setCloseNotify(bool notify);
		static void setCloseNotifyInfo(const std::string& caption, const std::string& text);

		static BOOL IsWindowsVersionOrGreaterWin32(WORD major, WORD minor, WORD sp);
		static BOOL IsWindows10BuildOrGreaterWin32(WORD build);

		WindowHelperWin32(cc::GLViewImpl* view, HWND handle);
		~WindowHelperWin32();
	};
}
