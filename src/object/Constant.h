#pragma once
#ifndef CONSTANT_H
#define CONSTANT_H

namespace hui {

enum class OBJECT_TYPE : int
{
	NULL_OBJ,		// null
	ERROR_OBJ,		// error

	BOOLEAN_OBJ,	// bool
	INTEGER_OBJ,	// int
	FLOAT_OBJ,		// float
	STRING_OBJ,		// string
	ARRAY_OBJ,		// array
	MAP_OBJ,		// map

	RETURN_VALUE_OBJ,	// return_value

	FUNCTION_OBJ,		// function

	BUILTIN_OBJ,		// builtin

};


static const char* OBJECT_TYPE_VALUE[]{
	"null",		// NULL_OBJ
	"error",	// ERROR_OBJ
	
	"boolean",	// BOOLEAN_OBJ
	"integer",	// INTEGER_OBJ
	"float",	// FLOAT_OBJ
	"string",	// STRING_OBJ
	"array",	// ARRAY_OBJ
	"map",		// MAP_OBJ

	"return_value",		// return_value
	"function",			// FUNCTION_OBJ
	"builtin",			// BUILTIN_OBJ

};



}	// namespace hui

#endif // !CONSTANT_H
