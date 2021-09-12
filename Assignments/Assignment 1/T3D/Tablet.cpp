#include "Tablet.h"
#include "Math.h"

namespace T3D
{
	Tablet::Tablet(Vector3 size, float bezel_width, float corner_radius, float screen_depression, int density)
	{
		// Init vertex and index arrays
		initArrays(
			(density + 1) * 8 + 10 * 4,	// Num vertices
			(density * 2) * 4,			// Num tris
			(density * 4) + (4 * 4 + 2)	// Num quads
		);

		// Set vertices
		int pos = 0;

		// Outward facing side of top bezel
		/*0*/setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), -(size.z / 2));
		/*1*/setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), -(size.z / 2));
		/*2*/setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), -(size.z / 2));
		/*3*/setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), -(size.z / 2));
		// Top of top bezel
		/*4*/setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), -(size.z / 2) + bezel_width);
		/*5*/setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), -(size.z / 2) + bezel_width);
		// Inward facing side of top bezel
		/*6*/setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2) - screen_depression, -(size.z / 2) + bezel_width);
		/*7*/setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2) - screen_depression, -(size.z / 2) + bezel_width);
		// Bottom of top bezel
		/*8*/setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), -(size.z / 2) + bezel_width);
		/*9*/setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), -(size.z / 2) + bezel_width);
		
		// Outward facing side of bottom bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), size.z / 2);
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), size.z / 2);
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), size.z / 2);
		setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), size.z / 2);
		// Top of bottom bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), size.z / 2 - bezel_width);
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), size.z / 2 - bezel_width);
		// Inward facing side of bottom bezel
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2) - screen_depression, size.z / 2 - bezel_width);
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2) - screen_depression, size.z / 2 - bezel_width);
		// Bottom of bottom bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), (size.z / 2) - bezel_width);
		setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), (size.z / 2) - bezel_width);

		// Outward facing side of left bezel
		setVertex(pos++, -(size.x / 2), -(size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, -(size.x / 2), (size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, -(size.x / 2), (size.y / 2), (size.z / 2) - bezel_width);
		setVertex(pos++, -(size.x / 2), -(size.y / 2), (size.z / 2) - bezel_width);
		// Top of left bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2), (size.z / 2) - bezel_width);
		// Inward facing side of left bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2) - screen_depression, (size.z / 2) - bezel_width);
		setVertex(pos++, -(size.x / 2) + bezel_width, (size.y / 2) - screen_depression, -(size.z / 2) + bezel_width);
		// Bottom of laft bezel
		setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, -(size.x / 2) + bezel_width, -(size.y / 2), (size.z / 2) - bezel_width);

		// Outward facing side of right bezel
		setVertex(pos++, size.x / 2, -(size.y / 2), (size.z / 2) - bezel_width);
		setVertex(pos++, size.x / 2, (size.y / 2), (size.z / 2) - bezel_width);
		setVertex(pos++, size.x / 2, (size.y / 2), -(size.z / 2) + bezel_width);
		setVertex(pos++, size.x / 2, -(size.y / 2), -(size.z / 2) + bezel_width);
		// Top of right bezel
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), (size.z / 2) - bezel_width);
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2), -(size.z / 2) + bezel_width);
		// Inward facing side of right bezel
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2) - screen_depression, -(size.z / 2) + bezel_width);
		setVertex(pos++, (size.x / 2) - bezel_width, (size.y / 2) - screen_depression, (size.z / 2) - bezel_width);
		// Bottom of laft bezel
		setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), (size.z / 2) - bezel_width);
		setVertex(pos++, (size.x / 2) - bezel_width, -(size.y / 2), -(size.z / 2) + bezel_width);

		float topRightCircleCentreX = (size.x / 2) - corner_radius;
		float topRightCircleCentreZ = -(size.z / 2) + corner_radius;
		float bottomRightCircleCentreX = (size.x / 2) - corner_radius;
		float bottomRightCircleCentreZ = (size.z / 2) - corner_radius;
		float bottomLeftCircleCentreX = -(size.x / 2) + corner_radius;
		float bottomLeftCircleCentreZ = (size.z / 2) - corner_radius;
		float topLeftCircleCentreX = -(size.x / 2) + corner_radius;
		float topLeftCircleCentreZ = -(size.z / 2) + corner_radius;

		// Set corner vertices
		float dTheta = (Math::PI/2) / (density + 1);
		for (int i = 0; i <= density; i++)
		{
			float theta = i * dTheta;
			float x1 = topRightCircleCentreX + corner_radius * cos(theta);
			float z1 = topRightCircleCentreZ - corner_radius * sin(theta);
			float x2 = bottomRightCircleCentreX + corner_radius * cos(theta);
			float z2 = bottomRightCircleCentreZ + corner_radius * sin(theta);
			float x3 = bottomLeftCircleCentreX - corner_radius * cos(theta);
			float z3 = bottomLeftCircleCentreZ + corner_radius * sin(theta);
			float x4 = topLeftCircleCentreX - corner_radius * cos(theta);
			float z4 = topLeftCircleCentreZ - corner_radius * sin(theta);

			// Top right vertices
			setVertex(pos, x1, size.y / 2, z1);
			setVertex(pos + (density + 1), x1, -(size.y / 2), z1);

			// Bottom right vertices
			setVertex(pos + (density + 1) * 2, x2, size.y / 2, z2);
			setVertex(pos + (density + 1) * 3, x2, -(size.y / 2), z2);

			// Bottom left vertices
			setVertex(pos + (density + 1) * 4, x3, size.y / 2, z3);
			setVertex(pos + (density + 1) * 5, x3, -(size.y / 2), z3);

			// Top left vertices
			setVertex(pos + (density + 1) * 6, x4, size.y / 2, z4);
			setVertex(pos + (density + 1) * 7, x4, -(size.y / 2), z4);

			pos++;
		}

		// Build quads
		pos = 0;

		int topRightStartCircleTop = 10 * 4 ;
		int topRightStartCircleBottom = 10 * 4 + (density + 1);
		int bottomRightStartCircleTop = 10 * 4 + (density + 1) * 2;
		int bottomRightStartCircleBottom = 10 * 4 + (density + 1) * 3;
		int bottomLeftStartCircleTop = 10 * 4 + (density + 1) * 4;
		int bottomLeftStartCircleBottom = 10 * 4 + (density + 1) * 5;
		int topLeftStartCircleTop = 10 * 4 + (density + 1) * 6;
		int topLeftStartCircleBottom = 10 * 4 + (density + 1) * 7;
		
		// 
		int topRightCornerCentreTop = 4;
		int topRightCornerCentreBottom = 8;
		int bottomRightCornerCentreTop = 34;
		int bottomRightCornerCentreBottom = 38;
		int bottomLeftCornerCentreTop = 14;
		int bottomLeftCornerCentreBottom = 18;
		int topLeftCornerCentreTop = 24;
		int topLeftCornerCentreBottom = 28;

		// Outward facing side of the bezels
		setQuadFace(pos++, topRightStartCircleTop + density, topRightStartCircleBottom + density, topLeftStartCircleBottom + density, topLeftStartCircleTop + density);
		setQuadFace(pos++, bottomRightStartCircleTop, bottomRightStartCircleBottom,topRightStartCircleBottom, topRightStartCircleTop);
		setQuadFace(pos++, bottomLeftStartCircleTop + density, bottomLeftStartCircleBottom + density, bottomRightStartCircleBottom + density, bottomRightStartCircleTop + density);
		setQuadFace(pos++, topLeftStartCircleTop, topLeftStartCircleBottom, bottomLeftStartCircleBottom, bottomLeftStartCircleTop);

		// Top of the bezels
		setQuadFace(pos++, topRightCornerCentreTop, topRightStartCircleTop + density, topLeftStartCircleTop + density, topLeftCornerCentreTop);
		setQuadFace(pos++, bottomRightStartCircleTop, topRightStartCircleTop, topRightCornerCentreTop, bottomRightCornerCentreTop);
		setQuadFace(pos++, bottomLeftCornerCentreTop, bottomLeftStartCircleTop + density, bottomRightStartCircleTop + density, bottomRightCornerCentreTop);
		setQuadFace(pos++, topLeftStartCircleTop, bottomLeftStartCircleTop, bottomLeftCornerCentreTop, topLeftCornerCentreTop);

		// Inward facing side of the bezels
		for (int i = 0; i < 4; i++)
		{
			setQuadFace(pos++, 7 + i * 10, 4 + i * 10, 5 + i * 10, 6 + i * 10);
		}

		// bottom of the bezels
		setQuadFace(pos++, topLeftCornerCentreBottom, topLeftStartCircleBottom + density, topRightStartCircleBottom + density, topRightCornerCentreBottom);
		setQuadFace(pos++, bottomRightCornerCentreBottom, topRightCornerCentreBottom, topRightStartCircleBottom, bottomRightStartCircleBottom);
		setQuadFace(pos++, bottomRightCornerCentreBottom, bottomRightStartCircleBottom + density, bottomLeftStartCircleBottom + density, bottomLeftCornerCentreBottom);
		setQuadFace(pos++, topLeftCornerCentreBottom, bottomLeftCornerCentreBottom, bottomLeftStartCircleBottom, topLeftStartCircleBottom);

		// The screen
		setQuadFace(pos++, 7, 6, 17, 16);
		// The bottom of the tablet
		setQuadFace(pos++, 19, 18, 9, 8);
		
		// Draw the sides of the corner
		for (int i = 0; i < density; i++)
		{
			// Top right corner
			setQuadFace(
				pos,
				topRightStartCircleBottom + i,
				topRightStartCircleBottom + (i + 1),
				topRightStartCircleTop + (i + 1),
				topRightStartCircleTop + i
			);
			// Bottom right corner
			setQuadFace(
				pos + density,
				bottomRightStartCircleTop + i,
				bottomRightStartCircleTop + (i + 1),
				bottomRightStartCircleBottom + (i + 1),
				bottomRightStartCircleBottom + i
			);
			// Bottom left corner
			setQuadFace(
				pos + density * 2,
				bottomLeftStartCircleBottom + i,
				bottomLeftStartCircleBottom + (i + 1),
				bottomLeftStartCircleTop + (i + 1),
				bottomLeftStartCircleTop + i
			);
			// Top left corner
			setQuadFace(
				pos + density * 3,
				topLeftStartCircleTop + i,
				topLeftStartCircleTop + (i + 1),
				topLeftStartCircleBottom + (i + 1),
				topLeftStartCircleBottom + i
			);

			pos++;
		}

		pos = 0;

		// Top and bottom of the corner
		for (int i = 0; i < density; i++)
		{
			// Top right corner
			setTriFace(
				pos,
				topRightCornerCentreTop,
				topRightStartCircleTop + i,
				topRightStartCircleTop + (i + 1)
			);
			setTriFace(
				pos + density,
				topRightCornerCentreBottom,
				topRightStartCircleBottom + (i + 1),
				topRightStartCircleBottom + i
			);

			// Bottom right corner
			setTriFace(
				pos + density * 2,
				bottomRightStartCircleTop + (i + 1),
				bottomRightStartCircleTop + i,
				bottomRightCornerCentreTop
			);
			setTriFace(
				pos + density * 3,
				bottomRightStartCircleBottom + i,
				bottomRightStartCircleBottom + (i + 1),
				bottomRightCornerCentreBottom
			);

			// Bottom left corner
			setTriFace(
				pos + density * 4,
				bottomLeftCornerCentreTop,
				bottomLeftStartCircleTop + i,
				bottomLeftStartCircleTop + (i + 1)
			);
			setTriFace(
				pos + density * 5,
				bottomLeftCornerCentreBottom,
				bottomLeftStartCircleBottom + (i + 1),
				bottomLeftStartCircleBottom + i
			);

			// Top left corner
			setTriFace(
				pos + density * 6,
				topLeftStartCircleTop + (i + 1),
				topLeftStartCircleTop + i,
				topLeftCornerCentreTop
			);
			setTriFace(
				pos + density * 7,
				topLeftStartCircleBottom + i,
				topLeftStartCircleBottom + (i + 1),
				topLeftCornerCentreBottom
			);

			pos++;
		}

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();
	}
}
