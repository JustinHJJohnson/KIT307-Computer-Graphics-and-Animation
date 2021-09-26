// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// Tutorial1.cpp
//
// Base application for tutorial 1.  Used in conjunction with DrawTask, a task for drawing onto a 2D texture.


#include "Tutorial3.h"
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

using namespace T3D;

Tutorial3::Tutorial3(void)
{
	drawTask = nullptr;
	drawArea = new Texture(renderer->WindowWidth, renderer->WindowHeight, false);
	drawArea->clear(Colour(255, 255, 255, 255));
}

bool Tutorial3::init() {
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

	// Camera
	GameObject* camObj = new GameObject(this);
	renderer->camera = new Camera(0.1, 500.0, 45.0, 1.6);
	camObj->getTransform()->setLocalPosition(Vector3(0, 0, 20));
	camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());

	// Material
	Material* green = renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(0, 1, 0, 1);

	// Pyramid
	/*GameObject* pyramid = new GameObject(this);
	pyramid->setMesh(new Pyramid(1));
	pyramid->setMaterial(green);
	pyramid->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	pyramid->getTransform()->setParent(root);
	pyramid->getTransform()->name = "Pyramid";*/

	// Cyclinder
	GameObject* cylinder = new GameObject(this);
	cylinder->setMesh(new Cylinder(10.0f, 10.0f, 8));
	cylinder->setMaterial(green);
	cylinder->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	cylinder->getTransform()->setParent(root);
	cylinder->getTransform()->name = "Cylinder";

	return true;
}