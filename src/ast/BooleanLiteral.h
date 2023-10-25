#pragma once
#ifndef BOOLEANLITERAL_H
#define BOOLEANLITERAL_H

#include <memory>
#include <string>
#include "Expression.h"
#include "Token.h"

namespace hui {

class BooleanLiteral : public Expression
{
private:
	std::unique_ptr<Token> m_token;
	bool m_value;

public:
	BooleanLiteral(const Token& token, bool value)
		: m_token(std::make_unique<Token>(token)),
		  m_value(value) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
	std::string to_string() override { return m_token->get_literal(); }
};

}	// namespace hui

#endif // !BOOLEANLITERAL_H
