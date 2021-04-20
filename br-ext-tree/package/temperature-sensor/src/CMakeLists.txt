if(NOT DEFINED SOURCES)
    file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp)
    list(FILTER SOURCES EXCLUDE REGEX ".*/main.cpp$")
endif()
if(NOT DEFINED HEADERS)
    file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*/*.h*)
endif()

find_package(sdbusplus)

set(LIBS
    systemd
    sdbusplus
    pthread
    )

add_executable(${PROJECT}
    main.cpp
    server.cpp
    error.cpp
    ${SOURCES}
    ${HEADERS}
    )

target_link_libraries(${PROJECT} ${LIBS})
