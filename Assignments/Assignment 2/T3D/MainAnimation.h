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
		Transform* bottle1;
		Transform* bottle2;
		Transform* bottle3;
		Transform* bottle4;
		Transform* bottle5;
		Transform* bottle6;

		Sound* breakAnnouncement;
		Sound* timeToBowl;
		Sound* unfortunate;
		Sound* damnIt;
		Sound* slipped;
		Sound* wtf;

		bool announcementPlayed;
		bool timeToBowlPlayed;
		bool unfortunatePlayed;
		bool damnItPlayed;
		bool slippedPlayed;
		bool wtfPlayed;

		MainAnimation::MainAnimation(T3DApplication* app);
		void MainAnimation::update(float dt);
	};
}

