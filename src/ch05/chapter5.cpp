#include "chapter5.h"


void chapter_5::flog_move() {
  std::random_device rnd;

  const int kN = rnd() % 10 + 2;
  const long long kINF = 1LL << 60;

  std::vector<long long> h(kN, 0LL);

  for (int i = 0; i < kN; ++i) {
    h[i] = rnd() % 10;
  }

  std::vector<long long> dp(kN, kINF);
  dp[0] = 0LL;

  for (int i = 1; i < kN; ++i) {
    if(i == 1) {
      dp[i] = std::abs(h[i] - h[i-1]);
      continue;
    } else {
      const long long kHminusOne = dp[i-1] + std::abs(h[i] - h[i-1]);
      const long long kHminusTwo = dp[i-2] + std::abs(h[i] - h[i-2]);

      dp[i] = std::min(kHminusOne, kHminusTwo);
    }
  }

  std::cout << dp[kN-1] << std::endl;
}
void chapter_5::relaxation::flog_move() {
  const long long kINF = 1LL << 60;

  std::random_device rnd;
  const int kN = rnd() % 10 + 2;

  std::vector<long long> h(kN, 0LL);
  for (int i = 0; i < kN; ++i) { h[i] = rnd() % 10; }

  std::vector<long long> dp(kN, kINF);
  dp[0] = 0LL;

  for (int i = 1; i < kN; ++i) {
    const long long kHMinusOne = dp[i-1] + std::abs(h[i] - h[i-1]);

    chmin(dp[i], kHMinusOne);

    if (i > 1) {
      const long long kHminusTwo = dp[i-2] + std::abs(h[i] - h[i-2]);
      chmin(dp[i], kHminusTwo);
    }
  }

  std::cout << dp[kN-1] << std::endl;
}
void chapter_5::relaxation::flog_move_deliver() {
  const long long kINF = 1LL << 60;

  std::random_device rnd;
  const int kN = rnd() % 10 + 2;

  std::vector<long long> h(kN, 0LL);
  for (int i = 0; i < kN; ++i) { h[i] = rnd() % 10; }

  std::vector<long long> dp(kN, kINF);
  dp[0] = 0LL;

  for (int i = 1; i < kN; ++i) {
    if (i < kN-1) {
      const long long kHPlusOne = dp[i] + std::abs(h[i] - h[i+1]);
      chmin(dp[i+1], kHPlusOne);
    }

    if (i < kN-2) {
      const long long kHPlusTwo = dp[i] + std::abs(h[i] - h[i+2]);
      chmin(dp[i+2], kHPlusTwo);
    }
  }

  std::cout << dp[kN-1] << std::endl;
}
long long chapter_5::relaxation::recursion_search(int i, std::vector<long long>h, std::vector<long long>*dp) {
  const long long kINF = 1LL << 60;
  if (dp->at(i) < kINF) return dp->at(i);

  if (i == 0) return dp->at(i) = 0LL;

  long long res = kINF;

  const long long kHMinusOne = recursion_search(i-1, h, dp) + std::abs(h[i]-h[i-1]);
  chmin(res, kHMinusOne);

  if (i > 1) {
    const long long kHMinusTwo = recursion_search(i-2, h, dp) + std::abs(h[i]-h[i-2]);
    chmin(res, kHMinusTwo);
  }

  return dp->at(i) = res;
}
void chapter_5::knapsack::execute() {
  /*
   * ナップザック問題：
   * 品物は重さと価値を持っている
   * 重さWを超えない範囲で品物を選び価値を最大化する
   *
   * 解法：
   * 品物を番号i, 重さw, 価値vで管理する
   * 品物i番まで選んだ場合のそれぞれの重さw にて価値の最大値を更新する
   */
  const int kN = 6;
  const int kW = 15;

  std::vector<int> weight(kN), value(kN);

  weight.assign({2, 1, 3, 2, 1, 5});
  value.assign({3, 2, 6, 1, 3, 85});

  std::vector<std::vector<int>> dp(kN+1, std::vector<int>(kW+1, 0));

  /*
   * i番目の品物を選んだ場合
   */
  for (int i = 1; i < kN+1; ++i) {
    for (int w = 0; w < kW+1; ++w) {
      // i+1番目の品物を選ばない場合、価値はi番目までの価値と等価
      dp[i][w] = std::max(dp[i][w], dp[i-1][w]);

      // i+1番目の品物を選んだ場合、価値はi番目までの価値と、i番目の価値にi+1番目の価値を追加したものの大きい方
      if (w - weight[i-1] >= 0) {  // NOTE: 不等号なのは、複数の品物を選んでいた場合も含みたいから
        dp[i][w] = std::max(dp[i][w], dp[i-1][w - weight[i-1]] + value[i-1]);
      }
    }
  }

  for (int i = 0; i < kN+1; ++i) {
    if(i==0)
      for(int w = 0; w < kW+1; ++w) {
        if (w == 0) std::cout << "\t";
        std::cout << w << "\t";

        if (w == kW) std::cout << "\n";
      }

    for (int w = 0; w < kW+1; ++w) {
      if (w == 0) std::cout << i << "\t";

      std::cout << dp[i][w] << "\t";

      if (w == kW) std::cout << std::endl;;
    }
  }

  std::cout << dp[kN][kW] << std::endl;
}
void chapter_5::edit_distance::execute() {
  const int kINF = 1 << 29;
  std::string S, T;

  S = "logistic";
  T = "algorithm";

  std::vector<std::vector<int>> dp(S.size()+1, std::vector<int>(T.size()+1, kINF));
  dp[0][0] = 0;

  for (int i = 0; i <= S.size(); ++i) {
    for (int j = 0; j <= T.size(); ++j) {

      // 変更操作
      if (i > 0 && j > 0) {
        if (S[i-1] == T[j-1]) {
          // NOTE: 同じ文字の場合、操作不要
          chmin(dp[i][j], dp[i-1][j-1]);
        } else {
          // NOTE: 同じ文字でない場合、変更操作
          chmin(dp[i][j], dp[i-1][j-1]+1);
        }
      }

      // 削除操作
      // NOTE: 文字列Sのiになるために要素削除を実行する場合、i-1番目の類似度+1
      if (i > 0) chmin(dp[i][j], dp[i-1][j]+1);

      // 挿入操作
      // NOTE: 文字列Sに一文字挿入= 文字列Tから一文字削除
      // 文字列Tのi番目になるために要素削除を実行する場合、j-1番目の類似度+1
      if (j > 0) chmin(dp[i][j], dp[i][j-1]+1);
    }
  }

  std::cout << dp[S.size()][T.size()] << std::endl;
}
void chapter_5::section_division::execute() {
  std::random_device rnd;

  const int kN = rnd() % 10 + 10;
  std::vector<std::vector<long long>> c(kN+1, std::vector<long long>(kN+1));

  for (int i = 0; i < kN+1; ++i) {
    for (int j = 0; j < kN+1; ++j) {
      c[j][i] = rnd() % 10 + 1;
    }
  }

  const long long kINF = 1LL << 60;
  std::vector<long long> dp(kN+1, kINF);
  dp[0] = 0LL;

  for (int i = 0; i <= kN; ++i) {
    for (int j = 0; j < i; ++j) {
      chmin(dp[i], dp[j]+c[j][i]);
    }
  }

  std::cout << dp[kN] << std::endl;
}
void chapter_5::question_1() {
  /*
   * NOTE: 初日の行動次第で最大値が変わる
   * 実装方針：前日の行動タイプを保持し、今日の幸福度が最大値になるよう更新する。初期値は３種類与える
   */
  std::random_device rnd;

  const int kN = 3; //rnd() % 10 + 3;

  // NOTE: ターミナル表示部分
  std::vector<int> a(kN), b(kN), c(kN);
  for (int i = 0; i < kN; ++i) {
    a[i] = rnd() % 100;
    b[i] = rnd() % 100;
    c[i] = rnd() % 100;
  }
  std::cout << "\t";
  for (int i = 0; i < kN; ++i) {
    std::cout << i << "\t";
  }
  std::cout << "\n";
  for (int i = 0; i < 3; ++i) {
    if (i == 0) std::cout << "a\t";
    else if(i==1) std::cout << "b\t";
    else std::cout << "c\t";

    for (int j = 0; j < kN; ++j) {
      if (i == 0) {
        std::cout << a[j] << "\t";
      }else if(i==1){
        std::cout << b[j] << "\t";
      }else{
        std::cout << c[j] << "\t";
      }
    }
    std::cout << "\n";
  }


  std::function<int(int, int, int, int)> max_action;
  max_action = [](int pre_action, int a_i, int b_i, int c_i) {
    std::vector<int> acts{a_i, b_i, c_i};
    std::sort(acts.begin(), acts.end(), std::greater<int>{});

    int max = 0;

    // 前回の行動と今回の行動の最大値が等しい場合
    if (pre_action == 0 && acts[0] == a_i) {
      max = acts[1];
    } else if (pre_action == 1 && acts[0] == b_i) {
      max = acts[1];
    } else if (pre_action == 2 && acts[0] == c_i){
      max = acts[1];

    // 前回の行動と今回の行動の最大値が異なる場合
    }else{
      max = acts[0];
    }

    if (max == a_i) return 0;
    else if (max == b_i) return 1;
    else return 2;
  };

  std::vector<std::vector<int>> dp(3, std::vector<int>(kN+1, 0));
  dp[0][0] = 0;
  dp[1][0] = 1;
  dp[2][0] = 2;

  for (int i = 1; i < kN; ++i) {
    dp[0][i] = max_action(dp[0][i-1], a[i], b[i], c[i]);
    dp[1][i] = max_action(dp[1][i-1], a[i], b[i], c[i]);
    dp[2][i] = max_action(dp[2][i-1], a[i], b[i], c[i]);
  }

  // NOTE: ターミナル表示部分
  std::cout << "\n";
  std::cout << "\t";
  for (int i = 0; i < kN; ++i) {
    std::cout << i << "\t";
  }
  std::cout << "\n";
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < kN; ++j) {
      int num;
      if (i == 0) { num = dp[0][j]; if(j==0)std::cout << "a\t"; }
      else if(i == 1) { num = dp[1][j]; if(j==0)std::cout << "b\t"; }
      else { num = dp[2][j]; if(j==0)std::cout << "c\t"; }

      std::cout << num << "\t";
    }
    std::cout << "\n";
  }
  std::cout << "\n";


  int sum_a = 0;
  int sum_b = 0;
  int sum_c = 0;

  std::function<int(int, int, std::vector<int>, std::vector<int>, std::vector<int>)> sum;
  sum = [](int i, int type, std::vector<int>x0, std::vector<int>x1, std::vector<int>x2) {
    switch (type) {
      case 0: return x0[i];
      case 1: return x1[i];
      case 2: return x2[i];
    }
  };

  for (int i = 0; i < kN; ++i) {
    sum_a += sum(i, dp[0][i], a, b, c);
    sum_b += sum(i, dp[1][i], a, b, c);
    sum_c += sum(i, dp[2][i], a, b, c);
  }

  std::cout << std::max(std::max(sum_a, sum_b), sum_c) << std::endl;
}
void chapter_5::question_2() {
  /*
   * knapsack
   * cache 0~W, and a1 ~ an
   * i+1番目の整数を選ばなかった場合、iまでの合計をi番目のキャッシュに登録
   * i+1番目の整数を選んだ場合、i番目の合計とi番目の合計の和をキャッシュに登録
   */

  std::random_device rnd;
  const int kN = 3;//rnd() % 10 + 2;
  const int kW = 10;//rnd() % 100 + 2;

  std::vector<int> a(kN, 0);
  for (int i = 0; i < kN; ++i) { a[i] = rnd() % kW; }

  // NOTE: 描画用コード
  std::cout << "N = " << kN << std::endl;
  std::cout << "W = " << kW << std::endl;
  std::cout << "a = " << std::endl;
  for (int i = 0; i < kN; ++i) {
    std::cout << "a[" << i << "] = " << a[i] << std::endl; }


  std::vector<std::vector<int>> dp;
  dp.assign(kN+1, std::vector<int>(kW+1, 0));

  bool exist = false;

  for (int i = 0; i < kN; ++i) {
    for (int w = 0; w < kW+1; ++w) {
      dp[i+1][w] = std::max(dp[i+1][w], dp[i][w]);

      if (w-a[i] >= 0)
        dp[i+1][w] = std::max(dp[i+1][w], dp[i][w-a[i]]+a[i]);

      if (dp[i+1][w] == kW) { exist = true; }
    }
  }

  // NOTE: 描画用コード
  for (int i = 0; i < kN+1; ++i) {
    for (int w = 0; w < kW+1; ++w) {
      std::cout << dp[i][w] << " ";
    }
    std::cout << "\n";
  }

  if (exist) { std::cout << "True" << std::endl; return;}
  std::cout << "False" << std::endl;
}
void chapter_5::question_3() {
  std::random_device rnd;
  const int kN = 3;// rnd() % 10 +2;
  const int kW = 10;// rnd() % 20 + 2;

  std::vector<int> a(kN, 0);
  for(int i = 0; i < kN; ++i) { a[i] = rnd() % 10; }

  // NOTE: 描画用コード
  std::cout << "N = " << kN << std::endl;
  std::cout << "W = " << kW << std::endl;
  for (int i = 0; i < kN; ++i) {
    std::cout << "a[" << i << "] = " << a[i] << std::endl; }

  std::vector<std::vector<int>> dp;
  dp.assign(kN+1, std::vector<int>(kW+1, 0));

  int count = 0;

  for (int i = 0; i < kN; ++i) {
    for (int w = 0; w < kW+1; ++w) {
      dp[i+1][w] = std::max(dp[i+1][w], dp[i][w]);

      if (w - a[i] >= 0)
        dp[i+1][w] = std::max(dp[i+1][w], dp[i][w-a[i]]+a[i]);

      if (dp[i+1][w] > 0 && dp[i+1][w] < kW+1) count++;
    }
  }

  for (int i = 0; i < kN+1; ++i) {
    for (int w = 0; w < kW+1; ++w) {
      std::cout << dp[i][w] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "count = " << count << std::endl;
}
void chapter_5::question_4() {
  /*
   * 実装方針：
   * 基本はナップザック、更新中に使用する値をキャッシュし計算中に可否を判定する
   * 計算量: O(2 * NW) = O(NW)
   *
   * 値が更新される場合のカウント更新：
   *     0. 初期値が一つの値に更新される場合、countを１追加する
   *         dp[i][w]=0 -> dp[i][w]=a[i]
   *         count[i][w]++
   *
   *     1. 初期値が複数の値の和に置き換えられる場合、countを要素の数だけ追加する
   *         dp[i][w]=0 -> dp[i][w]=a[i]+a[i-1]
   *         count[i][w]+=2
   *
   *     2. dp[i][w] が一つの値に置き換えられる場合、countの小さい方を保持する
   *         dp[i-1][w]=a[i-1] -> dp[i][w]=a[i], a[i-1]=a[i]
   *         count[i][w]=min(count[i-1][w], 1)
   *
   *     3. dp[i][w] が複数の値の和に置き換えられる場合、countが小さい方を保持する
   *         dp[i-1][w]=a[i-1] -> dp[i][w]=a[i-2]+a[i]
   *         count[i][w]=min(count[i-1][w], 2)
   */
  std::random_device rnd;
  const int kN = 4;//rnd() % 10 + 2;
  const int kW = 10;//rnd() % 30 + 2;
  const int kK = 2;//rnd() % kN + 1;

  std::vector<int> a(kN, 0);
  for (int i = 0; i < kN; ++i) { a[i] = rnd() % 10 + 1; }

  // NOTE: 確認用コード
  std::cout << "N = " << kN << std::endl;
  std::cout << "W = " << kW << std::endl;
  std::cout << "k = " << kK << std::endl;
  for (int i = 0; i < kN; ++i) {
    std::cout << "a[" << i << "] = " << a[i] << std::endl; }

  std::vector<std::vector<int>> dp, count;
  dp.assign(kN+1, std::vector<int>(kW+1, 0));
  count.assign(kN+1, std::vector<int>(kW+1, 0));

  bool possibility = false;

  for (int i = 0; i < kN; ++i) {
    for (int w = 0; w < kW+1; ++w) {
      dp[i+1][w] = std::max(dp[i+1][w], dp[i][w]);
      count[i+1][w] = std::max(count[i+1][w], count[i][w]);

      const int kWeight = w - a[i];
      if (kWeight >= 0) {
        bool not_same = dp[i+1][w] != dp[i][kWeight]+a[i];

        dp[i+1][w] = std::max(dp[i+1][w], dp[i][kWeight]+a[i]);

        if (dp[i+1][w] == dp[i][kWeight]+a[i]) {
          // NOTE: dp[i+1][w]が更新されたら,count[i+1][w]も更新
          if (not_same)
            count[i+1][w] = count[i][kWeight]+1;

          // NOTE: dp[i+1][w]を複数の組み合わせで作成できる場合、
          //       最小要素数でcount[i+1][w]を更新
          else
            count[i+1][w] = std::min(count[i][w], count[i+1][w]);
        }
      }

      if (dp[i+1][w] == kW && count[i+1][w] < kK+1) possibility = true;
    }
  }

  // NOTE: 確認用コード
  std::cout << "\n";
  std::cout << "--- dp ---" << std::endl;
  for (int i = 1; i < kN+1; ++i) {
    for (int w = 0; w < kW+1; ++w) {
      std::cout << dp[i][w] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  std::cout << "--- count ---" << std::endl;
  for (int i = 1; i < kN+1; ++i) {
    for (int w = 0; w < kW+1; ++w) {
      std::cout << count[i][w] << " ";
    }
    std::cout << "\n";
  }

  if (possibility) std::cout << "True" << std::endl;
  else
    std::cout << "False" << std::endl;
}
