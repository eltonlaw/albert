cmake_minimum_required(VERSION 3.6.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT temperature-sensor)
project(${PROJECT} VERSION 1.0.0 LANGUAGES CXX)

add_subdirectory(src)
