#include "chapter3.h"


void chapter_3::full_search() {
  std::random_device rnd;

  const int kN = rnd() % 10;
  const int kV = rnd() % 10;

  std::vector<int> a(kN, 0);

  for (int i = 0; i < kN; ++i) { a[i] = i; }

  for (int i = 0; i < kN; ++i) {
    if (a[i] == kV) {
      std::cout << "True & index:  " << i << std::endl;
      return;
    }
  }

  std::cout << "False" << std::endl;
}
void chapter_3::min() {
  std::random_device rnd;
  const int kN = rnd() % 100;

  std::vector<unsigned int> v(kN, 0);

  for (int i = 0; i < kN; ++i) { v[i] = rnd(); }

  std::cout << "min: " << *std::min_element(v.begin(), v.end()) << std::endl;
}
void chapter_3::pair_additional_min() {
  std::random_device rnd;

  const int kN = rnd() % 100;
  const int kK = 299;

  std::vector<unsigned int> a(kN, 0);
  std::vector<unsigned int> b(kN, 0);

  for(int i = 0; i < kN; ++i) {
    a[i] = rnd() % 100;
    b[i] = rnd() % 100;
  }

  int min = kK + 1;
  for(int i = 0; i < kN; ++i) {
    for (int j = 0; j < kN; ++j) {
      int sum = a[i] + b[j];

      if (sum > kK && sum < min) {
        min = sum;
      }
    }
  }

  std::cout << "min: " << min << ", k: " << kK << std::endl;
}
void chapter_3::partial_sum() {
  std::random_device rnd;

  const int kN = rnd() % 10;
  const int kW = rnd() % 10;

  std::vector<unsigned int> a(kN, 0);
  for(int i = 0; i < kN; ++i) { a[i] = rnd()%10; }

  /*
   * NOTE:
   *   (1 << N) はN桁目が１の二進数を示す
   *   例：N=4 の場合、1000で10進数では8を表す
   *   この場合は、N-1桁の２進数の各桁を a の各要素と紐付け、それぞれの要素が存在するかを確認する
   */
  for (int bit = 0; bit < (1 << kN); ++bit) {
    int sum = 0;

    for (int i = 0; i < kN; ++i) {
      if (bit & (1 << i)) sum += a[i];
    }

    if (sum == kW) {
      std::cout << "True" << std::endl;
      return;
    }
  }

  std::cout << "False" << std::endl;
}
void chapter_3::question_2() {
  std::random_device rnd;

  const int kN = rnd() % 10;
  const int kV = rnd() % 10;

  std::vector<int> a(kN, 0);

  for(int i = 0; i < kN; ++i) { a[i] = rnd() % 10; }

  int count = 0;
  for (int i = 0; i < kN; ++i) {
    if (a[i] == kV) ++count;
  }

  std::cout << count << std::endl;
}
void chapter_3::question_3() {
  std::random_device rnd;

  const int kN = rnd() % 10 + 2;
  std::vector<int> a(kN, 0);

  for (int i = 0; i < kN; ++i) { a[i] = rnd() % 100; }

  const int kMin = *std::min_element(a.begin(), a.end());
  int second_min = *std::max_element(a.begin(), a.end());

  for(int i = 0; i < kN; ++i) {
    if (a[i] > kMin && a[i] < second_min) second_min = a[i];
  }

  std::cout << second_min << std::endl;
}
void chapter_3::question_4() {
  std::random_device rnd;

  const int kN = rnd() % 10 + 2;
  std::vector<int> a(kN, 0);

  for (int i = 0; i < kN; ++i) { a[i] = rnd() % 100; }

  const int kMax = *std::max_element(a.begin(), a.end());
  const int kMin = *std::min_element(a.begin(), a.end());

  std::cout << kMax - kMin << std::endl;
}
void chapter_3::question_5() {
  std::random_device rnd;

  const int kN = rnd() % 10;
  std::vector<unsigned int> a(kN, 0);

  for (int i = 0; i < kN; ++i) { a[i] = rnd() % 100 * 2; }

  // 配列の要素全てが偶数かを判別する関数を定義
  std::function <bool(std::vector<unsigned int>)> is_even_vector;
  is_even_vector = [](std::vector<unsigned int> v) {
    if (std::accumulate(v.begin(), v.end(), 0) == 0) return false;

    return std::all_of(v.begin(), v.end(), [](int x){
      return x % 2 == 0;
    });
  };

  int count = 0;

  while(is_even_vector(a)) {
    for (int i = 0; i < kN; ++i) { a[i] /= 2; }
    ++count;
  }

  std::cout << count << std::endl;
}
void chapter_3::question_6() {
  std::random_device rnd;

  const int kN = rnd() % 10;
  const int kK = rnd() % 10;

  int count = 0;
  for (int x = 0; x <= kK; ++x) {
    for(int y = 0; y <= kK-x; ++y) {
      int z = kN - x - y;
      if (z >= 0 && z <= kK) ++count;
    }
  }

  std::cout
    << "N: " << kN
    << ", K: " << kK
    << ", Count: " << count << std::endl;
}
void chapter_3::question_7() {
  std::random_device rnd;

  const int kN = 3;//rnd() % 10 + 2;  // NOTE: 桁数 N
  const int kS = 125;//rnd() % static_cast<int>(std::pow(10, kN+1));  // NOTE: 文字列S

  /*
   * NOTE:
   *   分割総数：(kN-1)C0 + (kN-1)C1 + ... + (kN-1)C(kN-1) = Sigma_(x=0~kN-1){(kN-1)Cx} 個
   *   実装方針：分割方法を２進数に対応させ、各分割毎の和を足し合わせる
   *   実行例１：kN=3, kS=125, return=176
   *   実行例２：kN=4, kS=1234, return=1736
   */

  int sum = 0;
  for (int bit = 0; bit < (1 << kN-1); ++bit) {  // NOTE: 全分割数 [0 ~ kN-1)
    int S = kS;
    int half_division_sum = 0;

    for (int i = kN-1; i >= 0; --i) {
      if (bit & (1<<i)) {  // NOTE: 桁に分割が指定されていれば分割して足し合わせる
        const int kDigits = std::pow(10, i+1);

        half_division_sum += S / kDigits;  // NOTE: 分割した前半
        S %= kDigits;  // NOTE: 分割した後半
      }
    }
    sum += half_division_sum + S;  // NOTE: 分割の前半分の総和と最後の分割後半の和
  }

  std::cout << sum << std::endl;
}
