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

namespace question3 {
std::vector<int> color;
bool bfs(const Graph &G, int s) {
  std::queue<int> que;

  que.push(s);
  color[s] = 0;

  while (!que.empty()) {
    const int v = que.front();
    que.pop();

    for (auto next_v : G[v]) {
      if (color[next_v] != -1) {
        if (color[next_v] == color[v]) return false;

        continue;
      }

      color[next_v] = 1 - color[v];

      que.push(next_v);
    }
  }

  return true;
}

void exec() {
  int N, M;
  std::cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  color.assign(N, -1);

  for (int i = 0; i < N; ++i) {
    if (color[i] != -1) continue;

    if (!bfs(G, i)) {
      std::cout << "No" << std::endl;
      return;
    }
  }

  std::cout << "Yes" << std::endl;
}
}  // namespace question3

namespace question4 {
int bfs(const Graph &G, int H, int W, int s, int g) {
  std::vector<int> dist(H*W, -1);
  std::queue<int> que;

  que.push(s);
  dist[s] = 0;

  int count = 0;
  while (!que.empty()) {
    const int v = que.front();
    que.pop();

    for (auto next_v : G[v]) {
      if (dist[next_v] != -1)
        dist[next_v] = std::min(dist[next_v], dist[v] + 1);
      else
        dist[next_v] = dist[v] + 1;

      que.push(next_v);
    }

    std::cout << count << std::endl;

    ++count;
  }

  return dist[g];
}
void exec() {
  int H, W;
  std::cin >> H >> W;

  std::vector<std::string> field(H);
  for (auto& f : field) std::cin >> f;

  int sh, sw, gh, gw;
  for (int h = 0; h < H; ++h) {
    for (int w = 0; w < W; ++w) {
      if (field[h][w] == 'S') sh = h, sw = w;
      if (field[h][w] == 'G') gh = h, gw = w;
    }
  }

  using Node = std::pair<int, int>;
  std::queue<Node> que;

  que.push({sh, sw});
  std::vector<std::vector<int>> dist(H, std::vector<int>(W, -1));
  dist[sh][sw] = 0;

  const std::vector<int> dh{1, 0, -1, 0};
  const std::vector<int> dw{0, 1, 0, -1};

  while (!que.empty()) {
    const auto [h, w] = que.front();
    que.pop();

    for (int dir = 0; dir < 4; ++dir) {
      const int nh = h + dh[dir];
      const int nw = w + dw[dir];

      if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;

      if (field[nh][nw] == '#') continue;

      if (dist[nh][nw] == -1) {
        dist[nh][nw] = dist[h][w] + 1;
        que.push({nh, nw});
      }
    }
  }

  std::cout << dist[gh][gw] << std::endl;
}
}  // namespace question4

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
  question4::exec();
}
}  // namespace chapter13
