#include "chapter6.h"

int sum(int a, int b) { return a+ b; }

int chapter6::binary_search(int key) {
  const int N = 8;
  const std::vector<int> a = { 3, 5, 8, 10, 14, 17, 21, 39 };

  int left = 0;
  int right = static_cast<int>(a.size() - 1);

  while (right >= left) {
    const int mid = (right + left) * 0.5;

    if (a[mid] == key) return mid;
    else if (a[mid] > key) right = mid - 1;
    else if (a[mid] < key) left = mid + 1;
  }

  return -1;
}
