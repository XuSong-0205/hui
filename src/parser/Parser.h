#pragma once
#ifndef PARSER_H
#define PARSER_H


#include <map>
#include <vector>
#include <string>
#include <memory>
#include <functional>
#include "Token.h"
#include "Lexer.h"
#include "Program.h"
#include "VarStatement.h"
#include "ConstStatement.h"
#include "IfStatement.h"
#include "ForStatement.h"
#include "BlockStatement.h"
#include "FunctionStatement.h"
#include "ExpressionStatement.h"
#include "ReturnStatement.h"


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
	std::unique_ptr<Lexer> m_lexer;
	std::vector<std::string> m_errors;

	std::unique_ptr<Token> m_curr_token;
	std::unique_ptr<Token> m_next_token;

	using prefix_func = std::function<std::unique_ptr<Expression>()>;
	using infix_func  = std::function<std::unique_ptr<Expression>(std::unique_ptr<Expression>)>;

	std::map<TOKEN_TYPE, prefix_func> m_prefix_funcs;
	std::map<TOKEN_TYPE, infix_func>  m_infix_funcs;

public:
	Parser(const Lexer& lexer);
	Parser(std::unique_ptr<Lexer> lexer);


public:
	std::shared_ptr<Program> parse_program();
	const std::vector<std::string>& errors() const;

private:
	void init();
	void next_token();

	bool curr_token_is(TOKEN_TYPE t) const;
	bool next_token_is(TOKEN_TYPE t) const;
	bool expect_next(TOKEN_TYPE t);

	PRECEDENCE curr_precedence() const;
	PRECEDENCE next_precedence() const;
	
	void next_error(TOKEN_TYPE t);
	void no_prefix_parse_func_error(TOKEN_TYPE t);

private:
	std::unique_ptr<Statement> parse_statement();
	std::unique_ptr<VarStatement> parse_var_statement();
	std::unique_ptr<ConstStatement> parse_const_statement();
	std::unique_ptr<IfStatement> parse_if_statement();
	std::unique_ptr<ForStatement> parse_for_statement();
	//std::unique_ptr<Statement> parse_continue_statement();
	//std::unique_ptr<Statement> parse_break_statement();
	std::unique_ptr<ReturnStatement> parse_return_statement();
	std::unique_ptr<FunctionStatement> parse_function_statement();
	std::unique_ptr<ExpressionStatement> parse_expression_statement();
	std::unique_ptr<BlockStatement> parse_block_statement();


private:
	void reg_prefix_func(TOKEN_TYPE type, prefix_func func);
	void reg_infix_func(TOKEN_TYPE type, infix_func func);

	std::unique_ptr<Expression> parse_expression(PRECEDENCE prec = PRECEDENCE::LOWEST);

	std::unique_ptr<Expression> parse_identifier();
	std::unique_ptr<Expression> parse_bool_literal();
	std::unique_ptr<Expression> parse_integer_literal();
	std::unique_ptr<Expression> parse_float_literal();
	std::unique_ptr<Expression> parse_string_literal();
	std::unique_ptr<Expression> parse_array_literal();
	std::unique_ptr<Expression> parse_map_literal();

	std::unique_ptr<Expression> parse_prefix_expression();
	std::unique_ptr<Expression> parse_grouped_expression();
	std::unique_ptr<Expression> parse_infix_expression(std::unique_ptr<Expression> left);
	std::unique_ptr<Expression> parse_assign_expression(std::unique_ptr<Expression> left);
	std::unique_ptr<Expression> parse_dot_expression(std::unique_ptr<Expression> left);

	std::unique_ptr<std::vector<std::unique_ptr<Identifier>>> parse_function_parameters();
	std::unique_ptr<Expression> parse_call_expression(std::unique_ptr<Expression> expr);
	std::unique_ptr<std::vector<std::unique_ptr<Expression>>> parse_call_arguments();
	std::unique_ptr<std::vector<std::unique_ptr<Expression>>> parse_expression_list(TOKEN_TYPE end);
	std::unique_ptr<Expression> parse_index_expression(std::unique_ptr<Expression> left);

};




}	// namespace hui


#endif	// PARSER_H