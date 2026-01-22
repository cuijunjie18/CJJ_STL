#include <gtest/gtest.h>
#include <gtest/internal/gtest-internal.h>
#include "vector.hpp"

class VectorTest : public ::testing::Test {
public:
    void SetUp() {}
    void TearDown() {}
};

TEST_F(VectorTest, VectorNoResize) {
    cstd::vector<int> data;
    EXPECT_EQ(data.size(), 0);

    for (int i = 0; i < 10; i++) {
        data.push_back(i);
    }
    EXPECT_EQ(data.size(), 10);
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(data[i], i);
    }
    EXPECT_EQ(data.capacity(), 10000);
}

TEST_F(VectorTest, VectorResize) {
    cstd::vector<int> data;
    for (int i = 0; i < 20000; i++) {
        data.push_back(i);
    }
    for (int i = 0; i < 20000; i++) {
        EXPECT_EQ(data[i], i);
    }
    EXPECT_EQ(data.size(), 20000);
    EXPECT_EQ(data.capacity(), 40000); // 扩容了两次
}

TEST_F(VectorTest, VectorCustomSize) {
    cstd::vector<int> data(5000);
    EXPECT_EQ(data.size(), 0);
    EXPECT_EQ(data.capacity(), 5000);

    for (int i = 0; i < 6000; i++) {
        data.push_back(i);
    }
    EXPECT_EQ(data.size(), 6000);
    for (int i = 0; i < 6000; i++) {
        EXPECT_EQ(data[i], i);
    }
    EXPECT_EQ(data.capacity(), 10000);
}

TEST_F(VectorTest, VectorCopyConstructor) {
    cstd::vector<int> data;
    for (int i = 0; i < 10000; i++) {
        data.push_back(i);
    }

    cstd::vector<int> data_copy(data);
    EXPECT_EQ(data_copy.size(), 10000);
    EXPECT_EQ(data_copy.capacity(), 20000); // 已经扩容过一次
    for (int i = 0; i < 10000; i++) {
        EXPECT_EQ(data_copy[i], i);
    }
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}