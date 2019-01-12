cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set (CMAKE_CXX_STANDARD 14)
# if ( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
message("turning on warnings")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# else()
	# message("can't turn on warnings")
	# message(${CMAKE_CXX_COMPILER})
# endif()


project (Nintendo_project CXX)

#file globing
file(GLOB_RECURSE sources src/*.cpp src/*.h)
file(GLOB_RECURSE data resources/*)

# add_executable(Nintendo ${sources} ${data})
add_executable(Nintendo src/main.cpp src/encode.cpp ${data})

#copy resources to build directory
file(COPY ${data} DESTINATION resources)

target_link_libraries(Nintendo)
