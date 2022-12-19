// Copyright 2022 saito
#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

namespace chapter_5 {
  void flog_move();

  namespace relaxation {
    template<class T> void chmin(T& a, T b) {
      if (a>b) a = b;
    }
    void flog_move();
    void flog_move_deliver();
    long long recursion_search(int i, std::vector<long long>h, std::vector<long long>*dp);
  }
  namespace knapsack {
    template<class T>T chmax(T a, T b) {
      if (a < b) return b;
      return a;
    }

    void execute();
  }
  namespace edit_distance {
    template<class T> void chmin(T& a, T b) {
      if (a > b) a = b;
    }

    void execute();
  }
  namespace section_division {
    template<class T> void chmin(T &a, T b) {
      if (a > b) a = b;
    }

    void execute();
  }

  void question_1();
  namespace question_2 {
    void execute();
    bool func(int i, int W, std::vector<int>a, std::vector<std::vector<int>>*dp);
  }
  namespace question_3 {
    void execute();
    void func(int, int, std::vector<int>, std::vector<std::vector<int>>*, int*);
  }
}
