#include "Lexer.h"

namespace hui {

Lexer::Lexer(const std::string& str)
	: m_input(str)
{
	read_char();
}


constexpr bool Lexer::is_whitespace(char ch)
{
	return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

constexpr bool Lexer::is_dight(char ch)
{
	return '0' <= ch && ch <= '9';
}

constexpr bool Lexer::is_letter(char ch)
{
	return ch == '_' || ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

constexpr bool Lexer::is_ident(char ch)
{
	return is_letter(ch) || is_dight(ch);
}


std::unique_ptr<Token> Lexer::next_token()
{
	skip_whitespace();

	switch (m_ch)
	{
	case '.':
		if (is_dight(next_char()))
		{
			return std::make_unique<Token>(TOKEN_TYPE::FLOAT, read_dot_number());
		}
		return std::make_unique<Token>(TOKEN_TYPE::DOT, capture_char());

	case '!':
		if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::NOT_EQ, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::NOT, capture_char());

	case '~':
		return std::make_unique<Token>(TOKEN_TYPE::NEGATION, capture_char());

	case '*':
		if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::MUL_ASSIGN, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::MUL, capture_char());
		
	case '/':
		if (next_char() == '/')
		{
			read_annotation();
			return next_token();
		}
		else if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::DIV_ASSIGN, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::DIV, capture_char());

	case '%':
		if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::REM_ASSIGN, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::REM, capture_char());

	case '+':
		if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::ADD_ASSIGN, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::ADD, capture_char());

	case '-':
		if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::SUB_ASSING, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::SUB, capture_char());

	case '<':
		if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::LT_EQ, capture_char(2));
		}
		else if (next_char() == '<')
		{
			if (next_char(2) == '=')
			{
				return std::make_unique<Token>(TOKEN_TYPE::LS_ASSIGN, capture_char(3));
			}
			return std::make_unique<Token>(TOKEN_TYPE::LEFT_SHIFT, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::LT, capture_char());

	case '>':
		if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::GT_EQ, capture_char(2));
		}
		else if (next_char() == '>')
		{
			if (next_char(2) == '=')
			{
				return std::make_unique<Token>(TOKEN_TYPE::RS_ASSIGN, capture_char(3));
			}
			return std::make_unique<Token>(TOKEN_TYPE::RIGHT_SHIFT, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::GT, capture_char());

	case '=':
		if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::EQ, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::ASSIGN, capture_char());

	case '&':
		if (next_char() == '&')
		{
			return std::make_unique<Token>(TOKEN_TYPE::AND, capture_char(2));
		}
		else if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::BIT_AND_ASSIGN, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::BIT_AND, capture_char());

	case '^':
		if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::XOR_ASSIGN, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::XOR, capture_char());

	case '|':
		if (next_char() == '|')
		{
			return std::make_unique<Token>(TOKEN_TYPE::OR, capture_char(2));
		}
		else if (next_char() == '=')
		{
			return std::make_unique<Token>(TOKEN_TYPE::BIT_OR_ASSIGN, capture_char(2));
		}
		return std::make_unique<Token>(TOKEN_TYPE::BIT_OR, capture_char());

	case ',':
		return std::make_unique<Token>(TOKEN_TYPE::COMMA, capture_char());

	case ';':
		return std::make_unique<Token>(TOKEN_TYPE::SEMICOLON, capture_char());

	case '?':
		return std::make_unique<Token>(TOKEN_TYPE::QUES_MARK, capture_char());

	case ':':
		return std::make_unique<Token>(TOKEN_TYPE::COLON, capture_char());

	case '(':
		return std::make_unique<Token>(TOKEN_TYPE::LPAREN, capture_char());

	case ')':
		return std::make_unique<Token>(TOKEN_TYPE::RPAREN, capture_char());

	case '[':
		return std::make_unique<Token>(TOKEN_TYPE::LBRACKET, capture_char());

	case ']':
		return std::make_unique<Token>(TOKEN_TYPE::RBRACKET, capture_char());

	case '{':
		return std::make_unique<Token>(TOKEN_TYPE::LBRACE, capture_char());

	case '}':
		return std::make_unique<Token>(TOKEN_TYPE::RBRACE, capture_char());

	case '"':
		{
			std::string str = read_string();
			read_char();
			return std::make_unique<Token>(TOKEN_TYPE::STRING, str);
		}

	case 0:
		return std::make_unique<Token>(TOKEN_TYPE::EOF_, std::string_view());

	default:
		if (is_letter(m_ch)) 
		{
			std::string_view literal = read_identifier();
			return std::make_unique<Token>(Token::lookup_ident(literal), literal);
		}
		else if (is_dight(m_ch))
		{
			auto [is_float, literal] = read_number();
			return is_float ? std::make_unique<Token>(TOKEN_TYPE::FLOAT, literal)
							: std::make_unique<Token>(TOKEN_TYPE::INT, literal);
		}
		else
		{
			return std::make_unique<Token>(TOKEN_TYPE::ILLEGAL, capture_char());
		}
		break;
	}


	return std::make_unique<Token>();
}


