//------------------------------------------------------------------------------
//
// File Name:	Level2Scene.c
// Author(s):	Joren Mahal (joren.mahal)
// Project:		Project 0
// Course:		CS230S25
//
// Copyright � 2025 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Scene.h"
#include "SceneSystem.h"
#include "Level2Scene.h"
#include "Stream.h"
#include "SandboxScene.h"

#include "Trace.h"
//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

typedef struct Level2Scene
{
	// WARNING: The base class must always be included first.
	Scene	base;

	// Add any scene-specific variables second.
	int numLives;
	int numHealth;

} Level2Scene;

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

static void Level2SceneLoad(void);
static void Level2SceneInit(void);
static void Level2SceneUpdate(float dt);
static void Level2SceneExit(void);
static void Level2SceneUnload(void);
static void Level2SceneRender(void);

//------------------------------------------------------------------------------
// Instance Variable:
//------------------------------------------------------------------------------

static Level2Scene instance =
{
	// Initialize the base structure:
	{ "Level2", Level2SceneLoad, Level2SceneInit, Level2SceneUpdate, Level2SceneRender, Level2SceneExit, Level2SceneUnload },

	// Initialize any scene-specific variables:
	0,0

};

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Get the instance of the Level2S Scene.
// Returns:
//	 Pointer to the base Scene structure for this derived Scene.
const Scene* Level2SceneGetInstance(void)
{
	return &(instance.base);
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

// Load any resources used by the scene.
static void Level2SceneLoad(void)
{
	FILE* OpenFilelv2 = StreamOpen("Data/Level2_Lives.txt");


	if (OpenFilelv2 != NULL) {//check to make sure file openend
		instance.numLives = StreamReadInt(OpenFilelv2);//saves numLives from file
		StreamClose(&OpenFilelv2);//closes file
	}
	else {//sends to trace log
		TraceMessage("Level2_Lives.txt not opened");
	}

	

}

// Initialize the entities and variables used by the scene.
static void Level2SceneInit()
{
	FILE* OpenFilelv22 = StreamOpen("Data/Level2_Health.txt");

	if (OpenFilelv22 != NULL) {//check to make sure file openend
		instance.numHealth = StreamReadInt(OpenFilelv22);//saves numLives from file
		StreamClose(&OpenFilelv22);//closes file
	}
	else {//sends to trace log
		TraceMessage("Level2_Health.txt not opened");
	}
}

// Update the the variables used by the scene.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
static void Level2SceneUpdate(float dt)
{
	// Tell the compiler that the 'dt' variable is unused.
	UNREFERENCED_PARAMETER(dt);

	instance.numHealth--;
	if (instance.numHealth <= 0) {
		instance.numLives--;
		if (instance.numLives > 0) {
			SceneRestart();
		}
		else {
			SceneSystemSetNext(SandboxSceneGetInstance());
		}

			
	}


	// NOTE: This call causes the engine to exit immediately.  Make sure to remove
	//   it when you are ready to test out a new scene.
	//SceneSystemSetNext(NULL);
}

// Render any objects associated with the scene.
void Level2SceneRender(void)
{
}

// Free any objects associated with the scene.
static void Level2SceneExit()
{
}

// Unload any resources used by the scene.
static void Level2SceneUnload(void)
{
}

