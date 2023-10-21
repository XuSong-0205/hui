#include "Token.h"


namespace hui {

const std::map<std::string_view, TOKEN_TYPE> Token::TOKEN_KEY_WORDS{
	{"var", TOKEN_TYPE::VAR}, 
	{"const", TOKEN_TYPE::CONST},
	{"false", TOKEN_TYPE::FALSE},
	{"true", TOKEN_TYPE::TRUE},
	{"func", TOKEN_TYPE::FUNC}, 
	{"if", TOKEN_TYPE::IF},
	{"else", TOKEN_TYPE::ELSE}, 
	{"for", TOKEN_TYPE::FOR},
	{"continue", TOKEN_TYPE::CONTINUE}, 
	{"break", TOKEN_TYPE::BREAK},
	{"return", TOKEN_TYPE::RETURN}, 
};


std::ostream& operator<<(std::ostream& os, const Token& token)
{
	os << "{ ";
	os << "type: " << Token::token_type_value(token.get_type())
	   << ", literral: " << token.get_literal();
	os << " }";
	return os;
}

std::string_view Token::token_type_value(TOKEN_TYPE type)
{
	return token::TOKEN_TYPE_VALUE[static_cast<int>(type)];
}

TOKEN_TYPE Token::lookup_ident(std::string_view ident)
{
	if (auto it = TOKEN_KEY_WORDS.find(ident); it != TOKEN_KEY_WORDS.end()) {
		return it->second;
	}
	return TOKEN_TYPE::IDENT;
}


}	// namespace hui