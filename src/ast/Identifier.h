#pragma once
#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <string>
#include <memory>
#include "Expression.h"
#include "Token.h"

namespace hui {

class Identifier : public Expression
{
public:
	std::unique_ptr<Token> m_token;
	std::string m_value;

public:
	Identifier(const Token& token, const std::string& value)
		: m_token(std::make_unique<Token>(token)), m_value(value) { }

public:
	std::string token_literal() override { return m_token->get_literal(); };
	std::string to_string() override { return m_value; };
};

}	// namespace hui

#endif // !IDENTIFIER_H
