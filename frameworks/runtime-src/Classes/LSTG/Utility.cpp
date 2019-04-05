#include "Utility.h"
#include "UtilGLDefinition.h"
#include "AppFrame.h"
#include "../fcyLib/fcyMisc/fcyStringHelper.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;

string lstg::StringFormat(const char* Format, ...)noexcept
{
	va_list vaptr;
	va_start(vaptr, Format);
	string tRet = StringFormatV(Format, vaptr);
	va_end(vaptr);
	return tRet;
}

string lstg::StringFormatV(const char* Format, va_list vaptr)noexcept
{
	string tRet;
	try
	{
		while (*Format != '\0')
		{
			char c = *Format;
			if (c != '%')
				tRet.push_back(c);
			else
			{
				c = *(++Format);

				switch (c)
				{
				case '%':
					tRet.push_back('%');
					break;
				case 'b':
					tRet.append(va_arg(vaptr, bool) ? "true" : "false");
					break;
				case 'd':
					tRet.append(to_string(va_arg(vaptr, int32_t)));
					break;
				case 'f':
					tRet.append(to_string(va_arg(vaptr, double)));
					break;
				case 'l':
					c = *(++Format);
					switch (c)
					{
					case 'f':
						tRet.append(to_string(va_arg(vaptr, double)));
						break;
					case 'd':
						tRet.append(to_string(va_arg(vaptr, int64_t)));
						break;
					case 'u':
						tRet.append(to_string(va_arg(vaptr, uint64_t)));
						break;
					default:
						tRet.append("%l");
						if (c == '\0')
							Format--;
						else
							tRet.push_back(c);
						break;
					}
					break;
				case 'u':
					tRet.append(to_string(va_arg(vaptr, uint32_t)));
					break;
				case 'p':
					tRet.append(to_string(va_arg(vaptr, unsigned int)));
					break;
				case 'c':
					tRet.push_back(va_arg(vaptr, int32_t));
					break;
				case 's':
					{
						const char* p = va_arg(vaptr, char*);
						if (p)
							tRet.append(p);
						else
							tRet.append("<null>");
					}
					break;
				case 'w':
					{
						const wchar_t* p = va_arg(vaptr, wchar_t*);
						if (p)
							tRet.append(move(fcyStringHelper::WideCharToMultiByte_UTF8(p)));
						else
							tRet.append("<null>");
					}
					break;
				default:
					tRet.push_back('%');
					if (c == '\0')
						Format--;
					else
						tRet.push_back(c);
					break;
				}
			}
			Format++;
		}
	}
	catch (const bad_alloc&)
	{
	}

	return tRet;
}

wstring lstg::StringFormat(const wchar_t* Format, ...)noexcept
{
	va_list vaptr;
	va_start(vaptr, Format);
	wstring tRet = StringFormatV(Format, vaptr);
	va_end(vaptr);
	return tRet;
}