void Lexer::read_char()
{
	if (m_next_pos >= m_input.size())
	{
		m_ch = 0;
	}
	else
	{
		m_ch = m_input[m_next_pos];
	}

	m_curr_pos = m_next_pos++;
}

char Lexer::next_char()
{
	if (m_next_pos >= m_input.size())
	{
		return 0;
	}

	return m_input[m_next_pos];
}

char Lexer::next_char(int num)
{
	if (m_curr_pos + num >= m_input.size() ||
		m_curr_pos + num < 0)
	{
		return 0;
	}

	return m_input[m_curr_pos + num];
}

void Lexer::skip_whitespace()
{
	while (is_whitespace(m_ch)) {
		read_char();
	}
}


const char* Lexer::get_curr_pos_str()
{
	return m_input.c_str() + m_curr_pos;
}

std::string_view Lexer::capture_char(int num)
{
	auto str = get_curr_pos_str();

	m_curr_pos += num;
	m_next_pos = m_curr_pos + 1;
	if (m_curr_pos >= m_input.size())
	{
		m_ch = 0;
	}
	else
	{
		m_ch = m_input[m_curr_pos];
	}

	return std::string_view(str, num);
}

std::string_view Lexer::read_identifier()
{
	auto str = get_curr_pos_str();
	int count = 0;

	if (is_letter(m_ch))
	{
		read_char();
		++count;
	}

	while (is_ident(m_ch))
	{
		read_char();
		++count;
	}

	return std::string_view(str, count);
}

std::string_view Lexer::read_dot_number()
{
	auto str = get_curr_pos_str();
	int beg_pos = m_curr_pos;

	read_char();
	read_integer();

	if (m_ch == 'e' || m_ch == 'E')
	{
		read_char();
		if (m_ch == '-')
		{
			read_char();
		}
		read_integer();
	}

	int count = m_curr_pos - beg_pos;
	return std::string_view(str, count);
}

std::pair<bool, std::string_view> Lexer::read_number()
{
	auto str = get_curr_pos_str();
	bool is_float = false;
	int beg_pos = m_curr_pos;

	read_integer();
	if (m_ch == '.')
	{
		read_char();
		read_integer();
		is_float = true;
	}

	if (m_ch == 'e' || m_ch == 'E')
	{
		read_char();
		if (m_ch == '-')
		{
			read_char();
		}
		read_integer();
		is_float = true;
	}

	int count = m_curr_pos - beg_pos;
	return std::pair<bool, std::string_view>(is_float, std::string_view(str, count));
}

std::string_view Lexer::read_integer()
{
	auto str = get_curr_pos_str();

	int count = 0;
	while (is_dight(m_ch))
	{
		read_char();
		++count;
	}

	return std::string_view(str, count);
}

std::string Lexer::read_string()
{
	std::string str;

	while (true)
	{
		read_char();
		switch (m_ch)
		{
		case '"':
		case 0:
			return str;

		case '\\':
			switch (next_char())
			{
			case 'a':
				read_char(); str += '\a'; break;

			case 'b':
				read_char(); str += '\b'; break;

			case 'f':
				read_char(); str += '\f'; break;

			case 'n':
				read_char(); str += '\n'; break;

			case 'r':
				read_char(); str += '\r'; break;

			case 't':
				read_char(); str += '\t'; break;

			case 'v':
				read_char(); str += '\v'; break;

			case '\\':
				read_char(); str += '\\'; break;

			case '\'':
				read_char(); str += '\''; break;

			case '\"':
				read_char(); str += '\"'; break;

			default:
				str += m_ch; break;
			}
			break;

		default:
			str += m_ch; 
			break;
		}

	}

	return str;
}

void Lexer::read_annotation()
{
	read_char();
	read_char();

	while (m_ch != '\n')
	{
		read_char();
	}
}


}	// namespace hui