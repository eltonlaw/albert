cmake_minimum_required(VERSION 3.1.0)

set(PROJECT pi-main-controller)
project(${PROJECT} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Qml Quick Gui Charts REQUIRED)

qt5_add_resources(QT_RESOURCES qml.qrc)

if(NOT DEFINED SOURCES)
    file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
endif()
if(NOT DEFINED HEADERS)
    file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
endif()

add_executable(${PROJECT}
    ${SOURCES}
    ${HEADERS}
    ${QT_RESOURCES}
    )

target_link_libraries(${PROJECT}
    Qt5::Qml
    Qt5::Quick
    Qt5::Gui
    Qt5::Charts
    )
