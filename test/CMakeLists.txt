set(TEST_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
find_package(GTest REQUIRED)

add_executable(
    array_test
    ${TEST_SRC_DIR}/array_test.cpp
)
target_link_libraries(array_test PRIVATE
    GTest::GTest
)

add_executable(
    vector_test
    ${TEST_SRC_DIR}/vector_test.cpp
)
target_link_libraries(vector_test PRIVATE
    GTest::GTest
)

add_executable(
    string_test
    ${TEST_SRC_DIR}/string_test.cpp
)
target_link_libraries(string_test PRIVATE
    GTest::GTest
)