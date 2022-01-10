cmake_minimum_required(VERSION 3.21)

project(Marks)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

#find_package(jsoncpp CONFIG REQUIRED)
add_subdirectory(googletest)

include_directories(googletest)

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} gtest gtest_main)




#target_link_libraries(Marks PRIVATE jsoncpp_object jsoncpp_static JsonCpp::JsonCpp)
