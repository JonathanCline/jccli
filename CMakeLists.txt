cmake_minimum_required(VERSION 3.12)

#
# Variables
#

# Project sources
set(_Sources
	"source/jccli.cpp"
	"include/jccli/jccli.hpp"
	"include/jclib/cli.hpp")



#
# Machinery
#

project(jccli)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(${PROJECT_NAME}
	STATIC ${_Sources})

target_include_directories(${PROJECT_NAME}
	PUBLIC include
	PRIVATE source)
