cmake_minimum_required(VERSION 3.23)
project(CsInternalLoader)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib/chr-core)

add_library(CsInternalLoader SHARED src/CsInternalLoader)
set_target_properties(CsInternalLoader PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(CsInternalLoader PUBLIC chr-core)

target_include_directories(CsInternalLoader PUBLIC src/)

add_subdirectory(src)