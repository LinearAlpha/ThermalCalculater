INCLUDE_DIRECTORIES( ${BULLET_PHYSICS_SOURCE_DIR}/src)

# BulletProof's src
SET(BulletProof_SRC
    BulletProof/BulletProof.cpp
)
SET(BulletProof_HDR
    BulletProof/BulletProof.h
)

# DateTime's src
SET(DateTime_SRC
    DateTime/DateTime.cpp
)
SET(DateTime_HDR
    DateTime/DateTime.h
)

# MultyOSCom's src
SET(MultyOSCom_SRC
    MultyOSCom/MultyOSCom.cpp
)
SET(MultyOSCom_HDR
    MultyOSCom/MultyOSCom.h
)

# Adding ot libary
ADD_LIBRARY(BulletProof ${BulletProof_SRC} ${BulletProof_HDR})
ADD_LIBRARY(DateTime ${DateTime_SRC} ${DateTime_HDR})
ADD_LIBRARY(MultyOSCom ${MultyOSCom_SRC} ${MultyOSCom_HDR})