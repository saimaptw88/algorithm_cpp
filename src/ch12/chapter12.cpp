#include "chapter12.h"


namespace chapter12 {
void InsertionSoft(std::vector<int> &a) {
  const int N = static_cast<int>(a.size());

  for (int i = 1; i < N; ++i) {
    const int v = a[i];

    for (int j = i; j > 0; --j) {
      if (a[j-1] > v) a[j] = a[j-1];
      else break;

      a[j-1] = v;
    }
  }
}
}  // namespace chapter12
