#include <gtest/gtest.h>
#include "queue.hpp"

class QueueTest : public ::testing::Test {
public:
    void SetUp() override {
        // 在每个测试用例之前执行的代码
    }

    void TearDown() override {
        // 在每个测试用例之后执行的代码
    }
};

TEST_F(QueueTest, PushAndPop) {
    queue<int> q(5);
    EXPECT_TRUE(q.empty());

    q.push(1);
    q.push(2);
    q.push(3);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(q.front(), 1);
    EXPECT_EQ(q.back(), 3);

    q.pop();
    EXPECT_EQ(q.front(), 2);
    EXPECT_EQ(q.back(), 3);

    q.pop();
    q.pop();
    EXPECT_TRUE(q.empty());
}

TEST_F(QueueTest, Overflow) {
    queue<int> q(3);
    q.push(1);
    q.push(2);
    q.push(3);
    EXPECT_THROW(q.push(4), std::overflow_error);
}

TEST_F(QueueTest, Underflow) {
    queue<int> q(3);
    EXPECT_THROW(q.pop(), std::underflow_error);
    EXPECT_THROW(q.front(), std::underflow_error);
    EXPECT_THROW(q.back(), std::underflow_error);
}

TEST_F(QueueTest, TestSize) {
    queue<int> q(3);
    EXPECT_EQ(q.size(), 0);
    q.push(1);
    EXPECT_EQ(q.size(), 1);
    q.push(2);
    EXPECT_EQ(q.size(), 2);
    q.push(3);
    EXPECT_EQ(q.size(), 3);
    q.pop();
    EXPECT_EQ(q.size(), 2);
    EXPECT_EQ(q.capacity(), 3);
}