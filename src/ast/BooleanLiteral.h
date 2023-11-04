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
	bool m_value;

public:
	BooleanLiteral(const Token& token, bool value)
		: Expression(std::make_unique<Token>(token)),
		  m_value(value) { }

public:
	std::string to_string() override { return m_token->get_literal(); }
};

}	// namespace hui

#endif // !BOOLEANLITERAL_H
