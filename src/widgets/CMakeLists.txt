file( GLOB system_SOURCES *.cpp )

find_library(fltk FLTK)


add_library( widgetslib ${system_SOURCES})
target_include_directories(widgetslib  PUBLIC fltk  ${CMAKE_CURRENT_SOURCE_DIR} )

