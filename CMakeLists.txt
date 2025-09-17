cmake_minimum_required(VERSION 3.10)
project(CS200Final)

set (CMAKE_CXX_STANDARD 17)



include_directories(matplotplusplus/include)
add_executable(CS200Final src/main.cpp  
               src/Regression.cpp src/Regression.h src/DataCleaner.h  src/DataCleaner.cpp)
target_link_libraries(CS200Final PUBLIC matplot)

