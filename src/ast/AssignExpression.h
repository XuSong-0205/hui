#pragma once
#ifndef ASSIGNEXPRESSION_H
#define ASSIGNEXPRESSION_H

#include <memory>
#include <string>
#include "Token.h"
#include "Expression.h"
#include "Identifier.h"


namespace hui {

class AssignExpression : public Expression
{
public:
	std::unique_ptr<Identifier> m_name;
	std::unique_ptr<Expression> m_value;

public:
	using Expression::Expression;

public:
	std::string to_string() override
	{
		return m_name->to_string() + " = " + m_value->to_string();
	}

};

}	// namespace hui

#endif // !ASSIGNEXPRESSION_H
