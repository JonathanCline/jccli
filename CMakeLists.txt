cmake_minimum_required(VERSION 3.12)

#
# Variables
#

# Project sources
set(_Sources
	"source/jccli.cpp")



#
# Machinery
#

project(jccli)

add_library(${PROJECT_NAME}
	STATIC ${_Sources})

target_include_directories(${PROJECT_NAME}
	PUBLIC include
	PRIVATE source)
