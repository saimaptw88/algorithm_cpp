#include "chapter5.h"


void chapter_5::flog_move() {
  std::random_device rnd;

  const int kN = rnd() % 10 + 2;
  const long long kINF = 1LL << 60;

  std::vector<long long> h(kN, 0LL);

  for (int i = 0; i < kN; ++i) {
    h[i] = rnd() % 10;
  }

  std::vector<long long> dp(kN, kINF);
  dp[0] = 0LL;

  for (int i = 1; i < kN; ++i) {
    if(i == 1) {
      dp[i] = std::abs(h[i] - h[i-1]);
      continue;
    } else {
      const long long kHminusOne = dp[i-1] + std::abs(h[i] - h[i-1]);
      const long long kHminusTwo = dp[i-2] + std::abs(h[i] - h[i-2]);

      dp[i] = std::min(kHminusOne, kHminusTwo);
    }
  }

  std::cout << dp[kN-1] << std::endl;
}
void chapter_5::relaxation::flog_move() {
  const long long kINF = 1LL << 60;

  std::random_device rnd;
  const int kN = rnd() % 10 + 2;

  std::vector<long long> h(kN, 0LL);
  for (int i = 0; i < kN; ++i) { h[i] = rnd() % 10; }

  std::vector<long long> dp(kN, kINF);
  dp[0] = 0LL;

  for (int i = 1; i < kN; ++i) {
    const long long kHMinusOne = dp[i-1] + std::abs(h[i] - h[i-1]);

    chmin(dp[i], kHMinusOne);

    if (i > 1) {
      const long long kHminusTwo = dp[i-2] + std::abs(h[i] - h[i-2]);
      chmin(dp[i], kHminusTwo);
    }
  }

  std::cout << dp[kN-1] << std::endl;
}
void chapter_5::relaxation::flog_move_deliver() {
  const long long kINF = 1LL << 60;

  std::random_device rnd;
  const int kN = rnd() % 10 + 2;

  std::vector<long long> h(kN, 0LL);
  for (int i = 0; i < kN; ++i) { h[i] = rnd() % 10; }

  std::vector<long long> dp(kN, kINF);
  dp[0] = 0LL;

  for (int i = 1; i < kN; ++i) {
    if (i < kN-1) {
      const long long kHPlusOne = dp[i] + std::abs(h[i] - h[i+1]);
      chmin(dp[i+1], kHPlusOne);
    }

    if (i < kN-2) {
      const long long kHPlusTwo = dp[i] + std::abs(h[i] - h[i+2]);
      chmin(dp[i+2], kHPlusTwo);
    }
  }

  std::cout << dp[kN-1] << std::endl;
}
long long chapter_5::relaxation::recursion_search(int i, std::vector<long long>h, std::vector<long long>*dp) {
  const long long kINF = 1LL << 60;
  if (dp->at(i) < kINF) return dp->at(i);

  if (i == 0) return dp->at(i) = 0LL;

  long long res = kINF;

  const long long kHMinusOne = recursion_search(i-1, h, dp) + std::abs(h[i]-h[i-1]);
  chmin(res, kHMinusOne);

  if (i > 1) {
    const long long kHMinusTwo = recursion_search(i-2, h, dp) + std::abs(h[i]-h[i-2]);
    chmin(res, kHMinusTwo);
  }

  return dp->at(i) = res;
}
void chapter_5::knapsack::execute() {
  /*
   * ナップザック問題：
   * 品物は重さと価値を持っている
   * 重さWを超えない範囲で品物を選び価値を最大化する
   *
   * 解法：
   * 品物を番号i, 重さw, 価値vで管理する
   * 品物i番まで選んだ場合のそれぞれの重さw にて価値の最大値を更新する
   */
  const int kN = 6;
  const int kW = 15;

  std::vector<int> weight(kN), value(kN);

  weight.assign({2, 1, 3, 2, 1, 5});
  value.assign({3, 2, 6, 1, 3, 85});

  std::vector<std::vector<int>> dp(kN+1, std::vector<int>(kW+1, 0));

  /*
   * i番目の品物を選んだ場合
   */
  for (int i = 0; i < kN; ++i) {
    for (int w = 0; w < kW+1; ++w) {
      // i+1番目の品物を選ばない場合、価値はi番目までの価値と等価
      dp[i+1][w] = std::max(dp[i+1][w], dp[i][w]);

      // i+1番目の品物を選んだ場合、価値はi番目までの価値と、i番目の価値にi+1番目の価値を追加したものの大きい方
      if (w - weight[i] >= 0) {  // NOTE: 不等号なのは、複数の品物を選んでいた場合も含みたいから
        dp[i+1][w] = std::max(dp[i+1][w], dp[i][w - weight[i]] + value[i]);
      }
    }
  }

  for (int i = 0; i < kN+1; ++i) {
    if(i==0)
      for(int w = 0; w < kW+1; ++w) {
        if (w == 0) std::cout << "\t";
        std::cout << w << "\t";

        if (w == kW) std::cout << "\n";
      }

    for (int w = 0; w < kW+1; ++w) {
      if (w == 0) std::cout << i << "\t";

      std::cout << dp[i][w] << "\t";

      if (w == kW) std::cout << std::endl;;
    }
  }

  std::cout << dp[kN][kW] << std::endl;
}
void chapter_5::edit_distance::execute() {
  const int kINF = 1 << 29;
  std::string S, T;

  S = "logistic";
  T = "algorithm";

  std::vector<std::vector<int>> dp(S.size()+1, std::vector<int>(T.size()+1, kINF));
  dp[0][0] = 0;

  for (int i = 0; i <= S.size(); ++i) {
    for (int j = 0; j <= T.size(); ++j) {

      // 変更操作
      if (i > 0 && j > 0) {
        if (S[i-1] == T[j-1]) {
          // NOTE: 同じ文字の場合、操作不要
          chmin(dp[i][j], dp[i-1][j-1]);
        } else {
          // NOTE: 同じ文字でない場合、変更操作
          chmin(dp[i][j], dp[i-1][j-1]+1);
        }
      }

      // 削除操作
      // NOTE: 文字列Sのiになるために要素削除を実行する場合、i-1番目の類似度+1
      if (i > 0) chmin(dp[i][j], dp[i-1][j]+1);

      // 挿入操作
      // NOTE: 文字列Sに一文字挿入= 文字列Tから一文字削除
      // 文字列Tのi番目になるために要素削除を実行する場合、j-1番目の類似度+1
      if (j > 0) chmin(dp[i][j], dp[i][j-1]+1);
    }
  }

  std::cout << dp[S.size()][T.size()] << std::endl;
}
void chapter_5::section_division::execute() {
  std::random_device rnd;

  const int kN = rnd() % 10 + 10;
  std::vector<std::vector<long long>> c(kN+1, std::vector<long long>(kN+1));

  for (int i = 0; i < kN+1; ++i) {
    for (int j = 0; j < kN+1; ++j) {
      c[j][i] = rnd() % 10 + 1;
    }
  }

  const long long kINF = 1LL << 60;
  std::vector<long long> dp(kN+1, kINF);
  dp[0] = 0LL;

  for (int i = 0; i <= kN; ++i) {
    for (int j = 0; j < i; ++j) {
      chmin(dp[i], dp[j]+c[j][i]);
    }
  }

  std::cout << dp[kN] << std::endl;
}
void chapter_5::question_1() {
  /*
   * i日目の幸福度は、i-1日目の幸福度 + Max(ai, bi, ci)
   */

  std::random_device rnd;
  const int kN = rnd() % 10;

  std::vector<int> a(kN), b(kN), c(kN);
  for (int i = 0; i < kN; ++i) {
    a[i] = rnd() % 10;
    b[i] = rnd() % 10;
    c[i] = rnd() % 10;
  }

  int previous_activity = -1;

  std::function<int(int, int, int)> activity;
  activity = [&previous_activity](int a_i, int b_i, int c_i) {
    std::vector<int> i {a_i, b_i, c_i};

    decltype(i)::iterator max_itr = std::max_element(i.begin(), i.end());
    int max_index = std::distance(i.begin(), max_itr);

    if (previous_activity != max_index) {
      previous_activity = max_index;

      return *max_itr;
    }

    // 前回同じ行動をとった場合、今回分の行動を削除し最大値を再探索
    i[max_index] = -1;

    max_itr = std::max_element(i.begin(), i.end());
    max_index = std::distance(i.begin(), max_itr);

    previous_activity = max_index;

    return *max_itr;
  };

  std::vector<int> dp(kN, 0);
  dp[0] = 0;

  for (int i = 1; i < kN; ++i) {
    dp[i] = dp[i-1] + activity(a[i], b[i], c[i]);
  }

  std::cout << dp[kN-1] << std::endl;
}
void chapter_5::question_2::execute() {
  // 普通にやったらO(2^N)
  std::random_device rnd;

  const int kN = rnd() % 10 + 2;
  const int kW = rnd() % 10 + 10;

  std::cout << "N: " << kN << ", W: " << kW << std::endl;

  std::vector<int> a(kN, 0);
  for (int i = 0; i < kN; ++i) { a[i] = rnd() % 10; std::cout << a[i] << std::endl;}

  std::vector<std::vector<int>>dp(kN+1, std::vector<int>(kW+1, -1));

  if (func(kN, kW, a, &dp)) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}
bool chapter_5::question_2::func(int i, int w, std::vector<int>a, std::vector<std::vector<int>>* dp) {
  if (i == 0) {
    if (w == 0) return true;
    else return false;
  }

  if (w < 0) return false;

  if (dp->at(i).at(w) != -1) return dp->at(i).at(w);
  if (func(i-1, w, a, dp)) return dp->at(i).at(w) = true;

  if (func(i-1, w-a[i-1], a, dp)) return dp->at(i).at(w) = true;

  return false;
}
void chapter_5::question_3::execute() {
  std::random_device rnd;

  const int kN = rnd() % 10 + 2;
  const int kW = rnd() % 10 + 3;

  std::vector<int>a(kN, 0);
  for (int i = 0; i < kN; ++i) { a[i] = rnd() % 10; }

  int count = 0;
  std::vector<std::vector<int>> dp(kN+1, std::vector<int>(kW+1, -1));
  func(kN, kW, a, &dp, &count);

  std::cout << count << std::endl;
}
void chapter_5::question_3::func(int i, int w, std::vector<int>a, std::vector<std::vector<int>>* dp, int* count) {
  if (w <= 0) { count++; return;}

  func(i-1, w, a, dp, count);
  func(i-1, w-a[i-1], a, dp, count);
}
