// Copyright 2023 @saito
#include "../../src/dp/dp.h"

int hello() {
  std::cout << "hello" << std::endl;
  return 0;
}

int dp::question3(int N, int W, std::vector<int> a) {
  std::vector<std::vector<int>> dp;
  dp.assign(N+1, std::vector<int>(W+1, 0));

  for (int i = 0; i < N; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (w-a[i] >= 0)
        dp[i+1][w] = std::max(dp[i+1][w], dp[i][w-a[i]] + a[i]);

      dp[i+1][w] = std::max(dp[i+1][w], dp[i][w]);
    }
  }

  std::vector<int> kind;
  for (int i = 0; i <= N; ++i) {
    kind.insert(kind.begin(), dp[i].begin(), dp[i].end());
  }

  std::sort(kind.begin(), kind.end());
  kind.erase(std::unique(kind.begin(), kind.end()), kind.end());

  if (!kind[0]) return kind.size() - 1;
  return kind.size();
}
