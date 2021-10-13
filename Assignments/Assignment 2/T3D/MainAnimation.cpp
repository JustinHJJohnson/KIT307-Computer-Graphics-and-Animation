#include "MainAnimation.h"
#include "Vector3.h"
#include "Transform.h"
#include "Sound.h"
#include "Math.h"

namespace T3D
{
	MainAnimation::MainAnimation(T3DApplication* app) : Task(app)
	{
		elapsedTime = 0;

		inserter1 = NULL;
		inserter2 = NULL;
		inserter3 = NULL;
		inserter4 = NULL;
		bowlingBall = NULL;
		camera = NULL;

		breakAnnouncement = app->soundManager->createSound("Resources/beep.wav");
		announcementPlayed = false;


	}

	void MainAnimation::update(float dt)
	{
		elapsedTime += dt;

		if (!announcementPlayed && elapsedTime >= 0)
		{
			breakAnnouncement->play();
			announcementPlayed = true;
		}
		else if (elapsedTime <= 6)
		{
			//camera->setLocalRotation(Vector3(0, -27 * Math::DEG2RAD, 0));
			
			inserter1->getTransform()->setLocalPosition(Vector3::lerp(Vector3(0.5, 0, 0), Vector3(6.5, 0, 0), (elapsedTime - 2) / 5));
			inserter2->getTransform()->setLocalPosition(Vector3::lerp(Vector3(-1, 0, 0), Vector3(5, 0, 0), (elapsedTime - 2) / 5));
			inserter3->getTransform()->setLocalPosition(Vector3::lerp(Vector3(-0.5, 0, 0), Vector3(5.5, 0, 0), (elapsedTime - 2) / 5));
			inserter4->getTransform()->setLocalPosition(Vector3::lerp(Vector3(0, 0, 0), Vector3(6, 0, 0), (elapsedTime - 2) / 5));
		}
		else if (elapsedTime <= 6.9)
		{
			inserter1->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, 0)));
			inserter1->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::smoothedLerp(Math::PI / 2, Math::PI, elapsedTime - 6, 0.9) , 0, Math::PI / 2)));
			inserter1->headJoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, 0)));

			Vector3 bowlingBallPos = inserter1->rightProng->getTransform()->getWorldPosition();
			bowlingBallPos.y -= 0.115;
			bowlingBall->setLocalPosition(bowlingBallPos);
		}
		else if (elapsedTime <= 7.3)
		{
			Vector3 bowlingBallPos = bowlingBall->getLocalPosition();
			bowlingBallPos.z -= 0.07;
			bowlingBallPos.y -= 0.002;
			bowlingBall->setLocalPosition(bowlingBallPos);
		}
		//else if ()
	}
}