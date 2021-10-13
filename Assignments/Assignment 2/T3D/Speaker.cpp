#pragma once
#include "Speaker.h"
#include "T3DApplication.h"
#include "GameObject.h"
#include "Transform.h"
#include "SweepPath.h"
#include "Sweep.h"

namespace T3D
{
	Speaker::Speaker(T3DApplication* app) :GameObject(app)
	{
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

		speaker = new GameObject(app);
		speaker->setMesh(new Sweep(shadeProfile, shadesp, false));
		speaker->getTransform()->setParent(getTransform()); // attaching this piece to the Lamp object's transform
		speaker->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		speaker->getTransform()->name = "Speaker";
	}
}