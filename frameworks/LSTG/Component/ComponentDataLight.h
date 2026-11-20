#pragma once
#include "ComponentData.h"
#include "cocos2d.h"

namespace lstg
{	
	class ComponentDataLight : public ComponentData
	{
		bool init() override;
	public:
		static cc::IntrusivePtr<ComponentDataLight> create();

		void reset();
		void resetUniforms();
		void applyLights(const std::vector<cc::BaseLight*>& lights);
		void applyUniforms(cc::backend::ProgramState* state);

		void applyDirectionLight(cc::DirectionLight* light, size_t index);
		void applyPointLight(cc::PointLight* light, size_t index);
		void applySpotLight(cc::SpotLight* light, size_t index);

		void applyDirectionUniforms(cc::backend::ProgramState* state);
		void applyPointUniforms(cc::backend::ProgramState* state);
		void applySpotUniforms(cc::backend::ProgramState* state);

		uint32_t lightFlag = 0;

		std::vector<cc::Vec3> dirLightUniformColorValues;
		std::vector<cc::Vec3> dirLightUniformDirValues;

		std::vector<cc::Vec3> pointLightUniformColorValues;
		std::vector<cc::Vec3> pointLightUniformPositionValues;
		std::vector<float> pointLightUniformRangeInverseValues;

		std::vector<cc::Vec3> spotLightUniformColorValues;
		std::vector<cc::Vec3> spotLightUniformPositionValues;
		std::vector<cc::Vec3> spotLightUniformDirValues;
		std::vector<float> spotLightUniformInnerAngleCosValues;
		std::vector<float> spotLightUniformOuterAngleCosValues;
		std::vector<float> spotLightUniformRangeInverseValues;

		cc::Vec3 ambientColor;
	};
}
