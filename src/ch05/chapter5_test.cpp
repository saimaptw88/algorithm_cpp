// Copyright 2023 saito
#include "../../src/ch05/chapter5.h"

#include <gtest/gtest.h>

#include <cassert>

// NOTE: 同値テストのみ
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

TEST(question_6, false_at_random_retest_1) {
  // NOTE:
  // 下記条件だとTrueになるはずだがFalseになったので再テスト
  const int kN = 4;
  const int kW = 13;

  std::vector<int> a{ 14, 4, 14, 5 };
  std::vector<int> m{ 5, 4, 2, 2};

  const bool kResult = question_6(kN, kW, a, m);
  EXPECT_TRUE(kResult);
}

TEST(question_6, false_at_random_retest_2) {
  // NOTE:
  // 下記条件だとTrueになるはずだがFalseになったので再テスト
  const int kN = 3;
  const int kW = 20;

  std::vector<int> a{ 12, 4, 9 };
  std::vector<int> m{ 4, 3, 3};

  const bool kResult = question_6(kN, kW, a, m);
  EXPECT_TRUE(kResult);
}

TEST(question_7, same_arguments_test) {
  std::string response = question_7("test", "test");
  EXPECT_EQ("test", response);
}

TEST(question_7, no_same_string_test) {
  std::string response = question_7("abcde", "fghijk");
  EXPECT_EQ("", response);
}

TEST(question_7, normal_case) {
  std::string response = question_7("masahiro", "saito");
  EXPECT_EQ("aio", response);
}

TEST(question_8, normal_case) {
  const int kN = 4;
  const int kM = 1;
  std::vector<int> a{14, 4, 9, 7};

  double response = question_8(kN, kM, a);
  EXPECT_EQ(8.5, response);
}

TEST(question_8, normal_case_2) {
  const int kN = 5;
  const int kM = 3;

  std::vector<int> a{9, 1, 2, 3, 9};

  double response = question_8(kN, kM, a);

  EXPECT_EQ(20.0, response);
}

TEST(question_8, normal_case_3) {
  const int kN = 8;
  const int kM = 3;

  std::vector<int> a{11, 18, 9, 20, 4, 18, 12, 14};

  double response = question_8(kN, kM, a);

  EXPECT_DOUBLE_EQ(45.5, response);
}

TEST(question_9, normal_case_1) {
  const int kN = 4;
  std::vector<int> a{ 10, 20, 30, 40 };

  const int kResult = question_9(kN, a);
  EXPECT_EQ(190, kResult);
}

TEST(question_9, normal_case_2) {
  const int kN = 5;
  std::vector<int> a{ 10, 10, 10, 10, 10 };

  const int kResult = question_9(kN, a);
  EXPECT_EQ(120, kResult);
}

TEST(question_9, normal_case_3) {
  const int kN = 3;
  std::vector<int> a{ 1000000000, 1000000000, 1000000000 };

  const int kResult = question_9(kN, a);
  EXPECT_EQ(5000000000, kResult);
}

TEST(question_9, normal_case_4) {
  const int kN = 6;
  std::vector<int> a{ 7, 6, 8, 6, 1, 1 };

  const int kResult = question_9(kN, a);
  EXPECT_EQ(68, kResult);
}

}  // namespace chapter_5