wstring lstg::StringFormatV(const wchar_t* Format, va_list vaptr)noexcept
{
	wstring tRet;
	try
	{
		while (*Format != L'\0')
		{
			wchar_t c = *Format;
			if (c != L'%')
				tRet.push_back(c);
			else
			{
				c = *(++Format);

				switch (c)
				{
				case L'%':
					tRet.push_back(L'%');
					break;
				case 'b':
					tRet.append(va_arg(vaptr, bool) ? L"true" : L"false");
					break;
				case L'd':
					tRet.append(to_wstring(va_arg(vaptr, int32_t)));
					break;
				case L'f':
					tRet.append(to_wstring(va_arg(vaptr, double)));
					break;
				case L'l':
					c = *(++Format);
					switch (c)
					{
					case L'f':
						tRet.append(to_wstring(va_arg(vaptr, double)));
						break;
					case L'd':
						tRet.append(to_wstring(va_arg(vaptr, int64_t)));
						break;
					case L'u':
						tRet.append(to_wstring(va_arg(vaptr, uint64_t)));
						break;
					default:
						tRet.append(L"%l");
						if (c == L'\0')
							Format--;
						else
							tRet.push_back(c);
						break;
					}
					break;
				case L'u':
					tRet.append(to_wstring(va_arg(vaptr, uint32_t)));
					break;
				case L'p':
					tRet.append(to_wstring(va_arg(vaptr, unsigned int)));
					break;
				case L'c':
					tRet.push_back(va_arg(vaptr, int32_t));
					break;
				case L's':
					{
						const wchar_t* p = va_arg(vaptr, wchar_t*);
						if (p)
							tRet.append(p);
						else
							tRet.append(L"<null>");
					}
					break;
				case 'm':
					{
						const char* p = va_arg(vaptr, char*);
						if (p)
							tRet.append(move(fcyStringHelper::MultiByteToWideChar_UTF8(p)));
						else
							tRet.append(L"<null>");
					}
					break;
				default:
					tRet.push_back(L'%');
					if (c == L'\0')
						Format--;
					else
						tRet.push_back(c);
					break;
				}
			}
			Format++;
		}
	}
	catch (const bad_alloc&)
	{
	}

	return move(tRet);
}

void lstg::stackDump(lua_State *L) {
	int i;
	int top = lua_gettop(L);
	string s = "\n";
	for (i = 1; i <= top; i++) {
		s += "[" + to_string(i) + "] = ";
		int t = lua_type(L, i);
		switch (t) {

		case LUA_TSTRING:
			s += "\'";
			s += lua_tostring(L, i);
			s += "\'";
			break;

		case LUA_TBOOLEAN:
			if (lua_toboolean(L, i))
			{
				s += "true";
			}
			else { s += "false"; }
			break;

		case LUA_TNUMBER:
			s += to_string(lua_tonumber(L, i));
			break;

		default:
			s += lua_typename(L, t);
			break;

		}
		s += "\n";
	}
	LINFO("=== Lua Stack Dump ===\n%s", s.c_str());
}

string lstg::ReplacePathSep(string path, const string& ori, const string& dst)
{
	auto ret = path;
	size_t pos;
	while ((pos = ret.find_first_of(ori)) != string::npos)
	{
		ret.replace(pos, 1, dst);
	}
	return ret;
}

Vec2 lstg::AlignmentToAnchorPoint(TextHAlignment ha, TextVAlignment va)
{
	Vec2 ret;
	switch (ha)
	{
	case TextHAlignment::LEFT: ret.x = 0.f; break;
	case TextHAlignment::CENTER: ret.x = 0.5f; break;
	case TextHAlignment::RIGHT: ret.x = 1.f; break;
	}
	switch (va)
	{
	case TextVAlignment::TOP: ret.y = 1.f; break;
	case TextVAlignment::CENTER: ret.y = 0.5f; break;
	case TextVAlignment::BOTTOM: ret.y = 0.f; break;
	}
	return ret;
}

template <typename T>
void _pathUniform(T begin, T end, bool forward_slash, bool lower)
{
	while (begin != end)
	{
		int c = *begin;
		if (c == 0)
			break;
		if (lower)
		{
			if (c >= 'A' && c <= 'Z')
				*begin = c - 'A' + 'a';
		}
		else
		{
			if (c >= 'a' && c <= 'z')
				*begin = c - 'a' + 'A';
		}
		if (forward_slash)
		{
			if (c == '\\')
				*begin = '/';
		}
		else
		{
			if (c == '/')
				*begin = '\\';
		}
		++begin;
	}
}

void lstg::pathUniform(string& path, bool forward_slash, bool lower, bool utf8_convert)
{
	if (path[0] == '.' && (path[1] == '/' || path[1] == '\\'))path = path.substr(2);
	if (utf8_convert)
	{
		auto s = fcyStringHelper::MultiByteToWideChar_UTF8(path);
		_pathUniform(s.begin(), s.end(), forward_slash, lower);
		path = fcyStringHelper::WideCharToMultiByte_UTF8(s);
	}
	else
		_pathUniform(path.begin(), path.end(), forward_slash, lower);
}

