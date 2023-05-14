#include "chapter8.h"

int sum(int a, int b) { return a+ b; }
void chapter8::ConnectedList() {
  init();

  std::vector<std::string> names {
    "yamamoto",
    "watanabe",
    "ito",
    "takahashi",
    "suzuki",
    "sato"
  };

  for (int i = 0; i < names.size(); ++i) {
    Node* node = new Node(names[i]);
    insert(node);

    std::cout << "step " << i << ": ";
    printList();
  }
}

void chapter8::DoublyConnectedNode() {
  dInit();

  std::vector<std::string> names {
    "yamamoto",
    "watanabe",
    "ito",
    "takahashi",
    "suzuki",
    "sato"
  };

  DoublyNode* watanabe;

  for (int i = 0; i < names.size(); ++i) {
    DoublyNode* node = new DoublyNode(names[i]);

    dInsert(node);

    if (names[i] == "watanabe") watanabe = node;
  }

  std::cout << "before: ";
  dPrintList();
  dErace(watanabe);
  std::cout << "after: ";
  dPrintList();
}

void chapter8::question1() {
  std::cout << "O(N)" << std::endl;
}

void chapter8::question2() {
  std::cout << "O(N)" << std::endl;
}

void chapter8::question3() {
  std::cout << "連結リストの長さをもつ変数を定義する。"
  << "挿入なら+、削除なら-して長さを保つ。"
  << std::endl;
}

void chapter8::question4() {
  std::cout << "指定の要素を見つけるまで扇形探索して削除する\n";
}

void chapter8::question5() {
  std::random_device rnd;
  int N = rnd() % 100, M = rnd() % 100;
  std::vector<int> a(N), b(M);

  for (auto& a_ : a) a_ = rnd() % 100;
  for (auto& b_ : b) b_ = rnd() % 100;

  const int min = std::min(
    *std::min_element(a.begin(), a.end()),
    *std::min_element(b.begin(), b.end()));

  const int max = std::max(
    *std::max_element(a.begin(), a.end()),
    *std::max_element(b.begin(), b.end())
  );

  std::vector<bool> ad(max+std::abs(min), false);
  std::vector<bool> bd(max+std::abs(min), false);

  for (auto& a_ : a) ad[a_+std::abs(min)] = true;
  for (auto& b_ : b) bd[b_+std::abs(min)] = true;

  int count = 0;
  for (auto& a_ : a) if (bd[a_+std::abs(min)]) count++;
}
