#include "chapter1.h"

int chapter_1::question_1(){
  const int kminAge = 20;
  const int kmaxAge = 36;

  int real_age;
  std::cout << "正解の年齢(20~35): ";
  std::cin >> real_age;

  int min_age = kminAge;
  int max_age = kmaxAge;
  int half_age = (kmaxAge + kminAge) / 2;

  for(int i = 0; i < 4; ++i){
    std::string input;
    std::cout << "あなたの年齢は " << half_age << " 未満ですか？(y/n) >>";
    std::cin >> input;

    if (input == "y" || input == "Y") {
      max_age = half_age;
    } else {
      min_age = half_age;
    }
    half_age = (max_age + min_age) / 2;
  }
  std::cout << "あなたの年齢は " << half_age << " です." << std::endl;
}
void chapter_1::question_2(){
  std::cout << "7回必要" << std::endl;
}
void chapter_1::question_3() {
  int one, two, three, four, five;
  bool finish = false;
  for(int a = 0; a < 10; ++a) {
    for(int b = 0; b < 10; ++b) {
      for(int c = 0; c < 10; ++c) {
        if (c == 0) continue;

        one = 2 * 10 + a;
        two = c * 10 + b;
        three = one * b;
        four = one * c * 10;
        five = three + four;

        if (three / 100 == 0) continue;
        if (four / 100 == 0) continue;
        if(five / 100 == 0) continue;
        if (five / 1000 != 0) continue;

        int expect1 = (three % 100) / 10;
        int expect2 = (five % 100) / 10;

        if (expect1 == 3 && expect2 == 4) {
          std::cout << "expect1: " << expect1 << std::endl;
          std::cout << "expect2: " << expect2 << std::endl;

          finish = true;
          break;
        }
      }
      if (finish) break;
    }
    if (finish) break;
  }

  std::cout << "  " << one << std::endl;
  std::cout << "x " << two << std::endl;
  std::cout << "----" << std::endl;
  std::cout << " " << three << std::endl;
  std::cout << " " << four << std::endl;
  std::cout << " " << five << std::endl;
}
void chapter_1::question_4() {
  int one, two, three, four, five, A, B;
  bool finish = false;

  for(int a = 0; a < 10; ++a){
    for(int b = 0; b < 10; ++b) {
      for (int c = 0; c < 10; ++c) {
        for (int d = 0; d < 10; ++d) {
          for (int e = 0; e < 10; ++e) {
            for (int f = 1; f < 10; ++f) {
              for(int g = 0; g < 10; ++g) {
                for(int h = 0; h < 10; ++h) {
                  for(int i = 0; i < 10; ++i) {
                    for (int j = 1; j < 10; ++j) {
                      A = a + 10*b + 100*c + 1000*d + 10000*e + 100000*f;
                      B = g + 10*h + 100*i + 1000*j;

                      one = A * g;
                      two = A * h * 10;
                      three = A * i * 100;
                      four = A * j * 1000;
                      five = one + two + three + four + five;

                      if (five != A*B) continue;
                      if (one / 10^6 != 0) continue;
                      if (one / 10^5 != 6) continue;
                      if (one / 10^4 != 6) continue;
                      if (two / 10^7 != 0) continue;
                      if (two / 10^6 != 6) continue;
                      if (three / 10^8 == 0) continue;
                      if (three / 10^9 != 0) continue;
                      if (three / 10^6 != 6) continue;
                      if (three / 10^5 != 6) continue;
                      if (three / 10^4 != 6) continue;
                      if (four / 10^9 != 0) continue;
                      if (four / 10^8 == 0) continue;
                      if (four / 10^6 != 6) continue;
                      if (four / 10^3 != 6) continue;
                      if (five / 10^10 != 0) continue;
                      if (five / 10^9 == 0) continue;
                      if (five / 10^5 != 6) continue;
                      if (five / 10^4 != 6) continue;

                      finish = true;

                      if (finish) break;
                    }
                    if (finish) break;
                  }
                  if (finish) break;
                }
                if (finish) break;
              }
              if (finish) break;
            }
            if (finish) break;
          }
          if (finish) break;
        }
        if (finish) break;
      }
      if (finish) break;
    }
    if (finish) break;
  }
  if (!finish) {
    return;
    std::cout << "解なし" << std::endl;
  }

  std::cout << " .   " << A << std::endl;
  std::cout << " .  x" << B << std::endl;
  std::cout << "----------" << std::endl;
  std::cout << " .   " << one << std::endl;
  std::cout << " .  " << two << std::endl;
  std::cout << " " << three << std::endl;
  std::cout << " " << four << std::endl;
  std::cout << "----------" << std::endl;
  std::cout << five << std::endl;
}
