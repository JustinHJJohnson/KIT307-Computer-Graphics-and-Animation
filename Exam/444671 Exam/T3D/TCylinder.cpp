#include "TCylinder.h"
#include "Math.h"

namespace T3D
{
	TCylinder::TCylinder(float radius, float height, int density)
	{
		int startTopCap = density * 2 + 2;
		int startBottomCap = density * 3 + 2;
		int topCapMiddle = density * 4 + 2;
		int bottomCapMiddle = density * 4 + 3;

		// Init vertex and index arrays
		initArrays(
			density * 4 + 4,	// num vertices
			density * 2,		// num tris
			density				// num quads
		);

		// Set vertices
		float dTheta = Math::TWO_PI / density;
		for (int i = 0; i <= density; i++) {
			float theta = i * dTheta;
			float x = radius * cos(theta);
			float z = radius * sin(theta);

			// top vertices
			setVertex(i, x, height, z);
			setUV(i, float(density - i) / density, 0);

			// bottom vertices
			setVertex((density + 1) + i, x, -height, z);
			setUV(density + 1 + i, float(density - i) / density, 0.6);
		}

		for (int i = 0; i < density; i++) {
			float theta = i * dTheta;
			float x = radius * cos(theta);
			float z = radius * sin(theta);

			// top vertices
			setVertex(startTopCap + i, x, height, z);

			// bottom vertices
			setVertex(startBottomCap + i, x, -height, z);
		}

		setVertex(topCapMiddle, 0, height, 0);
		setVertex(bottomCapMiddle, 0, -height, 0);

		// Build quads
		for (int i = 0; i < density; i++) {
			setQuadFace(
				i,								// face id
				i,								// current top vertex
				(i + 1),						// next top vertex (wrapping)
				(density + 1) + (i + 1),		// next bottom vertex (wrapping) 
				(density + 1) + i				// current bottom vertex
			);
		}

		// Build the caps
		for (int i = 0; i < density; i++) {
			// Top caps
			setTriFace(
				i,
				topCapMiddle,
				startTopCap + (i + 1) % density,
				startTopCap + i
			);

			// Bottom caps
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
