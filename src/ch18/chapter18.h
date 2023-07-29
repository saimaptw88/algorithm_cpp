#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>


namespace chapter18 {
namespace sample_1 {
using Graph = std::vector<std::vector<int>>;

std::vector<int64_t> w;
Graph G;

std::vector<int> dp1, dp2;

void dfs(int v, int p = -1) {
  for (auto ch : G[v]) {
    if (ch == p)
      continue;

    dfs(ch, v);
  }

  dp1[v] = 0;
  dp2[v] = w[v];

  for (auto ch : G[v]) {
    if (ch == p)
      continue;

    dp1[v] += std::max(dp1[ch], dp2[ch]);
    dp2[v] += dp1[ch];
  }
}
void exec() {
  int N;
  std::cin >> N;

  w.resize(N);
  for (int i = 0; i < N; ++i)
    std::cin >> w[i];

  G.clear();
  G.resize(N);

  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    std::cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  int root = 0;
  dp1.assign(N, 0);
  dp2.assign(N, 0);
  dfs(root);

  std::cout << std::max(dp1[root], dp2[root]) << std::endl;
}
};  // namespace sample_1

namespace Question1 {
using Graph = std::vector<std::vector<int>>;
Graph G;

std::vector<bool> used;

void rec(const Graph &G, const int v, const int p = -1) {
  bool exist = false;

  for (auto ch : G[v]) {
    if (ch == p)
      continue;

    rec(G, ch, v);

    if (used[ch])
      exist = true;
  }

  if (!exist)
    used[v] = true;
}

void exec() {
  int N;
  std::cin >> N;

  Graph G(N);
  for (int i = 0; i < N; ++i) {
    int u, v;
    std::cin >> u >> v;

    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  used.assign(N, false);

  rec(G, 0);

  int res = 0;
  for (int v = 0; v <N; ++v) {
    if (used[v])
      ++res;
  }

  std::cout << res << std::endl;
}
};  // namespace Question1

namespace Question2 {
using Graph = std::vector<std::vector<int>>;

const int MOD = 100000007;

std::vector<int64_t> dp1, dp2;
void rec(const Graph& G, int v, int p = -1) {
  for (auto ch : G[v]) {
    if (ch == p)
      continue;

    rec(G, ch, v);
  }

  for (auto ch : G[v]) {
    if (ch == p)
      continue;

    dp1[v] = dp1[v] * (dp1[ch] + dp2[ch]) % MOD;
    dp2[v] = dp2[v] * dp1[v] % MOD;
  }
}

void exec() {
  int N;
  std::cin >> N;

  Graph G(N);
  for (int i = 0; i < N; ++i) {
    int u, v;
    std::cin >> u >> v;

    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dp1.assign(N, 1);
  dp2.assign(N, 1);

  rec(G, 0);

  std::cout << (dp1[0]+dp2[0]) % MOD << std::endl;
}
};  // namespace Question2
};  // namespace chapter18
