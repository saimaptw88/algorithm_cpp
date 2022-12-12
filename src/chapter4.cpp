#include "chapter4.h"

bool chapter_4::func(int N, int W, const std::vector<int>&a){
  if (N==0) {
    if (W == 0) return true;

    return false;
  }

  if (func(N-1, W, a)) return true;
  if (func(N-1, W-a[N-1], a)) return true;

  return false;
}
int chapter_4::GCD(int m, int n){
  if (n == 0) return m;

  return GCD(n, m % n);
}
long long chapter_4::fibo(int N, std::vector<long long>& memo){
  if(N == 0) return memo[N] = 0;
  else if(N == 1) return memo[N] = 1;

  if (memo[N] != -1) return memo[N];

  return memo[N] = fibo(N-1, memo) + fibo(N-2, memo);
}
int chapter_4::tribo(int N, std::vector<int>* memo) {
  if (N == 0) return 0;
  if (N == 1) return 0;
  if (N == 2) return 1;

  if (memo->at(N) != -1) return memo->at(N);

  memo->at(N) = tribo(N-1, memo) +
                tribo(N-2, memo) +
                tribo(N-3, memo);
  return memo->at(N);
}
int chapter_4::question_1(int N) {
  if (N == 0) return 0;
  if (N == 1) return 0;
  if (N == 2) return 1;

  return question_1(N-3) + question_1(N-2) + question_1(N-1);
}
chapter_4::question_2::Tribonacci::Tribonacci(int N) {
  std::cout << "N = " << N << std::endl;
  memo_.assign(N+1, -1);

  memo_[0] = 0;
  memo_[1] = 0;
  memo_[2] = 1;

  std::cout << Execute(N) << std::endl;
}
int chapter_4::question_2::Tribonacci::Execute(int N) {
  if (memo_[N] != -1) return memo_[N];

  memo_[N] = Execute(N-3) + Execute(N-2) + Execute(N-1);

  return memo_[N];
}
int chapter_4::question_2::execute() {
  std::random_device rnd;
  const int kN = rnd() % 10 + 3;

  Tribonacci e = Tribonacci(kN);
}
void chapter_4::question_3() {
  std::string url = "https://qiita.com/jkr_2255/items/762d075cb65cbb87e996";
  std::cout << url << " 参照" << std::endl;
}
void chapter_4::question_4() {
  std::cout << "fibo_n = 1/sqrt(5) * ((1+sqrt(5))/2)^n - (1-sqrt(5)/2)^n)" << std::endl;
  std::cout <<  "fibo_n / ((1+sqrt(5))/2)^n = 1/sqrt(5)" << std::endl;
}
int chapter_4::question_5::count_753(int digit, int k){
  // digit 桁で k 以下の 753数　の数を返す
  if (digit == 0) return 0;
  if (digit == 1) return 0;
  if (digit == 2) return 0;

  if (digit == 3) {
    int count = 0;
    for (int a = 3; a <= 7; a+=2) {
      for (int b = 3; b <= 7; b+=2) {
        if (b == a) continue;

        for (int c = 3; c <= 7; c+=2) {
          if (c == b || c == a) continue;

          if (a*100 + b*10 + c <= k) count++;
        }
      }
    }
    return count;
  }

  int num = k / std::pow(10.0, digit-1);

  // digit が 3以外で k と同じ桁の場合、最初の桁の値によって753総数が変わる
  if (num < 10) {
    if (num >= 7)
      return 3 * count_753(digit-1, k);
    else if (num >= 5)
      return 2 * count_753(digit-1, k);
    else
      return count_753(digit-1, k);
  }

  // digit が 3以外で k と同じ桁でないの場合、digit-1 桁の753数に3を掛けた値になる
  return 3 * count_753(digit-1, k);
}
void chapter_4::question_5::execute() {
  // k = 1000, return 6
  // k = 5000, return 12
  // k = 10000, return 18
  std::random_device rnd;
  const int kK = 5000;//rnd() % 10000 + 1000;

  int digit = 0;
  for (int i = 1; i <= kK; i*=10) {
    if (kK / i < 1) break;

    digit++;
  }

  std::cout << count_753(digit, kK) << std::endl;
}
bool chapter_4::question_6::func(int i, int w, const std::vector<int>a, std::vector<std::vector<int>>*memo) {
  if (i == 0){
    if (w == 0) return true;
    else return false;
  }
  if (w < 0) return false;

  // if (func(i-1, w, a, memo)) return true;
  if (memo->at(i).at(w) != -1) return memo->at(i).at(w);
  if (func(i-1, w, a, memo)) return memo->at(i).at(w) = true;

  // if (func(i-1, w-a[i-1], a, memo)) return true;
  if (func(i-1, w-a[i-1], a, memo)) return memo->at(i).at(w) = true;

  return false;
}
void chapter_4::question_6::execute() {
  std::random_device rnd;

  const int kN = rnd() % 10 + 1;
  const int kW = rnd() % 10 + 2;

  std::vector<int> a(kN);
  for (int i = 0; i < kN; ++i) {
    a[i] = rnd() % 10;
  }

  std::vector<std::vector<int>>memo(kN+1, std::vector<int>(kW+1, -1));

  if (func(kN, kW, a, &memo)) std::cout << "yes" << std::endl;
  else std::cout << "no" << std::endl;
}
