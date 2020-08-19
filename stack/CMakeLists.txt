cmake_minimum_required (VERSION 2.8)

project(stack)

aux_source_directory(. DIR_SRCS)

add_subdirectory(byArray)

add_executable(main main.c)

target_link_libraries (main stack)