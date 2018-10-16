cmake_minimum_required(VERSION 3.12)
project(NoobSolitarie)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Models)

add_subdirectory(Utils)

add_subdirectory(Controllers)

add_subdirectory(Views)

add_executable(NoobSolitarie main.cpp NoobSolitarie.cpp)
target_link_libraries (NoobSolitarie Console Local)