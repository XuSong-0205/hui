add_subdirectory(catch)


add_executable(test_lexer test_lexer.cpp)
add_test( NAME test_lexer COMMAND $<TARGET_FILE:test_lexer>)
target_link_libraries(test_lexer PRIVATE token lexer catch)

# add_executable(test_lexer test_lexer.cpp)
# add_test( NAME test_lexer COMMAND $<TARGET_FILE:test_lexer>)
# target_link_libraries(test_lexer PRIVATE token lexer catch)

# add_executable(test_lexer test_lexer.cpp)
# add_test( NAME test_lexer COMMAND $<TARGET_FILE:test_lexer>)
# target_link_libraries(test_lexer PRIVATE token lexer catch)

# add_executable(test_lexer test_lexer.cpp)
# add_test( NAME test_lexer COMMAND $<TARGET_FILE:test_lexer>)
# target_link_libraries(test_lexer PRIVATE token lexer catch)

# add_executable(test_lexer test_lexer.cpp)
# add_test( NAME test_lexer COMMAND $<TARGET_FILE:test_lexer>)
# target_link_libraries(test_lexer PRIVATE token lexer catch)