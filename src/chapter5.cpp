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
  std::random_device rnd;
  const int kN = 7;//rnd() % 10 + 2;
  const int kW = 1000;//rnd() % 10 + 5;

  std::vector<long long> weight(kN), value(kN);

  //for (int i = 0; i < kN; ++i) {
  //  weight[i] = rnd() % 10;
  //  value[i] = rnd() % 10;
  //}
  weight.assign({2,1,3,2,1,5});
  value.assign({3,2,6,1,3,85});

  std::vector<std::vector<long long>>dp;
  dp.assign(kN+1, std::vector<long long>(kW+1, 0LL));

  for (int i = 0; i < kN; ++i) {
    for (int w = 0; w < kW; ++w) {
      if (weight[i] <= w && value[i] > dp[i][w]) dp[i][w] = value[i];
    }
  }

  // NOTE: 品物番号i 番までを選んだ場合
  for (int i = 0; i < kN; ++i) {

    // NOTE: ナップザック重量上限値までの全重量を探索
    for (int w = 0; w <= kW; ++w) {

      /*
       * NOTE:
       *   i+1番, 重さwの時の価値が最大になる場合を求める
       *   i番目までの品物から重さwになるように選んだ場合の最大価値
       *     i+1番目の品物を選んだ場合、i+1番目の価値とi番目までの価値を比較する
       *     i+1番目の品物を選ばなかった場合、i番目までの価値を比較する
       */
      if (w-weight[i] >= 0) {
        dp[i+1][w] = chmax(dp[i+1][w], dp[i][w-weight[i]]+value[i]);
      }

      dp[i+1][w] = chmax(dp[i+1][w], dp[i][w]);
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
