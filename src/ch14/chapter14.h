// Copyright 2023 saito
#include <iostream>
#include <vector>


namespace chapter14 {
void execute();
class BellmanFord {
 private:
  const std::int64_t kInf_ = UINT64_MAX;

  struct Edge_ {
    int to_;
    std::int64_t weight_;

    Edge_(int to, int64_t weight) : to_(to), weight_(weight) {}
  };

  using Graph = std::vector<std::vector<Edge_>>;

  template<class T>
  bool chmin(T& a, T b) {
    if (a > b) {
      a = b;
      return true;
    }

    return false;
  }

 public:
 /*
intput;
6 12 0
0 1 3
0 3 100
1 3 57
3 1 -5
1 2 50
1 4 -4
2 3 -10
2 4 -5
2 5 100
4 3 25
4 2 57
4 5 8

output:
0
3
53
24
-1
7
 */
  void exec() {
    int N, M, s;
    std::cin >> N >> M >> s;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
      int a, b;
      std::int64_t w;
      std::cin >> a >> b >> w;

      G[a].push_back(Edge_(b, w));
    }

    bool exist_negarive_cycle = false;
    std::vector<std::int64_t> dist(N, kInf_);
    dist[s] = 0;

    for (int iter = 0; iter < N; ++iter) {
      bool update = false;

      for (int v = 0; v < N; ++v) {
        if (dist[v] == kInf_) continue;

        for (auto e : G[v]) {
          if (chmin(dist[e.to_], dist[v]+e.weight_))
            update = true;
        }
      }

      if (!update) break;

      if (iter == N-1 && update)
        exist_negarive_cycle = true;
    }

    if (exist_negarive_cycle) {
      std::cout << "NEGATIVE CYCLE" << std::endl;
      return;
    }

    for (int v = 0; v < N; ++v) {
      if (dist[v] < kInf_) {
        std::cout << dist[v] << std::endl;
        continue;
      }

      std::cout << "INF" << std::endl;
    }
  }
};
}  // namespace chapter14
