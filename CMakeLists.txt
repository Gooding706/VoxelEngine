cmake_minimum_required(VERSION 3.0.0)
project(Vox VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

find_library(COREVIDEO CoreVideo)
find_library(OPENGL OpenGL)
find_library(IOKIT IOKit)
find_library(COCOA Cocoa)
find_library(CARBON Carbon)

file(GLOB BuildFiles Src/*.cpp)

add_executable(Vox ${BuildFiles} external/glad/src/glad.c)

add_subdirectory(external/glfw)


target_include_directories(Vox PUBLIC external/glfw/include external/glad/include/)
target_link_directories(Vox PRIVATE external/glfw/src)
target_link_libraries(Vox glfw ${COREVIDEO} ${COREVIDEO} ${OPENGL} ${IOKIT} ${COCOA} ${CARBON})