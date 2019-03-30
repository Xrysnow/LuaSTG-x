#include "ComponentDataLight.h"

constexpr uint32_t maxDirLight = 2;
constexpr uint32_t maxPointLight = 2;
constexpr uint32_t maxSpotLight = 2;
static const char *s_dirLightUniformColorName = "u_DirLightSourceColor";
static const char *s_dirLightUniformDirName = "u_DirLightSourceDirection";
static const char *s_pointLightUniformColorName = "u_PointLightSourceColor";
static const char *s_pointLightUniformPositionName = "u_PointLightSourcePosition";
static const char *s_pointLightUniformRangeInverseName = "u_PointLightSourceRangeInverse";
static const char *s_spotLightUniformColorName = "u_SpotLightSourceColor";
static const char *s_spotLightUniformPositionName = "u_SpotLightSourcePosition";
static const char *s_spotLightUniformDirName = "u_SpotLightSourceDirection";
static const char *s_spotLightUniformInnerAngleCosName = "u_SpotLightSourceInnerAngleCos";
static const char *s_spotLightUniformOuterAngleCosName = "u_SpotLightSourceOuterAngleCos";
static const char *s_spotLightUniformRangeInverseName = "u_SpotLightSourceRangeInverse";
static const char *s_ambientLightUniformColorName = "u_AmbientLightSourceColor";

using namespace std;
using namespace lstg;
using namespace cocos2d;

bool ComponentDataLight::init()
{
	reset();
	return true;
}

