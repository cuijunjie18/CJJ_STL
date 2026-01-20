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
    EXPECT_EQ(data.get_alloc_size(), 10000);
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
    EXPECT_EQ(data.get_alloc_size(), 40000);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}