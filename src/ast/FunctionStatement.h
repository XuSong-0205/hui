#pragma once
#ifndef FUNCTIONSTATEMENT_H
#define FUNCTIONSTATEMENT_H

#include <vector>
#include <string>
#include <memory>
#include "BlockStatement.h"
#include "Statement.h"
#include "Identifier.h"
#include "Token.h"

namespace hui {

class FunctionStatement : public Statement
{
public:
	std::unique_ptr<Identifier> m_name;
	std::unique_ptr<std::vector<std::unique_ptr<Identifier>>> m_parameters;
	std::unique_ptr<BlockStatement> m_body;

public:
	using Statement::Statement;

public:
	std::string to_string() override
	{
		std::string str;

		str += token_literal();
		str += m_name->to_string();
		str += "(";
		for (auto&& param : *m_parameters)
		{
			str += param->to_string();
		}
		str += ")";
		str += m_body->to_string();

		return str;
	}
};

}	// namespace hui

#endif // !FUNCTIONSTATEMENT_H
