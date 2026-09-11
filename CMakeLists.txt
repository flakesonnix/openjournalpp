cmake_minimum_required(VERSION 3.25)

project(OpenJournal
        VERSION 0.1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(sdk)
add_subdirectory(examples)
add_subdirectory(tests)