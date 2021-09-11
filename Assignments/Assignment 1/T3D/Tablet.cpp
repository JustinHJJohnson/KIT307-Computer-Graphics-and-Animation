#include "Tablet.h"
#include "Math.h"

namespace T3D
{
	Tablet::Tablet(Vector3 size, float bezel_width, float corner_radius, float screen_depression, int density)
	{
		// Init vertex and index arrays
		initArrays(density * 2 + 10 * 4 + 1,	// num vertices
				   density * 2 + 2,		// num tris
				   4 * 4 + 2);	// num quads

		// Set vertices
		int pos = 0;

		//back of top bezel
		setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), -(size.z / 2));
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), -(size.z / 2));
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), -(size.z / 2));
		setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), -(size.z / 2));
		//top of top bezel
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), -(size.z / 2) + bezel_width);
		//front of top bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2) - screen_depression, -(size.z / 2) + bezel_width);
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2) - screen_depression, -(size.z / 2) + bezel_width);
		//bottom of top bezel
		setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), -(size.z / 2) + bezel_width);
		
		//back of bottom bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), size.z / 2);
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), size.z / 2);
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), size.z / 2);
		setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), size.z / 2);
		//top of bottom bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), size.z / 2 - bezel_width);
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), size.z / 2 - bezel_width);
		//front of bottom bezel
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2) - screen_depression, size.z / 2 - bezel_width);
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2) - screen_depression, size.z / 2 - bezel_width);
		//bottom of bottom bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), (size.z / 2) - bezel_width);
		setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), (size.z / 2) - bezel_width);

		//back of left bezel
		setVertex(pos++, -(size.x / 2), -(size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, -(size.x / 2), (size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, -(size.x / 2), (size.y / 2), (size.z / 2) - bezel_width);
		setVertex(pos++, -(size.x / 2), -(size.y / 2), (size.z / 2) - bezel_width);
		//top of left bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), (size.z / 2) - bezel_width);
		//front of left bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2) - screen_depression, (size.z / 2) - bezel_width);
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2) - screen_depression, -(size.z / 2) + bezel_width);
		//bottom of laft bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), (size.z / 2) - bezel_width);

		//back of right bezel
		setVertex(pos++, size.x / 2, -(size.y / 2), (size.z / 2) - bezel_width);
		printf("%d", pos);
		setVertex(pos++, size.x / 2, (size.y / 2), (size.z / 2) - bezel_width);
		setVertex(pos++, size.x / 2, (size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, size.x / 2, -(size.y / 2), -(size.z / 2) + bezel_width);
		//top of right bezel
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), (size.z / 2) - bezel_width);
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), -(size.z / 2) + bezel_width);
		//front of right bezel
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2) - screen_depression, -(size.z / 2) + bezel_width);
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2) - screen_depression, (size.z / 2) - bezel_width);
		//bottom of laft bezel
		setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), (size.z / 2) - bezel_width);
		setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), -(size.z / 2) + bezel_width);

		//top right corner
		setVertex(pos++, size.x / 2 - corner_radius, size.y / 2, -(size.z / 2) + corner_radius);

		float circleCentreX = (size.x / 2) - corner_radius;
		float circleCentreZ = -(size.z / 2) + corner_radius;
		// Set vertices
		float dTheta = (Math::PI/2) / density;
		for (int i = 0; i < density; i++) {
			float theta = i * dTheta;
			//float x = (size.x / 2 - corner_radius) * cos(theta);
			//float z = (-(size.z / 2) + corner_radius) * sin(theta);
			float x = circleCentreX + corner_radius * cos(theta);
			float z = circleCentreZ - corner_radius * sin(theta);

			// top vertices
			setVertex(pos + i, x, size.y / 2, z);
			//setVertex(startTopCap + i, x, height, z);

			// bottom vertices
			setVertex(density + pos + i, x, -(size.y / 2), z);
			//setVertex(startBottomCap + i, x, -height, z);
		}


		// Build quads
		pos = 0;
		
		for (int i = 0; i < 4; i++)
		{
			//back
			setQuadFace(pos++, 3 + i * 10, 2 + i * 10, 1 + i * 10, 0 + i * 10);
			//top
			setQuadFace(pos++, 4 + i * 10, 1 + i * 10, 2 + i * 10, 5 + i * 10);
			//front
			setQuadFace(pos++, 7 + i * 10, 4 + i * 10, 5 + i * 10, 6 + i * 10);
			//bottom
			setQuadFace(pos++, 3 + i * 10, 0 + i * 10, 8 + i * 10, 9 + i * 10);
		}

		//top of the screen
		setQuadFace(pos++, 7, 6, 17, 16);
		
		//bottom of the screen
		setQuadFace(pos++, 19, 18, 9, 8);

		int startCircle = 10 * 4 + 1;

		int topRightCornerCentre = 4;

		// top right corner
		for (int i = 0; i < density; i++) {
			setTriFace(
				i,
				topRightCornerCentre,
				startCircle + i,
				startCircle + (i + 1) % density
			);
		}

		// top right corner
		for (int i = 0; i < density; i++) {
			setTriFace(
				i + density,
				topRightCornerCentre,
				startCircle + i,
				startCircle + (i + 1) % density
			);
		}

		setTriFace(
			density,
			topRightCornerCentre,
			//startCircle,
			startCircle + density - 1,
			1
		);

		setTriFace(
			density + 1,
			topRightCornerCentre,
			32,
			startCircle
		);

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();
	}
}