void lstg::pathUniform(wstring& path, bool forward_slash, bool lower, bool utf8_convert)
{
	if (path[0] == L'.' && (path[1] == L'/' || path[1] == L'\\'))path = path.substr(2);
	if (utf8_convert)
	{
		auto s = fcyStringHelper::WideCharToMultiByte_UTF8(path);
		_pathUniform(s.begin(), s.end(), forward_slash, lower);
		path = fcyStringHelper::MultiByteToWideChar_UTF8(s);
	}
	else
		_pathUniform(path.begin(), path.end(), forward_slash, lower);
}

string lstg::glBlend_tostring(GLenum blend)
{
	switch (blend)
	{
	case GL_ZERO:return "GL_ZERO";
	case GL_ONE:return "GL_ONE";
	case GL_SRC_COLOR:return "GL_SRC_COLOR";
	case GL_ONE_MINUS_SRC_COLOR:return "GL_ONE_MINUS_SRC_COLOR";
	case GL_SRC_ALPHA:return "GL_SRC_ALPHA";
	case GL_ONE_MINUS_SRC_ALPHA:return "GL_ONE_MINUS_SRC_ALPHA";
	case GL_DST_COLOR:return "GL_DST_COLOR";
	case GL_ONE_MINUS_DST_COLOR:return "GL_ONE_MINUS_DST_COLOR";
	default: ;
	}
	return "UNKNOWN";
}

string lstg::tostring(const Vec2& v)
{
	return StringUtils::format("(%.3f, %.3f)", v.x, v.y);
}

string lstg::tostring(const Vec3& v)
{
	return StringUtils::format("(%.3f, %.3f, %.3f)", v.x, v.y, v.z);
}

string lstg::tostring(const Vec4& v)
{
	return StringUtils::format("(%.3f, %.3f, %.3f, %.3f)", v.x, v.y, v.z, v.w);
}

string lstg::tostring(const Size& s)
{
	return StringUtils::format("(w = %.3f, h = %.3f)", s.width, s.height);
}

string lstg::tostring(const Rect& r)
{
	return "(o = " + tostring(r.origin) + ", s = " + tostring(r.size) + ")";
}

string lstg::tostring(const Color3B& c)
{
	return "(" +
		to_string(c.r) + ", " +
		to_string(c.g) + ", " +
		to_string(c.b) + ")";
}

string lstg::tostring(const Color4B& c)
{
	return "(" +
		to_string(c.a) + ", " +
		to_string(c.r) + ", " +
		to_string(c.g) + ", " +
		to_string(c.b) + ")";
}

string lstg::tostring(const Color4F& c)
{
	return "(" +
		to_string(c.a) + ", " +
		to_string(c.r) + ", " +
		to_string(c.g) + ", " +
		to_string(c.b) + ")";
}

string lstg::tostring(const BlendFunc& b)
{
	return "(src = " + glBlend_tostring(b.src) + ", dst = " + glBlend_tostring(b.dst) + ")";
}

string lstg::tostring(const V3F_C4B_T2F& v)
{
	string ret = StringUtils::format("uv: (%.3f, %.3f)", v.texCoords.u, v.texCoords.v);
	ret += ", vert: " + tostring(v.vertices);
	ret += ", c: " + tostring(v.colors);
	return ret;
}

string lstg::tostring(const V3F_C4B_T2F_Quad& v)
{
	string ret = "tl: " + tostring(v.tl);
	ret += "\ntr: " + tostring(v.tr);
	ret += "\nbl: " + tostring(v.bl);
	ret += "\nbr: " + tostring(v.br);
	return ret;
}

string lstg::tostring(const Mat4& m)
{
	return StringFormat("%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f",
		m.m[0], m.m[4], m.m[8], m.m[12],
		m.m[1], m.m[5], m.m[9], m.m[13],
		m.m[2], m.m[6], m.m[10], m.m[14],
		m.m[3], m.m[7], m.m[11], m.m[15]);
}

