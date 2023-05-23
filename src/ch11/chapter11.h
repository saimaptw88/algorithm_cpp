// Copyright 2023 saito
#include <iostream>
#include <map>
#include <random>
#include <vector>


namespace chapter11 {
struct UnionFind {
  std::vector<int> par_;  // 各頂点の親番号
  std::vector<int> siz_;  // 各根付き木の頂点数

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

struct WeightedUnionFind : public UnionFind {
  std::vector<double> diff_weight_;

  WeightedUnionFind(int n) : UnionFind(n), diff_weight_(n, 0.0) {}

  int root(int x) {
    if (par_[x] == -1) return x;

    diff_weight_[x] += diff_weight_[par_[x]];

    return par_[x] = root(par_[x]);
  }

  bool unite(int x, int y, double w) {
    w += weight(x);
    w -= weight(y);

    x = root(x);
    y = root(y);

    if (x == y) return false;

    if (siz_[x] < siz_[y]) std::swap(x, y), w *= -1;

    par_[y] = x;
    siz_[x] += siz_[y];

    diff_weight_[y] = w;

    return true;
  }

  double weight(int x) {
    root(x);

    return diff_weight_[x];
  }

  double diff(int x, int y) {
    return weight(x) - weight(y);
  }
};

void code11_4();

namespace question1 {
void exec();
}  // namespace question1

namespace question2 {
void exec();
}  // namespace question2

void question3();

namespace question4 {
void exec();
}  // namespace question4
}  // namespace chapter11
