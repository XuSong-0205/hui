#pragma once
#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

#include <string_view>

namespace hui {
namespace token {

enum class TOKEN_TYPE : int {
	ILLEGAL,		// "ILLEGAL"
	EOF_,			// "EOF"


	// Identifiers + literals
	IDENT,			// "IDENT"	// add, foo, x, i, ...
	INT,			// "INT"	// 20231021
	FLOAT,			// "FLOAT"	// 3.1415926
	STRING,			// "STRING"	// "hello hui"


	// Operators
	// level 1
	DOT,			// "."

	// level 2
	NOT,			// "!"
	NEGATION,		// ~

	// level 3
	MUL,			// "*"
	DIV,			// "/"
	REM,			// "%"

	// level 4
	ADD,			// "+"
	SUB,			// "-"

	// level 5
	LEFT_SHIFT,		// "<<"
	RIGHT_SHIFT,	// ">>"

	// level 6
	LT,				// "<"
	LT_EQ,			// "<="
	GT,				// ">"
	GT_EQ,			// ">="

	// level 7
	EQ,				// "=="
	NOT_EQ,			// "!="

	// level 8
	BIT_AND,		// "&"

	// level 9
	XOR,			// "^"

	// level 10
	BIT_OR,			// "|"

	// level 11
	AND,			// "&&"

	// level 12
	OR,				// "||"

	// level 13
	ASSIGN,			// "="
	ADD_ASSIGN,		// "+="
	SUB_ASSING,		// "-="
	MUL_ASSIGN,		// "*="
	DIV_ASSIGN,		// "/="
	REM_ASSIGN,		// "%="
	BIT_AND_ASSIGN,	// "&="
	XOR_ASSIGN,		// "^="
	BIT_OR_ASSIGN,	// "|="
	LS_ASSIGN,		// "<<="
	RS_ASSIGN,		// ">>="


	// Delimiters
	COMMA,			// ","
	SEMICOLON,		// ";"
	QUES_MARK,		// "?"
	COLON,			// ":"

	LPAREN,			// "("
	RPAREN,			// ")"
	LBRACE,			// "{"
	RBRACE,			// "}"
	LBRACKET,		// "["
	RBRACKET,		// "]"


	// Keywords
	VAR,			// "VAR"	// "var"
	CONST,			// "CONST"	// "const"
	FALSE,			// "FALSE"	// "false"
	TRUE,			// "TRUE"	// "true"
	FUNC,			// "FUNC"	// "func"
	IF,				// "IF"		// "if"
	ELSE,			// "ELSE"	// "else"
	FOR,			// "FOR"	// "for"
	CONTINUE,		// "CONTINUE"	// "continue"
	BREAK,			// "BREAK"		// "break"
	RETURN,			// "RETURN"		// "return"
};


static constexpr std::string_view TOKEN_TYPE_VALUE[] = {
	"ILLEGAL",		// "ILLEGAL"
	"EOF",			// "EOF"


	// Identifiers + literals
	"IDENT",		// "IDENT"	// add, foo, x, i, ...
	"INT",			// "INT"	// 20231021
	"FLOAT",		// "FLOAT"	// 3.1415926
	"STRING",		// "STRING"	// "hello hui"


	// Operators
	// level 1
	"DOT",			// "."

	// level 2
	"NOT",			// "!"
	"NEGATION",		// ~

	// level 3
	"MUL",			// "*"
	"DIV",			// "/"
	"REM",			// "%"

	// level 4
	"ADD",			// "+"
	"SUB",			// "-"

	// level 5
	"LEFT_SHIFT",	// "<<"
	"RIGHT_SHIFT",	// ">>"

	// level 6
	"LT",			// "<"
	"LT_EQ",		// "<="
	"GT",			// ">"
	"GT_EQ",		// ">="

	// level 7
	"EQ",			// "=="
	"NOT_EQ",		// "!="

	// level 8
	"BIT_AND",		// "&"

	// level 9
	"XOR",			// "^"

	// level 10
	"BIT_OR",		// "|"

	// level 11
	"AND",			// "&&"

	// level 12
	"OR",			// "||"

	// level 13
	"ASSIGN",			// "="
	"ADD_ASSIGN",		// "+="
	"SUB_ASSING",		// "-="
	"MUL_ASSIGN",		// "*="
	"DIV_ASSIGN",		// "/="
	"REM_ASSIGN",		// "%="
	"BIT_AND_ASSIGN",	// "&="
	"XOR_ASSIGN",		// "^="
	"BIT_OR_ASSIGN",	// "|="
	"LS_ASSIGN",		// "<<="
	"RS_ASSIGN",		// ">>="


	// Delimiters
	"COMMA",			// ","
	"SEMICOLON",		// ";"
	"QUES_MARK",		// "?"
	"COLON",			// ":"

	"LPAREN",			// "("
	"RPAREN",			// ")"
	"LBRACE",			// "{"
	"RBRACE",			// "}"
	"LBRACKET",			// "["
	"RBRACKET",			// "]"


	// Keywords
	"VAR",				// "VAR"	// "var"
	"CONST",			// "CONST"	// "const"
	"FALSE",			// "FALSE"	// "false"
	"TRUE",				// "TRUE"	// "true"
	"FUNC",				// "FUNC"	// "func"
	"IF",				// "IF"		// "if"
	"ELSE",				// "ELSE"	// "else"
	"FOR",				// "FOR"	// "for"
	"CONTINUE",			// "CONTINUE"	// "continue"
	"BREAK",			// "BREAK"		// "break"
	"RETURN",			// "RETURN"		// "return"
};



static_assert(TOKEN_TYPE_VALUE[static_cast<int>(TOKEN_TYPE::RETURN)] == "RETURN", "TOKEN_TYPE_VALUE LENGTH ERROR!");


}	// namespace token
}	// namespace hui


#endif	// TOKEN_TYPE_H