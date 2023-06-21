// Copyright 2023 saito
#include "chapter14.h"


namespace chapter14 {
void execute() {
  Question1 q1;
  q1.exec();
}

void Question1::initialize() {
  std::cin >> N_ >> M_ >> s_;

  G_ = new std::vector<std::vector<Edge>>(N_);

  for (int _ = 0; _ < M_; ++_) {
    int a, b, w;
    std::cin >> a >> b >> w;

    G_->at(a).push_back(Edge(b, w));
  }

  dist_.assign(N_, INT8_MIN);
  dist_[s_] = 0;
}

void Question1::bellman_ford_algo() {
  for (int _ = 0; _ < N_; ++_) {
    bool is_updated = false;

    for (int v = 0; v < N_; ++v) {
      if (dist_[v] == INT8_MIN) continue;

      for (auto e : G_->at(v)) {
        is_updated = chmax(dist_[e.to_], dist_[v]+e.to_);
      }
    }

    if (!is_updated) break;
  }
}

void Question1::exec() {
  initialize();
  bellman_ford_algo();

  const int max = *std::max_element(dist_.begin(), dist_.end());

  std::cout << max << std::endl;
}
}  // namespace chapter14
