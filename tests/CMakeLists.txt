add_subdirectory(catch)


add_executable(test_lexer test_lexer.cpp)
add_test( NAME test_lexer COMMAND $<TARGET_FILE:test_lexer>)
target_link_libraries(test_lexer PRIVATE token lexer catch)

add_executable(test_ast test_ast.cpp)
add_test( NAME test_ast COMMAND $<TARGET_FILE:test_ast>)
target_link_libraries(test_ast PRIVATE token lexer ast catch)

add_executable(test_object test_object.cpp)
add_test( NAME test_object COMMAND $<TARGET_FILE:test_object>)
target_link_libraries(test_object PRIVATE token lexer ast parser object evaluator catch)

add_executable(test_parser test_parser.cpp)
add_test( NAME test_parser COMMAND $<TARGET_FILE:test_parser>)
target_link_libraries(test_parser PRIVATE token lexer ast parser catch)

add_executable(test_evaluator test_evaluator.cpp)
add_test( NAME test_evaluator COMMAND $<TARGET_FILE:test_evaluator>)
target_link_libraries(test_evaluator PRIVATE token lexer ast parser object evaluator catch)