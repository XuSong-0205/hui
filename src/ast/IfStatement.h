#pragma once
#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H

#include "Expression.h"
#include "Statement.h"
#include "BlockStatement.h"
#include <memory>
#include <string>


namespace hui {

class IfStatement : public Statement
{
public:
    std::vector<std::unique_ptr<Expression>> m_conditions;
    std::vector<std::unique_ptr<BlockStatement>> m_consequences;
    std::unique_ptr<BlockStatement> m_alternative;

public:
	using Statement::Statement;

public:
    std::string to_string() override
    {
        std::string str;

        str += "if (";
        str += m_conditions[0]->to_string();
        str += ") ";
        str += m_consequences[0]->to_string() + " ";

        for (size_t i = 1; i < m_conditions.size(); ++i)
        {
            str += "else if (";
            str += m_conditions[i]->to_string();
            str += ") ";
            str += m_consequences[i]->to_string() + " ";
        }

        if (m_alternative)
        {
            str += "else ";
            str += m_alternative->to_string();
        }
        
        return str;
    }
};

}	// namespace hui

#endif // !IFSTATEMENT_H
