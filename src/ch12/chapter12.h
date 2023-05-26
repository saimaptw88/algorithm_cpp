#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
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

void question1(std::vector<int>&);
void question2(int, int, const std::vector<int>&, const std::vector<int>&);
void question3(int, int, const std::vector<int>&);
void question5(int, int, const std::vector<int>&);
void question6(int, int);
}  // namespace chapter12
