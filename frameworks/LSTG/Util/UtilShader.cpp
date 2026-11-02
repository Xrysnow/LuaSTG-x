#include "Utility.h"

using namespace lstg;
using namespace cocos2d;

bool util::CheckBlendOperation(backend::BlendOperation equation)
{
	return equation <= backend::BlendOperation::RESERVE_SUBTRACT;
}

bool util::CheckBlendFactor(backend::BlendFactor func)
{
	return func <= backend::BlendFactor::BLEND_CLOLOR;
}
