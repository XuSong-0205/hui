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
	std::unique_ptr<Token> m_token;
	std::vector<std::unique_ptr<Statement>> m_statements;

public:
	BlockStatement(const Token& token)
		: m_token(std::make_unique<Token>(token)) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
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

#endif // !BLOCKSTATEMENT_H
