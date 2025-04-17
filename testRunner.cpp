#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(initialTest, someTest)
{
    ASSERT_TRUE(false);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}