add_library(evaluator "")


target_include_directories(evaluator 
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)


target_sources(evaluator 
	PRIVATE
		Evaluator.cpp
		Builtins.cpp
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/Evaluator.h
		${CMAKE_CURRENT_LIST_DIR}/Builtins.h
)


target_link_libraries(evaluator 
	PRIVATE
		ast
		token
		object
)