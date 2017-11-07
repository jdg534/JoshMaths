#include "gtest/gtest.h"

#include <iostream>

#include <Math.h>


TEST(FailTest, test)
{
    EXPECT_TRUE(false);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();
    return 0;
}