#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <map>
#include <string>
#include <string_view>
#include <iostream>
#include "TokenType.h"


namespace hui {

using token::TOKEN_TYPE;

class Token 
{
private:
	static const std::map<std::string_view, TOKEN_TYPE> TOKEN_KEY_WORDS;


private:
	TOKEN_TYPE m_type;
	std::string m_literal;

public:
	Token()
		: m_type(TOKEN_TYPE::EOF_) { }
	Token(TOKEN_TYPE token_type, std::string_view str)
		: m_type(token_type), m_literal(str.data(), str.size()) { }
	Token(TOKEN_TYPE token_type, const std::string& str)
		: m_type(token_type), m_literal(str) { }

public:
	TOKEN_TYPE get_type() const { return m_type; }
	const std::string get_literal() const { return m_literal; }

	friend std::ostream& operator<<(std::ostream& os, const Token& token);
	static std::string_view token_type_value(TOKEN_TYPE type);
	static TOKEN_TYPE lookup_ident(std::string_view ident);
};


}	// namespace hui



#endif	// TOKEN_H