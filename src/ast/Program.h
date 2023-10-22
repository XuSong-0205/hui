#pragma once
#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <memory>

#include "Node.h"
#include "Statement.h"


namespace hui {

class Program : public Node 
{
public:
	std::vector<std::unique_ptr<Statement>> m_statements;

public:
	std::string token_literal() override
	{
		return m_statements.empty() ? "" : m_statements[0]->token_literal();
	}

	std::string to_string() override
	{
		std::string str;

		for (auto&& stmt : m_statements)
		{
			str += stmt->to_string();
		}

		return str;
	}

};

}	// namespace hui

#endif // !PROGRAM_H
