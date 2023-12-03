#pragma once
#ifndef FORSTATEMENT_H
#define FORSTATEMENT_H

#include <string>
#include <memory>
#include "BlockStatement.h"
#include "VarStatement.h"
#include "Statement.h"
#include "Token.h"

namespace hui {

class ForStatement : public Statement
{
public:
	std::unique_ptr<VarStatement> m_loop_var;
	std::unique_ptr<Expression> m_condition;
	std::unique_ptr<Expression> m_next_step;
	std::unique_ptr<BlockStatement> m_body;

public:
	using Statement::Statement;

public:
	std::string to_string() override
	{
		std::string str;

		str += "for ";
		str += "(";

		str += m_loop_var->to_string();
		str += " " + m_condition->to_string() + ";";
		str += " " + m_next_step->to_string();

		str += ") ";
		str += m_body->to_string();

		return str;
	}

};

}	// namespace hui

#endif // !FORSTATEMENT_H
