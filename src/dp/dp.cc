#include "dp.hh"

int hello() {
  std::cout << "hello" << std::endl;
  return 0;
}

void question5_3() {
  std::random_device rnd;
  const int N = rnd() % 10 + 3;
  const int W = rnd() % 10 + 4;

  std::vector<int> a(N, 0);
  for (int i = 0; i < N; ++i) {
    a[i] = rnd();
  }

  std::vector<std::vector<int>> dp;
  dp.assign(N, std::vector<int>(W, 0));

  for (int i = 0; i < N; ++i) {
    for (int w = 0; w < W; ++w) {
      if (i > 0) dp[i][w] = std::max(dp[i][w], dp[i - 1][w]);

      if (w - a[i] > 0) {
        dp[i][w] = std::max(dp[i][w], dp[i][w - a[i]] + a[i]);
      }
    }
  }

  std::cout << dp[N - 1][W - 1] << std::endl;
}
