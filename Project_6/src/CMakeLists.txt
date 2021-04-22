cmake_minimum_required(VERSION 3.0.0)
project(Project_6 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(process-Project_6
Yacht.h
Yacht.cpp
Sailboat.h
Sailboat.cpp
)

add_executable(Project_6 main.cpp)

target_link_libraries(Project_6 PUBLIC process-Project_6)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
