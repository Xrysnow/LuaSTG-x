#pragma once
#include "ResBase.h"
#include "BlendMode.h"
#include "Global.h"
#include "ResSprite.h"
#include "../fcyLib/fcyMisc/fcyRandom.h"

namespace lstg {
	// implement of HGE particle system
	//TODO: WIP
	class ResParticle :
		public ResourceColliable
	{
	public:
		/// @brief 粒子信息
		struct ParticleInfo
		{
			uint32_t BlendInfo;
			uint32_t EmissionFreq;    // 每秒发射个数
			float Lifetime;           // 生命期
			float LifeMin;            // 粒子最小生命期
			float LifeMax;            // 粒子最大生命期
			float Direction;          // 发射方向
			float Spread;             // 偏移角度
			bool Relative;            // 使用相对值还是绝对值
			float SpeedMin;           // 速度最小值
			float SpeedMax;           // 速度最大值
			float GravityMin;         // 重力最小值
			float GravityMax;         // 重力最大值
			float RadialAccelMin;     // 最低线加速度
			float RadialAccelMax;     // 最高线加速度
			float TangentialAccelMin; // 最低角加速度
			float TangentialAccelMax; // 最高角加速度
			float SizeStart;          // 起始大小
			float SizeEnd;            // 最终大小
			float SizeVar;            // 大小抖动值
			float SpinStart;          // 起始自旋
			float SpinEnd;            // 最终自旋
			float SpinVar;            // 自旋抖动值
			float ColorStart[4];      // 起始颜色(rgba)
			float ColorEnd[4];        // 最终颜色
			float ColorVar;           // 颜色抖动值
			float AlphaVar;           // alpha抖动值
		};
		/// @brief 粒子实例
		struct ParticleInstance
		{
			cocos2d::Vec2 vecLocation;  // 位置
			cocos2d::Vec2 vecVelocity;  // 速度
			float gravity;              // 重力
			float radialAccel;          // 线加速度
			float tangentialAccel;      // 角加速度
			float spin;                 // 自旋
			float spinDelta;            // 自旋增量
			float size;                 // 大小
			float sizeDelta;            // 大小增量
			float color[4];             // 颜色
			float colorDelta[4];        // 颜色增量
			float life;                 // 当前存活时间
			float terminalLife;         // 终止时间
		};
		/// @brief 粒子池
		class ParticlePool : public cocos2d::Ref
		{
			friend class ResParticle;
		public:
			enum class Status
			{
				Alive,
				Sleep
			};
		private:
			ResParticle* _res;
			ParticleInfo particleInfo;
			fcyRandomWELL512 _rand;

			BlendMode* blendMode = BlendMode::Default;
			Status status = Status::Alive;  // 状态
			cocos2d::Vec2 center;  // 中心
			cocos2d::Vec2 prevCenter;  // 上一个中心
			float rotation = 0.f;  // 方向
			size_t numAlive = 0;  // 存活数
			float life = 0.f;  // 已存活时间
			float emissionResidue = 0.f;  // 不足的粒子数
			std::array<ParticleInstance, LPARTICLE_MAXCNT> particlePool;
		public:
#define PARTICLE_INFO_FUNC(_T, var) _T get##var() const noexcept { return particleInfo.var; } \
	void set##var(_T val) noexcept { particleInfo.var = val; }
			PARTICLE_INFO_FUNC(uint32_t, EmissionFreq);
			PARTICLE_INFO_FUNC(float, Lifetime);
			PARTICLE_INFO_FUNC(float, LifeMin);
			PARTICLE_INFO_FUNC(float, LifeMax);
			PARTICLE_INFO_FUNC(float, Direction);
			PARTICLE_INFO_FUNC(float, Spread);
			PARTICLE_INFO_FUNC(bool, Relative);
			PARTICLE_INFO_FUNC(float, SpeedMin);
			PARTICLE_INFO_FUNC(float, SpeedMax);
			PARTICLE_INFO_FUNC(float, GravityMin);
			PARTICLE_INFO_FUNC(float, GravityMax);
			PARTICLE_INFO_FUNC(float, RadialAccelMin);
			PARTICLE_INFO_FUNC(float, RadialAccelMax);
			PARTICLE_INFO_FUNC(float, TangentialAccelMin);
			PARTICLE_INFO_FUNC(float, TangentialAccelMax);
			PARTICLE_INFO_FUNC(float, SizeStart);
			PARTICLE_INFO_FUNC(float, SizeEnd);
			PARTICLE_INFO_FUNC(float, SizeVar);
			PARTICLE_INFO_FUNC(float, SpinStart);
			PARTICLE_INFO_FUNC(float, SpinEnd);
			PARTICLE_INFO_FUNC(float, SpinVar);
			PARTICLE_INFO_FUNC(float, ColorVar);
			PARTICLE_INFO_FUNC(float, AlphaVar);
#undef PARTICLE_INFO_FUNC
			cocos2d::Color4B getColorStart() noexcept;
			void setColorStart(const cocos2d::Color4B& color) noexcept;
			cocos2d::Color4B getColorEnd() noexcept;
			void setColorEnd(const cocos2d::Color4B& color) noexcept;

			ResParticle* getResource()const noexcept { return _res; }
			size_t getAliveCount()const noexcept { return numAlive; }

			void setSeed(uint32_t seed)noexcept { _rand.SetSeed(seed); }
			uint32_t getSeed()const noexcept { return _rand.GetRandSeed(); }
			BlendMode* getBlendMode()const noexcept { return blendMode; }
			void setBlendMode(BlendMode* m)noexcept { blendMode = m; }
			bool isActive()const noexcept { return status == Status::Alive; }
			void setActive(bool b) noexcept;
			void setCenter(const cocos2d::Vec2& pos) noexcept;
			cocos2d::Vec2 getCenter() const noexcept { return center; }
			void setRotation(float r)noexcept { rotation = r; }
			float getRotation() const noexcept { return rotation; }

			void Update(float delta);
			void Render(float scaleX, float scaleY);
		public:
			explicit ParticlePool(ResParticle* ref);
			~ParticlePool();
		};
	private:
		cocos2d::Sprite* bindSprite;
		ParticleInfo particleInfo;
		BlendMode* blendMode;
	public:
		BlendMode* getBlendMode() const noexcept { return blendMode; }
		ParticlePool* AllocInstance()noexcept;
		void FreeInstance(ParticlePool* p)noexcept;

		cocos2d::Sprite* getBindSprite() const noexcept { return bindSprite; }
		const ParticleInfo& getParticleInfo() const noexcept { return particleInfo; }

		std::string getInfo() const override;
	public:
		ResParticle(const std::string& name, const ParticleInfo& pinfo, cocos2d::Sprite* sprite,
			BlendMode* bld, double a, double b, XColliderType colliType = XColliderType::Circle);
		~ResParticle();

		static ResParticle* create(const std::string& name, const std::string& path, ResSprite* sprite,
			double a, double b, XColliderType colliType);
	};
}
