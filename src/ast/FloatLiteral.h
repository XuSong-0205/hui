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
	double m_value;

public:
	FloatLiteral(const Token& token, double value)
		: Expression(std::make_unique<Token>(token)),
		  m_value(value) { }

public:
	std::string to_string() override { return m_token->get_literal(); }
};

}	// namespace hui

#endif // !FLOATLITERAL_H
