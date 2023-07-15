#include <iostream>
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

void execute() {
  FordFulkerson ff;
  ff.execute();
}


};  // namespace chapter16
