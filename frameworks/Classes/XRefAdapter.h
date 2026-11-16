#pragma once
#include "cocos2d.h"

namespace lstg
{
	class RefAdapter : public cocos2d::Ref
	{
	public:
	    RefAdapter() = default;
	private:

		void* _ptr = nullptr;
		std::string _className;
		std::string _typeName;
		std::function<void(void*)> _dtor;
		// it's not recommand to use this class for a Ref object
		cocos2d::Ref* _ref = nullptr;

		static const char* getLuaTypeName(const char* typeName);
		static cc::IntrusivePtr<RefAdapter> _create(void* obj, const std::string& className,
			const std::function<void(void*)>& dtor);
	public:

		template<typename T>
		static cc::IntrusivePtr<RefAdapter> create(T* obj, const std::string& className,
			const std::function<void(void*)>& dtor)
		{
			auto ret = _create(obj, className, dtor);
			if (!ret)
				return nullptr;
			const auto name = getLuaTypeName(typeid(T).name());
			if (name)
				ret->_typeName = name;
			if constexpr (std::is_convertible_v<T*,const cc::RefCounted*>)
				ret->_ref = static_cast<cocos2d::Ref*>(obj);
			return ret;
		}

		template<typename T>
		static cc::IntrusivePtr<RefAdapter> create(T* obj, const std::string& className)
		{
			auto ret = create(obj, className, nullptr);
			if(!ret)
				return nullptr;
			ret->template setDefaultDtor<T>();
			return ret;
		}

		void pushLua(lua_State* L);

		~RefAdapter() override;

		template<typename T>
		void setDefaultDtor()
		{
			_dtor = [this](void*)
			{
				delete static_cast<T*>(_ptr);
			};
		}
	};
}
