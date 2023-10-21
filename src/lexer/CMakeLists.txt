add_library(lexer "")



target_include_directories(lexer
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)


target_sources(lexer
	PRIVATE
		Lexer.cpp
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/Lexer.h
)


target_link_libraries(lexer
	PRIVATE
		token
)
