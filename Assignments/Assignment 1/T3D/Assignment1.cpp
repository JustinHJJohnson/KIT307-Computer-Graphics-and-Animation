// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// Tutorial1.cpp
//
// Base application for tutorial 1.  Used in conjunction with DrawTask, a task for drawing onto a 2D texture.


#include "Assignment1.h"
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
#include "Tablet.h"
#include "Inserter.h"

using namespace T3D;

Assignment1::Assignment1(void)
{
	drawTask = nullptr;
	drawArea = new Texture(renderer->WindowWidth, renderer->WindowHeight, false);
	drawArea->clear(Colour(255, 255, 255, 255));
}

bool Assignment1::init() {
	WinGLApplication::init();

	// Light
	GameObject* lightObj = new GameObject(this);
	Light* light = new Light(Light::Type::DIRECTIONAL);
	light->setAmbient(1, 1, 1);
	light->setDiffuse(1, 1, 1);
	light->setSpecular(1, 1, 1);
	lightObj->setLight(light);
	lightObj->getTransform()->
		setLocalRotation(Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0));
	lightObj->getTransform()->setParent(root);

	// Camera
	GameObject* camObj = new GameObject(this);
	//renderer->camera = new Camera(Camera::Type::PERSPECTIVE, 0.1, 500.0, 45.0, 1.6);
	renderer->camera = new Camera();
	camObj->getTransform()->setLocalPosition(Vector3(0, 0, 20));
	camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());

	// Material
	Material* green = renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(0, 1, 0, 1);

	// Lamp
	/*Material* grey = renderer->createMaterial(Renderer::PR_OPAQUE);
	grey->setDiffuse(0.8, 0.8, 0.9, 1);
	Lamp* lamp = new Lamp(this);
	lamp->setMaterial(grey);
	lamp->getTransform()->setLocalPosition(Vector3(-2, 0, 2));
	lamp->getTransform()->setParent(root);
	lamp->base->setMaterial(grey);
	lamp->arm1->setMaterial(grey);
	lamp->arm2->setMaterial(grey);
	lamp->shade->setMaterial(grey);
	lamp->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 10, Math::PI / 4, 0)));
	lamp->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));
	lamp->shadeJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));*/

	// Lamp
	Material* grey = renderer->createMaterial(Renderer::PR_OPAQUE);
	grey->setDiffuse(0.8, 0.8, 0.9, 1);
	Inserter* inserter = new Inserter(this);
	inserter->setMaterial(grey);
	inserter->getTransform()->setLocalPosition(Vector3(-2, 0, 2));
	inserter->getTransform()->setParent(root);
	inserter->base->setMaterial(grey);
	inserter->arm1->setMaterial(grey);
	inserter->arm2->setMaterial(grey);
	inserter->head->setMaterial(grey);
	inserter->leftProng->setMaterial(grey);
	inserter->rightProng->setMaterial(grey);
	inserter->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 10, Math::PI / 4, 0)));
	inserter->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));
	inserter->headJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));

	// Tablet 
	GameObject* tablet = new GameObject(this);
	tablet->setMesh(new Tablet(Vector3(5, 0.7, 3), 0.5, 0.5, 0.2, 8));
	tablet->setMaterial(green);
	tablet->getTransform()->setLocalPosition(Vector3(7, 0, 7));
	tablet->getTransform()->setParent(root);
	tablet->getTransform()->name = "Tablet";

	return true;
}