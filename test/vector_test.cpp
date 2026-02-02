#include <gtest/gtest.h>
#include <gtest/internal/gtest-internal.h>
#include <algorithm>
#include <string>
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
    for (int i = 0; i < 31; i++) {
        Demo demo;
        data.push_back(demo);
    }
    EXPECT_EQ(data.size(), 31);
    EXPECT_EQ(data.capacity(), 32);
    for (int i = 0; i < 31; i++) {
        EXPECT_NE(data[i].data_, -1); // 目前的vector实现没有基于allocator，所以析构函数不会被调用
    }
}

TEST_F(VectorTest, VectorWithString) {
    cstd::vector<std::string> data;
    for (int i = 0; i < 20; i++) {
        data.push_back("String number " + std::to_string(i));
    }
    EXPECT_EQ(data.size(), 20);
    EXPECT_EQ(data.capacity(), 32);
    for (int i = 0; i < 20; i++) {
        EXPECT_EQ(data[i], "String number " + std::to_string(i));
    }
}

TEST_F(VectorTest, PopBack) {
    cstd::vector<int> data;
    for (int i = 0; i < 10; i++) {
        data.push_back(i);
    }
    EXPECT_EQ(data.size(), 10);
    data.pop_back();
    EXPECT_EQ(data.size(), 9);
    EXPECT_EQ(data[8], 8);
    data.pop_back();
    data.pop_back();
    EXPECT_EQ(data.size(), 7);
    EXPECT_EQ(data[6], 6);
}

TEST_F(VectorTest, UseIterator) {
    cstd::vector<int> data;
    cstd::vector<int>::iterator it;
    for (int i = 0; i < 10; i++) {
        data.push_back(i);
    }
    it = data.begin();
    EXPECT_EQ(*it, 0);
    ++it;
    EXPECT_EQ(*it, 1);
    it += 5;
    EXPECT_EQ(*it, 6);
    int sum = 0;
    for (it = data.begin(); it != data.end(); ++it) {
        sum += *it;
    }
    EXPECT_EQ(sum, 45); // 0+1+2+...+9 = 45
}

// TODO：目前不支持
// TEST_F(VectorTest, UseStdAlgorithm) {
//     cstd::vector<int> data;
//     for (int i = 0; i < 10; i++) {
//         data.push_back(10 - i);
//     }
//     std::sort(data.begin(), data.end());
//     for (int i = 0; i < 10; i++) {
//         EXPECT_EQ(data[i], i + 1);
//     }
// }