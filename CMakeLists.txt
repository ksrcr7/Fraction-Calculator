cmake_minimum_required(VERSION 3.27)
project(Fraction_Calculator)
set(CMAKE_CXX_STANDARD 17)

add_executable(Fraction_Calculator
        src/main.cpp
        src/Fraction.cpp
        include/Fraction.h
)

target_include_directories(Fraction_Calculator PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
