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

	cc::Vec2 AlignmentToAnchorPoint(cc::TextHAlignment ha, cc::TextVAlignment va);

	void pathUniform(std::string& path, bool forward_slash = false, bool lower = true, bool utf8_convert = false);
	void pathUniform(std::wstring& path, bool forward_slash = false, bool lower = true, bool utf8_convert = false);
	//
	std::string BlendFactor_tostring(cc::backend::BlendFactor factor);

	std::string tostring(const cc::Vec2& v);
	std::string tostring(const cc::Vec3& v);
	std::string tostring(const cc::Vec4& v);
	std::string tostring(const cc::Rect& r);
	std::string tostring(const cc::Color3B& c);
	std::string tostring(const cc::Color4B& c);
	std::string tostring(const cc::Color4F& c);
	std::string tostring(const cc::BlendFunc& b);
	std::string tostring(const cc::V3F_C4B_T2F& v);
	std::string tostring(const cc::V3F_C4B_T2F_Quad& v);
	std::string tostring(const cc::Mat4& m);
	std::string tostring(cc::TextHAlignment ha);
	std::string tostring(cc::TextVAlignment va);

	void transformPoint(cc::Vec3& point, const cc::Vec2& anchorPIP,
		float x, float y, float rot, float hscale, float vscale, float z);
	void transformQuad(cc::V3F_C4B_T2F_Quad& quad, const cc::Vec2& anchorPIP,
		float x, float y, float rot, float hscale, float vscale, float z);
	void getNodeTransform(const cc::Vec2& anchorPointInPoints,
		float x, float y, float rot, float hscale, float vscale, float z, cc::Mat4* out);
	cc::Mat4 getNodeTransform(const cc::Vec2& anchorPointInPoints,
		float x, float y, float rot, float hscale, float vscale, float z);

	void getQuaternion(const cc::Vec3& axis, float angle, cc::Quaternion* out);

	void getRotationTransform(const cc::Quaternion& q, cc::Mat4* out);
	void getRotationTransform(const cc::Vec3& axis, float angle, cc::Mat4* out);
	
	void getNodeTransform3D(const cc::Vec2& anchorPointInPoints,
		float x, float y, float z, const cc::Quaternion& q,
		float hscale, float vscale, float zscale, cc::Mat4* out);
	void getNodeTransform3D(const cc::Vec2& anchorPointInPoints,
		float x, float y, float z, const cc::Vec3& axis, float angle,
		float hscale, float vscale, float zscale, cc::Mat4* out);

	cc::Image* getTextureImage(cc::Texture2D* texture, bool flipImage = false);
	cc::Image* getTextureImage(cc::Texture2D* texture,
		size_t x, size_t y, size_t width, size_t height, bool flipImage = false);
	cc::Image* getSpriteImage(cc::Sprite* sprite, bool flipImage = false);
	bool initImageWithSVG(cc::Image* image, const std::string& path,
		float scale, const std::string& units = "px", float dpi = 96);
	bool initImageWithSVG(cc::Image* image, const std::string& path,
		const cc::Size& size);

	// (start, end, iThread)
	void deployThreadTask(size_t taskSize, size_t nSlice, const std::function<void(int, int, int)>& task);
	void deployThreadTaskAndWait(size_t taskSize, size_t nSlice, const std::function<void(int, int, int)>& task);
	std::vector<std::future<std::shared_ptr<void>>> deployThreadTaskFuture(size_t taskSize, size_t nSlice,
		const std::function<std::shared_ptr<void>(int, int, int)>& task);

	uint32_t XXHash32(const void* data, size_t size, uint32_t seed = 0);
	uint64_t XXHash64(const void* data, size_t size, uint64_t seed = 0);
	void RC4XOR(const std::string& key, const void* data, size_t size, void* out);
	std::string MD5Hash(const void* data, size_t size);

	// RC4 cryption
	class RC4
	{
		uint8_t S[256];
	public:
		void operator()(const uint8_t* input, size_t inputlen, uint8_t* output);
		RC4(const char* password, size_t len);
	};

	namespace util
	{
		cc::Viewport Viewport(float left, float right, float bottom, float top);

		std::vector<std::string> stringSplit(const std::string& str, const std::string& delimiter, bool trim);
		std::string stringTrimLeft(const std::string &str);
		std::string stringTrimRight(const std::string &str);
		std::string stringTrim(const std::string &str);
		std::wstring MultiByteToWideChar_UTF8(const std::string& str);
		std::string WideCharToMultiByte_UTF8(const std::wstring& str);

		bool BlendOperationFromString(const std::string& str, cc::backend::BlendOperation& val);
		bool BlendFactorFromString(const std::string& str, cc::backend::BlendFactor& val);
		cc::IntrusivePtr<cc::backend::Program> CreateProgramFromPath(const std::string& v, const std::string& f);
		cc::IntrusivePtr<cc::backend::Program> CreateProgramFromString(const std::string& v, const std::string& f);
		cc::IntrusivePtr<cc::backend::Program> CreateProgramFromData(cc::Data* v, cc::Data* f);
		bool CheckBlendOperation(cc::backend::BlendOperation equation);
		bool CheckBlendFactor(cc::backend::BlendFactor func);
	}
}
