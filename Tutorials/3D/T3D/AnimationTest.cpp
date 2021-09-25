#include "AnimationTest.h"
#include "Vector3.h"
#include "Transform.h"

namespace T3D
{
	AnimationTest::AnimationTest(T3DApplication* app) : Task(app)
	{
		elapsedTime = 0;
		lamp = NULL;
	}

	void AnimationTest::update(float dt)
	{
		/*if (elapsedTime <= 5)
		{
			lamp->setLocalPosition(Vector3::lerp(Vector3(0, 0, 0), Vector3(1, 0, 0), elapsedTime / 5));
		}
		else if (elapsedTime <= 10)
		{
			lamp->setLocalPosition(Vector3::lerp(Vector3(1, 0, 0), Vector3(0, 1, 0), (elapsedTime - 5) / 5));
		}*/

		lamp->setLocalPosition(Vector3(Math::smoothedLerp(0, 1, elapsedTime / 5.0, 0.2), 0, 0));
	}
}