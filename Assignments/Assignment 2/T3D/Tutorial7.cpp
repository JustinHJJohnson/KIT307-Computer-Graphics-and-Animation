#include "Tutorial7.h"
#include "WinGLApplication.h"
#include "GLRenderer.h"
#include "Camera.h"
#include "Math.h"
#include "GameObject.h"
#include "Transform.h"
#include "KeyboardController.h"
#include "Cube.h"
#include "TCube.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "TCylinder.h"
#include "Lamp.h"
#include "Sphere.h"
#include "GLShader.h"
#include "AnimationTest.h"
#include "LookAtBehaviour.h"
#include "LampBehaviour.h"
#include "Animation.h"

using namespace T3D;

Tutorial7::Tutorial7(void)
{
	drawTask = nullptr;
	drawArea = new Texture(renderer->WindowWidth, renderer->WindowHeight, false);
	drawArea->clear(Colour(0, 0, 0, 255));
}

bool Tutorial7::init() {
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
	camObj->getTransform()->setLocalPosition(Vector3(0, 0.5, 10));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());

	// Material
	Material* green = renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(0, 1, 0, 1);

	// Textures
	Texture* cratetex = new Texture("Resources/crate013jc.jpg", true, true);
	renderer->loadTexture(cratetex);
	Material* cratemat = renderer->createMaterial(Renderer::PR_OPAQUE);
	cratemat->setTexture(cratetex);

	Texture* barreltex = new Texture("Resources/ExplosiveBarrel.jpg", true, true);
	renderer->loadTexture(barreltex);
	Material* barrelmat = renderer->createMaterial(Renderer::PR_OPAQUE);
	barrelmat->setTexture(barreltex);

	// Cyclinder
	GameObject* cylinder = new GameObject(this);
	cylinder->setMesh(new TCylinder(1, 1, 10));
	cylinder->setMaterial(barrelmat);
	cylinder->getTransform()->setLocalPosition(Vector3(2, 0, 0));
	cylinder->getTransform()->setParent(root);
	cylinder->getTransform()->name = "Cylinder";

	// Cube
	GameObject* cube = new GameObject(this);
	cube->setMesh(new TCube(1));
	cube->setMaterial(cratemat);
	cube->getTransform()->setLocalPosition(Vector3(-2, 0, 0));
	cube->getTransform()->setParent(root);
	cube->getTransform()->name = "Cube";

	renderer->ambient[0] = 0.3;
	renderer->ambient[1] = 0.3;
	renderer->ambient[2] = 0.3;

	return true;
}
