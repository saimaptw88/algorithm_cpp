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

  const int fibo_count = 6;
  std::vector<int> fibos(fibo_count + 1);
  for (int i = 0; i <= fibo_count; ++i)
  {
    if (i == 0)
      fibos[i] = 0;
    else if (i == 1)
      fibos[i] = 1;
    else
    {
      fibos[i] = fibos[i - 1] + fibos[i - 2];
    }
  }
  std::cout << "fibos: " << fibos[fibo_count] << std::endl;
  auto end = std::chrono::system_clock::now();
  auto dur = end - start;
  auto msec = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();
  std::cout << msec << " micro sec \n";

  return 0;
}
