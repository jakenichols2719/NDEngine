cmake_minimum_required(VERSION 3.10)

project(NDEngine)
add_executable(run.exe run.cpp ndstruct.cpp ndconst.cpp load.cpp)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR})

target_link_libraries(run.exe ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})