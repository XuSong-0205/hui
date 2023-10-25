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
	std::unique_ptr<Token> m_token;
	std::string m_value;

public:
	StringLiteral(const Token& token, const std::string& value)
		: m_token(std::make_unique<Token>(token)),
		  m_value(value) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
	std::string to_string() override { return m_token->get_literal(); }
};

}	// namespace hui

#endif // !STRINGLITERAL_H
