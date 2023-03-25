// Copyright 2022 saito
#include <random>

#include "./ch06/chapter6.h"
#include "./ch05/chapter5.h"
#include "./dp/dp.h"
#include "chapter1.h"
#include "chapter2.h"
#include "chapter3.h"
#include "chapter4.h"

int main() {
  int ans = chapter6::binary_search(39);
  std::cout << ans << std::endl;

  return 0;
}
