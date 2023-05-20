// Copyright2023 saito
#include "chapter11.h"


namespace chapter11 {
void code11_4() {
  int N, M;
  std::cin >> N >> M;

  UnionFind uf(N);

  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;

    uf.unite(a, b);
  }

  int res = 0;
  for (int x = 0; x < N; ++x) {
    if (uf.root(x) == x) ++res;
  }

  std::cout << res << std::endl;
}

namespace question1 {
struct UF {
  std::vector<int> par_;

  UF() {}
  UF(int n) : par_(n, -1) {}

  void init(int n) { par_.assign(n, -1); }
  int root(int x) {
    if (par_[x] < 0) return x;

    return par_[x] = root(par_[x]);
  }
  bool issame(int x, int y) {
    return root(x) == root(y);
  }
  bool merge(int x, int y) {
    x = root(x);
    y = root(y);

    if (x == y) return false;

    if (par_[x] > par_[y]) std::swap(x, y);

    par_[x] += par_[y];
    par_[y] = x;

    return true;
  }

  int size(int x) {
    return -par_[root(x)];
  }
};
void exec() {
  int N,M;

  std::cin >> N >> M;

  std::vector<int> A(M), B(M);

  for (int i = 0; i < M; ++i) {
    std::cin >> A[i] >> B[i];

    --A[i], --B[i];
  }

  int res = 0;
  for (int e = 0; e < M; ++e) {
    UF uf(N);

    for (int i = 0; i < M; ++i) {
      if (i == e) continue;

      uf.merge(A[i], B[i]);
    }

    int num = 0;
    for (int v = 0; v < N; ++v) {
      if (uf.root(v) == v) num++;
    }

    if (num > 1) res++;
  }

  std::cout << res << std::endl;
}
}  // namespace question1
}  // namespace chapter11
