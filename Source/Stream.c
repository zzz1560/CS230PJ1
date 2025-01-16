//------------------------------------------------------------------------------
//
// File Name:	Stream.c
// Author(s):	Joren Mahal (joren.mahal)
// Project:		Project 0
// Course:		CS230S25
//
// Copyright © 2025 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "Stream.h"

#include "Trace.h"
#include "DGL.h"

//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------
typedef FILE* Stream;

typedef struct DGL_Vec2 Vector2D;

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

errno_t erro;//used in tandome with strerror_s to catch streamOpen erro msg
char errorMsg[1024];//space for file 
FILE* StreamOpen_File;//to store specific error txt

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------
// 
// Open a file for reading.
// (NOTE: Use fopen_s() with the "rt" option.)
// (NOTE: You must generate the following trace message if the file was not opened successfully:
//	  TraceMessage("Error: StreamOpen could not open file %s; %s", filePath, errorMsg);
//	  Where errorMsg is a char array containing the error message obtained using strerror_s().)
// Params:
//	 filePath = The file to be opened for reading.
// Returns:
//	 NULL if filePath is NULL or the file could not be opened.
//	 Pointer to a FILE object if the file was opened successfully.
//tested
Stream StreamOpen(const char* filePath) {

	if (filePath == NULL) {
		return NULL;
	}

	erro = fopen_s(&StreamOpen_File, filePath, "rt");

	if (erro != 0) {
		strerror_s(errorMsg, 1024, erro);
		TraceMessage("Error: StreamOpen could not open file %s", filePath, errorMsg);
		return NULL;
	}

	return StreamOpen_File;
}

// Read a single integer from a stream.
// (NOTE: Verify that the stream is valid first.)
// (NOTE: Use fscanf_s() to scan the input stream for an integer.)
// Params:
//	 stream = The file stream from which to read.
// Returns:
//	 0 if the stream was not opened succesfully;
//	 otherwise, an integer value read from the file.
//tested
int StreamReadInt(Stream stream) {
	if (stream == NULL) {
		return 0;
	}

	int val;
	if (fscanf_s(stream, "%d", &val) == 1){
		return val;
	}

	return 0;
}

// Read a single float from a stream.
// (NOTE: Verify that the stream is valid first.)
// (NOTE: Use fscanf_s() to scan the input stream for a float.)
// Params:
//	 stream = The file stream from which to read.
// Returns:
//	 If the stream was opened succesfully,
//	   then return a float value read from the file,
//	   else return 0.
//tested
float StreamReadFloat(Stream stream) {
	if (stream == NULL) {
		return 0;
	}

	float val;

	if (fscanf_s(stream, "%f", &val) == 1) {
		return val;
	}

	return 0;
}

// Read the data for a Vector2D from a stream.
// (NOTE: Verify that the stream and vector pointer are valid first.)
// (HINT: Use StreamReadFloat() to read the x and y values, in sequence.)
// Params:
//	 stream = The file stream from which to read.
// Returns:
//	 If the stream and vector pointer are both valid,
//	   then fill the vector with two float values (x & y),
//	   else do nothing (optionally, write an error message to the trace log).


void StreamReadVector2D(Stream stream, Vector2D* vector) {
	
	if (stream == NULL || vector == NULL) { // check if file was open or for error
		TraceMessage("Failed StreamReadVector2D Error: vector or stream faild");
		return;
	}

	vector->x = StreamReadFloat(stream);

	vector->y = StreamReadFloat(stream);
	

}


// Close an opened stream.
// (NOTE: Do not attempt to close the stream if the pointer is null.)
// (PRO TIP: Avoid dangling pointers by setting the FILE pointer to NULL.)
// Params:
//	 stream = The file stream to be closed.
//tested
void StreamClose(Stream* stream) {
	//remember pointers are wich line its defined, no pointer is value it holds need to check both.
	if (stream == NULL || *stream == NULL) {
		return;
	}

	fclose(*stream);
	*stream = NULL;
}

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Private Functions:
//---------------------------------------------------------------------------