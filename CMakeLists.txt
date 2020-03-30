cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(affinity)
set( version 1.1 )
set( CMAKE_INCLUDE_CURRENT_DIR ON )





mark_as_advanced( CUSTOM_NAMESPACE )
set( CUSTOM_NAMESPACE false CACHE BOOL "Wrap the affinity call in a custom namespace using -DAFFINITY_NAMESPACE=\"namespace\" when configuring cmake." )
if( CUSTOM_NAMESPACE )
add_definitions( "-DINJECT_NAMESPACE=1" )
add_definitions( "-DAFFINITY_NAMESPACE=${AFFINITY_NAMESPACE}" )
endif( CUSTOM_NAMESPACE )

include_directories ( ${PROJECT_SOURCE_DIR} )
include_directories ( ${PROJECT_SOURCE_DIR}/include )
add_subdirectory( src )

mark_as_advanced( BUILD_TESTS )
set( BUILD_TESTS true CACHE BOOL "Tests build target available if true" )
if( BUILD_TESTS )
##
# Set up unit tests
##
enable_testing()
add_subdirectory( testsuite )
endif( BUILD_TESTS )
