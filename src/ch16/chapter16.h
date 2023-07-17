#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>


namespace chapter16 {
struct Graph {
  struct Edge {
    int rev, from, to, cap;

    Edge(int r, int f, int t, int c) :
      rev(r), from(f), to(t), cap(c) {}
  };

  std::vector<std::vector<Edge>> list;

  Graph(int N = 0) : list(N) {}

  inline size_t size() const {
    return list.size();
  }

  std::vector<Edge> &operator [] (int i) {
    return list[i];
  }

  Edge& redge(const Edge &e) {
    return list[e.to][e.rev];
  }

  void run_flow(Edge &e, int f) {
    e.cap -= f;
    redge(e).cap += f;
  }

  void addedge(int from, int to, int cap) {
    int fromrev = (int)list[from].size();
    int torev = (int)list[to].size();

    list[from].push_back(Edge(torev, from, to, cap));
    list[to].push_back(Edge(fromrev, to, from, 0));
  }
};

class FordFulkerson {
 private:
  const int INF = 1 << 30;
  std::vector<int> seen;


  // 残余グラフ上でs-tパスを見つける(深さ優先探索)
  // 返り値はs-tパス上の容量の最小値(見つからなかったら0)
  // f: sからvへ到達した過程の各辺の容量の最小値
  int fodfs(Graph &G, int v, int t, int f) {
    // スタートとゴールが同じ値の場合
    if (v == t)
      return f;

    seen[v] = true;
    for (auto &e : G[v]) {
      if (seen[e.to])
        continue;

      if (e.cap == 0)
        continue;

      int flow = fodfs(G, e.to, t, std::min(f, e.cap));

      if (flow == 0)
        continue;

      G.run_flow(e, flow);

      return flow;
    }

    return 0;
  }

  int solve(Graph &G, int s, int t) {
    int res = 0;

    while(true) {
      seen.assign((int)G.size(), 0);
      int flow = fodfs(G, s, t, INF);

      if (flow == 0)
        return res;

      res += flow;
    }

    return 0;
  }

 public:
  void execute() {
    int N, M;
    std::cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
      int u, v, c;
      std::cin >> u >> v >> c;

      G.addedge(u, v, c);
    }

    int s = 0, t = N - 1;
    std::cout << solve(G, s, t) << std::endl;
  }

  FordFulkerson() {}
};

namespace Question1 {
struct Edge {
  int to_;
  int from_;
  int rev_;
  int cap_;

  Edge(int from, int to, int rev, int cap)
    : from_(from), to_(to), rev_(rev), cap_(cap) {}
};
struct Graph {
  std::vector<std::vector<Edge>> list_;

  Graph(int N) : list_(N) {}

  std::vector<Edge>& operator[] (int i) {
    return list_[i];
  }

  std::size_t size() const {
    return list_.size();
  }

  Edge& rev_edge(const Edge& e) {
    return list_[e.to_][e.rev_];
  }

  void add_edge(int from, int to, int cap) {
    const auto kFromSize = static_cast<int>(list_[from].size());
    const auto kToSize = static_cast<int>(list_[to].size());

    list_[from].push_back(Edge(from, to, kToSize, cap));
    list_[to].push_back(Edge(to, from, kFromSize, 0));
  }

  void run_flow(Edge& e, int f) {
    e.cap_ -= f;
    rev_edge(e).cap_ += f;
  }
};

class FordFulkerson {
 public:
  void exec() {
    init();
    std::cout << solve(0, N_) << std::endl;
  }

 private:
  int N_, M_, girls_size_;
  std::unique_ptr<Graph> G_;
  std::vector<int> girls_;
  std::vector<int> seen_;

  void init() {
    std::cin >> N_ >> girls_size_ >> M_;

    seen_ = std::vector<int>(N_+1, false);
    girls_ = std::vector<int>(girls_size_);
    for (int i = 0; i < girls_size_; ++i) {
      std::cin >> girls_[i];
    }

    G_ = std::make_unique<Graph>(N_+1);
    for (int i = 0; i < M_; ++i) {
      int u, v, cap=1;
      std::cin >> u >> v;

      G_->add_edge(u, v, cap);
    }

    for (const auto& e : girls_) {
      G_->add_edge(e, N_, 1);
    }
  }
  int fodfs(int v, int t, int f) {
    if (v == t)
      return f;

    seen_[v] = true;

    for (auto& e : (*G_)[v]) {
      if (seen_[e.to_])
        continue;

      if (e.cap_ == 0)
        continue;

      const int min_flow = std::min(f, e.cap_);
      const int flow = fodfs(e.to_, t, min_flow);

      if (flow == 0)
        continue;

      G_->run_flow(e, flow);

      return flow;
    }

    return 0;
  }
  int solve(int s, int t) {
    int res = 0;

    for (;;) {
      seen_.assign(N_+1, false);

      int flow = fodfs(s, t, INT_MAX);

      if (flow == 0)
        return res;

      res += flow;
    }

    return 0;
  }
};
};  // namespace Question1

