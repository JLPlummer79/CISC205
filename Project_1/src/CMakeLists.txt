cmake_minimum_required(VERSION 3.0.0)
project(Project_2 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(process-Project_2
display.h
display.cpp
test.h
test.cpp
modify.h
modify.cpp
sort.h
sort.cpp
)

add_executable(Project_2 main.cpp)

target_link_libraries(Project_2 PRIVATE process-Project_2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
