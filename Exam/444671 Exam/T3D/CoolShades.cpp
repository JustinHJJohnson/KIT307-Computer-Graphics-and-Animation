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

#include "CoolShades.h"

namespace T3D
{
	CoolShades::CoolShades()
	{
		// Init vertex and index arrays
		initArrays(
			4 * 15,		// num vertices
			0,			// num tris
			6 * 2 + 3	// num quads
		);				

		// Set vertices
		int vpos = 0;

		// inside wall left arm 
		setVertex(vpos++, 0, 0, 0);
		setVertex(vpos++, 0.7, 0, 0);
		setVertex(vpos++, 0.7, 0.1, 0);
		setVertex(vpos++, 0, 0.1, 0);
		// outside wall left arm
		setVertex(vpos++, 0.7, 0, 0.1);
		setVertex(vpos++, 0.7, 0.1, 0.1);
		setVertex(vpos++, 0, 0.1, 0.1);
		setVertex(vpos++, 0, 0, 0.1);
		// top wall left arm
		setVertex(vpos++, 0.7, 0.1, 0);
		setVertex(vpos++, 0.7, 0.1, 0.1);
		setVertex(vpos++, 0, 0.1, 0.1);
		setVertex(vpos++, 0, 0.1, 0);
		// bottom wall left arm
		setVertex(vpos++, 0.7, 0, 0);
		setVertex(vpos++, 0.7, 0, 0.1);
		setVertex(vpos++, 0, 0, 0.1);
		setVertex(vpos++, 0, 0, 0);
		// back left arm
		setVertex(vpos++, 0, 0, 0);
		setVertex(vpos++, 0, 0.1, 0);
		setVertex(vpos++, 0, 0.1, 0.1);
		setVertex(vpos++, 0, 0, 0.1);
		// front left arm
		setVertex(vpos++, 0.7, 0, 0);
		setVertex(vpos++, 0.7, 0.1, 0);
		setVertex(vpos++, 0.7, 0.1, 0.1);
		setVertex(vpos++, 0.7, 0, 0.1);

		float shadesWidth = 0.7;
		float shadesLength = 0.7;
		
		// inside wall right arm 
		setVertex(vpos++, 0, 0, shadesWidth + 0);
		setVertex(vpos++, shadesLength, 0, shadesWidth + 0);
		setVertex(vpos++, shadesLength, 0.1, shadesWidth + 0);
		setVertex(vpos++, 0, 0.1, shadesWidth + 0);
		// outside wall right arm
		setVertex(vpos++, shadesLength, 0, shadesWidth + 0.1);
		setVertex(vpos++, shadesLength, 0.1, shadesWidth + 0.1);
		setVertex(vpos++, 0, 0.1, shadesWidth + 0.1);
		setVertex(vpos++, 0, 0, shadesWidth + 0.1);
		// top wall right arm
		setVertex(vpos++, shadesLength, 0.1, shadesWidth + 0);
		setVertex(vpos++, shadesLength, 0.1, shadesWidth + 0.1);
		setVertex(vpos++, 0, 0.1, shadesWidth + 0.1);
		setVertex(vpos++, 0, 0.1, shadesWidth + 0);
		// bottom wall right arm
		setVertex(vpos++, shadesLength, 0, shadesWidth + 0);
		setVertex(vpos++, shadesLength, 0, shadesWidth + 0.1);
		setVertex(vpos++, 0, 0, shadesWidth + 0.1);
		setVertex(vpos++, 0, 0, shadesWidth + 0);
		// back right arm
		setVertex(vpos++, 0, 0, shadesWidth + 0);
		setVertex(vpos++, 0, 0.1, shadesWidth + 0);
		setVertex(vpos++, 0, 0.1, shadesWidth + 0.1);
		setVertex(vpos++, 0, 0, shadesWidth + 0.1);
		// front right arm
		setVertex(vpos++, shadesLength, 0, shadesWidth + 0);
		setVertex(vpos++, shadesLength, 0.1, shadesWidth + 0);
		setVertex(vpos++, shadesLength, 0.1, shadesWidth + 0.1);
		setVertex(vpos++, shadesLength, 0, shadesWidth + 0.1);

		
		// no back for these lenses as they're only going to be viewed from the front
		// left lense
		setVertex(vpos++, shadesLength, -0.08, 0.1);
		setVertex(vpos++, shadesLength, 0.18, 0.1 );
		setVertex(vpos++, shadesLength, 0.18, (0.1 + shadesWidth / 2) - 0.1);
		setVertex(vpos++, shadesLength, -0.08, (0.1 + shadesWidth / 2) - 0.1);
		// right lense
		setVertex(vpos++, shadesLength, -0.08, 0.1 + shadesWidth / 2);
		setVertex(vpos++, shadesLength, 0.18, 0.1 + shadesWidth / 2);
		setVertex(vpos++, shadesLength, 0.18, shadesWidth);
		setVertex(vpos++, shadesLength, -0.08, shadesWidth);
		// nose
		setVertex(vpos++, shadesLength, 0.16, (0.1 + shadesWidth / 2) - 0.1);
		setVertex(vpos++, shadesLength, 0.18, (0.1 + shadesWidth / 2) - 0.1);
		setVertex(vpos++, shadesLength, 0.18, 0.1 + shadesWidth / 2);
		setVertex(vpos++, shadesLength, 0.16, 0.1 + shadesWidth / 2);

		// Build quads
		vpos = 0;
		// inside wall left arm
		setQuadFace(vpos++, 3, 2, 1, 0);
		// outside wall left arm
		setQuadFace(vpos++, 4, 5, 6, 7);
		// left wall left arm
		setQuadFace(vpos++, 11, 10, 9, 8);
		// right wall left arm
		setQuadFace(vpos++, 12, 13, 14, 15);
		// back left arm
		setQuadFace(vpos++, 19, 18, 17, 16);
		// front left arm
		setQuadFace(vpos++, 20, 21, 22, 23);

		// outside wall right arm
		setQuadFace(vpos++, 27, 26, 25, 24);
		// inside wall right arm
		setQuadFace(vpos++, 28, 29, 30, 31);
		// left wall right arm
		setQuadFace(vpos++, 35, 34, 33, 32);
		// right wall right arm
		setQuadFace(vpos++, 36, 37, 38, 39);
		// back left arm
		setQuadFace(vpos++, 43, 42, 41, 40);
		// front left arm
		setQuadFace(vpos++, 44, 45, 46, 47);

		// left lense
		setQuadFace(vpos++, 48, 49, 50, 51);
		// right lense
		setQuadFace(vpos++, 52, 53, 54, 55);
		// nose
		setQuadFace(vpos++, 56, 57, 58, 59);
		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();
	}
}