string lstg::tostring(TextHAlignment ha)
{
	switch (ha)
	{
	case TextHAlignment::LEFT: return "left";
	case TextHAlignment::CENTER: return "center";
	case TextHAlignment::RIGHT: return "right";
	default: ;
	}
	return "";
}

string lstg::tostring(TextVAlignment va)
{
	switch (va)
	{
	case TextVAlignment::TOP: return "top";
	case TextVAlignment::CENTER: return "center";
	case TextVAlignment::BOTTOM: return "bottom";
	default: ;
	}
	return "";
}

void lstg::getNodeTransform(const Vec2& anchorPointInPoints,
	float x, float y, float rot, float hscale, float vscale, float z, Mat4* _transform)
{
	float zz2_;
	float wz2;
	// assert that most rot are 0
	if (rot == 0.f)
	{
		zz2_ = 1.0f;
		wz2 = 0;
	}
	else
	{
		const float halfRadz = -(rot * .5f * 0.01745329252f);
		const float qz = std::sin(halfRadz);
		const float qw = std::cos(halfRadz);
		const float z2 = qz + qz;
		zz2_ = 1.0f - qz * z2;
		wz2 = qw * z2;
	}

	_transform->m[0] = zz2_;
	_transform->m[1] = wz2;
	_transform->m[2] = 0.0f;
	_transform->m[3] = 0.0f;

	_transform->m[4] = -wz2;
	_transform->m[5] = zz2_;
	_transform->m[6] = 0.0f;
	_transform->m[7] = 0.0f;

	_transform->m[8] = 0.0f;
	_transform->m[9] = 0.0f;
	_transform->m[10] = 1.0f;
	_transform->m[11] = 0.0f;

	_transform->m[12] = x;
	_transform->m[13] = y;
	_transform->m[14] = z;
	_transform->m[15] = 1.0f;

	// note that m[2] and m[6] are 0
	if (hscale != 1.f)
	{
		_transform->m[0] *= hscale;
		_transform->m[1] *= hscale;
		//_transform->m[2] *= hscale;
	}
	if (vscale != 1.f)
	{
		_transform->m[4] *= vscale;
		_transform->m[5] *= vscale;
		//_transform->m[6] *= vscale;
	}
	// assert that most anchor points are not 0 (usually center)
	//if (!anchorPointInPoints.isZero())
	//{
		//_transform->m[12] += _transform->m[0] * -anchorPointInPoints.x + _transform->m[4] * -anchorPointInPoints.y;
		//_transform->m[13] += _transform->m[1] * -anchorPointInPoints.x + _transform->m[5] * -anchorPointInPoints.y;
		//_transform->m[14] += _transform->m[2] * -anchorPointInPoints.x + _transform->m[6] * -anchorPointInPoints.y;
		_transform->m[12] -= _transform->m[0] * anchorPointInPoints.x + _transform->m[4] * anchorPointInPoints.y;
		_transform->m[13] -= _transform->m[1] * anchorPointInPoints.x + _transform->m[5] * anchorPointInPoints.y;
	//}
}

Mat4 lstg::getNodeTransform(const Vec2& anchorPointInPoints,
	float x, float y, float rot, float hscale, float vscale, float z)
{
	Mat4 ret;
	getNodeTransform(anchorPointInPoints, x, y, rot, hscale, vscale, z, &ret);
	return ret;
}

void lstg::getQuaternion(const Vec3& axis, float angle, Quaternion* out)
{
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;
	float n = x * x + y * y + z * z;
	if (n != 1.f)
	{
		n = std::sqrt(n);
		if (n > MATH_TOLERANCE)
		{
			x /= n;
			y /= n;
			z /= n;
		}
	}
	const float halfAngle = angle * 0.5f;
	const float s = std::sin(halfAngle);
	const float c = std::cos(halfAngle);
	out->x = x * s;
	out->y = y * s;
	out->z = z * s;
	out->w = c;
}

