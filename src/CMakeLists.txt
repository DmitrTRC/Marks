# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.


project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set ( source_files
        main.cpp
        mark.cpp
        include/mark.h
        include/main.h
        logbook.cpp
        include/logbook.h
        screen_util.cpp
        include/screen_util.h )

add_executable(${PROJECT_NAME} ${source_files})



