#pragma once
#ifndef CALLEXPRESSION_H
#define CALLEXPRESSION_H

#include <memory>
#include <vector>
#include <string>
#include "Expression.h"


namespace hui {

class CallExpression : public Expression
{
public:
	std::unique_ptr<Expression> m_function;
	std::unique_ptr<std::vector<std::unique_ptr<Expression>>> m_arguments;

public:
	using Expression::Expression;

public:
	std::string to_string() override
	{
		std::string str;
		str += m_function->to_string();
		str += "(";

		auto&& args = *m_arguments;
		if (args.size() > 0)
		{
			str += args[0]->to_string();
		}

		for (size_t i = 1; i < args.size(); ++i)
		{
			str += ", ";
			str += args[i]->to_string();
		}

		str += ")";
		return str;
	}

};

}	// namespace hui

#endif // !CALLEXPRESSION_H