void lstg::getRotationTransform(const Quaternion& q, Mat4* out)
{
	const float x2 = q.x + q.x;
	const float y2 = q.y + q.y;
	const float z2 = q.z + q.z;

	const float xx2 = q.x * x2;
	const float yy2 = q.y * y2;
	const float zz2 = q.z * z2;
	const float xy2 = q.x * y2;
	const float xz2 = q.x * z2;
	const float yz2 = q.y * z2;
	const float wx2 = q.w * x2;
	const float wy2 = q.w * y2;
	const float wz2 = q.w * z2;

	out->m[0] = 1.0f - yy2 - zz2;
	out->m[1] = xy2 + wz2;
	out->m[2] = xz2 - wy2;
	out->m[3] = 0.0f;

	out->m[4] = xy2 - wz2;
	out->m[5] = 1.0f - xx2 - zz2;
	out->m[6] = yz2 + wx2;
	out->m[7] = 0.0f;

	out->m[8] = xz2 + wy2;
	out->m[9] = yz2 - wx2;
	out->m[10] = 1.0f - xx2 - yy2;
	out->m[11] = 0.0f;

	out->m[12] = 0.0f;
	out->m[13] = 0.0f;
	out->m[14] = 0.0f;
	out->m[15] = 1.0f;
}

void lstg::getRotationTransform(const Vec3& axis, float angle, Mat4* out)
{
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;
	// Make sure the input axis is normalized.
	float n = x * x + y * y + z * z;
	if (n != 1.0f)
	{
		n = std::sqrt(n);
		if (n > MATH_TOLERANCE)
		{
			n = 1.0f / n;
			x *= n;
			y *= n;
			z *= n;
		}
	}

	const float c = std::cos(angle);
	const float s = std::sin(angle);

	const float t = 1.0f - c;
	const float tx = t * x;
	const float ty = t * y;
	const float tz = t * z;
	const float txy = tx * y;
	const float txz = tx * z;
	const float tyz = ty * z;
	const float sx = s * x;
	const float sy = s * y;
	const float sz = s * z;

	out->m[0] = c + tx * x;
	out->m[1] = txy + sz;
	out->m[2] = txz - sy;
	out->m[3] = 0.0f;

	out->m[4] = txy - sz;
	out->m[5] = c + ty * y;
	out->m[6] = tyz + sx;
	out->m[7] = 0.0f;

	out->m[8] = txz + sy;
	out->m[9] = tyz - sx;
	out->m[10] = c + tz * z;
	out->m[11] = 0.0f;

	out->m[12] = 0.0f;
	out->m[13] = 0.0f;
	out->m[14] = 0.0f;
	out->m[15] = 1.0f;
}

void lstg::getNodeTransform3D(const Vec2& anchorPointInPoints, float x, float y, float z,
	const Quaternion& q, float hscale, float vscale, float zscale, Mat4* _transform)
{
	getRotationTransform(q, _transform);
	_transform->m[12] = x;
	_transform->m[13] = y;
	_transform->m[14] = z;
	if (hscale != 1.f)
	{
		_transform->m[0] *= hscale;
		_transform->m[1] *= hscale;
		_transform->m[2] *= hscale;
	}
	if (vscale != 1.f)
	{
		_transform->m[4] *= vscale;
		_transform->m[5] *= vscale;
		_transform->m[6] *= vscale;
	}
	if (zscale != 1.f)
	{
		_transform->m[8] *= zscale;
		_transform->m[9] *= zscale;
		_transform->m[10] *= zscale;
	}
	if (!anchorPointInPoints.isZero())
	{
		_transform->m[12] -= _transform->m[0] * anchorPointInPoints.x + _transform->m[4] * anchorPointInPoints.y;
		_transform->m[13] -= _transform->m[1] * anchorPointInPoints.x + _transform->m[5] * anchorPointInPoints.y;
		_transform->m[14] -= _transform->m[2] * anchorPointInPoints.x + _transform->m[6] * anchorPointInPoints.y;
	}
}

