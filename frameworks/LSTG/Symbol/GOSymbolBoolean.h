#pragma once
#include "GameObjectSymbol.h"

namespace lstg
{
	namespace symbol
	{
		class Boolean : public Operand
		{
			bool _value = false;
		public:
			static Boolean* createWithValue(bool v);
			static Boolean* createWithObjProperty(const std::string& property);

		protected:
			Boolean() { _type = Type::Boolean; }
			bool initWithValue(bool v);

		public:
			virtual ~Boolean() {}

			float getNumber() override { return int(getBoolean()); }
			bool getBoolean() override { return _value; }

			float getNumber(uint32_t idx) override { return int(getBoolean()); }
			bool getBoolean(uint32_t idx) override { return _value; }

			void _setBoolean(bool v) override { _value = v; }
			void pushLua(lua_State* L, uint32_t idxOut) override;
		};

		class BooleanFromGameObject : public Boolean
		{
			std::function<bool()> _eval;
			GameObjectProperty _p = GameObjectProperty::_KEY_NOT_FOUND;
		public:
			static BooleanFromGameObject* create(GameObjectProperty p);
			bool getBoolean() override;
			void pushLua(lua_State* L, uint32_t idxOut) override;
		private:
			bool init(GameObjectProperty p);
		};

		class BooleanFromGameObjectLua : public Boolean
		{
			std::string _field;
		public:
			static BooleanFromGameObjectLua* create(const std::string& field);
			bool getBoolean() override;
			void pushLua(lua_State* L, uint32_t idxOut) override;
		private:
			bool init(const std::string& field);
		};
	}
}
