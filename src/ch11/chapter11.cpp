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

namespace question2 {
void exec() {
  int N, M;
  std::cin >> N >> M;

  std::vector<int> A(M),B(M);
  for (int i = 0; i < M; ++i) {
    std::cin >> A[i] >> B[i];
    --A[i], --B[i];
  }

  std::vector<int> res(M);
  res[M-1] = (N-1) * N / 2;

  UnionFind uf(N);

  for (int i = M - 1; i >= 0; --i) {
    uf.unite(A[i], B[i]);

    std::vector<int> roots;
    for (int j = 0; j < N; ++j) {
      if (uf.root(j) == j) roots.push_back(j);
    }

    int inconvenience = 0;
    if (roots.size() > 1) {
      for (int bit = 0; bit < (1<<roots.size()); ++bit) {
        int count = 0;
        for (int j = 0; j < roots.size(); ++j) {
          if (bit & (1<<j)) count++;
        }

        if (count != 2) continue;

        int add = 1;
        for (int j = 0; j < roots.size(); ++j) {
          if (bit & (1<<j)) add *= uf.size(roots[j]);
        }

        inconvenience += add;
      }
    }


    if (i == 0) continue;
    res[i-1] = inconvenience;
  }

  for (const auto& r : res) {
    std::cout << r << std::endl;
  }
}
}  // namespace question2

void question3() {
  int N, K, L;
  std::cin >> N >> K >> L;

  UnionFind road(N), train(N);

  for (int i = 0; i < K; ++i) {
    int p, q;
    std::cin >> p >> q;

    road.unite(p - 1, q - 1);
  }

  for (int i = 0; i < L; ++i) {
    int r, s;
    std::cin >> r >> s;

    train.unite(r - 1, s - 1);
  }

  std::vector<int> res(N);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (!road.issame(i, j)) continue;
      if (!train.issame(i, j)) continue;

      res[i]++;
    }
  }

  for (const auto& r : res) {
    std::cout << r << std::endl;
  }
}

namespace question4 {
void exec() {
  int N,M;
  std::cin >> N >> M;

  WeightedUnionFind wuf(N);
  std::vector<int> R(M), L(M), D(M);

  for (int i = 0; i < M; ++i) {
    std::cin >> R[i] >> L[i] >> D[i];

    R[i]--, L[i]--;

    wuf.unite(R[i], L[i], D[i]);
  }

  bool res = true;
  for (int i = 0; i < M; ++i) {
    if (wuf.weight(L[i]) - wuf.weight(R[i]) != D[i]) res = false;
  }

  if (res) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}
}  // namespace question4
}  // namespace chapter11
