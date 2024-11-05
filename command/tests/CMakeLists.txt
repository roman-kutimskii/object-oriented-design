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
        main.cpp
        ConstDocumentItem.cpp
        DocumentItem.cpp
        History.cpp
        MockDocument.h
        MockImage.h
        MockParagraph.h
        command/DocumentCommand.cpp
        command/MockCommand.h
        command/InsertParagraph.cpp
        command/InsertImage.cpp
        command/SetTitle.cpp
        command/ResizeImage.cpp
        command/MarkDeleted.cpp
)
target_link_libraries(command_tests GTest::gtest_main GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(command_tests)
