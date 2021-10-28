#pragma once
#include "gameobject.h"

namespace T3D {
	class Cow : public GameObject
	{
	public:
		Cow(T3DApplication* app);
		~Cow(void);

		GameObject* backLeftLeg;
		GameObject* backRightLeg;
		GameObject* frontLeftLeg;
		GameObject* frontRightLeg;
		GameObject* body;
		GameObject* neckJoint;
		GameObject* neck;
		GameObject* headJoint;
		GameObject* head;
	};
}