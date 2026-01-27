#include "string.hpp"
#include <gtest/gtest.h>

class StringTest : public ::testing::Test {
public:
    void SetUp() override { }
    void TearDown() override { }
};

TEST_F(StringTest, AssignmentFromCString) {
    cstl::string str;
    str = "Hello, World!";
    EXPECT_EQ(str.size(), 13);
    EXPECT_EQ(str[0], 'H');
    EXPECT_EQ(str[7], 'W');
}

TEST_F(StringTest, AssignmentFromAnotherString) {
    cstl::string str1;
    str1 = "Test String";
    cstl::string str2;
    str2 = str1;
    EXPECT_EQ(str2.size(), str1.size());
    EXPECT_TRUE(str2 == str1);
}

int main(int agrc, char* agrv[]) {
    ::testing::InitGoogleTest(&agrc, agrv);
    return RUN_ALL_TESTS();
}

