cmake_minimum_required(VERSION 3.10)
project(problem_100_code CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(code main.cpp)
# Optimize for speed; static may fail on judge, so keep dynamic by default
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -pipe -s")
