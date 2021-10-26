#pragma once
#include "Mesh.h"

namespace T3D {
	class Pyramid :
		public Mesh
	{
	public:
		//! \brief Create Cube with volume = `size^3`.
		Pyramid(float size);
	};
}

