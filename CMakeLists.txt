# minimume verstion requried for cmake
cmake_minimum_required (VERSION 3.10)

# project info
project(
    "ThermalCalculater"
    VERSION 0.5
    LANGUAGES CXX
)

# setting the standared for cpp
set(CMAKE_CXX_STANDARD 11)

# if there is no build type commend, build as release
if(NOT CMAKE_BUILD_TYPE)
#    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_BUILD_TYPE "Release")
endif(NOT CMAKE_BUILD_TYPE)

# compiler setting excetp for MSCC (windows)
if (!MSVC)
    add_compile_options(-Wall -O2)
endif()

# Include sub-projects.
add_subdirectory("src") # libray dir
add_subdirectory("ThermalCalculater") # main ptoject dir