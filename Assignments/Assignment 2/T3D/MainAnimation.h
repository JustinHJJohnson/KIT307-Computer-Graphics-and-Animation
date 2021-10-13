#pragma once
#include "Task.h"
#include "Inserter.h"
#include "Sound.h"

namespace T3D
{
	class MainAnimation :
		public Task
	{
	public:
		float elapsedTime;

		Inserter* inserter1;
		Inserter* inserter2;
		Inserter* inserter3;
		Inserter* inserter4;

		Transform* camera;
		Transform* bowlingBall;

		Sound* breakAnnouncement;
		bool announcementPlayed;


		MainAnimation::MainAnimation(T3DApplication* app);
		void MainAnimation::update(float dt);
	};
}

