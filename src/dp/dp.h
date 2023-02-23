// Copyright 2023 @saito
#ifndef SRC_DP_DP_H_
#define SRC_DP_DP_H_

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int hello();

namespace dp {
void question3();
int question3(int N, int W, std::vector<int> a);

void question4();
bool question4(int N, int W, int k, std::vector<int> a);

void question5();
bool question5(int N, int W, std::vector<int> a);

void question6();
bool question6(int N, int W, std::vector<int> a, std::vector<int> m);
}  // namespace dp

#endif  // SRC_DP_DP_H_
