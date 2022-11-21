// Copyright 2022 saito
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <map>
#include <vector>
#include "question3.h"
#include "question4.h"


int main()
{
  int N = 6;
  std::vector<int> memo(N+1, -1);
  memo[0] = 0;
  memo[1] = 0;
  memo[2] = 1;

  std::cout << section_4::tribo(N, &memo) << std::endl;

  return 0;
}
