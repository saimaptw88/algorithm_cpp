#include "dp.hh"

int hello() {
  std::cout << "hello" << std::endl;
  return 0;
}

void question5_3() {
  /*
   * 実装方針：
   * ナップザック問題としてキャッシュを作った後、
   * キャッシュ内のユニークな要素数を数える
   */
  std::random_device rnd;
  const int N = 3;
  const int W = 4;

  std::vector<int> a{3, 5, 4};

  std::vector<std::vector<int>> dp;
  dp.assign(N, std::vector<int>(W + 1, 0));

  for (int i = 0; i < N; ++i) {
    for (int w = 0; w < W + 1; ++w) {
      if (i > 0) dp[i][w] = std::max(dp[i][w], dp[i - 1][w]);

      if (w - a[i] >= 0) {
        dp[i][w] = std::max(dp[i][w], dp[i][w - a[i]] + a[i]);
      }
    }
  }

  // NOTE: sort(), unique() が一次元配列のみに対応するための変換
  std::vector<int> cache;
  for (int i = 0; i < N; ++i) {
    cache.insert(cache.end(), dp[i].begin(), dp[i].end());
  }

  std::sort(cache.begin(), cache.end());
  cache.erase(std::unique(cache.begin(), cache.end()), cache.end());

  if (cache[0] == 0) cache.erase(cache.begin());

  std::cout << cache.size() << std::endl;
}
