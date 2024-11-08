cmake_minimum_required(VERSION 3.5.0)
project(soundMagic VERSION 0.1.0 LANGUAGES C CXX)

find_library(fltk FLTK)
find_library(asound asound)
find_library(mpg123 mpg123)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory( src/sound)


add_executable(soundMagic apps/main.cpp)

target_link_libraries( soundMagic PRIVATE soundlib asound fltk mpg123)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
