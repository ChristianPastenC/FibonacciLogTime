cmake_minimum_required(VERSION 3.31)
project(Fibonacci)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fibonacci main.cpp
        src/CustomMatrix.cpp
        include/CustomMatrix.h
        src/FibonacciLinear.cpp
        src/FastExponentiation.cpp
        include/FastExponentiation.h
        src/FibonacciLog.cpp
        include/FibonacciLinear.h
        include/FibonacciLog.h)
