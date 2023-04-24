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

void chapter7::AGC009A() {
  std::random_device rnd;
  const int N = rnd() % 10 + 3;

  std::vector<long long> A(N), B(N);
  for (int i = 0; i < N; ++i) {
    A[i] = rnd() % 10;
    B[i] = rnd() % 10;
  }

  long long sum = 0LL;

  for (int i = N -1; i > 0; --i) {
    A[i] += sum;
    long long amari = A[i] % B[i];
    long long D = 0LL;

    if (amari != 0) D = B[i] - amari;
    sum += D;
  }

  std::cout << sum << std::endl;
}

int chapter7::question1(const int N, std::vector<int>a, std::vector<int>b) {
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int count = 0;

  for (int i = 0; i < N; ++i) {
    int ind = std::upper_bound(b.begin(), b.end(), a[i]) - b.begin();

    count += N - ind;
  }

  return count;
}

int chapter7::question2(int N, std::vector<std::pair<int, int>>reds, std::vector<std::pair<int, int>>blues) {
  // 青のx座標をソートし、青のx座標xiよりx座標が小さく、青のy座標yiよりy座標が小さい中で最大のものを数える
  std::sort(blues.begin(), blues.end());
  std::sort(reds.begin(), reds.end());

  int count = 0;
  std::vector<bool> used(N, false);

  for (int i = 0; i < N; ++i) {
    int idx = std::lower_bound(reds.begin(), reds.end(), blues[i]) - reds.begin();

    if (!idx) continue;

    std::function<bool(const std::pair<int,int>&, const std::pair<int,int>&)> cmd;
    cmd = [](const std::pair<int,int>&a, const std::pair<int,int>&b) {
      return a.second < b.second;
    };
    idx = std::lower_bound(reds.begin(), reds.end(), blues[i], cmd) - reds.begin();

    if (!idx) continue;
    idx --;

    if (used[idx]) continue;

    count++;
    used[idx] = true;
  }

  return count;
}

bool chapter7::question3(int N, std::vector<int>d, std::vector<int>t) {
  std::vector<std::pair<int, int>> jobs(N);
  for (int i = 0; i < N; ++i) {
    jobs[i].first = t[i] - d[i];
    jobs[i].second = t[i];
  }

  std::function<bool(const std::pair<int,int>&, const std::pair<int, int>&)> cmd;
  cmd = [](const std::pair<int, int>&a, const std::pair<int, int>&b) {
    return a.second < b.second;
  };
  std::sort(jobs.begin(), jobs.end(), cmd);

  int count = 0;
  int end_time = 0;
  for (int i = 0; i < N; ++i) {
    if (jobs[i].first < end_time) continue;

    end_time = jobs[i].second;
    count++;
  }

  return count == N;
}
