cmake_minimum_required(VERSION 3.2)
SET(CMAKE_SYSTEM_NAME Linux) 
PROJECT("Demo")
add_custom_target(run ALL DEPENDS ${PROJECT_NAME})
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
add_definitions("-Wall -g") 
add_executable(${PROJECT_NAME} main.cc)
add_subdirectory(src)
include_directories("${PROJECT_SOURCE_DIR}/src")
#include_directories("${PROJECT_SOURCE_DIR}/src/include")
target_link_libraries(${PROJECT_NAME} lib_patterns)
target_link_libraries(${PROJECT_NAME} lib_algorithms)

 #       add_custom_command(
 #           TARGET run POST_BUILD COMMAND echo
 #           "executing a fake command" COMMENT
 #           "This command will be executed before building target Test1"
#COMMAND mkdir - p ${CMAKE_BINARY_DIR } subProject&& cd ${CMAKE_BINARY_DIR }subProject&& ${CMAKE_COMMAND } ${CMAKE_SOURCE_DIR }  subProject&& make)




#dd_executable(log log4cpp.cc)   
#find_package(Threads)
#target_link_libraries(log liblog4cpp.so pthread)

set( ALL_UNIT_TESTS "ssss" CACHE INTERNAL "all_unit_tests" FORCE )
message(${PROJECT_SOURCE_DIR})  
message(${PROJECT_BINARY_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})
#message(${BIN_ROOT})
message(${ALL_UNIT_TESTS})
message(${ALL_UNIT_TESTS})


