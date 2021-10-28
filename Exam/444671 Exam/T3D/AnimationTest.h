#pragma once
#include "Task.h"

namespace T3D
{
	class AnimationTest :
		public Task
	{
	public:
		float elapsedTime;
		Transform* lamp;

		AnimationTest::AnimationTest(T3DApplication* app);
		void AnimationTest::update(float dt);
	};
}

