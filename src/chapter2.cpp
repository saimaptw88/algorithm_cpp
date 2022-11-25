#include "chapter2.h"


void chapter_2::question_1() {
  std::cout << "T1(N) = 1000N¥t" << "O(N)" << std::endl;
  std::cout << "T2(N) = 5N^2 + 10N + 7¥t" << "O(N^2)" << std::endl;
  std::cout << "T3(N) = 4N^2 + 3N^3/2¥t" << "O(N^2)" << std::endl;
  std::cout << "T4(N) = N^3/2 + 5NlogN¥t" << "O(N^3/2)" << std::endl;
  std::cout << "T5(N) = 2^N + N^2019¥t" << "O(N^2019)" << std::endl;
}

void chapter_2::question_2() {
  std::cout << "NC3 = " << "O(N^3)" << std::endl;
}

void chapter_2::question_3() {
  std::cout << "O(N)" << std::endl;
}

void chapter_2::question_4() {
  std::cout << "二分探索法の計算量は、log(2^k)であるため0~log(2^k)の探索が可能なため" << std::endl;
}

void chapter_2::question_5() {
  question_4();
  std::cout << "0~Nまでの値を二分探索法で探索する場合は、順々に半分にするためlog(N)" << std::endl;
}

void chapter_2::question_6() {
  // 1 + 1/2 + 1/3 + 1/4 + ... + 1/N
  // 1 + 1/2 = (2 + 1)/2
  // 1 + 1/2 + 1/3 = (6 + 3 + 2)/6
  // 1 + 1/2 + 1/3 + 1/4 = (12 + 6 + 4 + 3)/12
  // (最大公約数/N)/最大公約数
}
