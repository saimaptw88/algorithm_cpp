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

void MergeSort(std::vector<int>& a, int left, int right) {
  if (right - left == 1) return;

  const int mid = (right + left) / 2;

  MergeSort(a, left, mid);
  MergeSort(a, mid, right);

  std::vector<int> buf;
  for (int i = left; i < mid; ++i) {
    buf.push_back(a[i]);
  }
  for (int i = right-1; i >= mid; --i) {
    buf.push_back(a[i]);
  }

  int index_left = 0;
  int index_right = static_cast<int>(buf.size()) - 1;

  for (int i = left; i < right; ++i) {
    if (buf[index_left] <= buf[index_right]) {
      a[i] = buf[index_left];
      index_left++;
    } else {
      a[i] = buf[index_right];
      index_right--;
    }
  }
}
}  // namespace chapter12