namespace Question2 {
struct Edge {
  int from_;
  int to_;
  int rev_;
  int cap_;

  Edge(int from, int to, int rev, int cap)
    : from_(from), to_(to), rev_(rev), cap_(cap) {}
};

struct Graph {
  std::vector<std::vector<Edge>> list_;

  Graph(int N) : list_(N) {};

  std::vector<Edge>& operator[] (int i) {
    return list_[i];
  }

  std::size_t size() const {
    return list_.size();
  }

  Edge& rev_edge(const Edge& e) {
    return list_[e.to_][e.rev_];
  }

  void add_edge(int from, int to, int cap) {
    const auto from_rev = static_cast<int>(list_[from].size());
    const auto to_rev = static_cast<int>(list_[to].size());

    list_[from].push_back(Edge(from, to, to_rev, cap));
    list_[to].push_back(Edge(to, from, from_rev, 0));
  }

  void run_flow(Edge& e, int f) {
    e.cap_ -= f;
    rev_edge(e).cap_ += f;
  }
};
class FordFulkerson {
 public:
  FordFulkerson(int N, int M, std::unique_ptr<Graph> G)
    : N_(N), M_(M), G_(std::move(G)), seen_(N) {}

  int calc(int s, int t) {
    int res = 0;

    for (;;) {
      seen_.assign(N_, false);

      int flow = fodfs(s, t, INT_MAX);

      if (flow == 0)
        return res;

      res += flow;
    }

    return 0;
  }

 private:
  int N_, M_;
  std::vector<int> seen_;
  std::unique_ptr<Graph> G_;

  int fodfs(int v, int t, int f) {
    if (v == t)
      return f;

    seen_[v] = true;
    for (auto &e : (*G_)[v]) {
      if (seen_[e.to_])
        continue;

      if (e.cap_ == 0)
        continue;

      const int min_flow = std::min(f, e.cap_);
      const int flow = fodfs(e.to_, t, min_flow);

      if (flow == 0)
        continue;

      G_->run_flow(e, flow);

      return flow;
    }

    return 0;
  }
};
class FroidWarshal {
 public:
  FroidWarshal(int N, const std::vector<std::vector<int64_t>>& dist)
    :N_(N), dp_({dist}) {}

  std::vector<std::vector<int64_t>>* calc() {
    for (int k = 0; k < N_; ++k) {
      for (int i = 0; i < N_; ++i) {
        for (int j = 0; j < N_; ++j) {
          dp_[i][j] = std::min(dp_[i][j], dp_[i][k] + dp_[k][j]);
        }
      }
    }
    for (int i = 0; i < N_; ++i) {
      if (dp_[i][i] < 0)
        is_negative_cycle_exist_ = true;
    }

    return &dp_;
  }

 private:
  std::vector<std::vector<int64_t>> dp_;
  int N_, M_;
  bool is_negative_cycle_exist_ = false;
};

void execute() {
  int N, M, s, t;
  std::cin >> N >> M >> s >> t;

  std::vector<std::vector<int64_t>> dist, cap;
  dist.assign(N, std::vector<int64_t>(N, INT64_MAX));
  cap.assign(N, std::vector<int64_t>(N, INT64_MAX));

  for (int i = 0; i < M; ++i) {
    int64_t u, v, d, c;
    std::cin >> u >> v >> d >> c;

    dist[u][v] = d;
    cap[u][v] = c;
  }

  FroidWarshal fw(N, dist);
  decltype(auto) dp = fw.calc();

  std::unique_ptr<Graph> G(new Graph(N));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j)
        continue;

