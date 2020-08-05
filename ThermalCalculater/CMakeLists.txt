# incloud dir
INCLUDE_DIRECTORIES(
    ${BULLET_PHYSICS_SOURCE_DIR}/src
)

set(OUTPUT_FL
    "${CMAKE_PROJECT_NAME}.out"
)

# lsit of source code
SET(SRC_LIST
    ThermalCalculater.cpp
)

# Add source to this project's executable.
add_executable (${OUTPUT_FL}
    ${SRC_LIST}
)
target_link_libraries(${OUTPUT_FL}
    BulletProof
    DateTime
    MultyOSCom
)