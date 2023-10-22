add_executable(hui main.cpp "ast/Node.h" "ast/Expression.h" "ast/Statement.h" "ast/Program.h" "ast/VarStatement.h" "ast/ConstStatement.h" "ast/ForStatement.h" "ast/IfStatement.h" "ast/FunctionStatement.h" "ast/ReturnStatement.h" "ast/ExpressionStatement.h" "ast/Identifier.h" "ast/BlockStatement.h")


add_subdirectory(token)
add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(ast)
# add_subdirectory(repl)
# add_subdirectory(object)
# add_subdirectory(evaluator)



# target_link_libraries(hui 
#	PRIVATE
#		object
#		evaluator
#		repl
#)