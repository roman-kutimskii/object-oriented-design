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
        History.cpp
        Image.cpp
        Menu.cpp
        MockCommand.h
        MockDocument.h
        MockExporter.h
        MockHistory.h
        MockImage.h
        MockMenu.h
        MockParagraph.h
        MockUndoableCommand.h
        Paragraph.cpp
        command/Exit.cpp
        command/Help.cpp
        command/List.cpp
        command/Redo.cpp
        command/Undo.cpp
)
target_link_libraries(command_tests GTest::gtest_main GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(command_tests)
