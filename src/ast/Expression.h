#pragma once
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Node.h"

namespace hui {

class Expression : public Node
{
protected:
	std::unique_ptr<Token> m_token;

public:
	explicit Expression(const Token& token)
		: m_token(std::make_unique<Token>(token)) { }
	explicit Expression(std::unique_ptr<Token> token)
		: m_token(std::move(token)) { }

	virtual ~Expression() = default;

public:
	virtual std::string token_literal() override { return m_token->get_literal(); }
	virtual std::string to_string() override { return ""; }
};

}	// namespace hui

#endif	// EXPRESSION_H