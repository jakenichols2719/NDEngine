cmake_minimum_required(VERSION 3.10)

project(NDEngine)
add_executable(run.exe run.cpp ndstruct.cpp ndconst.cpp load.cpp)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR})

target_link_libraries(run.exe ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})


# build library. work on this.
#cmake_minimum_required(VERSION 3.10)
# project name
#project(NDBaseLib VERSION 0.1 DESCRIPTION "desc")
# set source and include files
#set(SRCS
#  load.cpp
#  ndconst.cpp
#  ndstruct.cpp)
#set(INCL
#  ndgl.h
#  load.h
#  ndconst.h
#  ndstruct.h)
# create library
#add_library(nd_base ${SRCS} ${INCL})
# set properties
#set_target_properties(nd_base PROPERTIES
#  VERSION "${PROJECT_VERSION}"
#  SOVERSION 0
#  PUBLIC_HEADER "${INCL}")
# create an install rule
#include(GNUInstallDirs)
#install(TARGETS nd_base
#  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#  PUBLIC_HEADER DESTINATION ${CMAKE_INSTAL_INCLUDEDIR})
#target_include_directories(nd_base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})