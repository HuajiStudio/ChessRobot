cmake_minimum_required(VERSION 3.0)

project(ChessRobot)

set(BOOST_URL https://dl.bintray.com/boostorg/release/1.64.0/source/boost_1_64_0.zip)
set(Boost_INCLUDE_DIR include)
set(Boost_LIBRARY_DIR include/libs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# FIXME: this cmake was not useable yet...

if (NOT EXISTS ${Boost_INCLUDE_DIR})
	if (NOT EXISTS include/boost_1_64_0.zip)
		MESSAGE("Boost Library not found, trying to install...")
		file(DOWNLOAD ${BOOST_URL} include/boost_1_64_0.zip)
	endif()
	execute_process(COMMAND ${CMAKE_COMMAND} -E tar xzf include/boost_1_64_0.zip -C include/boost_1_64_0)
endif()

include_directories(${Boost_INCLUDE_DIR})

find_package(Boost REQUIRED COMPONENTS)

set(SOURCE_FILES ChessRobot/ChessRobot.cpp)
add_executable(ChessRobot ${SOURCE_FILES})
target_link_libraries(ChessRobot "${Boost_LIBRARIES}")
