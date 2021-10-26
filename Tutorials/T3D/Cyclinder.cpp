#include "Cylinder.h"
#include "Math.h"

namespace T3D
{
	Cylinder::Cylinder(float radius, float height, int density)
	{
		// Init vertex and index arrays
		initArrays(
			density * 2,	// num vertices
			0,				// num tris
			density			// num quads
		);

		// Set vertices
		float dTheta = Math::TWO_PI / density;
		for (int i = 0; i < density; i++) {
			float theta = i * dTheta;
			float x = radius * cos(theta);
			float z = radius * sin(theta);

			// top vertex
			setVertex(i, x, height, z);

			// bottom vertex
			setVertex(density + i, x, -height, z);
		}


		// Build quads
		for (int i = 0; i < density; i++) {
			setQuadFace(i,   // face id
				i,         // current top vertex
				(i + 1) % density,   // next top vertex (wrapping)
				density + (i + 1) % density, // next bottom vertex (wrapping) 
				density + i        // current bottom vertex
			);
		}

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();
	}
}
