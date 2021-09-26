// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// Tutorial1.cpp
//
// Base application for tutorial 1.  Used in conjunction with DrawTask, a task for drawing onto a 2D texture.

#pragma once

#include "WinGLApplication.h"
#include "Texture.h"
#include "DrawTask.h"

namespace T3D
{
	//! \brief Tutorial1 Driver
	class Tutorial3 :
		public WinGLApplication
	{
	public:
		Tutorial3(void);
		~Tutorial3(void) = default;

		bool init();


	private:
		Texture* drawArea;
		DrawTask* drawTask;

	};

}