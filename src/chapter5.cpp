#include "chapter5.h"


void chapter_5::flog_move() {
  const long long INF = 1LL << 60;

  std::random_device rnd;

  const unsigned int kN = rnd() % 10;

  std::vector<long long> h(kN);
  for (int i = 0; i < kN; ++i) { h[i] = rnd() % 10; }

  std::vector<long long> dp(kN, INF);
  dp[0] = 0;

  for (int i = 1; i < kN; ++i) {
    if (i == 1) {
      dp[i] = std::abs(h[i] - h[i-1]);
      continue;
    }

    const long long kOneStep = dp[i-1] + std::abs(h[i] - h[i-1]);
    const long long kTwoStep = dp[i-2] + std::abs(h[i] - h[i-2]);

    dp[i] = std::min(kOneStep, kTwoStep);
  }

  std::cout << dp[kN - 1] << std::endl;
}

void chapter_5::relaxation::get_transition() {
  const long long INF = 1LL << 60;

  std::random_device rnd;
  const unsigned int kN = rnd() % 10 + 2;

  std::vector<long long> h(kN);
  for(int i = 0; i < kN; ++i) { h[i] = rnd() % 10; }

  std::vector<long long> dp(kN, INF);
  dp[0] = 0;

  for (int i = 1; i < kN; ++i) {
    const long long kOneStep = dp[i-1] + std::abs(h[i] - h[i-1]);
    chmin(dp[i], kOneStep);

    if (i == 1) continue;

    const long long kTwoStep = dp[i-2] + std::abs(h[i] - h[i-2]);
    chmin(dp[i], kTwoStep);
  }

  std::cout << dp[kN - 1] << std::endl;
}
void chapter_5::relaxation::hand_out_transition() {
  const long long INF = 1LL << 60;

  std::random_device rnd;
  const int kN = rnd() % 10 + 2;

  std::vector<long long>h(kN);
  for(int i =0; i < kN; ++i) { h[i] = rnd() % 10; }

  std::vector<long long>dp(kN, INF);
  dp[0] = 0;

  for (int i = 0; i < kN; ++i) {
    if (i + 1 < kN) {
      const long long kOneStep = dp[i] + std::abs(h[i+1] - h[i]);

      chmin(dp[i+1], kOneStep);
    }

    if (i + 2 < kN) {
      const long long kTwoStep = dp[i] + std::abs(h[i+2] - h[i]);

      chmin(dp[i+2], kTwoStep);
    }
  }

  std::cout << dp[kN - 1] << std::endl;
}
long long chapter_5::relaxation::rec(int i,
  std::vector<long long>h, std::vector<long long>*dp) {
  if (i == 0) return 0LL;

  long long res = 1LL << 60;

  const long long kOneStep = rec(i-1, h, dp) + std::abs(h[i] - h[i-1]);
  chmin(res, rec(i-1, h, dp) + kOneStep);

  if (i > 1) {
    const long long kTwoStep = rec(i-2, h, dp) + std::abs(h[i] - h[i-2]);
    chmin(res, kTwoStep);
  }

  return dp->at(i) = res;
}
void chapter_5::relaxation::recursion() {
  const long long INF = 1LL << 60;

  std::random_device rnd;
  const int kN = rnd() % 10 + 2;

  std::vector<long long> h(kN);
  for(int i = 0; i < kN; ++i) { h[i] = rnd() % 10; }

  std::vector<long long> dp(kN, INF);

  std::cout << rec(kN-1, h, &dp) << std::endl;
}
