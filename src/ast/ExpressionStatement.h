#pragma once
#ifndef EXPRESSIONSTATEMENT_H
#define EXPRESSIONSTATEMENT_H

#include <memory>
#include "Expression.h"
#include "Identifier.h"
#include "Statement.h"
#include "Token.h"

namespace hui {

class ExpressionStatement : public Statement
{
public:
	std::unique_ptr<Token> m_token;
	std::unique_ptr<Expression> m_expression;
	
public:
	ExpressionStatement(const Token& token)
		: m_token(std::make_unique<Token>(token)) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
	std::string to_string() override { return m_expression->to_string(); }
};

}	// namespace hui

#endif // !EXPRESSIONSTATEMENT_H
