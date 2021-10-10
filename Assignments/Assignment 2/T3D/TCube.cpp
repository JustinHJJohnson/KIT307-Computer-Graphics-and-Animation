// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// TCube.cpp
//
// Simple TCube mesh with coloured sides
// Faces are GL quads.

#include "TCube.h"

namespace T3D
{
	TCube::TCube(float size)
	{
		// Init vertex and index arrays
		initArrays(4 * 6,	// num vertices
			0,		// num tris
			6);		// num quads

 // Set vertices

		int vpos = 0;
		int uvpos = 0;
		//front
		setVertex(vpos++, -size, -size, -size);
		setVertex(vpos++, size, -size, -size);
		setVertex(vpos++, size, size, -size);
		setVertex(vpos++, -size, size, -size);

		setUV(uvpos++, 0.48, 0.02);
		setUV(uvpos++, 0.02, 0.02);
		setUV(uvpos++, 0.02, 0.48);
		setUV(uvpos++, 0.48, 0.48);

		//back
		setVertex(vpos++, -size, -size, size);
		setVertex(vpos++, size, -size, size);
		setVertex(vpos++, size, size, size);
		setVertex(vpos++, -size, size, size);

		setUV(uvpos++, 0.52, 0.98);
		setUV(uvpos++, 0.98, 0.98);
		setUV(uvpos++, 0.98, 0.52);
		setUV(uvpos++, 0.52, 0.52);

		//left
		setVertex(vpos++, -size, -size, -size);
		setVertex(vpos++, -size, size, -size);
		setVertex(vpos++, -size, size, size);
		setVertex(vpos++, -size, -size, size);

		setUV(uvpos++, 0.02, 0.98);
		setUV(uvpos++, 0.02, 0.52);
		setUV(uvpos++, 0.48, 0.52);
		setUV(uvpos++, 0.48, 0.98);

		//right
		setVertex(vpos++, size, -size, -size);
		setVertex(vpos++, size, size, -size);
		setVertex(vpos++, size, size, size);
		setVertex(vpos++, size, -size, size);

		setUV(uvpos++, 0.48, 0.98);
		setUV(uvpos++, 0.48, 0.52);
		setUV(uvpos++, 0.02, 0.52);
		setUV(uvpos++, 0.02, 0.98);

		//bottom
		setVertex(vpos++, -size, -size, -size);
		setVertex(vpos++, -size, -size, size);
		setVertex(vpos++, size, -size, size);
		setVertex(vpos++, size, -size, -size);

		setUV(uvpos++, 0.52, 0.48);
		setUV(uvpos++, 0.52, 0.04);
		setUV(uvpos++, 0.98, 0.04);
		setUV(uvpos++, 0.98, 0.48);

		//top
		setVertex(vpos++, -size, size, -size);
		setVertex(vpos++, -size, size, size);
		setVertex(vpos++, size, size, size);
		setVertex(vpos++, size, size, -size);

		setUV(uvpos++, 0.52, 0.48);
		setUV(uvpos++, 0.52, 0.04);
		setUV(uvpos++, 0.98, 0.04);
		setUV(uvpos++, 0.98, 0.48);

		// Build quads
		vpos = 0;
		//front
		setQuadFace(vpos++, 3, 2, 1, 0);
		//back
		setQuadFace(vpos++, 4, 5, 6, 7);
		//left
		setQuadFace(vpos++, 11, 10, 9, 8);
		//right
		setQuadFace(vpos++, 12, 13, 14, 15);
		//bottom
		setQuadFace(vpos++, 19, 18, 17, 16);
		//top
		setQuadFace(vpos++, 20, 21, 22, 23);

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();

		// Setup other arrays		
		vpos = 0;
		//front
		for (int i = 0; i < 4; i++) {
			colors[vpos++] = 1; colors[vpos++] = 0; colors[vpos++] = 0; colors[vpos++] = 1;
		}
		//back
		for (int i = 0; i < 4; i++) {
			colors[vpos++] = 1; colors[vpos++] = 0; colors[vpos++] = 0; colors[vpos++] = 1;
		}
		//left
		for (int i = 0; i < 4; i++) {
			colors[vpos++] = 0; colors[vpos++] = 1; colors[vpos++] = 0; colors[vpos++] = 1;
		}
		//right
		for (int i = 0; i < 4; i++) {
			colors[vpos++] = 0; colors[vpos++] = 1; colors[vpos++] = 0; colors[vpos++] = 1;
		}
		//bottom
		for (int i = 0; i < 4; i++) {
			colors[vpos++] = 0; colors[vpos++] = 0; colors[vpos++] = 1; colors[vpos++] = 1;
		}
		//top
		for (int i = 0; i < 4; i++) {
			colors[vpos++] = 0; colors[vpos++] = 0; colors[vpos++] = 1; colors[vpos++] = 1;
		}

		//uvs
		/*vpos = 0;
		for (int f = 0; f < 6; f++) {
			uvs[vpos++] = 0; uvs[vpos++] = 0;
			uvs[vpos++] = 0; uvs[vpos++] = 1;
			uvs[vpos++] = 1; uvs[vpos++] = 1;
			uvs[vpos++] = 1; uvs[vpos++] = 0;
		}*/
	}
}
