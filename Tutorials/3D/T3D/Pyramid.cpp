#include "Pyramid.h"

namespace T3D
{
	Pyramid::Pyramid(float size)
	{
		// Init vertex and index arrays
		initArrays(
			4+3*4,	// num vertices
			4,		// num tris
			1		// num quads
		);

		// Set vertices

		int pos = 0;
		//front
		setVertex(pos++, -size, 2*-size, -size);
		setVertex(pos++, size, 2*-size, -size);
		setVertex(pos++, 0, 0, 0);
		//back
		setVertex(pos++, -size, 2*-size, size);
		setVertex(pos++, size, 2*-size, size);
		setVertex(pos++, 0, 0, 0);
		//left
		setVertex(pos++, -size, 2*-size, -size);
		setVertex(pos++, -size, 2*-size, size);
		setVertex(pos++, 0, 0, 0);
		//right
		setVertex(pos++, size, 2*-size, -size);
		setVertex(pos++, size, 2*-size, size);
		setVertex(pos++, 0, 0, 0);
		//bottom
		setVertex(pos++, -size, 2*-size, -size);
		setVertex(pos++, -size, 2*-size, size);
		setVertex(pos++, size, 2*-size, size);
		setVertex(pos++, size, 2*-size, -size);

		// Build quads
		pos = 0;
		//front
		setTriFace(pos++, 2, 1, 0);
		//back
		setTriFace(pos++, 3, 4, 5);
		//left
		setTriFace(pos++, 6, 7, 8);
		//right
		setTriFace(pos++, 11, 10, 9);
		//bottom
		setQuadFace(0, 15, 14, 13, 12);

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();
	}
}