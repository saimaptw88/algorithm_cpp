#include "question3.h"

void calculateMaxDifferenceAtSet(){
    int N = rand() % 10 + 2;
  N = 10;

  std::vector<int> a(N);

  for (int i = 0; i < N; ++i)
  {
    a[i] = rand();
  }

  // bit flag　が２つのものを全探索し、差分が最大の組み合わせを探す
  int difference = 0;

  for(int bit = 0; bit < (1<<N); ++bit){
    std::vector<int> b;

    for(int i = 0; i < N; ++i){
      if(bit & (1<<i)){
        b.push_back(i);
      }
    }
    if(b.size() == 2){
      int diff = a[b[0]] - a[b[1]];

      if (diff > difference) difference = diff;
    }
  }


  std::cout << "max difference = " << difference << std::endl;
}

void calculateCountOfHalve(){
  // 全ての要素に対して２で割れる回数を探索して、その最小値を返す
  int N = rand() % 10;
  N = 10;

  std::vector<int> a(N);
  bool is_a_half = true;

  int total_half_count = 10000000;

  for(int i = 0; i < N; ++i){
     a[i] = rand();
     std::cout << "a[" << i << "]: " << a[i] << std::endl;
  }

  for(int i = 0; i < N; ++i){
    int count = 0;

    while(a[i] % 2 == 0){
      a[i] /= 2;
      count ++;
    }

    if(total_half_count > count) {
      total_half_count = count;
    }
  }

  std::cout << "total half count: " << total_half_count << std::endl;
}

void isThreeNumbersSumToBeK(){
  int K = 100;
  int N = 30;

  int count = 0;

  for(int X = 0; X <= K; ++X){
    for(int Y = 0; Y <= K; ++Y){
      int Z = N - X -Y;

      if(Z >= 0 && Z<= K){
        count ++;
      }
    }
  }

  std::cout << "count: " << count << std::endl;
}

void manyFormula(){
  std::cout << "do not know" << std::endl;
}
