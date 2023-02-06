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
void question5_4() {
  /*
   * 実装方針：
   * ナップザックで解き、解いている途中に使った要素数もカウントする
   */
  const int N = 3;
  const int W = 6;
  const int k = 1;  // 2=True, 1=False

  std::vector<int> a{3, 2, 6};

  std::vector<std::vector<int>> dp;
  dp.assign(N + 1, std::vector<int>(W + 1, 0));

  std::vector<std::vector<int>> count;
  count.assign(N + 1, std::vector<int>(W + 1, 0));

  for (int i = 0; i < N; ++i) {
    for (int w = 0; w < W + 1; ++w) {
      if (w - a[i] >= 0) {
        dp[i + 1][w] = std::max(dp[i + 1][w], dp[i][w - a[i]] + a[i]);

        if (dp[i + 1][w] == dp[i][w - a[i]] + a[i]) count[i + 1][w]++;
      }

      dp[i + 1][w] = std::max(dp[i + 1][w], dp[i][w]);
      count[i + 1][w] = std::max(count[i + 1][w], count[i][w]);
    }
  }

  for (int i = 0; i < N + 1; ++i) {
    if (dp[i][W] == W && count[i][W] <= k) {
      std::cout << "Yes" << std::endl;
      return;
    }
  }
  std::cout << "No" << std::endl;
}
void question5_5() {
  /*
   * 実装方針：
   * ナップザックただし、もらう解法
   * キャッシュi番目計算時は、整数a[i]を可能な限り適応する
   */
  const int N = 3;
  const int W = 3;

  const std::vector<int> a{2, 7, 5};

  std::vector<std::vector<int>> dp;
  dp.assign(N, std::vector<int>(W + 1, 0));

  for (int i = 0; i < N; ++i) {
    for (int w = 0; w < W + 1; ++w) {
      if (i > 0) dp[i][w] = std::max(dp[i][w], dp[i - 1][w]);

      if (w - a[i] >= 0) dp[i][w] = std::max(dp[i][w], dp[i][w - a[i]] + a[i]);
    }
  }

  for (int i = 0; i < N; ++i) {
    if (dp[i][W] == W) {
      std::cout << "Yes" << std::endl;
      return;
    }
  }

  std::cout << "No" << std::endl;
}
void question5_6() {
  const int N = 3;
  const int W = 5;

  const std::vector<int> a{2, 3, 6};
  const std::vector<int> m{1, 3, 2};

  std::vector<std::vector<int>> dp;
  dp.assign(N, std::vector<int>(W + 1, 0));

  for (int i = 0; i < N; ++i) {
    int count = 0;
    for (int w = 0; w < W + 1; ++w) {
      if (i > 0) dp[i][w] = std::max(dp[i][w], dp[i - 1][w]);

      if (w - a[i] >= 0 && count <= m[i]) {
        dp[i][w] = std::max(dp[i][w], dp[i][w - a[i]] + a[i]);

        if (dp[i][w] == dp[i][w - a[i]] + a[i]) count++;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int w = 0; w < W + 1; ++w) {
      std::cout << dp[i][w] << " ";
    }
    std::cout << "\n";
  }

  for (int i = 0; i < N; ++i) {
    if (dp[i][W] == W) {
      std::cout << "Yes" << std::endl;
      return;
    }
  }

  std::cout << "No" << std::endl;
}
