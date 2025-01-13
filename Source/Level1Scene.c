//------------------------------------------------------------------------------
//
// File Name:	Level1Scene.c
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
#include "Level1Scene.h"

#include "Stream.h"
//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

typedef struct Level1Scene
{
	// WARNING: The base class must always be included first.
	Scene	base;

	// Add any scene-specific variables second.
	int numLives;

} Level1Scene;

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

static void Level1SceneLoad(void);
static void Level1SceneInit(void);
static void Level1SceneUpdate(float dt);
static void Level1SceneExit(void);
static void Level1SceneUnload(void);
static void Level1SceneRender(void);

//------------------------------------------------------------------------------
// Instance Variable:
//------------------------------------------------------------------------------

static Level1Scene instance =
{
	// Initialize the base structure:
	{ "Stub", Level1SceneLoad, Level1SceneInit, Level1SceneUpdate, Level1SceneRender, Level1SceneExit, Level1SceneUnload },

	// Initialize any scene-specific variables:
	0
};

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Get the instance of the Stub Scene.
// Returns:
//	 Pointer to the base Scene structure for this derived Scene.
const Scene* Level1SceneGetInstance(void)
{
	return &(instance.base);
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------
float i = 0;
// Load any resources used by the scene.
static void Level1SceneLoad(void)
{
	FILE *OpenFile = StreamOpen("Data/Level1_Lives.txt");


	if (OpenFile != NULL) {
		instance.numLives = StreamReadInt(OpenFile);//saves numLives from file
		StreamClose(&OpenFile);//closes file
	}

	
	
}

// Initialize the entities and variables used by the scene.
static void Level1SceneInit()
{

}

// Update the the variables used by the scene.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
static void Level1SceneUpdate(float dt)
{
	// Tell the compiler that the 'dt' variable is unused.
	UNREFERENCED_PARAMETER(dt);
	instance.numLives--;
	if (instance.numLives >= 0) {
		// NOTE: This call causes the engine to exit immediately.  Make sure to remove
		//   it when you are ready to test out a new scene.
		SceneSystemSetNext(NULL);
	}
}

// Render any objects associated with the scene.
void Level1SceneRender(void)
{

}

// Free any objects associated with the scene.
static void Level1SceneExit()
{

}

// Unload any resources used by the scene.
static void Level1SceneUnload(void)
{

}

