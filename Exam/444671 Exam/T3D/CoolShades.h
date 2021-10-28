// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// cube.h
//
// Simple cube mesh with coloured sides

#pragma once
#include "Mesh.h"

namespace T3D
{
	//! \brief A simple parametric Cube Mesh.
	class CoolShades :
		public Mesh
	{
	public:
		//! \brief Create Cube with volume = `size^3`.
		CoolShades();

		//! \brief Destroy Cube.
		/*! \note Mesh superclass deletes arrays if they have been created, no need to do anything here
		*/
		virtual ~CoolShades(void) = default;
	};
}

