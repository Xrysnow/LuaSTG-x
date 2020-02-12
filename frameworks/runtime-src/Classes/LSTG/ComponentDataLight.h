#pragma once
#include "ComponentData.h"
#include "cocos2d.h"

namespace lstg
{	
	class ComponentDataLight : public ComponentData
	{
		bool init() override;
	public:
		static ComponentDataLight* create();

		void reset();
		void resetUniforms();
		void applyLights(const std::vector<cocos2d::BaseLight*>& lights);
		void applyUniforms(cocos2d::backend::ProgramState* state);

		void applyDirectionLight(cocos2d::DirectionLight* light, size_t index);
		void applyPointLight(cocos2d::PointLight* light, size_t index);
		void applySpotLight(cocos2d::SpotLight* light, size_t index);

		void applyDirectionUniforms(cocos2d::backend::ProgramState* state);
		void applyPointUniforms(cocos2d::backend::ProgramState* state);
		void applySpotUniforms(cocos2d::backend::ProgramState* state);

		uint32_t lightFlag = 0;

		std::vector<cocos2d::Vec3> dirLightUniformColorValues;
		std::vector<cocos2d::Vec3> dirLightUniformDirValues;

		std::vector<cocos2d::Vec3> pointLightUniformColorValues;
		std::vector<cocos2d::Vec3> pointLightUniformPositionValues;
		std::vector<float> pointLightUniformRangeInverseValues;

		std::vector<cocos2d::Vec3> spotLightUniformColorValues;
		std::vector<cocos2d::Vec3> spotLightUniformPositionValues;
		std::vector<cocos2d::Vec3> spotLightUniformDirValues;
		std::vector<float> spotLightUniformInnerAngleCosValues;
		std::vector<float> spotLightUniformOuterAngleCosValues;
		std::vector<float> spotLightUniformRangeInverseValues;

		cocos2d::Vec3 ambientColor;
	};
}
