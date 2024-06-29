cmake_minimum_required(VERSION 3.14)

project(FormatProject LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(lib)
add_subdirectory(lib)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

set(Phoin_SOURCE
    main.cpp
    PhoinFormatObject.cpp
    PhoinFormatObject.h)


add_executable(FormatProject ${Phoin_SOURCE})
target_link_libraries(FormatProject Qt${QT_VERSION_MAJOR}::Core libPhoin)
