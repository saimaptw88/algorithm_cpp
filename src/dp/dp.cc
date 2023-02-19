// Copyright 2023 @saito
#include "../../src/dp/dp.h"

int hello() {
  std::cout << "hello" << std::endl;
  return 0;
}

void dp::question3() {
  std::random_device rnd;
  int N = rnd() % 10 + 3;
  int W = rnd() % 10 + 4;

  std::vector<int> a(N);
  for (auto &a_ : a) a_ = rnd() % 10;

  std::cout << "N=" << N << std::endl;
  std::cout << "W=" << W << std::endl;
  for (int i = 0; i < N; ++i)
    std::cout << "a[" << i << "]=" << a[i] << std::endl;
  std::cout << "ans=" << question3(N, W, a) << std::endl;
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

void dp::question4() {
  std::random_device rnd;
  int N = rnd() % 10 + 3;
  int W = rnd() % 10 + 3;
  int k = N - 2;

  std::vector<int> a(N);
  for (auto& a_ : a) a_ = rnd() % 10;

  std::cout << "N=" << N << std::endl;
  std::cout << "W=" << W << std::endl;
  std::cout << "k=" << k << std::endl;

  for (int i = 0; i < N; ++i) {
    std::cout << "a[" << i << "]=" << a[i] << std::endl;
  }

  std::string str = "No";
  if (question4(N, W, k, a)) str = "Yes";

  std::cout << "ans=" << str << std::endl;
}
bool dp::question4(int N, int W, int k, std::vector<int> a) {
  std::vector<std::vector<int>> dp, count;
  dp.assign(N+1, std::vector<int>(W+1, 0));
  count.assign(N+1, std::vector<int>(W+1, 0));

  for (int i = 0; i < N; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (w-a[i] >= 0) {
        int add_num = dp[i][w-a[i]] + a[i];
        dp[i+1][w] = std::max(dp[i+1][w], add_num);

        if (dp[i+1][w] == add_num) count[i+1][w] = count[i][w-a[i]] + 1;
      }

      dp[i+1][w] = std::max(dp[i+1][w], dp[i][w]);
      count[i+1][w] = std::max(count[i+1][w], count[i][w]);
    }
  }

  for (int i = 0; i < N+1; ++i) {
    if (dp[i][W] == W && count[i][W] <= k) return true;
  }

  return false;
}

void dp::question5() {
  std::random_device rnd;
  int N = rnd() % 10 + 3;
  int W = rnd() % 10 + 3;

  std::vector<int> a(N);
  for (auto& a_ : a) a_ = rnd() % 10;

  std::cout << "N=" << N << std::endl;
  std::cout << "W=" << W << std::endl;

  for (int i = 0; i < N; ++i) {
    std::cout << "a[" << i << "]=" << a[i] << std::endl;
  }

  std::string str = "No";
  if (question5(N, W, a)) str = "Yes";

  std::cout << "ans=" << str << std::endl;
}
bool dp::question5(int N, int W, std::vector<int> a) {
  std::vector<std::vector<int>> dp;
  dp.assign(N, std::vector<int>(W+1, 0));

  for (int i = 0; i < N; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (w-a[i] >= 0)
        dp[i][w] = std::max(dp[i][w], dp[i][w-a[i]] + a[i]);

      if (i > 0)
        dp[i][w] = std::max(dp[i][w], dp[i-1][w]);
    }
  }

  return (dp[N-1][W] == W);
}
