#include <gtest/gtest.h>
#include <gtest/internal/gtest-internal.h>
#include "vector.hpp"

class Demo {
public:
    Demo() {
        data_ = 0;
        std::cout << "Demo default constructor" << std::endl;
    }
    ~Demo() {
        data_ = -1;
        std::cout << "Demo destructor" << std::endl;
    }
    int data_;
};

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
    EXPECT_EQ(data.capacity(), 16); // 初始容量为16
}

TEST_F(VectorTest, VectorResize) {
    cstd::vector<int> data;
    for (int i = 0; i < 32; i++) {
        data.push_back(i);
    }
    for (int i = 0; i < 32; i++) {
        EXPECT_EQ(data[i], i);
    }
    EXPECT_EQ(data.size(), 32);
    EXPECT_EQ(data.capacity(), 64); // 扩容了两次
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
    for (int i = 0; i < 31; i++) {
        data.push_back(i);
    }

    cstd::vector<int> data_copy(data);
    EXPECT_EQ(data_copy.size(), 31);
    EXPECT_EQ(data_copy.capacity(), 32); // 已经扩容过一次
    for (int i = 0; i < 31; i++) {
        EXPECT_EQ(data_copy[i], i);
    }
}

TEST_F(VectorTest, VectorWithDemo) {
    cstd::vector<Demo> data;
    for (int i = 0; i < 5; i++) {
        Demo demo;
        data.push_back(demo);
    }
    EXPECT_EQ(data.size(), 5);
    EXPECT_EQ(data.capacity(), 16);
    for (int i = 0; i < 5; i++) {
        EXPECT_NE(data[i].data_, -1); // 目前的vector实现没有基于allocator，所以析构函数不会被调用
    }
}