#ifndef _CHAPTER4_H_
#define _CHAPTER4_H_

#include <iostream>
#include <map>
#include <vector>

namespace chapter_4{
  bool func(int N, int W, const std::vector<int>& a);
  int GCD(int m, int n);
  long long fibo(int N, std::vector<long long>& memo);

  int tribo(int N, std::vector<int>* memo);
}

#endif  // _CHAPTER4_H_
