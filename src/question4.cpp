#include "question4.h"

int func(int N){
  if (N==0) return 0;
  return N + func(N - 1);
}

int GCD(int m, int n){
  if (n == 0) return m;

  return GCD(n, m % n);
}

long long fibo(int N, std::vector<long long> memo){
  if(N == 0) return 0;
  else if(N == 1) return 1;

  if (memo[N] != -1) return memo[N];

  return memo[N] = fibo(N-1) + fibo(N-2);
}
