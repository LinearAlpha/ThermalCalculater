cmake_minimum_required (VERSION 3.8)

# incloud dir
INCLUDE_DIRECTORIES(
    ${BULLET_PHYSICS_SOURCE_DIR}/src
)

# Linking with incloude files
LINK_LIBRARIES(
    BulletProof
    DateTime
    MultyOSCom

)

# lsit of source code
SET(SCR
    ThermalCalculater.cpp
)

# Add source to this project's executable.
add_executable (ThermalCalculater
    ${SCR}
)

