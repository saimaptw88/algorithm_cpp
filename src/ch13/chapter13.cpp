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
void dfs(const Graph &G, int v, int p, int d=0) {
  depth[v] = d;

  for (auto c : G[v]) {
    if (c==p) continue;

    dfs(G, c, v, d+1);
  }

  subtree_size[v] = 1;
  for (auto c : G[v]) {
    if (c == p) continue;

    subtree_size[v] += subtree_size[c];
  }
}

std::vector<int> bfs(const Graph &G, int s) {
  const int N = static_cast<int>(G.size());

  std::vector<int> dist(N, -1);
  std::queue<int> que;

  dist[s] = 0;
  que.push(s);

  while(!que.empty()) {
    const int v = que.front();
    que.pop();

    for (int x : G[v]) {
      if (dist[x] != -1) continue;

      dist[x] = dist[v] + 1;
      que.push(x);
    }
  }

  return dist;
}

void has_path() {
  int N, M, s, t;
  std::cin >> N >> M >> s >> t;

  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;
    G[a].push_back(b);
  }

  seen.assign(N, false);

  dfs(G, s);

  if (seen[t]) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}

bool color_is_bool(const Graph &G, int v, int cur) {
  for (auto next_v : G[v]) {
    if (color[next_v] != -1) {
      if (color[next_v] == cur) return false;

      continue;
    }

    if (!color_is_bool(G, next_v, 1-cur)) return false;
  }

  return true;
}

void rec(const Graph &G, int v) {
  seen[v] = true;

  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;

    rec(G, next_v);
  }

  order.push_back(v);
}

namespace question1 {
// 幅優先探索を行い、再起が終了するたびに
std::vector<bool> seen;
void dfs(const Graph &G, int v) {
  seen[v] = true;

  for (auto c : G[v]) {
    if (seen[c]) continue;

    dfs(G, c);
  }
}

std::vector<int> dist;
void bfs(const Graph &G, int s) {
  std::queue<int> que;

  dist[s] = 0;
  que.push(s);

  while(!que.empty()) {
    const int v = que.front();
    que.pop();

    for (auto c : G[v]) {
      if (dist[c] != -1) continue;

      dist[v] = dist[c] + 1;
      que.push(c);
    }
  }
}
void exec() {
  int N,M;
  std::cin >> N >> M;

  seen.assign(N, false);

  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  int count = 0;
  for (int i = 0; i < N; ++i) {
    if (seen[i]) continue;

    dfs(G, i);

    ++count;
  }

  std::cout << count << std::endl;


  dist.assign(N, -1);

  int res = 0;
  for (int i = 0; i < N; ++i) {
    if (dist[i] != -1) continue;

    bfs(G, i);

    ++res;
  }

  std::cout << res << std::endl;
}
}  // namespace question1

namespace question2 {
void bfs(const Graph &G, int s) {
  std::queue<int> que;

  dist[s] = 0;
  que.push(s);

  while (!que.empty()) {
    const int v = que.front();
    que.pop();

    for (auto c : G[v]) {
      if (dist[c] != -1) continue;

      dist[c] = dist[v] + 1;
      que.push(c);
    }
  }
}

void exec() {
  int N, M, s, t;
  std::cin >> N >> M >> s >> t;

  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  dist.assign(N, -1);

  bfs(G, s);

  if (dist[t]) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}
}  // namespace question2

namespace question6 {
std::vector<bool> seen, finished;
int pos;
std::stack<int> hist;

void dfs(const Graph &G, int v, int p) {
  seen[v] = true;
  hist.push(v);

  for (auto next_v : G[v]) {
    if (next_v == p) continue;

    if (finished[next_v]) continue;

    if (seen[next_v]) {
      pos = next_v;
      return;
    }

    dfs(G, next_v, v);

    if (pos != -1) return;
  }

  hist.pop();
  finished[v] = true;
}

void exec() {
  int N, M;
  std::cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;

    --a, --b;

    G[a].push_back(b);
  }

  seen.assign(N, false);
  finished.assign(N, false);

  pos = -1;
  dfs(G, 0, -1);

  std::set<int> cycle;
  while (!hist.empty()) {
    const int t = hist.top();
    hist.pop();

    cycle.insert(t);
    if (t == pos) break;
  }

  int Q;
  std::cin >> Q;

  for (int _ = 0; _ < Q; ++_) {
    int a, b;
    std::cin >> a >> b;
    --a, --b;

    if (cycle.count(a) && cycle.count(b))
      std::cout << 2 << std::endl;
    else
      std::cout << 1 << std::endl;
  }
}
}  // namespace question3

void execute() {
  int N = 4, M = 5;
  std::cout << "N=" << N << ", M=" << M << std::endl;

  Graph G(N);
  std::random_device rnd;

  for (int i = 0; i < M; ++i) {
    int a = rnd() % 4;
    int b = rnd() % 4;

    std::cout << a << " -> " << b << std::endl;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  std::vector<int> dist = bfs(G, 0);
  for (int v = 0; v < N; ++v) {
    std::cout << v << ": " << dist[v] << std::endl;
  }
}
}  // namespace chapter13
