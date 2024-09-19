cmake_minimum_required(VERSION 3.29)
#project(assignment1)
#
#set(CMAKE_CXX_STANDARD 20)
#
#add_executable(untitled main.cpp
#        Stackt.cpp
#        Stackt.h
#        TowersOfHanoi.cpp
#        TowersOfHanoi.h
#        SimpleCalculator.cpp
#        SimpleCalculator.h)
project(Code_lib)

set(HEADER_FILES
        Stackt.h
        TowersOfHanoi.h
        SimpleCalculator.h
)

set(SOURCE_FILES
        Stackt.cpp
        TowersOfHanoi.cpp
        SimpleCalculator.cpp
        infix.cpp
)

add_library(Code_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})