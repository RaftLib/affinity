set( CMAKE_INCLUDE_CURRENT_DIR ON )

add_library( affinity affinity.cpp )

target_link_libraries( affinity PUBLIC pthread )


install( TARGETS affinity
         ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib )
