cmake_minimum_required(VERSION 3.30.0)

file(GLOB_RECURSE JOSH_MATH_SOURCE_FILES *.cpp)
file(GLOB_RECURSE JOSH_MATH_HEADER_FILES *.h)

add_library(JoshMath ${JOSH_MATH_HEADER_FILES} ${JOSH_MATH_SOURCE_FILES})

set(JoshMathHeaderDir ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "" FORCE)
