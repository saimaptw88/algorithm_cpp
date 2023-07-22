#include <iostream>


namespace chapter17 {
void question1() {
  std::cout << "答えがYesであった場合、その証拠としてハミルトンサイクルが与えられた時、"
            << "Gにハミルトンサイクルがあるかは深さ優先探索アルゴリズム(多項式時間)で"
            << "証明できる"
            << std::endl;
}

void question2() {
  std::cout << "答えがYesであり、その証拠としてグラフGと自然数kが与えられたなら、"
            << "Vからk以上を選ぶアルゴリズムはビット全探索擬多項式アルゴリズムと"
            << "選択した頂点が完全グラフかを判定するO(|E|)の多項式アルゴリズムの組み合わせの"
            << "多項式アルゴリズムで検証できる"
            << std::endl;
}
};  // namespace chapter17
