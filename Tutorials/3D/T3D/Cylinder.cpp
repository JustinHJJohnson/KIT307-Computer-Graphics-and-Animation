#include "Cyclinder.h"
#include "Math.h"

namespace T3D
{
	Cylinder::Cylinder(float radius, float height, int density)
	{
		int startTopCap = density * 2;
		int startBottomCap = density * 3;
		int topCapMiddle = density * 4;
		int bottomCapMiddle = density * 4 + 1;
		
		// Init vertex and index arrays
		initArrays(
			density * 4 + 2,	// num vertices
			density * 2,		// num tris
			density				// num quads
		);

		// Set vertices
		float dTheta = Math::TWO_PI / density;
		for (int i = 0; i < density; i++) {
			float theta = i * dTheta;
			float x = radius * cos(theta);
			float z = radius * sin(theta);

			// top vertices
			setVertex(i, x, height, z);
			setVertex(startTopCap + i, x, height, z);

			// bottom vertices
			setVertex(density + i, x, -height, z);
			setVertex(startBottomCap + i, x, -height, z);
		}

		setVertex(topCapMiddle, 0, height, 0);
		setVertex(bottomCapMiddle, 0, -height, 0);

		// Build quads
		for (int i = 0; i < density; i++) {
			setQuadFace(
				i,								// face id
				i,								// current top vertex
				(i + 1) % density,				// next top vertex (wrapping)
				density + (i + 1) % density,	// next bottom vertex (wrapping) 
				density + i						// current bottom vertex
			);
		}

		// Build top cap
		for (int i = 0; i < density; i++) {
			setTriFace(
				i,
				topCapMiddle,
				startTopCap + (i + 1) % density,
				startTopCap + i
			);
		}

		// Build bottom cap
		for (int i = 0; i < density; i++) {
			setTriFace(
				i + density,
				bottomCapMiddle,
				startBottomCap + i,
				startBottomCap + (i + 1) % density
			);
		}

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();
	}
}
