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
   * ???????????????????????????
   * ??????????????????????????????????????????
   * ??????W???????????????????????????????????????????????????????????????
   *
   * ?????????
   * ???????????????i, ??????w, ??????v???????????????
   * ??????i????????????????????????????????????????????????w ???????????????????????????????????????
   */
  std::random_device rnd;
  const int kN = 7;//rnd() % 10 + 2;
  const int kW = 1000;//rnd() % 10 + 5;

  std::vector<long long> weight(kN), value(kN);

  //for (int i = 0; i < kN; ++i) {
  //  weight[i] = rnd() % 10;
  //  value[i] = rnd() % 10;
  //}
  weight.assign({2,1,3,2,1,5});
  value.assign({3,2,6,1,3,85});

  std::vector<std::vector<long long>>dp;
  dp.assign(kN+1, std::vector<long long>(kW+1, 0LL));

  for (int i = 0; i < kN; ++i) {
    for (int w = 0; w < kW; ++w) {
      if (weight[i] <= w && value[i] > dp[i][w]) dp[i][w] = value[i];
    }
  }

  // NOTE: ????????????i ???????????????????????????
  for (int i = 0; i < kN; ++i) {

    // NOTE: ????????????????????????????????????????????????????????????
    for (int w = 0; w <= kW; ++w) {

      /*
       * NOTE:
       *   i+1???, ??????w???????????????????????????????????????????????????
       *   i?????????????????????????????????w????????????????????????????????????????????????
       *     i+1????????????????????????????????????i+1??????????????????i????????????????????????????????????
       *     i+1?????????????????????????????????????????????i????????????????????????????????????
       */
      if (w-weight[i] >= 0) {
        dp[i+1][w] = chmax(dp[i+1][w], dp[i][w-weight[i]]+value[i]);
      }

      dp[i+1][w] = chmax(dp[i+1][w], dp[i][w]);
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

      // ????????????
      if (i > 0 && j > 0) {
        if (S[i-1] == T[j-1]) {
          // NOTE: ????????????????????????????????????
          chmin(dp[i][j], dp[i-1][j-1]);
        } else {
          // NOTE: ??????????????????????????????????????????
          chmin(dp[i][j], dp[i-1][j-1]+1);
        }
      }

      // ????????????
      // NOTE: ?????????S???i??????????????????????????????????????????????????????i-1??????????????????+1
      if (i > 0) chmin(dp[i][j], dp[i-1][j]+1);

      // ????????????
      // NOTE: ?????????S??????????????????= ?????????T?????????????????????
      // ?????????T???i????????????????????????????????????????????????????????????j-1??????????????????+1
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
   * i????????????????????????i-1?????????????????? + Max(ai, bi, ci)
   */

  std::random_device rnd;
  const int kN = rnd() % 10;

  std::vector<int> a(kN), b(kN), c(kN);
  for (int i = 0; i < kN; ++i) {
    a[i] = rnd() % 10;
    b[i] = rnd() % 10;
    c[i] = rnd() % 10;
  }

  int previous_activity = -1;

  std::function<int(int, int, int)> activity;
  activity = [&previous_activity](int a_i, int b_i, int c_i) {
    std::vector<int> i {a_i, b_i, c_i};

    decltype(i)::iterator max_itr = std::max_element(i.begin(), i.end());
    int max_index = std::distance(i.begin(), max_itr);

    if (previous_activity != max_index) {
      previous_activity = max_index;

      return *max_itr;
    }

    // ??????????????????????????????????????????????????????????????????????????????????????????
    i[max_index] = -1;

    max_itr = std::max_element(i.begin(), i.end());
    max_index = std::distance(i.begin(), max_itr);

    previous_activity = max_index;

    return *max_itr;
  };

  std::vector<int> dp(kN, 0);
  dp[0] = 0;

  for (int i = 1; i < kN; ++i) {
    dp[i] = dp[i-1] + activity(a[i], b[i], c[i]);
  }

  std::cout << dp[kN-1] << std::endl;
}
void chapter_5::question_2::execute() {
  // ?????????????????????O(2^N)
  std::random_device rnd;

  const int kN = rnd() % 10 + 2;
  const int kW = rnd() % 10 + 10;

  std::cout << "N: " << kN << ", W: " << kW << std::endl;

  std::vector<int> a(kN, 0);
  for (int i = 0; i < kN; ++i) { a[i] = rnd() % 10; std::cout << a[i] << std::endl;}

  std::vector<std::vector<int>>dp(kN+1, std::vector<int>(kW+1, -1));

  if (func(kN, kW, a, &dp)) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}
bool chapter_5::question_2::func(int i, int w, std::vector<int>a, std::vector<std::vector<int>>* dp) {
  if (i == 0) {
    if (w == 0) return true;
    else return false;
  }

  if (w < 0) return false;

  if (dp->at(i).at(w) != -1) return dp->at(i).at(w);
  if (func(i-1, w, a, dp)) return dp->at(i).at(w) = true;

  if (func(i-1, w-a[i-1], a, dp)) return dp->at(i).at(w) = true;

  return false;
}
void chapter_5::question_3::execute() {
  std::random_device rnd;

  const int kN = rnd() % 10 + 2;
  const int kW = rnd() % 10 + 3;

  std::vector<int>a(kN, 0);
  for (int i = 0; i < kN; ++i) { a[i] = rnd() % 10; }

  int count = 0;
  std::vector<std::vector<int>> dp(kN+1, std::vector<int>(kW+1, -1));
  func(kN, kW, a, &dp, &count);

  std::cout << count << std::endl;
}
void chapter_5::question_3::func(int i, int w, std::vector<int>a, std::vector<std::vector<int>>* dp, int* count) {
  if (w <= 0) { count++; return;}

  func(i-1, w, a, dp, count);
  func(i-1, w-a[i-1], a, dp, count);
}
