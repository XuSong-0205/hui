#pragma once
#ifndef INDEXEXPRESSION_H
#define INDEXEXPRESSION_H

#include <memory>
#include <string>
#include "Expression.h"


namespace hui {

class IndexExpression : public Expression
{
public:
	std::unique_ptr<Expression> m_left;
	std::unique_ptr<Expression> m_index;

public:
	using Expression::Expression;

public:
	std::string to_string() override
	{
		std::string str;

		str += m_left->to_string();
		str += "[";
		str += m_index->to_string();
		str += "]";

		return str;
	}

};

}	// namespace hui

#endif // !INDEXEXPRESSION_H
