#include "chapter10.h"


namespace chapter10 {
struct Edge {
  int to_;
  long long w_;
  Edge(int to, long long w) : to_(to), w_(w) {}
};

void code10_1() {
  using Graph = std::vector<std::vector<Edge>>;

  int N, M;
  std::cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    long long w;
    std::cin >> a >> b >> w;

    G[a].push_back(Edge(b, w));
  }
}

struct Heap {
  std::vector<int> heap_;
  Heap() {}

  // heapにxを挿入する
  void push(int x) {
    heap_.push_back(x);

    int i = (int)heap_.size() - 1;

    while(i > 0) {
      int p = (i - 1) / 2;

      if (heap_[p] >= x) break;

      heap_[i] = heap_[p];

      i = p;
    }
    heap_[i] = x;
  }

  // 最大値を知る
  int top() {
    if (!heap_.empty()) return heap_[0];

    return -1;
  }

  // 最大値を削除する
  void pop() {
    if (heap_.empty()) return;

    const int x = heap_.back();
    heap_.pop_back();

    int i = 0;
    while (i * 2 + 1 < (int)heap_.size()) {
      int child1 = i * 2 + 1;
      int child2 = i * 2 + 2;

      if (child2 < (int)heap_.size() &&
          heap_[child2] > heap_[child1]) {
        child1 = child2;
      }

      if (heap_[child1] <= x) break;

      heap_[i] = heap_[child1];
      i = child1;
    }
    heap_[i] = x;
  }

  void print() {
    for (const auto& h : heap_) {
      std::cout << h << ", ";
    }
    std::cout << "\n";
  }
};

void code10_5() {
  Heap h;
  h.push(5); h.push(3); h.push(7); h.push(1);
  h.print();

  h.pop();
  h.print();

  h.push(11);
  h.print();
}

void question1() {
  std::cout << "１回だけ２分木がある" << std::endl;
}

void question2() {
  std::cout << "6, 5, 1" << std::endl;
}

void question3() {
  std::cout << "7, 6, 5, 3, 2, 1\n";
}

void question4() {
  std::cout << "0回に入るデータ数は2^0=1, 1回に入るデータ数は2^1=2となる."
            << "m回に入るデータを2^m >= Nとしてmを求める"
            << "log2(2^m) = log2(N)とすると m = log2(N)\n";
}

void question5() {
  std::cout << "木構造であるグラフをG1, G2とし両方のみを含むグラフをGとする."
            << "G1の頂点の個数をn1, G2の頂点の個数をn2とすると,"
            << "変の数はそれぞれn1-1, n2-1となる."
            << "ここでGを考えると頂点の数はn1とn2にそれぞれの親を加えたn1+n2+1となる."
            << "変の数はG1, G2の根に伸びる二本を追加して(n1-1)+(n2-1)+2=n1+n2となる."
            << "仕方って頂点数Nの木の変数はN-1となる" << std::endl;
}
}  // namespace chapter10
