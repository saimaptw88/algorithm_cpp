#include "chapter9.h"

void chapter9::question2(const std::string& str) {
  std::stack<int> stk;

  auto is_num = [] (const std::string& str) -> bool {
    std::regex re(R"([0-9])");
    if (std::regex_match(str, re)) return true;

    return false;
  };

  for (auto& s : str) {
    std::string s_{s};
    if (is_num(s_)) {
      stk.push(atoi(s_.c_str()));
    } else {
      const int num1 = stk.top();
      stk.pop();

      const int num2 = stk.top();
      stk.pop();

      if (s_ == "+") stk.push(num1 + num2);
      else if(s_ == "-") stk.push(num1 - num2);
      else if (s_ == "*") stk.push(num1 * num2);
      else stk.push(num1/num2);
    }
  }

  std::cout << stk.top();
}

void chapter9::question3(unsigned int N, const std::string& str) {
  int count = 0;
  for (const auto&s : str) {
    if (s == '(') count++;
  }
  if (count != N/2) {
    std::cout << "No\n";
  }

  std::vector<std::pair<int, int>> ans;
  std::stack<int> stk;

  for (int i = 0; i < N; ++i) {
    if (str[i] == '(') {
      stk.push(i);
      continue;
    }

    ans.push_back({stk.top(), i});
    stk.pop();
  }

  for (int i = 0; i < ans.size(); ++i) {
    std::cout << ans[i].first
              << " : "
              << ans[i].second
              << std::endl;
  }
}
