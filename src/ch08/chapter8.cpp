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
