#include "chapter7.h"

int sum(int a, int b) { return a+ b; }

void chapter7::DividedScheduling() {
  std::random_device rnd;
  const int N = rnd() % 10 + 3;

  std::vector<std::pair<int, int>> inter(N);
  for (int i = 0; i < N; ++i) {
    inter[i].first = rnd() % 10;
    inter[i].second = inter[i].first + rnd() % 10;
  }

  std::function<bool(const std::pair<int, int>&, const std::pair<int, int>&)> cmp;
  cmp = [](const std::pair<int, int>&a, const std::pair<int, int>&b) {
    return a.second < b.second;
  };

  std::sort(inter.begin(), inter.end(), cmp);

  int res = 0;
  int current_end_time = 0;
  for (int i = 0; i < N; ++i) {
    if (inter[i].first < current_end_time) continue;

    res++;
    current_end_time = inter[i].second;
  }

  std::cout << res << std::endl;
}
