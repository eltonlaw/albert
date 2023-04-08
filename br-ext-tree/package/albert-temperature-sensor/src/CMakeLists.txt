if(NOT DEFINED SOURCES)
    file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp)
    list(FILTER SOURCES EXCLUDE REGEX ".*/main.cpp$")
endif()
if(NOT DEFINED HEADERS)
    file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*/*.h*)
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(DBUS REQUIRED dbus-1)

include_directories(${DBUS_INCLUDE_DIRS})
link_directories(${DBUS_LIBRARY_DIRS})

set(LIBS
    pthread
    ${DBUS_LIBRARIES}
    )

add_executable(${PROJECT}
    main.cpp
    ${SOURCES}
    ${HEADERS}
    )

target_link_libraries(${PROJECT} ${LIBS})
