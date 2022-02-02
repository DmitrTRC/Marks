cmake_minimum_required(VERSION 3.21)

project(Marks)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_subdirectory(lib/googletest)
add_subdirectory(src)
add_subdirectory(Tests)

#TODO: Resolve It!!!
target_link_libraries(Marks ${Boost_LIBRARIES})
#add_executable(Marks main.cpp Console_color.h)




