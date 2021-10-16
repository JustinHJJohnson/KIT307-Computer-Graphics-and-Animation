#include "MainAnimation.h"
#include "Vector3.h"
#include "Transform.h"
#include "Sound.h"
#include "Math.h"
#include "LookAtBehaviour.h"

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
		bottle1 = NULL;
		bottle2 = NULL;
		bottle3 = NULL;
		bottle4 = NULL;
		bottle5 = NULL;
		bottle6 = NULL;

		breakAnnouncement = app->soundManager->createSound("Resources/BreakTime.mp3");
		breakAnnouncement->setVolume(1);
		timeToBowl = app->soundManager->createSound("Resources/TimeToBowl.wav");
		timeToBowl->setVolume(1);
		unfortunate = app->soundManager->createSound("Resources/Unfortunate.wav");
		unfortunate->setVolume(1);
		damnIt = app->soundManager->createSound("Resources/DamnIt.wav");
		damnIt->setVolume(1);
		slipped = app->soundManager->createSound("Resources/Slipped.wav");
		slipped->setVolume(1);
		wtf = app->soundManager->createSound("Resources/wtf.wav");
		wtf->setVolume(1);

		announcementPlayed = false;
		timeToBowlPlayed = false;
		unfortunatePlayed = false;
		damnItPlayed = false;
		slippedPlayed = false;
		wtfPlayed = false;
	}

	void MainAnimation::update(float dt)
	{
		elapsedTime += dt;

		if (!announcementPlayed && elapsedTime >= 0)
		{
			breakAnnouncement->play();
			announcementPlayed = true;
		}
		else if (elapsedTime >= 2 && elapsedTime <= 4)
		{
			float temp1 = Math::smoothedLerp(22, 0, elapsedTime - 2, 0.5);
			float temp2 = Math::smoothedLerp(115, -27, elapsedTime - 2, 0.5);
			camera->setLocalRotation(Quaternion(Vector3(temp1 * Math::DEG2RAD, temp2 * Math::DEG2RAD, 0)));
		}
		else if (elapsedTime <= 6)
		{
			inserter1->getTransform()->setLocalPosition(Vector3::lerp(Vector3(0.5, 0, 0), Vector3(6.5, 0, 0), (elapsedTime - 4) / 2));
			inserter2->getTransform()->setLocalPosition(Vector3::lerp(Vector3(-1, 0, 0), Vector3(5, 0, 0), (elapsedTime - 4) / 2));
			inserter3->getTransform()->setLocalPosition(Vector3::lerp(Vector3(-0.5, 0, 0), Vector3(5.5, 0, 0), (elapsedTime - 4) / 2));
			inserter4->getTransform()->setLocalPosition(Vector3::lerp(Vector3(0, 0, 0), Vector3(6, 0, 0), (elapsedTime - 4) / 2));
		}
		else if (elapsedTime <= 8)
		{
			if (!timeToBowlPlayed)
			{
				inserter1->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, 0)));
				inserter1->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, Math::PI / 2)));
				inserter1->headJoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, 0)));

				inserter2->getTransform()->setLocalPosition(Vector3(8, 0, 2));
				inserter3->getTransform()->setLocalPosition(Vector3(9, 0, 2));
				inserter3->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 180 * Math::DEG2RAD, 0)));
				inserter4->getTransform()->setLocalPosition(Vector3(8.2, 0, 1.5));
				inserter4->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, 90 * Math::DEG2RAD, 0)));

				Vector3 bowlingBallPos = inserter1->rightProng->getTransform()->getWorldPosition();
				bowlingBallPos.y -= 0.115;
				bowlingBall->setLocalPosition(bowlingBallPos);

				camera->setLocalPosition(Vector3(6.8, .5, -1.5));
				camera->setLocalRotation(Vector3(0, 180 * Math::DEG2RAD, 0));
				timeToBowl->play();
				timeToBowlPlayed = true;
			}
		}
		else if (elapsedTime <= 9)
		{
			inserter1->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::smoothedLerp(Math::PI / 2, Math::PI, elapsedTime - 8, 0.9) , 0, Math::PI / 2)));

			Vector3 bowlingBallPos = inserter1->rightProng->getTransform()->getWorldPosition();
			bowlingBallPos.y -= 0.115;
			bowlingBall->setLocalPosition(bowlingBallPos);
		}
		else if (elapsedTime <= 9.75)
		{
			camera->lookAt(bowlingBall->getLocalPosition());
			Vector3 bowlingBallPos = bowlingBall->getLocalPosition();
			bowlingBallPos.z -= 0.07;
			bowlingBallPos.y -= 0.001;
			bowlingBall->setLocalPosition(bowlingBallPos);
		}
		else if (elapsedTime <= 11)
		{
			float cameraX = camera->getEulerAngles().x;
			camera->setLocalRotation(Quaternion(Vector3(0, Math::smoothedLerp(cameraX, 180, elapsedTime - 9.75, 0.5) * Math::DEG2RAD, 0)));
		}
		else if (elapsedTime <= 13)
		{
			if (!unfortunatePlayed)
			{
				unfortunate->play();
				unfortunatePlayed = true;
			}

			inserter1->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::smoothedLerp(Math::PI, Math::PI / 2, elapsedTime - 11, 0.5), 0, Math::PI / 2)));
		}
		else if (elapsedTime <= 14)
		{
			inserter1->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::smoothedLerp(Math::PI / 2, Math::PI, elapsedTime - 13, 0.9), 0, Math::PI / 2)));

			Vector3 bowlingBallPos = inserter1->rightProng->getTransform()->getWorldPosition();
			bowlingBallPos.y -= 0.115;
			bowlingBall->setLocalPosition(bowlingBallPos);
		}
		else if (elapsedTime <= 14.74)
		{
			camera->lookAt(bowlingBall->getLocalPosition());
			Vector3 bowlingBallPos = bowlingBall->getLocalPosition();
			bowlingBallPos.z -= 0.07;
			bowlingBallPos.y -= 0.001;
			bowlingBallPos.x += 0.01;
			bowlingBall->setLocalPosition(bowlingBallPos);
		}
		else if (elapsedTime <= 16)
		{
			float cameraX = camera->getEulerAngles().x;
			camera->setLocalRotation(Quaternion(Vector3(0, Math::smoothedLerp(cameraX, 180, elapsedTime - 15, 0.5) * Math::DEG2RAD, 0)));
		}
		else if (elapsedTime <= 17)
		{
			if (!damnItPlayed)
			{
				damnIt->play();
				damnItPlayed = true;
			}

			inserter1->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::smoothedLerp(Math::PI, 1840 * Math::DEG2RAD, elapsedTime - 16, 0.5), 0, Math::PI / 2)));
			inserter1->headJoint->getTransform()->setLocalRotation(Quaternion(Vector3(0, Math::smoothedLerp(0, Math::PI / 2, elapsedTime - 16, 0.5), 0)));
		}
		else if (elapsedTime <= 17.5)
		{
			inserter1->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(
				Math::smoothedLerp(40 * Math::DEG2RAD, 15 * Math::DEG2RAD, (elapsedTime - 17) * 2, 0.5),
				Math::smoothedLerp(0, 10 * Math::DEG2RAD, (elapsedTime - 17) * 2, 0.5),
				Math::smoothedLerp(Math::PI / 2, Math::PI / 8, (elapsedTime - 17) * 2, 0.5)
			)));

			Vector3 bowlingBallPos = inserter1->rightProng->getTransform()->getWorldPosition();
			bowlingBallPos.x += 0.115;
			bowlingBall->setLocalPosition(bowlingBallPos);
		}
		else if (elapsedTime <= 20.47)
		{
			if (!slippedPlayed)
			{
				slipped->play();
				slippedPlayed = true;
			}

			Vector3 bowlingBallPos = bowlingBall->getLocalPosition();
			bowlingBallPos.x += 0.0012;
			bowlingBallPos.y = sin(((elapsedTime - 17.5) * 60) * Math::DEG2RAD) * 10;
			bowlingBallPos.z -= 0.0118;
			bowlingBall->setLocalPosition(bowlingBallPos);

			camera->lookAt(bowlingBall->getLocalPosition());
		}
		else if (elapsedTime >= 20.47 && elapsedTime <= 21.2){}
		else if (elapsedTime <= 22.2)
		{
			float cameraX = camera->getEulerAngles().x;
			camera->setLocalRotation(Quaternion(Vector3(0, Math::smoothedLerp(cameraX, 180, elapsedTime - 21.2, 0.5)* Math::DEG2RAD, 0)));
		}
		else if (elapsedTime <= 25)
		{
			if (!wtfPlayed)
			{
				camera->setLocalPosition(Vector3(6.5, 0.6, -0.5));
				wtf->play();
				wtfPlayed = true;
			}
		}
		else
		{
			camera->setLocalPosition(Vector3(0, 0.5, 4.5));
			camera->setLocalRotation(Vector3(Math::PI / 10, 0, 0));
		}
	}
	
}