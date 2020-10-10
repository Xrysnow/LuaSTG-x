#pragma once
#include "cocos2d.h"
#include "../Object/GameObject.h"
#include "../Object/GameObjectPropertyHash.h"
#include <functional>

#define DEF_OP_NUMBER1(name, _f) Operator::regist(name, 1, 1, ComputeNode::Type::Number, [](Operator* op){\
	const auto op1 = op->inputs.at(0)->getNumber();\
	op->outputs.at(0)->_setNumber(_f);})
#define DEF_OP_NUMBER2(name, _f) Operator::regist(name, 2, 1, ComputeNode::Type::Number, [](Operator* op){\
	const auto op1 = op->inputs.at(0)->getNumber();\
	const auto op2 = op->inputs.at(1)->getNumber();\
	op->outputs.at(0)->_setNumber(_f);})

#define DEF_OP_BOOLEAN1(name, _f) Operator::regist(name, 1, 1, ComputeNode::Type::Boolean, [](Operator* op){\
	const auto op1 = op->inputs.at(0)->getBoolean();\
	op->outputs.at(0)->_setBoolean(_f);})
#define DEF_OP_BOOLEAN2(name, _f) Operator::regist(name, 2, 1, ComputeNode::Type::Boolean, [](Operator* op){\
	const auto op1 = op->inputs.at(0)->getBoolean();\
	const auto op2 = op->inputs.at(1)->getBoolean();\
	op->outputs.at(0)->_setBoolean(_f);})

namespace lstg
{
	struct GameObject;
	class GameClass;

	namespace symbol
	{
		class ComputeNode : public cocos2d::Ref
		{
		public:
			enum class Type
			{
				Number,
				Boolean,
				String,
				OprandTypeNum
			};
		protected:
			bool is_atomic = false;
			bool require_luaobj = false;
			uint32_t _hash = 0;
			uint32_t num_in = 0;
			uint32_t num_out = 1;
			Type _type = Type::OprandTypeNum;
			virtual void calcHash();
		public:
			Type getType() const { return _type; }
			uint32_t getNumIn() const { return num_in; }
			uint32_t getNumOut() const { return num_out; }

			virtual float getNumber(uint32_t idx) { return 0.f; }
			virtual bool getBoolean(uint32_t idx) { return false; }
			virtual float getNumber() { return 0.f; }
			virtual bool getBoolean() { return false; }

			virtual void reset(){}

			virtual void pushLua(lua_State* L);
			virtual void pushLua(lua_State* L, uint32_t idxOut) = 0;

			virtual uint32_t getHash() { return _hash; }
			virtual bool isAtomic() { return is_atomic; }
			virtual bool requireLuaObj() { return require_luaobj; }
			virtual ~ComputeNode(){}
		};

		class Operand : public ComputeNode
		{
		public:

			enum class Source
			{
				Value,
				GameObject,
				GameObjectLua,
				OprandSourceNum
			};
		protected:
			Source _source = Source::OprandSourceNum;
		public:
			Operand(){}
			virtual ~Operand(){}

			virtual void _setNumber(float v){}
			virtual void _setBoolean(bool v){}
		};

		ComputeNode::Type GetGamePropertyType(GameObjectProperty p);
		std::function<float()> GetGamePropertyNumber(GameObjectProperty p);
		std::function<bool()> GetGamePropertyBoolean(GameObjectProperty p);
		std::function<void()> SetGamePropertyByNode(GameObjectProperty p, ComputeNode* node);
		GameObject* getCurrentGameObject();

		class Operator : public ComputeNode
		{
		public:
			using OperatorFunc = std::function<void(Operator*)>;
			struct OperatorDef
			{
				std::string name;
				uint32_t numIn = 0;
				uint32_t numOut = 0;
				Type outType = Type::OprandTypeNum;
				OperatorFunc func;
			};
		protected:
			std::string _name;
			OperatorFunc _func;
			cocos2d::Vector<ComputeNode*> inputs;
			cocos2d::Vector<Operand*> outputs;
			bool executed = false;
		protected:
			static std::unordered_map<std::string, OperatorDef> registry;

			void outNumber(uint32_t idx, float v) { outputs.at(idx)->_setNumber(v); }
			void outBoolean(uint32_t idx, bool v) { outputs.at(idx)->_setBoolean(v); }

			float getInNumber(uint32_t idx) { return inputs.at(idx)->getNumber(); }
			bool getInBoolean(uint32_t idx){ return inputs.at(idx)->getBoolean(); }
			bool init(const std::string& name);
		public:
			static Operator* create(const std::string& name);
			void addInput(ComputeNode* node);
			bool check();

			void execute();
			void reset() override;

			float getNumber(uint32_t idx) override;
			bool getBoolean(uint32_t idx) override;
			float getNumber() override;
			bool getBoolean() override;

			void pushLua(lua_State* L) override;
			void pushLua(lua_State* L, uint32_t idx) override;

			virtual ~Operator(){}

			static void regist(const std::string& name, uint32_t nIn, uint32_t nOut, Type type, OperatorFunc func);
			static void registBase();
		};


		class Statement : public ComputeNode
		{
		public:
			virtual void exe() = 0;
			virtual ~Statement(){}
		};

		class Assigment : public Statement
		{
			std::function<void()> eval;
			std::string objField;
			ComputeNode* rvalue = nullptr;
			Operand* output = nullptr;
		public:
			static Assigment* create(ComputeNode* var);
			static Assigment* createWithObjProperty(
				const std::string& property, ComputeNode* var);

			float getNumber() override;
			bool getBoolean() override;
			float getNumber(uint32_t idx) override { return getNumber(); }
			bool getBoolean(uint32_t idx) override { return getBoolean(); }

			void pushLua(lua_State* L, uint32_t idxOut) override;

			void exe() override;
		private:	
			bool initWithRValue(ComputeNode* var);
			bool initWithObjProperty(const std::string& objProperty, ComputeNode* var);
		public:
			Assigment(){}
			virtual ~Assigment();
		};

		class Block : public cocos2d::Ref
		{
			cocos2d::Vector<Statement*> statements;
			bool require_luaobj = false;
			bool is_atomic = true;
			cocos2d::Vector<ComputeNode*> outputs;
			uint32_t num_out = 0;

			static cocos2d::Vector<Block*> created;
		public:
			static Block* create();

			void push(Statement* s);
			void clear();
			void exe(GameObject* obj);

			void addOutputNode(ComputeNode* node);
			uint32_t getNumOutput() { return num_out; }
			void executeLua(GameObject* obj);
			void executeLua();

			virtual ~Block();
		};

	}
}
