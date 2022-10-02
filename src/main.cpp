// Copyright 2022 saito
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include "question3.h"
#include "question4.h"

int main()
{
  auto start = std::chrono::system_clock::now();

  std::vector<long long> memo;
  memo.assign(50, -1);

  fibo(50, memo);

  for(int i = 0; i < memo.size(); ++i){
    std::cout << i << " 項目: " << memo[i] << std::endl;
  }

  auto end = std::chrono::system_clock::now();
  auto dur = end - start;
  auto msec = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();
  std::cout << msec << " micro sec \n";

  return 0;
}
