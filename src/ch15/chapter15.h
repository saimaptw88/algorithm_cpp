#include <algorithm>
#include <cassert>
#include <iostream>
#include <type_traits>
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

class Question2 {
 public:
  void exec() {
    init();
    kruskal_algorithm();

    std::sort(median_->begin(), median_->end());

    const int half = median_->size() / 2;
    std::cout << median_->at(half) << std::endl;
  }

 private:
  int N_;
  int M_;
  std::unique_ptr<std::vector<int>> median_;

  using Edge = std::pair<int, std::pair<int, int>>;
  std::unique_ptr<std::vector<Edge>> edges_;

  std::unique_ptr<UnionFind> uf_;

  void init() {
    std::cin >> N_ >> M_;
    edges_ = std::make_unique<std::vector<Edge>>(M_);

    for (int i = 0; i < M_; ++i) {
      int u, v, w;

      std::cin >> u >> v >> w;
      edges_->at(i) = Edge(w, std::make_pair(u, v));
    }

    uf_ = std::make_unique<UnionFind>(N_);
  }

  void kruskal_algorithm() {
    std::sort(edges_->begin(), edges_->end());

    for (int i = 0; i < M_; ++i) {
      const int w = edges_->at(i).first;
      const int u = edges_->at(i).second.first;
      const int v = edges_->at(i).second.second;

      if (uf_->is_same(u, v))
        continue;

      uf_->unite(u, v);

      median_->push_back(w);
    }
  }
};
 public:
  void exec();

 private:
  int N_;
  int M_;

  using Edge = std::pair<int, std::pair<int, int>>;
  std::unique_ptr<std::vector<Edge>> edges_;

  std::unique_ptr<UnionFind> uf_;

  void init() {
    std::cin >> N_ >> M_;

    edges_ = std::make_unique<std::vector<Edge>>(M_);

    for (int i = 0; i < M_; ++i) {
      int u, v, w;
      std::cin >> u >> v >> w;

      edges_->at(i) = Edge(w, std::make_pair(u, v));
    }
  }

  void init_edges(const int e) {
    decltype(auto) edges = std::move(edges_);
    std::type_info t = typeid(std::move(edges));
    std::is_same<std::unique_ptr<std::vector<Edge>>, int>::value;

    if (edges_)
      edges_.reset();


  }

  int kruskal_algorithm(const std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end());

    int weight = 0;

    for (int i = 0; i < edges.size(); ++i) {
      const int w = edges.at(i).first;
      const int u = edges.at(i).second.first;
      const int v = edges.at(i).second.second;

      if (uf_->is_same(u, v))
        continue;

      uf_->unite(u, v);

      weight += w;
    }

    return weight;
  }
};
void execute();
}  // namespace chapter15
