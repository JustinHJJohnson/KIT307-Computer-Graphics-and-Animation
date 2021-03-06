// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// main.cpp
//
// Main entry point. Creates and runs a T3DApplication

#include "T3DTest.h"
#include "ShaderTest.h"
#include "AssigAnimation.h"
#include "ToonShader.h"
#include "GLTestApplication.h"

#ifdef main
#undef main
#endif


using namespace T3D;

int main(int argc, char* argv[])
{
	// AssigAnimation is my movie, ToonShader is the textured object and shader
	T3DApplication *theApp = new AssigAnimation();
	//T3DApplication *theApp = new ToonShader();

	theApp->run();
	delete theApp;

	return 0;
}
