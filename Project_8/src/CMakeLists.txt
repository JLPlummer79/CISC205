cmake_minimum_required(VERSION 3.0.0)
project(Project_8 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(process-Project_8
Painting.h
Painting.cpp
menu.h
menu.cpp
options.h
options.cpp
)

add_executable(Project_8 main.cpp)

target_link_libraries(Project_8 PUBLIC process-Project_8)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
