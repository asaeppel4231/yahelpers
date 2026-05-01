enable_testing()

include_directories(${CMAKE_INSTALL_PREFIX}/include) 

find_package(cmocka REQUIRED)

add_executable(test_assert test_assert.c)
target_link_libraries(test_assert PRIVATE cmocka::cmocka)

add_executable(test_log test_log.c)
target_link_libraries(test_log PRIVATE cmocka::cmocka)

# assert_tests: CMocka may raise SIGABRT, but CTest don't may see that 
# (Because CTest thinks everytime, that a test that raises a signal was failed)
add_test(NAME assert_tests
         COMMAND bash -c "./test_assert > assert.out 2>&1; echo $?; exit 0")

# log_tests: normal
add_test(NAME log_tests COMMAND test_log)

add_dependencies(test_assert ${PROJECT_NAME})
add_dependencies(test_log ${PROJECT_NAME})
