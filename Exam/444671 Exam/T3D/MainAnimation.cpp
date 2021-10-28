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

		excitedLamp = NULL;
		camera = NULL;
		cow = NULL;
		shades = NULL;

		boing = app->soundManager->createSound("Resources/boing.mp3");
		boing->setVolume(1);
		//YEAH = app->soundManager->createSound("Resources/Yeah Short.mp3");
		YEAH = app->soundManager->createSound("Resources/Yeah.mp3");
		YEAH->setVolume(0.5);

		boingPlayed = false;
		YEAHPlayed = false;
		lampExcited = false;
	}

	void MainAnimation::update(float dt)
	{
		elapsedTime += dt;

		if (elapsedTime <= 0.5)
		{
			Vector3 bLLStartPos = cow->backLeftLeg->getTransform()->getLocalPosition();
			float bLLNewZ = Math::lerp(bLLStartPos.z, bLLStartPos.z - 0.01, elapsedTime);
			cow->backLeftLeg->getTransform()->setLocalPosition(Vector3(bLLStartPos.x, bLLStartPos.y, bLLNewZ));

			Vector3 bRLStartPos = cow->backRightLeg->getTransform()->getLocalPosition();
			float bRLNewZ = Math::lerp(bRLStartPos.z, bRLStartPos.z - 0.01, elapsedTime);
			cow->backRightLeg->getTransform()->setLocalPosition(Vector3(bRLStartPos.x, bRLStartPos.y, bRLNewZ));

			Vector3 fLLStartPos = cow->frontLeftLeg->getTransform()->getLocalPosition();
			float fLLNewZ = Math::lerp(fLLStartPos.z, fLLStartPos.z - 0.01, elapsedTime);
			cow->frontLeftLeg->getTransform()->setLocalPosition(Vector3(fLLStartPos.x, fLLStartPos.y, fLLNewZ));

			Vector3 fRLStartPos = cow->frontRightLeg->getTransform()->getLocalPosition();
			float fRLNewZ = Math::lerp(fRLStartPos.z, fRLStartPos.z - 0.01, elapsedTime);
			cow->frontRightLeg->getTransform()->setLocalPosition(Vector3(fRLStartPos.x, fRLStartPos.y, fRLNewZ));

			Vector3 bodyStartPos = cow->body->getTransform()->getLocalPosition();
			float bodyNewY = Math::lerp(bodyStartPos.y, bodyStartPos.y - 0.011, elapsedTime);
			cow->body->getTransform()->setLocalPosition(Vector3(bodyStartPos.x, bodyNewY, bodyStartPos.z));
		}
		else if ( elapsedTime >= 0.6 && elapsedTime <= 1)
		{
			Vector3 bLLStartPos = cow->backLeftLeg->getTransform()->getLocalPosition();
			float bLLNewZ = Math::lerp(bLLStartPos.z, bLLStartPos.z + 0.01, (elapsedTime - 0.6) * 2);
			cow->backLeftLeg->getTransform()->setLocalPosition(Vector3(bLLStartPos.x, bLLStartPos.y, bLLNewZ));

			Vector3 bRLStartPos = cow->backRightLeg->getTransform()->getLocalPosition();
			float bRLNewZ = Math::lerp(bRLStartPos.z, bRLStartPos.z + 0.01, (elapsedTime - 0.6) * 2);
			cow->backRightLeg->getTransform()->setLocalPosition(Vector3(bRLStartPos.x, bRLStartPos.y, bRLNewZ));

			Vector3 fLLStartPos = cow->frontLeftLeg->getTransform()->getLocalPosition();
			float fLLNewZ = Math::lerp(fLLStartPos.z, fLLStartPos.z + 0.01, (elapsedTime - 0.6) * 2);
			cow->frontLeftLeg->getTransform()->setLocalPosition(Vector3(fLLStartPos.x, fLLStartPos.y, fLLNewZ));

			Vector3 fRLStartPos = cow->frontRightLeg->getTransform()->getLocalPosition();
			float fRLNewZ = Math::lerp(fRLStartPos.z, fRLStartPos.z + 0.01, (elapsedTime - 0.6) * 2);
			cow->frontRightLeg->getTransform()->setLocalPosition(Vector3(fRLStartPos.x, fRLStartPos.y, fRLNewZ));

			Vector3 bodyStartPos = cow->body->getTransform()->getLocalPosition();
			float bodyNewY = Math::lerp(bodyStartPos.y, bodyStartPos.y + 0.011, (elapsedTime - 0.6) * 2);
			cow->body->getTransform()->setLocalPosition(Vector3(bodyStartPos.x, bodyNewY, bodyStartPos.z));
		}
		else if (elapsedTime >= 1 && elapsedTime <= 6.97)
		{
			if (!boingPlayed)
			{
				boing->play();
				boingPlayed = true;
			}
			
			Vector3 cowPos = cow->getTransform()->getLocalPosition();
			camera->lookAt(cowPos);
			cowPos.x += 0.025;
			cowPos.y = sin(((elapsedTime - 1) * 30) * Math::DEG2RAD) * 25;
			cow->getTransform()->setLocalRotation(Quaternion((elapsedTime - 1) * (720 / 5.97) * Math::DEG2RAD, Math::PI / 2, 0));
			cow->getTransform()->setLocalPosition(cowPos);
		}
		else if (elapsedTime >= 7 && elapsedTime <= 8)
		{
			if (!lampExcited)
			{
				excitedLamp->play();
				lampExcited = true;
			}

			camera->setLocalPosition(Vector3(
				Math::lerp(6, 18, elapsedTime - 7),
				Math::lerp(0.5, 1.5, elapsedTime - 7),
				Math::lerp(10, 3, elapsedTime - 7)
			));
			camera->lookAt(cow->head->getTransform()->getWorldPosition());
		}
		else if (elapsedTime >= 8 && elapsedTime <= 9)
		{
			cow->neckJoint->getTransform()->setLocalRotation(Quaternion(
				-Math::PI / 4,
				0,
				Math::lerp(0, 45 * Math::DEG2RAD, elapsedTime - 8)));

			cow->headJoint->getTransform()->setLocalRotation(Quaternion(
				Math::PI / 4,
				-25 * Math::DEG2RAD,
				Math::lerp(0, 45 * Math::DEG2RAD, elapsedTime - 8)));
		}
		else if (elapsedTime >= 9 && elapsedTime <= 10.5)
		{
			Vector3 cowHeadPos = cow->head->getTransform()->getWorldPosition();
			if (!YEAHPlayed)
			{
				YEAH->play();
				YEAHPlayed = true;

				shades->setLocalRotation(Quaternion(Vector3(
					0,
					-90 * Math::DEG2RAD,
					0
				)));
			}

			shades->setLocalPosition(Vector3(
				cowHeadPos.x + 0.35,
				Math::lerp(cowHeadPos.y + 2, cowHeadPos.y + 0.1, (elapsedTime - 9) / 1.5),
				cowHeadPos.z - 0.2));
		}
	}
}