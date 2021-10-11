// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// Tutorial1.cpp
//
// Base application for tutorial 1.  Used in conjunction with DrawTask, a task for drawing onto a 2D texture.


#include "ToonShader.h"
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
#include "THouse.h"
#include "TCube.h"
#include "GLShader.h"

using namespace T3D;

ToonShader::ToonShader(void)
{
	drawTask = nullptr;
	drawArea = new Texture(renderer->WindowWidth, renderer->WindowHeight, false);
	drawArea->clear(Colour(0, 0, 0, 255));
}

bool ToonShader::init() {
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
	camObj->getTransform()->setLocalPosition(Vector3(0, 0.5, 15));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());

	// Material
	Material* green = renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(0, 1, 0, 1);

	Material* white = renderer->createMaterial(Renderer::PR_OPAQUE);
	white->setDiffuse(1, 1, 1, 1);

	Material* toonGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
	toonGreen->setDiffuse(0.0, 0.6, 0, 1);
	toonGreen->setShininess(20);
	GLShader* toonShader = new GLShader("Resources/toonVert.shader", "Resources/toonFrag.shader");
	toonShader->compileShader();
	toonGreen->setShader(toonShader);

	// Textures
	Texture* cratetex = new Texture("Resources/House.png", true, true);
	renderer->loadTexture(cratetex);
	Material* cratemat = renderer->createMaterial(Renderer::PR_OPAQUE);
	cratemat->setTexture(cratetex);

	// House
	GameObject* house = new GameObject(this);
	house->setMesh(new THouse());
	house->setMaterial(cratemat);
	house->getTransform()->setLocalPosition(Vector3(-2, 0, 10));
	house->getTransform()->setParent(root);
	house->getTransform()->name = "THouse";

	// Sphere
	GameObject* sphere = new GameObject(this);
	sphere->setMesh(new Sphere(1, 32));
	sphere->setMaterial(toonGreen);
	sphere->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	sphere->getTransform()->setParent(root);
	sphere->getTransform()->name = "Sphere";

	GameObject* cube = new GameObject(this);
	cube->setMesh(new Cube(10));
	cube->setMaterial(white);
	cube->getTransform()->setLocalPosition(Vector3(0, 0, -11));
	cube->getTransform()->setParent(root);
	cube->getTransform()->name = "Cube";

	renderer->ambient[0] = 0.3;
	renderer->ambient[1] = 0.3;
	renderer->ambient[2] = 0.3;

	return true;
}