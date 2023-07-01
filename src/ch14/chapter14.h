// Copyright 2023 saito
#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
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
 0
 3
 5
 14
 9
 16
 */
  inline void exec() {
    initialize();
    dijkstra();
  }

 private:
  int N_;
  int M_;
  int s_;

  std::unique_ptr<std::vector<int>> dist_;
  std::unique_ptr<std::vector<bool>> used_;

  struct Edge {
    int to_;
    int w_;

    Edge(int to, int w) : to_(to), w_(w) {}
  };
  using Graph = std::vector<std::vector<Edge>>;
  std::unique_ptr<Graph> G_;

  template<class T> bool chmin(T &a, T b) {
    if (b < a) {
      a = b;
      return true;
    }

    return false;
  }
  inline void initialize() {
    std::cin >> N_ >> M_ >> s_;

    G_ = std::make_unique<Graph>(N_);

    dist_ = std::make_unique<std::vector<int>>(N_, INT_MAX);
    dist_->at(s_) = 0;

    used_ = std::make_unique<std::vector<bool>>(N_, false);

    for (int i = 0; i < M_; ++i) {
      int from, to, w;
      std::cin >> from >> to >> w;

      G_->at(from).push_back(Edge(to, w));
    }
  }
  inline void dijkstra() {
    for (int itr = 0; itr < N_; ++itr) {
      int min_dist = INT_MAX;
      int min_v = -1;

      for (int v = 0; v < N_; ++v) {
        if (!used_->at(v) && dist_->at(v) < min_dist) {
          min_dist = dist_->at(v);
          min_v = v;
        }
      }

      if (min_v == -1)
        break;

      for (auto e : G_->at(min_v)) {
        chmin(dist_->at(e.to_), dist_->at(min_v)+e.w_);
      }

      used_->at(min_v) = true;
    }

    for (int v = 0; v < N_; ++v) {
      if (dist_->at(v) < INT_MAX) {
        std::cout << dist_->at(v) << std::endl;
        continue;
      }

      std::cout << "INF" << std::endl;
    }
  }
};

class HeapDijkstraAlgorithm {
 public:
  inline void exec() {
    initialize();
    dijkistra();
  }

 private:
  int N_;
  int M_;
  int s_;

  struct Edge {
    int to_;
    int w_;

    Edge(int to, int w) : to_(to), w_(w) {}
  };

  using Graph = std::vector<std::vector<Edge>>;
  std::unique_ptr<Graph> G_;

  std::unique_ptr<std::vector<int>> dist_;

  template <class T> bool chmin(T &a, T b) {
    if (a > b) {
      a = b;
      return true;
    }

    return false;
  }
  inline void initialize() {
    std::cin >> N_ >> M_ >> s_;

    G_ = std::make_unique<Graph>(N_);
    dist_ = std::make_unique<std::vector<int>>(N_, INT_MAX);
    dist_->at(s_) = 0;

    for (int i = 0; i < M_; ++i) {
      int a, b, w;
      std::cin >> a >> b >> w;

      G_->at(a).push_back(Edge(b, w));
    }
  }
  inline void dijkistra() {
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>> que;

    que.push(std::make_pair(dist_->at(s_), s_));

    while (!que.empty()) {
      const int v = que.top().second;
      const int d = que.top().first;
      que.pop();

      if (d > dist_->at(v))
        continue;

      for (auto e : G_->at(v)) {
        if (chmin(dist_->at(e.to_), dist_->at(v)+e.w_)) {
          que.push(std::make_pair(dist_->at(e.to_), e.to_));
        }
      }
    }

    for (int v = 0; v < N_; ++v) {
      if (dist_->at(v) < INT_MAX) {
        std::cout << dist_->at(v) << std::endl;
        continue;
      }

      std::cout << "INF" << std::endl;
    }
  }
};

class FloydWarshall {
 public:
 /*
  6 9
  0 1 3
  0 2 5
  1 2 4
  1 3 12
  2 3 9
  2 4 4
  3 5 2
  4 3 7
  4 5 8
 */
  void exec() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> dp;
    dp.assign(N, std::vector<int>(N, INT_MAX/2));

    for (int i = 0; i < M; ++i) {
      int a, b, w;
      std::cin >> a >> b >> w;

      dp[a][b] = w;
    }

    for (int i = 0; i < N; ++i)
      dp[i][i] = 0;

    for (int k = 0; k < N; ++k)
      for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
          dp[i][j] = std::min(dp[i][j], dp[i][k]+dp[k][j]);

    bool exist_negative_cycle = false;

    for (int v = 0; v < N; ++v)
      if (dp[v][v] < 0)
        exist_negative_cycle = true;

    if (exist_negative_cycle) {
      std::cout << "NEGATIVE CYCLE" << std::endl;
      return;
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (j)
          std::cout << " ";

        if (dp[i][j] < INT_MAX / 3)
          std::cout << dp[i][j];
        else
          std::cout << "INF";
      }
      std::cout << std::endl;
    }
  }
};

void question1() {
  int N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int64_t>> dp;
  dp.assign(N, std::vector<int64_t>(N, INT32_MIN));

  for (int i = 0; i < M; ++i) {
    int a, b;
    int64_t w;
    std::cin >> a >> b >> w;

    dp[a][b] = w;
  }

  for (int i = 0; i < N; ++i)
    dp[i][i] = 0;

  for (int k = 0; k < N; ++k)
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        dp[i][j] = std::max(dp[i][j], dp[i][k]+dp[k][j]);

  for (int i = 0; i < N; ++i) {
    if (dp[i][i] >= 0)
      continue;

    std::cout << "NEGATIVE CYCLE" << std::endl;
    return;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cout << dp[i][j] << " ";
    }
    std::cout << std::endl;
  }

  int64_t max = INT64_MIN;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (max < dp[i][j])
        max = dp[i][j];

  std::cout << max << std::endl;
}
}  // namespace chapter14
