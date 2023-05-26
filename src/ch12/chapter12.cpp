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

void question1(std::vector<int>& a) {
  const int kMax = 1000000;
  const int kN = static_cast<int>(a.size());

  std::vector<int> num(kMax, 0);
  for (int i = 0; i < kN; ++i) ++num[a[i]];

  std::vector<int> sum(kMax, 0);
  for (int i = 1; i < kMax; ++i)
    sum[i] = sum[i-1] + num[i];

  std::vector<int> count(kN);
  for (int i = 0; i < kN; ++i)
    count[i] = sum[a[i]];

  for (const auto& c : count)
    std::cout << c << std::endl;
}
void question2(
  const int kN,
  const int kM,
  const std::vector<int>& kA,
  const std::vector<int>& kB) {
  int min = 1000000;
  for (int i = 0; i < kA.size(); ++i) {
    if (kA[i] < min) min = kA[i];
  }

  std::cout << min * kM << std::endl;
}

struct Heap {
  std::vector<int> heap_;

  Heap() {}
  void push(int x) {
    heap_.push_back(x);
    int i = static_cast<int>(heap_.size() - 1);

    while(i > 0) {
      int p = (i - 1) / 2;

      if (heap_[p] >= x) break;

      heap_[i] = heap_[p];
      i = p;
    }

    heap_[i] = x;
  }
  int top() {
    if (!heap_.empty()) return heap_[0];

    return -1;
  }
  void pop() {
    if (heap_.empty()) return;

    int x = heap_.back();
    heap_.pop_back();

    int i = 0;
    while (i*2+1 < heap_.size()) {
      int child1 = i * 2 + 1, child2 = i * 2 + 2;

      if (child2 < (int)heap_.size()
        && heap_[child2] > heap_[child1]) {
        child1 = child2;
      }

      if (heap_[child1] <= x) break;

      heap_[i] = heap_[child1];
      i = child1;
    }

    heap_[i] = x;
  }
};
void question3(int k, int N, const std::vector<int>& a) {
  Heap heap;

  for (int i = 0; i < k; ++i) heap.push(a[i]);

  for (int i = k; i < N; ++i) {
    if (a[i] < heap.top()) {
      heap.pop();
      heap.push(a[i]);
    }

    std::cout << heap.top() << std::endl;
  }
}

void question5(int k, int N, const std::vector<int>&a) {
  const int kMax = 1000000;

  std::vector<int> num(kMax, 0);
  for (int i = 0; i < N; ++i) {
    num[a[i]]++;
  }

  std::vector<int> sum(kMax, 0);
  for (int i = 1; i < kMax; ++i) {
    sum[i] = sum[i-1] + num[i];

    if (sum[i] >= k) {
      std::cout << i << std::endl;
      return;
    }
  }
}
void question6(int a, int m) {
  std::cout << "Pass";
}
}  // namespace chapter12
