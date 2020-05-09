cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(affinity)
set( version 1.1 )
set( CMAKE_INCLUDE_CURRENT_DIR ON )




##
# AFFINITY_CUSTOM_NAMESPACE - set to true if you want
# to inject a custom namespace. 
##
mark_as_advanced( AFFINITY_CUSTOM_NAMESPACE )

if( NOT DEFINED AFFINITY_CUSTOM_NAMESPACE )
set( AFFINITY_CUSTOM_NAMESPACE false CACHE BOOL "Wrap the affinity call in a custom namespace using -DAFFINITY_NAMESPACE=\"namespace\" when configuring cmake." )
endif() 

##
# AFFINITY_NAMESPACE - set to actual name you want to 
# inject. 
##
mark_as_advanced( AFFINITY_NAMESPACE )

if( NOT DEFINED AFFINITY_NAMESPACE )
set( AFFINITY_NAMESPACE "" CACHE STRING "Namespace to inject" )
endif()

if( AFFINITY_CUSTOM_NAMESPACE )
message (STATUS "Injecting the following namespace into your libaffinity build: ${AFFINITY_NAMESPACE}" )
add_definitions( "-DINJECT_AFFINITY_NAMESPACE=1" )
add_definitions( "-DAFFINITY_NAMESPACE=${AFFINITY_NAMESPACE}" )
endif( AFFINITY_CUSTOM_NAMESPACE )

include_directories ( ${PROJECT_SOURCE_DIR} )
include_directories ( ${PROJECT_SOURCE_DIR}/include )
add_subdirectory( src )

mark_as_advanced( BUILD_TESTS )

##
# Set up unit tests
##
if( BUILD_TESTS AND NOT WIN32 )
enable_testing()
add_subdirectory( testsuite )
endif()


