#pragma once
#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Node.h"
#include "Token.h"
#include "Identifier.h"
#include "VarStatement.h"
#include "ConstStatement.h"
#include "ExpressionStatement.h"
#include "IfStatement.h"
#include "ForStatement.h"
#include "BlockStatement.h"
#include "ReturnStatement.h"
#include "FunctionStatement.h"
#include "Program.h"
#include "Environment.h"
#include "Object.h"

#include <memory>


namespace hui {

class Evaluator
{
public:
	Evaluator();

public:
	std::shared_ptr<Object> eval(Node* node, Environment* env);

private:
	std::shared_ptr<Object> eval_program(Program* program, Environment* env);
	std::shared_ptr<Object> eval_identifier(Identifier* node, Environment* env);
	std::shared_ptr<Object> eval_var_statement(VarStatement* var_stmt, Environment* env);
	std::shared_ptr<Object> eval_const_statement(ConstStatement* const_stmt, Environment* env);
	std::shared_ptr<Object> eval_expression_statement(ExpressionStatement* expr_stmt, Environment* env);
	std::shared_ptr<Object> eval_if_statement(IfStatement* if_stmt, Environment* env);
	std::shared_ptr<Object> eval_for_statement(ForStatement* for_stmt, Environment* env);
	std::shared_ptr<Object> eval_block_statement(BlockStatement* block_stmt, Environment* env);
	std::shared_ptr<Object> eval_return_statement(ReturnStatement* return_stmt, Environment* env);
	std::shared_ptr<Object> eval_function_statement(FunctionStatement* func_stmt, Environment* env);

	std::shared_ptr<Object> eval_prefix_expression(Object* obj);
	std::shared_ptr<Object> eval_infix_expression(TOKEN_TYPE op, Object* left, Object* right);
	


private:
	bool is_truthy(Object* obj);
	bool is_error(Object* obj);
	std::shared_ptr<Object> error_binary_op(TOKEN_TYPE op, Object* left, Object* right);
	std::shared_ptr<Object> error_prefix_op(TOKEN_TYPE op, Object* right);
	std::shared_ptr<Object> error_suffix_op(TOKEN_TYPE op, Object* left);

};

}	// namespace hui

#endif // !EVALUATOR_H
