cmake_minimum_required(VERSION 3.6.0)

set(PROJECT joomby)
project(${PROJECT} VERSION 1.0.0 LANGUAGES CXX)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Qml Quick Gui Charts REQUIRED)

qt5_add_resources(QT_RESOURCES qml.qrc)

if(NOT DEFINED SOURCES)
    file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
    list(FILTER SOURCES EXCLUDE REGEX ".*/src/main.cpp$")
endif()
if(NOT DEFINED HEADERS)
    file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
endif()

set(LIBS
    Qt5::Qml
    Qt5::Quick
    Qt5::Gui
    Qt5::Charts
    systemd
    sdbusplus
    pthread
    )

add_executable(${PROJECT}
    src/main.cpp
    ${SOURCES}
    ${HEADERS}
    ${QT_RESOURCES}
    )

target_link_libraries(${PROJECT} ${LIBS})

if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    add_executable(run_tests
        test/test.cpp
        ${SOURCES}
        ${HEADERS}
        ${QT_RESOURCES}
        )
    target_link_libraries(run_tests ${LIBS})
endif( CMAKE_BUILD_TYPE STREQUAL "Debug" )
