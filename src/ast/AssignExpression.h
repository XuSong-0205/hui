#pragma once
#ifndef ASSIGNEXPRESSION_H
#define ASSIGNEXPRESSION_H

#include <memory>
#include <string>
#include "Token.h"
#include "Expression.h"
#include "Identifier.h"


namespace hui {

class AssignExpression : public Expression
{
private:
	std::unique_ptr<Token> m_token;
	std::unique_ptr<Identifier> m_name;
	std::unique_ptr<Expression> m_value;

public:
	AssignExpression(std::unique_ptr<Token> token,
					 std::unique_ptr<Identifier> name,
					 std::unique_ptr<Expression> value)
		: m_token(std::move(token)),
		  m_name(std::move(name)),
		  m_value(std::move(value)) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
	std::string to_string() override
	{
		return m_name->to_string() + " = " + m_value->to_string();
	}

};

}	// namespace hui

#endif // !ASSIGNEXPRESSION_H
