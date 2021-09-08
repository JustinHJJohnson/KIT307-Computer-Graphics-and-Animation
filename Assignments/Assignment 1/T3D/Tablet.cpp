#include "Tablet.h"
#include "Math.h"

namespace T3D
{
	Tablet::Tablet(Vector3 size, float bezel_width, float corner_radius, float screen_depression, int density)
	{
		// Init vertex and index arrays
		initArrays(10 * 4,	// num vertices
				   0,		// num tris
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

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();
	}
}
