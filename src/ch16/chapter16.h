#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
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

void execute() {
  Question1::FordFulkerson ff;
  ff.exec();
}


};  // namespace chapter16
