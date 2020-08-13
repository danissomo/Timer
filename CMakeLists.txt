cmake_minimum_required(VERSION 3.10)
project(Timer)
add_subdirectory( ./src)
target_include_directories(Timer PUBLIC ./include)
set_target_properties(
    Timer
    PROPERTIES 
        OUTPUT_NAME "a"
        SUFFIX ".out"
)
add_compile_options(
  "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
  "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)
