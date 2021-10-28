// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// main.cpp
//
// Main entry point. Creates and runs a T3DApplication

#include "Exam2D.h"
#include "Exam3D.h"
#include "GLTestApplication.h"

#ifdef main
#undef main
#endif


using namespace T3D;

int main(int argc, char* argv[]) {
	// Dish ran away with the spoon
	//T3DApplication *theApp = new Exam2D();
	// Cow jumped over the moon
	T3DApplication* theApp = new Exam3D();

	theApp->run();
	delete theApp;

	return 0;
}
