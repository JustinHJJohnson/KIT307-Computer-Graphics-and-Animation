#pragma once
#include "Cow.h"
#include "T3DApplication.h"
#include "GameObject.h"
#include "Cyclinder.h"
#include "Transform.h"
#include "SweepPath.h"
#include "Sweep.h"
#include "Sphere.h"

namespace T3D 
{
	Cow::Cow(T3DApplication* app) :GameObject(app) {
		//setMesh(new Cylinder(.1, .01, 16));
		getTransform()->name = "Lamp";

		body = new GameObject(app); // note the use of 'app' not 'this' - you should understand why
		body->setMesh(new Cylinder(.5, 1, 20));
		body->getTransform()->setParent(getTransform()); // attaching this piece to the Lamp object's transform
		body->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		body->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
		body->getTransform()->name = "Body";

		neckJoint = new GameObject(app);
		neckJoint->getTransform()->setLocalPosition(Vector3(0, 0.9, -0.4));
		neckJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 4, 0, 0)));
		neckJoint->getTransform()->setParent(body->getTransform());
		neckJoint->getTransform()->name = "NeckJoint";

		headJoint = new GameObject(app);
		headJoint->getTransform()->setLocalPosition(Vector3(0, 0.5, -0.1));
		headJoint->getTransform()->setParent(neckJoint->getTransform());
		headJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0))); // this rotation is just to make a good starting pose
		headJoint->getTransform()->name = "HeadJoint";

		neck = new GameObject(app);
		neck->setMesh(new Cylinder(0.2, 0.6, 20));
		neck->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
		neck->getTransform()->setParent(neckJoint->getTransform());
		neck->getTransform()->name = "Neck";

        int density = 30;
        std::vector<Vector3> headProfile;
        float radius = 0.08f;
        float dTheta = Math::TWO_PI / density;

        for (int i = 0; i < density; i++)
        {
            float theta = i * dTheta;
            float x = radius * cos(theta);
            float y = radius * sin(theta);

            headProfile.push_back(Vector3(x, y, 0.0f));
        }

        SweepPath headPath;
        Transform t;

		t.setLocalPosition(Vector3(0, 0, -0.2));
		t.setLocalRotation(Quaternion(Vector3(-Math::PI / 4, 0, 0)));
		t.setLocalScale(Vector3(0.0001, 0.0001, 0.0001));
		headPath.addTransform(t);
		
		t.setLocalPosition(Vector3(0, 0, -0.2));
		t.setLocalRotation(Quaternion(Vector3(-Math::PI / 4, 0, 0)));
		t.setLocalScale(Vector3(3.8, 3.8, 3.0));
		headPath.addTransform(t);
		
		t.setLocalPosition(Vector3(0, 0.2, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 4, 0, 0)));
        t.setLocalScale(Vector3(3.8, 3.8, 3.0));
        headPath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.3, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(3.4, 3.4, 3.0));
        headPath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.4, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(3.2, 3.2, 3.0));
        headPath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.5, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(3, 3, 3.0));
        headPath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.6, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(2.8, 2.8, 3));
        headPath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.7, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(2.6, 2.6, 3.0));
        headPath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.7, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(0.001, 0.001, 0.001));
        headPath.addTransform(t);

        head = new GameObject(app);
        head->setMesh(new Sweep(headProfile, headPath, false));
        head->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
        head->getTransform()->setParent(headJoint->getTransform());
        head->getTransform()->name = "Head";

		backLeftLeg = new GameObject(app);
		backLeftLeg->setMesh(new Cylinder(0.1, 0.5, 20));
		backLeftLeg->getTransform()->setLocalPosition(Vector3(-0.3, -0.5, 0.5));
		backLeftLeg->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
		backLeftLeg->getTransform()->setParent(body->getTransform());
		backLeftLeg->getTransform()->name = "BackLeftLeg";

		backRightLeg = new GameObject(app);
		backRightLeg->setMesh(new Cylinder(0.1, 0.5, 20));
		backRightLeg->getTransform()->setLocalPosition(Vector3(0.3, -0.5, 0.5));
		backRightLeg->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
		backRightLeg->getTransform()->setParent(body->getTransform());
		backRightLeg->getTransform()->name = "BackRightLeg";

		frontLeftLeg = new GameObject(app);
		frontLeftLeg->setMesh(new Cylinder(0.1, 0.5, 20));
		frontLeftLeg->getTransform()->setLocalPosition(Vector3(-0.3, 0.5, 0.5));
		frontLeftLeg->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
		frontLeftLeg->getTransform()->setParent(body->getTransform());
		frontLeftLeg->getTransform()->name = "FrontLeftLeg";

		frontRightLeg = new GameObject(app);
		frontRightLeg->setMesh(new Cylinder(0.1, 0.5, 20));
		frontRightLeg->getTransform()->setLocalPosition(Vector3(0.3, 0.5, 0.5));
		frontRightLeg->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
		frontRightLeg->getTransform()->setParent(body->getTransform());
		frontRightLeg->getTransform()->name = "FrontRightLeg";
	}
}