ComponentDataLight* ComponentDataLight::create()
{
	auto pRet = new(std::nothrow) ComponentDataLight();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

void ComponentDataLight::reset()
{
	lightFlag = 0;
	resetUniforms();
}

void ComponentDataLight::resetUniforms()
{
	dirLightUniformColorValues.assign(maxDirLight, Vec3::ZERO);
	dirLightUniformDirValues.assign(maxDirLight, Vec3::ZERO);

	pointLightUniformColorValues.assign(maxPointLight, Vec3::ZERO);
	pointLightUniformPositionValues.assign(maxPointLight, Vec3::ZERO);
	pointLightUniformRangeInverseValues.assign(maxPointLight, 0.0f);

	spotLightUniformColorValues.assign(maxSpotLight, Vec3::ZERO);
	spotLightUniformPositionValues.assign(maxSpotLight, Vec3::ZERO);
	spotLightUniformDirValues.assign(maxSpotLight, Vec3::ZERO);
	spotLightUniformInnerAngleCosValues.assign(maxSpotLight, 1.0f);
	spotLightUniformOuterAngleCosValues.assign(maxSpotLight, 0.0f);
	spotLightUniformRangeInverseValues.assign(maxSpotLight, 0.0f);
}

void ComponentDataLight::applyLights(const std::vector<cocos2d::BaseLight*>& lights)
{
	ambientColor = Vec3::ZERO;
	GLint dirNum = 0;
	GLint pointNum = 0;
	GLint spotLightNum = 0;
	const auto maxDirLight = dirLightUniformDirValues.size();
	const auto maxPointLight = pointLightUniformPositionValues.size();
	const auto maxSpotLight = spotLightUniformPositionValues.size();
	for (const auto& li : lights)
	{
		const bool useLight = li->isEnabled() && ((unsigned int)li->getLightFlag() & lightFlag);
		if (!useLight)
			continue;
		switch (li->getLightType())
		{
		case LightType::DIRECTIONAL:
			if (dirNum < maxDirLight)
			{
				applyDirectionLight(static_cast<DirectionLight*>(li), dirNum);
				++dirNum;
			}
			break;
		case LightType::POINT:
			if (pointNum < maxPointLight)
			{
				applyPointLight(static_cast<PointLight*>(li), pointNum);
				++pointNum;
			}
			break;
		case LightType::SPOT:
			if (spotLightNum < maxSpotLight)
			{
				applySpotLight(static_cast<SpotLight*>(li), spotLightNum);
				++spotLightNum;
			}
			break;
		case LightType::AMBIENT:
		{
			const float intensity = li->getIntensity();
			const auto ambLight = static_cast<AmbientLight*>(li);
			const auto& col = ambLight->getDisplayedColor();
			ambientColor.add(col.r / 255.0f * intensity, col.g / 255.0f * intensity, col.b / 255.0f * intensity);
		}
		break;
		default:
			break;
		}
	}
}

void ComponentDataLight::applyUniforms(GLProgramState* state)
{
	applyDirectionUniforms(state);
	applyPointUniforms(state);
	applySpotUniforms(state);
	if(state)
		state->setUniformVec3(s_ambientLightUniformColorName, Vec3(ambientColor.x, ambientColor.y, ambientColor.z));
}

void ComponentDataLight::applyDirectionLight(DirectionLight* light, size_t index)
{
	if (light && index < dirLightUniformDirValues.size())
	{
		const float intensity = light->getIntensity();
		Vec3 dir = light->getDirectionInWorld();
		dir.normalize();
		const auto& col = light->getDisplayedColor();
		dirLightUniformColorValues[index].set(col.r / 255.0f * intensity, col.g / 255.0f * intensity, col.b / 255.0f * intensity);
		dirLightUniformDirValues[index] = dir;
	}
}

void ComponentDataLight::applyPointLight(PointLight* light, size_t index)
{
	if (light && index < pointLightUniformPositionValues.size())
	{
		const float intensity = light->getIntensity();
		const Mat4 mat = light->getNodeToWorldTransform();
		const auto& col = light->getDisplayedColor();
		pointLightUniformColorValues[index].set(col.r / 255.0f * intensity, col.g / 255.0f * intensity, col.b / 255.0f * intensity);
		pointLightUniformPositionValues[index].set(mat.m[12], mat.m[13], mat.m[14]);
		pointLightUniformRangeInverseValues[index] = 1.0f / light->getRange();
	}
}

void ComponentDataLight::applySpotLight(SpotLight* light, size_t index)
{
	if (light && index < spotLightUniformPositionValues.size())
	{
		const float intensity = light->getIntensity();
		Vec3 dir = light->getDirectionInWorld();
		dir.normalize();
		const Mat4 mat = light->getNodeToWorldTransform();
		const auto& col = light->getDisplayedColor();
		spotLightUniformColorValues[index].set(col.r / 255.0f * intensity, col.g / 255.0f * intensity, col.b / 255.0f * intensity);
		spotLightUniformPositionValues[index].set(mat.m[12], mat.m[13], mat.m[14]);
		spotLightUniformDirValues[index] = dir;
		spotLightUniformInnerAngleCosValues[index] = light->getCosInnerAngle();
		spotLightUniformOuterAngleCosValues[index] = light->getCosOuterAngle();
		spotLightUniformRangeInverseValues[index] = 1.0f / light->getRange();
	}
}

void ComponentDataLight::applyDirectionUniforms(GLProgramState* state)
{
	if (state && !dirLightUniformDirValues.empty())
	{
		state->setUniformVec3v(s_dirLightUniformColorName, dirLightUniformColorValues.size(), &dirLightUniformColorValues[0]);
		state->setUniformVec3v(s_dirLightUniformDirName, dirLightUniformDirValues.size(), &dirLightUniformDirValues[0]);
	}
}

void ComponentDataLight::applyPointUniforms(GLProgramState* state)
{
	if (state && !pointLightUniformPositionValues.empty())
	{
		state->setUniformVec3v(s_pointLightUniformColorName, pointLightUniformColorValues.size(), &pointLightUniformColorValues[0]);
		state->setUniformVec3v(s_pointLightUniformPositionName, pointLightUniformPositionValues.size(), &pointLightUniformPositionValues[0]);
		state->setUniformFloatv(s_pointLightUniformRangeInverseName, pointLightUniformRangeInverseValues.size(), &pointLightUniformRangeInverseValues[0]);
	}
}

void ComponentDataLight::applySpotUniforms(GLProgramState* state)
{
	if (state && !spotLightUniformPositionValues.empty())
	{
		state->setUniformVec3v(s_spotLightUniformColorName, spotLightUniformColorValues.size(), &spotLightUniformColorValues[0]);
		state->setUniformVec3v(s_spotLightUniformPositionName, spotLightUniformPositionValues.size(), &spotLightUniformPositionValues[0]);
		state->setUniformVec3v(s_spotLightUniformDirName, spotLightUniformDirValues.size(), &spotLightUniformDirValues[0]);
		state->setUniformFloatv(s_spotLightUniformInnerAngleCosName, spotLightUniformInnerAngleCosValues.size(), &spotLightUniformInnerAngleCosValues[0]);
		state->setUniformFloatv(s_spotLightUniformOuterAngleCosName, spotLightUniformOuterAngleCosValues.size(), &spotLightUniformOuterAngleCosValues[0]);
		state->setUniformFloatv(s_spotLightUniformRangeInverseName, spotLightUniformRangeInverseValues.size(), &spotLightUniformRangeInverseValues[0]);
	}
}
