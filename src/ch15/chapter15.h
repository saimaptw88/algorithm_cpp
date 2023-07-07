#include <algorithm>
#include <iostream>
#include <vector>

namespace chapter15 {
int sum(int a, int b);

struct UnionFind {
  std::vector<int> par, siz;

  UnionFind(int n) : par(n, -1), siz(n, 1) {}

  int root(int x) {
    if (par[x] == -1) return x;

    return par[x] = root(par[x]);
  }

  bool is_same(int x, int y) { return root(x) == root(y); }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);

    if (x == y) return false;

    if (siz[x] < siz[y]) std::swap(x, y);

    par[y] = x;
    siz[x] += siz[y];

    return true;
  }

  int size(int x) { return siz[root(x)]; }
};

using Edge = std::pair<int, std::pair<int, int>>;

void kruskal_algorithm() {
  int N, M;
  std::cin >> N >> M;

  std::vector<Edge> edges(M);
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;

    edges[i] = Edge(w, std::make_pair(u, v));
  }

  std::sort(edges.begin(), edges.end());

  int64_t res = 0;
  UnionFind uf(N);

  for (int i = 0; i < M; ++i) {
    int w = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;

    if (uf.is_same(u, v)) continue;

    res += w;
    uf.unite(u, v);
  }

  std::cout << res << std::endl;
}

void execute();
}  // namespace chapter15
