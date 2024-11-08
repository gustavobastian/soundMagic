file( GLOB system_SOURCES *.cpp )

find_library(asound asound)
find_library(mpg123 mpg123)


add_library( soundlib ${system_SOURCES})
target_include_directories(soundlib  PUBLIC asound mpg123 ${CMAKE_CURRENT_SOURCE_DIR} )

