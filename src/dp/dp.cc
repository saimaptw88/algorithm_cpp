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

void dp::question6() {
  std::random_device rnd;
  int N = rnd() % 10 + 3;
  int W = rnd() % 10 + 3;

  std::vector<int> a(N), m(N);
  for (auto& a_ : a) a_ = rnd() % 10;
  for (auto& m_ : m) m_ = rnd() % 10;

  std::cout << "N=" << N << std::endl;
  std::cout << "W=" << W << std::endl;

  for (int i = 0; i < N; ++i) {
    std::cout << "a[" << i << "]=" << a[i] <<
    ", m[" << i << "]=" << m[i] << std::endl;
  }

  if (question6(N, W, a, m))
    std::cout << "ans=Yes" << std::endl;
  else
    std::cout << "ans=No" << std::endl;
}
bool dp::question6(int N, int W, std::vector<int> a, std::vector<int> m) {
  std::vector<std::vector<bool>> dp;
  dp.assign(N, std::vector<bool>(W+1, false));

  std::vector<std::vector<int>> count;
  count.assign(N, std::vector<int>(W+1, 0));

  for (int i = 0; i < N; ++i) {
    if (a[i] <= W) {
      dp[i][a[i]] = true;
      count[i][a[i]] = 1;
    }

    for (int w = 0; w <= W; ++w) {
      if (i > 0) {
        // NOTE: (i-1,w)=Trueなら、(i,w)もTrue
        if (dp[i-1][w]) dp[i][w] = true;
        // NOTE: (i-1, w-a[i])=Trueなら(i,w)=True
        if (w-a[i] >= 0 && dp[i-1][w-a[i]]) {
          dp[i][w] = true;
          count[i][w] = 1;
        }
      }

      // NOTE: (i, w-a[i])=Trueならm[i]を超えない範囲で(i,w)=True
      if (w-a[i] >= 0 && count[i][w-a[i]] < m[i] && dp[i][w-a[i]]) {
        dp[i][w] = true;
        count[i][w] = count[i][w-a[i]] + 1;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    if (dp[i][W]) return true;
  }
  return false;
}

std::string dp::question7(std::string s, std::string t) {
  std::cout << "s=" << s << std::endl;
  std::cout << "t=" << t << "\n" << std::endl;

  std::vector<std::vector<bool>> dp;
  dp.assign(s.size(), std::vector<bool>(t.size(), false));

  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < t.size(); ++j) {
      if (s[i] == t[j]) dp[i][j] = true;
    }
  }

  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < t.size(); ++j) {
      std::cout << dp[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::string str;

  int start = 0;
  for (int j = 0; j < t.size(); ++j) {
    for (int i = start; i < s.size(); ++i) {
      if (dp[i][j]) {
        str.push_back(t[j]);
        start = i + 1;
        break;
      }
    }
  }

  std::cout << "ans=" << str << std::endl;
  return str;
}
