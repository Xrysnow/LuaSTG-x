#pragma once
#include "Global.h"
#include "../Classes/XStopWatch.h"

namespace lstg
{
	class Scope
	{
	private:
		std::function<void()> m_WhatToDo;
	public:
		Scope& operator=(const Scope&) = delete;
		Scope(const Scope&) = delete;
		Scope(std::function<void()> exitJob)
			: m_WhatToDo(exitJob) {}
		~Scope()
		{
			m_WhatToDo();
		}
	};

	class TimerScope
	{
	private:
		StopWatch m_StopWatch;
		float& m_Out;
	public:
		TimerScope(float& Out)
			: m_Out(Out)
		{
		}
		~TimerScope()
		{
			m_Out = static_cast<float>(m_StopWatch.get());
		}
	};

	/** @brief string format, va_list\n
	* @code
	* bool     b; int32_t   c; unsigned int p;
	* int32_t  d; uint32_t  u; double  f;
	* int64_t ld; uint64_t lu; double lf;
	* char*    s; wchar_t*  w; @endcode
	*/
	std::string StringFormat(const char* Format, ...)noexcept;
	std::string StringFormatV(const char* Format, va_list vaptr)noexcept;

	/** dump lua stack */
	std::string stackDump(lua_State *L);

	std::string ReplacePathSep(std::string path, const std::string& ori = "\\", const std::string& dst = "/");

	cocos2d::Vec2 AlignmentToAnchorPoint(cocos2d::TextHAlignment ha, cocos2d::TextVAlignment va);

	void pathUniform(std::string& path, bool forward_slash = false, bool lower = true, bool utf8_convert = false);
	void pathUniform(std::wstring& path, bool forward_slash = false, bool lower = true, bool utf8_convert = false);
	//
	std::string BlendFactor_tostring(cocos2d::backend::BlendFactor factor);

	std::string tostring(const cocos2d::Vec2& v);
	std::string tostring(const cocos2d::Vec3& v);
	std::string tostring(const cocos2d::Vec4& v);
	std::string tostring(const cocos2d::Size& s);
	std::string tostring(const cocos2d::Rect& r);
	std::string tostring(const cocos2d::Color3B& c);
	std::string tostring(const cocos2d::Color4B& c);
	std::string tostring(const cocos2d::Color4F& c);
	std::string tostring(const cocos2d::BlendFunc& b);
	std::string tostring(const cocos2d::V3F_C4B_T2F& v);
	std::string tostring(const cocos2d::V3F_C4B_T2F_Quad& v);
	std::string tostring(const cocos2d::Mat4& m);
	std::string tostring(cocos2d::TextHAlignment ha);
	std::string tostring(cocos2d::TextVAlignment va);

	void getNodeTransform(const cocos2d::Vec2& anchorPointInPoints,
		float x, float y, float rot, float hscale, float vscale, float z, cocos2d::Mat4* out);
	cocos2d::Mat4 getNodeTransform(const cocos2d::Vec2& anchorPointInPoints,
		float x, float y, float rot, float hscale, float vscale, float z);

	void getQuaternion(const cocos2d::Vec3& axis, float angle, cocos2d::Quaternion* out);

	void getRotationTransform(const cocos2d::Quaternion& q, cocos2d::Mat4* out);
	void getRotationTransform(const cocos2d::Vec3& axis, float angle, cocos2d::Mat4* out);
	
	void getNodeTransform3D(const cocos2d::Vec2& anchorPointInPoints,
		float x, float y, float z, const cocos2d::Quaternion& q,
		float hscale, float vscale, float zscale, cocos2d::Mat4* out);
	void getNodeTransform3D(const cocos2d::Vec2& anchorPointInPoints,
		float x, float y, float z, const cocos2d::Vec3& axis, float angle,
		float hscale, float vscale, float zscale, cocos2d::Mat4* out);

	cocos2d::Image* getTextureImage(cocos2d::Texture2D* texture, bool flipImage = false);
	cocos2d::Image* getTextureImage(cocos2d::Texture2D* texture,
		size_t x, size_t y, size_t width, size_t height, bool flipImage = false);
	cocos2d::Image* getSpriteImage(cocos2d::Sprite* sprite, bool flipImage = false);

	// (start, end, iThread)
	void deployThreadTask(size_t taskSize, size_t nSlice, const std::function<void(int, int, int)>& task);
	void deployThreadTaskAndWait(size_t taskSize, size_t nSlice, const std::function<void(int, int, int)>& task);
	std::vector<std::future<std::shared_ptr<void>>> deployThreadTaskFuture(size_t taskSize, size_t nSlice,
		const std::function<std::shared_ptr<void>(int, int, int)>& task);

	// RC4 cryption
	class RC4
	{
	private:
		uint8_t S[256];
	public:
		void operator()(const uint8_t* input, size_t inputlen, uint8_t* output);
		RC4(const uint8_t* password, size_t len);
	};

	namespace util
	{
		cocos2d::Viewport Viewport(float left, float right, float bottom, float top);

		std::vector<std::string> stringSplit(const std::string& str, const std::string& delimiter, bool trim);
		std::string stringTrimLeft(const std::string &str);
		std::string stringTrimRight(const std::string &str);
		std::string stringTrim(const std::string &str);
		std::wstring MultiByteToWideChar_UTF8(const std::string& str);
		std::string WideCharToMultiByte_UTF8(const std::wstring& str);

		bool BlendOperationFromString(const std::string& str, cocos2d::backend::BlendOperation& val);
		bool BlendFactorFromString(const std::string& str, cocos2d::backend::BlendFactor& val);
		cocos2d::backend::Program* CreateProgramFromPath(const std::string& v, const std::string& f);
		cocos2d::backend::Program* CreateProgramFromString(const std::string& v, const std::string& f);
		cocos2d::backend::Program* CreateProgramFromData(cocos2d::Data* v, cocos2d::Data* f);
		bool CheckFragmentShader(const std::string& src);
		bool CheckVertexShader(const std::string& src);
		bool CheckBlendOperation(cocos2d::backend::BlendOperation equation);
		bool CheckBlendFactor(cocos2d::backend::BlendFactor func);
	}
}
