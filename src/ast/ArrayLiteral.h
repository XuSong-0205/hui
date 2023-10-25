#pragma once
#ifndef ARRAYLITERAL_H
#define ARRAYLITERAL_H

#include <memory>
#include <vector>
#include <string>
#include "Token.h"
#include "Expression.h"

namespace hui {

class ArrayLiteral : public Expression
{
private:
	std::unique_ptr<Token> m_token;
	std::unique_ptr<std::vector<std::unique_ptr<Expression>>> m_elements;

public:
	ArrayLiteral(const Token& token, std::unique_ptr<std::vector<std::unique_ptr<Expression>>> value)
		: m_token(std::make_unique<Token>(token)),
		  m_elements(std::move(value)) { }

public:
	std::string token_literal() override { return m_token->get_literal(); }
	std::string to_string() override 
	{ 
		std::string str;
		str += "[";

		auto& elements = *m_elements;
		int size = static_cast<int>(elements.size());
		if (size > 0)
		{
			str += elements[0]->to_string();
		}

		for (int i = 1; i < size; ++i)
		{
			str += ", ";
			str += elements[i]->to_string();
		}

		str += "]";
		return str;
	}
};

}	// namespace hui

#endif // !ARRAYLITERAL_H
