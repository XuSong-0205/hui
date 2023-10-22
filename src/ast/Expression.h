#pragma once
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Node.h"

namespace hui {

class Expression : public Node
{
public:
	virtual ~Expression() = default;

public:
	virtual std::string token_literal() override { return ""; }
	virtual std::string to_string() override { return ""; }
};

}	// namespace hui

#endif	// EXPRESSION_H