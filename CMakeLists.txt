cmake_minimum_required(VERSION 3.9)
project(threadpool_first)

include_directories("./inc")

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(./src SRCS)

add_executable(threadpool_first main.cpp ${SRCS})