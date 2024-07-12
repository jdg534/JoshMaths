cmake_minimum_required(VERSION 3.9.0)

enable_testing()

file(GLOB UnitTestSourceFiles *.cpp *.h)

add_executable(RunUnitTests ${UnitTestSourceFiles})

target_include_directories(RunUnitTests PUBLIC gtest_build_include_dirs)
target_include_directories(RunUnitTests PUBLIC ${JoshMathHeaderDir})
	
target_link_libraries(RunUnitTests PRIVATE GTest::gtest)
target_link_libraries(RunUnitTests PRIVATE JoshMath)

add_test(RunUnitTestsExecutable RunUnitTests)
