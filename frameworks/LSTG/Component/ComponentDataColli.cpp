#include "ComponentDataColli.h"

bool lstg::ComponentDataColli::init()
{
	reset();
	return true;
}

void lstg::ComponentDataColli::reset()
{
	type = xmath::collision::ColliderType::Circle;
	a = 0;
	b = 0;
	col_r = 0;
	group = 0;
}
