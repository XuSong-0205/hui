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
	std::unique_ptr<Token> m_token;
	std::unique_ptr<VarStatement> m_loop_var;
	std::unique_ptr<Expression> m_condition;
	std::unique_ptr<Expression> m_next_step;
	std::unique_ptr<BlockStatement> m_body;

public:
	ForStatement(const Token& token)
		: m_token(std::make_unique<Token>(token)) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
	std::string to_string() override
	{
		std::string str;

		str += "for";
		str += "(";

		str += m_loop_var->to_string();
		str += m_condition->to_string();
		str += m_next_step->to_string();

		str += ")";
		str += m_body->to_string();

		return str;
	}

};

}	// namespace hui

#endif // !FORSTATEMENT_H