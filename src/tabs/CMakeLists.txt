file( GLOB system_SOURCES *.cpp )

find_library(fltk FLTK)


add_library( tabsLib ${system_SOURCES})
target_include_directories(tabsLib  PUBLIC fltk  ${CMAKE_CURRENT_SOURCE_DIR} )

