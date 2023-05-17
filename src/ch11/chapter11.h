// Copyright 2023 saito
#include <iostream>
#include <vector>


namespace chapter11 {
struct UnionFind {
  std::vector<int> par_, siz_;

  UnionFind(int n) : par_(n, -1), siz_(n, 1) {}

  int root(int x) {
    if (par_[x] == -1) return x;

    return par_[x] = root(par_[x]);
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);

    if (x == y) return false;

    if (siz_[x] < siz_[y]) std::swap(x, y);

    par_[y] = x;
    siz_[x] += siz_[y];

    return true;
  }

  int size(int x) {
    return siz_[root(x)];
  }
};

void code11_4();
}  // namespace chapter11
