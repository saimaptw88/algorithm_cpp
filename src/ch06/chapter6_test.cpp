// Copyright 2023 saito
#include "../../src/ch06/chapter6.h"

#include <gtest/gtest.h>


TEST(chapter_06, sum_test) {
  EXPECT_EQ(3, sum(1, 2));
}

TEST(chapter6, binary_search_test_case1) {
  EXPECT_EQ(0, chapter6::binary_search(3));
}

TEST(chapter6, binary_search_test_case2) {
  EXPECT_EQ(7, chapter6::binary_search(39));
}

TEST(chapter6, binary_search_test_case3) {
  EXPECT_EQ(-1, chapter6::binary_search(40));
}

TEST(chapter6, binary_search_test_case4) {
  EXPECT_EQ(-1, chapter6::binary_search(2));
}

TEST(chapter6, binary_search_test_case5) {
  EXPECT_EQ(-1, chapter6::binary_search(6));
}

TEST(chapter6, question1_case1_test) {
  int N = 5;
  std::vector<int> a{ 12, 43, 7, 15, 9 };
  std::vector<int> num(N, 0);
  std::vector<int> expected { 2, 4, 0, 3, 1 };

  chapter6::question1(N, a, &num);

  for (int i = 0; i < N; ++i) {
    EXPECT_EQ(expected[i], num[i]);
  }
}

TEST(chapter6, question1_case2_test) {
  int N = 3;
  std::vector<int> a{ 0, 1, 2 };
  std::vector<int> num(N, 0);
  std::vector<int> expected { 0, 1, 2 };

  chapter6::question1(N, a, &num);

  for (int i = 0; i < N; ++i) {
    EXPECT_EQ(expected[i], num[i]);
  }
}
