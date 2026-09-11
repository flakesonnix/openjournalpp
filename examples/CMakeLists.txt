add_executable(openjournal-example
        basic.cpp
)

target_link_libraries(openjournal-example
        PRIVATE
        openjournal-sdk
)