cmake_minimum_required(VERSION 2.4)

project(sllist)

aux_source_directory(. DIR_SRCS)

add_executable(main main.c)

aux_source_directory(. DIR_LIB_SRCS)
add_library(sllist ${DIR_LIB_SRCS})

target_link_libraries(main sllist)