// Copyright 2022 saito
#include <string>

#include "./ch12/chapter12.h"
#include "./ch11/chapter11.h"
#include "./ch10/chapter10.h"
#include "./ch09/chapter9.h"
#include "./ch08/chapter8.h"
#include "./ch07/chapter7.h"
#include "./ch06/chapter6.h"
#include "./ch05/chapter5.h"
#include "./dp/dp.h"
#include "chapter1.h"
#include "chapter2.h"
#include "chapter3.h"
#include "chapter4.h"


int main() {
  std::vector<int> a{2,1,6,3,4};
  chapter12::QuickSort(a, 0, 5);

  for (const auto& a_ : a) std::cout << a_ << std::endl;

  return 0;
}
