#pragma once
#ifndef LEXER_H
#define LEXER_H

#include <memory>
#include <string>
#include "Token.h"


namespace hui {

class Lexer 
{
private:
	std::string m_input;
	int m_curr_pos = 0;
	int m_next_pos = 0;
	char m_ch = 0;

public:
	Lexer(const std::string& str);

public:
	constexpr static bool is_whitespace(char ch);
	constexpr static bool is_dight(char ch);
	constexpr static bool is_letter(char ch);
	constexpr static bool is_ident(char ch);

public:
	std::unique_ptr<Token> next_token();

private:
	void read_char();
	char next_char();
	char next_char(int num);
	void skip_whitespace();

	const char* get_curr_pos_str();
	std::string_view capture_char(int num = 1);
	std::string_view read_identifier();
	std::string_view read_dot_number();
	std::pair<bool, std::string_view> read_number();
	std::string_view read_integer();
	std::string read_string();
	void read_annotation();
};




}	// namespace hui

#endif	// LEXER_H