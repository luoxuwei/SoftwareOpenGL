#需求的最低cmake程序版本
cmake_minimum_required(VERSION 3.12)

#本工程的名字
project(SoftwareOpenGL)

#本工程支持的C++版本
set(CMAKE_CXX_STANDARD 17)

file(GLOB copyResources "./assets")
file(COPY ${copyResources} DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(app)
add_subdirectory(opengl)

#本工程所有cpp文件编译链接，生成exe
add_executable(SoftwareOpenGL "main.cpp")
add_executable(testMath "testMath.cpp")
add_executable(testMatrix "testMatrix.cpp")

target_link_libraries(SoftwareOpenGL appLib openglLib) 