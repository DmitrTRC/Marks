set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

include_directories(${Boost_INCLUDE_DIR})

find_package(Boost COMPONENTS serialization)

target_link_libraries(${BINARY}  gtest gtest_main)

target_link_libraries(${BINARY} ${Boost_LIBRARIES})
message(STATUS "Running tests..." ${CMAKE_PROJECT_NAME})
target_link_libraries(${BINARY}  ${CMAKE_PROJECT_NAME}_lib)