void lstg::getNodeTransform3D(const Vec2& anchorPointInPoints, float x, float y, float z,
	const Vec3& axis, float angle, float hscale, float vscale, float zscale, Mat4* _transform)
{
	getRotationTransform(axis, angle, _transform);
	_transform->m[12] = x;
	_transform->m[13] = y;
	_transform->m[14] = z;
	if (hscale != 1.f)
	{
		_transform->m[0] *= hscale;
		_transform->m[1] *= hscale;
		_transform->m[2] *= hscale;
	}
	if (vscale != 1.f)
	{
		_transform->m[4] *= vscale;
		_transform->m[5] *= vscale;
		_transform->m[6] *= vscale;
	}
	if (zscale != 1.f)
	{
		_transform->m[8] *= zscale;
		_transform->m[9] *= zscale;
		_transform->m[10] *= zscale;
	}
	if (!anchorPointInPoints.isZero())
	{
		_transform->m[12] -= _transform->m[0] * anchorPointInPoints.x + _transform->m[4] * anchorPointInPoints.y;
		_transform->m[13] -= _transform->m[1] * anchorPointInPoints.x + _transform->m[5] * anchorPointInPoints.y;
		_transform->m[14] -= _transform->m[2] * anchorPointInPoints.x + _transform->m[6] * anchorPointInPoints.y;
	}
}

Image* lstg::GetTextureImage(Texture2D* texture, bool flipImage)
{
	// from RenderTexture::newImage
	if (!texture)
		return nullptr;
	if (texture->getPixelFormat() != Texture2D::PixelFormat::RGBA8888)
		return nullptr;
	const Size& s = texture->getContentSizeInPixels();
	const int buffer_width = (int)s.width;
	const int buffer_height = (int)s.height;
	const int buffer_size = buffer_width * buffer_height * 4;

	GLubyte *buffer = nullptr;
	GLubyte *tempData = nullptr;
	Image *image = new (std::nothrow) Image();
	do
	{
		CC_BREAK_IF(!((buffer = new (std::nothrow) GLubyte[buffer_size])));

		if (!((tempData = new (std::nothrow) GLubyte[buffer_size])))
		{
			delete[] buffer;
			buffer = nullptr;
			break;
		}

		GLint lastTex = 0;
		glGetIntegerv(GL_TEXTURE_BINDING_2D, &lastTex);
		GL::bindTexture2D(texture);
		glPixelStorei(GL_PACK_ALIGNMENT, 1);
		glReadPixels(0, 0, buffer_width, buffer_height, GL_RGBA, GL_UNSIGNED_BYTE, tempData);
		GL::bindTexture2D(lastTex);

		if (flipImage) // -- flip is only required when saving image to file
		{
			// to get the actual texture data
			// #640 the image read from rendertexture is dirty
			for (int i = 0; i < buffer_height; ++i)
			{
				memcpy(&buffer[i * buffer_width * 4],
					&tempData[(buffer_height - i - 1) * buffer_width * 4],
					buffer_width * 4);
			}

			image->initWithRawData(buffer, buffer_size, buffer_width, buffer_height, 8);
		}
		else
		{
			image->initWithRawData(tempData, buffer_size, buffer_width, buffer_height, 8);
		}

	} while (false);

	CC_SAFE_DELETE_ARRAY(buffer);
	CC_SAFE_DELETE_ARRAY(tempData);

	return image;
}

void lstg::deployThreadTask(size_t taskSize, size_t nSlice, const std::function<void(int, int)>& task)
{
	const auto nThr = nSlice;
	const int num = taskSize / nThr;
	for (auto i = 0u; i < nThr; ++i)
	{
		const auto start = i * num;
		auto end = (i + 1)*num;
		if (i == nThr - 1)
			end = taskSize;
		auto task_ = [=]()
		{
			task(start, end);
		};
		if (i == nThr - 1) // reserve one job for this thread
			task_();
		else
			LTHP.addTask(task_);
	}
}

