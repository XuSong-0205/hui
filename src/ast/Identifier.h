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
	std::string m_value;

public:
	using Expression::Expression;
	Identifier(const Token& token, const std::string value)
		: Expression(std::make_unique<Token>(token))
		, m_value(value) { }

public:
	std::string to_string() override { return m_value; };
};

}	// namespace hui

#endif // !IDENTIFIER_H
