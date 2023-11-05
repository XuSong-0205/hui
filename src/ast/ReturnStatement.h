#pragma once
#ifndef RETURNSTATEMENT_H
#define RETURNSTATEMENT_H

#include "Statement.h"
#include "Expression.h"
#include <memory>
#include <string>


namespace hui {

class ReturnStatement : public Statement
{
public:
	std::unique_ptr<Expression> m_return_value;

public:
	using Statement::Statement;

public:
	std::string to_string() override
	{
		return token_literal() + " " + m_return_value->to_string() + ";";
	}


};

}	// namespace hui

#endif // !RETURNSTATEMENT_H
