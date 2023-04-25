// Copyright 2022 saito
#ifndef SRC_CH08_CHAPTER8_H_
#define SRC_CH08_CHAPTER8_H_


#include <algorithm>
#include <functional>
#include <iostream>
#include <random>


int sum(int, int);

namespace chapter8 {
struct Node {
  Node* next;
  std::string name;

  Node(std::string name_ = ""): next(nullptr), name(name_) {}
};

Node* nil;

void init() {
  nil = new Node();
  nil->next = nil;
}

void printList() {
  Node* cur = nil->next;
  for (; cur!=nil;cur=cur->next) {
    std::cout << cur->name << " -> ";
  }
  std::cout << "\n";
}

void insert(Node*v, Node*p=nil) {
  v->next = p->next;
  p->next = v;
}

void ConnectedList();

struct DoublyNode {
  DoublyNode* prev, *next;
  std::string name;

  DoublyNode(std::string name_ = "") :
  prev(nullptr), next(nullptr), name(name_) {}
};

DoublyNode *dNil;

void dInit() {
  dNil = new DoublyNode();
  dNil->prev = dNil;
  dNil->next = dNil;
}

void dPrintList() {
  DoublyNode* cur = dNil->next;
  for (; cur != dNil; cur = cur->next) {
    std::cout << cur->name << " -> ";
  }
  std::cout << "\n";
}

void dInsert(DoublyNode* v, DoublyNode* p = dNil) {
  v->next = p->next;
  p->next->prev = v;
  p->next = v;
  v->prev = p;
}

void dErace(DoublyNode* v) {
  if (v == dNil) return;

  v->prev->next = v->next;
  v->next->prev = v->prev;

  delete v;
}

void DoublyConnectedNode();

};  // chaapter8

#endif  // SRC_CH08_CHAPTER8_H_
