add_executable(hui main.cpp)


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