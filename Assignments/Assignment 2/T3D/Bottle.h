#pragma once
#include "gameobject.h"

namespace T3D {
	class Bottle : public GameObject
	{
	public:
		Bottle(T3DApplication* app);
		~Bottle(void);

		GameObject* bottle;
	};
}