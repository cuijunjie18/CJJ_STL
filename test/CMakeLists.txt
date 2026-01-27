set(TEST_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MAIN ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

file(GLOB TEST_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
list(REMOVE_ITEM TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

MESSAGE("Test sources: ${TEST_SOURCES}")

find_package(GTest REQUIRED)

add_executable(
    array_test
    ${MAIN}
    ${TEST_SRC_DIR}/array_test.cpp
)
target_link_libraries(array_test PRIVATE
    GTest::GTest
)

add_executable(
    vector_test
    ${MAIN}
    ${TEST_SRC_DIR}/vector_test.cpp
)
target_link_libraries(vector_test PRIVATE
    GTest::GTest
)

add_executable(
    string_test
    ${MAIN}
    ${TEST_SRC_DIR}/string_test.cpp
)
target_link_libraries(string_test PRIVATE
    GTest::GTest
)

add_executable(
    all_tests
    ${MAIN}
    ${TEST_SOURCES}
)
target_link_libraries(all_tests PRIVATE
    GTest::GTest
)