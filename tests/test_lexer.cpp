#include "catch.hpp"

#include "TokenType.h"
#include "Lexer.h"

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <tuple>


TEST_CASE("lexer next_token test", "[lexer]") {
	std::string_view input = R"(
	var five = 5;
	const ten = 10;
	
	var add = func(x, y) {
		return x + y;
	}
	
	var ans = add(five, ten);
	print(ans);

	for (var i = 0; i < ten; i += 1) {
		if (i % 2 == 0) {
			print("i = ", i, "\n");
		}
	}

	// ¸÷¸öÔËËã·û²âÊÔ
	var a = !false;
	var b = ~233;
	var c = 1 + 2 - 3 * 4 / 5 % 6;
	var d = 1 & 2 ^ 3 | 4;
	var e = 1 << 2 | 3 >> 4;
	var f = 1 < 2 && 3 > 4 || 5 <= 6 && 7 >= 8;
	var g = 1 != 2 || 3 == 4;
	c += 1;
	d -= 2;
	e *= 3;
	f /= 4;
	g %= 5;
	c &= 6;
	d ^= 7;
	e |= 8;
	f <<= 9;
	g >>= 10;
	
	func test() {
		var arr = [(1 + 2) * 3, 4, 5, 3.14, .233e-2, "hui"];
		const n = len(arr);
		for (var i = 0; i < n; i += 1) {
			if (i == 0) {
				print(arr[i]);
			} else {
				print(", ", arr[i]);
			}
			
			continue;
			break;
		}

		return n;
	}

)";

	using hui::token::TOKEN_TYPE;
	std::tuple<TOKEN_TYPE, std::string_view> tokens[] = {
		{TOKEN_TYPE::VAR, "var"},
		{TOKEN_TYPE::IDENT, "five"},
		{TOKEN_TYPE::ASSIGN, "="},
		{TOKEN_TYPE::INT, "5"},
		{TOKEN_TYPE::SEMICOLON, ";"},

		{TOKEN_TYPE::CONST, "const"},
		{TOKEN_TYPE::IDENT, "ten"},
		{TOKEN_TYPE::ASSIGN, "="},
		{TOKEN_TYPE::INT, "10"},
		{TOKEN_TYPE::SEMICOLON, ";"},

		{TOKEN_TYPE::VAR, "var"},
		{TOKEN_TYPE::IDENT, "add"},
		{TOKEN_TYPE::ASSIGN, "="},
		{TOKEN_TYPE::FUNC, "func"},
		{TOKEN_TYPE::LPAREN, "("},
		{TOKEN_TYPE::IDENT, "x"},
		{TOKEN_TYPE::COMMA, ","},
		{TOKEN_TYPE::IDENT, "y"},
		{TOKEN_TYPE::RPAREN, ")"},
		{TOKEN_TYPE::LBRACE, "{"},
		{TOKEN_TYPE::RETURN, "return"},
		{TOKEN_TYPE::IDENT, "x"},
		{TOKEN_TYPE::ADD, "+"},
		{TOKEN_TYPE::IDENT, "y"},
		{TOKEN_TYPE::SEMICOLON, ";"},
		{TOKEN_TYPE::RBRACE, "}"},

		{TOKEN_TYPE::VAR, "var"},
		{TOKEN_TYPE::IDENT, "ans"},
		{TOKEN_TYPE::ASSIGN, "="},
		{TOKEN_TYPE::IDENT, "add"},
		{TOKEN_TYPE::LPAREN, "("},
		{TOKEN_TYPE::IDENT, "five"},
		{TOKEN_TYPE::COMMA, ","},
		{TOKEN_TYPE::IDENT, "ten"},
		{TOKEN_TYPE::RPAREN, ")"},
		{TOKEN_TYPE::SEMICOLON, ";"},

		{TOKEN_TYPE::IDENT, "print"},
		{TOKEN_TYPE::LPAREN, "("},
		{TOKEN_TYPE::IDENT, "ans"},
		{TOKEN_TYPE::RPAREN, ")"},
		{TOKEN_TYPE::SEMICOLON, ";"},

		{TOKEN_TYPE::FOR, "for"},
		{TOKEN_TYPE::LPAREN, "("},
		{TOKEN_TYPE::VAR, "var"},
		{TOKEN_TYPE::IDENT, "i"},
		{TOKEN_TYPE::ASSIGN, "="},
		{TOKEN_TYPE::INT, "0"},
		{TOKEN_TYPE::SEMICOLON, ";"},
		{TOKEN_TYPE::IDENT, "i"},
		{TOKEN_TYPE::LT, "<"},
		{TOKEN_TYPE::IDENT, "ten"},
		{TOKEN_TYPE::SEMICOLON, ";"},
		{TOKEN_TYPE::IDENT, "i"},
		{TOKEN_TYPE::ADD_ASSIGN, "+="},
		{TOKEN_TYPE::INT, "1"},
		{TOKEN_TYPE::RPAREN, ")"},
		{TOKEN_TYPE::LBRACE, "{"},
		{TOKEN_TYPE::IF, "if"},
		{TOKEN_TYPE::LPAREN, "("},
		{TOKEN_TYPE::IDENT, "i"},
		{TOKEN_TYPE::REM, "%"},
		{TOKEN_TYPE::INT, "2"},
		{TOKEN_TYPE::EQ, "=="},
		{TOKEN_TYPE::INT, "0"},
		{TOKEN_TYPE::RPAREN, ")"},
		{TOKEN_TYPE::LBRACE, "{"},
		{TOKEN_TYPE::IDENT, "print"},
		{TOKEN_TYPE::LPAREN, "("},
		{TOKEN_TYPE::STRING, "i = "},
		{TOKEN_TYPE::COMMA, ","},
		{TOKEN_TYPE::IDENT, "i"},
		{TOKEN_TYPE::COMMA, ","},
		{TOKEN_TYPE::STRING, "\n"},
		{TOKEN_TYPE::RPAREN, ")"},
		{TOKEN_TYPE::SEMICOLON, ";"},
		{TOKEN_TYPE::RBRACE, "}"},
		{TOKEN_TYPE::RBRACE, "}"},

		{TOKEN_TYPE::VAR, "var"},
		{TOKEN_TYPE::IDENT, "a"},
		{TOKEN_TYPE::ASSIGN, "="},
		{TOKEN_TYPE::NOT, "!"},
		{TOKEN_TYPE::FALSE, "false"},
		{TOKEN_TYPE::SEMICOLON, ";"},

		{TOKEN_TYPE::VAR, "var"},
		{TOKEN_TYPE::IDENT, "b"},
		{TOKEN_TYPE::ASSIGN, "="},
		{TOKEN_TYPE::NEGATION, "~"},
		{TOKEN_TYPE::INT, "233"},
		{TOKEN_TYPE::SEMICOLON, ";"},

		{TOKEN_TYPE::VAR, "var"},
		{TOKEN_TYPE::IDENT, "c"},
		{TOKEN_TYPE::ASSIGN, "="},
		{TOKEN_TYPE::INT, "1"},
		{TOKEN_TYPE::ADD, "+"},
		{TOKEN_TYPE::INT, "2"},
		{TOKEN_TYPE::SUB, "-"},
		{TOKEN_TYPE::INT, "3"},
		{TOKEN_TYPE::MUL, "*"},
		{TOKEN_TYPE::INT, "4"},
		{TOKEN_TYPE::DIV, "/"},
		{TOKEN_TYPE::INT, "5" },
		{TOKEN_TYPE::REM, "%" },
		{TOKEN_TYPE::INT, "6" },
		{TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::VAR, "var" },
		{ TOKEN_TYPE::IDENT, "d" },
		{ TOKEN_TYPE::ASSIGN, "=" },
		{ TOKEN_TYPE::INT, "1" },
		{ TOKEN_TYPE::BIT_AND, "&" },
		{ TOKEN_TYPE::INT, "2" },
		{ TOKEN_TYPE::XOR, "^" },
		{ TOKEN_TYPE::INT, "3" },
		{ TOKEN_TYPE::BIT_OR, "|" },
		{ TOKEN_TYPE::INT, "4" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::VAR, "var" },
		{ TOKEN_TYPE::IDENT, "e" },
		{ TOKEN_TYPE::ASSIGN, "=" },
		{ TOKEN_TYPE::INT, "1" },
		{ TOKEN_TYPE::LEFT_SHIFT, "<<" },
		{ TOKEN_TYPE::INT, "2" },
		{ TOKEN_TYPE::BIT_OR, "|" },
		{ TOKEN_TYPE::INT, "3" },
		{ TOKEN_TYPE::RIGHT_SHIFT, ">>" },
		{ TOKEN_TYPE::INT, "4" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::VAR, "var" },
		{ TOKEN_TYPE::IDENT, "f" },
		{ TOKEN_TYPE::ASSIGN, "=" },
		{ TOKEN_TYPE::INT, "1" },
		{ TOKEN_TYPE::LT, "<" },
		{ TOKEN_TYPE::INT, "2" },
		{ TOKEN_TYPE::AND, "&&" },
		{ TOKEN_TYPE::INT, "3" },
		{ TOKEN_TYPE::GT, ">" },
		{ TOKEN_TYPE::INT, "4" },
		{ TOKEN_TYPE::OR, "||" },
		{ TOKEN_TYPE::INT, "5" },
		{ TOKEN_TYPE::LT_EQ, "<=" },
		{ TOKEN_TYPE::INT, "6" },
		{ TOKEN_TYPE::AND, "&&" },
		{ TOKEN_TYPE::INT, "7" },
		{ TOKEN_TYPE::GT_EQ, ">=" },
		{ TOKEN_TYPE::INT, "8" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::VAR, "var" },
		{ TOKEN_TYPE::IDENT, "g" },
		{ TOKEN_TYPE::ASSIGN, "=" },
		{ TOKEN_TYPE::INT, "1" },
		{ TOKEN_TYPE::NOT_EQ, "!=" },
		{ TOKEN_TYPE::INT, "2" },
		{ TOKEN_TYPE::OR, "||" },
		{ TOKEN_TYPE::INT, "3" },
		{ TOKEN_TYPE::EQ, "==" },
		{ TOKEN_TYPE::INT, "4" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::IDENT, "c" },
		{ TOKEN_TYPE::ADD_ASSIGN, "+=" },
		{ TOKEN_TYPE::INT, "1" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::IDENT, "d" },
		{ TOKEN_TYPE::SUB_ASSING, "-=" },
		{ TOKEN_TYPE::INT, "2" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::IDENT, "e" },
		{ TOKEN_TYPE::MUL_ASSIGN, "*=" },
		{ TOKEN_TYPE::INT, "3" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::IDENT, "f" },
		{ TOKEN_TYPE::DIV_ASSIGN, "/=" },
		{ TOKEN_TYPE::INT, "4" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::IDENT, "g" },
		{ TOKEN_TYPE::REM_ASSIGN, "%=" },
		{ TOKEN_TYPE::INT, "5" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::IDENT, "c" },
		{ TOKEN_TYPE::BIT_AND_ASSIGN, "&=" },
		{ TOKEN_TYPE::INT, "6" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::IDENT, "d" },
		{ TOKEN_TYPE::XOR_ASSIGN, "^=" },
		{ TOKEN_TYPE::INT, "7" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::IDENT, "e" },
		{ TOKEN_TYPE::BIT_OR_ASSIGN, "|=" },
		{ TOKEN_TYPE::INT, "8" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::IDENT, "f" },
		{ TOKEN_TYPE::LS_ASSIGN, "<<=" },
		{ TOKEN_TYPE::INT, "9" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::IDENT, "g" },
		{ TOKEN_TYPE::RS_ASSIGN, ">>=" },
		{ TOKEN_TYPE::INT, "10" },
		{ TOKEN_TYPE::SEMICOLON, ";" },

		{ TOKEN_TYPE::FUNC, "func" },
		{ TOKEN_TYPE::IDENT, "test" },
		{ TOKEN_TYPE::LPAREN, "(" },
		{ TOKEN_TYPE::RPAREN, ")" },
		{ TOKEN_TYPE::LBRACE, "{" },
		{ TOKEN_TYPE::VAR, "var" },
		{ TOKEN_TYPE::IDENT, "arr" },
		{ TOKEN_TYPE::ASSIGN, "=" },
		{ TOKEN_TYPE::LBRACKET, "[" },
		{ TOKEN_TYPE::LPAREN, "(" },
		{ TOKEN_TYPE::INT, "1" },
		{ TOKEN_TYPE::ADD, "+" },
		{ TOKEN_TYPE::INT, "2" },
		{ TOKEN_TYPE::RPAREN, ")" },
		{ TOKEN_TYPE::MUL, "*" },
		{ TOKEN_TYPE::INT, "3" },
		{ TOKEN_TYPE::COMMA, "," },
		{ TOKEN_TYPE::INT, "4" },
		{ TOKEN_TYPE::COMMA, "," },
		{ TOKEN_TYPE::INT, "5" },
		{ TOKEN_TYPE::COMMA, "," },
		{ TOKEN_TYPE::FLOAT, "3.14" },
		{ TOKEN_TYPE::COMMA, "," },
		{ TOKEN_TYPE::FLOAT, ".233e-2" },
		{ TOKEN_TYPE::COMMA, "," },
		{ TOKEN_TYPE::STRING, "hui" },
		{ TOKEN_TYPE::RBRACKET, "]" },
		{ TOKEN_TYPE::SEMICOLON, ";" },
		{ TOKEN_TYPE::CONST, "const" },
		{ TOKEN_TYPE::IDENT, "n" },
		{ TOKEN_TYPE::ASSIGN, "=" },
		{ TOKEN_TYPE::IDENT, "len" },
		{ TOKEN_TYPE::LPAREN, "(" },
		{ TOKEN_TYPE::IDENT, "arr" },
		{ TOKEN_TYPE::RPAREN, ")" },
		{ TOKEN_TYPE::SEMICOLON, ";" },
		{ TOKEN_TYPE::FOR, "for" },
		{ TOKEN_TYPE::LPAREN, "(" },
		{ TOKEN_TYPE::VAR, "var" },
		{ TOKEN_TYPE::IDENT, "i" },
		{ TOKEN_TYPE::ASSIGN, "=" },
		{ TOKEN_TYPE::INT, "0" },
		{ TOKEN_TYPE::SEMICOLON, ";" },
		{ TOKEN_TYPE::IDENT, "i" },
		{ TOKEN_TYPE::LT, "<" },
		{ TOKEN_TYPE::IDENT, "n" },
		{ TOKEN_TYPE::SEMICOLON, ";" },
		{ TOKEN_TYPE::IDENT, "i" },
		{ TOKEN_TYPE::ADD_ASSIGN, "+=" },
		{ TOKEN_TYPE::INT, "1" },
		{ TOKEN_TYPE::RPAREN, ")" },
		{ TOKEN_TYPE::LBRACE, "{" },
		{ TOKEN_TYPE::IF, "if" },
		{ TOKEN_TYPE::LPAREN, "(" },
		{ TOKEN_TYPE::IDENT, "i" },
		{ TOKEN_TYPE::EQ, "==" },
		{ TOKEN_TYPE::INT, "0" },
		{ TOKEN_TYPE::RPAREN, ")" },
		{ TOKEN_TYPE::LBRACE, "{" },
		{ TOKEN_TYPE::IDENT, "print" },
		{ TOKEN_TYPE::LPAREN, "(" },
		{ TOKEN_TYPE::IDENT, "arr" },
		{ TOKEN_TYPE::LBRACKET, "[" },
		{ TOKEN_TYPE::IDENT, "i" },
		{ TOKEN_TYPE::RBRACKET, "]" },
		{ TOKEN_TYPE::RPAREN, ")" },
		{ TOKEN_TYPE::SEMICOLON, ";" },
		{ TOKEN_TYPE::RBRACE, "}" },
		{ TOKEN_TYPE::ELSE, "else" },
		{ TOKEN_TYPE::LBRACE, "{" },
		{ TOKEN_TYPE::IDENT, "print" },
		{ TOKEN_TYPE::LPAREN, "(" },
		{ TOKEN_TYPE::STRING, ", " },
		{ TOKEN_TYPE::COMMA, "," },
		{ TOKEN_TYPE::IDENT, "arr" },
		{ TOKEN_TYPE::LBRACKET, "[" },
		{ TOKEN_TYPE::IDENT, "i" },
		{ TOKEN_TYPE::RBRACKET, "]" },
		{ TOKEN_TYPE::RPAREN, ")" },
		{ TOKEN_TYPE::SEMICOLON, ";" },
		{ TOKEN_TYPE::RBRACE, "}" },
		{ TOKEN_TYPE::CONTINUE, "continue" },
		{ TOKEN_TYPE::SEMICOLON, ";" },
		{ TOKEN_TYPE::BREAK, "break" },
		{ TOKEN_TYPE::SEMICOLON, ";" },
		{ TOKEN_TYPE::RBRACE, "}" },
		{ TOKEN_TYPE::RETURN, "return" },
		{ TOKEN_TYPE::IDENT, "n" },
		{ TOKEN_TYPE::SEMICOLON, ";" },
		{ TOKEN_TYPE::RBRACE, "}" },

	};

	hui::Lexer lexer(input.data());

	for (auto [type, literal] : tokens)
	{
		auto token = lexer.next_token();

		//std::cout	<< "type: (" << hui::Token::token_type_value(token->get_type()) 
		//			<< ",  " << hui::Token::token_type_value(type) 
		//			<< "), literal: (" << token->get_literal() << ", " << literal << ")\n";

		REQUIRE(token->get_type() == type);
		REQUIRE(token->get_literal() == literal);
	}


}