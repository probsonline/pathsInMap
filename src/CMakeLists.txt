add_library(mapTraversal "")

target_sources(
    mapTraversal
    PRIVATE
        mapTraversal.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/mapTraversal.h
    )

target_include_directories(
    mapTraversal
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
