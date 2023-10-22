#pragma once
#ifndef STATEMENT_H
#define STATEMENT_H

#include "Node.h"

namespace hui {

class Statement : public Node
{
public:
	virtual ~Statement() = default;

public:
	virtual std::string token_literal() = 0;
	virtual std::string to_string() = 0;
};

}	// namespace hui

#endif	// STATEMENT_H