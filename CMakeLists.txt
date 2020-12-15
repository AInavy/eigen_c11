cmake_minimum_required(VERSION 2.8)

project(C11test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" )
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB src_files ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/include/*.h)

add_executable(main main.cpp ${src_files})
target_link_libraries(main )

