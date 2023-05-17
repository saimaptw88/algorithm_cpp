// Copyright2023 saito
#include "chapter11.h"


namespace chapter11 {
void code 11_4() {
  int N, M;
  std::cin >> N >> M;

  UnionFind uf(N);

  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;

    uf.unite(a, b);
  }

  int res = 0;
  for (int x = 0; x < N; ++x) {
    if (uf.root(x) == x) ++res;
  }

  std::cout << res << std::endl;
}
}
