#include <iostream>
#include <utility>
#include <vector>


namespace chapter12 {
void InsertionSoft(std::vector<int> &);
void MergeSort(std::vector<int>&, int, int);
void QuickSort(std::vector<int>&, int, int);

namespace heap {
void Heapify(std::vector<int>&, int, int);
void HeapSort(std::vector<int>&);
}  // namespace haep

void BucketSort(std::vector<int>&);
}  // namespace chapter12
