#pragma once
#ifndef INFIXEXPRESSION_H
#define INFIXEXPRESSION_H

#include <memory>
#include <string>
#include "Token.h"
#include "Expression.h"


namespace hui {

class InfixExpression : public Expression
{
public:
	std::unique_ptr<Expression> m_left;
	std::string m_oper;
	std::unique_ptr<Expression> m_right;

public:
 	explicit InfixExpression(const Token& token) 
		: Expression(std::make_unique<Token>(token))
		, m_oper(token.get_literal()) { }

public:
	std::string to_string() override
	{
		return "(" + m_left->to_string() + " " + m_oper + " " + m_right->to_string() + ")";
	}

};

}	// namespace hui

#endif // !INFIXEXPRESSION_H
