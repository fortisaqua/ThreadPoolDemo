cmake_minimum_required(VERSION 3.9)
project(threadpool_first)

include_directories("./inc")

set(CMAKE_CXX_STANDARD 11)

add_executable(threadpool_first main.cpp inc/condition.h src/condition.cpp inc/threadpool.h src/threadpool.cpp)