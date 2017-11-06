# disclaimer: the main cmake list logic is taken from:  https://github.com/snikulov/google-test-examples.git

cmake_minimum_required(VERSION 3.9.0)
set(PROJECT_NAME_STR JoshMaths)
project(${PROJECT_NAME_STR} C CXX)

set(CMAKE_CXX_FLAGS "-g -Wall")

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

add_subdirectory(JoshMath)

if (EnableUnitTesting)
	if (APPLE)
		add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
		add_definitions(-D__GLIBCXX__)
	endif(APPLE)
	
	add_subdirectory(ExternalLibs/gtest-1.6.0)
	
	enable_testing()
	
	include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
	
	add_subdirectory(UnitTests)
	
endif()