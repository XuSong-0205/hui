add_library(token "")

target_sources(token 
	PRIVATE
		Token.cpp
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/Token.h
		${CMAKE_CURRENT_LIST_DIR}/TokenType.h
)

target_include_directories(token 
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(token)