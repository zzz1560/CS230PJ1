//------------------------------------------------------------------------------
//
// File Name:	SandboxScene.c
// Author(s):	Joren Mahal (joren.mahal)
// Project:		Project 0
// Course:		CS230S25
//
// Copyright © 2025 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Scene.h"
#include "SceneSystem.h"
#include "SandboxScene.h"
#include "DGL.h"
#include "vector2D.h"
#include "Trace.h"
#include "Stream.h"

//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

typedef struct SandboxScene
{
	// WARNING: The base class must always be included first.
	Scene	base;

	// Add any scene-specific variables second.
	float x;
	float y;
} SandboxScene;

typedef struct DGL_Vec2 Vector2D;
typedef struct DGL_Vec2 Test;
typedef struct DGL_Vec2 Test1;
typedef struct DGL_Vec2 Test2;

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

static void SandboxSceneLoad(void);
static void SandboxSceneInit(void);
static void SandboxSceneUpdate(float dt);
static void SandboxSceneExit(void);
static void SandboxSceneUnload(void);
static void SandboxSceneRender(void);

//------------------------------------------------------------------------------
// Instance Variable:
//------------------------------------------------------------------------------

static SandboxScene instance =
{
	// Initialize the base structure:
	{ "Sandbox", SandboxSceneLoad, SandboxSceneInit, SandboxSceneUpdate, SandboxSceneRender, SandboxSceneExit, SandboxSceneUnload },

	// Initialize any scene-specific variables:
	0
};

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Get the instance of the Sandbox Scene.
// Returns:
//	 Pointer to the base Scene structure for this derived Scene.
const Scene* SandboxSceneGetInstance(void)
{
	return &(instance.base);
}

static void SandboxSceneTraceFloat(const char* text, float f) {

	
	if (text == NULL) {
		TraceMessage("SandboxSceneTraceFloat failed text unsuported");
		return;
	}

	TraceMessage("Vector Test: %s = %f", text, f);
}


static void SandboxSceneTraceVector(const char* text, const Vector2D* v){

	if (text == NULL || v == NULL) {
		TraceMessage("SandboxSceneTraceVector failed: ");
		return;
	}

	TraceMessage("Vector Test: %s = [%f, %f]", text, v->x, v->y);
}


//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

// Load any resources used by the scene.
static void SandboxSceneLoad(void)
{
}

// Initialize the entities and variables used by the scene.
static void SandboxSceneInit()
{
	
}

// Update the the variables used by the scene.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
static void SandboxSceneUpdate(float dt)
{
	FILE* OpenVecFile = StreamOpen("Data/VectorTests.txt");

	if (OpenVecFile) {
		// Tell the compiler that the 'dt' variable is unused.
		UNREFERENCED_PARAMETER(dt);

		//StreamOpen()

		//tests
		Test test = {1,2};
	//o	Call Vector2DZero
		Vector2DZero(&test);
		SandboxSceneTraceVector("Vector2DZero", &test);

	//o	Call Vector2DSet with the parameters 1.5f and 1.0f
		Vector2DSet(&test, 1.5f, 1.0f);
		SandboxSceneTraceVector("Vector2DSet", &test);

	//o	Call Vector2DNeg
		Vector2DNeg(&test, &test);
		SandboxSceneTraceVector("Vector2DNeg", &test);

	//o	Call Vector2DAdd
		Vector2DAdd(&test, &test, &test);
		SandboxSceneTraceVector("Vector2DAdd", &test);

	//o	Call Vector2DSub
		Vector2DSub(&test, &test, &test);
		SandboxSceneTraceVector("Vector2DSub", &test);

	//o	Call StreamReadVector2D, passing the vector
		StreamReadVector2D(OpenVecFile, &test);
		SandboxSceneTraceVector("StreamReadVector2D", &test);

	//o	Call Vector2DNormalize
		Vector2DNormalize(&test, &test);
		SandboxSceneTraceVector("Vector2DNormalize", &test);

	//o	Call StreamReadFloat to initialize a “scale” variable
		SandboxSceneTraceFloat("StreamReadFloat", StreamReadFloat(OpenVecFile));

	//o	Call Vector2DScale
		Vector2DScale(&test, &test, 5);
		SandboxSceneTraceVector("Vector2DScale", &test);

	//o	Call Vector2DScaleAdd
		Vector2DScaleAdd(&test, &test, 5, &test);
		SandboxSceneTraceVector("Vector2DScaleAdd", &test);

	//o	Call Vector2DScaleSub
		Vector2DScaleSub(&test, &test, 5, &test);
		SandboxSceneTraceVector("Vector2DScaleSub", &test);

	//o	Call Vector2DLength
		SandboxSceneTraceFloat("Vector2DLength", Vector2DLength(&test));

	//o	Call Vector2DSquareLength
		SandboxSceneTraceFloat("Vector2DSquareLength", Vector2DSquareLength(&test));

	//•	Create two Vector2D 
		Vector2D alt = {0,0};
		Vector2D alt2 = { 0,0 };

	//o	Call StreamReadVector2D, passing the 1st vector
		StreamReadVector2D(OpenVecFile, &alt);
		SandboxSceneTraceVector("StreamReadVector2D", &alt);

	//o	Call StreamReadVector2D, passing the 2nd vector
		StreamReadVector2D(OpenVecFile, &alt2);
		SandboxSceneTraceVector("StreamReadVector2D", &alt2);

	//o	Call Vector2DDistance
		SandboxSceneTraceFloat("Vector2DDistance", Vector2DDistance(&alt, &alt2));

	//o	Call Vector2DSquareDistance
		SandboxSceneTraceFloat("Vector2DSquareDistance", Vector2DSquareDistance(&alt, &alt2));

	//o	Call Vector2DDotProduct
		SandboxSceneTraceFloat("Vector2DDotProduct", Vector2DDotProduct(&alt, &alt2));
	
	//•	Create a single Vector2D 
		Vector2D fin = { 0,0 };

	//o	Call StreamReadFloat to read an angle, in degrees
		float save = StreamReadFloat(OpenVecFile);//save the float pulled from the file to use multiple times
		SandboxSceneTraceFloat("StreamReadFloat", save);

	//o	Call Vector2DFromAngleDeg
		Vector2DFromAngleDeg(&fin, save);
		SandboxSceneTraceVector("Vector2DFromAngleDeg", &fin);
		
	//o	Call StreamReadFloat to read an angle, in radians
		float save2 = StreamReadFloat(OpenVecFile);
		SandboxSceneTraceFloat("StreamReadFloat", save2);
	
	//o	Call Vector2DFromAngleRad
		Vector2DFromAngleRad(&fin, save2);
		SandboxSceneTraceVector("Vector2DFromAngleRad", &fin);

	//o	Call Vector2DToAngleRad, passing the result from the previous test
		SandboxSceneTraceFloat("Vector2DToAngleRad", Vector2DToAngleRad(&fin));

		StreamClose(&OpenVecFile);
	}
	// NOTE: This call causes the engine to exit immediately.  Make sure to remove
	//   it when you are ready to test out a new scene.
	SceneSystemSetNext(NULL);
}

// Render any objects associated with the scene.
void SandboxSceneRender(void)
{

}

// Free any objects associated with the scene.
static void SandboxSceneExit()
{

}

// Unload any resources used by the scene.
static void SandboxSceneUnload(void)
{

}

