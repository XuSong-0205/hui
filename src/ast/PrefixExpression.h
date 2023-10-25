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
private:
	std::unique_ptr<Token> m_token;
	std::string m_oper;
	std::unique_ptr<Expression> m_right;

public:
	PrefixExpression(const Token& token, 
					 const std::string& oper,
					 std::unique_ptr<Expression> right)
		: m_token(std::make_unique<Token>(token)),
		  m_oper(oper),
		  m_right(std::move(right)) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
	std::string to_string() override 
	{
		return "(" + m_oper + m_right->to_string() + ")";
	}

};

}	// namespace hui

#endif // !PREFIXEXPRESSION_H
