#include <gtest/gtest.h>
#include "stack.hpp"

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

class StackTest : public ::testing::Test {
public:
    void SetUp() {}
    void TearDown() {}
};

TEST_F(StackTest, BasicOperations) {
    cstd::stack<int> s;
    
    // Test empty stack
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0);
    
    // Test push and top
    s.push(10);
    EXPECT_EQ(s.top(), 10);
    EXPECT_EQ(s.size(), 1);
    EXPECT_FALSE(s.empty());
    
    s.push(20);
    s.push(30);
    EXPECT_EQ(s.top(), 30);
    EXPECT_EQ(s.size(), 3);
    
    // Test pop (LIFO order)
    s.pop();
    EXPECT_EQ(s.top(), 20);
    EXPECT_EQ(s.size(), 2);
    
    s.pop();
    EXPECT_EQ(s.top(), 10);
    EXPECT_EQ(s.size(), 1);
    
    s.pop();
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0);
}

TEST_F(StackTest, StackWithStrings) {
    cstd::stack<std::string> s;
    
    s.push("first");
    s.push("second");
    s.push("third");
    
    EXPECT_EQ(s.top(), "third");
    EXPECT_EQ(s.size(), 3);
    EXPECT_FALSE(s.empty());
    
    s.pop();
    EXPECT_EQ(s.top(), "second");
    EXPECT_EQ(s.size(), 2);
    
    s.pop();
    EXPECT_EQ(s.top(), "first");
    EXPECT_EQ(s.size(), 1);
    
    s.pop();
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0);
}

TEST_F(StackTest, LargeOperations) {
    cstd::stack<int> s;
    const int N = 1000;
    
    // Push N elements
    for (int i = 0; i < N; ++i) {
        s.push(i);
    }
    
    EXPECT_EQ(s.size(), N);
    EXPECT_EQ(s.top(), N - 1);
    EXPECT_FALSE(s.empty());
    
    // Pop all elements in LIFO order
    for (int i = N - 1; i >= 0; --i) {
        EXPECT_EQ(s.top(), i);
        s.pop();
    }
    
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0);
}

TEST_F(StackTest, MixedOperations) {
    cstd::stack<int> s;
    
    // Mix push and pop operations
    s.push(1);
    s.push(2);
    EXPECT_EQ(s.top(), 2);
    EXPECT_EQ(s.size(), 2);
    
    s.pop();
    EXPECT_EQ(s.top(), 1);
    EXPECT_EQ(s.size(), 1);
    
    s.push(3);
    s.push(4);
    EXPECT_EQ(s.size(), 3);
    EXPECT_EQ(s.top(), 4);
    
    s.pop();
    s.pop();
    EXPECT_EQ(s.top(), 1);
    EXPECT_EQ(s.size(), 1);
    
    s.push(5);
    s.push(6);
    s.push(7);
    EXPECT_EQ(s.size(), 4);
    EXPECT_EQ(s.top(), 7);
}

TEST_F(StackTest, StackWithDemo) {
    cstd::stack<Demo> s;
    
    for (int i = 0; i < 5; ++i) {
        Demo demo;
        s.push(demo);
    }
    
    EXPECT_EQ(s.size(), 5);
    EXPECT_FALSE(s.empty());
    
    // Verify the top element is properly constructed
    EXPECT_EQ(s.top().data_, 0);
    
    // Pop all elements
    while (!s.empty()) {
        s.pop();
    }
    
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0);
}

TEST_F(StackTest, EmptyStackOperations) {
    cstd::stack<int> s;
    
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0);
    
    // Push and pop to make it empty again
    s.push(42);
    EXPECT_FALSE(s.empty());
    EXPECT_EQ(s.size(), 1);
    EXPECT_EQ(s.top(), 42);
    
    s.pop();
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0);
}

TEST_F(StackTest, PerformanceTest) {
    cstd::stack<int> s;
    const int N = 10000;
    
    // Stress test with many operations
    for (int i = 0; i < N; ++i) {
        s.push(i);
        if (i % 2 == 0 && !s.empty()) {
            s.pop();
        }
    }
    
    // Stack should not be empty after these operations
    EXPECT_FALSE(s.empty());
    EXPECT_GT(s.size(), 0);
    
    // Clear the stack
    size_t remaining = s.size();
    for (size_t i = 0; i < remaining; ++i) {
        s.pop();
    }
    
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0);
}