#include "question4.h"

int func(int N){
  if (N==0) return 0;
  return N + func(N - 1);
}

int GCD(int m, int n){
  if (n == 0) return m;

  return GCD(n, m % n);
}

int fibo(int N){
  if(N == 0) return 0;
  else if(N == 1) return 1;

  return fibo(N-1) + fibo(N-2);
}
