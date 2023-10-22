#pragma once
#ifndef VARSTATEMENT_H
#define VARSTATEMENT_H

#include <memory>
#include "Expression.h"
#include "Identifier.h"
#include "Statement.h"
#include "Token.h"

namespace hui {

class VarStatement : public Statement
{
public:
	std::unique_ptr<Token> m_token;
	std::unique_ptr<Identifier> m_name;
	std::unique_ptr<Expression> m_value;

public:
	VarStatement(const Token& token)
		: m_token(std::make_unique<Token>(token)) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
	std::string to_string() override
	{
		std::string str = token_literal() + " " +
			m_name->to_string() + " = " +
			m_value->to_string() + ";";
		return str;
	}

};

}	// namespace hui

#endif // !VARSTATEMENT_H
