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

  int n = fibo(6);
  std::cout << n << std::endl;

  auto end = std::chrono::system_clock::now();
  auto dur = end - start;
  auto msec = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();
  std::cout << msec << " micro sec \n";

  return 0;
}
