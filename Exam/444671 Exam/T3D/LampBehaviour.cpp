#include "LampBehaviour.h"
#include "GameObject.h"
#include "Math.h"

namespace T3D
{
	void LampBehaviour::update(float dt)
	{
		elapsedTime += dt;
		
		gameObject->getTransform()->setLocalPosition(Vector3(Math::smoothedLerp(0, 1, elapsedTime / 5.0, 0.2), 0, 0));
	}
}
