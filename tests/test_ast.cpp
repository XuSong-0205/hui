#include <iostream>
#include <memory>
#include <string>
#include <string_view>

#include "catch.hpp"
#include "ArrayLiteral.h"
#include "AssignExpression.h"
#include "BlockStatement.h"
#include "BooleanLiteral.h"
#include "CallExpression.h"
#include "ConstStatement.h"
#include "ExpressionStatement.h"
#include "FloatLiteral.h"
#include "ForStatement.h"
#include "FunctionStatement.h"
#include "IfStatement.h"
#include "ReturnStatement.h"
#include "VarStatement.h"
#include "PrefixExpression.h"
#include "InfixExpression.h"
#include "IntegerLiteral.h"
#include "StringLiteral.h"



TEST_CASE("test statement to_string ", "[ast]") {
	using namespace hui;
	using namespace std::string_literals;
	using namespace std::string_view_literals;

	// var statement
	{
		Token t1(TOKEN_TYPE::VAR, "var"sv);
		Token t2(TOKEN_TYPE::IDENT, "v1"sv);
		Token t3(TOKEN_TYPE::IDENT, "v2"sv);

		auto ls = std::make_unique<VarStatement>(t1);
		ls->m_name = std::make_unique<Identifier>(t2, t2.get_literal());
		ls->m_value = std::make_unique<Identifier>(t3, t3.get_literal());

		REQUIRE(ls->to_string() == "var v1 = v2;");
	}


	// const statement
	{
		Token t1(TOKEN_TYPE::CONST, "const"sv);
		Token t2(TOKEN_TYPE::IDENT, "v1"sv);
		Token t3(TOKEN_TYPE::IDENT, "v2"sv);

		auto ls = std::make_unique<ConstStatement>(t1);
		ls->m_name = std::make_unique<Identifier>(t2, t2.get_literal());
		ls->m_value = std::make_unique<Identifier>(t3, t3.get_literal());

		REQUIRE(ls->to_string() == "const v1 = v2;");
	}


	// expression statement
	// block statement
	{
		Token t1(TOKEN_TYPE::IDENT, "v1"sv);
		Token t2(TOKEN_TYPE::IDENT, "v2"sv);
		Token t3(TOKEN_TYPE::IDENT, "v3"sv);
		Token t4(TOKEN_TYPE::IDENT, "v4"sv);
		Token t5(TOKEN_TYPE::IDENT, "v5"sv);
		Token o1(TOKEN_TYPE::ADD, "+"sv);
		Token o2(TOKEN_TYPE::SUB, "-"sv);
		Token o3(TOKEN_TYPE::MUL, "*"sv);
		Token o4(TOKEN_TYPE::DIV, "/"sv);
		Token o5(TOKEN_TYPE::NOT, "!"sv);


		auto es1 = std::make_unique<InfixExpression>(o1);
		es1->m_left = std::make_unique<Identifier>(t1, t1.get_literal());
		es1->m_right = std::make_unique<Identifier>(t2, t2.get_literal());
		REQUIRE(es1->to_string() == "(v1 + v2)");

		auto es2 = std::make_unique<InfixExpression>(o2);
		es2->m_left = std::make_unique<Identifier>(t2, t2.get_literal());
		es2->m_right = std::make_unique<Identifier>(t3, t3.get_literal());
		REQUIRE(es2->to_string() == "(v2 - v3)");

		auto es3 = std::make_unique<InfixExpression>(o3);
		es3->m_left = std::make_unique<Identifier>(t3, t3.get_literal());
		es3->m_right = std::make_unique<Identifier>(t4, t4.get_literal());
		REQUIRE(es3->to_string() == "(v3 * v4)");

		auto es4 = std::make_unique<InfixExpression>(o4);
		es4->m_left = std::make_unique<Identifier>(t4, t4.get_literal());
		es4->m_right = std::make_unique<Identifier>(t5, t5.get_literal());
		REQUIRE(es4->to_string() == "(v4 / v5)");

		auto es5 = std::make_unique<PrefixExpression>(o5);
		es5->m_right = std::make_unique<Identifier>(t5, t5.get_literal());
		REQUIRE(es5->to_string() == "(!v5)");
	}


	// if statement
	{
		Token t1(TOKEN_TYPE::IF, "if"sv);

		Token v1(TOKEN_TYPE::IDENT, "v1"sv);
		Token v2(TOKEN_TYPE::IDENT, "v2"sv);
		Token v3(TOKEN_TYPE::IDENT, "v3"sv);
		Token v4(TOKEN_TYPE::IDENT, "v4"sv);

		Token x1(TOKEN_TYPE::IDENT, "print"sv);
		Token x2(TOKEN_TYPE::LPAREN, "("sv);
		Token x3(TOKEN_TYPE::RPAREN, ")"sv);
		Token x4(TOKEN_TYPE::LBRACE, "{"sv);
		Token x5(TOKEN_TYPE::RBRACE, "}"sv);


		auto i1 = std::make_unique<Identifier>(v1, v1.get_literal());
		auto i2 = std::make_unique<Identifier>(v2, v2.get_literal());
		auto i3 = std::make_unique<Identifier>(v3, v3.get_literal());
		auto i4 = std::make_unique<Identifier>(v4, v4.get_literal());

		auto cs1 = std::make_unique<CallExpression>(x2);
		cs1->m_function = std::make_unique<Identifier>(x1, x1.get_literal());
		cs1->m_arguments = std::make_unique<std::vector<std::unique_ptr<Expression>>>();
		cs1->m_arguments->push_back(std::make_unique<Identifier>(v1, v1.get_literal()));
		auto es1 = std::make_unique<ExpressionStatement>(x2);
		es1->m_expression = std::move(cs1);
		auto bs1 = std::make_unique<BlockStatement>(x4);
		bs1->m_statements.push_back(std::move(es1));

		auto cs2 = std::make_unique<CallExpression>(x2);
		cs2->m_function = std::make_unique<Identifier>(x1, x1.get_literal());
		cs2->m_arguments = std::make_unique<std::vector<std::unique_ptr<Expression>>>();
		cs2->m_arguments->push_back(std::make_unique<Identifier>(v2, v2.get_literal()));
		auto es2 = std::make_unique<ExpressionStatement>(x2);
		es2->m_expression = std::move(cs2);
		auto bs2 = std::make_unique<BlockStatement>(x4);
		bs2->m_statements.push_back(std::move(es2));

		auto cs3 = std::make_unique<CallExpression>(x2);
		cs3->m_function = std::make_unique<Identifier>(x1, x1.get_literal());
		cs3->m_arguments = std::make_unique<std::vector<std::unique_ptr<Expression>>>();
		cs3->m_arguments->push_back(std::make_unique<Identifier>(v3, v3.get_literal()));
		auto es3 = std::make_unique<ExpressionStatement>(x2);
		es3->m_expression = std::move(cs3);
		auto bs3 = std::make_unique<BlockStatement>(x4);
		bs3->m_statements.push_back(std::move(es3));

		auto cs4 = std::make_unique<CallExpression>(x2);
		cs4->m_function = std::make_unique<Identifier>(x1, x1.get_literal());
		cs4->m_arguments = std::make_unique<std::vector<std::unique_ptr<Expression>>>();
		cs4->m_arguments->push_back(std::make_unique<Identifier>(v4, v4.get_literal()));
		auto es4 = std::make_unique<ExpressionStatement>(x2);
		es4->m_expression = std::move(cs4);
		auto bs4 = std::make_unique<BlockStatement>(x4);
		bs4->m_statements.push_back(std::move(es4));


		auto if_state = std::make_unique<IfStatement>(t1);
		if_state->m_conditions.push_back(std::move(i1));
		if_state->m_conditions.push_back(std::move(i2));
		if_state->m_conditions.push_back(std::move(i3));
		if_state->m_consequences.push_back(std::move(bs1));
		if_state->m_consequences.push_back(std::move(bs2));
		if_state->m_consequences.push_back(std::move(bs3));
		if_state->m_alternative = std::move(bs4);

		REQUIRE(if_state->to_string() == "\
if (v1) {\n\
print(v1);\n\
} else if (v2) {\n\
print(v2);\n\
} else if (v3) {\n\
print(v3);\n\
} else {\n\
print(v4);\n\
}");
	}


	// for statement
	{
		Token t1(TOKEN_TYPE::IF, "for"sv);
		Token t2(TOKEN_TYPE::VAR, "var"sv);

		Token v1(TOKEN_TYPE::IDENT, "i"sv);
		Token v2(TOKEN_TYPE::INT, "0"sv);
		Token v3(TOKEN_TYPE::INT, "10"sv);
		Token v4(TOKEN_TYPE::INT, "1"sv);

		Token o1(TOKEN_TYPE::LT, "<"sv);
		Token o2(TOKEN_TYPE::ADD_ASSIGN, "+="sv);

		Token x1(TOKEN_TYPE::IDENT, "print"sv);
		Token x2(TOKEN_TYPE::LPAREN, "("sv);
		Token x3(TOKEN_TYPE::RPAREN, ")"sv);
		Token x4(TOKEN_TYPE::LBRACE, "{"sv);
		Token x5(TOKEN_TYPE::RBRACE, "}"sv);



		auto for_state = std::make_unique<ForStatement>(t1);
		for_state->m_loop_var = std::make_unique<VarStatement>(t2);
		for_state->m_loop_var->m_name = std::make_unique<Identifier>(v1, v1.get_literal());
		for_state->m_loop_var->m_value = std::make_unique<IntegerLiteral>(v2, 0);

		auto ie1 = std::make_unique<InfixExpression>(o1);
		ie1->m_left = std::make_unique<Identifier>(v1, v1.get_literal());
		ie1->m_right = std::make_unique<IntegerLiteral>(v3, 10);
		for_state->m_condition = std::move(ie1);

		auto ne1 = std::make_unique<InfixExpression>(o2);
		ne1->m_left = std::make_unique<Identifier>(v1, v1.get_literal());
		ne1->m_right = std::make_unique<IntegerLiteral>(v4, 1);
		for_state->m_next_step = std::move(ne1);

		auto cs1 = std::make_unique<CallExpression>(x2);
		cs1->m_function = std::make_unique<Identifier>(x1, x1.get_literal());
		cs1->m_arguments = std::make_unique<std::vector<std::unique_ptr<Expression>>>();
		cs1->m_arguments->push_back(std::make_unique<Identifier>(v1, v1.get_literal()));
		auto es1 = std::make_unique<ExpressionStatement>(x2);
		es1->m_expression = std::move(cs1);
		auto bs1 = std::make_unique<BlockStatement>(x4);
		bs1->m_statements.push_back(std::move(es1));
		for_state->m_body = std::move(bs1);


		REQUIRE(for_state->to_string() == "\
for (var i = 0; (i < 10); (i += 1)) {\n\
print(i);\n\
}");
		
	}


	// return statement
	{
		Token t1(TOKEN_TYPE::RETURN, "return"sv);

		Token v1(TOKEN_TYPE::IDENT, "v1"sv);
		Token v2(TOKEN_TYPE::INT, "233"sv);
		Token v3(TOKEN_TYPE::STRING, "hui"sv);


		auto r1 = std::make_unique<ReturnStatement>(t1);
		r1->m_return_value = std::make_unique<Identifier>(v1, v1.get_literal());
		REQUIRE(r1->to_string() == "return v1;");

		auto r2 = std::make_unique<ReturnStatement>(t1);
		r2->m_return_value = std::make_unique<IntegerLiteral>(v2, 233);
		REQUIRE(r2->to_string() == "return 233;");

		auto r3 = std::make_unique<ReturnStatement>(t1);
		r3->m_return_value = std::make_unique<StringLiteral>(v3, v3.get_literal());
		REQUIRE(r3->to_string() == "return \"hui\";");

	}


	// function statement
	{
		Token t1(TOKEN_TYPE::FUNC, "func"sv);

		Token v1(TOKEN_TYPE::IDENT, "x"sv);
		Token v2(TOKEN_TYPE::IDENT, "test1"sv);

		Token x1(TOKEN_TYPE::IDENT, "print"sv);
		Token x2(TOKEN_TYPE::LPAREN, "("sv);
		Token x3(TOKEN_TYPE::RPAREN, ")"sv);
		Token x4(TOKEN_TYPE::LBRACE, "{"sv);
		Token x5(TOKEN_TYPE::RBRACE, "}"sv);


		auto fs1 = std::make_unique<FunctionStatement>(t1);
		fs1->m_name = std::make_unique<Identifier>(v2, v2.get_literal());
		fs1->m_parameters = std::make_unique<std::vector<std::unique_ptr<Identifier>>>();
		fs1->m_parameters->push_back(std::make_unique<Identifier>(v1, v1.get_literal()));


		auto cs1 = std::make_unique<CallExpression>(x2);
		cs1->m_function = std::make_unique<Identifier>(x1, x1.get_literal());
		cs1->m_arguments = std::make_unique<std::vector<std::unique_ptr<Expression>>>();
		cs1->m_arguments->push_back(std::make_unique<Identifier>(v1, v1.get_literal()));
		auto es1 = std::make_unique<ExpressionStatement>(x2);
		es1->m_expression = std::move(cs1);
		auto bs1 = std::make_unique<BlockStatement>(x4);
		bs1->m_statements.push_back(std::move(es1));
		fs1->m_body = std::move(bs1);



		REQUIRE(fs1->to_string() == "\
func test1(x) {\n\
print(x);\n\
}");
	}



}


