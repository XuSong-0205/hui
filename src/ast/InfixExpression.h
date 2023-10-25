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
private:
	std::unique_ptr<Token> m_token;
	std::unique_ptr<Expression> m_left;
	std::string m_oper;
	std::unique_ptr<Expression> m_right;

public:
	InfixExpression(std::unique_ptr<Token> token,
					std::unique_ptr<Expression> left,
					const std::string& oper,
					std::unique_ptr<Expression> right)
		: m_token(std::move(token)),
		  m_left(std::move(left)),
		  m_oper(oper),
		  m_right(std::move(right)) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
	std::string to_string() override
	{
		return "(" + m_left->to_string() + " " + m_oper + " " + m_right->to_string() + ")";
	}

};

}	// namespace hui

#endif // !INFIXEXPRESSION_H
