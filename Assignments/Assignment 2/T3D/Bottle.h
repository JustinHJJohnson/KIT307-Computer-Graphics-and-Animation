#pragma once
#include "gameobject.h"

namespace T3D {
	class Bottle : public GameObject
	{
	public:
		Bottle(T3DApplication* app, int density);
		~Bottle(void) = default;

		GameObject* bottle;
	};
}