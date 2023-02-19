// Copyright 2023 @saito
#include "../../src/dp/dp.h"

#include <gtest/gtest.h>

TEST(dp, hello_test) { EXPECT_EQ(0, hello()); }
TEST(dp, question3_achieve_w) {
  int N = 3;
  int W = 5;
  std::vector<int> a{2, 3, 4};

  EXPECT_EQ(4, dp::question3(N, W, a));
}
TEST(dp, question3_not_achieve_w) {
  int N = 3;
  int W = 8;
  std::vector<int> a{2, 3, 4};

  EXPECT_EQ(6, dp::question3(N, W, a));
}
