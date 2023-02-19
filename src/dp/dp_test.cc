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
TEST(dp, question4_not_achieve_w) {
  int N = 3;
  int W = 8;
  int k = 3;
  std::vector<int> a{ 2, 3, 4 };

  EXPECT_EQ(false, dp::question4(N, W, k, a));
}
TEST(dp, question4_achive_w_but_over_k) {
  int N = 3;
  int W = 9;
  int k = 2;
  std::vector<int> a{ 2, 3, 4 };

  EXPECT_EQ(false, dp::question4(N, W, k, a));
}
TEST(dp, question4_achive_w) {
  int N = 3;
  int W = 7;
  int k = 2;
  std::vector<int> a{ 2, 3, 4 };

  EXPECT_EQ(true, dp::question4(N, W, k, a));
}
TEST(dp, question5_achive_w) {
  int N = 3;
  int W = 17;
  std::vector<int> a{ 2, 4, 7 };

  EXPECT_TRUE(dp::question5(N, W, a));
}
TEST(dp, question6_achive_w_and_not_over_m) {
  int N = 3;
  int W = 9;
  std::vector<int> a{ 2, 3, 8 };
  std::vector<int> m{ 3, 2, 3 };

  EXPECT_TRUE(dp::question6(N, W, a, m));
}
TEST(dp, question6_achive_w_and_over_m) {
  int N = 3;
  int W = 9;
  std::vector<int> a{ 2, 3, 8 };
  std::vector<int> m{ 2, 2, 3 };

  EXPECT_FALSE(dp::question6(N, W, a, m));
}
TEST(dp, question6_not_achive_w) {
  int N = 3;
  int W = 9;
  std::vector<int> a{ 4, 2, 8 };
  std::vector<int> m{ 3, 2, 3 };

  EXPECT_FALSE(dp::question6(N, W, a, m));
}
