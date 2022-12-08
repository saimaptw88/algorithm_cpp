// Copyright 2022 saito
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

namespace chapter_5 {
  void flog_move();

  namespace relaxation {
    template<class T> void chmin(T& a, T b) {
      if (a > b) a= b;
    }
    void get_transition();
    void hand_out_transition();
    long long rec(int, std::vector<long long>, std::vector<long long>*);
    void recursion();
  }
}
