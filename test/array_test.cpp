#include <iostream>
#include <memory.h>
#include <gtest/gtest.h>
#include "array.hpp"

class ArrayTest : public ::testing::Test {
public:
    void SetUp(){
    }
    void TearDown(){
        
    }
public:

};

TEST_F(ArrayTest, ArrayWithInt) {
    constexpr int size = 5;
    cstd::array<int, size> data;
    EXPECT_EQ(data.Size(), 5);

    EXPECT_NO_THROW(
        data[0] = 2;
        data[1] = 3;
        data[2] = 5;
    );

    memset(data.Data(), 0, data.Size() * sizeof(int));
    for (int i = 0; i < size; i++) EXPECT_EQ(data[i], 0);
}

TEST_F(ArrayTest, ArrayWithString) {
    constexpr int size = 5;
    cstd::array<std::string, size> data;
    EXPECT_NO_THROW(
        data[0] = "Cherno";
        data[1] = "C++";
    );
}

TEST_F(ArrayTest, ArrayWithConst) {
    const int size = 5;
    const cstd::array<int, size> data{};
    EXPECT_EQ(data[1], 0);
    // data[5] = 10; // 编译时报错
}