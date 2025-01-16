//------------------------------------------------------------------------------
//
// File Name:	Stub.c
// Author(s):	Joren Mahal (joren.mahal)
// Project:		Project 0
// Course:		CS230S25
//
// Copyright © 2025 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "DGL.h"
#include "Vector2D.h"
#include "Trace.h"

#define _USE_MATH_DEFINES
#include "math.h"
//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

typedef struct DGL_Vec2 Vector2D;

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------


// This function sets the coordinates of the 2D vector (pResult) to 0
void Vector2DZero(Vector2D* pResult) {
	pResult->x = 0;
	pResult->y = 0;

}

// This function sets the coordinates of the 2D vector (pResult) to x & y
void Vector2DSet(Vector2D* pResult, float x, float y) {
	pResult->x = x;
	pResult->y = y;
}


// In this function, pResult will be set to the opposite of pVec0 (e.g. x = -x & y = -y)
void Vector2DNeg(Vector2D* pResult, const Vector2D* pVec0) {
	pResult->x = pVec0->x*-1;
	pResult->y = pVec0->y*-1;
}


// In this function, pResult will be the sum of pVec0 and pVec1 (x result = x0 + x1)
void Vector2DAdd(Vector2D* pResult, const Vector2D* pVec0, const Vector2D* pVec1) {
	pResult->x = pVec0->x + pVec1->x;
	pResult->y = pVec0->y + pVec1->y;
}

// In this function, pResult will be the difference between pVec0 and pVec1 (specifically, pVec0 - pVec1)
void Vector2DSub(Vector2D* pResult, const Vector2D* pVec0, const Vector2D* pVec1) {
	pResult->x = pVec0->x - pVec1->x;
	pResult->y = pVec0->y - pVec1->y;
}

// In this function, pResult will be the unit vector of pVec0
// (NOTE: Care must be taken when pResult = pVec0!)
void Vector2DNormalize(Vector2D* pResult, const Vector2D* pVec0) {
	float temp = sqrtf((pResult->x*pResult->x) + (pResult->y*pResult->y));
	pResult->x = pVec0->x/temp;
	pResult->y = pVec0->y/temp;
}

// In this function, pResult will be the vector pVec0 scaled by the value 'scale'
void Vector2DScale(Vector2D* pResult, const Vector2D* pVec0, float scale) {
	//scaled
	pResult->x = pVec0->x * scale;
	pResult->y = pVec0->y * scale;
}


// In this function, pResult will be the vector pVec0 scaled by 'scale' and added to pVec1
void Vector2DScaleAdd(Vector2D* pResult, const Vector2D* pVec0, float scale, const Vector2D* pVec1) {
	//create save values
	float ansx = 0;
	float ansy = 0;
	
	//scale
	ansx = pVec0->x * scale;
	ansy = pVec0->y * scale;

	//added
	ansx = ansx + pVec1->x;
	ansy = ansy + pVec1->y;

	//set answer
	pResult->x = ansx;
	pResult->y = ansy;
}


// In this function, pResult will be the vector pVec0 scaled by 'scale' and pVec1 will be subtracted from it
void Vector2DScaleSub(Vector2D* pResult, const Vector2D* pVec0, float scale, const Vector2D* pVec1) {
	//create save values
	float ansx = 0;
	float ansy = 0;

	//scale
	ansx = pVec0->x * scale;
	ansy = pVec0->y * scale;

	//sub
	ansx = ansx - pVec1->x;
	ansy = ansy - pVec1->y;

	//set answer
	pResult->x = ansx;
	pResult->y = ansy;
}


// This function returns the length of the vector pVec0
float Vector2DLength(const Vector2D* pVec0) {
	float ans = sqrtf((pVec0->x * pVec0->x) + (pVec0->y * pVec0->y));
	return ans;
}

// This function returns the square of pVec0's length.
// NOTE: The square root function must NOT be called by this function.
float Vector2DSquareLength(const Vector2D* pVec0) {
	float ans = (pVec0->x * pVec0->x) + (pVec0->y * pVec0->y);
	
	return ans;
}

// This function returns the distance between two points.
float Vector2DDistance(const Vector2D* pVec0, const Vector2D* pVec1) {
	float ans = sqrtf(((pVec0->x - pVec1->x) * (pVec0->x - pVec1->x)) + ((pVec0->y - pVec1->y) * (pVec0->y - pVec1->y)));
	
	return ans;
}

// This function returns the distance squared between two points.
// NOTE: The square root function must NOT be called by this function.
float Vector2DSquareDistance(const Vector2D* pVec0, const Vector2D* pVec1) {
	float ans = ((pVec0->x - pVec1->x) * (pVec0->x - pVec1->x)) + ((pVec0->y - pVec1->y) * (pVec0->y - pVec1->y));
	
	return ans;
}

// This function returns the dot product between pVec0 and pVec1
float Vector2DDotProduct(const Vector2D* pVec0, const Vector2D* pVec1) {
	float ans = ((pVec0->x * pVec1->x) + (pVec0->y * pVec1->y));
	return ans;
}

// This function computes the coordinates of the unit vector represented by the angle "angle", which is in Degrees.
// Converting from degrees to radians can be performed as follows:
//	 radians = (angle * M_PI) / 180.0f
// M_PI is defined in "math.h", which may be included as follows:
//   #define _USE_MATH_DEFINES
//   #include <math.h>
void Vector2DFromAngleDeg(Vector2D* pResult, float angle) {
	float rad = ((angle * (float)M_PI) / 180.0f);
	pResult->x = cosf(rad);
	pResult->y = sinf(rad);
}

// This function computes the coordinates of the unit vector represented by the angle "angle", which is in Radians.
// HINT: x = cos(angle), y = sin(angle).
void Vector2DFromAngleRad(Vector2D* pResult, float angle) {

	pResult->x = cosf(angle);
	pResult->y = sinf(angle);
}

// This function computes the angle, in radians, of the specified vector.
// HINT: Angle (radians) = atan2f(direction Y, direction X).
// NOTE: If the pointer is NULL, then return 0.0f.
float Vector2DToAngleRad(const Vector2D* pVec) {
	if (pVec == NULL) {
		return 0.0f;
	}
	float ans = atan2f(pVec->y, pVec->x);

	return ans;
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

