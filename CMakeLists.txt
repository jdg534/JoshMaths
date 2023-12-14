# disclaimer: the main cmake list logic is taken from:  https://github.com/snikulov/google-test-examples.git

cmake_minimum_required(VERSION 3.9.0)
set(PROJECT_NAME_STR JoshMaths)
project(${PROJECT_NAME_STR} C CXX)

set(CMAKE_CXX_FLAGS "-g -Wall")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRE ON)

# force static runtime libraries for msvc builds
if(MSVC)
  set(variables 
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_RELEASE
	CMAKE_CXX_FLAGS_RELWITHDEBINFO
	CMAKE_CXX_FLAGS_MINSIZEREL
  )
  foreach(variable ${variables})
	if(${variable} MATCHES "/MD")
	  string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
	endif()
  endforeach()
endif()

add_subdirectory(Submodule)
add_subdirectory(JoshMath)
add_subdirectory(UnitTests)	
