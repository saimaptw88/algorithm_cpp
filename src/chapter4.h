#ifndef _CHAPTER4_H_
#define _CHAPTER4_H_

#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

namespace chapter_4{
  bool func(int N, int W, const std::vector<int>& a);
  int GCD(int m, int n);
  long long fibo(int N, std::vector<long long>& memo);

  int tribo(int N, std::vector<int>* memo);
  int question_1(int N);
  namespace question_2 {
    class Tribonacci {
      public:
        Tribonacci(int N);

      private:
        std::vector<int> memo_;

        int Execute(int N);
    };
    int execute();
  }
  void question_3();
  void question_4();
  namespace question_5 {
    int count_753(int digit, int k);
    void execute();
  }
  namespace question_6 {
    bool func(int i, int w, const std::vector<int> a, std::vector<std::vector<int>>* memo);
    void execute();
  }
}

#endif  // _CHAPTER4_H_
