#pragma once
#include "gameobject.h"

namespace T3D {
	class Speaker : public GameObject
	{
	public:
		Speaker(T3DApplication* app);
		~Speaker(void);

		GameObject* speaker;
	};
}