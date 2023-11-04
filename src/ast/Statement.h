#pragma once
#ifndef STATEMENT_H
#define STATEMENT_H

#include "Node.h"

namespace hui {

class Statement : public Node
{
protected:
	std::unique_ptr<Token> m_token;

public:
	explicit Statement(const Token& token)
		: m_token(std::make_unique<Token>(token)) { }
	explicit Statement(std::unique_ptr<Token> token)
		: m_token(std::move(token)) { }

	virtual ~Statement() = default;

public:
	virtual std::string token_literal() override { return m_token->get_literal(); }
	virtual std::string to_string() = 0;
};

}	// namespace hui

#endif	// STATEMENT_H