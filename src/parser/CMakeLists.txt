add_library(parser "")


target_include_directories(parser
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)


target_sources(parser
	PRIVATE
		Parser.cpp
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/Parser.h
)

target_link_libraries(parser
	PRIVATE
		token
		lexer
)
