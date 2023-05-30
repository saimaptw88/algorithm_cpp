#include "chapter13.h"


namespace chapter13 {
void search(const Graph& G, int s) {
  const int N = static_cast<int>(G.size());

  std::vector<bool> seen(N, false);
  std::queue<int> todo;

  seen[s] = true;
  todo.push(s);

  while (!todo.empty()) {
    const int v = todo.front();
    todo.pop();

    for (int x : G[v]) {
      if (seen[x]) continue;

      seen[x] = true;
      todo.push(x);
    }
  }
}

std::vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true;

  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;

    dfs(G, next_v);
  }
}

void execute() {
  int N, M;
  std::cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;

    G[a].push_back(b);
  }

  seen.assign(N, false);
  for (int v = 0; v < N; ++v) {
    if (seen[v]) continue;

    dfs(G, v);
  }
}
}
