project(MultyOSCom)
include_directories(
    ${BULLET_PHYSICS_SOURCE_DIR}/src
)

add_library(MultyOSCom STATIC
    MultyOSCom.cpp
)
