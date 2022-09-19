// Copyright 2022 saito
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int N = rand() % 10 + 2;
  N = 10;

  std::vector<int> a(N);

  for (int i = 0; i < N; ++i)
  {
    a[i] = rand();
  }

  std::sort(a.begin(), a.end());

  std::cout << a[1] << std::endl;

  return 0;
}
