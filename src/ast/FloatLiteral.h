#pragma once
#ifndef FLOATLITERAL_H
#define FLOATLITERAL_H

#include <memory>
#include <string>
#include "Token.h"
#include "Expression.h"


namespace hui {

class FloatLiteral : public Expression
{
private:
	std::unique_ptr<Token> m_token;
	double m_value;

public:
	FloatLiteral(const Token& token, double value)
		: m_token(std::make_unique<Token>(token)),
		  m_value(value) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
	std::string to_string() override { return m_token->get_literal(); }
};

}	// namespace hui

#endif // !FLOATLITERAL_H
