cmake_minimum_required(VERSION 3.9.0)

file(GLOB UnitTestSourceFiles *.cpp *.h)
	
add_executable(RunUnitTests ${UnitTestSourceFiles})
	
include_directories(../JoshMath)
	
target_link_libraries(RunUnitTests gtest gtest_main)
	
target_link_libraries(RunUnitTests JoshMath)
	
add_test(RunUnitTestsExecutable RunUnitTests)