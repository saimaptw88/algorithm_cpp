#include "question4.h"

bool section_4::func(int N, int W, const std::vector<int>&a){
  if (N==0) {
    if (W == 0) return true;

    return false;
  }

  if (func(N-1, W, a)) return true;
  if (func(N-1, W-a[N-1], a)) return true;

  return false;
}

int section_4::GCD(int m, int n){
  if (n == 0) return m;

  return GCD(n, m % n);
}

long long section_4::fibo(int N, std::vector<long long>& memo){
  if(N == 0) return memo[N] = 0;
  else if(N == 1) return memo[N] = 1;

  if (memo[N] != -1) return memo[N];

  return memo[N] = fibo(N-1, memo) + fibo(N-2, memo);
}

  int section_4::tribo(int N, std::vector<int>* memo) {
    if (N == 0) return 0;
    if (N == 1) return 0;
    if (N == 2) return 1;

    if (memo->at(N) != -1) return memo->at(N);

    memo->at(N) = section_4::tribo(N-1, memo) +
                  section_4::tribo(N-2, memo) +
                  section_4::tribo(N-3, memo);
    return memo->at(N);
  }
