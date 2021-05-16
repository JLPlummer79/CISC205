cmake_minimum_required(VERSION 3.0.0)
project(Project_7 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(process-Project_7
SeaPollution.h
SeaPollution.cpp
menu.h
menu.cpp
)

add_executable(Project_7 main.cpp)

target_link_libraries(Project_7 PUBLIC process-Project_7)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
