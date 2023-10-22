#pragma once
#ifndef NODE_H
#define NODE_H

#include <string>

namespace hui {

class Node 
{
public:
	virtual ~Node() = default;

public:
	virtual std::string token_literal() = 0;
	virtual std::string to_string() = 0;
};

}	// namespace hui

#endif	// NODE_H