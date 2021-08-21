#pragma once
#include "Mesh.h"

namespace T3D {
	class Cylinder :
		public Mesh
	{
	public:
		//! \brief Create Cube with volume = `size^3`.
		Cylinder(float radius, float height, int density);
	};
}

