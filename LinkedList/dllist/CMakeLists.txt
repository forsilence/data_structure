cmake_minimum_required ( VERSION 2.8)

project(dllist)

aux_source_directory (. DIR_SRCS)

add_executable (main main.c)

aux_source_directory (. DIR_LIB_SRCS)
add_library (dllist ${DIR_LIB_SRCS})

target_link_libraries (main dllist)