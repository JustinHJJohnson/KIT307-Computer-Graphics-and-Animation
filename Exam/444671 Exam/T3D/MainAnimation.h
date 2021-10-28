#pragma once
#include "Task.h"
#include "Sound.h"
#include "Animation.h"
#include "Cow.h"

namespace T3D
{
	class MainAnimation :
		public Task
	{
	public:
		float elapsedTime;
		
		Cow* cow;

		Transform* camera;
		Transform* shades;

		Animation* excitedLamp;

		Sound* boing;
		Sound* YEAH;

		bool boingPlayed;
		bool YEAHPlayed;
		bool lampExcited;

		MainAnimation::MainAnimation(T3DApplication* app);
		void MainAnimation::update(float dt);
	};
}

