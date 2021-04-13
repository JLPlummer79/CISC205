cmake_minimum_required(VERSION 3.0.0)
project(Project_3 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(process-Project_3
record.h
menu.h
menu.cpp
error.h
error.cpp
options.h
options.cpp
display.h
display.cpp
)

add_executable(Project_3 main.cpp)

target_link_libraries(Project_3 PRIVATE process-Project_3)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
