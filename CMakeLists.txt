cmake_minimum_required(VERSION 3.11)
project(ChantageStudio)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.ui" "src/*.qrc")

add_executable(studio MACOSX_BUNDLE WIN32 ${SOURCES})
target_include_directories(studio PRIVATE src)
target_link_libraries(studio Qt5::Core Qt5::Widgets)
set_target_properties(
    studio
    PROPERTIES
    OUTPUT_NAME "Chantage Studio"
    MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/Info.plist.in"
    )
