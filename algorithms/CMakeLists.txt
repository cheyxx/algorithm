aux_source_directory(. DIR_LIB_SRCS)
include_directories("${PROJECT_SOURCE_DIR}")
add_library (lib_algorithms ${DIR_LIB_SRCS})