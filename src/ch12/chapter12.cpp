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

void QuickSort(std::vector<int>& a, int left, int right) {
  if (right - left <= 1) return;

  const int kPivotIndex = (left + right) / 2;
  const int kPivot = a[kPivotIndex];

  std::swap(a[kPivotIndex], a[right-1]);

  int i = left;
  for (int j = left; j < right - 1; ++j) {
    if (a[j] < kPivot) {
      std::swap(a[i++], a[j]);
    }
  }
  std::swap(a[i], a[right-1]);

  QuickSort(a, left, i);
  QuickSort(a, i+1, right);
}

namespace heap {
void Heapify(std::vector<int>& a, int i, int N) {
  int child1 = i * 2 + 1;
  if (child1 >= N) return;

  if (child1 + 1 < N && a[child1 + 1] > a[child1]) ++child1;

  std::swap(a[i], a[child1]);

  Heapify(a, child1, N);
}
void HeapSort(std::vector<int>& a) {
  int N = static_cast<int>(a.size());

  for (int i = N / 2 - 1; i >= 0; --i) {
    Heapify(a, i, N);
  }

  for (int i = N - 1; i > 0; --i) {
    std::swap(a[0], a[i]);
    Heapify(a, 0, i);
  }
}
}  // namespace haep

void BucketSort(std::vector<int>& a) {
  const int max = 1000000;
  const int N = static_cast<int>(a.size());

  std::vector<int> num(max, 0);
  for (int i = 0; i < N; ++i) {
    ++num[a[i]];
  }

  std::vector<int> sum(max, 0);
  for (int i = 1; i < max; ++i) {
    sum[i] = sum[i-1] + num[i];
  }

  std::vector<int> a2(N);
  for (int i = N; i >= 0; --i) {
    a2[--sum[a[i]]] = a[i];
  }

  a = a2;
}
}  // namespace chapter12
