set(BINARY ${CMAKE_PROJECT_NAME})


find_package(Boost REQUIRED)

if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()

message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

include_directories(${Boost_INCLUDE_DIR})

find_package(Boost COMPONENTS serialization)

if (NOT Boost_FOUND)
    message(FATAL_ERROR  "Boost serialization module NOT FOUND! ")
endif()

    message(STATUS "Boost serialization module OK.")

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY} ${SOURCES})

target_link_libraries(${BINARY} ${Boost_LIBRARIES})

#add_library(${BINARY} STATIC ${SOURCES})