      if (dp->at(s)[i] + dist[i][j] + dp->at(j)[t] == dp->at(s)[t]) {
        G->add_edge(i, j, cap[i][j]);
      }
    }
  }

  FordFulkerson ff(N, M, std::move(G));
  std::cout << ff.calc(s, t) << std::endl;
}
};  // namespace Question2

namespace Question3 {
struct Edge {
int to_;
int from_;
int rev_;
int cap_;
int icap_;

Edge(int to, int from, int rev, int cap)
  : to_(to), from_(from), rev_(rev), cap_(cap), icap_(cap) {}
};

struct Graph {
  std::vector<std::vector<Edge>> list_;

  Graph(int N = 0) : list_(N) {}

  void add_edge(int to, int from, int cap) {
    const auto from_count = static_cast<int>(list_[from].size());
    const auto to_count = static_cast<int>(list_[to].size());

    list_[from].push_back(Edge(to, from, to_count, cap));
    list_[to].push_back(Edge(from, to, from_count, 0));
  }

  void run_flow(Edge& e, int f) {
    e.cap_ -= f;
    rev_edge(e).cap_ += f;
  }

  Edge& rev_edge(const Edge& e) {
    return list_[e.to_][e.rev_];
  }

  std::vector<Edge>& at(int i) {
    return list_[i];
  }

 private:
  std::vector<Edge>& operator[] (int i) {
    return list_[i];
  }

  std::size_t size() const {
    return list_.size();
  }
};

class FordFulkerson {
 public:
  FordFulkerson() {}
  inline void exec() {
    init();
    const int flow = solve(s_, t_);

    std::vector<int> S(N_, false), T(N_, false);
    S[s_] = true;
    T[t_] = true;

    std::queue<int> que;

    // sから到達可能な点の検索
    que.push(s_);
    while(!que.empty()) {
      const auto v = que.front();
      que.pop();

      for (const auto& e : G_->at(v)) {
        // from -> toへの容量が0以上
        if (e.cap_ > 0 && !S[e.to_]) {
          S[e.to_] = true;
          que.push(e.to_);
        }
      }
    }

    // tへ到達可能な点の検索
    que.push(t_);
    while(!que.empty()) {
      const auto v = que.front();
      que.pop();

      for (const auto& e : G_->at(v)) {
        // to -> from への容量が0以上
        if (G_->rev_edge(e).cap_ > 0 && !T[e.to_]) {
          T[e.to_] = true;
          que.push(e.to_);
        }
      }
    }

    int res = 0;
    for (int v = 0; v < N_; ++v) {
      // tへ到達可能な頂点のうち
      if (T[v]) {
        for (const auto& e : G_->at(v)) {
          // sから到達可能でかつ容量が減っていないもの
          if (e.cap_ > 0 && e.cap_ == e.icap_ && S[e.to_])
            ++res;
        }
      }
    }
    // 多分S, Tの検索条件が逆

    int ma (res ? flow : flow + 1);
    std::cout << ma << " " << res << std::endl;
  }
  inline void init() {
    std::cin >> N_ >> M_ >> s_ >> t_;

    G_ = std::make_shared<Graph>(N_);
    for (int i = 0; i < M_; ++i) {
      int u, v, c;
      std::cin >> u >> v >> c;

      G_->add_edge(v, u, c);
    }

    seen_ = std::vector<int>(N_, false);
  }

 private:
  int N_, M_, s_, t_;
  std::shared_ptr<Graph> G_;

  std::vector<int> seen_;

  inline int fodfs(const int v, const int t, const int f) {
    if (v == t)
      return f;

    seen_[v] = true;

    for (auto& e : G_->at(v)) {
      if (seen_[e.to_])
        continue;

      if (e.cap_ == 0)
        continue;

      const int min_flow = std::min(f, e.cap_);
      const int flow = fodfs(e.to_, t, min_flow);

      if (flow == 0)
        continue;

      G_->run_flow(e, flow);

      return flow;
    }
    return 0;
  }

  inline int solve(const int s, const int t) {
    int res = 0;

    for (;;) {
      seen_.assign(N_, false);

      int flow = fodfs(s, t, INT_MAX);

      if (flow == 0)
        return res;

      res += flow;
    }

    return 0;
  }

  FordFulkerson(const FordFulkerson&) = delete;
  FordFulkerson& operator= (const FordFulkerson&) = delete;
};
};  // namespace Question3
void execute() {
  Question2::execute();
}
};  // namespace chapter16
