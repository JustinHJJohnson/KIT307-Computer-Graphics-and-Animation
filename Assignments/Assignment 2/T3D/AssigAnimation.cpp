// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// Tutorial1.cpp
//
// Base application for tutorial 1.  Used in conjunction with DrawTask, a task for drawing onto a 2D texture.


#include "AssigAnimation.h"
#include "WinGLApplication.h"
#include "GLRenderer.h"
#include "Camera.h"
#include "Math.h"
#include "GameObject.h"
#include "Transform.h"
#include "KeyboardController.h"
#include "MainAnimation.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "PlaneMesh.h"
#include "Inserter.h"
#include "Speaker.h"
#include "Bottle.h"
#include "GLShader.h"

using namespace T3D;

AssigAnimation::AssigAnimation(void)
{
	//drawTask = nullptr;
	//drawArea = new Texture(renderer->WindowWidth, renderer->WindowHeight, false);
	//drawArea->clear(Colour(0, 0, 0, 255));
}

bool AssigAnimation::init() {
	WinGLApplication::init();

	// Light
	GameObject* lightObj = new GameObject(this);
	Light* light = new Light(Light::Type::DIRECTIONAL);
	light->setAmbient(1, 1, 1);
	light->setDiffuse(1, 1, 1);
	light->setSpecular(1, 1, 1);
	lightObj->setLight(light);
	lightObj->getTransform()->
		setLocalRotation(
			Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0));
	lightObj->getTransform()->setParent(root);

	//add a camera to the scene
	//This camera is super fast... you have been warned
	GameObject* camObj = new GameObject(this);
	renderer->camera = new Camera(0.1, 500.0, 45.0, 1.6);
	camObj->getTransform()->setLocalPosition(Vector3(0.7, 0.5, 1.8));
	camObj->getTransform()->setLocalRotation(Vector3(22 * Math::DEG2RAD, 115 * Math::DEG2RAD, 0));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());

	// Materials
	Material* green = renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(0, 1, 0, 1);
	Material* white = renderer->createMaterial(Renderer::PR_OPAQUE);
	white->setDiffuse(1, 1, 1, 1);
	Material* yellow = renderer->createMaterial(Renderer::PR_OPAQUE);
	yellow->setDiffuse(0.8, 0.8, 0, 1);
	Material* floor = renderer->createMaterial(Renderer::PR_OPAQUE);
	floor->setDiffuse(0.5, 0.5, 0.5, 1);
	Material* darkGrey = renderer->createMaterial(Renderer::PR_OPAQUE);
	darkGrey->setDiffuse(0.6, 0.6, 0.6, 1);
	Material* grey = renderer->createMaterial(Renderer::PR_OPAQUE);
	grey->setDiffuse(0.8, 0.8, 0.9, 1);
	Material* brown = renderer->createMaterial(Renderer::PR_OPAQUE);
	brown->setDiffuse(0.5, 0.35, 0.05, 1);
	Material* black = renderer->createMaterial(Renderer::PR_OPAQUE);
	black->setDiffuse(0, 0, 0, 1);

	// The floor
	GameObject* plane = new GameObject(this);
	plane->setMesh(new PlaneMesh(1));
	plane->setMaterial(floor);
	plane->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	plane->getTransform()->setLocalScale(Vector3(30, 1, 30));
	plane->getTransform()->setParent(root);
	plane->getTransform()->name = "Plane";

	// Inserter1
	Inserter* inserter1 = new Inserter(this);
	inserter1->setMaterial(green);
	inserter1->getTransform()->setLocalPosition(Vector3(-5, 0, 5));
	inserter1->getTransform()->setParent(root);
	inserter1->base->setMaterial(green);
	inserter1->arm1->setMaterial(green);
	inserter1->arm2->setMaterial(green);
	inserter1->head->setMaterial(green);
	inserter1->leftProng->setMaterial(green);
	inserter1->rightProng->setMaterial(green);
	inserter1->base->getTransform()->setLocalRotation(Quaternion(Vector3(0, Math::PI / 4,0)));
	inserter1->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 10, Math::PI / 4, 0)));
	inserter1->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));
	inserter1->headJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));

	// Inserter2
	Inserter* inserter2 = new Inserter(this);
	inserter2->setMaterial(darkGrey);
	inserter2->getTransform()->setLocalPosition(Vector3(-5, 0, 5));
	inserter2->getTransform()->setParent(root);
	inserter2->base->setMaterial(darkGrey);
	inserter2->arm1->setMaterial(darkGrey);
	inserter2->arm2->setMaterial(darkGrey);
	inserter2->head->setMaterial(darkGrey);
	inserter2->leftProng->setMaterial(darkGrey);
	inserter2->rightProng->setMaterial(darkGrey);
	inserter2->base->getTransform()->setLocalRotation(Quaternion(Vector3(0, Math::PI / 4, 0)));
	inserter2->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 10, Math::PI / 4, 0)));
	inserter2->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));
	inserter2->headJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));

	// Inserter3
	Inserter* inserter3 = new Inserter(this);
	inserter3->setMaterial(yellow);
	inserter3->getTransform()->setLocalPosition(Vector3(-5, 0, 5));
	inserter3->getTransform()->setParent(root);
	inserter3->base->setMaterial(yellow);
	inserter3->arm1->setMaterial(yellow);
	inserter3->arm2->setMaterial(yellow);
	inserter3->head->setMaterial(yellow);
	inserter3->leftProng->setMaterial(yellow);
	inserter3->rightProng->setMaterial(yellow);
	inserter3->base->getTransform()->setLocalRotation(Quaternion(Vector3(0, Math::PI / 4, 0)));
	inserter3->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 10, Math::PI / 4, 0)));
	inserter3->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));
	inserter3->headJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));

	// Inserter4
	Inserter* inserter4 = new Inserter(this);
	inserter4->setMaterial(white);
	inserter4->getTransform()->setLocalPosition(Vector3(-5, 0, 5));
	inserter4->getTransform()->setParent(root);
	inserter4->base->setMaterial(white);
	inserter4->arm1->setMaterial(white);
	inserter4->arm2->setMaterial(white);
	inserter4->head->setMaterial(white);
	inserter4->leftProng->setMaterial(white);
	inserter4->rightProng->setMaterial(white);
	inserter4->base->getTransform()->setLocalRotation(Quaternion(Vector3(0, Math::PI / 4, 0)));
	inserter4->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 10, Math::PI / 4, 0)));
	inserter4->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));
	inserter4->headJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));

	// Speaker
	Speaker* speaker = new Speaker(this);
	speaker->setMaterial(grey);
	speaker->getTransform()->setLocalPosition(Vector3(0, 0.8, 2.2));
	speaker->getTransform()->setParent(root);
	speaker->speaker->setMaterial(grey);
	speaker->speaker->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / -1.6, 0, 0)));

	// Bowling ball
	GameObject* bowlingBall = new GameObject(this);
	bowlingBall->setMesh(new Sphere(0.115, 100));
	bowlingBall->setMaterial(black);
	bowlingBall->getTransform()->setLocalPosition(Vector3(5, 0.2, 0));
	bowlingBall->getTransform()->setParent(root);
	bowlingBall->getTransform()->name = "bowlingBall";

	// Bottle
	/*Bottle* bottle = new Bottle(this);
	bottle->setMaterial(green);
	bottle->getTransform()->setLocalPosition(Vector3(1, 1, 0));
	bottle->getTransform()->setParent(root);
	bottle->bottle->setMaterial(green);
	//bottle->bottle->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 1.6, 0, 0)));*/

	// The Building
	GameObject* doorLeftWall = new GameObject(this);
	doorLeftWall->setMesh(new Cube(1));
	doorLeftWall->setMaterial(brown);
	doorLeftWall->getTransform()->setLocalPosition(Vector3(3, 0, -1.5));
	doorLeftWall->getTransform()->setParent(root);
	doorLeftWall->getTransform()->name = "doorLeftWall";

	GameObject* doorRightWall = new GameObject(this);
	doorRightWall->setMesh(new Cube(1));
	doorRightWall->setMaterial(brown);
	doorRightWall->getTransform()->setLocalPosition(Vector3(3, 0, 1.5));
	doorRightWall->getTransform()->setParent(root);
	doorRightWall->getTransform()->name = "doorRightWall";

	GameObject* roof = new GameObject(this);
	roof->setMesh(new PlaneMesh(1));
	roof->setMaterial(grey);
	roof->getTransform()->setLocalPosition(Vector3(0, 1, 0));
	roof->getTransform()->setLocalScale(Vector3(20, 1, 30));
	roof->getTransform()->setLocalRotation(Vector3(180 * Math::DEG2RAD, 0, 0));
	roof->getTransform()->setParent(root);
	roof->getTransform()->name = "Roof";

	GameObject* outsideLeftWall = new GameObject(this);
	outsideLeftWall->setMesh(new PlaneMesh(1));
	outsideLeftWall->setMaterial(brown);
	outsideLeftWall->getTransform()->setLocalPosition(Vector3(0, 0, -2.2));
	outsideLeftWall->getTransform()->setLocalScale(Vector3(10, 1, 2));
	outsideLeftWall->getTransform()->setLocalRotation(Vector3(90 * Math::DEG2RAD, 0, 0));
	outsideLeftWall->getTransform()->setParent(root);
	outsideLeftWall->getTransform()->name = "OutsideLeftWall";

	GameObject* outsideRightWall = new GameObject(this);
	outsideRightWall->setMesh(new PlaneMesh(1));
	outsideRightWall->setMaterial(brown);
	outsideRightWall->getTransform()->setLocalPosition(Vector3(0, 0, 2.2));
	outsideRightWall->getTransform()->setLocalScale(Vector3(10, 1, 2));
	outsideRightWall->getTransform()->setLocalRotation(Vector3(-90 * Math::DEG2RAD, 0, 0));
	outsideRightWall->getTransform()->setParent(root);
	outsideRightWall->getTransform()->name = "OutsideRightWall";

	GameObject* outsideFrontWall = new GameObject(this);
	outsideFrontWall->setMesh(new PlaneMesh(1));
	outsideFrontWall->setMaterial(brown);
	outsideFrontWall->getTransform()->setLocalPosition(Vector3(-2, 0, 0));
	outsideFrontWall->getTransform()->setLocalScale(Vector3(5, 1, 2));
	outsideFrontWall->getTransform()->setLocalRotation(Vector3(90 * Math::DEG2RAD, 90 * Math::DEG2RAD, 0));
	outsideFrontWall->getTransform()->setParent(root);
	outsideFrontWall->getTransform()->name = "OutsideFrontWall";

	// Setup the animation task
	MainAnimation* animTask = new MainAnimation(this);
	animTask->camera = camObj->getTransform();
	animTask->inserter1 = inserter1;
	animTask->inserter2 = inserter2;
	animTask->inserter3 = inserter3;
	animTask->inserter4 = inserter4;
	animTask->bowlingBall = bowlingBall->getTransform();

	addTask(animTask);

	return true;
}