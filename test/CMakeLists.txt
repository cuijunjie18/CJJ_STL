set(TEST_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MAIN ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

file(GLOB TEST_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
list(REMOVE_ITEM TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

MESSAGE("Test sources: ${TEST_SOURCES}")

find_package(GTest REQUIRED)

# 定义一个函数来创建测试可执行文件
function(add_stl_test TEST_NAME)
    add_executable(${TEST_NAME} ${MAIN} ${TEST_SRC_DIR}/${TEST_NAME}.cpp)
    target_link_libraries(${TEST_NAME} PRIVATE GTest::GTest)
endfunction()

# 获取所有测试文件并自动创建可执行文件
foreach(TEST_SOURCE ${TEST_SOURCES})
    # 提取测试文件名（不带路径和_test.cpp后缀）
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    # string(REPLACE "_test" "" TEST_NAME ${TEST_NAME})
    
    # 创建测试可执行文件
    add_stl_test(${TEST_NAME})
endforeach()

# 集成全部测试
add_executable(
    all_tests
    ${MAIN}
    ${TEST_SOURCES}
)
target_link_libraries(all_tests PRIVATE
    GTest::GTest
)