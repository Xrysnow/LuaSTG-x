#pragma once
#include "../Classes/LSTG/Global.h"
#include <cstdint>
#include <string>
#include <vector>
#include "../fcyLib/fcyMath.h"
#include "../Classes/Classes/WindowHelper.h"

namespace lstg
{
	enum F2DWINBORDERTYPE
	{
		F2DWINBORDERTYPE_NONE,
		F2DWINBORDERTYPE_FIXED,
		F2DWINBORDERTYPE_SIZEABLE
	};

	enum F2DIMEINFO
	{
		F2DIMEINFO_NULL,
		F2DIMEINFO_CANDIDATECOUNT,  // 候选词个数
		F2DIMEINFO_CANDIDATEINDEX,  // 当前选中的候选词索引
		F2DIMEINFO_PAGESIZE,        // 一页的候选词个数
		F2DIMEINFO_PAGESTART        // 当前页面开始的候选词索引
	};
	// TODO: error handle
	class WindowHelperWin32 : public WindowHelperDesktop
	{
	private:
		// 状态
		HWND m_hWnd;
		bool m_bShow;
		std::wstring m_CaptionText;

		// 输入法上下文
		HIMC m_hIMC;
		bool m_bHideIME;
		std::wstring m_CurIMEDesc;          // 输入法描述
		std::wstring m_CurIMEComposition;   // 输入法组词文本
		uint32_t m_IMETotalCandidate;          // 候选词个数
		uint32_t m_IMESelectedCandidate;       // 选中的候选词索引
		uint32_t m_IMEPageStartCandidate;      // 当前页码中第一个候选词的索引
		uint32_t m_IMEPageCandidateCount;      // 一页的候选词个数
		std::vector<std::wstring> m_IMECandidateList; // 候选词列表

	protected: // 内部方法
		// 初始化输入法上下文
		void InitIMEContext();
		// 取消输入法上下文
		void UninitIMEContext();

		// 处理IME语言变化
		void HandleIMELanguageChanged();
		// 处理组词
		void HandleIMEComposition();
		// 处理选词
		void HandleIMECandidate();
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
		fcyRect GetRect();
		int SetRect(const fcyRect& Range);
		fcyRect GetClientRect();
		int SetClientRect(const fcyRect& Range);
		bool IsTopMost();
		int SetTopMost(bool TopMost);
		void HideMouse(bool bShow);

		bool IsHideIME() { return m_bHideIME; }
		void SetHideIME(bool v) { m_bHideIME = v; }

		const wchar_t* GetIMEDesc()
		{
			return m_CurIMEDesc.c_str();
		}

		uint32_t GetIMEInfo(F2DIMEINFO InfoType);

		const wchar_t* GetIMECompString()
		{
			return m_CurIMEComposition.c_str();
		}
		uint32_t GetIMECandidateCount()
		{
			return m_IMETotalCandidate;
		}
		const wchar_t* GetIMECandidate(uint32_t Index)
		{
			if (Index > m_IMETotalCandidate)
				return nullptr;
			else
				return m_IMECandidateList[Index].c_str();
		}

		//void setTitle(const char* s) override;
		//void setPosition(const cocos2d::Vec2& p) override;
		//void setVisible(bool b) override;

		static void setCloseNotify(bool notify);
		static void setCloseNotifyInfo(const std::string& caption, const std::string& text);

		static BOOL IsWindowsVersionOrGreaterWin32(WORD major, WORD minor, WORD sp);
		static BOOL IsWindows10BuildOrGreaterWin32(WORD build);

		WindowHelperWin32(cocos2d::GLViewImpl* view, HWND handle);
		~WindowHelperWin32();
	};
}
