// Copyright 2023 saito
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
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

    // |V|回の緩和を実施
    for (int iter = 0; iter < N; ++iter) {
      bool update = false;

      for (int v = 0; v < N; ++v) {
        if (dist[v] == kInf_) continue;

        // 辺のみ緩和
        for (auto e : G[v]) {
          if (chmin(dist[e.to_], dist[v]+e.weight_))
            update = true;
        }
      }

      if (!update) break;

      // |V|回目に更新された場合は閉路を報告
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

class DijkstraAlgorithm {
 protected:
  const int64_t kInf = INT64_MAX;

  struct Edge {
    int to_;
    int64_t w_;

    Edge(int to, int64_t w): to_(to), w_(w) {}
  };

  using Graph = std::vector<std::vector<Edge>>;

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
  input:
  6 9 0
  0 1 3
  0 2 5
  1 2 4
  1 3 12
  2 3 9
  2 4 4
  3 5 2
  4 3 7
  4 5 8

  output:
  0 3 5 14 9 16
  */
  virtual void exec() {
    int N, M, s;
    std::cin >> N >> M >> s;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
      int a, b;
      int64_t w;
      std::cin >> a >> b >> w;

      G[a].push_back(Edge(b, w));
    }

    std::vector<bool> used(N, false);
    std::vector<int64_t> dist(N, kInf);
    dist[0] = 0;

    for (int itr = 0; itr < N; ++itr) {
      int64_t min_dist = kInf;
      int min_v = -1;

      for (int v = 0; v < N; ++v) {
        if (!used[v] && dist[v] < min_dist) {
          min_dist = dist[v];
          min_v = v;
        }
      }

      if (min_v == -1) break;

      for (auto e : G[min_v]) {
        chmin(dist[e.to_], dist[min_v]+e.w_);
      }

      used[min_v] = true;
    }

    for (int v = 0; v < N; ++v) {
      if (dist[v] < kInf)
        std::cout << dist[v] << std::endl;
      else
        std::cout << "INF" << std::endl;
    }
  }
};

class UpdatedDijkstraAlgorithm : public DijkstraAlgorithm{
 public:
  void exec() override {
    int N, M, s;
    std::cin >> N >> M >> s;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
      int a, b;
      int64_t w;
      std::cin >> a >> b >> w;

      G[a].push_back(Edge(b, w));
    }

    std::vector<int64_t> dist(N, kInf);
    dist[s] = 0;

    using Pair = std::pair<int64_t, int>;
    std::priority_queue<Pair,
                        std::vector<Pair>,
                        std::greater<Pair>> que;

    que.push(std::make_pair(dist[s], s));

    while (!que.empty()) {
      const int v = que.top().second;
      const int64_t d = que.top().first;
      que.pop();

      if (d > dist[v]) continue;

      for (auto e : G[v]) {
        if (chmin(dist[e.to_], dist[v]+e.w_)) {
          que.push(std::make_pair(dist[e.to_], e.to_));
        }
      }
    }

    for (int v = 0; v < N; ++v) {
      if (dist[v] < kInf)
        std::cout << dist[v] << std::endl;
      else
        std::cout << "INF" << std::endl;
    }
  }
};

class FloydWarshall {
 private:
  const int64_t kInf = INT64_MAX;

 public:
  void exec() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int64_t>> dp;
    dp.assign(N, std::vector<int64_t>(N, kInf));

    for (int _ = 0; _ < M; ++_) {
      int a, b;
      int64_t w;
      std::cin >> a >> b >> w;

      dp[a][b] = w;
    }

    for (int v = 0; v < N; ++v) {
      dp[v][v] = 0;
    }

    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          dp[i][j] = std::min(dp[i][j], dp[i][k]+dp[k][j]);
        }
      }
    }

    bool exist_negative_cycle = false;
    for (int v = 0; v < N; ++v) {
      if (dp[v][v] < 0)
        exist_negative_cycle = true;
    }

    if (exist_negative_cycle) {
      std::cout << "NEGETIVE CYCLE" << std::endl;
      return;
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (j) std::cout << " ";

        if (dp[i][j] < kInf / 2)
          std::cout << dp[i][j];
        else
          std::cout << "INF";
      }

      std::cout << std::endl;
    }
  }
};
}  // namespace chapter14
