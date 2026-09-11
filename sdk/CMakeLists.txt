add_library(openjournal-sdk
        src/experience.cpp
        src/location.cpp
        src/ingestion.cpp
        src/substance.cpp
)

target_include_directories(openjournal-sdk
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)