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
	std::unique_ptr<Identifier> m_name;
	std::unique_ptr<Expression> m_value;

public:
	using Statement::Statement;

public:
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
