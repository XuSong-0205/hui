#include "Parser.h"

namespace hui {

const std::map<TOKEN_TYPE, PRECEDENCE> OPER_PRECEDENCE{
	{TOKEN_TYPE::DOT, PRECEDENCE::DOT},

	{TOKEN_TYPE::NOT, PRECEDENCE::NOT},
	{TOKEN_TYPE::NEGATION, PRECEDENCE::NOT},

	{TOKEN_TYPE::MUL, PRECEDENCE::MUL},
	{TOKEN_TYPE::DIV, PRECEDENCE::MUL},
	{TOKEN_TYPE::REM, PRECEDENCE::MUL},

	{TOKEN_TYPE::ADD, PRECEDENCE::ADD},
	{TOKEN_TYPE::SUB, PRECEDENCE::ADD},

	{TOKEN_TYPE::LEFT_SHIFT, PRECEDENCE::LS},
	{TOKEN_TYPE::RIGHT_SHIFT, PRECEDENCE::LS},

	{TOKEN_TYPE::LT, PRECEDENCE::LT},
	{TOKEN_TYPE::LT_EQ, PRECEDENCE::LT},
	{TOKEN_TYPE::GT, PRECEDENCE::LT},
	{TOKEN_TYPE::GT_EQ, PRECEDENCE::LT},

	{TOKEN_TYPE::EQ, PRECEDENCE::EQ},
	{TOKEN_TYPE::NOT_EQ, PRECEDENCE::EQ},

	{TOKEN_TYPE::BIT_AND, PRECEDENCE::BIT_AND},

	{TOKEN_TYPE::XOR, PRECEDENCE::XOR},

	{TOKEN_TYPE::BIT_OR, PRECEDENCE::BIT_OR},

	{TOKEN_TYPE::AND, PRECEDENCE::AND},

	{TOKEN_TYPE::OR, PRECEDENCE::OR},

	{TOKEN_TYPE::ASSIGN, PRECEDENCE::ASSIGN},
	{TOKEN_TYPE::ADD_ASSIGN, PRECEDENCE::ASSIGN},
	{TOKEN_TYPE::SUB_ASSING, PRECEDENCE::ASSIGN},
	{TOKEN_TYPE::MUL_ASSIGN, PRECEDENCE::ASSIGN},
	{TOKEN_TYPE::DIV_ASSIGN, PRECEDENCE::ASSIGN},
	{TOKEN_TYPE::REM_ASSIGN, PRECEDENCE::ASSIGN},
	{TOKEN_TYPE::BIT_AND_ASSIGN, PRECEDENCE::ASSIGN},
	{TOKEN_TYPE::XOR_ASSIGN, PRECEDENCE::ASSIGN},
	{TOKEN_TYPE::BIT_OR_ASSIGN, PRECEDENCE::ASSIGN},
	{TOKEN_TYPE::LS_ASSIGN, PRECEDENCE::ASSIGN},
	{TOKEN_TYPE::RS_ASSIGN, PRECEDENCE::ASSIGN},

};

static PRECEDENCE get_oper_precedence(TOKEN_TYPE t1)
{
	auto it = OPER_PRECEDENCE.find(t1);
	if (it != OPER_PRECEDENCE.end()) {
		return it->second;
	}

	return PRECEDENCE::LOWEST;
}

static bool compare_oper_precedence(TOKEN_TYPE t1, TOKEN_TYPE t2)
{
	return get_oper_precedence(t1) < get_oper_precedence(t2);
}




Parser::Parser(const Lexer& lexer)
	: m_lexer(std::make_unique<Lexer>(lexer))
{
	init();
}

Parser::Parser(std::unique_ptr<Lexer> lexer)
	: m_lexer(std::move(lexer))
{
	init();
}

std::shared_ptr<Program> Parser::parse_program()
{
	auto program = std::make_shared<Program>();

	while (!curr_token_is(TOKEN_TYPE::EOF_))
	{
		if (auto stmt = parse_statement())
		{
			program->m_statements.push_back(std::move(stmt));
		}
		next_token();
	}

	return program;
}

const std::vector<std::string>& Parser::errors() const
{
	return m_errors;
}


void Parser::init()
{
	// todo



	next_token();
	next_token();
}

void Parser::next_token()
{
	m_curr_token = std::move(m_next_token);
	m_next_token = m_lexer->next_token();
}

bool Parser::curr_token_is(TOKEN_TYPE t) const
{
	return m_curr_token->get_type() == t;
}

bool Parser::next_token_is(TOKEN_TYPE t) const
{
	return m_next_token->get_type() == t;
}

bool Parser::expect_next(TOKEN_TYPE t)
{
	if (next_token_is(t))
	{
		next_token();
		return true;
	}
	else
	{
		next_error(t);
		return false;
	}
}

PRECEDENCE Parser::curr_precedence() const
{
	return get_oper_precedence(m_curr_token->get_type());
}

PRECEDENCE Parser::next_precedence() const
{
	return get_oper_precedence(m_next_token->get_type());
}

void Parser::next_error(TOKEN_TYPE t)
{
	std::string msg = "expected next token to be ";
				msg += Token::token_type_value(t);
				msg += ", got ";
				msg += Token::token_type_value(m_next_token->get_type());
				msg += " instead";
	m_errors.push_back(msg);
}

void Parser::no_prefix_parse_func_error(TOKEN_TYPE t)
{
	std::string msg = "no prefix parse function for ";
				msg += Token::token_type_value(t); 
				msg += " found";
	m_errors.push_back(msg);
}

std::unique_ptr<Statement> Parser::parse_statement()
{
	switch (m_curr_token->get_type())
	{
	case TOKEN_TYPE::VAR:
		return parse_var_statement();

	case TOKEN_TYPE::CONST:
		return parse_const_statement();

	case TOKEN_TYPE::IF:
		//return parse_if_statement();

	case TOKEN_TYPE::FOR:
		return parse_for_statement();

	case TOKEN_TYPE::RETURN:
		//return parse_return_statement();

	case TOKEN_TYPE::FUNC:
		return parse_function_statement();

	case TOKEN_TYPE::SEMICOLON:
		return nullptr;

	default:
		return parse_expression_statement();
	}
}

std::unique_ptr<VarStatement> Parser::parse_var_statement()
{
	auto stmt = std::make_unique<VarStatement>(*m_curr_token);

	if (!expect_next(TOKEN_TYPE::IDENT))
	{
		return nullptr;
	}

	stmt->m_name = std::make_unique<Identifier>(*m_curr_token, m_curr_token->get_literal());

	if (!expect_next(TOKEN_TYPE::ASSIGN))
	{
		return nullptr;
	}
	next_token();

	auto expr = parse_expression();
	if (!expr)
	{
		return nullptr;
	}

	stmt->m_value = std::move(expr);

	if (!expect_next(TOKEN_TYPE::SEMICOLON))
	{
		return nullptr;
	}

	return stmt;
}

std::unique_ptr<ConstStatement> Parser::parse_const_statement()
{
	auto var_stmt = parse_var_statement();

	auto const_stmt = std::make_unique<ConstStatement>(*var_stmt->m_token);
	const_stmt->m_name = std::move(var_stmt->m_name);
	const_stmt->m_value = std::move(var_stmt->m_value);

	return const_stmt;
}

//std::unique_ptr<IfStatement> Parser::parse_if_statement()
//{
//	return std::unique_ptr<IfStatement>();
//}

std::unique_ptr<ForStatement> Parser::parse_for_statement()
{
	auto stmt = std::unique_ptr<ForStatement>();

	if (!expect_next(TOKEN_TYPE::LPAREN))
	{
		return nullptr;
	}
	next_token();

	if (!curr_token_is(TOKEN_TYPE::VAR))
	{
		return nullptr;
	}

	stmt->m_loop_var = parse_var_statement();
	if (!stmt->m_loop_var)
	{
		return nullptr;
	}
	next_token();

	stmt->m_condition = parse_expression();
	if (!stmt->m_condition)
	{
		return nullptr;
	}
	next_token();
	next_token();

	stmt->m_next_step = parse_expression();
	if (!stmt->m_next_step)
	{
		return nullptr;
	}
	next_token();

	if (!curr_token_is(TOKEN_TYPE::RPAREN))
	{
		return nullptr;
	}
	next_token();

	stmt->m_body = parse_block_statement();
	

	return stmt;
}

//std::unique_ptr<Statement> Parser::parse_continue_statement()
//{
//	return std::unique_ptr<Statement>();
//}
//
//std::unique_ptr<Statement> Parser::parse_break_statement()
//{
//	return std::unique_ptr<Statement>();
//}

//std::unique_ptr<ReturnStatement> Parser::parse_return_statement()
//{
//	return std::unique_ptr<ReturnStatement>();
//}

std::unique_ptr<FunctionStatement> Parser::parse_function_statement()
{
	auto func = std::make_unique<FunctionStatement>(*m_curr_token);

	if (next_token_is(TOKEN_TYPE::IDENT))
	{
		next_token();
		if (auto name = parse_identifier())
		{
			func->m_name = std::unique_ptr<Identifier>(dynamic_cast<Identifier*>(name.release()));
		}
	}

	if (!expect_next(TOKEN_TYPE::LPAREN))
	{
		return nullptr;
	}

	func->m_parameters = parse_function_parameters();
	if (!func->m_parameters)
	{
		return nullptr;
	}

	if (!expect_next(TOKEN_TYPE::LBRACE))
	{
		return nullptr;
	}

	func->m_body = parse_block_statement();


	return func;
}

std::unique_ptr<ExpressionStatement> Parser::parse_expression_statement()
{
	auto stmt = std::make_unique<ExpressionStatement>(*m_curr_token);

	stmt->m_expression = parse_expression();
	if (!stmt->m_expression)
	{
		return nullptr;
	}

	//if (next_token_is(TOKEN_TYPE::SEMICOLON))
	//{
	//	next_token();
	//}
	if (!expect_next(TOKEN_TYPE::LBRACE))
	{
		return nullptr;
	}

	return stmt;
}

std::unique_ptr<BlockStatement> Parser::parse_block_statement()
{
	auto block = std::make_unique<BlockStatement>(*m_curr_token);
	next_token();

	while (!curr_token_is(TOKEN_TYPE::RBRACE) &&
		   !curr_token_is(TOKEN_TYPE::EOF_))
	{
		if (auto stmt = parse_statement())
		{
			block->m_statements.push_back(std::move(stmt));
		}
		next_token();
	}

	return block;
}



std::unique_ptr<std::vector<std::unique_ptr<Identifier>>> Parser::parse_function_parameters()
{
	auto identifiers = std::make_unique<std::vector<std::unique_ptr<Identifier>>>();

	if (next_token_is(TOKEN_TYPE::RPAREN))
	{
		next_token();
		return identifiers;
	}

	next_token();
	identifiers->push_back(std::make_unique<Identifier>(*m_curr_token, m_curr_token->get_literal()));

	while (next_token_is(TOKEN_TYPE::COMMA))
	{
		next_token();
		next_token();

		identifiers->push_back(std::make_unique<Identifier>(*m_curr_token, m_curr_token->get_literal()));
	}

	if (!expect_next(TOKEN_TYPE::RPAREN))
	{
		return nullptr;
	}

	return identifiers;
}

}