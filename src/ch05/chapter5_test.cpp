// Copyright 2023 saito
#include "../../src/ch05/chapter5.h"

#include <gtest/gtest.h>

#include <cassert>

namespace chapter_5 {
TEST(question_5, true_test) {
  const int kN = 4;
  const int kW = 10;

  std::vector<int> a{2, 3, 4, 9};

  assert(a.size() == kN);

  const bool kResult = question_5(kN, kW, a);
  EXPECT_TRUE(kResult);
}

TEST(question_5, false_test) {
  const int kN = 3;
  const int kW = 13;

  std::vector<int> a{3, 3, 6};

  assert(a.size() == kN);

  const bool kResult = question_5(kN, kW, a);
  EXPECT_FALSE(kResult);
}

TEST(question_6, true_test) {
  const int kN = 4;
  const int kW = 10;

  std::vector<int>a { 3, 5, 6, 7 };
  std::vector<int>m { 2, 3, 4, 5 };

  const bool kResult = question_6(kN, kW, a, m);
  EXPECT_TRUE(kResult);
}

TEST(question_6, false_test) {
  const int kN = 4;
  const int kW = 10;

  std::vector<int>a { 3, 5, 6, 9 };
  std::vector<int>m { 2, 1, 4, 5 };

  const bool kResult = question_6(kN, kW, a, m);
  EXPECT_FALSE(kResult);
}
}  // namespace chapter_5
