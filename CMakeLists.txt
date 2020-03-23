cmake_minimum_required(VERSION 3.10)

# set the project name
project(AdventureQuest C)
set(quest_srcs src/main.c) 

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb")

# add the executable
add_executable(quest ${quest_srcs})
target_include_directories(quest PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
                           )

target_link_libraries(quest cursesw)

