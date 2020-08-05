project(BulletProof)
include_directories(
    ${BULLET_PHYSICS_SOURCE_DIR}/src
)

add_library(BulletProof STATIC
    BulletProof.cpp
)
