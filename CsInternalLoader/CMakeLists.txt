cmake_minimum_required(VERSION 3.23)
project(CsInternalLoader)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib/chr-core)

add_library(CsInternalLoader SHARED src/CsInternalLoader)
set_target_properties(CsInternalLoader PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(CsInternalLoader PUBLIC chr-core)

target_include_directories(CsInternalLoader PUBLIC src/)

target_compile_options(CsInternalLoader PUBLIC -DNOMINMAX)
target_link_directories(CsInternalLoader PUBLIC ../CsInternalClient/bin/Release/net7.0-windows10.0.22621.0/win-x64/native)

add_subdirectory(src)