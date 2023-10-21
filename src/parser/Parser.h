#pragma once
#ifndef PARSER_H
#define PARSER_H


#include <map>
#include <vector>
#include <string>
#include <functional>
#include "Token.h"
#include "Lexer.h"


namespace hui {

enum class PRECEDENCE : int {
	// level 1
	DOT,		// (), [], .

	// level 2
	NOT,		// !, ~, +, -(ÕýºÅ£¬¸ººÅ)

	// level 3
	MUL,		// *, /, %

	// level 4
	ADD,		// +, -

	// level 5
	LS,			// <<, >>
	
	// level 6
	LT,			// <, <=, >, >=

	// level 7
	EQ,			// ==, !=

	// level 8
	BIT_AND,	// &

	// level 9
	XOR,		// ^

	// level 10
	BIT_OR,		// |

	// level 11
	AND,		// &&

	// level 12
	OR,			// ||

	// level 13
	ASSIGN,		// =, +=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=

	// level 14
	COMMA,		// ,

	// level 15
	LOWEST,

};



class Parser 
{
private:
	Lexer lexer;

public:
	Parser(Lexer& lexer);
	Parser(Lexer&& lexer);

};




}	// namespace hui


#endif	// PARSER_H