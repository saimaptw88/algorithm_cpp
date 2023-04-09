// Copyright 2022 saito
#include <random>
#include <vector>


#include "./ch06/chapter6.h"
#include "./ch05/chapter5.h"
#include "./dp/dp.h"
#include "chapter1.h"
#include "chapter2.h"
#include "chapter3.h"
#include "chapter4.h"

int main() {
  int N = 3;
  std::vector<int> a(N), num(N);
  for (int i = 0; i < N; ++i) { a[i] = i; num[i] = i; }

  chapter6::question1(N, a, &num);

  for (int i = 0; i < N; ++i) {
    std::cout << a[i] << ", " << num[i] << std::endl;
  }
  return 0;
}
