#pragma once
#ifndef PREFIXEXPRESSION_H
#define PREFIXEXPRESSION_H

#include <memory>
#include <string>
#include "Token.h"
#include "Expression.h"


namespace hui {

class PrefixExpression : public Expression
{
public:
	std::string m_oper;
	std::unique_ptr<Expression> m_right;

public:
	explicit PrefixExpression(const Token& token)
		: Expression(std::make_unique<Token>(token))
		, m_oper(token.get_literal()) { } 

public:
	std::string to_string() override 
	{
		return "(" + m_oper + m_right->to_string() + ")";
	}

};

}	// namespace hui

#endif // !PREFIXEXPRESSION_H
