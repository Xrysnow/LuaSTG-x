#pragma once
#include "cocos2d.h"

namespace lstg
{
	class RefAdapter : public cocos2d::Ref
	{
		void* _ptr = nullptr;
		std::string _className;
		std::string _typeName;
		std::function<void(void*)> _dtor;
		// it's not recommand to use this class for a Ref object
		bool _isRef = false;

		static const char* getLuaTypeName(const std::string& hashName);
		static RefAdapter* _create(void* obj, const std::string& className,
			const std::function<void(void*)>& dtor);
	public:

		template<typename T>
		static RefAdapter* create(T* obj, const std::string& className,
			const std::function<void(void*)>& dtor)
		{
			RefAdapter* ret = _create(obj, className, dtor);
			if (!ret)
				return nullptr;
			const auto name = getLuaTypeName(typeid(T).name());
			if (name)
				ret->_typeName = name;
			ret->_isRef = std::is_base_of<cocos2d::Ref, T>::value;
			return ret;
		}

		template<typename T>
		static RefAdapter* create(T* obj, const std::string& className)
		{
			auto ret = create(obj, className, nullptr);
			if(!ret)
				return nullptr;
			ret->template setDefaultDtor<T>();
			return ret;
		}

		void pushLua(lua_State* L);

		virtual ~RefAdapter();

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
