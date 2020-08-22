cmake_minimum_required(VERSION 2.8)

project (division)

aux_source_directory(. DIRSRCS)

add_executable (main main.c)

aux_source_directory (. DIR_LIB_SRCS)
add_library (hashMap ${DIR_LIB_SRCS})

target_link_libraries (main hashMap)