void lstg::deployThreadTask(size_t taskSize, size_t nSlice, const std::function<void(int, int, int)>& task)
{
	const auto nThr = nSlice;
	const int num = taskSize / nThr;
	for (auto i = 0u; i < nThr; ++i)
	{
		const auto start = i * num;
		auto end = (i + 1)*num;
		if (i == nThr - 1)
			end = taskSize;
		auto task_ = [=]()
		{
			task(start, end, i);
		};
		if (i == nThr - 1) // reserve one job for this thread
			task_();
		else
			LTHP.addTask(task_);
	}
}

void RC4::operator()(const uint8_t* input, size_t inputlen, uint8_t* output)
{
	uint8_t Scpy[256];
	memcpy(Scpy, S, sizeof(S));

	for (size_t i = 0, j = 0; i < inputlen; i++)
	{
		// S盒置换
		size_t i2 = (i + 1) % 256;
		j = (j + Scpy[i2]) % 256;
		swap(Scpy[i2], Scpy[j]);
		uint8_t n = Scpy[(Scpy[i2] + Scpy[j]) % 256];

		// 加解密
		*(output + i) = *(input + i) ^ n;
	}
}

RC4::RC4(const uint8_t* password, size_t len)
{
	len = min(len, size_t(256));

	// 初始化S盒
	for (int i = 0; i < 256; ++i)
		S[i] = i;

	// S盒初始置换
	for (size_t i = 0, j = 0; i < 256; i++)
	{
		j = (j + S[i] + password[i % len]) % 256;
		swap(S[i], S[j]);
	}
}

bool util::glMacroFromString(const std::string& str, GLuint& val)
{
	const auto it = GLMacro.find(str);
	if (it == GLMacro.end())
		return false;
	val = it->second;
	return true;
}

GLProgram* util::CreateGLProgramFromPath(const std::string& v, const std::string& f)
{
	const auto ret = GLProgram::createWithFilenames(v, f);
	if (ret)return ret;
	const auto __error = glGetError();
	if (__error) { XERROR("OpenGL error %u", __error); }
	XERROR("can't load shader from [%s] and [%s]", v.c_str(), f.c_str());
	auto fu = FileUtils::getInstance();
	const auto v_content = fu->getStringFromFile(fu->fullPathForFilename(v));
	const auto f_content = fu->getStringFromFile(fu->fullPathForFilename(f));
	CheckVertexShader(v_content);
	CheckFragmentShader(f_content);
	return nullptr;
}

GLProgram* util::CreateGLProgramFromString(const std::string& v, const std::string& f)
{
	const auto ret = GLProgram::createWithByteArrays(v.c_str(), f.c_str());
	if (ret)return ret;
	const auto __error = glGetError();
	if (__error) { XERROR("OpenGL error %u", __error); }
	XERROR("can't load shader from given string", v.c_str(), f.c_str());
	CheckVertexShader(v);
	CheckFragmentShader(f);
	return nullptr;
}

GLProgram* util::CreateGLProgramFromData(Data* v, Data* f)
{
	if (!v || !f)
	{
		XERROR("invalid param");
		return nullptr;
	}
	auto vdata = (GLchar*)v->getBytes();
	auto fdata = (GLchar*)f->getBytes();
	if (vdata[v->getSize() - 1] != '\0' || fdata[f->getSize() - 1] != '\0')
	{
		XERROR("invalid data");
		return nullptr;
	}
	const auto ret = GLProgram::createWithByteArrays(vdata, fdata);
	if (ret)return ret;
	const auto __error = glGetError();
	if (__error) { XERROR("OpenGL error %u", __error); }
	XERROR("can't load shader from given bytes");
	CheckVertexShader(vdata);
	CheckFragmentShader(fdata);
	return nullptr;
}
