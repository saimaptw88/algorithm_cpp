// Copyright 2022 saito
#ifndef SRC_CH06_CHAPTER6_H_
#define SRC_CH06_CHAPTER6_H_


#include <algorithm>
#include <functional>
#include <limits>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>


int sum(int, int);

namespace chapter6 {
  int binary_search(int);
  int binary_age();
  int binary_search_lower_bound(std::vector<int>, std::vector<int>, int, int);
  int shoot_king();
  void question1(int, const std::vector<int>, std::vector<int>*);
  int question2(int, const std::vector<int>, const std::vector<int>, const std::vector<int>);
  int question3(int, int, const std::vector<int>&);
  int question4(int, int, const std::vector<int>&);
  int question5(int, int, const std::vector<int>&, const std::vector<int>&);
  float question6(int, int, int);
  unsigned int question7(int, std::vector<unsigned int>);
}

#endif  // SRC_CH06_CHAPTER6_H_
