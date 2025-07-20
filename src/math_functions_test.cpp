#include "math_functions.h"

#include <gtest/gtest.h>

TEST(MathFunctionsTest, AddTest) { EXPECT_EQ(add(2, 3), 5); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}