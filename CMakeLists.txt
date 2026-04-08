cmake_minimum_required(VERSION 3.10)
project(NFA2DFA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES 
    src/main.cpp 
    src/converter.cpp 
    src/interaction.cpp
)

add_executable(nfa_tool ${SOURCES})
