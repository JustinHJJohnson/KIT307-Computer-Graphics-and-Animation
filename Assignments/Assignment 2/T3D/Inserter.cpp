#pragma once
#include "Inserter.h"
#include "T3DApplication.h"
#include "GameObject.h"
#include "Cyclinder.h"
#include "Transform.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "Sweep.h"
#include "Cube.h"

namespace T3D {
	Inserter::Inserter(T3DApplication* app) :GameObject(app) {
		setMesh(new Cylinder(.1, .01, 16));
		getTransform()->name = "Inserter";

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

		baseJoint = new GameObject(app);
		baseJoint->getTransform()->setParent(base->getTransform());
		baseJoint->getTransform()->name = "BaseJoint";

		elbowJoint = new GameObject(app);
		elbowJoint->getTransform()->setLocalPosition(Vector3(0, 0.2, 0));
		elbowJoint->getTransform()->setParent(baseJoint->getTransform());
		elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0))); // this rotation is just to make a good starting pose
		elbowJoint->getTransform()->name = "ElbowJoint";

		headJoint = new GameObject(app);
		headJoint->getTransform()->setLocalPosition(Vector3(0, 0.2, 0));
		headJoint->getTransform()->setParent(elbowJoint->getTransform());
		headJoint->getTransform()->name = "ShadeJoint";

		leftProngJoint = new GameObject(app);
		leftProngJoint->getTransform()->setLocalPosition(Vector3(-0.12, 0.11, 0));
		leftProngJoint->getTransform()->setParent(headJoint->getTransform());
		leftProngJoint->getTransform()->name = "LeftProngJoint";

		rightProngJoint = new GameObject(app);
		rightProngJoint->getTransform()->setLocalPosition(Vector3(0.12, 0.11, 0));
		rightProngJoint->getTransform()->setParent(headJoint->getTransform());
		rightProngJoint->getTransform()->name = "RightProngJoint";

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

		head = new GameObject(app);
		head->setMesh(new Sweep(armProfile, armsp, false));
		head->getTransform()->setLocalPosition(Vector3(0, 0.01, 0));
		head->getTransform()->setParent(headJoint->getTransform());
		head->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, Math::PI / 2)));;
		head->getTransform()->name = "BaseHead";

		leftProng = new GameObject(app);
		leftProng->setMesh(new Sweep(armProfile, armsp, false));
		leftProng->getTransform()->setLocalPosition(Vector3(0, 0.01, 0));
		leftProng->getTransform()->setParent(leftProngJoint->getTransform());
		//leftProng->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
		leftProng->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, 0)));
		leftProng->getTransform()->setLocalScale(Vector3(0.5, 1, 1));
		leftProng->getTransform()->name = "LeftProng";

		rightProng = new GameObject(app);
		rightProng->setMesh(new Sweep(armProfile, armsp, false));
		rightProng->getTransform()->setLocalPosition(Vector3(0, 0.01, 0));
		rightProng->getTransform()->setParent(rightProngJoint->getTransform());
		rightProng->getTransform()->setLocalRotation(Quaternion(Vector3(0, 0, 0)));
		rightProng->getTransform()->setLocalScale(Vector3(0.5, 1, 1));
		rightProng->getTransform()->name = "RightProng";
	}
}