include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(openjournal-tests
        journal/location_test.cpp
        journal/experience_test.cpp
        journal/ingestion_test.cpp
)

target_link_libraries(openjournal-tests
        PRIVATE
        openjournal-sdk
        GTest::gtest_main
)

gtest_discover_tests(openjournal-tests)
