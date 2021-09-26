// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// Tutorial1.cpp
//
// Base application for tutorial 1.  Used in conjunction with DrawTask, a task for drawing onto a 2D texture.


#include "Tutorial6.h"
#include "WinGLApplication.h"
#include "GLRenderer.h"
#include "Camera.h"
#include "Math.h"
#include "GameObject.h"
#include "Transform.h"
#include "KeyboardController.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "Lamp.h"
#include "Sphere.h"
#include "GLShader.h"
#include "AnimationTest.h"
#include "LookAtBehaviour.h"
#include "LampBehaviour.h"
#include "Animation.h"

using namespace T3D;

Tutorial6::Tutorial6(void)
{
	drawTask = nullptr;
	drawArea = new Texture(renderer->WindowWidth, renderer->WindowHeight, false);
	drawArea->clear(Colour(255, 255, 255, 255));
}

bool Tutorial6::init() {
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
	camObj->getTransform()->setLocalPosition(Vector3(0, 0.5, 3));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());

	// Lamp
	Material* grey = renderer->createMaterial(Renderer::PR_OPAQUE);
	grey->setDiffuse(0.8, 0.8, 0.9, 1);
	Lamp* lamp = new Lamp(this);
	lamp->setMaterial(grey);
	lamp->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	lamp->getTransform()->setParent(root);
	lamp->base->setMaterial(grey);
	lamp->arm1->setMaterial(grey);
	lamp->arm2->setMaterial(grey);
	lamp->shade->setMaterial(grey);
	lamp->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 10, Math::PI / 4, 0)));
	lamp->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));
	lamp->shadeJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));

	// Different animation methods
	// Task
	/*AnimationTest* animTask = new AnimationTest(this);
	animTask->lamp = lamp->getTransform();
	addTask(animTask);

	// Behaviour
	GameObject* lookAt = new GameObject(this);
	lookAt->getTransform()->setLocalPosition(Vector3(0, 0, 5));

	lamp->addComponent(new LookAtBehaviour(lookAt->getTransform()));*/
	//lamp->addComponent(new LampBehaviour());

	// Key-Frames
	Animation* anim = new Animation(10.0);
	lamp->addComponent(anim);
	anim->addKey("ElbowJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
	anim->addKey("ElbowJoint", 5.0, Quaternion(Vector3(-Math::HALF_PI, 0, 0)), Vector3(0, 0.2, 0));
	anim->addKey("ElbowJoint", 7.0, Quaternion(Vector3(Math::HALF_PI, 0, 0)), Vector3(0, 0.2, 0));
	anim->addKey("ElbowJoint", 10.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
	anim->addKey("ShadeJoint", 0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
	anim->addKey("ShadeJoint", 5.0, Quaternion(Vector3(0, 0, -Math::HALF_PI)), Vector3(0, 0.2, 0));
	anim->addKey("ShadeJoint", 7.0, Quaternion(Vector3(0, 0, Math::HALF_PI)), Vector3(0, 0.2, 0));
	anim->addKey("ShadeJoint", 10.0, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
	anim->loop(true);
	anim->play();
	
	return true;
}