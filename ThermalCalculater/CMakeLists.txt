# incloud dir
INCLUDE_DIRECTORIES(
    "${BULLET_PHYSICS_SOURCE_DIR}/src"
    "${BULLET_PHYSICS_SOURCE_DIR}/ThermalCalculater/include"
)

# output file name
set(OUTPUT_FL
    "${CMAKE_PROJECT_NAME}"
)

# lsit of source code
set(SRC_LIST
    "main.cpp"
    "calculation.cpp"
)

# list of headers
set(HDR_LIST
    "include/stdafx.h"
    "include/calculation.h"
)

# Add source to this project's executable.
add_executable (${OUTPUT_FL}
    ${SRC_LIST} ${HDR_LIST}
)

# linking libray
target_link_libraries(${OUTPUT_FL}
    BulletProof
    MultyOSCom    
)