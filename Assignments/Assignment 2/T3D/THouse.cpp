// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// THouse.cpp
//
// Simple THouse mesh with coloured sides
// Faces are GL quads.

#include "THouse.h"

namespace T3D
{
	THouse::THouse()
	{
		float size = 1.0f;
		float roofHeight = 1.0f;

		// Init vertex and index arrays
		initArrays(4 * 7 + 2 * 3 + 4 * 5,	// num vertices
				   2,				// num tris
				   12);				// num quads

		// Set vertices
		int vpos = 0;
		int uvpos = 0;

		//back
		setVertex(vpos++, -size, -size, -size);
		setVertex(vpos++, size, -size, -size);
		setVertex(vpos++, size, size, -size);
		setVertex(vpos++, -size, size, -size);

		setUV(uvpos++, 1, 0.5);
		setUV(uvpos++, 0.8, 0.5);
		setUV(uvpos++, 0.8, 0);
		setUV(uvpos++, 1, 0);

		//front
		setVertex(vpos++, -size, -size, size);
		setVertex(vpos++, size, -size, size);
		setVertex(vpos++, size, size, size);
		setVertex(vpos++, -size, size, size);

		setUV(uvpos++, 0.8, 1);
		setUV(uvpos++, 1, 1);
		setUV(uvpos++, 1, 0.5);
		setUV(uvpos++, 0.8, 0.5);

		//left
		setVertex(vpos++, -size, -size, -size);
		setVertex(vpos++, -size, size, -size);
		setVertex(vpos++, -size, size, size);
		setVertex(vpos++, -size, -size, size);

		setUV(uvpos++, 0.6, 0.5);
		setUV(uvpos++, 0.6, 0);
		setUV(uvpos++, 0.8, 0);
		setUV(uvpos++, 0.8, 0.5);

		//right
		setVertex(vpos++, size, -size, -size);
		setVertex(vpos++, size, size, -size);
		setVertex(vpos++, size, size, size);
		setVertex(vpos++, size, -size, size);

		setUV(uvpos++, 0.8, 1);
		setUV(uvpos++, 0.8, 0.5);
		setUV(uvpos++, 0.6, 0.5);
		setUV(uvpos++, 0.6, 1);

		//bottom
		setVertex(vpos++, -size, -size, -size);
		setVertex(vpos++, -size, -size, size);
		setVertex(vpos++, size, -size, size);
		setVertex(vpos++, size, -size, -size);

		setUV(uvpos++, 0, 0.5);
		setUV(uvpos++, 0, 0);
		setUV(uvpos++, 0.2, 0);
		setUV(uvpos++, 0.2, 0.5);

		//left roof
		setVertex(vpos++, -size, size, size);
		setVertex(vpos++, 0, size + roofHeight, size);
		setVertex(vpos++, 0, size + roofHeight, -size);
		setVertex(vpos++, -size, size, -size);

		setUV(uvpos++, 0.6, 0.5);
		setUV(uvpos++, 0.6, 0);
		setUV(uvpos++, 0.4, 0);
		setUV(uvpos++, 0.4, 0.5);

		//right roof
		setVertex(vpos++, size, size, -size);
		setVertex(vpos++, 0, size + roofHeight, -size);
		setVertex(vpos++, 0, size + roofHeight, size);
		setVertex(vpos++, size, size, size);

		setUV(uvpos++, 0.6, 1);
		setUV(uvpos++, 0.6, 0.5);
		setUV(uvpos++, 0.4, 0.5);
		setUV(uvpos++, 0.4, 1);

		//front tri
		setVertex(vpos++, size, size, size);
		setVertex(vpos++, 0, size + roofHeight, size);
		setVertex(vpos++, -size, size, size);

		setUV(uvpos++, 0.4, 0);
		setUV(uvpos++, 0.2, 0);
		setUV(uvpos++, 0.2, 0.5);

		//back tri
		setVertex(vpos++, -size, size, -size);
		setVertex(vpos++, 0, size + roofHeight, -size);
		setVertex(vpos++, size, size, -size);

		setUV(uvpos++, 0.2, 0.5);
		setUV(uvpos++, 0.4, 0.5);
		setUV(uvpos++, 0.4, 0);

		//front chimney
		setVertex(vpos++, 0.4, size + 0.6, 0.2);
		setVertex(vpos++, 0.8, size + 0.2, 0.2);
		setVertex(vpos++, 0.8, size + roofHeight, 0.2);
		setVertex(vpos++, 0.4, size + roofHeight, 0.2);

		setUV(uvpos++, 0, 1);
		setUV(uvpos++, 0.2, 1);
		setUV(uvpos++, 0.2, 0.5);
		setUV(uvpos++, 0, 0.5);

		//back chimney
		setVertex(vpos++, 0.8, size + 0.2, -0.2);
		setVertex(vpos++, 0.4, size + 0.6, -0.2);
		setVertex(vpos++, 0.4, size + roofHeight, -0.2);
		setVertex(vpos++, 0.8, size + roofHeight, -0.2);

		setUV(uvpos++, 0, 1);
		setUV(uvpos++, 0.2, 1);
		setUV(uvpos++, 0.2, 0.5);
		setUV(uvpos++, 0, 0.5);

		//right chimney
		setVertex(vpos++, 0.8, size + 0.2, -0.2);
		setVertex(vpos++, 0.8, size + roofHeight, -0.2);
		setVertex(vpos++, 0.8, size + roofHeight, 0.2);
		setVertex(vpos++, 0.8, size + 0.2, 0.2);

		setUV(uvpos++, 0.2, 1);
		setUV(uvpos++, 0.2, 0.5);
		setUV(uvpos++, 0, 0.5);
		setUV(uvpos++, 0, 1);

		//left chimney
		setVertex(vpos++, 0.4, size + 0.6, 0.2);
		setVertex(vpos++, 0.4, size + roofHeight, 0.2);
		setVertex(vpos++, 0.4, size + roofHeight, -0.2);
		setVertex(vpos++, 0.4, size + 0.6, -0.2);

		setUV(uvpos++, 0.2, 1);
		setUV(uvpos++, 0.2, 0.5);
		setUV(uvpos++, 0, 0.5);
		setUV(uvpos++, 0, 1);

		//top chimney
		setVertex(vpos++, 0.8, size + roofHeight, -0.2);
		setVertex(vpos++, 0.4, size + roofHeight, -0.2);
		setVertex(vpos++, 0.4, size + roofHeight, 0.2);
		setVertex(vpos++, 0.8, size + roofHeight, 0.2);

		setUV(uvpos++, 0.4, 0.5);
		setUV(uvpos++, 0.2, 0.5);
		setUV(uvpos++, 0.2, 1);
		setUV(uvpos++, 0.4, 1);

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
		//left roof
		setQuadFace(vpos++, 20, 21, 22, 23);
		//right roof
		setQuadFace(vpos++, 24, 25, 26, 27);
		// front chimney
		setQuadFace(vpos++, 34, 35, 36, 37);
		// back chimney
		setQuadFace(vpos++, 38, 39, 40, 41);
		// right chimney
		setQuadFace(vpos++, 42, 43, 44, 45);
		// left chimney
		setQuadFace(vpos++, 46, 47, 48, 49);
		// top chimney
		setQuadFace(vpos++, 50, 51, 52, 53);

		vpos = 0;

		//front tri
		setTriFace(vpos++, 28, 29, 30);
		//back tri
		setTriFace(vpos++, 31, 32, 33);

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
