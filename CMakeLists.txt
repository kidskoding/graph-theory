cmake_minimum_required(VERSION 3.30)
project(graph_theory)

include_directories(include)

set(CMAKE_CXX_STANDARD 20)

add_executable(graph_theory src/main.cpp
        src/graph.cpp
        include/graph.h
        include/graph_node.h
        include/graph_utilities.h
        src/graph_utilities.cpp)
