cmake_minimum_required(VERSION 3.21)

project(Marks)

set(CMAKE_CXX_STANDARD 20)


find_package(Boost REQUIRED)

if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()

message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

include_directories(${Boost_INCLUDE_DIR})

find_package(Boost COMPONENTS serialization)


add_executable(Marks main.cpp )


target_link_libraries(Marks ${Boost_LIBRARIES})

