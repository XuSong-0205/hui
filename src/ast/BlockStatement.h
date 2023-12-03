#pragma once
#ifndef BLOCKSTATEMENT_H
#define BLOCKSTATEMENT_H

#include <vector>
#include <memory>
#include "Statement.h"
#include "Token.h"

namespace hui {

class BlockStatement : public Statement
{
public:
	std::vector<std::unique_ptr<Statement>> m_statements;

public:
	using Statement::Statement;

public:
	std::string to_string() override
	{
		std::string str;

		str += "{\n";
		for (auto&& stmt : m_statements)
		{
			str += stmt->to_string() + "\n";
		}
		str += "}";

		return str;
	}
};

}	// namespace hui

#endif // !BLOCKSTATEMENT_H
