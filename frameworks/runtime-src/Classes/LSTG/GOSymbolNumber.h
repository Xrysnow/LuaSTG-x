#pragma once
#include "GameObjectSymbol.h"

namespace lstg
{
	namespace symbol
	{
		class Number : public Operand
		{
			float _value = 0.f;
		public:
			static Number* createWithValue(float v);
			static Number* createWithObjProperty(const std::string& property);

		protected:
			Number() { _type = Type::Number; }
			bool initWithValue(float v);

		public:
			virtual ~Number(){}

			float getNumber() override { return _value; }
			bool getBoolean() override { return getNumber() != 0.f; }

			float getNumber(uint32_t idx) override { return _value; }
			bool getBoolean(uint32_t idx) override { return getNumber() != 0.f; }

			void _setNumber(float v) override { _value = v; }
			void pushLua(lua_State* L, uint32_t idxOut) override;
		};

		class NumberFromGameObject : public Number
		{
			std::function<float()> _eval;
			GameObjectProperty _p = GameObjectProperty::_KEY_NOT_FOUND;
		public:
			static NumberFromGameObject* create(GameObjectProperty p);
			float getNumber() override;
			void pushLua(lua_State* L, uint32_t idxOut) override;
		private:
			bool init(GameObjectProperty p);
		};

		class NumberFromGameObjectLua : public Number
		{
			std::string _field;
		public:
			static NumberFromGameObjectLua* create(const std::string& field);
			float getNumber() override;
			void pushLua(lua_State* L, uint32_t idxOut) override;
		private:
			bool init(const std::string& field);
		};
	}
}
