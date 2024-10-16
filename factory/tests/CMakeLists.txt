include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        factory_tests
        main.cpp
        Canvas/MockCanvas.h
        Shape/EllipseTest.cpp
        Shape/TriangleTest.cpp
)
target_link_libraries(factory_tests GTest::gtest_main GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(factory_tests)
