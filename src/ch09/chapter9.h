#include <array>
#include <iostream>
#include <list>
#include <vector>
#include <regex>
#include <queue>
#include <stack>
#include <utility>


namespace chapter9 {
namespace stack {
constexpr int MAX = 1000000;

int st[MAX];
int top = 0;

void init() {
  top = 0;
}

bool is_empty() {
  return (top == 0);
}

bool is_full() {
  return (top == MAX);
}

void push(int x) {
  if (is_full()) {
    std::cout << "ERROR: stack is full.\n";
    return ;
  }
  st[top] = x;
  top++;
}

int pop() {
  if (is_empty()) {
    std::cout << "ERROR: stack is empty.\n";
    return -1;
  }

  top--;
  return st[top];
}

void stack() {
  init();
  push(3);
  push(5);
  push(7);

  std::cout << pop() << std::endl;
  std::cout << pop() << std::endl;

  push(9);
}
}  // namespace stack

namespace queue {
constexpr int MAX = 100000;
std::array<int, MAX> qu;
int tail = 0, head = 0;

void init() {
  head = tail = 0;
}

bool is_empty() {
  return (head == tail);
}

bool is_full() {
  return (head == (tail + 1) % MAX);
}

void enqueue(int x) {
  if (is_full()) {
    std::cout << "ERROR: queue is full.\n";
    return;
  }

  qu[tail] = x;
  tail++;

  if (tail == MAX) tail = 0;
}

int dequeue() {
  if (is_empty()) {
    std::cout << "ERROR: queue is empty.\n";
    return -1;
  }

  const int res = qu[head];
  head++;

  if (head == MAX) head = 0;
  return res;
}

void queue() {
  init();

  enqueue(3);
  enqueue(5);
  enqueue(7);

  std::cout << dequeue() << std::endl;
  std::cout << dequeue() << std::endl;

  enqueue(9);
}
}  // namespace queue

namespace question1 {
template<typename T>
class Stack {
 public:
  std::list<T> list_;

  void push(T x) {
    if (list_.size() == list_.max_size()) {
      std::cout << "ERROR stack is full.\n";
      return;
    }

    list_.push_back(x);
    top_++;
  }

  const T pop() {
    if (list_.empty()) {
      std::cout << "ERROR stack is empty.\n";

      T res = -1;
      return res;
    }

    top_--;

    const T res = list_.back();
    list_.pop_back();

    return res;
  }

 private:
  unsigned int top_ = 0;
};

template<typename T>
class Queue {
 public:
  std::list<T> queue_;

  void enqueue(T x) {
    if (queue_.size() == queue_.max_size()) {
      std::cout << "ERROR queue is full.\n";
      return;
    }

    queue_.push_back(x);
  }

  const T dequeue() {
    if (queue_.empty()) {
      std::cout << "ERROR: queue is empty.\n";
      T res = -1;

      return res;
    }

    const T res = queue_.front();
    queue_.pop_front();

    return res;
  }
};

void exec() {
  std::cout << "*****" << "stack" << "*****" << std::endl;
  Stack<int> stack;
  stack.push(3);
  stack.push(5);
  stack.push(7);

  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;

  stack.push(9);

  std::cout << "*****" << "queue" << "*****" << std::endl;
  Queue<int> queue;
  queue.enqueue(1);
  queue.enqueue(3);
  queue.enqueue(5);

  std::cout << queue.dequeue() << std::endl;
  std::cout << queue.dequeue() << std::endl;

  queue.enqueue(7);
}

}

void question2(const std::string& str);
void question3(unsigned int, const std::string&);
}  // namespace chapter9
