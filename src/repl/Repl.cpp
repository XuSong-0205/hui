#include "Repl.h"
#include "Evaluator.h"
#include "Environment.h"
#include "Lexer.h"
#include "Parser.h"
#include <execution>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



namespace hui
{

void print_hui();
void print_parser_errors(const std::vector<std::string>& errors);


void Repl::start()
{
	print_hui();

	constexpr auto PROMPT = ">> ";
	
	std::string line;

	Evaluator eval;
	auto env = std::make_shared<Environment>();

	while (true)
	{
		Lexer lexer(line);
		Parser parser(lexer);

		auto program = parser.parse_program();
		if (!parser.errors().empty())
		{
			print_parser_errors(parser.errors());
			continue;
		}

		std::cout << program->to_string() << std::endl;

		auto result = eval.eval(program.get(), env.get());
		if (result)
		{
			std::cout << result->inspect() << std::endl;
		}
	}


}

void Repl::exec(const char* file_name)
{
	std::ifstream ifile(file_name);
	if (!ifile)
	{
		std::cout << "file: " << file_name << " not founc!\n";
		return;
	}

	std::istreambuf_iterator<char> beg(ifile);
	std::istreambuf_iterator<char> end;
	std::string code(beg, end);
	ifile.close();


	Evaluator eval;
	auto env = std::make_shared<Environment>();

	Lexer lexer(code);
	Parser parser(lexer);
	auto program = parser.parse_program();
	if (!parser.errors().empty())
	{
		print_parser_errors(parser.errors());
		return;
	}

	eval.eval(program.get(), env.get());
}


void print_hui()
{
	constexpr auto name = R"(
	#########################################
	#	h			u		u	  iiiii		#
    #	h			u		u		i		#
	#	hhhhhhhhh	u		u		i		#
	#	h		h	u		u		i		#
	#	h		h	uuuuuuuuu	  iiiii		#
	#########################################
	)";

	std::cout << name << std::endl;
}

void print_parser_errors(const std::vector<std::string>& errors)
{
	print_hui();
	std::cout << "Woops! We ran into some `hui` business here!\n";
	std::cout << " parser errors:\n";
	for (auto&& err : errors)
	{
		std::cout << "\t" << err << "\n";
	}
}

}	// namespace hui