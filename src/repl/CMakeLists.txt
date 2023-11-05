add_library(repl "")


target_include_directories(repl 
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)


target_sources(repl 
	PRIVATE
		Repl.cpp
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/Repl.h
)


target_link_libraries(repl 
	PRIVATE
		object
		token
		lexer
		parser
		ast
		evaluator
)