# project info
project(
    "my_lib"
    # Author: Minpyo Kim (Min Kim)
    VERSION 1.0
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

# dir for the libs
add_subdirectory("BulletProof")
add_subdirectory("DateTime")
add_subdirectory("MultyOSCom")