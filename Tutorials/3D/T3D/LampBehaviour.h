#pragma once
#include "Component.h"
#include "Transform.h"

namespace T3D
{
	class LampBehaviour :
		public Component
	{
	public:
		LampBehaviour() { elapsedTime = 0; };
		~LampBehaviour(void) = default;

		virtual void update(float dt);

		float elapsedTime;
	};
}