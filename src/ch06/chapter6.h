// Copyright 2022 saito
#ifndef SRC_CH06_CHAPTER6_H_
#define SRC_CH06_CHAPTER6_H_


#include <algorithm>
#include <iostream>
#include <random>
#include <vector>


int sum(int, int);

namespace chapter6 {
  int binary_search(int);
  int binary_age();
  int binary_search_lower_bound(std::vector<int>, std::vector<int>, int, int);
  int shoot_king();
}

#endif  // SRC_CH06_CHAPTER6_H_
