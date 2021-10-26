#pragma once
#include "Mesh.h"

namespace T3D {
	class TCylinder :
		public Mesh
	{
	public:
		//! \brief Create Cube with volume = `size^3`.
		TCylinder(float radius, float height, int density);
	};
}

