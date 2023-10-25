#pragma once
#ifndef INTEGERLITERAL_H
#define INTEGERLITERAL_H

#include <memory>
#include <string>
#include "Token.h"
#include "Expression.h"


namespace hui {

class IntegerLiteral : public Expression
{
private:
	std::unique_ptr<Token> m_token;
	std::int64_t m_value;

public:
	IntegerLiteral(const Token& token, std::int64_t value)
		: m_token(std::make_unique<Token>(token)),
		  m_value(value) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
	std::string to_string() override { return m_token->get_literal(); }
};

}	// namespace hui

#endif // !INTEGERLITERAL_H
