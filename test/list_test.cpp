#include <gtest/gtest.h>
#include "list.hpp"

class ListTest : public ::testing::Test {
public:
    void SetUp(){
    }
    void TearDown(){
        
    }
};

TEST_F(ListTest, ListWithInt) {
    cstd::list<int> data;
    EXPECT_NO_THROW(
        data.push_back(2);
        data.push_back(3);
        data.push_front(1);
    );
    EXPECT_EQ(data.size(), 3);
}

TEST_F(ListTest, ListWithString) {
    cstd::list<std::string> data;
    EXPECT_NO_THROW(
        data.push_back("world");
        data.push_front("hello");
    );
    EXPECT_EQ(data.size(), 2);
}

TEST_F(ListTest, PopElements) {
    cstd::list<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    EXPECT_NO_THROW(
        data.pop_front();
        data.pop_back();
    );
    EXPECT_EQ(data.size(), 1);
}

TEST_F(ListTest, CopyConstructor) {
    cstd::list<int> data1;
    data1.push_back(1);
    data1.push_back(2);
    cstd::list<int> data2 = data1; // Copy constructor
    EXPECT_EQ(data2.size(), 2);
}

TEST_F(ListTest, CopyAssignment) {
    cstd::list<int> data1;
    data1.push_back(1);
    data1.push_back(2);
    cstd::list<int> data2;
    data2 = data1; // Copy constructor
    EXPECT_EQ(data2.size(), 2);
}

TEST_F(ListTest, UseIterator) {
    cstd::list<int> data;
    cstd::list<int>::iterator it;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    it = data.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
    int sum = 0;
    for (auto it = data.begin(); it != data.end(); ++it) {
        sum += *it;
    }
    EXPECT_EQ(sum, 6);
}