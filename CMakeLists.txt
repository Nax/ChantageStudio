cmake_minimum_required(VERSION 3.11)
project(ChantageStudio)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.ui" "src/*.qrc")

add_executable(studio MACOSX_BUNDLE WIN32 ${SOURCES})
set_target_properties(studio PROPERTIES OUTPUT_NAME "Chantage Studio")
target_include_directories(studio PRIVATE src)
target_link_libraries(studio Qt5::Widgets)
