cmake_minimum_required(VERSION 3.12)

set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(version_cmp)
set(CMAKE_BUILD_TYPE Debug)

set(TEST_SOURCES
    test/main.cc
    test/test_version.cc
)

add_executable(tests ${TEST_SOURCES})
find_package(Catch2 3 REQUIRED)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE src)

include(CTest)
include(Catch)
catch_discover_tests(tests)
