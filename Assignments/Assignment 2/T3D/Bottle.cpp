#pragma once
#include "Bottle.h"
#include "T3DApplication.h"
#include "GameObject.h"
#include "Transform.h"
#include "SweepPath.h"
#include "Sweep.h"

namespace T3D
{
    Bottle::Bottle(T3DApplication* app, int density) :GameObject(app)
    {
        //create a profile with density points
        std::vector<Vector3> bottleProfile; //create the bottle profile
        float radius = 0.08f;
        float dTheta = Math::TWO_PI / density;

        // Create profile based on input density
        for (int i = 0; i < density; i++)
        {
            float theta = i * dTheta;
            float x = radius * cos(theta);
            float y = radius * sin(theta);
            
            bottleProfile.push_back(Vector3(x, y, 0.0f));
        }

        // Create SweepPath and add transforms
        SweepPath bottlePath;
        Transform t;

        t.setLocalPosition(Vector3(0, 0, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(1.0, 1.0, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.3, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(1.0, 1.0, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.35, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(0.7, 0.7, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.4, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(0.55, 0.55, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.45, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(0.4, 0.4, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.55, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(0.3, 0.3, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.56, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(0.31, 0.31, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0.57, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(0.33, 0.33, 1.0));
        bottlePath.addTransform(t);

        t.setLocalPosition(Vector3(0, 0, 0));
        t.setLocalRotation(Quaternion(Vector3(-Math::PI / 2, 0, 0)));
        t.setLocalScale(Vector3(0.001, 0.001, 0.001));
        bottlePath.addTransform(t);

        // Actually create the object
        bottle = new GameObject(app);
        bottle->setMesh(new Sweep(bottleProfile, bottlePath, false));
        bottle->getTransform()->setLocalPosition(Vector3(0, 0, 0));
        bottle->getTransform()->setParent(getTransform());
        bottle->getTransform()->name = "Bottle";
    }
}