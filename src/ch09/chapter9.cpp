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
