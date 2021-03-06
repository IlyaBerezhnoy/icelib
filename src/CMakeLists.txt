#
#
# compiling/installing sources for icelib

set ( icelib_srcs
      fifo.c
      icelib.c
      timer.c
      icelibtypes.c
)

set (ADDITIONAL_LIBS "")

include_directories ( 
  "./../sockaddrutil/include" 
  "./../stunlib/include" 
)

add_library ( icelib SHARED ${icelib_srcs} )
target_include_directories ( icelib PUBLIC ../include )
target_include_directories ( icelib PRIVATE ../src )


install ( TARGETS icelib
          LIBRARY DESTINATION lib
          ARCHIVE DESTINATION lib
          RUNTIME DESTINATION bin)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

target_link_libraries ( icelib PUBLIC sockaddrutil stunlib
                        ${ADDITIONAL_LIBS})

if (coveralls)
    include(Coveralls)
    coveralls_turn_on_coverage()

    set(COVERAGE_SRCS "")
    foreach (S ${icelib_srcs})
      get_filename_component(S_ABS ${S} ABSOLUTE)
      list (APPEND COVERAGE_SRCS ${S_ABS})
    endforeach()

    # Create the coveralls target.
    coveralls_setup(
        "${COVERAGE_SRCS}"
        ${coveralls_send}                 # If we should upload.
    )

    #add_dependencies(coveralls, all)
endif()
