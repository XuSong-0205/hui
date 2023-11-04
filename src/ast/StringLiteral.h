#pragma once
#ifndef STRINGLITERAL_H
#define STRINGLITERAL_H

#include <memory>
#include <string>
#include "Token.h"
#include "Expression.h"

namespace hui {

class StringLiteral : public Expression
{
private:
	std::string m_value;

public:
	StringLiteral(const Token& token, const std::string& value)
		: Expression(std::make_unique<Token>(token)),
		  m_value(value) { }

public:
	std::string to_string() override { return m_token->get_literal(); }
};

}	// namespace hui

#endif // !STRINGLITERAL_H
