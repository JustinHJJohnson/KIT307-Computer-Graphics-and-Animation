// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// Tutorial1.cpp
//
// Base application for tutorial 1.  Used in conjunction with DrawTask, a task for drawing onto a 2D texture.


#include "Tutorial5.h"
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

using namespace T3D;

Tutorial5::Tutorial5(void)
{
	drawTask = nullptr;
	drawArea = new Texture(renderer->WindowWidth, renderer->WindowHeight, false);
	drawArea->clear(Colour(255, 255, 255, 255));
}

bool Tutorial5::init() {
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

	// Material
	Material* green = renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(0, 1, 0, 1);

	Material* fixedGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
	fixedGreen->setDiffuse(0.0, 0.6, 0, 1);
	fixedGreen->setShininess(20);

	Material* gouraudGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
	gouraudGreen->setDiffuse(0.0, 0.6, 0, 1);
	gouraudGreen->setShininess(20);
	GLShader* gouraudShader = new GLShader("Resources/vspecular.shader", "Resources/frag.shader");
	gouraudShader->compileShader();
	gouraudGreen->setShader(gouraudShader);

	Material* phongGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
	phongGreen->setDiffuse(0.0, 0.6, 0, 1);
	phongGreen->setShininess(20);
	GLShader* phongShader = new GLShader("Resources/phongVert.shader", "Resources/phongFrag.shader");
	phongShader->compileShader();
	phongGreen->setShader(phongShader);

	// Cyclinder
	GameObject* sphere1 = new GameObject(this);
	sphere1->setMesh(new Sphere(1, 32));
	sphere1->setMaterial(fixedGreen);
	sphere1->getTransform()->setLocalPosition(Vector3(-3, 0, 0));
	sphere1->getTransform()->setParent(root);
	sphere1->getTransform()->name = "Sphere1";
	// Cyclinder
	GameObject* sphere2 = new GameObject(this);
	sphere2->setMesh(new Sphere(1, 32));
	sphere2->setMaterial(gouraudGreen);
	sphere2->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	sphere2->getTransform()->setParent(root);
	sphere2->getTransform()->name = "Sphere2";
	// Cyclinder
	GameObject* sphere3 = new GameObject(this);
	sphere3->setMesh(new Sphere(1, 32));
	sphere3->setMaterial(phongGreen);
	sphere3->getTransform()->setLocalPosition(Vector3(3, 0, 0));
	sphere3->getTransform()->setParent(root);
	sphere3->getTransform()->name = "Sphere3";

	return true;
}