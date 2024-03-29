// Copyright2023 saito
#include <iostream>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>


namespace chapter13 {
using Graph = std::vector<std::vector<int>>;
void search(const Graph &, int);
void dfs(const Graph &, int);

std::vector<int> depth;
std::vector<int> subtree_size;
void dfs(const Graph&, int, int, int);

std::vector<int> bfs(const Graph&, int);
void has_path();

std::vector<int> color;
bool color_is_bool(const Graph&, int, int cur=0);

std::vector<int> order;
void rec(const Graph&, int);

namespace question1 {
void dfs(const Graph&, int);
void bfs(const Graph&, int);
void exec();
}  // namespace question1

namespace question2 {
std::vector<int> dist;
void bfs(const Graph&, int);
void exec();
}  // namespace question2

namespace question3 {
bool bfs(const Graph&, int);
void exec();
}  // namespace question3

namespace question4 {
int bfs(const Graph &, int, int, int, int);
void exec();
}  // namespace question4

namespace question6 {
void dfs(const Graph &, int, int);
void exec();
}  // namespace question3

void execute();
}  // namespace chapter13
