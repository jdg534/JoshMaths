cmake_minimum_required(VERSION 3.30.0)
set(PROJECT_NAME_STR JoshMaths)
project(${PROJECT_NAME_STR} C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRE ON)

if(BuildToRunWithCTest)
	include(CTest)
endif()

add_subdirectory(Submodule)
add_subdirectory(JoshMath)
add_subdirectory(UnitTests)	
