#pragma once
#include "Mesh.h"
#include "Math.h"

namespace T3D {
	class Tablet :
		public Mesh
	{
	public:
		//! \brief Create Tablet.
		Tablet(Vector3 size, float bezel_width, float corner_radius, float screen_depression, int density);
	};
}

