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

class Question1 {
 public:
  void execute() {
    FordFulkerson ff;
    ff.execute();
  }
 private:
  struct Edge {
    int rev_;
    int from_;
    int to_;
    int cap_;

    Edge(int rev, int from, int to, int cap)
      : rev_(rev), from_(from), to_(to), cap_(cap) {}
  };
  struct Graph {
    std::vector<std::vector<Edge>> list_;

    Graph(int N) : list_(N) {};

    size_t size() {
      return list_.size();
    }

    std::vector<Edge>& operator[] (int i) {
      return list_[i];
    }

    Edge& redge(const Edge& e) {
      return list_[e.to_][e.rev_];
    }

    void run_flow(Edge& e, int f) {
      e.cap_ -= f;
      redge(e).cap_ += f;
    }

    void add_edge(int from, int to, int cap) {
      int fromrev = list_[from].size();
      int torev = list_[to].size();

      list_[from].push_back(Edge(torev, from, to, cap));
      list_[to].push_back(Edge(fromrev, to, from, 0));
    }
  };

  class FordFulkerson {
   public:
    void execute() {
      init();
      int res = solve(0, N_);
      std::cout << res << std::endl;
    }
    FordFulkerson() {}

   private:
    std::shared_ptr<Graph> graph_;
    std::vector<int> seen_, girls_;
    int N_, G_, E_;

    inline void init() {
      std::cin >> N_ >> G_ >> E_;

      graph_ = std::make_shared<Graph>(N_+1);
      girls_ = std::vector<int>(G_);

      for (int i = 0; i < G_; ++i) {
        std::cin >> girls_[i];
      }

      for (int i = 0; i < E_; ++i) {
        int u, v, c=1;
        std::cin >> u >> v;

        graph_->add_edge(u, v, c);
      }

      for (auto v : girls_) {
        graph_->add_edge(v, N_, 1);
      }
    }

    int fodfs(int v, int t, int f) {
      if (v == t)
        return f;

      seen_[v] = true;

      for (auto& e : (*graph_)[v]) {
        if (seen_[e.to_])
          continue;

        if (!e.cap_)
          continue;

        int flow = fodfs(e.to_, t, std::min(f, e.cap_));

        if (!flow)
          continue;

        graph_->run_flow(e, flow);

        return flow;
      }

      return 0;
    }

    int solve(int s, int t) {
      int res = 0;

      for (;;) {
        seen_.assign(graph_->size(), false);
        int flow = fodfs(s, t, INT_MAX);

        if (flow == 0)
          return res;

        res += flow;
      }

      return res;
    }
  };
};

void execute() {
  Question1 q1;
  q1.execute();
}


};  // namespace chapter16
