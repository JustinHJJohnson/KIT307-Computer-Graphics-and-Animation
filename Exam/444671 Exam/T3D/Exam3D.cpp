#include "Exam3D.h"
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
#include "Sphere.h"
#include "CoolShades.h"
#include "GLShader.h"
#include "AnimationTest.h"
#include "LookAtBehaviour.h"
#include "LampBehaviour.h"
#include "Animation.h"
#include "Cow.h"
#include "Terrain.h"
#include "MainAnimation.h"
#include "Lamp.h";

using namespace T3D;

Exam3D::Exam3D(void)
{
	drawTask = nullptr;
	drawArea = new Texture(renderer->WindowWidth, renderer->WindowHeight, false);
	drawArea->clear(Colour(255, 255, 255, 255));
}

bool Exam3D::init() {
	WinGLApplication::init();

	// https://assetstore.unity.com/packages/2d/textures-materials/sky/10-skyboxes-pack-day-night-32236#content
	renderer->loadSkybox("Resources/SkyMidNight");
	renderer->setFog(0.007f, 0.0f, 0.5f, 0.0f, 1.0f);
	renderer->toggleFog();
	
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
	camObj->getTransform()->setLocalPosition(Vector3(6, 0.5, 10));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->getTransform()->setLocalRotation(Quaternion(Vector3(2 * Math::DEG2RAD, 55 * Math::DEG2RAD, 0)));
	//camObj->addComponent(new KeyboardController());

	// Material
	Material* green = renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(0, 1, 0, 1);
	Material* black = renderer->createMaterial(Renderer::PR_OPAQUE);
	black->setDiffuse(0, 0, 0, 1);
	Material* white = renderer->createMaterial(Renderer::PR_OPAQUE);
	white->setDiffuse(1, 1, 1, 1);
	Material* brown = renderer->createMaterial(Renderer::PR_OPAQUE);
	brown->setDiffuse(0.3921, 0.2275, 0, 1);
	Material* grey = renderer->createMaterial(Renderer::PR_OPAQUE);
	grey->setDiffuse(0.8, 0.8, 0.9, 1);

	GameObject* shades = new GameObject(this);
	shades->setMesh(new CoolShades());
	shades->setMaterial(black);
	shades->getTransform()->setLocalPosition(Vector3(0, -5, -3));
	shades->getTransform()->setParent(root);
	shades->getTransform()->name = "Shades";

	GameObject* moon = new GameObject(this);
	moon->setMesh(new Sphere(3, 10));
	moon->setMaterial(white);
	moon->getTransform()->setLocalPosition(Vector3(6, 15, 0));
	moon->getTransform()->setParent(root);
	moon->getTransform()->name = "Moon";

	Cow* cow = new Cow(this);
	cow->setMaterial(white);
	cow->body->setMaterial(white);
	cow->neck->setMaterial(white); 
	cow->head->setMaterial(white);
	cow->backLeftLeg->setMaterial(white);
	cow->backRightLeg->setMaterial(white);
	cow->frontLeftLeg->setMaterial(white);
	cow->frontRightLeg->setMaterial(white);
	cow->getTransform()->setLocalPosition(Vector3(-4, 0, 0));
	cow->getTransform()->setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
	cow->getTransform()->setParent(root);
	cow->getTransform()->name = "Cow";

	Lamp* lamp = new Lamp(this);
	lamp->setMaterial(grey);
	lamp->getTransform()->setLocalPosition(Vector3(24, 0, -6));
	lamp->getTransform()->setLocalScale(Vector3(2, 2, 2));
	lamp->getTransform()->setParent(root);
	lamp->base->setMaterial(grey);
	lamp->arm1->setMaterial(grey);
	lamp->arm2->setMaterial(grey);
	lamp->shade->setMaterial(grey);
	lamp->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 10, Math::PI / 4, 0)));
	lamp->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));
	lamp->shadeJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));

	Texture* proctex = new Texture("Resources/Terrain.bmp");
	renderer->loadTexture(proctex, true);
	Material* procmat = renderer->createMaterial(Renderer::PR_TERRAIN);
	procmat->setTexture(proctex, 50);
	procmat->setSpecular(0, 0, 0, 0);
	
	GameObject* terrain = new GameObject(this);
	Terrain* terrainComponent = new Terrain();
	terrain->addComponent(terrainComponent);
	terrainComponent->createTerrain("Resources/Terrain.bmp", 500, 20); // procedurally generate terrain
	terrain->setMaterial(brown);
	terrain->getTransform()->setLocalPosition(Vector3(0, -12.5, 0));
	terrain->getTransform()->setParent(root);
	terrain->getTransform()->name = "Terrain";

	Vector3 lampPos = lamp->getTransform()->getWorldPosition();
	Vector3 lampPosJump = Vector3(lampPos.x, lampPos.y + 1, lampPos.z);

	// Keyframe animation for a very impressed lamp that saw that sick jump
	Animation* excitedLamp = new Animation(1);
	lamp->addComponent(excitedLamp);
	excitedLamp->addKey("ElbowJoint", 0, Quaternion(Vector3(Math::HALF_PI, 0, 0)), Vector3(0, 0.2, 0));
	excitedLamp->addKey("BaseJoint", 0, Quaternion(Vector3(-Math::PI / 4, 0, 0)), Vector3(0, 0, 0));
	excitedLamp->addKey("Lamp", 0, Quaternion(Vector3(0, -45 * Math::DEG2RAD, 0)), lampPos);
	excitedLamp->addKey("ElbowJoint", 0.5, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0.2, 0));
	excitedLamp->addKey("BaseJoint", 0.5, Quaternion(Vector3(0, 0, 0)), Vector3(0, 0, 0));
	excitedLamp->addKey("Lamp", 0.5, Quaternion(Vector3(0, -45 * Math::DEG2RAD, 0)), lampPosJump);
	excitedLamp->addKey("ElbowJoint", 1, Quaternion(Vector3(Math::HALF_PI, 0, 0)), Vector3(0, 0.2, 0));
	excitedLamp->addKey("BaseJoint", 1, Quaternion(Vector3(-Math::PI / 4, 0, 0)), Vector3(0, 0, 0));
	excitedLamp->addKey("Lamp", 1, Quaternion(Vector3(0, -45 * Math::DEG2RAD, 0)), lampPos);
	excitedLamp->loop(true);

	// Setup the animation task
	MainAnimation* animTask = new MainAnimation(this);
	animTask->camera = camObj->getTransform();
	animTask->cow = cow;
	animTask->shades = shades->getTransform();
	animTask->excitedLamp = excitedLamp;
	addTask(animTask);

	return true;
}
