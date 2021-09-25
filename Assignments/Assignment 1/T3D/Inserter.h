#pragma once
#include "gameobject.h"

namespace T3D {
	class Inserter : public GameObject
	{
	public:
		Inserter(T3DApplication* app);
		~Inserter(void);

		GameObject* leg1;
		GameObject* leg2;
		GameObject* leg3;
		GameObject* base;
		GameObject* arm1;
		GameObject* arm2;
		GameObject* head;
		GameObject* leftProng;
		GameObject* rightProng;

		GameObject* legsJoint;
		GameObject* baseJoint;
		GameObject* elbowJoint;
		GameObject* headJoint;
		GameObject* leftProngJoint;
		GameObject* rightProngJoint;
	};
}