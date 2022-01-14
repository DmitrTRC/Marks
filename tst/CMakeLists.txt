set(BINARY ${CMAKE_PROJECT_NAME}_tst)


set(TEST_SOURCES test1.cpp)

add_executable(${BINARY} test1.cpp})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest gtest_main)
