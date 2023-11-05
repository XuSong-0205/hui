#include "Evaluator.h"

namespace hui {

Evaluator::Evaluator()
{

}


std::shared_ptr<Object> Evaluator::eval(Node* node, Environment* env)
{
	if (auto cast_node = dynamic_cast<Program*>(node))
	{
		return eval_program(cast_node, env);
	}

	if (auto cast_node = dynamic_cast<Identifier*>(node))
	{
		return eval_identifier(cast_node, env);
	}

	if (auto cast_node = dynamic_cast<VarStatement*>(node))
	{
		return eval_var_statement(cast_node, env);
	}

	if (auto cast_node = dynamic_cast<ConstStatement*>(node))
	{
		return eval_const_statement(cast_node, env);
	}

	if (auto cast_node = dynamic_cast<ExpressionStatement*>(node))
	{
		return eval_expression_statement(cast_node, env);
	}

	if (auto cast_node = dynamic_cast<IfStatement*>(node))
	{
		return eval_if_statement(cast_node, env);
	}

	if (auto cast_node = dynamic_cast<ForStatement*>(node))
	{
		return eval_for_statement(cast_node, env);
	}

	if (auto cast_node = dynamic_cast<BlockStatement*>(node))
	{
		return eval_block_statement(cast_node, env);
	}

	if (auto cast_node = dynamic_cast<ReturnStatement*>(node))
	{
		return eval_return_statement(cast_node, env);
	}

	if (auto cast_node = dynamic_cast<FunctionStatement*>(node))
	{
		return eval_function_statement(cast_node, env);
	}




	return nullptr;
}



}	// namespace hui