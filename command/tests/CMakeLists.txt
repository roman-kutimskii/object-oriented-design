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
        command_tests
        Document.cpp
        DocumentItem.cpp
        Image.cpp
        Menu.cpp
        MockDocument.h
        MockExporter.h
        MockImage.h
        MockParagraph.h
        Paragraph.cpp
        MockCommand.h
        MockUndoableCommand.h
)
target_link_libraries(command_tests GTest::gtest_main GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(command_tests)
