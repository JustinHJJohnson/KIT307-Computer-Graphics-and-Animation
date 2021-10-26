#pragma once
#include "Lamp.h"
#include "T3DApplication.h"
#include "GameObject.h"
#include "Cyclinder.h"
#include "Transform.h"
#include "SweepPath.h"
#include "Sweep.h"

namespace T3D {
	Lamp::Lamp(T3DApplication* app):GameObject(app) {
		setMesh(new Cylinder(.1, .01, 16));
		getTransform()->name = "Lamp";

		base = new GameObject(app); // note the use of 'app' not 'this' - you should understand why
		base->setMesh(new Cylinder(.02, .01, 16));
		base->getTransform()->setParent(getTransform()); // attaching this piece to the Lamp object's transform
		base->getTransform()->setLocalPosition(Vector3(0, 0.02, 0));
		base->getTransform()->name = "Base";

		std::vector<Vector3> armProfile;
		armProfile.push_back(Vector3(0.0f, -0.12f, 0.0f));
		armProfile.push_back(Vector3(0.014f, -0.114f, 0.0f));
		armProfile.push_back(Vector3(0.02f, -0.1f, 0.0f));
		armProfile.push_back(Vector3(0.02f, 0.1f, 0.0f));
		armProfile.push_back(Vector3(0.014f, 0.114f, 0.0f));
		armProfile.push_back(Vector3(0.0f, 0.12f, 0.0f));
		armProfile.push_back(Vector3(-0.014f, 0.114f, 0.0f));
		armProfile.push_back(Vector3(-0.02f, 0.1f, 0.0f));
		armProfile.push_back(Vector3(-0.02f, -0.1f, 0.0f));
		armProfile.push_back(Vector3(-0.014f, -0.114f, 0.0f));

		SweepPath armsp;
		Transform t;

		t.setLocalPosition(Vector3(-0.01, 0, 0));
		t.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
		t.setLocalScale(Vector3(0, 0, 1.0)); // no need to scale the z-direction because the profile is in the XY plane
		armsp.addTransform(t);

		t.setLocalScale(Vector3(0.9, 1, 1.0));
		armsp.addTransform(t);
		armsp.addTransform(t);

		t.setLocalPosition(Vector3(-0.0075, 0, 0));
		t.setLocalScale(Vector3(1, 1, 1.0));
		armsp.addTransform(t);
		armsp.addTransform(t);

		t.setLocalPosition(Vector3(0.0075, 0, 0));
		armsp.addTransform(t);
		armsp.addTransform(t);

		t.setLocalPosition(Vector3(0.01, 0, 0));
		t.setLocalScale(Vector3(0.9, 1, 1.0));
		armsp.addTransform(t);
		armsp.addTransform(t);

		t.setLocalScale(Vector3(0, 0, 1.0));
		armsp.addTransform(t);
		armsp.addTransform(t);

		std::vector<Vector3> shadeProfile;
		shadeProfile.push_back(Vector3(0, -0.5, 0) * 0.08);
		shadeProfile.push_back(Vector3(0.5, -0.4, 0) * 0.08);
		shadeProfile.push_back(Vector3(0.6, 0.4, 0) * 0.08);
		shadeProfile.push_back(Vector3(1, 2, 0) * 0.08);
		shadeProfile.push_back(Vector3(1.5, 2.5, 0) * 0.08);
		shadeProfile.push_back(Vector3(1.5, 2.5, 0) * 0.08);
		shadeProfile.push_back(Vector3(1.45, 2.6, 0) * 0.08);
		shadeProfile.push_back(Vector3(1.45, 2.6, 0) * 0.08);
		shadeProfile.push_back(Vector3(0.9, 2.1, 0) * 0.08);
		shadeProfile.push_back(Vector3(0.5, 0.35, 0) * 0.08);
		shadeProfile.push_back(Vector3(0, 0.4, 0) * 0.08);

		SweepPath shadesp;

		shadesp.makeCirclePath(0, 100);

		baseJoint = new GameObject(app);
		baseJoint->getTransform()->setParent(base->getTransform());
		baseJoint->getTransform()->name = "BaseJoint";

		elbowJoint = new GameObject(app);
		elbowJoint->getTransform()->setLocalPosition(Vector3(0, 0.2, 0));
		elbowJoint->getTransform()->setParent(baseJoint->getTransform());
		elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0))); // this rotation is just to make a good starting pose
		elbowJoint->getTransform()->name = "ElbowJoint";

		shadeJoint = new GameObject(app);
		shadeJoint->getTransform()->setLocalPosition(Vector3(0, 0.2, 0));
		shadeJoint->getTransform()->setParent(elbowJoint->getTransform());
		shadeJoint->getTransform()->name = "ShadeJoint";

		arm1 = new GameObject(app);
		arm1->setMesh(new Sweep(armProfile, armsp, false));
		arm1->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
		arm1->getTransform()->setParent(baseJoint->getTransform());
		arm1->getTransform()->name = "Arm1";

		arm2 = new GameObject(app);
		arm2->setMesh(new Sweep(armProfile, armsp, false));
		arm2->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
		arm2->getTransform()->setParent(elbowJoint->getTransform());
		arm2->getTransform()->name = "Arm2";
		
		shade = new GameObject(app);
		shade->setMesh(new Sweep(shadeProfile, shadesp, false));
		shade->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		shade->getTransform()->setParent(shadeJoint->getTransform());
		shade->getTransform()->name = "Shade";
	}
}