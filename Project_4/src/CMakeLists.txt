cmake_minimum_required(VERSION 3.0.0)
project(Project_4 VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(process-Project_4
Patient.h
Patient.cpp
PatientAccount.h
PatientAccount.cpp
Surgery.h
Surgery.cpp
Pharmacy.h
Pharmacy.cpp
menu.h
menu.cpp
error.h
error.cpp
display.h
display.cpp
options.h
options.cpp
)

add_executable(Project_4 main.cpp)

target_link_libraries(Project_4 PUBLIC process-Project_4)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
