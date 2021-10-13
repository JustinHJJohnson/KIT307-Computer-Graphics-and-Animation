#pragma once
#include "Bottle.h"
#include "T3DApplication.h"
#include "GameObject.h"
#include "Transform.h"
#include "SweepPath.h"
#include "Sweep.h"

namespace T3D
{
    Bottle::Bottle(T3DApplication* app) :GameObject(app)
    {
        //create a profile with 8 points
        std::vector<Vector3> bottleProfile;                        //create an umbrella
        bottleProfile.push_back(Vector3(0.0f, -0.08f, 0.0f));
        bottleProfile.push_back(Vector3(0.05f, -0.07f, 0.0f));
        bottleProfile.push_back(Vector3(0.07f, -0.05f, 0.0f));
        bottleProfile.push_back(Vector3(0.08f, 0.0f, 0.0f));
        bottleProfile.push_back(Vector3(0.07f, 0.05f, 0.0f));
        bottleProfile.push_back(Vector3(0.05f, 0.07f, 0.0f));
        bottleProfile.push_back(Vector3(0.0f, 0.08f, 0.0f));
        bottleProfile.push_back(Vector3(-0.05f, 0.07f, 0.0f));
        bottleProfile.push_back(Vector3(-0.07f, 0.05f, 0.0f));
        bottleProfile.push_back(Vector3(-0.08f, 0.0f, 0.0f));
        bottleProfile.push_back(Vector3(-0.07f, -0.05f, 0.0f));
        bottleProfile.push_back(Vector3(-0.05f, -0.07f, 0.0f));
        //bottleProfile.push_back(Vector3(0.0f, -0.08f, 0.0f));    //loop back, might not need.

        // create sweeppath and transform object for sweeppath
        SweepPath bottlePath;
        Transform t;

        //create sweeppaths transforms, times 8
        //start at the tip
        //top
        t.setLocalPosition(Vector3(0.443, 0, 0));
        t.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
        t.setLocalScale(Vector3(0, 0, 1.0));
        bottlePath.addTransform(t);
        //stem
        t.setLocalPosition(Vector3(0.34, 0, 0));
        t.setLocalScale(Vector3(0.010, 0.010, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.345, 0, 0));
        t.setLocalScale(Vector3(0.015, 0.015, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.35, 0, 0));
        t.setLocalScale(Vector3(0.020, 0.020, 1.0));
        bottlePath.addTransform(t);
        //inner brella
        t.setLocalPosition(Vector3(0.421, 0, 0));
        t.setLocalScale(Vector3(0.020, 0.020, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.42, 0, 0));
        t.setLocalScale(Vector3(0.40, 0.40, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.415, 0, 0));
        t.setLocalScale(Vector3(0.90, 0.90, 1.0));
        bottlePath.addTransform(t);
        //outer brella
        t.setLocalPosition(Vector3(0.41, 0, 0));
        t.setLocalScale(Vector3(1.0, 1.0, 1.0));
        bottlePath.addTransform(t);
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.42, 0, 0));
        t.setLocalScale(Vector3(0.95, 0.95, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.428, 0, 0));
        t.setLocalScale(Vector3(0.80, 0.80, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.431, 0, 0));
        t.setLocalScale(Vector3(0.65, 0.65, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.435, 0, 0));
        t.setLocalScale(Vector3(0.35, 0.35, 1.0));
        bottlePath.addTransform(t);
        //top stem
        t.setLocalPosition(Vector3(0.436, 0, 0));
        t.setLocalScale(Vector3(0.020, 0.020, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.439, 0, 0));
        t.setLocalScale(Vector3(0.020, 0.020, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.44, 0, 0));
        t.setLocalScale(Vector3(0.015, 0.015, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.442, 0, 0));
        t.setLocalScale(Vector3(0.01, 0.01, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0.443, 0, 0));
        t.setLocalScale(Vector3(0, 0, 1.0));
        bottlePath.addTransform(t);

        //create the object based on the sweeppath and sweepprofile
        bottle = new GameObject(app);
        bottle->setMesh(new Sweep(bottleProfile, bottlePath, false));
        bottle->getTransform()->setLocalPosition(Vector3(0, 0.1, 0));
        bottle->getTransform()->setParent(getTransform());
        bottle->getTransform()->name = "Task1";
    }
}