#pragma once
#include "GameObjectManager.h"

namespace lstg
{
	/**
	 * NOTE: This class is designed for lua.
	 */
	class GameObjectSet
	{
	public:
		enum class SortMode
		{
			NONE,
			DEFAULT,
			LAYER
		};
	};
}
