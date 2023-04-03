#include "chapter6.h"

int sum(int a, int b) { return a+ b; }

int chapter6::binary_search(int key) {
  const int N = 8;
  const std::vector<int> a = { 3, 5, 8, 10, 14, 17, 21, 39 };

  int left = 0;
  int right = static_cast<int>(a.size() - 1);

  while (right >= left) {
    const int mid = (right + left) * 0.5;

    if (a[mid] == key) return mid;
    else if (a[mid] > key) right = mid - 1;
    else if (a[mid] < key) left = mid + 1;
  }

  return -1;
}

int chapter6::binary_age() {
  const int left = 20;
  const int right = 36;

  int l = left, r = right;
  while (r-l > 1) {
    const int mid = (r+l) / 2;

    std::cout << "Is your age over than " << mid << "? (Y/n)" << std::endl;

    std::string ans;
    std::cin >> ans;

    if (ans == "y" || ans == "Y") {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  std::cout << l << std::endl;
  return l;
}

int chapter6::binary_search_lower_bound(std::vector<int>a, std::vector<int>b, int K, int N) {
  std::sort(b.begin(), b.end());

  int min_value = 100000;
  for (int i = 0; i < N; ++i) {
    auto iter = std::lower_bound(b.begin(), b.end(), K-a[i]);
    int val = *iter;

    if (a[i] + val < min_value) {
      min_value = a[i] + val;
    }
  }

  return min_value;
}

int chapter6::shoot_king() {
  std::random_device rnd;

  const int N = rnd() % 10 + 2;
  std::vector<int> H(N), S(N);

  for (int i = 0; i < N; ++i) {
    H[i] = rnd() % 10;
    S[i] = rnd() % 10;
  }

  int left = 0, right = 10000;

  while (right - left > 1) {
    const int mid = (right + left) / 2;
    bool ok = true;

    std::vector<int> t(N, 0);
    for (int i = 0; i < N; ++i) {
      if (mid < H[i]) ok = false;
      else t[i] = (mid - H[i]) / S[i];
    }

    std::sort(t.begin(), t.end());
    for (int i = 0; i < N; ++i) {
      if (t[i] < i) ok = false;
    }

    if (ok) right = mid;
    else left = mid;
  }

  return right;
}

void chapter6::question1(const int N, const std::vector<int> a, std::vector<int>* num) {
  // 実装方針
  // 各値aiに対して2分探索を行いそれぞれが何番目に小さい値かを格納するベクトルnumを返す
  // int N: ベクトルの要素数
  // const std::vector<int>a: 整数列
  // std::vector<int> num: 戻り値
  std::vector<int>a_copy(N);
  std::copy(a.begin(), a.end(), a_copy.begin());

  std::sort(a_copy.begin(), a_copy.end());

  for (int i = 0; i < N; ++i) {
    decltype(a_copy)::iterator itr = std::lower_bound(a_copy.begin(), a_copy.end(), a[i]);
    num->at(i) = std::distance(a_copy.begin(), itr);
  }
}
