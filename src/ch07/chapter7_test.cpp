// Copyright 2023 saito
#include "../../src/ch07/chapter7.h"

#include <gtest/gtest.h>


TEST(chapter7, sum_test) {
  EXPECT_EQ(3, sum(1, 2));
}

TEST(chapter7, question1_test_case1) {
  int N = 3;
  std::vector<int> a{0, 1, 2};
  std::vector<int> b{5, 0, 1};

  EXPECT_EQ(4, chapter7::question1(N, a, b));
}

TEST(chapter7, question1_test_case2) {
  int N = 3;
  std::vector<int> a{10, 6, 5};
  std::vector<int> b{5, 0, 1};

  EXPECT_EQ(0, chapter7::question1(N, a, b));
}

TEST(chapter7, question2_test_case1) {
  int N = 3;
  std::vector<std::pair<int, int>> reds{std::make_pair(3, 8),
                                     std::make_pair(2, 9),
                                     std::make_pair(2, 4)};
  std::vector<std::pair<int, int>> blues{{3, 5}, {2, 4}, {6, 4}};

  EXPECT_EQ(1, chapter7::question2(N, reds, blues));
}

TEST(chapter7, question2_test_case2) {
  int N = 4;
  std::vector<std::pair<int, int>> reds{std::make_pair(3, 8),
                                     std::make_pair(2, 9),
                                     std::make_pair(2, 4),
                                     std::make_pair(1, 3)};
  std::vector<std::pair<int, int>> blues{{3, 5}, {2, 4}, {6, 4}, {1, 3}};

  EXPECT_EQ(2, chapter7::question2(N, reds, blues));
}

TEST(chapter7, question3_test_case1) {
  int N = 1;
  std::vector<int> d{2};
  std::vector<int> t{3};

  EXPECT_TRUE(chapter7::question3(N, d, t));
}

TEST(chapter7, question3_test_case2) {
  int N = 2;
  std::vector<int> d{2, 4};
  std::vector<int> t{3, 7};

  EXPECT_TRUE(chapter7::question3(N, d, t));
}

TEST(chapter7, question3_test_case3) {
  int N = 2;
  std::vector<int> d{2, 4};
  std::vector<int> t{3, 6};

  EXPECT_FALSE(chapter7::question3(N, d, t));
}
