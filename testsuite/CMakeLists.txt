list( APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake )
set( CMAKE_INCLUDE_CURRENT_DIR ON )

set( TESTAPPS #list apps
        simple
    )


foreach( APP ${TESTAPPS} )
 add_executable( "${APP}_affinity" "${APP}.cpp" )
 target_link_libraries( "${APP}_affinity" affinity pthread )
 add_test( NAME "${APP}_affinity_test" COMMAND "${APP}_affinity" )
endforeach( APP ${TESTAPPS} )
