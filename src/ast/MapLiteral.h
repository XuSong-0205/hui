#pragma once
#ifndef MAPLITERAL_H
#define MAPLITERAL_H

#include <memory>
#include <string>
#include <map>
#include "Token.h"
#include "Expression.h"

namespace hui {

class MapLiteral : public Expression
{
private:
	std::unique_ptr<std::map<std::shared_ptr<Expression>, std::shared_ptr<Expression>>> m_map;

public:
	MapLiteral(const Token& token, 
			   std::unique_ptr<std::map<std::shared_ptr<Expression>, std::shared_ptr<Expression>>> value)
		: Expression(std::make_unique<Token>(token)),
		  m_map(std::move(value)) { }

	MapLiteral(std::unique_ptr<Token> token, 
			   std::unique_ptr<std::map<std::shared_ptr<Expression>, std::shared_ptr<Expression>>> value)
		: Expression(std::move(token)),
		  m_map(std::move(value)) { }

public:
	std::string to_string() override { 
		std::string str;
		str += "{";

		auto it = m_map->begin();
		if (it != m_map->end())
		{
			str += it->first->to_string() + ":" + it->second->to_string();
		}

		while (++it != m_map->end())
		{
			str += ", ";
			str += it->first->to_string() + ": " + it->second->to_string();
		}

		str += "}";
		return str;
	}
};

}	// namespace hui

#endif // !MAPLITERAL_H
