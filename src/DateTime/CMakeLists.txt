project(DateTime)
include_directories(
    ${BULLET_PHYSICS_SOURCE_DIR}/src
)

add_library(DateTime STATIC
    DateTime.cpp
    DateTime.h
)
