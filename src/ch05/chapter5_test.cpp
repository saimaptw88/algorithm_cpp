// Copyright 2023 saito
#include "../../src/ch05/chapter5.h"

#include <gtest/gtest.h>

#include <cassert>

namespace chapter_05 {
TEST(question5, true_test) {
  const int kN = 4;
  const int kW = 10;

  std::vector<int> a{2, 3, 4, 9};

  assert(a.size() == kN);

  const bool kResult = chapter_5::question_5(kN, kW, a);
  EXPECT_EQ(true, kResult);
}

TEST(question5, false_test) {
  const int kN = 3;
  const int kW = 13;

  std::vector<int> a{3, 3, 6};

  assert(a.size() == kN);

  const bool kResult = chapter_5::question_5(kN, kW, a);
  EXPECT_EQ(false, kResult);
}
}  // namespace chapter_05
