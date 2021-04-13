cmake_minimum_required(VERSION 3.0.0)
project(Project_5 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(process-Project_5
SeaPollution.h
SeaPollution.cpp
menu.h
menu.cpp
error.h
error.cpp
)

add_executable(Project_5 main.cpp)

target_link_libraries(Project_5 PUBLIC process-Project_5)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
